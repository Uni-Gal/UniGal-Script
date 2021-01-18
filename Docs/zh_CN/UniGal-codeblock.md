# UniGal-codeblock

code部分主要涉及内嵌代码段

如果某个语言有一整段难以被翻译且较为整体的内容，我们允许暂时不进行转换，整段保留。

请注意，含有代码段的无法生成目标平台的语言。

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

```
<codeblock enginefamily="Librian" enginename="Librian" lang="CSS">
    <!-- 实际CSS代码 -->
</codeblock>
<codeblock enginefamily="Librian" enginename="Librian" lang="Python">
    <!-- 实际Python代码 -->
</codeblock>
```