# UniGal-animation

UniGal提供一定的基本动画功能

## 动画模式

### 关键帧模式

### 连续帧序列播放模式

## 播放位置

？

## ？

不知道怎么定义了
准备抄文档

## 在各引擎中出现的动画文档

### Librian

**Librian的动画是基于什么的我也搞不清了**，猜就猜和当年flash一样有点像，是关键帧吧

重点鞭尸对象，不用进阶的编程技巧做不出简单的动画来

只能用类似滤镜或者叠加SVG的图层一样的东西才可以

详情可见[特效 - Librian中文文檔](https://doc.librian.net/site/%E9%80%B2%E9%9A%8E/%E7%89%B9%E6%95%88.html)

仅仅是让已有元素动起来的话，可以使用css来写特效

总之由于Librian的这个动画写起来实在是太奇葩（但这也是它的特色），我们暂且较难支持。

### BKEngine

**BKE的动画是基于帧序列的**

BKE的官方文档分为两部分

[旧教程/动画](http://docs.bakery.moe/old/animation/)

[脚本命令手册/帧动画](http://docs.bakery.moe/bkscr/animate/)

BKEngine提供了丰富帧动画模式，同时提供简单的控制选项，他们都归属于animate指令。
帧动画是一种特殊的精灵。~~——说白了就是图片~~

>
>这一次给各位介绍的是BKE的动画类，它包含了 `animate` 、 `action` 与 `trans` 。三者都是在BKE中制作动画时必不可缺的组成部分。 虽然实际说来三者其实是不同的三个类，不过考虑到功能划分，我们这一次就先对 `animate` 类先进行说明。
>
>## animate
>
>顾名思义，`animate` 命令常被用于创建逐帧动画时使用，您可以利用此命令来创建一个循环播放的动画。
>
>其命令格式如下：
>
>**animate** **mode*
>    动画系命令关键字。
>
>*mode*
>    接下来执行动画命令的类型。  
>
>`animate` 命令有6种不同的模式（mode关键字），它们分别是：
>
>```
>horizontal vertical multfiles start cell stop
>```
>
>对于不同的 `mode` ， `animate` 命令有不同的参数，这里就向大家顺序介绍一下：

这个mode有：

1. animate mode=”horizontal” index file frame interval loop
动画系命令，模式为剪裁方式（动画帧水平排列）。

2. animate mode=”vertical” index file frame interval loop
动画系命令，模式为垂直模式（动画帧垂直排列）。

3. animate mode=”multifiles” index *file interval loop delay
从多个文件创建一个动画。

4. animate mode=”start” index
开始一个动画。

5. animate mode=”stop” index
停止一个动画。

6. animate mode=”cell” index *frame
切换动画到某一帧（会停止动画）。

这里，我觉得horizontal、vertical是描述的一个图像集的属性，描述了图像集是单文件还是多文件的、描述了单文件的图像集里面的数据结构。我们决定新建一种resource来存放。（如果有对象概念，它就是继承的image这种资源）

而multifiles、start、stop是一种控制命令，是一个动作，我们决定把它放进```<action>```中。

### AVGPlus

**AVGPlus的动画是基于关键帧的？**，因为我找到了这样[一份文档](https://docs.avg-engine.com/handbook/conception/animation-engine/),但他是空的。

AVGPlus的动画教学没有完整的聚集在一个地方，而是分散在文档的各个地方

我们将分散的把他们在这里汇总起来。其中，部分是需要手动点击和定位的，没有在官网找到永久链接这样的形式。

显示立绘-带入场动画的立绘。https://docs.avg-engine.com/handbook/api/character/#_1

隐藏立绘-带动画的隐藏立绘。https://docs.avg-engine.com/handbook/api/character/#_5

立绘动画。https://docs.avg-engine.com/handbook/api/character/#_7

因为AVGPlus的其他的图片类的对象API差不多，今天只分析立绘。

接下来是AVGPlus的代码示范

#### 显示立绘-带入场动画的立绘。

```javascript
// 同样通过 show 方法来显示一个立绘
character.show("char1", "girl-smile.png", {
  renderer: {
    // 在渲染器中指定 position 调整到一个合适的位置
    position: "(0, bottom)",
  },
  animation: {
    // 我们通过 initialFrame 来描述动画开始时的初始状态
    // 当然，在上面的 renderer 中写也是没问题的
    // initialFrame 实际上就是一个 renderer 对象
    // 它会在时间轴开始执行时初始化立绘的参数
    initialFrame: {
      alpha: 0,         // 设置初始透明度为0
      scaleX: 1,        // x 轴缩放
      scaleY: 1,        // y 轴缩放
    },

    // 接下来，我们来定义一个时间轴
    // 时间轴是一个 renderer 数组，但是它比 renderer 多了一个 duration 字段
    timeline: [
      {
        duration: 1000,         // 这一状态帧的动画时长，单位是毫秒
        alpha: 1,               // 透明度设为 1
        x: 500,                 // 移动到 x 坐标 500
      },
      {
        duration: 1000,         // 这一状态帧的动画时长
        scaleX: 1.1,            // x 轴缩放
        scaleY: 1.1,            // y 轴缩放
        ease: "easeOutElastic"  // 缓动函数
      }
    ]
  }
});
```

没有更多了，这一段就够定义很多东西了。

可以定义动画的持续时间、动画X和Y的移动方向移动速度共计四个量。（对于关键帧）

动画的间隔时间和帧率。

对于关键帧而言，使用的什么插值方法。