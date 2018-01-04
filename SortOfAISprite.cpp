//
// Created by Oscar Törnquist on 2017-12-28.
//

#include "SortOfAISprite.h"

namespace game {
    SortOfAISprite::SortOfAISprite(int xPos, int yPos, int width, int height, float speed, const char *path)
            : PlayerSprite(xPos, yPos, width, height, speed, path) {
        setUp(true);
        randCount = 0;
    }

    SortOfAISprite *
    SortOfAISprite::getInstance(int xPos, int yPos, int width, int height, float speed, const char *path) {
        return new SortOfAISprite(xPos, yPos, width, height, speed, path);
    }

    void SortOfAISprite::tick() {
        float y = getRect().y;

        for (Bullet *b: bullets) {
            b->tick();
        }



        if (isUp() && y < 0) {
            setUp(false);
            setDown(true);
        }
        if (isDown() && y > (sys.getHeight() - getRect().h)) {
            setDown(false);
            setUp(true);
        }
        if (isUp()) {
            setRectY(y - getSpeed());
        } else if (isDown()) {
            setRectY(y += getSpeed());
        }

        /*
        if (randInt > 90 && randCount == 10) {
            shoot();
        }

        randInt = rand()%100;
        if (randCount < 10) {
            randCount++;
        } else if (randCount == 10) {
            randCount = 0;
        }
        */
    }

    SortOfAISprite::~SortOfAISprite() {

    }

    void SortOfAISprite::shoot() {
        Bullet *b = Bullet::getInstance(getRect().x - 20, getRect().y + getRect().h / 2, 20, 20, 10, "Textures/bullet.png",
                                        false);

        addBullet(b);
    }

    void SortOfAISprite::keyDown(const SDL_Event &) {
    }

    void SortOfAISprite::keyUp(const SDL_Event &) {
    }


}