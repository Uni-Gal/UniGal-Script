# UniGal-text

**<text></text>**

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
```

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


