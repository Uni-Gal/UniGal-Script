# UniGal-srtuct

## 定义

```xml
<unigal-script>
  <body>
    <code>
      <struct>
        <label>
          <label_name>
            <!--标签的名字,目前标签尚未开发出更多用途。-->
            <!--name可以是英文数字字符串，也可以是中文名。-->
          </label_name>
          <label_ID>
            <!--标签对应的序号（并非所有引擎都会用到，是扩展属性）。-->
            <!--若某语言中是只有序号的，那么应优先使用label_name，仅在同时有名称和序号的时候使用label_ID-->
          </label_ID>
          <label_comment>
            <!--一个标签对应的故事（并非所有引擎都会用到，是扩展属性）-->
          </label_comment>
        </label>
        <count>
          <!--第X句台词的编号-->
        </count>
        <block>
          <block_name>
          </block_name>
          <block_type>
          </block_type>
          <block_body>
          </block_body>
          <!--部分游戏还在脚本文件和脚本行两个层次之间，有块的等级，因此在src_engine标记为这些语言的时候，解释器就需要深入block来探测。-->
          <!--别看，就是给Nova加的-->
          <!--如果硬要说其他游戏也有块，那么其他游戏整个脚本包一个block就好了，没必要这么费事-->
        </block>
      </struct>
    </code>
  </body>
</unigal-script>
```