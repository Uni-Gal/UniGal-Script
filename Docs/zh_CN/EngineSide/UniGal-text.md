# UniGal-text

text宏里面只封装纯粹与文本和剧本执行相关的内容

# 注意：本文档仅存放原子意味上的text
# 关于实验性的多层次结构的text请参考根目录下code部分

## text的定义
```xml
<unigal-script>
    <body>
    <text>
      <character>
        <name>
          NULL
        </name>
        <color>
          <!--文本颜色-->
        </color>
        <ruby>
          <!--可以加入注音-->
        </ruby>
        <style>
          <size></size>
          <bold></bold>
          <italic></italic>
          <deleted></deleted>
          <underlined></underlined>
            <shadow></shadow>
            <shadowcolor></shadowcolor>
            <glow></glow>
            <glowcolor></glow>
          <!--style中只允许填写bool值，即true与false,除shadowcolor和glowcolor-->
        </style>
        <!--Character是姓名相关，其中name是必须有的，而color和ruby是非必须的。此外，bold/italic/deleted/underlined也是非必须的-->
      </character>
      <content>
       <page>
        <para>
          <!--内容-->
        </para>
        <color>
          <!--文本颜色-->
        </color>
        <ruby>
          <!--可以加入注音-->
        </ruby>
        <style>
          <size></size>
          <bold></bold>
          <italic></italic>
          <deleted></deleted>
          <underlined></underlined>
          <shadow></shadow>
          <shadowcolor></shadowcolor>
          <glow></glow>
          <glowcolor></glow>
          <!--style中只允许填写bool值，即true与false,除shadowcolor和glowcolo,至于颜色用什么格式，回头再定，反正都是RGB系统不会出CMYK和YUV之类变态-->
          <!--shadow和glow若没指定对应的颜色，则shadowcolor默认纯黑，glowcolor默认纯白-->
        </style>
        <!--content是文本相关,可以叠若干个page。每个page中part是必须有的（当然也可以没有，但是需要留一个全角空格，半角的不行，parser不当字），而color和ruby是非必须的。content允许多个page连写以压缩空间和方便后期处理。(仅当character完全相同的时候)-->
        </page>
        <page></page>
        <page></page>
      </content>
    </text>
    </body>
    </unigal-script>
```
## text的指南

### Renpy

参见https://www.renpy.cn/doc/quickstart.html#a-simple-game

rpy有一个比较恶心的地方是

它的姓名不一定是每句话都定义的

而是可能在开始使用宏定义

总之，renpy的基本文本语法较为简单



那么

这是一段示范文本

**【注意！文本和姓名的颜色目前尚未正式规范化】**

#### Simple

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

#### Translation

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
      <page>
        <para>
          不久之后，我们就抵达了牧场，也是我们俩人出生的地方
        </para>
        <comment>
          //文本内容
        </comment>
        </page>
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
      <page>
        <para>
          我就是在这样的风景环绕之中成长起来的。这里的秋天格外秀美。
        </para>
        <comment>
          //文本内容
        </comment>
        </page>
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
      <page>
        <para>
          童年时，我们经常在牧场里玩耍，所以这里满满充斥着回忆。
        </para>
        <comment>
          //文本内容
        </comment>
        </page>
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
      <page>
        <para>
          嗨……唔……
        </para>
        <comment>
          //文本内容
        </comment>
        </page>
      </content>
    </text>
  </body>
</unigal-script>
```



### AVGPlus

参见https://docs.avg-engine.com/handbook/api/text/

此外，其他同样以JSON存储的引擎还有 GameCreator monogatari

但是，AVGPlus和BKEngine一样有着一些存放在下标中的文本控制标识符，详情见[AVGPlus文档](https://docs.avg-engine.com/handbook/api/text/#3)

现摘录于此方便查照

>
>| 控制符类型 | 说明    | 语法   |
>| ------ | ------ | --------- |
>| 粗体       | 字体加粗显示                                                 | [b]粗体[/b]                                 |
>| 斜体       | 字体斜体                                                     | [i]斜体[/i]                                 |
>| 文本颜色   | 更改文本颜色， | [c=#FF0000]文本颜色[/c]                     |
>| 文本大小   | 更改文本字号                                                 | [s=30]文本大小[/s]                          |
>| 删除线     | 文本删除线样式                                               | [del]删除线[/del]                           |
>| 嵌入图片   | 在文本中插入一个图片，支持 `.jpg`, `.png`, `.gif` 等主流图片文件格式。默认目录位于 `graphics/iamges` 下 | [emoji=pic.jpg]                             |
>| 注音       | 在文本上面标注注音                                           | [rt= *Dark Flame Master*]漆黑烈焰使[/rt]    |
>| 语气停顿   | 文本遇到 `[wait]` 时，需要接收键鼠输入之后才会显示剩余文本。 | [wait]下次点击时继续 [wait=3000] 3 秒后继续 |
>

其中

文本颜色和注音可以使用```<text><color></color></text>```和```<text><ruby></ruby></text>```来控制。

粗体/斜体/文本大小可以使用```<text><style></style></text>```来控制。

可以用 `[wait=time]` 的形式控制超时时间。time 为毫秒，如`[wait=3000]`则表示 3 秒后文本继续。

###### 表情包问题

在文本中插入一个图片，其实就是插入一个emoji，目前还没有比较合适的解决方案，考虑的是定义一种新的resource叫做emoji或者specialcharacter，然后断开前后的文本，因为没有遇到action的newline，这个是依然会继续执行的。

不建议采用定义宏的形式处理，因为unigal是不赞成这种形式的。

###### 颜色问题

可使用如 `#FF0000` 这样的十六进制值或者 `red` 这类 CSS 颜色预设值。详见：[CSS Colors](https://www.w3schools.com/cssref/css_colors.asp)

