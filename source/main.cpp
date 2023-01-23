#include <iostream>
#include "SDL.h"

using namespace std;

int main(int, char **) {
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Error";

    } else {
        if (window = SDL_CreateWindow("Antiquarian", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN)) {
            screenSurface = SDL_GetWindowSurface( window );
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x3F, 0xFF, 0x4F ) );
            SDL_UpdateWindowSurface( window );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
            
        } else {
            cout << "SDL Window Error";
        }
    }
    
    // Shutdown
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}