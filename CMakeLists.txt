cmake_minimum_required(VERSION 3.0)

project(C)

set( CMAKE_CXX_EXTENSIONS ON )

include_directories(./)

add_subdirectory (CardGame)
include_directories(CardGame)
include_directories(CardGame/event_queue/)
include_directories(CardGame/game_basic/)
include_directories(CardGame/poker/)
include_directories(CardGame/poker_ddz/)

############################################# APP

add_executable(ddz APP/ddz.cpp)
target_link_libraries (ddz CardGame)
# target_link_libraries (ddz Dragon)
