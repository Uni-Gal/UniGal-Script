# UniGal-Script

Offer a visuable way to switch and show the different possibility of a Galgame



## UniGal-Script介绍
首先感谢各位开发者对本项目的支持，在各种地方提及这个尚未成熟，仅仅写出了一个最基本最简单的编译器的小项目，之后还将进一步完善。

本项目是受Nova引擎的开发者提出的统一语法标准，也因为作者曾经学过不少引擎的使用和语法，对之间互不相同，迁移学习成本过高表示很头疼，因此才想到这一点。当然，这里面也有Librian开发者提供的支持和帮助。

~~不过，似乎本语法也不是什么好懂的东西啊（笑）~~

若要直接查看语法标准，请移步[语法标准](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-text.md)

UniGal是一个完整的项目，分为[Script](https://github.com/Uni-Gal/UniGal-Script)(脚本语法)、[Diagram](https://github.com/Uni-Gal/UniGal-Diagram)(流程图语法)、[Complier&Interpreter](https://github.com/Uni-Gal/UniGal-Complier-Interpreter)(编译器和解释器)三部分。欢迎您查看其他两部分的内容。

## UniGal-Script特性

1. UniGal-Script为创造一种具有普适性的语法标准，因此采用了XML作为基础。之所以采用XML而不是JSON或YAML，可详见备注部分的文档。没有采用JSON或YAML，是为了保证一个能更好的适应更多环境的脚本
2. UniGal-Script是高度抽象化和反复封装的，因此对于一些较为简练的引擎来说，其语法显得较为繁琐。
3. UniGal-Script将演出与脚本与代码等合为一体，不再刻意强调演出与剧本之间的工作划分，不将其分割为多个不同文件，不参与素材属于演出还是脚本的名词争端。
4. UniGal-Script中凡是纯粹的文本内容，都用```<text></text>```包装，其他的均视为```<code></code>```包装

## 支持计划

首先说明，我们支持的引擎，将尽可能以开源世界和非常具有代表性的引擎为主，不对私有引擎提供支持，因为那将可能意味着本工具被用于破解和解包后重置使用。我们希望它只是一个工具。当然，工具不可能因为使用者的意图而选择展示自己的能力，但我们希望它仅仅是被用来辅助Galgame开发者的，而不是辅助未授权的破解者。

**下面的支持列表仅在一定程度上大致表示我们的支持顺序**

### 可能支持的允许导出的引擎

nova

librian

### 准备支持的单向导入的引擎

BKE 与 librian

AVGPlus/AVG.js 与 unity-nova

krkr 与 renpy/renjs

GameCreator

monogatari

snowing

### 可能支持的单向导入的引擎

（都是商业引擎了，准备放弃）

unity-Utage

unity-Fungus

（林叶先生可能不允许，准备放弃）

unity-XiHe animation engine

（这个是有想法和考虑的）

unity-Kirino-Engine

QGame(虽然是通用引擎（库）但是有AVG部分)

### 不会考虑支持的引擎（附原因）

橙光文字游戏制作工具：**业界毒瘤**，捆绑平台，逼迫作者吊死在自家一颗树上

iFAction：是商业引擎并有基于账号云端验证的加密功能，作品的打开需要掌握在引擎制作方的手里，提供导出工具既与开发者的盈利和用户素材安全违背，又不符合本项目开放的初衷。

### 更多支持计划

更多引擎，可以见 [名单A-github topic](https://github.com/topics/visual-novel-engine) 和 [名单B 野榜](https://awesomeopensource.com/projects/visual-novel) ，其中已经有一些引擎已在本支持名单中。我们选择支持一个引擎的理由主要是考虑其用户基础和体量，其完成程度，其对开发者的友好程度，其使用的开源协议是否足够开放，其是否有足够的面向中文用户的开发文档，其是否有很好的i18n支持和跨平台支持，其是否有良好的用户社群。

出于便于交流的目的，我们不对Galgame和VisualNovel的词汇进行明确的划分，视为同一含义。

## 教程与介绍目录

以下是UniGal-Script的文档的目录

[Docs/zh_CN/UniGal-main.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-main.md)

[Docs/zh_CN/UniGal-text.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-text.md)

[Docs/zh_CN/UniGal-code.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-code.md)

[Docs/zh_CN/UniGal-basic.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-basic.md)

[Docs/zh_CN/UniGal-resource.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-resource.md)

[Docs/zh_CN/UniGal-Developer.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-Developer.md)

以下是UniGal-Script的多语言Readme的目录

[zh_CN.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Readme/zh_CN.md)

[en_UK.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Readme/en_UK.md)

~~出于i18n的心态，我们可能会提供多语言文档，但是，众所周知，人类的本质是鸽子，况且本项目也还远未结束~~

~~提供的语言：简体中文、英式英文（其实可以有更多，反正是占坑）~~


## 最重要的Todo List

1.完善resource相关的函数，音声俱全

2.更多的了解合适的值得支持的引擎

3.引入图层系统，更好的对图层进行管理，不要只做单层战士

遥远的未来，我们也将随着自己标准的制定，不断推出更完善的官方编译器（complier）（Alang2Blang）和官方解释器（Unigal runtime）。但是我们觉得，我们自己做出来的解释器，无论如何都跟不上标准的不断变大和制定。并且我们本意不是做一个游戏引擎，因此不要奢求我们能做出多么好的解释器，我们只是想定义一个标准


4.研发对应的unigal在不同编辑器中统一的着色器，目前的XML着色器并不是最适合我们的，当然unigal的着色器肯定是在xml的基础上来改造。
例如，resource和action这样的，虽然都是code，但是差别很大，应该使用不同的颜色。
而code和text虽然都是body下的element，但是差别更大，因此也应该使用不同的颜色。
而struct一般是用于分割和结构上的提示作用，私以为应该给予非常醒目的表示。
这件事情宜早不宜迟，需要特事特办，尽快完成。首选sublime（这样就不用VS2017的傻逼着色了），没有人帮忙就自行完成。

此外，其他各种常见语言的Sublime着色器文件在此，均为第三方开发，而非引擎方提供。我们可能会在Unigal着色计划中引用这些开源代码。

BKE  在[官方教程](http://docs.bakery.moe/faq)中提及，在[Github](https://github.com/AllanZyne/BKS4Sublime)上有公开   AllenZyne开发，无人维护

librian https://github.com/RimoChan/Librian/tree/master/librian/librian%E6%9C%AC%E9%AB%94/%E5%9C%9F%E7%89%B9%E7%94%A2   Rimochan开发，chenmaster05维护

Nova 抱歉我没找到，我觉得可以滴滴一下开发者们

至于VSCode着色器……这个存在的吗？有这种插件的吗？（笑）

## 联系我们

~~联系我们（X）~~

联系我（√）

Email：keaitianxinmail@qq.com
