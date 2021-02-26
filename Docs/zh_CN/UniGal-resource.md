# UniGal-resource

对于同一行中有图有字的处理方式，若非引擎特殊情况，UniGal中尽可能优先为“先音乐后图片最后文字”的顺序，越复杂的演出效果越优先。


# Librian

官方文档位置：
立绘 https://doc.librian.net/site/%E7%94%A8%E6%88%B6%E6%8C%87%E5%8D%97/%E7%AB%8B%E7%B9%AA.html

背景 https://doc.librian.net/site/%E7%94%A8%E6%88%B6%E6%8C%87%E5%8D%97/%E5%8A%87%E6%9C%AC%E5%91%BD%E4%BB%A4.html#bg

~~~~~~

~~~~~~

Librian同时提供了一个官方的parser，可以用于分析Librian的脚本。该Parser是基于Python的。要实现Complier的前端语法分析，可以使用这个Parser实现，然后接上Python对XML的实现，就可以生成unigal的中间体了。

链接：https://github.com/librian-center/liber-language

未来可能也许会用其他语言重写这个parser，也说不定不会。

同时，早晚有一天会直接给那玩意交一个pr过去以支持引擎直读的（挠头

~~~~~~

~~~~~~

以上两个是图像相关的

Librian中的图像调用的语法写的非常简洁，直接说明就可以，而且是从PSD里面调取。需要按照[UniGal-filesystem.md](UniGal-filesystem.md)中的规范来处理。

这里与其他引擎不同的是，其人物立绘的调用是和人物名字一起声明的，只要命中文件就会自动的调用这张立绘，这个处理在Gal引擎里面是罕见的。

