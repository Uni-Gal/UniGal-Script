# UniGal-text

text宏里面只封装纯粹与文本和剧本执行相关的内容



# BKEngine

参见http://docs.bakery.moe/new/quickstart/#_3

在BKE中，纯文本可以直接输入。在换行时以[p]结尾，[r]为手动换行，[l]为等待点击。行之间的换行采用(WINDOWS-CRLF)

在BKE官方API中给出的，涉及文本处理的非状态关键字有如下三种。

因为BKE的脚本也涉及多代处理系统，因此用[]包装是可以的，而改为@的新方式也是可以的。鉴于较多复杂的效果函数采用@调用的方式，我们暂时仅处理[]包装的文本控制函数。

三种分别对应的UniGal中的行为如下
|关键字|内容|UniGal中的处理|对应的action|
| ---- | ----- | ----- | ----- |
|r|手动换行|插入action宏来分割part|newline|
|l|等待点击|插入action宏来分割part|waitclick|
|p|换页等待，点击后换页|结束一个```<text></text>```|无|

注意，所有的换行和点击等一系列函数都不属于单纯的文本处理，应将其视作```<code><action></action></code>```中的一个函数

此外，加粗/倾斜/删除线/下划线 四个状态已通过/text/character/style或/text/content/style加入到```<text></text>```中

## Simple

>```bkscr
>*main
>你好，[l][r]世界！[p]
>```

## Translate
```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      BKE
    </src>
  </head>
  <body>
    <struct>
      <label>
        <label_name>
          main
        </label_name>
      </label>
    </struct>
    <text>
      <character>
        <name>
          NULL
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          你好，
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <code>
      <action>
        <textcontrol>
          waitclick
        </textcontrol>
      </action>
    </code>
    <code>
      <action>
        <textcontrol>
          newline
        </textcontrol>
      </action>
    </code>
    <text>
      <character>
        <name>
          NULL
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          世界！
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal-script>
```

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

## Guess

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


## Simple

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

# Librian

参见https://doc.librian.net/site/%E7%94%A8%E6%88%B6%E6%8C%87%E5%8D%97/%E5%8A%87%E6%9C%AC%E5%AF%AB%E6%B3%95.html

librian中的一个文本是直接结束的

单行即为一句话

姓名位于文本前，要求显式给出，文本内容用繁体中文的引号包装

总之，librian的基本文本语法较为简单

### Simple

>```liber
>潘大爺 「舟舟！來得正是時候！」
>```

### Translation

```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      Librian
    </src>
  </head>
  <body>
    <text>
      <character>
	<name>
          潘大爺
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          舟舟！來得正是時候！
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal-script>
```

# Renpy

参见https://www.renpy.cn/doc/quickstart.html#a-simple-game

rpy有一个比较恶心的地方是

它的姓名不一定是每句话都定义的

而是可能在开始使用宏定义

总之，renpy的基本文本语法较为简单



那么

这是一段示范文本

**【注意！文本和姓名的颜色目前尚未正式引入概念，下面的```<color></color>```仅仅作为实验性功能，是可选的而非必须的】**

### Simple

>```python
>define s = Character('希尔维亚', color="#c8ffc8")
>define m = Character('我', color="#c8c8ff")
>
>label start:
>
>    s "不久之后，我们就抵达了牧场，也是我们俩人出生的地方"
>
>    "鼠宝宝" "我就是在这样的风景环绕之中成长起来的。这里的秋天格外秀美。"
>
>    s "童年时，我们经常在牧场里玩耍，所以这里满满充斥着回忆。"
>
>    m "嗨……唔……"
>
>```

### Translation

