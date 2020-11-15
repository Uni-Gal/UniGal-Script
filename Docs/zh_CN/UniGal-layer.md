# UniGal-Layer

Layer是UniGal推出的图层系统
这里的图层也是希望能够尽可能引入目前各种引擎中的图层概念
比如图层ID，图层透明度，图层属性，图层属于的资源组，等
我们希望创造一个足够丰富的图层类来完成这一些

<layerlist>
  <layer_ID>1</layer_ID>
  <layer_ID>2</layer_ID>
  <layer_ID>3</layer_ID>
</layerlist>
//ID的顺序就是从上到下的，从1~3，分别逐渐向下。然后需要查询某个layer的信息的时候再随时去查找？
//默认在排序图层的时候，这个上下顺序不一定和大小一一对应，但是每次新建图层的时候，就按照ID大小来确定插入的位置，而不是无脑直接叠最顶上吧。
问：有无必要维护一套layerlist的表吗？只在每个剧本的开头或者结尾手动存储一次layerlist？还是每次发生图层增减的时候都需要重新声明一次？

<layer>
  <layer_ID>
    图层编号
  </layer_ID>
  <layer_name>
    这个图层的名字
  </layer_name>
  <layer_opacity>
    255
  </layer_opacity>
  <layer_transparent>
    100
  </layer_transparent>
  //设计为transparent为一百等级的透明度写法，而opacity为255级的透明度写法？试着中和一下英美矛盾？
  //那么如果都写怎么办？取中值？设置优先考虑某一个钦点？还是直接报错？我们认为高是全透明还是低是全透明？
  //不如这样，opacity设置为高透明，transparent设置为低透明。
  <layer_Image>
    <img_ID>
      0
    </img_ID>
    <img_ID>
      0
    </img_ID>
    <img_ID>
      0
    </img_ID>
  </layer_Image>
</layer>

问：图层中有无必要引入图像列表（存储一个图层可能存在的多个图像）

(在跳转前后，后一个剧本文件将继承上一个文件的layerlist中的所有图层信息，若有与后序剧本文件的初始状态冲突的，则按后序剧本文件的来)

这样，图层的概念就变成了一个游戏中有一个（祖传的）```<layerlist>```，然后这一个```<layerlist>```里面有若干个```<layer>```，每个```<layer>```中有若干个```<image>```

再问：layer有没有必要做成一种资源？还是让code中多一种类型

layerlist呢？