unigal中的颜色格式没有固定的要求。

###### 倒计时问题

关于倒计时的问题，目前有三种设想

1.倒计时作为一种新的logic，不同于switch_timer，他是一种新的逻辑

2.倒计时作为一种action（倾向于此）（不过实际上在解释器里面是需要用子线程方法来实现的）

3.倒计时作为一种新的resource，名为subthread，同时引入多线程优化思想。（倾向于此）

并且，怎么表示哪个文本或者哪个图片出发的timer，在unigal翻译回去的时候能保证关联关系不变也是问题。可能需要引入“音乐图片文字计时器”这样的控制路线

#### Simple-1

>```
>// 单次对话
>text.show(
>"是我，是我先，明明都是我先来的……接吻也好，拥抱也好，还是喜欢上那家伙也好……",
>);
>```

#### Translation-1

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
      <page>
        <para>
          是我，是我先，明明都是我先来的……接吻也好，拥抱也好，还是喜欢上那家伙也好……
        </para>
        <comment>
          //文本内容
        </comment>
        <page>
      </content>
    </text>
  </body>
</unigal-script>
```

#### Simple-2

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

#### Translation-2


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
      <page>
        <para>
          为什么会变成这样呢……第一次有了喜欢的人。有了能做一辈子朋友的人。
        </para>
        <comment>
          //文本内容
        </comment>
        </page>
      <page>
        <part>
          两件快乐事情重合在一起。而这两份快乐，又给我带来更多的快乐。
        </part>
        <comment>
          //文本内容
        </comment>
      </page>
<page>
        <para>
          得到的，本该是像梦境一般幸福的时间……但是，为什么，会变成这样呢……~
        </para>
        <comment>
          //文本内容
        </comment>
      </page>
<page>
        <para>
          只要给 options 对象定义 name 字段，就会在对话中显示名字了。
        </para>
        <comment>
          //文本内容
        </comment>
      </page>
<page>
        <para>
          多次连续对话会使用同一个名字。
        </para>
        <comment>
          //文本内容
        </comment>
      </page>
      </content>
      
    </text>

   
  </body>
</unigal-script>
```

#### 文本变量

暂时没想好怎么处理

```
const name = "李狗蛋";
text.show(`我的名字是…… [c=red]${name}[/c]。`);
text.hide();

// 当然，直接进行字符串拼接也是可以的啦~
const number = 3;
text.show("老实交代，你是不是把我的" + number + "个雪糕偷吃了！！！");
text.hide();
```

现在有两种处理思路，一个是引入unigal的变量系统——但是这个是违背初心的，最多也就是const的var。

另一个是引入{{moustache}}的处理形式，允许加载moustache——但是其他引擎支持吗？目标引擎不支持这个是要塌缩的吧

### Monogatari

教程文档https://developers.monogatari.io/documentation/building-blocks/script-and-labels

## Simple-1

```
const person = {
    'name': 'Jane Doe',
    'age': 24
};
```
#### Simple-2

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

#### Translation
没啥可翻译的，建议直接看AVGPlus的Translation就好了

### GameCreator

制作中(其实是开发者偶尔看到了日日夜夜的补丁后发现了剧本格式是JSON，现在还没找到GC的官方教程因此不可能把拆包的内容拿出来作为Simple的)
教程和iFAction一样，都是只有偏重RPG的教程，AVG的文档都没有，怀疑AVG都是拿这个用js改出来的。
https://www.gamecreator.com.cn/gc/document/?file=003-GC%E6%9C%AC%E4%BD%93%E6%96%87%E6%A1%A3/0001-%E5%85%B3%E4%BA%8EGC

### iFAction
不会有的，纯商业引擎，一般不考虑导出，而且这个iF是有加密素材的，我们也不可能读取出来，读取它等于和制作方过不去。

### Snowing

弦语蝶梦系引擎造的太快，暂不考虑，有事请联系[@Seng-Jik](https://gist.github.com/Seng-Jik)老师