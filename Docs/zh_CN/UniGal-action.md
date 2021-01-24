# UniGal-action

想了想，希望能把UniGal中的函数单独拿出来算一个章节去讲一讲。

这里只介绍各类action函数，不介绍其他函数

## 面向文本控制和演出效果的函数

这块从bke吸收进来了不少。

### 已整理的

11001. textcontrol

对应BKE的[]，对应AVG的【】

11002. newline

对应BKE的[r]，对应AVG的【】

11003. waitclick

对应BKE的[l]，对应AVG的【】

11004.clearmassagelayertext

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

## 面向资源调度的函数

### 图像image

21001.showimage

### 声音sound

22001.playsound

### 索引index

23001.refresh_layerlist

23002.refresh_channellist

23003.refresh_framelist

## 面向动画控制的函数

### 基本

31001.animation_start

参数：```animation_id```

31002.animation_stop

参数：```animation_id```

31003.animation_pause

参数：```animation_id```

31004.animation_continue

参数：```animation_id```

### 特效

暂无

### 其他

33001.animation_jumptoframe

参数：```animation_id```\ ```frame_id```

该函数是跳转到指定帧(如果需要跳转并继续播放应该再call一个恢复播放的取消暂停的cintinue),因此额外需要一个帧的定位参数，可以是int可以是pointer

xxxx.animation_playdirection

参数：```animation_id```\ ```direction```

控制倒放和正放，因此额外需要一个方向参数

## 面向网络和文件IO的函数

此外，网络访问和文件读写等操作也应属于action范畴。但UniGal仅表示“存在此项操作”，具体该操作如何实现以及引擎是否以安慰剂实现，UniGal不从标准的角度去规定。

在```<network_basic>```为```true```后可以使用```network_get```、```network_post```

在```<network_restful>```为```true```后可以使用```network_get```、```network_post```、```network_delete```、```network_put```

+ 1011. network_get
+ 1012. network_post
+ 1013. network_delete
+ 1014. network_put

在```<fileIO>```为```true```后可以使用如下函数

+ 1021. fileIO_read
+ 1022. fileIO_create
+ 1023. fileIO_delete