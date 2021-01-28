# UniGal-main

## UniGal命名原则

1. **TODO：需要统一下划线命名法(如：size_t)和大驼峰命名法(如：IntPtr)**

2. 多个层级之间尽量不要重复，若要拆分和更精确描述一个标签，请您尽可能使其延长。

## UniGal的全部原子操作的列表

在您拆分原子操作的过程中,将需要大量的参考其他语言的语法文档。

在此将一部分有官方文档或高度可信文档的引擎的文档贴在[UniGal-reference.md](UniGal-reference.md#各引擎维护团队联系名录)中,供后面拆原子操作的大佬参考。

### 文本处理部分(text)

text的原子操作有

1. 封装为part
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

4001. steam_init
4002. steam_shutdown

### 静态结构部分(struct)

静态结构部分属于标记，仅包含label标签和count标签两种,count就是计数菌了，负责标记准确的行号，对应的galgame语言中的一行的起始。在翻译的时候是源语言的每一行开始的时候加一个count。

jump和switch等跳转逻辑属于函数，归为code的logic所有

将意味着每次跳转前后不同流程图需要对应不同的代码块，需要将UniGal-Script与UniGal-Diagram结合使用

（当然简单的单线的应该也不用吧？没必要把人引入到自己的生态圈中，那样强行不好）

但我们可以保证把每个label都拆分为一个独立的脚本文件，因此一个文件只能在开头有label就好了)))

## 全部功能的树
(为了人好看所以用了这个玩意，但是突然发现这可能将引导本项目最终全部转投这种格式并且允许人看懂，然后下一步怕不是就开始转投py写解释器了（）)
```yaml
- unigal-script
    - head
        - src\dst 等 一堆metadata
    - body
        - text
            - character
                - name
                - color
                - style
            - content
                - name
                - color
                - style
        - code
            - action
                - textcontrol
                - showimage
                - showsound
            - animation
            - resource_image
            - resource_sound
            - resource_layer
                - layer_ID
                - layer_name
                - layer_opacity
                - layer_transparent
                - layer_Image
                    - img_ID
            - resource_channel
            - resource_index
                - layerlist
                - channellist
                - framelist
            - resource_live2d
            - resource_spine
            - logic
                - switch
                - jump
            - extension
            - codeblock
        - struct
            - label
            - count
```

## 全部功能的代码示范（原型Prototype）

