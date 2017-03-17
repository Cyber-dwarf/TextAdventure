#pragma once

#include <vector>
#include "FontCharacterSet.h"
#include "Renderer.h"
#include <algorithm>

class FontRenderer : public Renderer {
    private:
        FontCharacterSet *fcs;
public:
    FontRenderer(SDL_Window *w,SDL_Renderer *r, FontCharacterSet *fcs);

    
    void render(std::string toRender,int x,int y);
    
    inline FontCharacterSet* getFontCharacterSet(){return this->fcs;};
    inline void setFontCharacterSet(FontCharacterSet *f){this->fcs = f;}; 
    
};