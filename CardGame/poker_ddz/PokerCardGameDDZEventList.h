#ifndef CARD_GAME_GAME_DDZ_EVENT_LIST
#define CARD_GAME_GAME_DDZ_EVENT_LIST

#include "EventList.h"

#define   EVENT_SHUFFLE_AND_DEAL        "SHUFFLE_AND_DEAL"    // Data: Game

#define   EVENT_DZ_START                "DZ_START"
#define   EVENT_DZ_ASK_TO_BE            "DZ_ASK_TO_BE"        // Data: DZInfo
#define   EVENT_DZ_TO_BE                "DZ_TO_BE"  // Data: DZInfo
#define   EVENT_DZ_NOT_TO_BE            "DZ_NOT_TO_BE"  // Data: DZInfo
#define   EVENT_DZ_NO_DECIDE_YET        "DZ_NO_DECIDE_YET"
#define   EVENT_DZ_CLAIM                "DZ_CLAIM"
#define   EVENT_DZ_SHOW_3_CARDS         "DZ_SHOW_3_CARDS"

#define   EVENT_ASK_TO_PLAY             "ASK_TO_PLAY"         //
#define   EVENT_WANT_TO_PLAY_CARDS      "WANT_TO_PLAY_CARDS"
#define   EVENT_PASS_THIS_TURN          "PASS_THIS_TURN"
#define   EVENT_I_WIN                   "I_WIN"
#define   EVENT_CLAIM_WIN               "CLAIM_WIN"
#define   EVENT_FINISH_ALL_CARD         "FINISH_ALL_CARD"
#endif /* end of include guard: CARD_GAME_GAME_DDZ_EVENT_LIST */
