# 使用虚拟机安装Linux

**版本：ubuntu20.04**



## 一、VMware相关

**官网：**https://www.vmware.com/

![image-20201115160332451](https://i.loli.net/2020/11/15/DzHwdn3cAE85r14.png)

**选择VMware Workstation Pro 16.0 for Windows下载（当前最新版）**

![image-20201115233840538](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201115233840538.png)

**安装：**

![](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201115175715876.png)

**下一步安装即可**





## 二、ubuntu相关

### 1.下载映像文件

**选择下载ubuntu 20.04.1 LTS**

https://ubuntu.com/download/desktop

![image-20201115155320583](https://i.loli.net/2020/11/15/LtSJsK5iMAx7pwB.png)

**选择存放路径**

![image-20201115155719980](https://i.loli.net/2020/11/15/OaoEb74HsGmMgvQ.png)

**等待下载完成即可**



### 2.安装ubuntu

**在vmware中创建新的虚拟机**

![](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201115180057518.png)

**选择自定义**

![](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201115180207215.png)

**选择稍后安装操作系统**

![image-20201116000036529](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116000036529.png)

**选择Linux，ubuntu**

![image-20201116000141603](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116000141603.png)

**根据电脑配置选择处理器数量**

![image-20201116000356510](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116000356510.png)

**选择内存大小**

![image-20201116000607760](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116000607760.png)

**网络类型，I/O控制器类型，磁盘类型，磁盘选择默认即可**

**磁盘大小选择**

![image-20201116000919973](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116000919973.png)

**指定磁盘文件默认即可**

**选择自定义硬件**

![image-20201116001105197](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116001105197.png)

**完成下列操作后关闭**

![image-20201116001519587](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116001519587.png)

**完成**



### 3.开启Linux

**开启此虚拟机**

![image-20201116001750169](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116001750169.png)



**稍作等待至Install**

![image-20201116002343400](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116002343400.png)

**continue**

**Install Now**

![image-20201116002715987](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116002715987.png)

**continue**

**选择地区**

![image-20201116002811568](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116002811568.png)

**设置用户名和密码**

![image-20201116002948041](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116002948041.png)

**稍作等待**

![image-20201116003202060](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116003202060.png)

**restart重启**

![image-20201116003825147](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116003825147.png)

**使用刚才创建的账户登录**

![image-20201116004426112](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116004426112.png)

**Skip**

![image-20201116004531824](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116004531824.png)

**Next**...

![image-20201116004603633](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116004603633.png)

**完成**

![image-20201116004750134](C:\Users\32662\AppData\Roaming\Typora\typora-user-images\image-20201116004750134.png)

## 三.常用的linux命令

### 1.文件的增删改查

1）增

mkdir 路径/文件夹名      //创建文件夹

touch 路径/文件名          //创建文件

2）删

rm -rf 路径/文件名          //删除文件

3)改

mv 原文件路径 新文件路径       //移动文件  

4）查

ls      //查看当前所有文件

ll       //查看所有文件包括详细信息

cat 文件名      //查看文本

### 2.文件的编辑

1）使用vi或vim编辑器打开文件

vi 路径/文件

2)编辑

默认是vim命令模式,按 i 进入插入模式,进行编辑

命令模式下

yy   复制                nyy   复制n行

p   粘贴

u   撤消

dd   删除单行           ndd    删除n行

dd p 剪切

:set nu   显示行号        :set nonu  取消行号

3)保存

esc    退出编辑模式

:w+回车   保存

:q+回车    退出

:wq+回车   保存退出

:wq!+回车  强制保存退出

4)查找

/name +回车            按n切换到下一个查找内容

### 3.服务相关

service name start                                                     //启动服务
service name stop                                                     //停止服务
service name restart                                                //重启服务
service name status                                                 //查询服务运行状态
systemctl enable name.service                              //设为开机自动运行服务
systemctl disable name.service                             //取消开机自动运行服务
reboot                                                                        //重启(慎用)
shutdown                                                                  // 关机

### 4.其他

sudo su root        //切换为root 用户

ifconfig                 //获取IP地址

top                       //任务管理器

apt-get --help     //查看安装相关命令

dpkg -i                //安装软件包

ctrl+C                 //终止命令

ctrl+L                 //清理屏幕

Tab键                //自动补全

tar -zxvf           //解压tar.gz压缩包

uname -a

```
uname -a
Linux linux 5.4.0-54-generic #60-Ubuntu SMP Fri Nov 6 10:37:59 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux
```

ln -s file_path /usr/bin/

```
 ln -s /usr/local/src/sqlmapproject-sqlmap-6b7c3a2/sqlmap.py /usr/bin/sqlmap
```

find ./ -name filename

gedit     //打开文件







[linux常用基本命令](https://blog.csdn.net/xiaoguaihai/article/details/8705992?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param)

[Linux系统终端常用指令命令汇总](https://blog.csdn.net/yueyueniaolzp/article/details/81133122)

[vim快速入门使用](https://blog.csdn.net/cui_csdn/article/details/52464017)

[Vim快速入门](https://blog.csdn.net/lc013/article/details/83154820)

