# UniGal-main



在您拆分原子操作的过程中

将需要大量的参考其他语言的语法文档

在此将一部分有官方文档或高度可信文档的引擎的文档贴在这里

供后面拆原子操作的大佬参考

librian https://doc.librian.net/site/%E4%B8%BB%E9%A0%81.html 官方QQ群618775838

avgplus https://docs.avg-engine.com/ 官方QQ群323092720

BKEngine http://docs.bakery.moe/ 官方QQ群303680897

nova 还没开源呢 官方QQ群（不仅是引擎）876212259

renpy https://www.renpy.org/doc/html/ TG群都莫得就别想QQ了（简中文档https://www.renpy.cn/doc/index.html）

krkr（正在找，不存在的吧

（https://github.com/krkrz/krkrz  这个算吗说实话我对KR系的一大家子产品没啥了解和认识）

（官方不存在了听说这个民间版很有名http://blog.sina.com.cn/s/articlelist_1251573991_5_1.html 和这个 https://tieba.baidu.com/p/1236613654）





## UniGal的全部原子操作的列表

### 文本处理部分（text）

text的原子操作有

1. 封装为part
2. newline
3. waitclick
4. 设置姓名

### 演出控制部分（code）

code的原子操作有

### ~~逻辑控制部分~~

~~若将所有的跳转逻辑单独列为一类操作，将意味着每次跳转前后不同流程图需要对应不同的代码块，需要将UniGal-Script与UniGal-Diagram结合使用（当然简单的单线的应该也不用吧？没必要把人引入到自己的生态圈中，那样强行不好）(这还将意味着，一旦出现```<logic></logic>```,就意味着一个剧本文件的结束)~~



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
        </action>
    </code>
    <logic>
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
        <jump>
            //就是单纯的跳转
        </jump>
            <comment>
              //您只能选择switch或jump中的一种logic
            </comment>
    </logic>
  </body>
</unigal-script>
```

