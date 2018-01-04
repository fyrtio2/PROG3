//
// Created by Oscar Törnquist on 2017-12-23.
//

#ifndef GAME_MOVABLESPRITE_H
#define GAME_MOVABLESPRITE_H


#include "Sprite.h"

#define STANDARD_SPEED 1.5f
#define MAX_SPEED 15.0f
#define MIN_SPEED 0.5f

namespace game {
    class MovableSprite: public Sprite{
    public:
        virtual void keyDown(const SDL_Event&);
        virtual void keyUp(const SDL_Event&);
        static MovableSprite* getInstance(int xPos, int yPos, int width, int heigth, float speed);
        void setSpeed(float); //möjligt att protected funkar
        virtual void draw() const;
        virtual void tick();
        virtual ~MovableSprite();
    protected:
        MovableSprite(int xPos, int yPos, int width, int height, float speed);

        void setRight(bool);
        void setLeft(bool);
        void setUp(bool);
        void setDown(bool);
        bool isRight() const;
        bool isLeft() const;
        bool isUp() const;
        bool isDown() const;
        float getSpeed() const;


    private:
        float speed;
        bool right, left, up, down;
    };
}

#endif //GAME_MOVABLESPRITE_H
