#include "engine.h"

Engine::Engine() {
    version = "1.0";
    isRunning = true;
    pWindow = nullptr;
    pRenderer = nullptr;
}

bool Engine::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    pWindow = SDL_CreateWindow(
            getTitle(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            640, 480,
            SDL_WINDOW_SHOWN);

    if (pWindow != nullptr) {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    } else { return false; }

    return OnLoad();
}

int Engine::OnExecute() {
    SDL_Event event;

    if (!OnInit()) { return -1; }

    while (isRunning) {
        while (SDL_PollEvent(&event) != 0) {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }
    OnExit();
    return 0;
}

void Engine::OnEvent(SDL_Event *event) {
    if (event->type == SDL_QUIT) {
        isRunning = false;
    }
}

void Engine::OnLoop() {

}

void Engine::OnRender() {
//    SDL_RenderGeometry(pRenderer, texCoin)

    SDL_RenderPresent(pRenderer);
}

void Engine::OnExit() {
    SDL_DestroyWindow(pWindow);
    pWindow = nullptr;
    SDL_Quit();
}

bool Engine::OnLoad() {
    texCoin = loadTexture("assets/coin.png");

    return true;
}

