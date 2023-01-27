#include <iostream>
#include "SDL.h"

using namespace std;

// Display module
bool DISPLAY_init();
bool DISPLAY_deinit();

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;

// Main module
int main(int, char **) {

    DISPLAY_init();

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x3F, 0xFF, 0x4F));
    SDL_UpdateWindowSurface(window);

    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    
    // Shutdown
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

bool DISPLAY_init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Init Error";
        return false;
    }

    window = SDL_CreateWindow("Antiquarian", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    if (!window) {
        cout << "SDL Window Error";
        return false;
    }

    screenSurface = SDL_GetWindowSurface(window);
    return true;
}