# UniGal-main



在您拆分原子操作的过程中

将需要大量的参考其他语言的语法文档

在此将一部分有官方文档或高度可信文档的引擎的文档贴在这里

供后面拆原子操作的大佬参考

**librian** https://doc.librian.net/site/%E4%B8%BB%E9%A0%81.html 官方QQ群618775838

**avgplus** https://docs.avg-engine.com/ 官方QQ群323092720

**BKEngine** http://docs.bakery.moe/ 官方QQ群303680897

**nova** [Nova引擎](https://github.com/Lunatic-Works/Nova)已于近日以MIT协议开源,在这里可以查看[wiki](https://github.com/Lunatic-Works/Nova/wiki)。Nova的脚本格式可以参见本文档[Nova--Script](https://github.com/Lunatic-Works/Nova/wiki/NovaScript)    官方QQ群（不仅是引擎）876212259

**renpy** https://www.renpy.org/doc/html/ TG群都莫得就别想QQ了（简中文档https://www.renpy.cn/doc/index.html）

**krkr**（不存在的吧）（https://github.com/krkrz/krkrz  这个算吗说实话我对KR系的一大家子产品没啥了解和认识）

（官方不存在了听说这个民间版很有名http://blog.sina.com.cn/s/articlelist_1251573991_5_1.html 和这个 https://tieba.baidu.com/p/1236613654）

**monogatati** [官网](https://monogatari.io/)  [教程和文档](https://developers.monogatari.io/documentation/)



## UniGal的全部原子操作的列表

### 文本处理部分(text)

text的原子操作有

1. 封装为part
2. 设置姓名

### 函数控制部分(code)

函数包括资源管理（resource）、演出（action）、逻辑控制（logic）、扩展（extension）功能等一系列都成为函数。

其中一些引擎相关的特有API按照extension来书写，确保引擎的feature不会影响到大部分的内容。比如librian的支持CSS样式和嵌入任何一种语言。比如BKE的支持live2D(如果有其他家也支持的很好，可能会挪动到resource)，比如krkr的一些允许内置浏览器的代码，比如橙光的鲜花（虽然不会支持它的）（文件读写，调取第三方api等也属于extension）

code的原子操作有

面向文本控制和演出效果的action函数textcontrol

1. newline
2. waitclick

面向逻辑的logic函数

3. jump
4. switch

面向资源管理和调度的resource函数

5. showimg

面向特色功能的extension函数

6. 若干

### 静态结构部分(struct)

静态结构部分属于标记，仅包含label标签和count标签两种,count就是计数菌了，负责标记准确的行号，对应的galgame语言中的一行的起始。在翻译的时候是源语言的每一行开始的时候加一个count。

jump和switch等跳转逻辑属于函数，归为code的logic所有

将意味着每次跳转前后不同流程图需要对应不同的代码块，需要将UniGal-Script与UniGal-Diagram结合使用

（当然简单的单线的应该也不用吧？没必要把人引入到自己的生态圈中，那样强行不好）

但我们可以保证把每个label都拆分为一个独立的脚本文件，因此一个文件只能在开头有label就好了)))

## 实验性功能

**本次（其实是每次）引入了不少全新的实验性模式，具体是否需要保留待定**

这次试图引入一个新的标签，将原有的```<src></src>```拆分为可以保留更多meta信息的```<src_X></src_X>```标签。
X可以是```engine，characterset，language```等。（没错，野心甚至包含机器自动翻译）
不仅仅引擎需要标注，不同引擎默认编码可能会有不同，如SHIFT-JIS和UTF-8之间的区别，在转换过程中有必要特别标注，避免出错.
而属于XML头的```<?xml version="1.0" encoding="utf-8"?>```则标志着中间体的UniGal脚本使用的是UTF-8编码，并不意味着源文件和目标文件的编码一定都是UTF-8.
这个实验性的标签在这期间是优先使用，并不强制性的对旧标签进行替换（有HTML的屎山的味道了）

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
            - resource_image
            - resource_sound
            - logic
                - switch
                - jump
            - extension
        - struct
            - label
            - count
