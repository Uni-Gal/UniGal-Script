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