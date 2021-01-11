# UniGal-code
示例
```XML
<code engine="Unity" lang="CSharp">
    <!-- 实际C#代码 -->
</code>
```


# BKE
关于BKE的文本效果补充部分

### 文本效果 补充

在BKE中，[p]，[r]，[l]三个文本相关的之外，另外有直接作用于文本的如[i],[b],[s],[u],[er]等五种文字显示的无参函数以及@storefont、@restorefont两种储存文本状态的

在BKE官方API中给出的，涉及文本处理的非状态关键字有如下三种

|关键字|内容|
| ---- | ----- |
|i|开关斜体(这个决定添加到text)|
|b|开关粗体(这个决定添加到text)|
|s|开关删除线(这个决定添加到text)|
|u|开关下划线(这个决定添加到text)|
|er|清除消息层上文字(这个决定添加到code/action)|

此外，关于储存文本状态的，还有这两个函数

|关键字|内容|备注|
| ---- | ------ |---|
|storefont|如果多次storefont，只会保存最后一次的结果。用restorefont命令可以将字体设为最后一次storefont时的状态。|暂存字体信息|
|restorefont||复原字体信息|



这部分的代码可以如下实例

Simple

```bkscr

```

## 文本控制类代码

这类效果应由解释器实现，我们不应过多干涉

text
textcursor
textwindow
textoff
texton
textspeed
textstyle
texttag
textsprite



## Nova

关于Nova的文本效果补充部分

### 文本效果 补充

咕



关于Nova的演出和资源素材部分

### 资源与素材

咕

### 演出

咕

