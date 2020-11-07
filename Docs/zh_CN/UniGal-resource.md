# UniGal-resource

## Examples

```xml
<resource type="image">
<image>
<action>
//显示图像的方法


</action>

</image>
</resource>


<action>
    <showimage>
        //暂时没有设置图层概念因此没有设计目标图层,否则可以加一个dstLayer
        <imgname>
        </imgname>
        //提供两种标志图像范围的方法，两点标记或者LURD标记
        <imgpos>
            <pos1>//键值对</pos1>
            <pos2>//键值对</pos2>
        </imgpos>//但是不好解析
        <imgLURD>
            <L>1</L>
            <U>2</U>
            <R>3</R>
            <D>4</D>
        </imgULRD>
    </showimage>
</action>

above are written by LaoShuBaby
```
```xml
<imgLURD>1,2,3,4</imgLURD>

above are written by RimoChan
```

