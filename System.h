//
// Created by Oscar Törnquist on 2017-12-20.
//

#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H



#include <SDL.h>
#include <iostream>



namespace game {
    class System {

    public:
        System();

        ~System();

        SDL_Renderer* getRen() const;
        int getWidth() const;
        int getHeight() const;
    private:

        static const int WIDTH = 1366;
        static const int HEIGHT = 768;
        SDL_Window *win;
        SDL_Renderer *ren;
    };

    extern System sys;
}

#endif //GAME_SYSTEM_H
