## UniGal-text
Text呈现游戏的台本
## 示例
以这一段BKE脚本为例
```bkscr
*main
你好，[l][r]世界！[p]
```

翻译过来，并添加说话角色“Fa鸽”是这样
```xml
<?xml version="1.0" encoding="utf-8"?>
<unigal-script>
  <head>
    <src>
      BKE
    </src>
  </head>
  <body>
    <text>

      <pages>
        <character>Fa鸽</character>
        <page label="main">
          <para>你好，</para>
          <para>世界！</para>
        </page>
      </pages>
    </text>
  </body>
</unigal-script>
```
显示出来是这样

![textv2-sample.svg](./text-sample.svg)  

我们再来演示点别的活
```xml
<unigal-script>
  <body>
    <text>
      <pages>
        <character></character>
        <page>
          <para><sized size="large">大号字</sized>演示</para>
          <para><bold>加粗</bold>演示</para>
          <para><underlined>加下划线</underlined>演示</para>
          <para><shadow color="#FFFF0000">黄色不透明文字阴影</shadow>演示</para>
          <para><glow color="#0033FF00">蓝色外发光</glow>演示</para>
        </page>
      </pages>
    </text>
  </body>
</unigal-script>
```
