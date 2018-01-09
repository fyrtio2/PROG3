

#include "NonMovableSprite.h"

namespace game{

    NonMovableSprite::NonMovableSprite(int xPos, int yPos, int width, int height, const char* path) : Sprite(xPos, yPos, width, height) {
        texture = IMG_LoadTexture(sys.getRen(), path);
        if (texture == NULL) {
            printf("Texture in NonMovableSprite is NULL\n" );
        }
    }

    void NonMovableSprite::draw() const {
        SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

    }

    NonMovableSprite* NonMovableSprite::getInstance(int xPos, int yPos, int width, int height, const char* path) {
        return new NonMovableSprite(xPos, yPos, width, height, path);
    }

    NonMovableSprite::~NonMovableSprite() {
        SDL_DestroyTexture(texture);
    }
}