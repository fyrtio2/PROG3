

#ifndef GAME_BULLET_H
#define GAME_BULLET_H

#include "MovableSprite.h"
#include <vector>

namespace game {
    class Bullet: public MovableSprite{
    public:
        static Bullet* getInstance(int xPos, int yPos, int width, int height, float speed, const char* path, bool direction);
        void tick();
        void draw() const;
        ~Bullet();
    protected:
        Bullet(int xPos, int yPos, int width, int height, float speed, const char* path, bool direction);
    private:
        SDL_Texture* texture;
    };
}

#endif //GAME_BULLET_H
