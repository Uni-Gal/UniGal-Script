# UniGal-Script

Offer a visuable way to switch and show the different possibility of a Galgame



## UniGal-Script介绍
首先感谢各位开发者对本项目的支持，在各种地方提及这个尚未成熟，仅仅写出了一个最基本最简单的编译器的小项目，之后还将进一步完善。

本项目是受Nova引擎的开发者提出的统一语法标准，也因为作者曾经学过不少引擎的使用和语法，对之间互不相同，迁移学习成本过高表示很头疼，因此才想到这一点。当然，这里面也有Librian开发者提供的支持和帮助。

~~不过，似乎本语法也不是什么好懂的东西啊（笑）~~

若要直接查看语法标准，请移步[语法标准](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-text.md)

## UniGal-Script特性
1. UniGal-Script为创造一种具有普适性的语法标准，因此采用了XML作为基础。之所以采用XML而不是JSON或YAML，可详见备注部分的文档。没有采用JSON或YAML，是为了保证一个能更好的适应更多环境的脚本
2. UniGal-Script是高度抽象化和反复封装的，因此对于一些较为简练的引擎来说，其语法显得较为繁琐。
3. UniGal-Script将演出与脚本与代码等合为一体，不再刻意强调演出与剧本之间的工作划分，不将其分割为多个不同文件，不参与素材属于演出还是脚本的名词争端。
4. UniGal-Script中凡是纯粹的文本内容，都用```<text></text>```包装，其他的均视为```<code></code>```包装

## 支持计划

首先说明，我们支持的引擎，将尽可能以开源世界和非常具有代表性的引擎为主，不对私有引擎提供支持，因为那将可能意味着本工具被用于破解和解包后重置使用。我们希望它只是一个工具。当然，工具不可能因为使用者的意图而选择展示自己的能力，但我们希望它仅仅是被用来辅助Galgame开发者的，而不是辅助未授权的破解者。

### 可能支持的允许导出的引擎
nova

librian

GameCreator~~（太棒了居然是JSON，差别不大，太棒了）~~（等一下，GC似乎是商业引擎）

### 准备支持的单向导入的引擎

krkr

BKE

librian

AVGPlus

snowing

unity-nova

unity-xihe animation engine

renpy

~~如果66rpg不会打我，我希望能制作橙光导出工具，虽然我在做梦~~

### 可能支持的单向导入的引擎
unity-Utage

unity-Fungus

## 教程与介绍目录

以下是UniGal-Script的文档的目录

Docs/zh_CN/UniGal-Script-main.md

Docs/zh_CN/UniGal-Script-text.md

Docs/zh_CN/UniGal-Script-code.md

Docs/zh_CN/UniGal-Script-basic.md

Docs/zh_CN/UniGal-Script-resource.md

Docs/zh_CN/UniGal-Script-Developer.md

以下是UniGal-Script的多语言Readme的目录

Readme



~~出于i18n的心态，我们可能会提供多语言文档，但是，众所周知，人类的本质是鸽子，况且本项目也还远未结束~~

~~提供的语言：简体中文、美式英文（其实可以有更多，反正是占坑）~~



## 联系我们

~~联系我们（X）~~

联系我（√）

Email：keaitianxinmail@qq.com
