# UniGal-text

**<text></text>**



text宏里面只封装纯粹与文本和剧本执行相关的内容



# BKE

参见http://docs.bakery.moe/new/quickstart/#_3

在BKE中，纯文本可以直接输入。在换行时以[p]结尾，[r]为手动换行，[l]为等待点击。行之间的换行采用(WINDOWS-CRLF)

在BKE官方API中给出的，涉及文本处理的非状态关键字有如下三种

|关键字|内容|
| ---- | ----- |
|r|手动换行|
|l|等待点击|
|p|换页等待，点击后换页|

因为BKE的脚本也涉及多代处理系统，因此用[]包装是可以的，而改为@的新方式也是可以的

鉴于较多复杂的效果函数采用@调用的方式，我们暂时仅处理[]包装的文本控制函数。

三种分别对应的UniGal中的行为如下
|关键字|内容|UniGal中的处理|对应的action|
| ---- | ----- | ----- | ----- |
|r|手动换行|插入action宏来分割part|newline|
|l|等待点击|插入action宏来分割part|waitclick|
|p|换页等待，点击后换页|||

注意，所有的换行和点击等一系列函数都不属于单纯的文本处理，应将其视作<code><action></action></code>中的一个函数

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
    <logic>
      <label>
        <label_name>
          main
        </label_name>
      </label>
    </logic>
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

暂未开源

在nova中，文本内容需要以|><|包装，在换行时直接自然换行(UNIX-LF)，结尾需要空行。
## Simple

>```txt
>|>
>坐在车厢里的人总会向外眺望。
>
>眺望的理由多种多样：
>晕车，发呆，欣赏风景……
>
>亦或者只是下意识地一瞥。
>
>但人们心中压抑的冲动都是相似的。
>
><|
>```


## Translate
```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      nova
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
          坐在车厢里的人总会向外眺望。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
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
          眺望的理由多种多样：
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
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
          晕车，发呆，欣赏风景……
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
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
          亦或者只是下意识地一瞥。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
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
          但人们心中压抑的冲动都是相似的。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal-script>
```

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

# renpy

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
    <logic>
      <label>
        <label_name>
          start
        </label_name>
      </label>
    </logic>
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