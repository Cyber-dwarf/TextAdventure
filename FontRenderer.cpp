#include "FontRenderer.h"

FontRenderer::FontRenderer(SDL_Window *w,SDL_Renderer *r, FontCharacterSet *fcs) {
    this->setRenderer(r);
    this->setWindow(w);
    
    this->setFontCharacterSet(fcs);
    
    SDL_Texture *tex = this->loadTexture("fonts/test_0.tga");
    
   
    this->getFontCharacterSet()->setFontTexture(tex);
    
    
    
}


void FontRenderer::render(std::string str,int x,int y) {
    
    int lineHeight = this->getFontCharacterSet()->getLineHeight();
    
    struct cursor {
        int x;
        int y;
    };
    
    cursor c;
    c.x = x;
    c.y = y;
    
    std::vector<int> listOfSpaces;
    // Collect a list of the indices of every space in the text to render,
    // as to not word wrap in the middle of the word
    int i = 0;
    for (auto character : str) {
        if (character == ' ') {
            listOfSpaces.push_back(i);
        }
        ++i;
    }
    
    SDL_RenderClear(this->getRenderer());
    
    SDL_Texture *fontTexture = this->getFontCharacterSet()->getfontTexture();
    
    std::unordered_map<char,FontCharacter*> dict = this->getFontCharacterSet()->
    getCharToFontCharacterDictionary();
    
    int j = 0;
    for (auto character : str) {
        
        if (dict[character] != NULL) {
            FontCharacter* fg = dict[character];
            SDL_Rect source;
            SDL_Rect destination;
    
            source.x = fg->getX();
            source.y = fg->getY();
            source.w = fg->getWidth();
            source.h = fg->getHeight();
            
            destination.x = c.x + fg->getXOffset();
            destination.y = c.y + fg->getYOffset();
                    
            destination.w = fg->getWidth();
            destination.h = fg->getHeight();
            
            SDL_RenderCopy(this->getRenderer(),fontTexture,&source,&destination);
            
            c.x += fg->getXAdvance();
            
            
            if (std::find(listOfSpaces.begin(),listOfSpaces.end(), j) != listOfSpaces.end()) {
               
                auto firstSpacePointer = std::find(listOfSpaces.begin(),listOfSpaces.end(), j);
                
                // If we've gone past the container, that means we're at the
                // end of the text
                if (listOfSpaces.end() >= (firstSpacePointer+1)) {
                    int nextSpace = *(firstSpacePointer+1);

                    int spaceToTraverse = ((nextSpace - *firstSpacePointer)-1) * 8;

                    if (c.x + spaceToTraverse > this->getWindowWidth()) {
                        c.y += lineHeight;
                        c.x = x;
                    }
                }
                
            }
            
           
           
        } 
         j++;
    }
    
    SDL_RenderPresent(this->getRenderer());
    
}