Librian比较特别的是，使用BG会把当前的背景图片直接换成指定的文件，而不是多个图层有叠加顺序。使用BGM是直接替换曲目，并且只有淡出没有淡入。详情您可以参考[劇本命令 - Librian中文文檔](https://doc.librian.net/site/%E7%94%A8%E6%88%B6%E6%8C%87%E5%8D%97/%E5%8A%87%E6%9C%AC%E5%91%BD%E4%BB%A4.html)

等价于，它只允许有2个layer，位于下层的该layer中只能有一个图层用来存放背景，位于上层的layer中只能有若干个角色的立绘图片（但是每个立绘都有好多个图像）。

只允许有1个Channel，且该Channel中只能有一个Sound。

对于从BKEngine等多图层引擎转换到Librian的时候，需要在IR的过程中，忽视UniGal脚本中对原脚本真实记录下的图层号，直接切换即可。

因此，若判定到原引擎中存在多个图层（比如Librian中出现了多于2个的layer（即背景或者立绘是多于一个layer的））同时出现且最上方图层透明度非255（即有使用多图层叠加效果的时候），应给予一个“目标引擎不支持图层叠加”的警告。

## Examples-1

```
> BG 魔王城內
> 背景 染紅的街道.png
> BG 潘大爺神殿 1.5 "50% 50%"
```
作者给出的官方解读是

```
BG {文件名} {淡入時間=1} {位置="0% 0%"} {漸變方法='_淡出'}

## Translation-1

```
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src_engine>
      Librian
    </src_engine>
  </head>
  <body>
    <resource type="layer">
      <layer_ID>
        01
      </layer_ID>
      <layer_name>
        Librian_default
      </layer_name>
      <layer_opacity>
        255
      </layer_opacity>
      <layer_transparent>
        100
      </layer_transparent>
    </resource>
    <resource type="index">
      <layerlist>
        <layer_ID>01</layer_ID>
      </layerlist>
    </resource>
    <!-- Librian暂无需要预处理的内容，因此直接定义句数就可以 -->
    <!-- 不过只要涉及到图像和音频，就有必要提前预定义layer和channel -->
    <struct>
      <count>
        1
      </count>
    </struct>
    <code>
      <resource type="sound">
        <sound>
          <sound_ID>
            0001<!--声音ID-->
          </sound_ID>
          <file>
            魔王城內
            <!--我们也不知道是什么格式，不知道就默认mp3好了-->
          </file>
        </sound>
        <bgm>
          <comment>
            true<!--是背景音乐-->
          </comment>
        </bgm>
      </resource>
      <action>
        <showsound>
          0001
        </showsound>
      </action>
    </code>
    <struct>
      <count>
        2
      </count>
    </struct>
    <struct>
      <count>
        3
      </count>
    </struct>
  </body>
</unigal-script>
```
**不过似乎把layer和channel搞混了，明天完善一下channel和example2一块好了**

```
## Examples-2
```
@潘大爺 + 裸體    
潘大爺 「我看看……」
潘大爺 (大笑)「哈哈哈，你是豬嗎？」

```
作者给出的官方解读是
```

    @潘大爺 + 裸體。
    
    後端將 潘大爺 的衣服設置爲 裸體。
    
    潘大爺 「我看看……」 (對話，沒有指定表情)。
    
    後端將 潘大爺 的表情設置爲 _默認 。
    
    前端繪圖，此時 潘大爺 爲 裸體+默認表情 的狀態。因此從「潘大爺.psd」取得 裸體 、 無表情 、 眼睛 三個圖層，從下往上進行疊加。
    
    潘大爺 (大笑)「哈哈哈，你是豬嗎！」 (對話，有表情)。
    
    後端將 潘大爺 的表情設置爲 _大笑 。
    
    前端繪圖，此時 潘大爺 爲 裸體+大笑表情 的狀態。因此從「潘大爺.psd」取得 裸體 、 大笑 、 眼睛 三個圖層，從下往上進行疊加。

librian中载入一个图像（唔，就是malloc吧）是隐式的由引擎来完成的，但是在Unigal中它将会显式的出现。
```

此外，Librian的包中的封包也是非常有讲究的，有其特殊的目录树。对这个感兴趣的可以到doc.librian.net自行查找。


## Translation-2
```xml
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src_engine>
      Librian
    </src_engine>
  </head>
  <body>
    <resource type="layer">
      <layer_ID>
        01
      </layer_ID>
      <layer_name>
        Librian_background
      </layer_name>
      <layer_opacity>
        255
      </layer_opacity>
      <layer_transparent>
        100
      </layer_transparent>
    </resource>
    <resource type="layer">
      <layer_ID>
        02
      </layer_ID>
      <layer_name>
        Librian_tachie
      </layer_name>
      <layer_opacity>
        255
      </layer_opacity>
      <layer_transparent>
        100
      </layer_transparent>
    </resource>
    <resource type="index">
      <layerlist>
        <layer>
          <layer_ID>02</layer_ID>
          <layer_order>1</layer_order>
        </layer>
        <layer>
          <layer_ID>01</layer_ID>
          <layer_order>2</layer_order><!--更靠下-->
        </layer>
      </layerlist>
    </resource>
    <!-- Librian暂无需要预处理的内容，因此直接定义句数就可以 -->
    <!-- 不过只要涉及到图像和音频，就有必要提前预定义layer和channel -->
    <!--【1】-->
    <struct>
      <count>
        1
      </count>
    </struct>
    <code>
      <resource type="image">
        <image>
          <img_ID>
            001
          </img_ID>
          <layer_ID>
            02
          </layer_ID>
          <file>
            (['裸體']@{'潘大爺.psd'})
          </file>
        </image>
        <tachie>
          <cloth>
            裸體
          </cloth>
        </tachie>
      </resource>
      <resource type="layer">
        <layer_ID>
          02
        </layer_ID>
        <layer_Image>
          <image>
            <img_ID>001</img_ID>
            <img_order>1</img_order>
          </image>
        </layer_Image>
      </resource>
    </code>
    <action>
      <showimage>
        <!--意思意思-->
      </showimage>
    </action>
    <!--【2】-->
    <struct>
      <count>
        2
      </count>
    </struct>
    <code>
      <resource type="image">
        <image>
          <img_ID>
            002
          </img_ID>
          <layer_ID>
            02
          </layer_ID>
          <file>
            (['默認表情']@{'潘大爺.psd'})
          </file>
        </image>
        <tachie>
          <expression>
            默認表情
          </expression>
        </tachie>
      </resource>
      <resource type="layer">
        <layer_ID>
          02
        </layer_ID>
        <layer_Image>
          <image>
            <img_ID>002</img_ID>
            <img_order>1</img_order>
            <img_ID>001</img_ID>
            <img_order>2</img_order>
          </image>
        </layer_Image>
      </resource>
    </code>
    <action>
      <showimage>
        <!--意思意思-->
      </showimage>
    </action>
    <!--暂定为先画图，后写字-->
    <text>
      <character>
        <name>
          潘大爺
        </name>
      </character>
      <content>
        <part>
          我看看……
        </part>
      </content>
    </text>
    <!--【3】-->
    <struct>
      <count>
        3
      </count>
    </struct>
    <code>
      <resource type="image">
        <image>
          <img_ID>
            003
          </img_ID>
          <layer_ID>
            02
          </layer_ID>
          <file>
            (['大笑']@{'潘大爺.psd'})
          </file>
        </image>
        <tachie>
          <expression>
            大笑
          </expression>
        </tachie>
      </resource>
      <resource type="layer">
        <layer_ID>
          02
        </layer_ID>
        <layer_Image>
          <image>
            <img_ID>003</img_ID>
            <img_order>1</img_order>
            <img_ID>001</img_ID>
            <img_order>2</img_order>
          </image>
        </layer_Image>
      </resource>
    </code>
    <!--暂定为先画图，后写字-->
    <text>
      <character>
        <name>
          潘大爺
        </name>
      </character>
      <content>
        <part>
          哈哈哈，你是豬嗎？
        </part>
      </content>
    </text>
  </body>
</unigal-script>
```


# Nova

官方文档位置：https://github.com/Lunatic-Works/Nova/wiki/NovaScript

(里面也包含了音声画色等除了文字以外的所有文档，函数不多，但是每个都得琢磨着看)

Nova的引擎较为复杂，但代码段和文本段好在还有明显的区分。

一些介绍可以看这篇Docs中的介绍（UniGal内）[UniGal-text.md](./Docs/zh_CN/UniGal-text.md)

目前暂且认为除了文本以外的其他内容都在提前代码段中，延迟代码段中有控制。而文本不在延迟代码段中直接暴露，可以和本引擎的```<text></text>```与```<code></code>```这样的粗暴的两大类分类方法相提并论一起类比。

```
@<|
//位于开头的提前代码块（eager execution block）//
>|
```

目录结构参考这个研究https://github.com/Lunatic-Works/Nova/wiki/Repo-Structure

示范代码可以参考这个文档来https://github.com/Lunatic-Works/Nova/tree/master/Assets/Examples/Colorless/Resources/Colorless/Scenarios

里面全是示范脚本

## Examples

```
@<|
label('ch1', '第一章')
is_default_start()
|>

<|
anim:trans_fade(cam, function()
show(ergong, 'normal', pos_c)
show(bg, 'room')
end, 2)
play(bgs, 'rain')
anim:volume(bgs, 0.2, 3)
box_hide_show(2)
auto_voice_on('王二宫', 1)
auto_voice_on('陈高天', 1)
set_auto_voice_delay(2)
|>

王二宫：：“真没想到，我们竟然会被暴雨困在了教学楼里。”

<|
show(qianye, 'normal', pos_c)
sound('flap', 0.5)
|>

我出门的时候，依旧可以感觉到有目光追随着我的背影。
@<| jump_to 'ch2' |>
```

我们可以看出，上面这段代码中，文本没有放在延迟代码段中，控制语句放在了延迟代码段中。

Nova的label函数不仅仅是一个标记，而是一个标记对象，这个对象中包含了名称和符号，幸运的是，unigal的label允许用多个属性来模拟这种对象的形式。

其中，show函数可以直接展示一张图片，类似unigal中的showimage函数。当然，在unigal中，一张图片必须先被声明才能被展示

因此nova中直接展示图片的行为，在转化为unigal脚本的时候，将隐式的用resource先进行声明。

而unigal脚本转化到没有声明的语言如nova/librian的时候，我们直接不表达这段声明过程就可以了。

## Translation

```xml
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src_engine>
      Unity-Nova
    </src_engine>
  </head>
  <body>
    <!--提前代码块开始-->
    <struct>
      <label>
        <label_name>
          第一章
        </label_name>
        <label_ID>
          ch1
        </label_ID>
      </label>
    </struct>
    <!--is_default_start()不知道怎么翻译-->
    <!--提前代码块结束-->

    <!--延迟代码块开始-->
    <!--延迟代码块结束-->
    
    <text>
      <character>
        <name>
          王二宫
        </name>
      </character>
      <content>
        <part>
          真没想到，我们竟然会被暴雨困在了教学楼里。
        </part>
      </content>
    </text>

    <!--延迟代码块开始-->
    <!--anim:trans_fade(cam, function()-->
    <!--show(ergong, 'normal', pos_c)-->
    <!--show(bg, 'room')-->
    <!--end, 2)-->
    <!--play(bgs, 'rain')-->
    <!--anim:volume(bgs, 0.2, 3)-->
    <!--box_hide_show(2)-->
    <!--auto_voice_on('王二宫', 1)-->
    <!--auto_voice_on('陈高天', 1)-->
    <!--set_auto_voice_delay(2)-->
    <!--延迟代码块结束-->

    <code>
      <logic>
        <jump>
          <jump_dst>
            ch2
          </jump_dst>
        </jump>
      </logic>
    </code>
  </body>
</unigal-script>
```

**尚未完全翻译完毕，尚有诸多不恰当之处**

似乎在Nova这边不仅要引入struct/count，还需要引入struct/block了

# AVGPlus

## 官网教程摘要——有特色的地方

### sprite

在 AVGPlus 引擎中，所有图像类的元素，都属于 Sprite （精灵）, 尽管他们的使用场合不尽相同，但技术特性是完全一致的。他们都是同一个类派生出来的子类。

因此，立绘、场景、屏幕图片组件等元素，都属于此类别内，所以他们大多数 API 的用法几乎是一致的。

不过，这一点只是帮助您加深概念，对此不理解也完全没关系，因为并不影响学习 API 的使用。

以上，摘自https://docs.avg-engine.com/handbook/api/character/

### Displacement

使用 scene.filter() 方法可以给场上的场景附加一个或多个滤镜。和在 renderer 里设置滤镜是完全一样的。

在本小节，我们就不再简单地设置一个普通的滤镜啦。为了让您看到滤镜对场景的强大作用，这里我们会使用 自动滤镜。

在前面我们看到的滤镜渲染后的图像都是静态的，不过在 AVGPlus 中，也有一些滤镜是支持自己动画的，换言说，只要添加了该滤镜，并且做一些简单的回调处理，场景就能动起来。

这一小节里，我们会用到一个强大的 自动滤镜 —— 置换滤镜 (Displacement)。

以上，摘自https://docs.avg-engine.com/handbook/api/scene/#_6

这个应该是目前较为少见的特性，可能只在AVGPlus出现。


AVGPlus 的 scene 有点接近我们的 resource

## 简单示范——因为官网都是小例子

### 简单显示立绘

```javascript
// 显示一个立绘
character.show("char1", "girl-smile.png");
```

### 指定坐标和尺寸

```javascript
// 在指定位置以指定尺寸显示立绘
character.show("char1", "girl-smile.png", {
  renderer: {
    size: "80%",               // 宽高分别设置为原图的 80%
    position: `(center, 80%)`, // 指定 x 坐标居中，y 为窗口的 85% 位置
  },
});
```

### 隐藏立绘

```javascript
// 我们先显示一个 name 为 'space' 的立绘
character.show("space", "space-normal.png", {
  renderer: {
    position: "(center, 90%)",
  }
});

text.show("「没什么事我先走了。」", {
  name: "空格"
});

text.hide();

// 隐藏 name 为 'space' 的立绘
character.hide("space");
```

### 其他
动画和滤镜效果此处不表

动画会在未来增加

滤镜需要专门特设。