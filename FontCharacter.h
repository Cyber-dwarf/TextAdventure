/* 
 * File:   FontGlyph.h
 * Author: zero
 *
 * Created on February 5, 2014, 11:46 PM
 */

#pragma once

class FontCharacter {
    private:
        int id;
        int x;
        int y;
        int width;
        int height;
        int xoffset;
        int yoffset;
        int xadvance;
        int page;
        int channel;
    public:
        inline int getID() {return this->id;};
        inline int getX() {return this->x;};
        inline int getY() {return this->y;};
        inline int getWidth() {return this->width;};
        inline int getHeight() {return this->height;};
        inline int getXOffset() {return this->xoffset;};
        inline int getYOffset() {return this->yoffset;};
        inline int getXAdvance() {return this->xadvance;};
        inline int getPage() {return this->page;};
        inline int getChannel() {return this->channel;};
        
        inline void setID(int id) {this->id = id;};
        inline void setX(int x) { this->x = x;};
        inline void setY(int y) { this->y = y;};
        inline void setWidth(int width) { this->width = width;};
        inline void setHeight(int height) { this->height = height;};
        inline void setXOffset(int xOffset) { this->xoffset = xOffset;};
        inline void setYOffset(int yOffset) { this->yoffset = yOffset;};
        inline void setXAdvance(int xAdvance) { this->xadvance = xAdvance;};
        inline void setPage(int page) { this->page = page;};
        inline void setChannel(int channel) { this->channel = channel;}; 
};