```

## 全部功能的代码示范（原型Prototype）

即日起，UniGal的给电脑看的需要展示出来的注释用```<comment></comment>```封装，给人看的纯粹开发的时候方便了解是啥的，今后统一用```<!-- {{comment_content}} -->```写，就不要暴露出来给解析脚本的时候添麻烦了。已有的存量代码逐步实行更改。

```XML
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
      //
    </comment>
  </head>
  <body>
    <text>
      <character>
        <name>
          NULL
        </name>
        <color>
          //文本颜色
        </color>
        <ruby>
          //可以加入注音
        </ruby>
        <style>
          <bold></bold>
          <italic></italic>
          <deleted></deleted>
          <underlined></underlined>
          //style中只允许填写bool值，即true与false
        </style>
        <comment>
          //Character是姓名相关，其中name是必须有的，而color和ruby是非必须的。此外，bold/italic/deleted/underlined也是非必须的
        </comment>
      </character>
      <content>
        <part>
          内容
        </part>
        <color>
          //文本颜色
        </color>
        <ruby>
          //可以加入注音
        </ruby>
        <style>
          <bold></bold>
          <italic></italic>
          <deleted></deleted>
          <underlined></underlined>
          //style中只允许填写bool值，即true与false
        </style>
        <comment>
          //content是文本相关，其中part是必须有的，而color和ruby是非必须的
        </comment>
      </content>
    </text>
    <code>
      <resource type="image">
        <image>
          <img_ID>
            图像ID
          </img_ID>
          <layer_ID>
            图层ID，若不声明则放进默认图层，若没有默认图层则放进最高图层
          </layer_ID>
          <file>
            //文件路径
          </file>
          <load>
            //载入内存
          </load>
          <free>
            //从内存释放
          </free>
          <image_opacity>
            //私以为一个图层如果允许多个图像并存（图层成为图像文件夹的概念了的话），那么每个图像的透明度也是非常有必要引入的
          </image_opacity>
          //英国人如果看到opacity会不会震怒？是否应该加入transparent和opacity的重载？（想啥呢傻了？）
          <size>
            <x></x>
            <y></y>
          </size>
          //更多的文件属性的信息还没有设计好标签，暂定为文件格式，图像的尺寸等。
        </image>
        <background>
          <comment>
            //背景
          </comment>
        </background>
        <cg>
          <comment>
            //CG
          </comment>
        </cg>
        <tachie>
          <pose>
            动作造型
          </pose>
          <expression>
            //表情
            <expression>
              <comment>
                //立绘
              </comment>
            </tachie>
      </resource>
      <resource type="sound">
        <sound>
          //文件基本信息
        </sound>
        <voice>
          <comment>
            //人声
          </comment>
        </voice>
        <bgm>
          <comment>
            //背景音乐
          </comment>
        </bgm>
        <effect>
          <comment>
            //音效
          </comment>
        </effect>
      </resource>
      <resource type="layer">

      </resource>
      <action>
        <textcontrol>
          waitclick//重载+1
        </textcontrol>
        <textcontrol>
          newline//重载+1
        </textcontrol>
        <showimage>
          //暂时没有设置图层概念因此没有设计目标图层,否则可以加一个dstLayer
          <imgname>
          </imgname>
          //提供两种标志图像范围的方法，两点标记或者LURD标记
          <img_region>
            <type>
              //填写DoublePoint/LURD
            </type>
            <DoublePoint>
              <Point1>
                //左上点
                <pos1>
                  //row
                </pos1>
                <pos2>
                  //col
                </pos2>
              </Point1>
              <Point2>
                //右下点
                <pos1>
                  //row
                </pos1>
                <pos2>
                  //col
                </pos2>
              </Point2>
            </DoublePoint>
            <LURD>
              <L>1</L>
              <U>2</U>
              <R>3</R>
              <D>4</D>
            </LURD>
            //imgRegion提供多种的表示图像区域的方法，互相等价，在内部默认存储为LURD的形式，会自动进行转换。
          </img_region>
        </showimage>
      </action>
      <logic>
        <jump>
          <jump_dst>
            //目的地标签
          </jump_dst>
          <jump_addtional>
            //附加内容
          </jump_addtional>
        </jump>
        <switch>
          <choise>
            <choise_name>
              //选择支显示名称
            </choise_name>
            <choise_label>
              //选择支跳转目标
            </choise_label>
          </choise>
          <timer>
            <timer_num>
              //允许您写一个以毫秒为单位的倒计时
            </timer_num>
            <timer_default>
              //倒计时结束后需要自动选择的选择支的名称
            </timer_default>
          </timer>
        </switch>
        <comment>
          //您只能选择switch或jump中的一种logic
        </comment>
      </logic>
      <extension>
        //暂未设定
      </extension>
    </code>
    <struct>
      <label>
        <label_name>
          //标签的名字,目前标签尚未开发出更多用途。name可以是英文数字字符串，也可以是中文名。
        </label_name>
		<label_ID>
		  //标签对应的序号（并非所有引擎都会用到，是扩展属性）。若某语言中是只有序号的，那么应优先使用label_name，仅在同时有名称和序号的时候使用label_ID
		</label_ID>
		<label_comment>
		  //一个标签对应的故事（并非所有引擎都会用到，是扩展属性）
		</label_comment>
      </label>
      <conut>
        //第X句台词的编号
      </conut>
    </struct>
  </body>
</unigal-script>
```

