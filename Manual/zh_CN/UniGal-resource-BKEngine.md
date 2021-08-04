# BKEngine

官方文档位置：http://docs.bakery.moe/old/image/

BKE中的图像资源是被称作sprite的，即所说的精灵。不仅图片，基本所有素材都可以被认为是一个精灵。和本引擎中的resource类似，然后在sprite/resource的基础上，再派生出更多的类来。

因此，我们此处仅针对图像精灵来设定BKE到UniGal的写法。

此外，这个转换是有损的，因为目前还没有确定好UniGal中的图层是如何写。

我觉得我们真的应该让resource这种函数化的东西尽可能大

它作为被执行的东西，不会和静态的文本一样各种标记。它所携带的，应该是真正被调用的那个函数的各种参数。

我们根据这种参数，不管目标引擎它变成什么名字，都还能认识它。

## Part

```
*main

[sprite index=0 file="image/bg/BG25a_1280"]
[addto index=0 target=basic_layer pos=[0,0] zorder=0 opacity=200]

[layer index=10 width=1280 height=720 opacity=0]
[addto index=10 target=basic_layer pos=[640,120] zorder=50]
//创建了一个编号为10的层，其座标为640,120。

[sprite index=1 file="image/character/A/1_normal"]
[addto index=1 target=10 zorder=10 pos=[-220,0] opacity=255]
[sprite index=2 file="image/character/B/1_normal"]
[addto index=2 target=10 zorder=10 pos=[40,0] opacity=255]
//将两个人物立绘添加到了层上，座标是相对于层的原点计算的
[addto index=10 target=basic_layer pos=[440,120] zorder=50]
//改变了层的座标，附加在层上的人物位置也随之改变了

```

## Analyse
```
[sprite index=0 file="image/bg/BG25a_1280"]
```
这样的声明，类似创建一个对象```<resource>```
之后的属于```<action>```的调用

sprite类比load

remove类比free

index对应resource中增加一个resource id

target要涉及图层

pos没问题，files没问题，opacity建议在图层中引入。图层定义时原来不必全都定义，居然也可以写起止范围

对Analyse中这一行代码，可以用如下的代码来表示

```xml
<resource type="image">
  <image>
    <img_ID>
      0
    </img_ID>
    <file>
      image/bg/BG25a_1280
    </file>
    <load>
      yes
    </load>
    <!--更多的文件属性的信息还没有设计好标签，暂定为文件格式，图像的尺寸等。-->
  </image>
</resource>
```
如果是BKE这种有图层概念的，并且有一些默认的0图层啊1图层啊这样的定义
那么我们在BKE脚本转换为UniGal-Script的时候，我们需要在每次生成的body的开头就预先init一个layerlist

## Examples

```bkengine
[sprite index=0 file="image/bg/BG25a_1280"]
[addto index=0 target=basic_layer pos=[0,0] zorder=0 opacity=200]

[layer index=10 width=1280 height=720 opacity=0]
[addto index=10 target=basic_layer pos=[640,120] zorder=50]
```

## Translation
首先提醒，我们可能未来将不会按照逐句翻译的形式进行转换，第一行和第二行，sprite的声明和addto存在相同之处的地方，可能会考虑合并，本次依然按照逐句转换实现

```XML
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src_engine>
      BKEngine
    </src_engine>
  </head>
  <body>
    <code>
      <!--首先定义一个基本图层0层-->
      <resource type="layer">
        <layer_ID>
          0
        </layer_ID>
        <layer_name>
          basic_layer
        </layer_name>
        <layer_opacity>
          255
        </layer_opacity>
      </resource>
      <!--//接下来刷新一个有0层的layerlist-->
      <resource type="index">
        <layerlist>
          <layer_ID>0</layer_ID>
        </layerlist>
      </resource>
    </code>
    <struct>
      <count>
        1
      </count>
    </struct>
    <code>
      <!--//接下来是声明sprite（即创建resource元素）-->
      <resource type="image">
        <image>
          <img_ID>
            0
          </img_ID>
          <file>
            image/bg/BG25a_1280
          </file>
          <load>
            yes
          </load>
          <image_opacity>
            255<!--//默认在BKE中只要声明图片精灵都是255，把它添加到图层中才是图层中的图名都-->
          </image_opacity>
          <size>
            <x></x>
            <y></y>
          </size>
        </image>
      </resource>
    </code>
    <struct>
      <count>
        2
      </count>
    </struct>
    <code>
      <!--//addto是一个函数？-->
      <!--//这一行分为两部分，一个是将图片插入layer，另一个是展示他。-->
      <!--//zorder是什么我还么想好-->
      <!--//第一步，插入图片-->
      <resource type="layer">
        <layer_ID>
          0
        </layer_ID>
        <layer_name>
          basic_layer <!--//本打算叫BKengine_default-->
        </layer_name>
        <layer_opacity>
          255
        </layer_opacity>
        <layer_image>
          <img_ID>
            0
          </img_ID>
        </layer_image>
      </resource>
      <!--//第二步，改透明度-->
      <!--//无状态确实麻烦，每次都得重新声明一次内存状态-->
      <!--//建议对于这种需要频繁更迭状态的东西，所有字段都是非强制好了，这样可以想改啥改啥？（那这不就是有状态了吗，但起码load和file可以省（不是第一次的时候）-->
      <resource type="image">
        <image>
          <img_ID>
            0
          </img_ID>
          <image_opacity>
            255<!--//默认在BKE中只要声明图片精灵都是255，把它添加到图层中才是图层中的图名都-->
          </image_opacity>
          <size>
            <x></x>
            <y></y>
          </size>
        </image>
      </resource>
      <!--//第三步，展示-->
      <action>
        <showimage>
          <imgname>
          </imgname>
          <img_region>
            <type>
              DoublePoint
            </type>
            <DoublePoint>
              <Point1>
                <!--//左上点-->
                <pos1>
                  0
                </pos1>
                <pos2>
                  0
                </pos2>
              </Point1>
              <Point2>
                <!--//右下点-->
                <pos1>
                  image.x
                </pos1>
                <pos2>
                  image.y
                </pos2>
              </Point2>
            </DoublePoint>
          </img_region>
        </showimage>
      </action>
    </code>
    <struct>
      <count>
        3
      </count>
    </struct>
    <code>
      <!--//新建图层-->
      <!--//但我认为layer的w和h可以不用写-->
      <!--我们的layer都是全屏的（然后这个w和h直接用于修建layer的所有image-->
      <!--在unigal到bke的时候，需要检测一下是否所有图像都是一个大小，一样就把它还原回去-->
      <resource type="layer">
        <layer_ID>
          10
        </layer_ID>
        <layer_name>
          user_defined_1
        </layer_name>
        <layer_opacity>
          255
        </layer_opacity>
      </resource>
      <!--//此时layerlist发生变化，重新声明-->
      <resource type="index">
        <layerlist>
          <layer_ID>10</layer_ID>
          <layer_ID>0</layer_ID>
        </layerlist>
      </resource>
    </code>
    <struct>
      <count>
        4
      </count>
    </struct>
    <code>
      <!--//准备向旧图层添加一个ID为10的图像-->
      <!--//但是这个图像什么时候定义的？故这个操作应该报错了吧？-->
      <!--//还没写第四句对应的代码-->
    </code>
  </body>
</unigal-script>
```