#include "Renderer.h"

SDL_Texture *Renderer::loadTexture(std::string path) {
   
    SDL_Texture *tex = nullptr;
    
    SDL_Surface *surf = IMG_Load(path.c_str());
    
    tex = SDL_CreateTextureFromSurface(this->renderer,surf);
    
    SDL_FreeSurface(surf);
    
    return tex;
    
    
}
    
