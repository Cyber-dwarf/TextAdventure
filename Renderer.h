#pragma once

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Renderer {
private:
    
    int windowWidth;
    int windowHeight;
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    

protected:
    SDL_Texture *loadTexture(std::string path);
    
public:
    
    template <typename T>
    void render(T toRender,int x,int y);
    
    inline void setWindow(SDL_Window *w){this->window = w;};
    inline SDL_Window *getWindow(){return this->window;};
    
    inline void setRenderer(SDL_Renderer *ren){this->renderer = ren;};
    inline SDL_Renderer *getRenderer(){return this->renderer;};
    
    inline int getWindowHeight(){return this->windowHeight;};
    inline void setWindowHeight(int h){this->windowHeight = h;};
    
    inline int getWindowWidth(){return this->windowWidth;};
    inline void setWindowWidth(int w){this->windowWidth = w;};
    
    
};