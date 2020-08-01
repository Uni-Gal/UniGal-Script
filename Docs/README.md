# UniGal

## UniGal介绍
UniGal是一个希望能通过统一的语法标准和格式，允许从各种不同的引擎导入，并允许各游戏引擎的开发者构建支持UniGal的导入工具，实现类似ONNX一样的跨框架的方案支持，允许开发者快速从一套框架迁移到另一套更适合的框架，实现迈向开放世界的第一步。

## UniGal特性
1. UniGal为创造一种具有普适性的语法标准，因此采用了XML作为基础。之所以采用XML而不是JSON或YAML，可详见
2. UniGal是高度抽象化和反复封装的，因此对于一些较为简练的引擎来说，其语法显得较为繁琐。
3. UniGal将演出与脚本与代码等合为一体，不再刻意强调演出与剧本之间的工作划分，不将其分割为多个不同文件，不参与素材属于演出还是脚本的名词争端。
4. UniGal中凡是纯粹的文本内容，都用<text></text>包装，其他的均视为<code></code>包装

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

## 教程目录

以下是UniGal的文档的目录
Docs/UniGal-main
Docs/UniGal-text
Docs/UniGal-code
