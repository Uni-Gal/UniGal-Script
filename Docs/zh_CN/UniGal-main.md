# UniGal-main



在您拆分原子操作的过程中

将需要大量的参考其他语言的语法文档

在此将一部分有官方文档或高度可信文档的引擎的文档贴在这里

供后面拆原子操作的大佬参考

librian https://doc.librian.net/site/%E4%B8%BB%E9%A0%81.html 官方QQ群618775838

avgplus https://docs.avg-engine.com/ 官方QQ群323092720

BKEngine http://docs.bakery.moe/ 官方QQ群303680897

nova [Nova引擎](https://github.com/huisedenanhai/Nova)已于近日以MIT协议开源

Nova的脚本格式可以参见本文档[Nova--Script](https://github.com/huisedenanhai/Nova/blob/master/doc/novascript.md)
 官方QQ群（不仅是引擎）876212259

renpy https://www.renpy.org/doc/html/ TG群都莫得就别想QQ了（简中文档https://www.renpy.cn/doc/index.html）

krkr（正在找，不存在的吧

（https://github.com/krkrz/krkrz  这个算吗说实话我对KR系的一大家子产品没啥了解和认识）

（官方不存在了听说这个民间版很有名http://blog.sina.com.cn/s/articlelist_1251573991_5_1.html 和这个 https://tieba.baidu.com/p/1236613654）

monogarati [官网](https://monogatari.io/)  [教程和文档](https://developers.monogatari.io/documentation/)



## UniGal的全部原子操作的列表

### 文本处理部分（text）

text的原子操作有

1. 封装为part
2. 设置姓名

### 函数控制部分（code）

函数包括演出（action）、逻辑控制（logic）、扩展（extension）功能（文件读写，调取第三方api等）等一系列都成为函数。其中一些引擎相关的特有API按照extension来书写，确保引擎的feature不会影响到大部分的内容。比如librian的支持CSS样式和嵌入任何一种语言。比如BKE的支持live2D(如果有其他家也支持的很好，可能会挪动到resource)，比如krkr的一些允许内置浏览器的代码，比如橙光的鲜花（虽然不会支持它的）

code的原子操作有

面向文本控制和演出效果的action函数textcontrol

1. newline
2. waitclick

面向逻辑的logic函数
3. jump
4. switch

面向资源效果的resource函数
5. showimg

面向特色功能的extension函数
6. 若干

### ~~静态结构部分~~struct

静态结构部分属于标记，仅包含label标签和count标签两种

jump和switch等跳转逻辑属于函数，归为code的logic所有

将意味着每次跳转前后不同流程图需要对应不同的代码块，需要将UniGal-Script与UniGal-Diagram结合使用

（当然简单的单线的应该也不用吧？没必要把人引入到自己的生态圈中，那样强行不好）

但我们可以保证把每个label都拆分为一个独立的脚本文件，因此一个文件只能在开头有label就好了)))~~

## 全部功能的代码示范（原型Prototype）

本次引入了不少全新的实验性模式，具体是否需要保留待定

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
        <comment>
          //姓名
        </comment>
      </character>
      <content>
        <color>
          //文本颜色
        </color>
        <ruby>
          //可以加入注音
        </ruby>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <code>
      <resource type="image">
        <image>
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
            <comment>
              //立绘
            </comment>
          </tachie>
        </image>
      </resource>
      <resource type="sound">
        <sound>
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
        </sound>
      </resource>
      <action>
        <textcontrol>
          waitclick
        </textcontrol>
        <textcontrol>
          newline
        </textcontrol>
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
        </logic>
        <extension>
        </extension>
    </code>
    <struct>
      <label>
        <label_name>
          //标签的名字,目前标签尚未开发出更多用途
        </label_name>
      </label>
      <conut>
        //第X句台词的编号
      </conut>
    </struct>
  </body>
</unigal-script>
```

