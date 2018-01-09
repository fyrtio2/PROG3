

#include "PlayerSprite.h"


namespace game {

    PlayerSprite *PlayerSprite::getInstance(int xPos, int yPos, int width, int heigth, float speed, const char *path) {
        return new PlayerSprite(xPos, yPos, width, heigth, speed, path);
    }

    PlayerSprite::PlayerSprite(int xPos, int yPos, int width, int heigth, float speed, const char *path)
            : MovableSprite(
            xPos, yPos, width, heigth, speed) {

        texture = IMG_LoadTexture(sys.getRen(), path);
        if (texture == NULL) {
            printf("Texture in PlayerSprite is NULL\n");

        }
    }

    void PlayerSprite::draw() const {
        SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
        for (Bullet *b: bullets) {
            b->draw();
        }
    }

    void PlayerSprite::tick() {

        float x = getRect().x;
        float y = getRect().y;

        if (isUp() && (y > 0)) {
            setRectY(y -= getSpeed());
        }
        if (isDown() && ((y + getRect().h) < sys.getHeight())) {
            setRectY(y += getSpeed());
        }
        if (isRight() && ((x + getRect().w) < sys.getWidth())) {
            setRectX(x += getSpeed());
        }
        if (isLeft() && (x > 0)) {
            setRectX(x -= getSpeed());
        }

        int iter = 0;
        for (Bullet *b: bullets) {
            b->tick();
            if ((b->getRect().x > sys.getWidth() + 100) || b->getRect().x < 0 - 100) {
                //bullets.erase(std::remove(bullets.begin(), bullets.end(), b), bullets.end());
                bullets.erase(bullets.begin() + iter);
                delete b;
            }
            iter++;
        }


    }

    void PlayerSprite::keyDown(const SDL_Event &event) {
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT:
                //setRight(true);
                break;
            case SDLK_LEFT:
                //setLeft(true);
                break;
            case SDLK_UP:
                setUp(true);
                break;
            case SDLK_DOWN:
                setDown(true);
                break;
            case SDLK_SPACE:
                shoot();
                break;
        }
    }

    void PlayerSprite::keyUp(const SDL_Event &event) {
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT:
                setRight(false);
                break;
            case SDLK_LEFT:
                setLeft(false);
                break;
            case SDLK_UP:
                setUp(false);
                break;
            case SDLK_DOWN:
                setDown(false);
                break;
        }
    }


    void PlayerSprite::shoot() {
        Bullet *b = Bullet::getInstance(getRect().x + getRect().w, getRect().y + getRect().h / 2, 20, 20, 10,
                                        "Textures/bullet.png", true);
        addBullet(b);


    }

    PlayerSprite::~PlayerSprite() {
        SDL_DestroyTexture(texture);
    }

    void PlayerSprite::addBullet(Bullet *b) {
        bullets.push_back(b);
    }

    bool PlayerSprite::checkCollision(Sprite* s) {
        for (Bullet *b: bullets) {
            if (dynamic_cast<MovableSprite*>(s) && (SDL_HasIntersection(&b->getRect(), &s->getRect()))) {
                bullets.erase(std::remove(bullets.begin(), bullets.end(), b));
                delete b;
                return true;

            }
        }
        return false;
    }
}