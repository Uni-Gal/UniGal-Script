# UniGal-main

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

