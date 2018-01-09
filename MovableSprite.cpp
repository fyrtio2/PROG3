

#include "MovableSprite.h"

namespace game {

    MovableSprite *MovableSprite::getInstance(int xPos, int yPos, int width, int heigth, float speed) {
        return new MovableSprite(xPos, yPos, width, heigth, speed);
    }

    MovableSprite::MovableSprite(int xPos, int yPos, int width, int height, float speed) : Sprite(xPos, yPos, width,
                                                                                                  height) {
        /*
         * Om hastigheten är mer eller mindre än tillåtet sätts den till STANDARD_SPEED vid skapandet av objektet
         */

        if (speed > MAX_SPEED || speed < MIN_SPEED) {
            this->speed = STANDARD_SPEED;
        } else {
            this->speed = speed;
        }

        right = up = down = left = false;
    }


    void MovableSprite::setRight(bool b) {
        if (!right && b) {
            right = b;
        } else if (right && !b) {
            right = b;
        }
    }

    void MovableSprite::setLeft(bool b) {
        if (!left && b) {
            left = b;
        } else if (left && !b) {
            left = b;
        }
    }

    void MovableSprite::setUp(bool b) {
        if (!up && b) {
            up = b;
        } else if (up && !b) {
            up = b;
        }
    }

    void MovableSprite::setDown(bool b) {
        if (!down && b) {
            down = b;
        } else if (down && !b) {
            down = b;
        }
    }

    void MovableSprite::setSpeed(float f) {
        speed = f;
    }

    void MovableSprite::tick() {

    }

    void MovableSprite::draw() const {

    }

    void MovableSprite::keyDown(const SDL_Event &) {

    }

    void MovableSprite::keyUp(const SDL_Event &) {

    }


    MovableSprite::~MovableSprite() {

    }

    bool MovableSprite::isRight() const {
        return right;
    }

    bool MovableSprite::isLeft() const {
        return left;
    }

    bool MovableSprite::isUp() const {
        return up;
    }

    bool MovableSprite::isDown() const {
        return down;
    }

    float MovableSprite::getSpeed() const {
        return speed;
    }

}
