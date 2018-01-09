
#include "Bullet.h"

namespace game {

    Bullet::Bullet(int xPos, int yPos, int width, int height, float speed, const char *path, bool direction)
            : MovableSprite(xPos, yPos, width,
                            height,
                            speed) {
        texture = IMG_LoadTexture(sys.getRen(), path);
        if (texture == NULL) {
            printf("Texture in Bullet is NULL\n");
        }
        /*
         * Direction är antingen höger och vänster,
         * true för höger
         * false för vänster
         */

        if (direction) {
            setRight(true);
        } else {
            setLeft(true);
        }



    }

    Bullet *
    Bullet::getInstance(int xPos, int yPos, int width, int height, float speed, const char *path, bool direction) {
        return new Bullet(xPos, yPos, width, height, speed, path, direction);
    }

    void Bullet::tick() {
        int x = getRect().x;
        if (isRight()) {
            setRectX(x += getSpeed());
        }
        if (isLeft()) {
            setRectX(x -= getSpeed());
        }

    }

    void Bullet::draw() const {
        SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
    }

    Bullet::~Bullet() {
        SDL_DestroyTexture(texture);
    }
}