```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      Renpy
    </src>
  </head>
  <body>
    <struct>
      <label>
        <label_name>
          start
        </label_name>
      </label>
    </struct>
    <text>
      <character>
        <name>
          希尔维亚
        </name>
        <color>
          #c8ffc8
        </color>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          不久之后，我们就抵达了牧场，也是我们俩人出生的地方
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <character>
        <name>
          鼠宝宝
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          我就是在这样的风景环绕之中成长起来的。这里的秋天格外秀美。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <character>
        <name>
          希尔维亚
        </name>
        <color>
          #c8ffc8
        </color>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          童年时，我们经常在牧场里玩耍，所以这里满满充斥着回忆。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <character>
        <name>
          我
        </name>
        <color>
          #c8c8ff
        </color>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          嗨……唔……
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal-script>
```



# AVGPlus

参见https://docs.avg-engine.com/handbook/api/text/

此外，其他同样以JSON存储的引擎还有 GameCreator monogatari

### Simple-1

>```
>// 单次对话
>text.show(
>"是我，是我先，明明都是我先来的……接吻也好，拥抱也好，还是喜欢上那家伙也好……",
>);
>```

### Translation-1

```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      AVGPlus
    </src>
  </head>
  <body>
    <text>
      <character>
	<name>
          NULL
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          是我，是我先，明明都是我先来的……接吻也好，拥抱也好，还是喜欢上那家伙也好……
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal-script>
```

### Simple-2

>```
>// 使用数组可以在同一次调用里显示多次连续对话
>// 通过在参数中指定 name 字段指定说话人名字
>text.show(
>[
>"为什么会变成这样呢……第一次有了喜欢的人。有了能做一辈子朋友的人。",
>"两件快乐事情重合在一起。而这两份快乐，又给我带来更多的快乐。",
>"得到的，本该是像梦境一般幸福的时间……但是，为什么，会变成这样呢……~",
>"只要给 options 对象定义 name 字段，就会在对话中显示名字了。",
>"多次连续对话会使用同一个名字。",
>],
>{
>name: "愤怒的泡面",
>},
>);
>```

/*这数组，难对付啊*/

### Translation-2


```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      AVGPlus
    </src>
  </head>
  <body>
    <text>
      <character>
	<name>
          愤怒的泡面
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          为什么会变成这样呢……第一次有了喜欢的人。有了能做一辈子朋友的人。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <character>
	<name>
          愤怒的泡面
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          两件快乐事情重合在一起。而这两份快乐，又给我带来更多的快乐。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <character>
	<name>
          愤怒的泡面
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          得到的，本该是像梦境一般幸福的时间……但是，为什么，会变成这样呢……~
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <character>
	<name>
          愤怒的泡面
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          只要给 options 对象定义 name 字段，就会在对话中显示名字了。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <character>
	<name>
          愤怒的泡面
        </name>
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <part>
          多次连续对话会使用同一个名字。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal-script>
```

# Monogatari

教程文档https://developers.monogatari.io/documentation/building-blocks/script-and-labels

## Simple-1

```
const person = {
    'name': 'Jane Doe',
    'age': 24
};
```
## Simple-2

```
monogatari.script ({
    'Start': [
        'Hi there!',
        'This is a list of statements',
        'jump myLabel'
    ],
    'myLabel': [
        'And this is yet another label',
        'Also a list of statements',
        'end'
    ]
});
```

注意label是属于struct的而不是属于logic的了哦
logic现在是属于code的树下面的一种函数了哦

## Translation
没啥可翻译的，建议直接看AVGPlus的Translation就好了

# GameCreator

制作中(其实是开发者偶尔看到了日日夜夜的补丁后发现了剧本格式是JSON，现在还没找到GC的官方教程因此不可能把拆包的内容拿出来作为Simple的)
教程和iFAction一样，都是只有偏重RPG的教程，AVG的文档都没有，怀疑AVG都是拿这个用js改出来的。
https://www.gamecreator.com.cn/gc/document/?file=003-GC%E6%9C%AC%E4%BD%93%E6%96%87%E6%A1%A3/0001-%E5%85%B3%E4%BA%8EGC

# iFAction
不会有的，纯商业引擎，一般不考虑导出，而且这个iF是有加密素材的，我们也不可能读取出来，读取它等于和制作方过不去。
