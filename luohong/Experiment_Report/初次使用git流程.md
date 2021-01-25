# 初次使用git流程

```
cd Documents/git_share/(这里根据自己文件夹名)
git init
git remote add origin https://github.com/wawyw/XUPTSEC.git
这里随便在文件夹里创建个文件
git add .
git commit -m "Update"
git branch work
git checkout work
这里切换到了work分支下，你想要上传什么文件现在放入文件夹内，通过git add和commit(如5,6行所示)
git checkout master 
git pull origin master --allow-unrelated-histories 
git checkout work 
git rebase master 
git checkout master 
 git merge work 
git push 
git push --set-upstream origin master 

大概是这样，可能有些许遗漏
```

