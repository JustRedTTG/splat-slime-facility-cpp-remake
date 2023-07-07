#ifndef SPLAT_ENGINE_H
#define SPLAT_ENGINE_H

#include "std.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Engine {
public:
    Engine();

    int OnExecute();

private:
    string version;
    bool isRunning;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

    // Textures
    SDL_Texture *texCoin = nullptr;

    const char *getTitle() {
        string title = "Splat Engine" + version;
        return title.c_str();
    }

    SDL_Texture *loadTexture(string file) {
        SDL_Surface *surface = IMG_Load(file.c_str());
        return SDL_CreateTextureFromSurface(pRenderer, surface);
    }

    bool OnInit();

    void OnEvent(SDL_Event *event);

    void OnLoop();

    void OnRender();

    void OnExit();

    bool OnLoad();

};

#endif //SPLAT_ENGINE_H
