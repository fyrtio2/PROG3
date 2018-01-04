//
// Created by Oscar Törnquist on 2017-12-28.
//

#ifndef GAME_SORTOFAISPRITE_H
#define GAME_SORTOFAISPRITE_H

#include "PlayerSprite.h"

namespace game {
    class SortOfAISprite: public PlayerSprite {
    public:
        static SortOfAISprite* getInstance(int xPos, int yPos, int width, int height, float speed, const char* path);
        void tick();
        virtual ~SortOfAISprite();
        void keyDown(const SDL_Event&);
        void keyUp(const SDL_Event&);

    protected:
        SortOfAISprite(int xPos, int yPos, int width, int height, float speed, const char *path);
        void shoot();

    private:
        int randInt;
        int randCount;

    };
}


#endif //GAME_SORTOFAISPRITE_H
