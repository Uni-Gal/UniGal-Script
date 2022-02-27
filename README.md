# UniGal-Script

Offer a visuable way to switch and show the different possibility of a Galgame

Note: UniGal may change to a BDFL language design mode. (Read in [中文](https://zh.wikipedia.org/wiki/%E7%BB%88%E8%BA%AB%E4%BB%81%E6%85%88%E7%8B%AC%E8%A3%81%E8%80%85) or [English](https://en.wikipedia.org/wiki/Benevolent_dictator_for_life))

-----

关于一些新的可能存在的进化演变方向的探讨

我们可能将不仅面向Galgame的剧本，更试着引入一些支持从通用编剧领域进入的作者。按照饱受诟病的“上位艺术”理论的原则，Galgame在文学和戏曲领域分别都有一个“上位艺术”，即**小说**和**戏剧（话剧&影视剧）**。随着Galgame编剧能力的壮大，这两个相关领域的编剧试水Galgame编剧，也是存在可能的。
那么，如何适应这带给我们的剧本风格和形式结构上的变化，是有必要的。

对于小说来说，更多的在于长句和段落化，以及如果要做到好的演出效果，可能需要的丰富美术素材，但这不涉及技术问题。小说家常使用```Notepad(.txt)```或者```Word(.doc/.docx)```来撰写他们的剧本，极少标注演出效果的符号，即使有也是在括号内添加。Galgame从业人员直接逐字逐句切分为剧本格式就可以了。
对于戏剧来说，目前，不论是各大院校内才有的学院派，还是好莱坞和横店才有的影视工业，编剧导演们，一般不采用单纯的文本或富文本编辑器，而是使用专门的编剧工具。在一些其他的非Galgame的游戏中，有时候涉及到剧情的时候，也有不少Unity系的开发者自己创造了一套剧情撰写工具。

我们查找Github后，找到了这些可能会有帮助的项目：
```plaintext
https://github.com/Kozea/pygal
https://github.com/LittleLittleStory/TinyDialogueEditor
https://github.com/zhongcaojieji/TimelineScript
https://github.com/xdedzl/StoryKit
https://github.com/Tangoyzx/WordEditor
```

而对于纯编剧软件的话，通过查阅资料了解，我们也逐渐了解到编剧领域是有非常复杂且封闭的编剧软件的。或许有一天会有人以UniGal-Script开发剧情编辑器吗？谁知道呢？不过我们会考虑引入一些对剧情编辑软件的支持的。比如Fountain编剧语言是基于markdown这门标记语言而特化的标记语言，我们有信心在年内给出基于正则的parser以及编译为UniGal-Script这份IR的Complier

相应的，您可以参考这些文章：
```plaintext
https://www.zhihu.com/question/43343445/answer/137042561
http://fountain.io/
https://sspai.com/post/40467
```

很庆幸，之前做的UniGal-Diagram的工作，是一套偏向数学和理论意义上的抽象工作，而非实际工程。因为Galgame的剧情流程比很多常见的影视剧更为复杂，因此我们觉得它是能服务于多种人群的，也包括编剧行业。当然，人物关系图，我们暂没有添加进Diagram的想法，是因为它属于编剧的辅助工具，不服务于抽象的剧情结构，而是剧情的附属物。欢迎各位提出自己的实现，百花齐放。

-----

## UniGal-Script介绍
首先感谢各位开发者对本项目的支持，在各种地方提及这个尚未成熟，仅仅写出了一个最基本最简单的编译器的小项目，之后还将进一步完善。

本项目是受Nova引擎的开发者提出的统一语法标准，也因为作者曾经学过不少引擎的使用和语法，对之间互不相同，迁移学习成本过高表示很头疼，因此才想到这一点。当然，这里面也有Librian开发者提供的支持和帮助。

~~不过，似乎本语法也不是什么好懂的东西啊（笑）~~

若要直接查看语法标准，请移步[语法标准](./Docs/zh_CN/UniGal-text.md)

UniGal是一个完整的项目，分为标准，实现，提案三部分。

标准分为[Script](https://github.com/Uni-Gal/UniGal-Script)(脚本语法)、[Diagram](https://github.com/Uni-Gal/UniGal-Diagram)(流程图语法)、PolyDB(针对作品的管理系统)

实现分为编译器、解释器、渲染器三部分。其中，目前维护的有两个编译器分支，未来可能为其赋予代号以便区分。

UniGal有自己的异常处理提案[EnforcementProposal(UEP)](https://github.com/Uni-Gal/UniGal-EnforcementProposal)。

## UniGal-Script特性

1. UniGal-Script为创造一种具有普适性的语法标准，因此采用了XML作为基础。之所以采用XML而不是JSON或YAML，可详见备注部分的文档。没有采用JSON或YAML，是为了保证一个能更好的适应更多环境的脚本。此外，有的引擎基于js所以偏向JSON，有的基于Python所以偏向YAML，如果分别维护分支，工作量会很大，会很难维护的过来。

   此外，现在各种常见编程语言下，不论是XML还是JSON，都有很成熟的库可以互相转换。因此，出于可交换性和统一性的考虑，只提供一个XML的写法。如果您有具体的需要，我们认为这个应该是引擎内完成的转换（UniGal.Compilers.FrontEnd和Unigal.Compilers.IR要吗，.NET专用的）。

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

## Code of conduct环节  
曾经的惨痛教训使得我们制定这一章内容，日后这段长了也会独立成文    
实验性项目的文件名应以`exp-`（取experimental缩写）为前缀，如`exp-textv2.md`  
在主仓库的实验性项目都应新建一个分支，该分支也以`exp-`作为前缀，接受社区p判后再由dev/script团队投票决定是否融入主分支  

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
