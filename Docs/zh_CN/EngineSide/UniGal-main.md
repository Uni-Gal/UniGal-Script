# UniGal-main

## 全部功能的树及该部分的草案贡献者

> 因篇幅限制和便于展开，部分细节仅展示至第4层次，未继续展开
> 部分可点击直接跳转到对应的实现细节

```yaml
- unigal-script
    - head [Fa鸽、快乐的老鼠宝宝]
        - src_engine
        - dst_engine
        - src_characterset
        - dst_characterset
        - src_language
        - dst_language
    - body
        - text
            - character [快乐的老鼠宝宝]
                - name
                - color
                - style
            - content [快乐的老鼠宝宝]
                - page [Fa鸽]
                  - para [Fa鸽]
                  - color
                  - style
        - code
            - action [快乐的老鼠宝宝]
                - textcontrol
                - imagecontrol
                - soundcontrol
                - animationcontrol
                - indexcontrol
                - otherscontrol
            - animation
            - resource_image [Fa鸽、快乐的老鼠宝宝]
            - resource_sound [快乐的老鼠宝宝]
            - resource_video [快乐的老鼠宝宝]
            - resource_layer [快乐的老鼠宝宝]
                - layer_ID
                - layer_name
                - layer_opacity
                - layer_transparent
                - layer_Image
                    - img_ID
            - resource_channel [快乐的老鼠宝宝]
            - resource_index [快乐的老鼠宝宝]
                - layerlist
                - channellist
                - framelist
            - resource_live2d [快乐的老鼠宝宝]
            - resource_spine [快乐的老鼠宝宝]
            - logic [快乐的老鼠宝宝]
                - switch
                - jump
            - extension [Fa鸽、快乐的老鼠宝宝]
            - codeblock [Fa鸽、快乐的老鼠宝宝]
        - struct
            - label [快乐的老鼠宝宝]
            - count [快乐的老鼠宝宝]
```

## 全部功能的代码示范（原型Prototype）

```xml
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src_engine>
      krkr/BKE/nova/librian
      <!--当我们需要从Fountain之类的剧本格式导入的时候，src_engine直接写Fountain之类，dstengine必须是unigal-->
    </src_engine>
    <dst_engine>
      nova/others
    </dst_engine>
    <src_characterset>
      UTF-8
    </src_characterset>
    <dst_characterset>
      UTF-8
    </dst_characterset>
    <src_language>
      zh_CN
    </src_language>
    <dst_language>
      zh_CN
    </dst_language>
    <comment>
      <!---->
    </comment>
  </head>
  <body>
    <text>
      <!-- 这部分请参见UniGal-text.md -->
    </text>
    <code>
      <resource>
        <!-- 这部分请参见UniGal-code-resource.md -->
      </resource>
      <struct>
        <!-- 这部分请参见UniGal-code-struct.md -->
      </struct>
      <action>
        <!-- 这部分请参见UniGal-code-action.md -->
      </action>
      <animation>
        <!-- 这部分请参见UniGal-code-animation.md -->
      </animation>
      <logic>
        <!-- 这部分请参见UniGal-code-logic.md -->
      </logic>
      <extension>
        <!--暂未设定-->
      </extension>
      <codeblock>
        <!-- 这部分请参见UniGal-code-codeblock.md -->
      </codeblock>
    </code>
  </body>
</unigal-script>
```

## UniGal的全部原子操作的列表

在您拆分原子操作的过程中,将需要大量的参考其他语言的语法文档。

在此将一部分有官方文档或高度可信文档的引擎的文档贴在[UniGal-reference.md](UniGal-reference.md#各引擎维护团队联系名录)中,供后面拆原子操作的大佬参考。

### 文本处理部分(text)

text的原子操作有

1. 封装为page
2. 设置姓名

### 函数控制部分(code)

函数包括资源管理（resource）、演出（action）、逻辑控制（logic）、扩展（extension）功能等一系列都成为函数。

**一切皆函数~~（大雾）~~**

> 
> 所有的函数之间平等，平等的享有命名空间和编号。但action的函数比其他的函数更平等。
> ——窝，自己说的

其中一些引擎相关的特有API按照extension来书写，确保引擎的feature不会影响到大部分的内容。比如librian的支持CSS样式和嵌入任何一种语言。比如BKE的支持live2D(如果有其他家也支持的很好，可能会挪动到resource)，比如krkr的一些允许内置浏览器的代码，比如橙光的鲜花（虽然不会支持它的）（文件读写，调取第三方api等也属于extension）

code的原子操作有

#### logic函数

面向逻辑的函数

2001. jump
2002. switch

#### resource函数

面向资源管理和调度的函数

3001. showimg

#### extension函数

面向特色功能的函数，如steamAPI等，但命名尚有争议。

再比如，平台送花、账号登陆、这样的东西，也属于extension函数的范畴。当然，账号验证和平台送花属于橙光行为，我们不会写这种文档的（笑）

4001. steam_init
4002. steam_shutdown

### 静态结构部分(struct)

静态结构部分属于标记，仅包含label标签和count标签两种,count就是计数菌了，负责标记准确的行号，对应的galgame语言中的一行的起始。在翻译的时候是源语言的每一行开始的时候加一个count。

jump和switch等跳转逻辑属于函数，归为code的logic所有

将意味着每次跳转前后不同流程图需要对应不同的代码块，需要将UniGal-Script与UniGal-Diagram结合使用

（当然简单的单线的应该也不用吧？没必要把人引入到自己的生态圈中，那样强行不好）

但我们可以保证把每个label都拆分为一个独立的脚本文件，因此一个文件只能在开头有label就好了)))
