# UniGal-supportlist

## 目前的通用脚本语言

* [UniGal系](https://github.com/Uni-Gal/)
* [PrepPipe系](https://github.com/PrepPipe/)

## UniGal对各引擎的支持详表

大部分并未收录在[github/linguist](https://github.com/github/linguist/blob/master/lib/linguist/languages.yml)里

(这个表格可以考虑抽出来了)

| 引擎代系 | 引擎名称             | 引擎主流语言 | 存活状态     | 引擎原生支持             | 双向导入导出 | 可从Unigal导入 | 可导出为Unigal | 暂无支持计划 | 是否自由 |
| -------- | -------------------- | ------------ | ------------ | ------------------------ | ------------ | -------------- | -------------- | ------------ | -- |
| Krkr     | Krkr                 | TJS          | 已停止维护   |                          |              |                | √（开发中）    |              | |
| 面包工坊 | [BKEngine](https://bke.bakery.moe/index.html) | bkspr (.bkspr)       | 已停止维护   |                          |              | √（开发中）    |                |              | | |
| Unity    | [Unity-Nova](https://github.com/Lunatic-Works/Nova)([语法](https://github.com/Lunatic-Works/Nova/wiki/NovaScript)) | Lua/C# (.txt)          | **活跃**     | （正在说服开发者）       | √（开发中）  | √（开发中）    | √（开发中）    |              |
| Unity    | [Unity-Naninovel](https://naninovel.com/)([语法](https://naninovel.com/guide/naninovel-scripts.html)) | JS (.nani)         | **活跃**     | 做梦       | 做梦  | 做梦    | √（开发中）    |              | |
| Python   | [Librian](http://librian.net/) | liber        | **活跃**     | （正在说服开发者）       | √（开发中）  | √（开发中）    | √（开发中）    |              | |
| js       | [AVGPlus](https://avg-engine.com/) | json         | **活跃**     | （考虑要不要联系开发者） |              |                | √（开发中）    |              | |
| js       | AVG.js               | json         | 未知         |                          |              |                | √（开发中）    |              | |
| js       | [WebGal](https://github.com/MakinoharaShoko/WebGAL)       | 未知         | 未知         |                          |              |                | √（开发中）    |              | |
| js       | Renjs                | javascript   | 未知         |                          |              |                | √（开发中）    |              | |
| Python   | [Renpy](https://www.renpy.org/) | Python (.rpy)      | **活跃**     |                          |              |                | √（开发中）    |              | |
| Strrationalism | [YukimiScript](https://github.com/Strrationalism/YukimiScript)              | C++          | 不能理解它到底有多少是属于非Galgame的，处于观察中 |                          |              |                |  √（艰难开发中）              |           | |
| json     | [Monogatari](https://monogatari.io) | json         | **活跃**     |                          |              |                | √（开发中）    |              | |
| json     | GameCreator          | 未知         | **活跃**     | （考虑要不要联系开发者） |              |                | √（开发中）    |              | |
| Unity    | Unity-Utage          | C#           | **活跃**     |                          |              |                |                | √            | |
| Unity    | Unity-Fungus         | C#           | **活跃**     |                          |              |                |                | √            | |
| Unity    | Unity-Kirino-Engine  | C#           | 已停止维护   |                          |              |                |                | √            | |
| Unity    | Unity-XiheAnimation  | C#           | 未知         |                          |              |                |                | √            | |
| SDL      | VoidMatrix系列        | C++          | **活跃**     | （正在与开发者合作，已经提供XML读取支持了） | √（开发中）  | √（开发中）    | √（开发中）    |     |          |
| 橙光     | 橙光文字游戏制作工具 | 可视化       | **生不如死** |                          |              |                |                | √            | |
| 橙光     | iFAction             | 可视化       | 活跃         |                          |              |                |                | √            | |
| 橙光     | EvkWorld幻境         | 可视化       | 未知         |                          |              |                |                | √            | |
| js       | [Ink](https://www.inklestudios.com/ink/) | YAML | 活跃 | | | | | 语法简单适合支持| MIT|

https://github.com/soryu-ryouji/VNFrameworkCore

~~另有TUNA正在研发的Gal引擎，可见[“开源软件供应链点亮计划——暑期2022”项目提案](https://tuna.moe/blog/2022/ospp-summer-2022/)~~

另可参考如下网友根据其破解和解包经验完善的引擎与代表作信息。请注意，我们不鼓励破解和反编译等逆向工程。

+ YeLikesss的 https://github.com/YeLikesss/CNGALTools 
+ 2439905184的 https://github.com/2439905184/Galgame-Engine-Collect#%E6%AD%A3%E9%A2%98

## 目前各类语言的编辑器内着色器详表

| 引擎 | 着色器网站 | 支持引擎 | 仓库 |
|-|-|-|-|
| BKEngine | [BKE官方教程](http://docs.bakery.moe/faq) | Sublime | [AllanZyne/BKS4Sublime](https://github.com/AllanZyne/BKS4Sublime) |
| BKEngine | - | VSCode | [BKEngine/vscode-bkscr](https://github.com/BKEngine/vscode-bkscr) |
| Librian | - | Sublime | [RimoChan/Librian](https://github.com/RimoChan/Librian/tree/master/librian/librian%E6%9C%AC%E9%AB%94/%E5%9C%9F%E7%89%B9%E7%94%A2) |
| Unity-Nova | - | VSCode | [zhouhaoyu/vscode-nova-script](https://github.com/zhouhaoyu/vscode-nova-script) |
| Naninovel | [Guide](https://naninovel.com/guide/ide-extension) | VSCode | [Naninovel/VSCode](https://github.com/Naninovel/VSCode) |

注意，以上部分语法着色器开发者维护较缓慢，可能不适合非开发者使用。

## 关于请求各位引擎开发者能够提供的帮助的说明

### 语法方面

有很多语法上面不清晰的地方，还是希望能直接引用文档的，当然大部分引擎的文档都很出色。我们是希望能引用一个开放的文档而不是私有的文档，只是群文件的话，恐怕不便于直接引用和给出参考链接，毕竟互联网是开放的，只要可能，我们没有必要建设一个私域流量的网络吧~

### “引擎自身支持”方面

（已经试着打入各位开发者的交流群并且试着和大家做好友了）但是因为太菜而瑟瑟发抖不敢说话。

此外，最终没有打算提供JSON或者YAML版本的UniGal标准写法，是因为认为这个应该是引擎内完成的事情。有的引擎基于js所以偏向json，有的基于python所以偏向yaml，如果分别维护分支，工作量会很大，会很难维护的过来。

因此，出于可交换性和统一性的考虑，只提供一个XML的写法。因为现在各种常见编程语言下，不论是XML还是JSON，都有很成熟的库可以使用，而且XML和JSON/YAML互转也是有方法的。如果您的引擎确实不能处理XML，可以考虑在引擎读入XML的时候自动转换一个temp的JSON文件。若是需要写入，先写JSON，再写回的时候再把JSON转XML，也是一种引擎内的实现吧。

因此，觉得这将会极大增加各位引擎开发者的工作量。并且，UniGal的语法也会随着演进而不断的滚动变更，要各位开始就实现很多功能但是后期却发生变更的话，想必也是过意不去的。我们只是作为一个标准制定和推行者，不可以也不应该去强制各位遵循的。

不过如果可以，可以从```<text></text>```这块下手，至少text上，UniGal的标准是基本定型了的。而纯粹针对文本的转换和读取，执行，技术上的调整和难度也是最小的。可以以某个确定版本的标准（如0.1.0）来尝试去实现。希望这可以成为大家合作的开始。UniGal社区在此再次感谢各位引擎开发者。



## 关于支持列表的补充说明

### 遇到的困难

1. Strrationalism系造轮子太快，暂缓支持。

2. Unity系的不少商业框架，文档不便。

### 不会考虑支持的引擎和原因

橙光文字游戏制作工具：**业界毒瘤**，捆绑平台，逼迫作者吊死在自家一颗树上

iFAction：是商业引擎并有基于账号云端验证的加密功能，作品的打开需要掌握在引擎制作方的手里，提供导出工具既与开发者的盈利和用户素材安全违背，又不符合本项目开放的初衷。

EvkWorld：曾经以群邮件的形式大量向使用者推销官方的打卡课程。并且该引擎并非专注于AVG，而是杂糅式的的多功能引擎，但又高度依赖模板，在AVG的可扩展空间不一定足够大。

### 更多支持计划

更多引擎，可以见visual-novel-engine的[Github Topic](https://github.com/topics/visual-novel-engine)。其中已经有一些引擎已在本支持名单中。

我们选择支持一个引擎的理由主要是考虑以下几个因素：

+ 其用户基础和体量
+ 其完成程度
+ 其对开发者的友好程度
+ 其使用的开源协议是否足够开放
+ 其是否有足够的面向中文用户的开发文档
+ 其是否有很好的i18n支持、a11y支持和跨平台支持
+ 其是否有良好的用户社群。
