//
// Created by Oscar Törnquist on 2017-12-20.
//

#include "System.h"


namespace game {

    System::System() {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            printf("SDL_Init failed %s\n", SDL_GetError());
        }

        win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        ren = SDL_CreateRenderer(win, -1, 0);

    }

    System::~System() {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
    }

    int System::getHeight() const {
        return HEIGHT;
    }

    int System::getWidth() const {
        return WIDTH;
    }

    SDL_Renderer *System::getRen() const {
        return ren;
    }

    System sys;


}