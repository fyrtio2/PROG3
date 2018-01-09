

#include "Sprite.h"

namespace game {

    Sprite::~Sprite() {
        //Måste implementera virtuella destruktorer för alla sprites
    }

    void Sprite::keyDown(const SDL_Event &) {

    }

    void Sprite::keyUp(const SDL_Event &) {

    }


    Sprite::Sprite(int xPos, int yPos, int width, int heigth): destRect{xPos, yPos, width, heigth} {

    }

    void Sprite::tick() {

    }

    void Sprite::setRectX(float x) {
        destRect.x = x;
    }

    void Sprite::setRectY(float y) {
        destRect.y = y;
    }

    bool Sprite::checkCollision(Sprite* s) {

    }



}
