# UniGal-action

## action定义

```xml
<unigal-script>
  <body>
    <code>
      <action>
        <!--正在考虑把函数的定义挪动到单独的文件夹中-->
        <!--为了保证一致性，对textcontrol的层次进行了变动。-->
        <textcontrol>
          <waitclick>
            true
          </waitclick>
        </textcontrol>
        <textcontrol>
          <newline>
            true
          </newline>
        </textcontrol>
        <imagecontrol>
          <showimage>
            <!--暂时没有设置图层概念因此没有设计目标图层,否则可以加一个dstLayer-->
            <imgname>
            </imgname>
            <!-- 提供三种储存图像范围的方法，两点标记，LURD标记以及仿射矩阵 -->
            <img_region>
              <DoublePoint>
                <Point1>
                  <!--左上点-->
                  <pos1>
                    <!--row-->
                  </pos1>
                  <pos2>
                    <!--col-->
                  </pos2>
                </Point1>
                <Point2>
                  <!--右下点-->
                  <pos1>
                    <!--row-->
                  </pos1>
                  <pos2>
                    <!--col-->
                  </pos2>
                </Point2>
              </DoublePoint>
              <LURD>
                <L>1</L>
                <U>2</U>
                <R>3</R>
                <D>4</D>
              </LURD>
              <TransformMatirx>
                左上,右上,左下,右下,x坐标,y坐标
              </TransformMatirx>
              <!--imgRegion提供多种的表示图像区域的方法，互相等价，内部储存方式由实现定义，会自动进行转换。-->
            </img_region>
          </showimage>
        </imagecontrol>
        <soundcontrol>
          <showsound>
            <!-- 音乐播放的部分就靠你了,包括淡入淡出之类的 -->
          </showsound>
        </soundcontrol>
        <indexcontrol>
          <!--索引包括layerlist、channellist、framelist等多种类型-->
        </indexcontrol>
        <animationcontrol>
          <!--动画控制函数-->
        </animationcontrol>
        <otherscontrol>
          <!--其他控制，如IO和网路-->
        </otherscontrol>
      </action>
    </code>
  </body>
</unigal-script>
```

## actionlist


想了想，希望能把UniGal中的函数单独拿出来算一个章节去讲一讲。

这里只介绍各类action函数，不介绍其他函数

## 面向文本控制和演出效果的函数 **textcontrol**

这块从bke吸收进来了不少。

### 已整理的

11001. newline

对应BKE的[r]

11002. waitclick

对应BKE的[l]，对应AVGPlus的[wait]。但是AVGPlus的[wait=time]的形式如何处理未定。

11003.clearmassagelayertext

仅对应BKE的[er]

### BKEngine来源的还未整理的

#### 文本效果

在BKE中，[p]，[r]，[l]三个文本相关的之外，另外有@storefont、@restorefont两种储存文本状态的

|关键字|内容|备注|
| ---- | ------ |---|
|storefont|如果多次storefont，只会保存最后一次的结果。|暂存字体信息|
|restorefont|用restorefont命令可以将字体设为最后一次storefont时的状态。|复原字体信息|

文本状态可能会抽为一个resource

但是真的文本状态放进无状态的unigal以后是会丢失的。因为unigal是一个无状态的语言，包括变量也不可以直接说增量而只能说当前量的。unigal的text就是一种“当前量”。这两个函数真的很难搞。

#### 文本控制类代码

这类效果应由解释器和编译器中间设置缓存变量，不应表现在最终的unigal代码中（但是可以加注释）

+ text
+ textcursor
+ textwindow
+ textoff
+ texton
+ textspeed
+ textstyle
+ texttag
+ textsprite

总之，这些BKE残留的状态量（BKE是有状态的，我确信），最终在转化成unigal的时候，给一个选项吧，如果是允许保留状态就给个resource，如果是不允许保留状态，那么他就会在unigal中被消失处理，同时给一个UEP-W。而在unigal到其他语言的这个过程中，unigal已经损失了信息了，到有状态语言需要压栈，到bke的话就直接每句话都硬声明就可以。

