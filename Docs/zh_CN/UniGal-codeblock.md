# UniGal-codeblock

code部分主要涉及内嵌代码段。如果某个语言有一整段难以被翻译且较为整体的内容，我们允许暂时不进行转换，整段保留。

请注意，含有代码段的无法生成目标平台的语言。

此外，有必要对```<codeblock></codeblock>```和```<extension></extension>```进行区分。

前者是暂时未定义详细的拆分方式或者有意保留的嵌入部分，但均为必要的；后者是属于语言的特色功能，或者可选的如steamAPI相关内容等非必须内容。

但请注意，live2d和spine等资产应属于```<resource></resource>```管理。

此外，对于嵌入代码块的作用域尚有争议，目前参数已经非常多，不宜再添加新的参数，全局还是局部需要有一些处理方式。

## Simple1

同一引擎代系，但不同的引擎，（例如同源自Unity的多个框架，虽然各有差异算作多个引擎，但均应归为同一引擎代系Unity中），可能存在部分可以通用的代码，也可能没有。

在实际使用中，若```enginefamily```和```lang```均一致，在```<strict></strict>```中bool变量不为```true```的时候，可以允许进行代换。

```XML
<codeblock enginefamily="Unity" enginename="Unity-Nova" lang="Lua">
    <!-- 实际Lua代码 -->
</codeblock>
<codeblock enginefamily="Unity" enginename="Unity-Utage" lang="CSharp">
    <!-- 实际C#代码 -->
</codeblock>
<codeblock enginefamily="Unity" enginename="Unity-Fungus" lang="CSharp">
    <!-- 实际C#代码 -->
</codeblock>
```
## Simple2

部分引擎允许无条件的内嵌多种不同语言的代码，并允许多种不同的解释器的存在，根据不同情况调用。

这类情况的特点是仅有```lang```存在差异。

关于具体引擎您可以参考具体引擎的规范来实现。[Librian的实现](https://doc.librian.net/site/%E9%80%B2%E9%9A%8E/%E5%B5%8C%E5%85%A5%E4%BB%A3%E7%A2%BC.html)

```
<codeblock enginefamily="Librian" enginename="Librian" lang="CSS">
    <!-- 实际CSS代码 -->
</codeblock>
<codeblock enginefamily="Librian" enginename="Librian" lang="Python">
    <!-- 实际Python代码 -->
</codeblock>
```