#include "FontCharacterSet.h"


FontCharacterSet::FontCharacterSet(std::string fontFileLocation) {
    
    
    pugi::xml_document fontFile;
    
    fontFile.load_file(fontFileLocation.c_str());
    
    for (auto node = fontFile.first_child().first_child();node != NULL; node = node.next_sibling()) {
        
        std::string nodeName = node.name();
    
        if (nodeName == "info") {
            // pass
        } else if ( nodeName == "common") {
            for (auto attr = node.first_attribute();
                               attr != NULL; attr = attr.next_attribute()) {
                std::string attribName = attr.name();
                
                if (attribName == "lineHeight") {
                    this->setLineHeight(atoi(attr.value()));
                } else if (attribName == "base") {
                    this->setBase(atoi(attr.value()));
                }
            }
            
            
        } else if (nodeName == "pages") {
            // pass
        } else {
            
            // iterate through char nodes
            for(auto charNode = node.first_child();charNode != NULL;
                    charNode = charNode.next_sibling()) {
                
                FontCharacter *fontCharacter = new FontCharacter();
                
                // iterate through char node attributes
                for (auto attr = charNode.first_attribute();
                               attr != NULL; attr = attr.next_attribute()) {
                    
                    std::string attrName = attr.name();
                    
                    if (attrName == "id") {
                        fontCharacter->setID(atoi(attr.value()));
                    } 
                    else if (attrName == "x") {
                        fontCharacter->setX(atoi(attr.value()));
                    } else if (attrName == "y") {
                         fontCharacter->setY(atoi(attr.value()));
                    } else if (attrName == "width") {
                         fontCharacter->setWidth(atoi(attr.value()));
                    } else if (attrName == "height") {
                         fontCharacter->setHeight(atoi(attr.value()));
                    } else if (attrName == "xoffset") {
                         fontCharacter->setXOffset(atoi(attr.value()));
                    } else if (attrName == "yoffset") {
                         fontCharacter->setYOffset(atoi(attr.value()));
                    } else if (attrName == "xadvance") {
                         fontCharacter->setXAdvance(atoi(attr.value()));
                    } else if (attrName == "page") {
                         fontCharacter->setPage(atoi(attr.value()));
                    } else {
                         fontCharacter->setChannel(atoi(attr.value()));
                    }  
                }
                
                this->charToFontCharacter[(char)fontCharacter->getID()] = fontCharacter;
            }     
        }   
    }
    
}

FontCharacterSet::~FontCharacterSet() {
    for (auto i : this->charToFontCharacter) {
        delete i.second;
    }

    SDL_DestroyTexture(this->fontTexture);
}

void FontCharacterSet::setFontTexture(SDL_Texture *tex) {
     this->fontTexture = tex;
}