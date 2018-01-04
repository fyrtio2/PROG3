//
// Created by Oscar Törnquist on 2017-12-20.
//

#ifndef GAME_NONMOVABLESPRITE_H
#define GAME_NONMOVABLESPRITE_H

#include "Sprite.h"

namespace game {
    class NonMovableSprite: public Sprite{
    public:

        static NonMovableSprite* getInstance(int xPos, int yPos, int width, int height, const char* path);
        virtual ~NonMovableSprite();


        void draw() const;
    protected:
        NonMovableSprite(int xPos, int yPos, int width, int height, const char* path);

    private:
        SDL_Texture* texture;

    };
}

#endif //GAME_NONMOVABLESPRITE_H
