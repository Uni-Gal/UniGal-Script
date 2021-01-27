# UniGal-reference

本文档主要讲述了各个语言中的很多细节特征，算是一定程度上的参考大全了。

用来方便开发者迅速的找到不同语言中的细节定义，方便后续完善和更改。

这个文档中的，就是很快会添加到正式的内容中去的。


## 各引擎维护团队联系名录

**librian** https://doc.librian.net/site/%E4%B8%BB%E9%A0%81.html 官方QQ群618775838

**avgplus** https://docs.avg-engine.com/ 官方QQ群323092720

**BKEngine** http://docs.bakery.moe/ 官方QQ群303680897

**nova** [Nova引擎](https://github.com/Lunatic-Works/Nova)已于近日以MIT协议开源,在这里可以查看[wiki](https://github.com/Lunatic-Works/Nova/wiki)。Nova的脚本格式可以参见本文档[Nova--Script](https://github.com/Lunatic-Works/Nova/wiki/NovaScript)    官方QQ群（不仅是引擎）876212259

**renpy** https://www.renpy.org/doc/html/ TG群都莫得就别想QQ了（简中文档https://www.renpy.cn/doc/index.html）

**krkr**（不存在的吧）（https://github.com/krkrz/krkrz  这个算吗说实话我对KR系的一大家子产品没啥了解和认识）

（官方不存在了听说这个民间版很有名http://blog.sina.com.cn/s/articlelist_1251573991_5_1.html 和这个 https://tieba.baidu.com/p/1236613654）

**monogatati** [官网](https://monogatari.io/)  [教程和文档](https://developers.monogatari.io/documentation/)


## 各引擎需要维护和整理成unigal特性的部分






### Nova

关于Nova的文本效果补充部分

#### 文本效果 补充

咕



关于Nova的演出和资源素材部分

#### 资源与素材

咕

#### 演出

咕

## 希望能给各引擎开发者的建议

### 对于引擎开发者而言的支持方式

#### 原生支持

若希望能在您的引擎中提供对UniGal-Script的原生支持

需要您的引擎能至少支持XML的解析。这需要您开发引擎使用的编程语言有一个强大的XML解析库。幸运的是，目前的主流编程语言生态都可为您提供这类的库。

对于C语言开发者而言，可以考虑使用lib2xml或？？？（若您使用C++，亦可使用XXX）

对于python开发者而言，可以考虑使用？？？（总之只是简单的把Librian中的纯文本部分导出成unigal其实没难度？@rimochan 

对于Java开发者而言，（@hokaso 

对于C#开发者而言，建议使用System.Xml用于解析UniGal脚本，或者等待[UniGal.Compiler.Frontend](https://github.com/Uni-Gal/UniGal.Compilers)做完

对于Node.js开发者而言（说你呢面叔

~~请以上被捕捉的开发者们不要来打我~~

#### 非原生支持

若您的引擎虽然不方便提供UniGal-Script的原生支持，但希望能使其模式较为通用友好

欢迎您将您的设计思路与我们沟通，共同调整不同的抽象方法

### 对于脚本开发者而言

希望您能帮我们多画饼，多拆几个原子操作

### 对于编译器开发者而言

**膜**！不过这个我们需要先实现编译器的前端既句法分析。至于代码生成的后端可以之后再做
