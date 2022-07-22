# UniGal-中文文档


<!-- 顺序有待调整，是按照字母顺序还是按照重要性，有待研究。但如果按照重要性，resource要放在text之后了？ -->

## 先看这个

### [UniGal-main.md](UniGal-main.md)

如果要整体了解所有各类已经有的原子操作，相当于以下resource、text、layer、code的总大纲。

## 引擎相关

### [UniGal-text.md](EngineSide/UniGal-text.md)

本文档重点强调了各个引擎中的文本控制方式，也是Galgame的核心——文字。

+ [BKEngine](../../Manual/zh_CN/UniGal-text-BKEngine.md)
+ [Nova](../../Manual/zh_CN/UniGal-text-Nova.md)
+ [Librian](../../Manual/zh_CN/UniGal-text-Librian.md)
+ [Renpy](EngineSide/UniGal-text.md#Renpy)
+ [AVGPlus](EngineSide/UniGal-text.md#AVGPlus)
+ [Monogatari](EngineSide/UniGal-text.md#Monogatari)
+ [GameCreator](EngineSide/UniGal-text.md#GameCreator)
+ [iFAction](EngineSide/UniGal-text.md#iFAction)

### [UniGal-code-resource.md](UniGal-code-resource.md)

想看资源调度和素材管理相关的部分，可以参考本文档。

+ [BKEngine](../../Manual/zh_CN/UniGal-code-resource-BKEngine.md)
+ [Librian](../../Manual/zh_CN/UniGal-code-resource-Librian.md)
+ [Nova](../../Manual/zh_CN/UniGal-code-resource-Nova.md)
+ [AVGPlus](../../Manual/zh_CN/UniGal-code-resource-AVGPlus.md)

### [UniGal-code-animation.md]()

### [UniGal-code-action.md]()

### [UniGal-code-codeblock.md](UniGal-code-codeblock.md)
想看内嵌代码段，看codeblock。目前尚不够完善，欢迎您来开荒式的定义。

### [UniGal-layer.md](UniGal-layer.md)
想看图层的实验性选项，看layer。目前尚不够完善，欢迎您来开荒式的定义。

## 引擎无关

### [UniGal-enforcement_proposal.md](StandardSide/UniGal-enforcement_proposal.md)
UniGal的异常处理提案。用于解决不同引擎间转换不完美的问题和处理错误。
若要详细了解建议移步[Uni-Gal/UniGal-EnforcementProposal](https://github.com/Uni-Gal/UniGal-EnforcementProposal/)。

### [UniGal-reference.md](StandardSide/UniGal-reference.md)
啥都不想看只看还有什么需要拆分操作，看

### [UniGal-filesystem.md](StandardSide/UniGal-filesystem.md)
啥都不想看只看还有什么需要拆分操作，看reference

### [UniGal-environment.md]()

### [UniGal-keyword.md]()

关于UniGal中的可互换关键词

此外，有同行提到的关于unigal中的关键词问题，unigal中如果说是描绘一个功能的关键词，您可以看main这个文档和resource、layer、text

但是如果是说保留字关键词的话，我想unigal不存在保留字的问题，因为它的内容一定是被xml的令牌封装起来的。


## UniGal不会涉及的

UniGal不会涉及DRM加密方面的内容，也不会涉及已编译完成的游戏解包并转换格式的内容。

一是不同引擎之间的DRM加密实现方法存在巨大的差异，粒度也各有千秋，难以统一。且这方面的实现和细节对于引擎间迁移并无帮助，有时这就是可以防止迁移而涉及的。

二是关于DRM实现方面的标准，若以具体引擎作为例子，将会助长反编译和破解的势头，对游戏开发者不利。同时容易让引擎作者和游戏开发者因为利益相关而冒犯。

三是该部分研究不存在也不应存在通用标准。DRM加密就本应当是站在出其不意的地方验证来恶心破解者的，因此我们若非破解者，对这部分进行定义和规范是没有任何必要的。

但我们仍无法百分百的阻止有心之人基于本标准开发破解技术，因为没有百分百可靠的技术。
