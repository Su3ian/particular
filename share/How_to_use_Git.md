# Git简单使用

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


## 以提交这篇How_to_use_Git.md为例

### 1.创建并切换到我的工作分支

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

### 2.在当前分支上完成对文件的修改，并提交

```git

```

























