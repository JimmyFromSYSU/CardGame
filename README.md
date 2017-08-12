# CardGame
一个卡牌游戏的游戏流程通用框架，目前为实现扑克牌斗地主游戏。

# Feature
* 事件驱动，解耦了游戏中的各个组成部分，如Dealer，Player，Rule，Historical，UI等之间通过事件队列通信。
* CardGame类负责组装游戏，比如选择Player，Dealer，Rule等。
* GameRule解耦了游戏规则，这样就可以通过更换Rule完成相似的游戏，比如更换斗地主中选地主的流程，更改发牌洗牌流程等。
* HistoricalStack监听所有玩家的Action，所有Action可以撤销。

# TODO
* 添加GameState: 游戏全局状态，从而可以中途保存游戏，重新加载以便调试。
* GameState中包含HistoricalStack，可以回溯游戏流程。
* 添加AIPlayer，并添加第一个AI：托管AI
* AI出牌合理性检测：判断AI选择的Action是否是游戏规则所允许的。

# BUG
