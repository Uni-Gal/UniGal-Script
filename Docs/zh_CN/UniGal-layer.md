# UniGal-Layer

Layer是UniGal推出的图层(layer)和图层组(layerlist)系统

一个工程中只可以有一个layerlist，但是一个layerlist可以有若干个layer

一个layer可以有若干个image

## Layer

### layer定义

如下是Layer在main中的定义

Layer是一种resource

```xml
<resource type="layer">
  <layer_ID>
    <!--图层编号-->
  </layer_ID>
  <layer_name>
    <!--这个图层的名字-->
  </layer_name>
  <!--设计为transparent为一百等级的透明度写法，而opacity为255级的透明度写法？试着中和一下英美矛盾？那么0-1的float呢？-->
  <!--
      FA: 直接掐死，只允许unsigned int8 (0-255)，唯一指定像素格式R8G8A8B8
      因为画师手里的图片一半是R8G8B8A8
      另一大半是B8G8R8A8
      可大胆推定不会有用浮点表示色彩的原图
  -->
  <alpha>255</alpha>
  <!--那么如果都写怎么办？取中值？设置优先考虑某一个钦点？还是直接报错？我们认为高是全透明还是低是全透明？-->
  <!--不如这样，opacity设置为高透明，transparent设置为低透明。-->
  <layer_Image>
    <image>
      <img_ID>11</img_ID>
      <img_order>1</img_order>
    </image>
    <image>
      <img_ID>45</img_ID>
      <img_order>2</img_order>
    </image>
    <image>
      <img_ID>14</img_ID>
      <img_order>3</img_order>
    </image>
  </layer_Image>
</resource>
```
### 注意

1. image在layer中的上下顺序完全由img_order决定，数字越小的位于越上方。

2. 每次图层中Layer_Image变化的时候，应重新声明一次此时的Layer中的图像，需要且仅需要展示layer_Image这一个节点就可以了（带上layerID）。


## Layerlist

### layerlist定义

如下是Layerlist在main中的定义

Layerlist是一种index。index是一种resourece

```xml
<resource type="index">
  <layerlist>
    <layer>
      <layer_ID>19</layer_ID>
      <layer_order>1</layer_order>
    </layer>
    <layer>
      <layer_ID>198</layer_ID>
      <layer_order>3</layer_order>
    </layer>
    <layer>
      <layer_ID>10</layer_ID>
      <layer_order>2</layer_order>
    </layer>
  </layerlist>
</resource>
```
### 注意

1. ID的顺序就是从上到下的，从1~3，分别逐渐向下。需要查询某个layer的信息的时候再随时去查找对应的layer的位次。

2. 每次新建图层的时候，就按照ID大小来确定插入的位置，而不是无脑直接叠最顶上吧。

3. 默认在排序图层的时候，这个上下顺序不一定和大小一一对应，序号小的不一定需要在最上面，不需要过度排序。

4. 在layer_ID之外引入layer_Order的属性，来负责维护排序

5. Layerlist每次发生变化的时候都需要重新声明一次当前的状态

## Layer和Layerlist关系

UniGal的图层是希望能够尽可能引入目前各种引擎中的图层概念，比如图层ID，图层透明度，图层属性，图层属于的资源组等。我们希望创造一个足够丰富的图层类来完成这一些工作。

图层的概念，就是一个游戏中有一个（祖传的）```<layerlist>```，然后这一个```<layerlist>```里面有若干个```<layer>```，每个```<layer>```中有若干个```<image>```

需要注意的是，在跳转前后，后一个剧本文件将继承上一个文件的layerlist中的所有图层信息，若有与后序剧本文件的初始状态冲突的，则按后序剧本文件的来。（这句挺难理解的）