```xml
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      krkr/BKE/nova/librian
    </src>
    <dst>
      nova/others
    </dst>
    <src_engine>
      krkr/BKE/nova/librian
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
          <!--style中只允许填写bool值，即true与false-->
        </style>
        <!--Character是姓名相关，其中name是必须有的，而color和ruby是非必须的。此外，bold/italic/deleted/underlined也是非必须的-->
      </character>
      <content>
        <part>
          <!--内容-->
        </part>
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
          <!--style中只允许填写bool值，即true与false-->
        </style>
        <!--content是文本相关，其中part是必须有的（当然也可以没有，但是需要留一个全角空格，半角的不行，parser不当字），而color和ruby是非必须的-->
      </content>
    </text>
    <code>
      <resource type="image">
        <image>
          <img_ID>
            <!--图像ID-->
          </img_ID>
          <layer_ID>
            <!--图层ID，若不声明则放进默认图层，若没有默认图层则放进最高图层-->
          </layer_ID>
          <file>
            <!--文件路径，为文件的完整路径或相对路径，但必须保留扩展名-->
          </file>
          <load>
            <!--载入内存-->
          </load>
          <free>
            <!--从内存释放。若目标实现的图像由GC管理，则无效果。-->
          </free>
          <image_opacity>
            <!--私以为一个图层如果允许多个图像并存（图层成为图像文件夹的概念了的话）-->
            <!--那么每个图像的透明度也是非常有必要引入的,因此这一点上看，对称的，单个音频也应该可以单独调节音量-->
          </image_opacity>
          <size>
            <x></x>
            <y></y>
          </size>
        </image>
          <image_type>
            <!--
              内置background、cg、tachie、Other
              若使用了目标实现不支持的图像类型，该图像就是Other
            -->
          </image_type>
        <background_info>
          <!--背景-->
          <weather>
          </weather>
          <time>
          </time>
        </background_info>
        <cg_info>
          <!--CG-->
          <!--可能会引入serial之类的东西，因为感觉CG还是有一些可提取的特征的-->
        </cg_info>
        <tachie_info>
          <!--立绘-->
          <cloth>
            <!--服装-->
          </cloth>
          <pose>
            <!--动作造型-->
          </pose>
          <expression>
            <!--表情-->
          </expression>
        </tachie_info>
      </resource>
      <resource type="sound">
        <sound>
          <sound_ID>
            <!--声音ID-->
          </sound_ID>
          <channel_id>
            <!--
              channel_id填channel的编号
            -->
          </channel_id>
          <sound_type>
            <!--
              内置BGM、Voice、Ambient/Effect（总之就是音效~，叮啊铛啊的~）、Other
              其它类型由实现定义
              若使用了目标实现不支持的声音类型，该声音就是Other
            -->
          </sound_type>
          <file>
            <!--文件路径，为文件的完整路径或相对路径，但必须保留扩展名-->
          </file>
          <load>
            <!--载入内存-->
          </load>
          <free>
            <!--从内存释放。若目标实现的声音由GC管理，则无效果。-->
          </free>
          <sound_volume>
            <!--在允许channel成组调节音量的基础上，可以单个文件的调节音量-->
          </sound_volume>
          <!--文件基本信息-->
        </sound>
      </resource>
      <resource type="video">
        <!--参考image，只不过里面的img_id换成vid_id这样-->
      </resource>
      <resource type="layer">
        <!--layer可以同时存放image和video，因为video在某一时刻就是一张图片-->
        <!-- layer的内容太长写不下了，可以自己去看UniGal-layer.md -->
        <!-- 但是上面的树依然是正常的写出来了 -->
      </resource>
      <resource type="channel">
        <!---->
      </resource>
      <resource type="index">
        <layerlist>
        </layerlist>
        <channellist>
        </channellist>
        <framelist>
        </framelist>
      </resource>
      <resource type="live2d">
        <!---->
      </resource>
      <resource type="spine">
        <!---->
      </resource>
      <action>
        <!--正在考虑把函数的定义挪动到单独的文件夹中-->
        <!--为了保证一致性，对textcontrol的层次进行了变动。-->
        <textcontrol>
          <waitclick>
            true
          </waitclick>
        </textcontrol>
        <textcontrol>
          <newline>
            true
          </newline>
        </textcontrol>
        <imagecontrol>
          <showimage>
            <!--暂时没有设置图层概念因此没有设计目标图层,否则可以加一个dstLayer-->
            <imgname>
            </imgname>
            <!-- 提供三种储存图像范围的方法，两点标记，LURD标记以及仿射矩阵 -->
            <img_region>
              <DoublePoint>
                <Point1>
                  <!--左上点-->
                  <pos1>
                    <!--row-->
                  </pos1>
                  <pos2>
                    <!--col-->
                  </pos2>
                </Point1>
                <Point2>
                  <!--右下点-->
                  <pos1>
                    <!--row-->
                  </pos1>
                  <pos2>
                    <!--col-->
                  </pos2>
                </Point2>
              </DoublePoint>
              <LURD>
                <L>1</L>
                <U>2</U>
                <R>3</R>
                <D>4</D>
              </LURD>
              <TransformMatirx>
                左上,右上,左下,右下,x坐标,y坐标
              </TransformMatirx>
              <!--imgRegion提供多种的表示图像区域的方法，互相等价，内部储存方式由实现定义，会自动进行转换。-->
            </img_region>
          </showimage>
        </imagecontrol>
        <soundcontrol>
          <showsound>
            <!-- 音乐播放的部分就靠你了,包括淡入淡出之类的 -->
          </showsound>
        </soundcontrol>
        <indexcontrol>
          <!--索引包括layerlist、channellist、framelist等多种类型-->
        </indexcontrol>
        <animationcontrol>
          <!--动画控制函数-->
        </animationcontrol>
        <otherscontrol>
          <!--其他控制，如IO和网路-->
        </otherscontrol>
      </action>
      <animation>
      </animation>
      <logic>
        <jump>
          <jump_dst>
            <!--目的地标签-->
          </jump_dst>
          <jump_addtional>
            <!--附加内容-->
          </jump_addtional>
        </jump>
        <switch>
          <switch_choise>
            <choise_name>
              <!--选择支显示名称-->
            </choise_name>
            <choise_label>
              <!--选择支跳转目标-->
            </choise_label>
          </switch_choise>
          <switch_timer>
            <timer_num>
              <!--允许您写一个以毫秒为单位的倒计时-->
            </timer_num>
            <timer_default>
              <!--倒计时结束后需要自动选择的选择支的名称-->
            </timer_default>
          </switch_timer>
        </switch>
        <!--您只能选择switch或jump中的一种logic-->
      </logic>
      <extension>
        <!--暂未设定-->
      </extension>
      <codeblock>
        <!--代码段-->
      </codeblock>
    </code>
    <struct>
      <label>
        <label_name>
          <!--标签的名字,目前标签尚未开发出更多用途。-->
          <!--name可以是英文数字字符串，也可以是中文名。-->
        </label_name>
        <label_ID>
          <!--标签对应的序号（并非所有引擎都会用到，是扩展属性）。-->
          <!--若某语言中是只有序号的，那么应优先使用label_name，仅在同时有名称和序号的时候使用label_ID-->
        </label_ID>
        <label_comment>
          <!--一个标签对应的故事（并非所有引擎都会用到，是扩展属性）-->
        </label_comment>
      </label>
      <conut>
        <!--第X句台词的编号-->
      </conut>
      <block>
        <block_name>
        </block_name>
        <block_type>
        </block_type>
        <block_body>
        </block_body>
        <!--部分游戏还在脚本文件和脚本行两个层次之间，有块的等级，因此在src_engine标记为这些语言的时候，解释器就需要深入block来探测。-->
        <!--别看，就是给Nova加的-->
        <!--如果硬要说其他游戏也有块，那么其他游戏整个脚本包一个block就好了，没必要这么费事-->
      </block>
    </struct>
  </body>
</unigal-script>
```

## 草案提出者

仅在第4级节点上展示该节点及其各层次子节点的草案提出者

```yaml
- unigal-script
    - head
        - src\dst 等 一堆metadata
    - body
        - text
            - character[快乐的老鼠宝宝]
                - name
                - color
                - style
            - content[快乐的老鼠宝宝]
                - name
                - color
                - style
        - code
            - action[快乐的老鼠宝宝]
                - textcontrol
                - imagecontrol
                - soundcontrol
                - animationcontrol
                - indexcontrol
                - otherscontrol
            - resource.image[Fa鸽、快乐的老鼠宝宝]
            - resource.sound[快乐的老鼠宝宝]
            - resource.layer[快乐的老鼠宝宝]
            - resource.channel[快乐的老鼠宝宝]
            - resource.live2d[快乐的老鼠宝宝]
            - resource.spine[快乐的老鼠宝宝]
            - logic[快乐的老鼠宝宝]
                - switch
                - jump
            - extension
            - codeblock[Fa鸽、快乐的老鼠宝宝]
        - struct
            - label[快乐的老鼠宝宝]
            - count[快乐的老鼠宝宝]
```
