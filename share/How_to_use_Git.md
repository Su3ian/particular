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

```git
$ git remote add origin https://github.com/wawyw/XUPTSEC.git
```

关联后，就可以把本地库的内容推送到远程库上：

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

切换至share目录

```
cd share
```

完成对此文件的创建，编辑，修改...

提交文件至暂存区

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





















