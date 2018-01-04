

#include "GameEngine.h"
#include "NonMovableSprite.h"
#include "PlayerSprite.h"
#include "SortOfAISprite.h"

using namespace game;

int main() {

    printf("Hello world! \n");
    GameEngine game;

    NonMovableSprite* bg = NonMovableSprite::getInstance(0,0, sys.getWidth(), sys.getHeight(), "Textures/bg.png");
    PlayerSprite* player = PlayerSprite::getInstance(30, 300, 100, 100, 2.5, "Textures/UFO-Icon.png");
    SortOfAISprite* enemy = SortOfAISprite::getInstance(sys.getWidth() - 130, 300 , 100, 100, 2.5, "Textures/enemy_icon.png");

    game.add(bg);
    game.add(player);
    game.add(enemy);
    game.run();



    return 0;
}