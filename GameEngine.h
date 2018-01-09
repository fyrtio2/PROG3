

#ifndef GAME_GAMEENGINE_H
#define GAME_GAMEENGINE_H

#include <vector>
#include "Sprite.h"
#include <SDL.h>
#include "System.h"

namespace game {
    class GameEngine {
    public:
        GameEngine();
        ~GameEngine();
        void add(Sprite* );
        void run();

        void draw();
        void ticker();
        void collisionCheck();

    private:
        std::vector<Sprite*> sprites;

    };
}

#endif //GAME_GAMEENGINE_H
