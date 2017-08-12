include_directories(./)
include_directories(./event_queue/)
include_directories(./game_basic/)
include_directories(./poker/)
include_directories(./poker_ddz/)
include_directories(./poker_ddz/ai)
include_directories(./poker_ddz/player)
include_directories(./poker_ddz/rule)

set(GAME_BASIC_CODE
  event_queue/Event.cpp
  event_queue/EventQueue.cpp
  event_queue/EventQueueListener.cpp

  game_basic/CardGroup.cpp
  game_basic/CardGame.cpp
  game_basic/Player.cpp
  game_basic/PlayerRing.cpp
  game_basic/Dealer.cpp
  game_basic/Action.cpp
  game_basic/GameRule.cpp
  game_basic/PlayCardsAction.cpp
  game_basic/HistoricalStack.cpp

  poker/PokerCard.cpp
  poker/PokerCardGame.cpp
  poker/PokerCardUtils.cpp

  poker_ddz/PokerCardGameDDZ.cpp
  poker_ddz/PokerCardGameDDZDealer.cpp
  poker_ddz/PokerCardGameDDZUtils.cpp

  poker_ddz/rule/DDZDecideDZRule.cpp

  poker_ddz/player/PokerCardGameDDZPlayer.cpp

  poker_ddz/ai/DDZEntrustAI.cpp
)

add_library(CardGame
	SHARED
	${GAME_BASIC_CODE}
)
