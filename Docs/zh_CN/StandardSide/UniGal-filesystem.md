# UniGal-filesystem


## UniGal路径规则

目前的文件路径有三种，绝对路径、相对路径、包路径。

用双引号来表示绝对路径，用单引号表示相对路径。

### 绝对路径

绝对路径需要从根目录开始书写。

绝对路径对```\```和```/```是敏感的，Windows路径使用```\```，Unix路径使用```/```

#### Windows写法

```
"C:\Users\Administrator\Documents\UniGal-Script\Hello_World.jpg"
```

#### Unix写法

```
"/usr/root/home/download/UniGal-Script/Hello_World.jpg"
```

### 相对路径

相对路径仅写相对于本目录(工程目录)的层次即可，最前端不需符号。

#### Windows写法

若工作目录的绝对路径为

```
"C:\Users\Administrator\Documents\UniGal-Script"
```

文件的绝对路径为

```
"C:\Users\Administrator\Documents\UniGal-Script\Data\Image\Background\Sakura.jpg"
```

则文件的相对路径为

```
"Data\Image\Background\Sakura.jpg"
```

#### Unix写法

若工作目录的绝对路径为

```
"/usr/root/home/download/UniGal-Script"
```

文件的绝对路径为

```
"/usr/root/home/download/UniGal-Script/Data/Image/Background/Sakura.jpg"
```

则文件的相对路径为

```
"Data/Image/Background/Sakura.jpg"
```

### 包路径

对于从psd/zip等文件中读取路径的情况，需要用特殊的方式来书写路径（包路径）。

包路径必须为```([包内路径]@{包文件路径})```的格式出现，括号代表组合为整体，@表示定位于，方括号代表元素，花括号代表集合。

包内路径必须以相对路径书写，包文件路径可以使用绝对路径也可以使用相对路径。

包可以是zip包/docx包/psd包等一系列形式。只要能提供一个可访问的层级，就可以被定义为包。对包的具体访问应由具体引擎实现，UniGal在标准层次上不应干涉。

如

```
(['data/image/background/campus.bmp']@{"D:\Games\Galgame\UniGal.zip"})
```

## 其他引擎中的路径规则和文件系统规则

### BKEngine

图像：http://docs.bakery.moe/old/image/

音频：http://docs.bakery.moe/old/sound/

读文件：http://docs.bakery.moe/parser/#loadfile

精灵sprite需要的文件路径格式：http://docs.bakery.moe/bkscr/sprite/

### Librian

图像：https://doc.librian.net/site/%E7%94%A8%E6%88%B6%E6%8C%87%E5%8D%97/%E7%AB%8B%E7%B9%AA.html

### Nova

似乎没有专门提到

有这个：https://github.com/Lunatic-Works/Nova/wiki/Repo-Structure

还有这个：https://github.com/Lunatic-Works/Nova/wiki/Standing-Import

似乎Nova全都是相对路径的（x