# UniGal-basic

1. UniGal-Script/Diagram的后缀名为.unigal

2. UniGal-Script文件分为<head></head>与<body></body>，其中<head></head>不涉及具体内容，而是存储各类配置，而<body></body>则是脚本的具体内容。

3. UniGal-Script提供注释

给电脑看的需要展示出来的注释用```<comment></comment>```封装

给人看的纯粹开发的时候方便了解是啥的，今后统一用```<!-- {{comment_content}} -->```写，就不要暴露出来给解析脚本的时候添麻烦了。已有的存量代码逐步实行更改。
