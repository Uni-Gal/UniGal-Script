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

### 代码控制部分（code）

code的原子操作有



## 全部功能的代码示范

```XML
<?xml version="1.0" encoding="utf-8"?>
<unigal>
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
      <name>
        <comment>
          //姓名
        </comment>
      </name>
      <content>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <code>
      <resource type="pic">
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
    </code>
  </body>
</unigal>
```

