# UniGal-logic

## logic段定义

```xml
<unigal-script>
  <body>
    <code>
      <logic>
        <jump>
          <jump_dst>
            <!--目的地标签-->
          </jump_dst>
          <jump_addtional>
            <!--附加内容-->
          </jump_addtional>
        </jump>
        <switch>
          <switch_choise>
            <choise_name>
              <!--选择支显示名称-->
            </choise_name>
            <choise_label>
              <!--选择支跳转目标-->
            </choise_label>
          </switch_choise>
          <switch_timer>
            <timer_num>
              <!--允许您写一个以毫秒为单位的倒计时-->
            </timer_num>
            <timer_default>
              <!--倒计时结束后需要自动选择的选择支的名称-->
            </timer_default>
          </switch_timer>
        </switch>
        <!--您只能选择switch或jump中的一种logic-->
      </logic>
    </code>
  </body>
</unigal-script>
```