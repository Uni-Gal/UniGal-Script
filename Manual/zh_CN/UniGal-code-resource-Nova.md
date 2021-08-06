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