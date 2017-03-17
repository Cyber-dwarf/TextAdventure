#pragma once
#include <unordered_map>
#include "pugixml-1.2/src/pugixml.hpp"
#include <string>
#include "FontCharacter.h"
#include "SDL2/SDL.h"

class FontCharacterSet {

private:
        int lineHeight;
        int base;
        std::unordered_map<char,FontCharacter*> charToFontCharacter;
        
        SDL_Texture *fontTexture;
        
public:
   FontCharacterSet(std::string fontFileLocation);
   ~FontCharacterSet();
    
   inline void setLineHeight(int lh) {this->lineHeight = lh;};
   inline void setBase(int b) {this->base = b;};
   
   inline int getLineHeight() {return this->lineHeight;};
   inline int getBase(){return this->base;};
   
   inline std::unordered_map<char,FontCharacter*> getCharToFontCharacterDictionary(){return this->charToFontCharacter;};
   
   inline SDL_Texture *getfontTexture(){return this->fontTexture;};
   void setFontTexture(SDL_Texture *tex);
    
};