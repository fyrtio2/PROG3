//
// Created by Oscar Törnquist on 2017-12-20.
//

#include "GameEngine.h"
#define FPS 60

namespace game {

    GameEngine::GameEngine() {

    }

    GameEngine::~GameEngine() {
        for (Sprite* s: sprites) {
            delete s;
        }
    }

    void GameEngine::add(Sprite * s) {
        sprites.push_back(s);
    }

    void GameEngine::run() {
        bool quit = false;

        const int tickInterval = 1000 / FPS;

        while (!quit) {
            Uint32 nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event event;

            while(SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        for (Sprite* s: sprites) {
                            s->keyDown(event);
                        }
                        break;
                    case SDL_KEYUP:
                        for (Sprite* s: sprites) {
                            s->keyUp(event);
                        }
                }
            }

            int delay = nextTick - SDL_GetTicks();
            if (delay > 0) {
                SDL_Delay(delay);
            }


            ticker();
            collisionCheck();
            draw();
        }

    }



    void GameEngine::ticker() {
        for (Sprite* s: sprites) {
            s->tick();
        }
    }

    void GameEngine::draw() {
        SDL_RenderClear(sys.getRen());
        for (Sprite* s: sprites) {
            s->draw();
        }
        SDL_RenderPresent(sys.getRen());
    }

    void GameEngine::collisionCheck() {
        for (Sprite* s: sprites) {
            for (Sprite *s1: sprites) {

                if (s->checkCollision(s1)){
                    sprites.erase(std::remove(sprites.begin(), sprites.end(), s1));
                    delete s1;
                    break;
                }

            }
        }
    }


}