具体的实现，我们希望能用official的complier给大家一个合理的交代，告诉大家我们认为应该怎么做。

### AVGPlus来源的

我看AVGPlus这块也不少，甚至可以和BKE有重复的部分。

### Nova/Librian来源的

暂无

## 面向资源调度的函数 **分拆分类**

### 图像 **imagecontrol**

21001.showimage

### 声音 **soundcontrol**

22001.playsound

### 索引 **indexcontrol**

23001.refresh_layerlist

23002.refresh_channellist

23003.refresh_framelist

## 面向动画控制的函数 **animationcontrol**

### 基本

31001.animation_start

参数：```animation_id```

虽然这个函数是从BKEngine里面抽提出来的，BKE里面是需要传入单个frame的id，但是UniGal中认为frame是animation的基类，它被animation所继承，应从animation中调用。

31002.animation_stop

参数：```animation_id```

31003.animation_pause

参数：```animation_id```

31004.animation_continue

参数：```animation_id```

32005.animation_changespeed

调节animation的播放帧率速率

32006.animation_lastingtime

调节frame的持续时间

### 特效

32001.animation_move

平移，对于有对应函数的引擎采用转换的方式，没有的采用重设参数（可能伴删掉旧animation结构）的方式实现

32002.animation_resize

缩放(可不按比例，只看传入参数)，对于有对应函数的引擎采用转换的方式，没有的采用重设参数（可能伴删掉旧animation结构）的方式实现

32005.animation_changetransparency

调节animation的透明度（未来到底是调animation的还是frame的待议）

### 其他

33001.animation_jumptoframe

参数：```animation_id```\ ```frame_id```

该函数是跳转到指定帧(如果需要跳转并继续播放应该再call一个恢复播放的取消暂停的cintinue),因此额外需要一个帧的定位参数，可以是int可以是pointer

xxxx.animation_playdirection

参数：```animation_id```\ ```direction```

控制倒放和正放，因此额外需要一个方向参数

## 存档读档 **save**
Galgame没有存档那就莫得灵魂，这里规定一些存档action，用来取代原来的io和net。  面向网络和文件IO的函数是危险的，因此您不应在此处寻找，而是参考https://github.com/Uni-Gal/UniGal-Script/pull/8/files  
标准保证：自动存档`save_auto`和按槽位存档`save_at`可用且有效，如果无效建议换个引擎，毕竟这年头没有存档的gal十有八九是整活（当然你非要整这种阴间活当我没说）。    
当`save_existcloud`为true时，`save_*cloud`可用  

对于存档相关的内容，我们并不采用文件IO的方式来处理

存档并非一个脚本的必需品，存档的具体结构是依赖引擎的实现的。UniGal的对于存档的描述，仅限于存档是位于一个剧本中所必备的内容的时候。

我们不具体描述一次存档的实现方式，但是会提供描述一次存档的方法

存读的函数，可以包含文件名、图像、字符串等一系列作为参数。快速存读也可以作为参数。希望这可以帮助对一些特定的引擎和特定的游戏的精准描述有帮助。

但是，不是所有引擎都支持如此高度自定义的存读行为，因此向某些引擎翻译的时候，将可能出现数据损失或不存在实现方法的问题。需要根据实际情况给予UEE0005或者UEW-ProposalDistEngineLoss

+ 1001. save_auto  
+ 1002. save_at，示例`<save_at page="autosave" slot="1" />`  
+ 1003. save_pushcloud，示例`<save_pushcloud timeout="2000ms" />`  
+ 1004. save_pullcloud，示例`<save_pullcloud timeout="2000ms" />`  

### 备注
#### save_auto
进行一次自动存档
#### save_at
`save_at`的page参数按字符串处理，当值为`"autosave"`时，这个存档是自动存档，和`save_auto`存的自动存档处在同一页。

#### save_*cloud
云存档操作，可以没有。  
目标引擎不支持，但你又恰好用了这些功能时会发出警告UEE0005。  
`save_pushcloud`推送时将覆盖云存档，同理`save_pullcloud`拉取时覆盖本地存档。  
