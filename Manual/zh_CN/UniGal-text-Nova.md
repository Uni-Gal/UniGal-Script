# nova

[Nova引擎](https://github.com/Lunatic-Works/Nova)已于近日以MIT协议开源,[wiki](https://github.com/Lunatic-Works/Nova/wiki)

Nova的脚本格式可以参见本文档[Nova--Script](https://github.com/Lunatic-Works/Nova/wiki/NovaScript)

>一部作品的脚本由许多节点（node）组成。脚本可以被拆分为多个文件，一个文件中可以有多个node。脚本解析的结果与读取文件的顺序无关。
>
>每个节点的开头和结尾处各有一个提前代码块（eager execution block），语法为`@<| ... |>`。它记录着关于节点的信息，比如每一章的标题和分支选项等等，在游戏开始之前执行。
>
>一个节点中有很多“条”对话（dialogue entry）。每条对话可以包括一个延迟代码块（lazy execution block），语法为`<| ... |>`，以及一些文本。延迟代码块记录着这条对话对应的演出代码，在游戏过程中执行。

>两条对话之间由一个空行分隔。一条对话的文本可以有许多行。如果文本中需要空行，可以写一个空的XML标记`<p/>`。
>
>延迟代码块和文本之间不应该有空行。（如果有空行，就会变成两条对话，点一下鼠标执行代码，再点一下鼠标播放文本。）节点开头的提前代码块和第一条对话之间，以及最后一条对话与结尾的提前代码块之间，也不应该有空行。

在换行时直接自然换行(UNIX-LF)，结尾需要空行。

说实话，NovaScript较难理解，暂时我们还没想出比较好的转换方法，请不要依照这个作为撰写标准。

而且我很好奇，何为提前，何为延迟?

### Guess

下面是对一个Nova的节点（Node）的结构的猜想，若有不妥还请指出

~~说实话这个姓名和对话的分割让我想起了命名空间，好嘛，每个人就是一个Class~~

```lua
@<|
//位于开头的提前代码块（eager execution block）//
>|

<|
//某条控制语句的延迟代码块（lazy execution block）//
>|

鼠宝宝：：今天我们来看看UniGal的脚本吧
UniGal::请多多指教
<p/>
引擎A：：“我要原生支持它！”
引擎B：：「啊，果然還是XML的運行程式讓我看起來舒服一些，比YAML好多了！」
鼠宝宝：：不要随便商业互吹啊kura！我自己写的什么东西我会不清楚吗！
...

<|
//某条控制语句的延迟代码块（lazy execution block）//
>|

鼠宝宝：：那么我们今天的学习就到这里了，同学们再见喵~

@<|
//位于结尾的提前代码块（eager execution block）//
>|
```


### Simple

>```lua
>@<|
>label('ch1', '第一章')
>is_default_start()
>|>
>
><|
>anim:trans_fade(cam, function()
>show(ergong, 'normal', pos_c)
>show(bg, 'room')
>end, 2)
>play(bgs, 'rain')
>anim:volume(bgs, 0.2, 3)
>box_hide_show(2)
>auto_voice_on('王二宫', 1)
>auto_voice_on('陈高天', 1)
>set_auto_voice_delay(2)
>|>
>
>王二宫：：“真没想到，我们竟然会被暴雨困在了教学楼里。”
>
><|
>show(qianye, 'normal', pos_c)
>sound('flap', 0.5)
>|>
>
>我出门的时候，依旧可以感觉到有目光追随着我的背影。
>@<| jump_to 'ch2' |>
>```