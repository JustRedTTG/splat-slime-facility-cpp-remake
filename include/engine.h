#ifndef SPLAT_ENGINE_H
#define SPLAT_ENGINE_H

#include "std.h"
#include <SDL2/SDL.h>

class Engine {
public:
    Engine();

    int OnExecute();

    bool OnInit();

    void OnEvent(SDL_Event *event);

    void OnLoop();

    void OnRender();

    void OnExit();

private:
    string version;
    bool isRunning;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

    const char *getTitle() {
        string title = "Splat Engine" + version;
        return title.c_str();
    }
};

#endif //SPLAT_ENGINE_H
