# 元游戏拓展专项
这一章节的内容不应该用于一般的文字冒险游戏，且可能不受支持

## action
+ 1032. archive_allow
+ 1033. archive_delete
+ 1034. archive_clear

像DDLC、君彼女这样的meta游戏，存档可以是剧情的一部分。有时候这些游戏的剧情进行到一定地步时，会加载、清空、删除存档或禁止用户存档。  
通过使用`<archive_allow status="false" />`来禁止用户存档，反之将`status`参数修改为`true`将允许用户存档。  
`archive_delete`和`archive_clear`可以删除存档，delete删除单个，clear删除全部