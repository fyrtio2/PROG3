cmake_minimum_required(VERSION 3.9)
project(game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
add_executable(game main.cpp System.cpp System.h GameEngine.cpp GameEngine.h Sprite.cpp Sprite.h NonMovableSprite.cpp NonMovableSprite.h MovableSprite.cpp MovableSprite.h PlayerSprite.cpp PlayerSprite.h Bullet.cpp Bullet.h SortOfAISprite.cpp SortOfAISprite.h)

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(game ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})