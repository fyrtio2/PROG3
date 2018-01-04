//
// Created by Oscar Törnquist on 2017-12-20.
//

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include "System.h"




namespace game {
    class Sprite {
    public:
        virtual ~Sprite();


        virtual void keyDown(const SDL_Event&);
        virtual void keyUp(const SDL_Event&);
        virtual void draw() const = 0;
        virtual void tick();
        virtual bool checkCollision(Sprite * s);


        const SDL_Rect &getRect() const {return destRect;}


    protected:

        void setRectX(float x);
        void setRectY(float y);
        Sprite(int xPos, int yPos, int width, int heigth);

    private:
        SDL_Rect destRect;
        Sprite(const Sprite&) = delete;
        const Sprite& operator = (const Sprite&) = delete;


    };
}

#endif //GAME_SPRITE_H
