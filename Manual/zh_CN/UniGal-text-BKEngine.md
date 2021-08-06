# BKEngine

参见http://docs.bakery.moe/new/quickstart/#_3

在BKE中，纯文本可以直接输入。在换行时以[p]结尾，[r]为手动换行，[l]为等待点击。行之间的换行采用(WINDOWS-CRLF)

在BKE官方API中给出的，涉及文本处理的非状态关键字有如下三种。

因为BKE的脚本也涉及多代处理系统，因此用[]包装是可以的，而改为@的新方式也是可以的。鉴于较多复杂的效果函数采用@调用的方式，我们暂时仅处理[]包装的文本控制函数。

三种分别对应的UniGal中的行为如下
|关键字|内容|UniGal中的处理|对应的action|
| ---- | ----- | ----- | ----- |
|r|手动换行|插入action宏来分割part|newline|
|l|等待点击|插入action宏来分割part|waitclick|
|p|换页等待，点击后换页|结束一个```<text></text>```|无|

注意，所有的换行和点击等一系列函数都不属于单纯的文本处理，应将其视作```<code><action></action></code>```中的一个函数

此外，加粗/倾斜/删除线/下划线 四个状态已通过/text/character/style或/text/content/style加入到```<text></text>```中

### Simple

>```bkscr
>*main
>你好，[l][r]世界！[p]
>```