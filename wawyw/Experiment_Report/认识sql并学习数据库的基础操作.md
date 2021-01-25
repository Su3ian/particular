# 认识sql并学习数据库的基础操作



## 一、认识

1. 数据库 : 用来存储海量数据的仓库 。

2. SQL ：用于访问和处理数据库的计算机语言。



## 二、分类

1. 关系型数据库（二维表格形式）：Oracle,MySQL,MariaDB,SQL Server...
2. 非关系型数据库（not only sql）: Memcached,redis,MongoDB...



## 三、MySQL基础操作

安装mysql

```
apt-get install mysql-server mysql-client
```

登录mysql

```
mysql -u root -p
```

![image-20201109225823132](https://i.loli.net/2020/11/15/zXqlJhGSIiWtvbD.png)

退出mysql

```
\q 
```

当前用户

```
SELECT USER();
```

当前日期时间

```
SELECT NOW();
```

当前版本信息

```
SELECT VERSION();
```

服务器状态

```
SHOW STATUS;
```

服务器配置变量

```
SHOW VARIABLES;
```



### 1.用户相关命令

（1）创建用户

```
create user 'name'@'host' identified by 'password';
```

![image-20201112171427748](https://i.loli.net/2020/11/15/sWatwF4vhOJYTNA.png)

（2）删除用户

```
drop user name@'host';
```

![image-20201112171814162](https://i.loli.net/2020/11/12/oe5ZK9Fv1qEkCAQ.png)

（3）为用户授权

```
grant some_privileges on *.* to 'name'@'host';
flush privileges;
```

![image-20201112172854469](https://i.loli.net/2020/11/12/fy1be78PohEBaL5.png)

查看

```
select * from user where user='wyw';
```

![image-20201112173201025](https://i.loli.net/2020/11/12/D6eKVu1wSGP3IvT.png)

（4）撤销用户权限

```
revoke some_privileges to *.* from 'name'@'host';
```

![image-20201112174611837](https://i.loli.net/2020/11/12/qmYS8la1EuW27iB.png)

查看

![image-20201112174719182](https://i.loli.net/2020/11/12/9MGbYT5ym1ASae3.png)

### 2.库相关命令

（1）增

```
CREATE DATABASE db_name;
```

------

（2）删

```
DROP DATABASE db_name;
```

（3）查

```
SHOW DATABASES;
```

```
SHOW CREATE DATABASE db_name;
```

（4）打开数据库

```
USE db_name;
```

（5）查看当前所在数据库

```
SELECT DATABASE();
```



### 3.表相关命令

（1）增

```
CREATE TABLE table_name(
column_name data_type,
......
)[ENGINE=MYISAM DEFAULT CHARSET=UTF8MB4];
```

// []中内容可省略。

eg:

```
CREATE TABLE user(
uid INT AUTO_INCREMENT PRIMARY KEY,
username VARCHAR(30) NOT NULL,
pwd CHAR(32) NOT NULL,
pic CHAR(40) NOT NULL DEFAULT 'a.jpg',
money DECIMAL(8,2),
content TEXT,
sex ENUM('male','female','secret'),
age TINYINT UNSIGNED NOT NULL DEFAULT '18'
)[ENGINE=MYISAM DEFAULT CHARSET=UTF8MB4];
```

（2）删

```
DROP TABLE table_name;
```

（3）改

```
ALTER TABLE tab_name RENAME new_tab_name;
```

（4）查

查看表

```
SHOW TABLES[FROM db_name];
```

查看数据表结构

```
DESC table_name;   
```



### 4.字段相关命令

（1）增

```
ALTER TABLE table_name ADD col_name col_definition[FIRST|AFTER col_name];
```

```
ALTER TABLE table_name ADD (col_name col_definition,...);
```

（2）删

```
ALTER TABLE table_name DROP col_name;
```

```
ALTER TABLE table_name DROP col_name,DROP col_name,...;
```

（3）改

```
ALTER TABLE tab_name MODIFY col_name col_definition[FIRST|AFTER col_name];
```

```
ALTER TABLE tab_name CHANGE old_col_name new_col_name col_definition[FIRST|AFTER col_name];
```



### 5.数据相关命令

（1）增

```
INSERT INTO table_name(column_name,...)
VALUES('','',...)，('','',...),...;
```

```
INSERT INTO table_name SET col_name=expr,...;
```

```
INSERT INTO table_name(col_name) SELECT col_name FROM table_reference;
```

（2）删

```
DELETE FROM table_name [WHERE where_condition];
```

（3）改

```
UPDATE table_name SET col_name1=expr,col_name2=expr,...[WHERE where_condition];
```

（4）查

```
SELECT * FROM table_name [WHERE where_condition];
```

```
SELECT column_name,... FROM table_name;
```

查询结果分组

```
SELECT col_name FROM table_name GROUP BY col_name;
```

查询结果排序

```
SELECT col_name FROM table_name ORDER BY col_name ASC|DESC;
```

限制查询结果返回数量

```
SELECT * FROM table_name LIMIT row_count;
```

（5）连接

mysql在SELECT,UPDATE,DELETE语句中支持JOIN操作

```
table_reference INNER|LEFT|RIGHT JOIN table_reference ON conditional_expr
```



## 四、遇到的问题



### 1.MySQL中为root用户设置密码

进入mysql后发现root用户密码为空

```
USE mysql;
```

```
SELECT host,user,authentication_string FROM user;
```

![image-20201101233018450](https://i.loli.net/2020/11/09/3AYLdpV4iGK6Bzu.png)

使用以下命令设置密码：

```
ALTER USER 'root'@'%' IDENTIFIED BY '新密码' PASSWORD EXPIRE NEVER;
```

```
ALTER USER 'root'@'%' IDENTIFIED WITH mysql_native_password BY '新密码';
```

```
FLUSH PRIVILEGES;
```

出现错误：

**ERROR 1819 (HY000): Your password does not satisfy the current policy requirements**

查找资料：

原因是因为密码设置的过于简单会报错,MySQL有密码设置的规范

如果想要查看MySQL完整的初始密码规则,登陆后执行以下命令：

```
SHOW VARIABLES LIKE 'validate_password%';
```

![image-20201101235231684](https://i.loli.net/2020/11/09/ZTkVwiKIoWrHGtb.png)

validate_password.length决定密码的长度,默认长度为8位，可以通过以下命令修改为4位：

```
set global validate_password.length=4;
```

validate_password_policy决定密码的验证策略,默认等级为MEDIUM(中等),可以通过以下命令修改为LOW(低)：

```
set global validate_password.policy=0;
```

修改完成后密码就可以设置的很简单。

再次设置密码

![image-20201101235825039](https://i.loli.net/2020/11/09/PeC6lhpZ4gVNJG1.png)

成功!

退出后重新使用设置的密码进入MySQL

![image-20201101235949729](https://i.loli.net/2020/11/09/Q8HoYIWZLOrpGmy.png)

再次查看用户及密码：

```
SELECT host,user,authentication_string FROM user;
```

![image-20201102000107053](https://i.loli.net/2020/11/09/VzMwpaEI18cnTbL.png)

完成!



### 2.Navicat远程连接MySQL

1)修改配置文件

```
vi etc/mysql/mysql.conf.d/mysqld.cnf
```

查找到bind-address,将bind-address=127.0.0.1 修改为bind-address=0.0.0.0 ,以允许任何IP来访问MySQL服务

2）重启MySQL服务

```
service mysql restart
```

3）给需要远程访问的用户授权

授权所有权限

```
grant all privileges on *.* to 'root'@'%' identified by '123456' with grant option;
```

![image-20201118172547045](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201118172547045.png)

























参考资料:  https://www.pianshen.com/article/251865160/ 

​                  https://blog.csdn.net/calistom/article/details/87939956

​                 

