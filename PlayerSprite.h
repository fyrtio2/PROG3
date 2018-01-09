
#ifndef GAME_PLAYERSPRITE_H
#define GAME_PLAYERSPRITE_H

#include "MovableSprite.h"
#include "Bullet.h"

namespace game {
    class PlayerSprite: public MovableSprite{

    public:

        static PlayerSprite* getInstance(int xPos, int yPos, int width, int heigth, float speed, const char* path);
        virtual void keyDown(const SDL_Event&);
        virtual void keyUp(const SDL_Event&);
        virtual void draw() const;
        virtual void tick();
        bool checkCollision(Sprite* s);
        virtual ~PlayerSprite();

    protected:
        PlayerSprite(int xPos, int yPos, int width, int heigth, float speed, const char* path);
        virtual void shoot();
        void addBullet(Bullet*);
        std::vector <Bullet*> bullets;

    private:
        SDL_Texture* texture;
    };
}

#endif //GAME_PLAYERSPRITE_H
