# Librian

参见https://doc.librian.net/site/%E7%94%A8%E6%88%B6%E6%8C%87%E5%8D%97/%E5%8A%87%E6%9C%AC%E5%AF%AB%E6%B3%95.html

librian中的一个文本是直接结束的

单行即为一句话

姓名位于文本前，要求显式给出，文本内容用繁体中文的引号包装

总之，librian的基本文本语法较为简单

### Simple

>```liber
>潘大爺 「舟舟！來得正是時候！」
>```

### Translation

```unigal
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      Librian
    </src>
  </head>
  <body>
    <text>
      <character>
	<name>
          潘大爺
        </name>
        <comment>
          //姓名
        </comment>
      </character>
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
</unigal-script>
```