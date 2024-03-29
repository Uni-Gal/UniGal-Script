## 注意事项

## UniGal命名原则

暂不创建这个文件，而是把纲领和注意事项直接列举。因为**一定要看**

>
>1. UniGal-Script/Diagram的后缀名为.unigal
>
>2. UniGal-Script文件分为```<head></head>```与```<body></body>```，其中```<head></head>```不涉及具体内容，而是存储各类配置，而```<body></body>```则是脚本的具体内容。
>
>3. UniGal-Script提供注释
>
>给电脑看的需要展示出来的注释用```<comment></comment>```封装
>
>给人看的纯粹开发的时候方便了解是啥的，今后统一用```<!-- {{comment_content}} -->```写，就不要暴露出来给解析脚本的时候添麻烦了。已有的存量代码逐步实行更改。
>

**接下来的工作重点将在codeblock和resource上**

此外，没有特殊规定的话，引擎名称均遵守首字母大写，在```<head></head>```中的引擎名称应保持与这里一致，作为本框架对大家的官方称呼。

1. **TODO：需要统一下划线命名法(如：size_t)和大驼峰命名法(如：IntPtr)**

2. 多个层级之间尽量不要重复，若要拆分和更精确描述一个标签，请您尽可能使其延长。

1. 大小写严格，如果有拼写错误是会报错的。

2. 此外，不正确的缩写和习惯名称也会报错。

我们不是不想做更丰富的支持，更人性化的支持。只是我们实在不能相信前端的输入和用户的输入，为了尽可能减少错误的可能，我们采用了严格的UEP来对异常进行管理。错误的引擎名称将可能导致UEP-E-0006错误。

3. 我们的XML缩进用两个空格

4. 下划线优先。在下划线和空格均可选的时候，应尽可能优先考虑使用下划线。因为我们不知道有些场景中空格是否会被转义为其他符号，是否会被认为是两端内容的分割，但下划线很少有这种问题。支持下划线的场景普遍来说是比空格更多的。

5. 若有文档中于此处不符合的，以此处为准。其他地方有说过类似话的，因为年代比这早，所以自动失效。