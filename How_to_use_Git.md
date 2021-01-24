# Git简单使用

## 1.日常流程

Git支持很多种工作流程，我们采用的一般是这样，远程创建一个主分支，本地每人创建功能分支，日常工作流程如下：

去自己的工作分支

```
$ git checkout work
```

---

工作
....

---

提交工作分支的修改

```
$ git commit -a
```

---

回到主分支

```
$ git checkout master
```

---

获取远程最新的修改，此时不会产生冲突

```
$ git pull
```

---


回到工作分支

```
$ git checkout work
```

---

[用rebase合并主干的修改，如果有冲突在此时解决](http://blog.csdn.net/hudashi/article/details/7664631/)

```
$ git rebase master
```

---

回到主分支

```
$ git checkout master
```

---

合并工作分支的修改，此时不会产生冲突。

```
$ git merge work
```

---

提交到远程主干

```
$ git push
```

这样做的好处是，远程主干上的历史永远是线性的。每个人在本地分支解决冲突，不会在主干上产生冲突。

<hr >


## 2.以提交这篇How_to_use_Git.md为例

### 2.0.前提

把本地仓库与我们远程的github仓库相关联

==仓库地址== 

git@github.com:wawyw/XUPTSEC.git

```git
$ git remote add origin git@github.com:wawyw/XUPTSEC.git
```

**注意对于多人协作开发，那么每个人需各自从远程克隆仓库。**

```
$ git clone git@github.com:wawyw/XUPTSEC.git
```

这样各成员在自己的本地就拥有了向XUPTSEC仓库中提交代码(commit/push/merge/branch)的权限,就好比拥有这个仓库一样, 但是成员操作此仓库的时候使用的是自己的github账号和密码. 同样此时自己的github账号中并不会出现XUPTSEC仓库。

关联或克隆完成后，就可以把本地库的内容推送到远程库上：

```
$ git push -u origin master
```

把本地库的内容推送到远程，用`git push`命令，实际上是把当前分支`master`推送到远程。

由于远程库是空的，我们第一次推送`master`分支时，加上了`-u`参数，Git不但会把本地的`master`分支内容推送的远程新的`master`分支，还会把本地的`master`分支和远程的`master`分支关联起来，在以后的推送或者拉取时就可以简化命令。

### 2.1.创建并切换到工作分支dev

```git
$ git checkout -b dev
Switched to a new branch 'dev'
```

`git checkout`命令加上`-b`参数表示创建并切换，相当于以下两条命令：

```git
$ git branch dev
$ git checkout dev
Switched to branch 'dev'
```

此时，用`git branch`命令查看当前分支：

```git
$ git branch
* dev
  master
```

`git branch`命令会列出所有分支，当前分支前面会标一个`*`号。

### 2.2.在当前分支上完成对文件的修改，并提交

在本地完成对此文件的创建，编辑，修改...

然后提交文件至暂存区

```git
git add How_to_use_Git.md
```

提交至本地仓库，并附说明

```git
$ git commit -m "Git_use"
[dev 7ca8319] Git_use
 1 file changed, 144 insertions(+)
 create mode 100644 share/How_to_use_Git.md
```

### 2.3.回到主分支master,并获取远程最新的修改

```git
$ git checkout master
```

```git	
$ git pull
Already up to date.
```

### 2.4.回到工作分区，并合并主分支的修改

```git
$ git checkout dev
Switched to branch 'dev'
```

```git
$ git rebase master
//如果有冲突，在此时解决
```

### 2.5.回到主分支，并合并工作分支的修改

```
$ git checkout master
```

```
$ git merge dev
Updating b72a27e..7ca8319
Fast-forward
 share/How_to_use_Git.md | 144 ++++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 144 insertions(+)
 create mode 100644 share/How_to_use_Git.md
 //此时不会产生冲突。
```

### 2.6.提交文件到远程主分支

```
$ git push
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 1.10 KiB | 1.10 MiB/s, done.
Total 4 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/wawyw/XUPTSEC.git
   b72a27e..7ca8319  master -> master
```



<hr>

### 参考资料

[1] [Git简介 - 廖雪峰的官方网站](https://www.liaoxuefeng.com/wiki/896043488029600/896067008724000)

[2] [Git 多人协作开发的过程](https://blog.csdn.net/wangliang888888/article/details/80536277)

[3] [[Git & GitHub] 怎么团队合作多人开发项目](https://bluetata.blog.csdn.net/article/details/81391835?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.control)



## 3.补充：

### 3.1.前提

我想在初始化仓库后，创建新分支work，但是要实现这个目的就需要先进行commit(这个我也不清楚具体原因)，于是我就先进行了

```
git add <filename>
git commit -m "说明"
```

之后才进行创建分支work

```
git branch work
```

而这会导致此数据既没有被push到远程仓库也没有被del，所以会报一个fatal，如下：

```
$ git pull 
Username for 'https://github.com': airy324
Password for 'https://airy324@github.com': 
warning: 没有共同的提交
来自 https://github.com/wawyw/XUPTSEC
 * [新分支]          ljz201128-patch-1 -> origin/ljz201128-patch-1
 * [新分支]          master            -> origin/master
 * [新分支]          zzmxyz-patch-1    -> origin/zzmxyz-patch-1
当前分支没有跟踪信息。
请指定您要合并哪一个分支。
详见 git-pull(1)。

    git pull <远程> <分支>

如果您想要为此分支创建跟踪信息，您可以执行：

    git branch --set-upstream-to=origin/<分支> master
```

```
$ git pull origin master 
Username for 'https://github.com': airy324
Password for 'https://airy324@github.com': 
来自 https://github.com/wawyw/XUPTSEC
 * branch            master     -> FETCH_HEAD
fatal: 拒绝合并无关的历史
```

解决方法：让git在检验时忽略掉所谓无关历史数据

```
$ git pull origin master --allow-unrelated-histories
```

之后又出现了问题，在执行完

```
git rebase master
git merge work(这个work是自己创建的分支，名儿可能不一样)
```



```
$ git push 
fatal: 当前分支 master 没有对应的上游分支。
为推送当前分支并建立与远程上游的跟踪，使用

    git push --set-upstream origin master

$ git push --set-upstream origin master 
Username for 'https://github.com': airy324
Password for 'https://airy324@github.com': 
枚举对象: 115, 完成.
对象计数中: 100% (115/115), 完成.
使用 8 个线程进行压缩
压缩对象中: 100% (106/106), 完成.
写入对象中: 100% (114/114), 6.26 MiB | 388.00 KiB/s, 完成.
总共 114 （差异 2），复用 0 （差异 0）
remote: Resolving deltas: 100% (2/2), done.
To https://github.com/wawyw/XUPTSEC.git
   6b3d8ee..2d17948  master -> master
分支 'master' 设置为跟踪来自 'origin' 的远程分支 'master'。
```



<hr>参考资料

[git: 拒绝合并无关的历史(报错原因及解决) ](https://blog.csdn.net/qq_39713775/article/details/100048096)

再添上我参考的文章：

[1git命令的使用,查看git仓库状态,添加文件到git跟踪,git提交,查看git分支,查看git仓库日志信息,切换git分支，解决git分支合并后出现冲突的问题](https://blog.csdn.net/toto1297488504/article/details/41398025?utm_source=app&app_version=4.5.0)

[Git的使用--如何将本地项目上传到Github](https://blog.csdn.net/zamamiro/article/details/70172900?utm_source=app&app_version=4.5.0)

