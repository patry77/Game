cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game main.cpp Player.cpp Player.h Animation.cpp Animation.h Map.cpp Map.h NPC.cpp NPC.h Menu.cpp Menu.h)

##### SFML #####
set(SFML__STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(Game sfml-system sfml-window sfml-graphics sfml-audio)
