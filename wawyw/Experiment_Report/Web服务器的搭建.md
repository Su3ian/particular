# Web服务器的搭建



**搭建环境 : LAMP(Linux+Apache+MySQL+PHP)**

​                   **LNMP(Linux+nginx+MySQL+php)**

**安装方式:apt-get**     

​                                    

## 一.Nginx

### 1.安装Nginx

```
 apt-get update
```

```
 apt-get upgrade
```

//更新可获取软件及其版本信息

```
 apt-get install nginx
```

### 2. 查看nginx版本

当安装进程完成后，查看安装好的Nginx版本：

```
nginx -v
```

![image-20201022162435298](https://i.loli.net/2020/11/15/rV7YWxyPI9ohmnU.png)

### 3. 查看Nginx运行状态

```
service nginx status
```

![image-20201031195542396](https://i.loli.net/2020/11/15/jWGrVhoucm6iOMb.png)

### 4.访问nginx

查看路径

```
ls /var/www/html
```

![image-20201031200343805](https://i.loli.net/2020/11/15/cOAtGPxZU465afL.png)

浏览器中访问localhost/index.nginx-debian.html

![image-20201031200518986](https://i.loli.net/2020/11/15/Tri23bY8EMU9KQy.png)



## 二.PHP

### 1.安装php

```
 apt-get install php
```

### 2.查看php版本

```
php -v
```

![image-20201031200705310](https://i.loli.net/2020/11/15/TIHsyvJMAjEt5D6.png)

### 3.安装FastCgi及php必要扩展

```
 apt-get install spawn-fcgi
```

```
apt-get install php-pear
```

```
apt-get install php7.4-cgi
```

### 4.修改nginx配置文件(让其支持php)

进入此目录

```
vi /etc/nginx/sites-available/default
```

此行增加index.php

![image-20201023215217976](https://i.loli.net/2020/11/15/OiYhyqUDEHl4z3M.png)

去掉下面部分的注释用于支持php脚本,去掉注释后如下:

![image-20201023221149743](https://i.loli.net/2020/11/15/ayTLGlxUWXJfF7z.png)

### 4.重启nginx

```
service nginx restart
```

### 5.查看php相关信息

在访问目录下创建phpinfo.php文件

```
vi /var/www/html/
```

编辑

```
<?php
	phpinfo();
?>
```

然后浏览器中访问localhost/phpinfo.php

![image-20201031201415794](https://i.loli.net/2020/11/15/NLXfVKwi5W3UoZy.png)

### 6.配置虚拟主机

创建一个test文件(虚拟主机配置文件)

```
vi /etc/nginx/sites-available/test
```

编辑如下：

```
server {
       listen 80;
       listen [::]:80;

       server_name example.com;

       root /var/www/example.com;
       index index.html;

       location / {
               try_files $uri $uri/ =404;
       }
}

```

配置域名

```
vi /etc/hosts
```

![image-20201031203722330](https://i.loli.net/2020/11/15/gKI5qMRse9xPDLo.png)

创建一个软链接到/etc/nginx/sites-enabled/目录下,使配置文件生效

```
ln -s /etc/nginx/sites-available/test /etc/nginx/sites-enabled/
```

在/var/www/example.com中创建一个index.html,随便输出,重启nginx,访问地址得到

![image-20201031205422671](https://i.loli.net/2020/11/15/WQcDK73TIynb6a8.png)



## 三.Apache

### 1.安装apache2

```
apt-get install apache2
```

### 2.查看apache版本

```
apache2 -v
```

![image-20201024172309352](https://i.loli.net/2020/11/15/Hv6IhwSQXP7dAzG.png)

### 3.访问apache2

![image-20201031205925779](https://i.loli.net/2020/11/15/SWsLDPz2uX4BMIb.png)

### 3.安装php apache mod

```
apt-get install libapache2-mod-php
```

### 4.安装php插件

```
apt-get install php7.4-mysql php7.4-curl php7.4-gd php7.4-mbstring php7.4-zip 
```

### 5.查看php相关信息

访问localhost/phpinfo.php

#### ![image-20201031211242600](https://i.loli.net/2020/11/15/jCUKNYfocs7ku1I.png)

### 6.配置虚拟主机

修改文件

```
vi /etc/apache2/sites-available/000-default.conf 
```

```
<VirtualHost *:80>

ServerAdmin webmaster@localhost
DocumentRoot /var/www/html/project
ServerName www.youwen.com

ErrorLog ${APACHE_LOG_DIR}/error.log
CustomLog ${APACHE_LOG_DIR}/access.log combined

</VirtualHost>

```

重启apache

然后配置域名,

```
vi /etc/hosts
```

增加一行如下:

![image-20201026231143988](https://i.loli.net/2020/11/15/bG1F2M5LX9ETODS.png)

在先前路径文件下创建index.php文件,编辑如下:

```
vi /var/www/html/project/index.php
```

![image-20201026231450732](https://i.loli.net/2020/11/15/DvwdQ1fZczeoisW.png)

打开浏览器,访问www.youwen.com

![image-20201031213933587](https://i.loli.net/2020/11/15/I7YRjuQP6gNSU8v.png)



## 四.MySQL

### 1.安装mysql

```
apt-get install mysql-server mysql-client
```

### 2.mysql相关设置

为了让数据库更安全和正常运转，进行初始化操作

```
mysql_secure_installation 
```

--为root用户设置密码
--删除匿名账号
--取消root用户远程登录
--删除test库和对test库的访问权限
--刷新授权表使修改生效

### 3.登录MySQL

```
mysql -uroot -p
password
```

![image-20201024203846140](https://i.loli.net/2020/11/15/Fqc9rSLX1D8UK3Z.png)

查看数据库

```
SHOW DATABASES;
```

![image-20201101161119257](https://i.loli.net/2020/11/15/duwv794bxMV2SyD.png)

退出 quit

![image-20201024203932154](https://i.loli.net/2020/11/15/b1Vv9aYjNLOrUKu.png)

### 4.php连接mysql

在能够访问并处理数据库中的数据之前，必须创建到达数据库的连接。

在 PHP 中，这个任务通过 mysqli_connect() 函数完成。

连接方式    MySQLi - 面向过程

在 /var/www/html/project 创建connect.php

```
<?php
$dbhost = 'localhost';  // mysql服务器主机地址
$dbuser = 'debian-sys-maint';            // mysql用户名
$dbpass = 'PGpiTZ2V1aeDHuZg';          // mysql用户名密码
$conn = mysqli_connect($dbhost, $dbuser, $dbpass);
if(! $conn )
{
    die('Could not connect: ' . mysqli_error());
}
echo '数据库连接成功！';
mysqli_close($conn);
?>         
```

#安装后默认用户的用户名及密码,获取如下:

```
cat /etc/mysql/debian.cnf
```

![image-20201030183122653](https://i.loli.net/2020/11/15/JKNwX7sTF29RZ6q.png)

#

验证

![image-20201030182730755](https://i.loli.net/2020/11/15/tn8DE5mohjJ4GCI.png)



## 五.web服务器加固

### 1.php 安全配置

#### （1）运行用户

确保运行php的用户为一般用户，如www

#### （2） php.ini 配置

```
disable_functions = passthru,exec,system,chroot,chgrp,chown,shell_exec,popen,proc_get_status,ini_alter,ini_restore,dl,openlog,syslog,readlink,symlink,popepassthru,pcntl_exec,proc_get_status,stream_socket_server,fsocket,phpinfo #禁用函数

expose_php = off #避免暴露PHP信息

display_errors = off #关闭错误信息提示

register_globals = off #关闭全局变量

enable_dl = off #不允许调用dl

allow_url_include = off #避免远程调用文件

session.cookie_httponly = 1 #http only开启

upload_tmp_dir = /tmp#明确定义upload目录

open_basedir = ./:/tmp:/home/wwwroot/#限制用户访问的目录

```

### 2.MySQL安全设置

#### （1）网络和端口的配置

- 在数据库只需供本机使用的情况下，使用 –skip-networking 参数禁止监听网络 。
- 数据库若使用云数据库，则限制只能内网访问，禁止外网连接

#### （2） 用户权限

- 确保运行 MySQL 的用户为一般用户，如 mysql，注意存放数据目录权限为mysql

```
vi/etc/my.cnf 
user = mysql
```

#### （3）历史日志

开启mysql二进制日志，在误删除数据的情况下，可以通过二进制日志恢复到某个时间点

```
vi/etc/my.cnf 
log_bin = mysql-bin 
expire_logs_days = 7
```

#### （4）认证和授权

1) 禁止root账号从网络访问数据库，root账号只允许来自本地主机的登陆。

```
mysql>grant all privileges on *.* to root@localhost identified by 'password' with grant option; 
mysql>flush priveleges;
```

2) 删除匿名账号和空口令账号

```
mysql>USE mysql; 
mysql>delete from user where User=; 
mysql>delete from user where Password=; 
mysql>delete from db where User=;
```

### 3.WEB 服务器安全

#### (1）Git泄漏

- 禁止访问：/.git/

#### (2）用户权限

确保运行 Nginx 或者 Apache 的用户为一般用户，如 www，注意存放数据目录权限为 www

#### (3） 防止 sql 注入

```
if( $query_string ~* ".*[\;'\<\>].*"){ 
return404; 
}
```

#### (4） URL 解析

- 关闭存放数据上传等目录的 PHP 解析

```
location ~* ^/(attachments|data)/.*\.(php|php5)${ 
deny all; 
}
```

- 针对Apache：关闭图片目录/上传等目录的PHP解析

```
order allow,deny 
Deny from all
```

### 5.木马查杀和防范

#### (1） 快速查找

php 木马快速查找命令

```
grep -r --include=*.php '[^a-z]eval($_POST'/home/wwwroot/
grep -r --include=*.php 'file_put_contents(.*$_POST\[.*\]);'/home/wwwroot/
```

利用find mtime查找最近两天或者发现木马的这几天，有哪些PHP文件被修改

```
find-mtime -2 -typef -name \*.php
```

#### （2） 防范

**1) 做好之前的安全措施，比如禁用相关PHP函数等**
**2) 改变目录和文件属性**

```
find -typef -name \*.php -exec chomd 644 {} \; 
find -typed -exec chmod755 {} \; 
chown -R www.www /home/wwwroot/www.xxx.cn
```

**3) 目录隔离**
为防止跨站感染，需要做虚拟主机目录隔离

- ① nginx 的简单实现方法
  利用nginx跑多个虚拟主机，习惯的php.ini的open_basedir配置：

  ```
  open_basedir = ./:tmp:/home/wwwroot/
  ```

  注：/home/wwwroot/是放置所有虚拟主机的web路径
  黑客可以利用任何一个站点的webshell进入到/home/wwwroot/目录下的任何地方，这样对各个虚拟主机的危害就很大
  例如： /data/www/wwwroot目录下有2个虚拟主机
  修改php.ini：

  ```
  open_basedir = ./:/tmp:/home/wwwroot/www.sinesafe.com:/home/wwwroot/back.sinesafe.com
  ```

  这样用户上传webshell就无法跨目录访问了。

  - ② Apache的实现方法，控制跨目录访问
    在虚拟机主机配置文件中加入

    ```
    php_admin_value open_basedir "/tmp:/home/wwwroot/www.sinesafe.com"
    ```

    