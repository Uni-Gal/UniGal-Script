# UniGal-resource

## 杂谈

Resource是关于资源的组织和安排的一个功能

关于Resource的内容

按照@Fa鸽 的说法，这块和index都应该重新修正表述方式

因此我们关于Resource的内容，都将单独安排

## 原则

对于同一行中有图有字的处理方式，若非引擎特殊情况，UniGal中尽可能优先为“先音乐后图片最后文字”的顺序，越复杂的演出效果越优先。

注意！！index到底算不算resource，暂时是算的，未来是什么情况我们也不知道怎么处理合适，还在研究中！关于resource的实现还请大家不要急！如果可以先支持text比较好！

## resource定义

```xml
<unigal-script>
    <body>
        <code>
      <resource type="image">
        <image>
          <img_ID>
            <!--图像ID-->
          </img_ID>
          <layer_ID>
            <!--图层ID，若不声明则放进默认图层，若没有默认图层则放进最高图层-->
          </layer_ID>
          <file>
            <!--文件路径，为文件的完整路径或相对路径，但必须保留扩展名-->
          </file>
          <load>
            <!--载入内存-->
          </load>
          <free>
            <!--从内存释放。若目标实现的图像由GC管理，则无效果。-->
          </free>
          <image_opacity>
            <!--私以为一个图层如果允许多个图像并存（图层成为图像文件夹的概念了的话）-->
            <!--那么每个图像的透明度也是非常有必要引入的,因此这一点上看，对称的，单个音频也应该可以单独调节音量-->
          </image_opacity>
          <size>
            <x></x>
            <y></y>
          </size>
        </image>
          <image_type>
            <!--
              内置background、cg、tachie、Other
              若使用了目标实现不支持的图像类型，该图像就是Other
            -->
          </image_type>
        <background_info>
          <!--背景-->
          <weather>
          </weather>
          <time>
          </time>
        </background_info>
        <cg_info>
          <!--CG-->
          <!--可能会引入serial之类的东西，因为感觉CG还是有一些可提取的特征的-->
        </cg_info>
        <tachie_info>
          <!--立绘-->
          <cloth>
            <!--服装-->
          </cloth>
          <pose>
            <!--动作造型-->
          </pose>
          <expression>
            <!--表情-->
          </expression>
        </tachie_info>
      </resource>
      <resource type="sound">
        <sound>
          <sound_ID>
            <!--声音ID-->
          </sound_ID>
          <channel_id>
            <!--
              channel_id填channel的编号
            -->
          </channel_id>
          <sound_type>
            <!--
              内置BGM、Voice、Ambient/Effect（总之就是音效~，叮啊铛啊的~）、Other
              其它类型由实现定义
              若使用了目标实现不支持的声音类型，该声音就是Other
            -->
          </sound_type>
          <file>
            <!--文件路径，为文件的完整路径或相对路径，但必须保留扩展名-->
          </file>
          <load>
            <!--载入内存-->
          </load>
          <free>
            <!--从内存释放。若目标实现的声音由GC管理，则无效果。-->
          </free>
          <sound_volume>
            <!--在允许channel成组调节音量的基础上，可以单个文件的调节音量-->
          </sound_volume>
          <!--文件基本信息-->
        </sound>
      </resource>
      <resource type="video">
        <!--参考image，只不过里面的img_id换成vid_id这样-->
      </resource>
      <resource type="layer">
        <!--layer可以同时存放image和video，因为video在某一时刻就是一张图片-->
        <!-- layer的内容太长写不下了，可以自己去看UniGal-layer.md -->
        <!-- 但是上面的树依然是正常的写出来了 -->
      </resource>
      <resource type="channel">
        <!---->
      </resource>
      <resource type="index">
        <layerlist>
        </layerlist>
        <channellist>
        </channellist>
        <framelist>
        </framelist>
      </resource>
      <resource type="live2d">
        <!---->
      </resource>
      <resource type="spine">
        <!---->
      </resource>
        </code>
    </body>
</unigal-script>
```

## resource指南

要从其他引擎迁移到UniGal，以下是为这些引擎的语法转换指南

+ [AVGPlus](../../Manual/zh_CN/UniGal-code-resource-AVGPlus.md)
+ [BKEngine](../../Manual/zh_CN/UniGal-code-resource-BKEngine.md)
+ [Librian](../../Manual/zh_CN/UniGal-code-resource-Librian.md)
+ [Nova](../../Manual/zh_CN/UniGal-code-resource-Nova.md)