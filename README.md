# UniGal-Script

Offer a visuable way to switch and show the different possibility of a Galgame

## UniGal-Script介绍
首先感谢各位开发者对本项目的支持，在各种地方提及这个尚未成熟，仅仅写出了一个最基本最简单的编译器的小项目，之后还将进一步完善。

本项目是受Nova引擎的开发者提出的统一语法标准，也因为作者曾经学过不少引擎的使用和语法，对之间互不相同，迁移学习成本过高表示很头疼，因此才想到这一点。当然，这里面也有Librian开发者提供的支持和帮助。

~~不过，似乎本语法也不是什么好懂的东西啊（笑）~~

若要直接查看语法标准，请移步[语法标准](./Docs/zh_CN/UniGal-text.md)

UniGal是一个完整的项目，分为[Script](https://github.com/Uni-Gal/UniGal-Script)(脚本语法)、[Diagram](https://github.com/Uni-Gal/UniGal-Diagram)(流程图语法)、[Complier&Interpreter](https://github.com/Uni-Gal/UniGal-Complier-Interpreter)(编译器和解释器)三部分。欢迎您查看其他两部分的内容。

此外，UniGal也有自己的异常处理提案UEP，若要进一步了解请移步[ExceptionProposal(UEP)](https://github.com/Uni-Gal/UniGal-ExceptionProposal)。

## UniGal-Script特性

1. UniGal-Script为创造一种具有普适性的语法标准，因此采用了XML作为基础。之所以采用XML而不是JSON或YAML，可详见备注部分的文档。没有采用JSON或YAML，是为了保证一个能更好的适应更多环境的脚本
2. UniGal-Script是高度抽象化和反复封装的，因此对于一些较为简练的引擎来说，其语法显得较为繁琐。
3. UniGal-Script将演出与脚本与代码等合为一体，不再刻意强调演出与剧本之间的工作划分，不将其分割为多个不同文件，不参与素材属于演出还是脚本的名词争端。
4. UniGal-Script中凡是纯粹的文本内容，都用```<text></text>```包装，其他的均视为```<code></code>```包装。
5. UniGal-Script中的标签名称，尽可能做到不同层级间独一无二，力求精确，让一类标签和特定属性挂钩。表签尽可能做到语义化，标签名自注释，不和HTML5时代的网页前端一样通过class来进行定义和分类。
6. UniGal-Script不论是什么文件皆以unigal结尾，若要区别应关注不同文件的根元素的标签值为何。可以为```<unigal-script>```、```<Node>```、```<stylesheet>```

## 支持计划

首先说明，我们支持的引擎，将尽可能以开源世界和非常具有代表性的引擎为主，不对私有引擎提供支持，因为那将可能意味着本工具被用于破解和解包后重置使用。我们希望它只是一个工具。当然，工具不可能因为使用者的意图而选择展示自己的能力，但我们希望它仅仅是被用来辅助Galgame开发者的，而不是辅助未授权的破解者。

出于便于交流的目的，我们不对Galgame和VisualNovel的词汇进行明确的划分，视为同一含义。

此外，我们不会支持橙光文字游戏制作工具——**业界毒瘤**。捆绑平台，逼迫作者吊死在自家一颗树上。UniGal不建议非乙女向且有非橙光社群以外的收入计划的任何开发者盲目入坑此工具，直至橙光允许用户自由的本地的打包游戏为止。

**注意：支持列表仅在一定程度上大致表示我们的支持顺序，并不代表UniGal对所述引擎任何程度的支持与认可。**

详细的支持列表可以参见[此处](Readme/zh_CN/UniGal-supportlist.md)。

## 教程与介绍目录

以下是UniGal-Script的多语言文档的目录

[zh_CN.md](./Docs/zh_CN/README.md)

[en_UK.md](./Docs/en_UK/README.md)

以下是UniGal-Script的多语言Readme的目录

[zh_CN.md](./Readme/zh_CN/README.md)

[en_UK.md](./Readme/en_UK/README.md)

~~出于i18n和a11y的心态，我们可能会提供多语言文档。我们提供的语言有：简体中文、英式英文（其实可以有更多，反正是占坑）。但是，众所周知，人类的本质是鸽子，况且本项目也还远未结束~~


## 最重要的Todo List

1.完善resource相关的函数，音声俱全

2.更多的了解合适的值得支持的引擎

3.引入图层系统，更好的对图层进行管理，不要只做单层战士

遥远的未来，我们也将随着自己标准的制定，不断推出更完善的官方编译器（complier）（Alang2Blang）和官方解释器（Unigal runtime）。但是我们觉得，我们自己做出来的解释器，无论如何都跟不上标准的不断变大和制定。并且我们本意不是做一个游戏引擎，因此不要奢求我们能做出多么好的解释器，我们只是想定义一个标准


4.研发对应的unigal在不同编辑器中统一的着色器，目前的XML着色器并不是最适合我们的，当然unigal的着色器肯定是在xml的基础上来改造。
例如，resource和action这样的，虽然都是code，但是差别很大，应该使用不同的颜色。
而code和text虽然都是body下的element，但是差别更大，因此也应该使用不同的颜色。
而struct一般是用于分割和结构上的提示作用，私以为应该给予非常醒目的表示。
这件事情宜早不宜迟，需要特事特办，尽快完成。首选sublime（这样就不用VS2017的傻逼着色了），VSCode也是可选可行的。没有人帮忙就自行完成。

此外，其他各种常见语言的Sublime着色器文件在此，均为第三方开发，而非引擎方提供。我们可能会在Unigal着色计划中引用这些开源代码。

BKE  

在[官方教程](http://docs.bakery.moe/faq)中提及，在[Github](https://github.com/AllanZyne/BKS4Sublime)上有公开   由AllenZyne开发，无人维护

librian 

在github上有[librian着色器](https://github.com/RimoChan/Librian/tree/master/librian/librian%E6%9C%AC%E9%AB%94/%E5%9C%9F%E7%89%B9%E7%94%A2) ，由Rimochan开发，由chenmaster05维护

Nova 

官方提供了[Nova基于VSCode的着色插件](https://github.com/zhouhaoyu/vscode-nova-script)，并据开发者称，其语法与lua有相似之处，在着色方案上可以参考。Nova开发团队较活跃，维护较为积极。

## 联系我们

~~联系我们（X）~~

联系我（√）

Email：keaitianxinmail@qq.com
