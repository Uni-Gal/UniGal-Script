# UniGal-resource

# BKE

官方文档位置：http://docs.bakery.moe/old/image/

BKE中的图像资源是被称作sprite的，即所说的精灵。不仅图片，基本所有素材都可以被认为是一个精灵。和本引擎中的resource类似，然后在sprite/resource的基础上，再派生出更多的类来。

因此，我们此处仅针对图像精灵来设定BKE到UniGal的写法。
此外，这个转换是有损的，因为目前还没有确定好UniGal中的图层是如何写。


## Examples

```
*main

[sprite index=0 file="image/bg/BG25a_1280"]
[addto index=0 target=basic_layer pos=[0,0] zorder=0 opacity=255]

[layer index=10 width=1280 height=720 opacity=0]
[addto index=10 target=basic_layer pos=[640,120] zorder=50]
//创建了一个编号为10的层，其座标为640,120。

[sprite index=1 file="image/character/A/1_normal"]
[addto index=1 target=10 zorder=10 pos=[-220,0] opacity=255]
[sprite index=2 file="image/character/B/1_normal"]
[addto index=2 target=10 zorder=10 pos=[40,0] opacity=255]
//将两个人物立绘添加到了层上，座标是相对于层的原点计算的
[wait time=5000 canskip=false]
[addto index=10 target=basic_layer pos=[440,120] zorder=50]
//改变了层的座标，附加在层上的人物位置也随之改变了

```
[sprite index=0 file="image/bg/BG25a_1280"]
这样的声明，类似创建一个对象<resource>
之后的属于<action>的调用


## Translation

```

```

# Librian

官方文档位置：
立绘 https://doc.librian.net/site/%E7%94%A8%E6%88%B6%E6%8C%87%E5%8D%97/%E7%AB%8B%E7%B9%AA.html
背景 https://doc.librian.net/site/%E7%94%A8%E6%88%B6%E6%8C%87%E5%8D%97/%E5%8A%87%E6%9C%AC%E5%91%BD%E4%BB%A4.html#bg
以上两个是图像相关的

Librian中的图像调用的语法写的非常简洁，直接说明就可以，而且是从PSD里面调取
这里不同的是，其人物立绘的调用是和人物名字一起声明的，只要找得到文件就会自动的调用这张立绘，这个处理在Gal引擎里面是罕见的。
因此较为复杂，暂不提供Translation

## Examples

```
> BG 魔王城內
> 背景 染紅的街道.png
> BG 潘大爺神殿 1.5 "50% 50%"
```
作者给出的解读是

BG {文件名} {淡入時間=1} {位置="0% 0%"} {漸變方法='_淡出'}
```
@潘大爺 + 裸體    
潘大爺 「我看看……」
潘大爺 (大笑)「哈哈哈，你是豬嗎？」

```
作者给出的官方解读是

    @潘大爺 + 裸體。

    後端將 潘大爺 的衣服設置爲 裸體。

    潘大爺 「我看看……」 (對話，沒有指定表情)。

    後端將 潘大爺 的表情設置爲 _默認 。

    前端繪圖，此時 潘大爺 爲 裸體+默認表情 的狀態。因此從「潘大爺.psd」取得 裸體 、 無表情 、 眼睛 三個圖層，從下往上進行疊加。

    潘大爺 (大笑)「哈哈哈，你是豬嗎！」 (對話，有表情)。

    後端將 潘大爺 的表情設置爲 _大笑 。

    前端繪圖，此時 潘大爺 爲 裸體+大笑表情 的狀態。因此從「潘大爺.psd」取得 裸體 、 大笑 、 眼睛 三個圖層，從下往上進行疊加。

librian中载入一个图像（唔，就是malloc吧）是隐式的由引擎来完成的，但是在Unigal中它将会显式的出现。

## Translation

```
还没翻译
```

# Nova

官方文档位置：https://github.com/Lunatic-Works/Nova/wiki/NovaScript
(里面也包含了音声画色等除了文字以外的所有文档，函数不多，但是每个都得琢磨着看)

Nova的引擎较为复杂，但代码段和文本段好在还有明显的区分。
一些介绍可以看这篇Docs中的介绍（UniGal内）[Docs/zh_CN/UniGal-Script-text.md](https://github.com/Uni-Gal/UniGal-Script/blob/master/Docs/zh_CN/UniGal-Script-text.md)
目前暂且认为除了文本以外的其他内容都在提前代码段中，延迟代码段中有控制。而文本不在延迟代码段中直接暴露，可以和本引擎的<text></text>与<code></code>这样的粗暴的两大类分类方法相提并论一起类比。

@<|
//位于开头的提前代码块（eager execution block）//
>|

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

## Translation

```
还没翻译
```