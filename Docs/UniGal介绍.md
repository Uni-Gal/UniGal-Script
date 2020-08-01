# UniGal

## 代码示范
```
<?xml version="1.0" encoding="utf-8"?>
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
    <resource>
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
```
## 支持计划

### 可能支持的允许导出的引擎
nova
librian

### 准备支持的单向导入的引擎

krkr
BKE
librian
AVGPlus
snowing
unity-nova
unity-xihe animation engine

### 可能支持的单向导入的引擎
unity-Utage
unity-Fungus

## UniGal介绍

UniGal是一个希望能通过统一的语法标准和格式，允许从各种不同的引擎导入，并允许各游戏引擎的开发者构建支持UniGal的导入工具，实现类似ONNX一样的跨框架的方案支持，允许开发者快速从一套框架迁移到另一套更适合的框架，实现迈向开放世界的第一步。
UniGal为创造一种具有普适性的语法标准，因此采用了XML作为基础。
UniGal是高度抽象化和反复封装的，因此对于一些较为简练的引擎来说，其语法显得较为繁琐。
UniGal将演出与脚本与代码等合为一体，不再刻意强调演出与剧本之间的工作划分，不将其分割为多个不同文件，不参与素材属于演出还是脚本的名词争端。凡是纯粹的文本内容，都用<text></text>包装，其他的均视为<code></code>包装
UniGal脚本的后缀名为.unigal
UniGal文件分为<head></head>与<body></body>，其中<head></head>不涉及具体内容，而是存储各类配置，而<body></body>则是脚本的具体内容。
UniGal提供注释，注释内容为<comment></comment>中的内容，并必须以//为前缀

<text></text>教学
# BKE
在BKE中，纯文本可以直接输入。在换行时以[p]结尾，[r]为手动换行，[l]为等待点击。行之间的换行采用(WINDOWS-CRLF)
## Simple
```bkscr
你好，[l][r]世界！[p]
```
## Translate
```unigal
<?xml version="1.0" encoding="utf-8"?>
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
	    click
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

```


