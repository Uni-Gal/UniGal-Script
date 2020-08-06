# UniGal-text

**<text></text>**



text宏里面只封装纯粹与文本和剧本执行相关的内容



# BKE
在BKE中，纯文本可以直接输入。在换行时以[p]结尾，[r]为手动换行，[l]为等待点击。行之间的换行采用(WINDOWS-CRLF)

在BKE官方API中给出的，涉及文本处理的非状态关键字有如下三种

|关键字|内容|
| ---- | ----- |
|r|手动换行|
|l|等待点击|
|p|换页等待，点击后换页|

因为BKE的脚本也涉及多代处理系统，因此用[]包装是可以的，而改为@的新方式也是可以的

鉴于较多复杂的效果函数采用@调用的方式，我们暂时仅处理[]包装的文本控制函数。

三种分别对应的UniGal中的行为如下
|关键字|内容|UniGal中的处理|对应的action|
| ---- | ----- | ----- | ----- |
|r|手动换行|插入action宏来分割part|newline|
|l|等待点击|插入action宏来分割part|waitclick|
|p|换页等待，点击后换页|||


## Simple
```bkscr
你好，[l][r]世界！[p]
```
## Translate
```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal>
  <head>
    <src>
      BKE
    </src>
  </head>
  <body>
    <text>
      <name>
        NULL
        <comment>
          //姓名
        </comment>
      </name>
      <content>
        <part>
          你好，
        </part>
        <action>
          waitclick
        </action>
        <action>
          newline
        </action>
        <part>
          世界！
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal>
```
# nova
在nova中，文本内容需要以|><|包装，在换行时直接自然换行(UNIX-LF)，结尾需要空行。
## Simple
```txt
|>
坐在车厢里的人总会向外眺望。

眺望的理由多种多样：
晕车，发呆，欣赏风景……

亦或者只是下意识地一瞥。

但人们心中压抑的冲动都是相似的。

<|
```

## Translate
```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal>
  <head>
    <src>
      BKE
    </src>
  </head>
  <body>
    <text>
      <name>
        NULL
        <comment>
          //姓名
        </comment>
      </name>
      <content>
        <part>
          坐在车厢里的人总会向外眺望。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <name>
        NULL
        <comment>
          //姓名
        </comment>
      </name>
      <content>
        <part>
          眺望的理由多种多样：
        </part>
        <action>
          newline
        </action>
        <part>
          晕车，发呆，欣赏风景……
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <name>
        NULL
        <comment>
          //姓名
        </comment>
      </name>
      <content>
        <part>
          亦或者只是下意识地一瞥。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
    <text>
      <name>
        NULL
        <comment>
          //姓名
        </comment>
      </name>
      <content>
        <part>
          但人们心中压抑的冲动都是相似的。
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal>

```

## Librian

librian中的一个文本是直接结束的

单行即为一句话

姓名位于文本前，要求显式给出，文本内容用繁体中文的引号包装

### Simple

>
>
>```liber
>潘大爺 「舟舟！來得正是時候！」
>```



### Translation

```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal>
  <head>
    <src>
      BKE
    </src>
  </head>
  <body>
    <text>
      <name>
        潘大爺
        <comment>
          //姓名
        </comment>
      </name>
      <content>
        <part>
          舟舟！來得正是時候！
        </part>
        <comment>
          //文本内容
        </comment>
      </content>
    </text>
  </body>
</unigal>
```

