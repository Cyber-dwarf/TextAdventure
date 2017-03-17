/* 
 * File:   main.cpp
 * Author: zero
 *
 * Created on February 5, 2014, 9:48 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include "FontCharacter.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"


#include "FontCharacterSet.h"
#include "FontRenderer.h"
#include "Renderer.h"

using namespace std;

const string LOREM = "Lexx is a science fantasy television series that follows "
"the adventures of a group of mismatched individuals aboard the organic space "
"craft Lexx. They travel through two universes and encounter planets including "
"a parody of the Earth.The series is a Canadian and German co-production, with "
"some additional funding from Britain's Channel 5. The Sci Fi Channel purchased"
" the series from Salter Street Films and began airing versions of Season 2 "
"episodes for United States' audience in January 2000.[1] Lexx was co-produced "
"by Salter Street Films, later absorbed by Alliance Atlantis. In Canada, Lexx "
"aired on the Alliance Atlantis-owned Showcase network.The series was primarily "
"filmed in Halifax (Nova Scotia, Canada) and Berlin (Germany), with additional "
"filming on location in Iceland, Bangkok (Thailand), and Namibia. Stan, Zev and "
"Kai accidentally steal the Lexx, the most powerful destructive weapon in the "
"two universes. After successfully fleeing from the Cluster, the main planet of "
"the League of the 20,000 Planets, they are looking for a new home. Kai needs "
"protoblood to live outside of his cryochamber. Looking for protoblood, the Lexx "
"returns to the Cluster to learn that a huge insect survived. This insect had "
"controlled The Divine Order and His Divine Shadow in order to eat all human "
"inhabitants of the 20,000 planets. The insect then begins a metamorphosis into "
"the Gigashadow. Gigashadow produces protoblood. With the help of Zev, Kai "
"manages to fill up his store of protoblood. Kai places the cluster lizard "
"Squish in the brain of the insect and thus is able to destroy it. The main "
"conflict of the second season is the fight against Mantrid, the former Bio-"
"Vizier of His Divine Shadow. The crew had inadvertently helped him transfer"
" his mind into a machine in the first episode of the season while accidentally "
"fusing it with a remnant of His Shadow. Mantrid's goal is to transform all "
"matter in the Light Universe into Mantrid Drones.In the meantime the crew "
"keeps getting into difficult situations and is usually rescued by Kai. At the "
"end of the season they destroy Mantrid. Unfortunately, the Light Universe is "
"also destroyed. The crew flees into the Dark Zone. The Lexx is running out of "
"food and must fly slowly to conserve energy. 790 computes that it might take "
"thousands of years until they reach an inhabited planet. The crew enters "
"cryostasis to survive the voyage. After 4,000 years in cryostasis, they "
"reach the twin planets Fire and Water. The entire third season takes place "
"on these two planets. The crew meets people they knew from the Light Universe, "
"but these survivors can not remember their past in the parallel universe, "
"though their personalities are still the same. Fire is ruled by the charismatic"
" Prince. Water doesn't seem to have a ruler. The inhabitants of both planets "
"live in isolated towns. On Water they live on islands in a huge ocean and on"
" Fire there are big towers divided by desert.Prince wants to win the crew over "
"to his side, especially Xev. The Prince tests their sense of morality through"
" various temptations. The crew is frequently separated, forcing them to act "
"individually. After jumping from the Lexx to the surface of Water, Kai has "
"trouble functioning normally without the other crew members. On Water, deep "
"beneath its surface, Kai encounters his soul essence which awaits rebirth. "
"Stanley dies and a trial is held over the destination of his soul. All his "
"bad decisions are weighted against his good deeds and he is sentenced to "
"eternal punishment on Fire. At the end of the season both planets Fire and "
"Water are destroyed, and Stan's soul is set free and is able to return into "
"his body, though he can not remember what happened to him on Fire. The souls "
"of all inhabitants of Fire and Water are also released, and travel to a planet "
"that looks like Earth. The Lexx travels to Earth looking for food. It is "
"located in the very center of the Dark Universe and the crew assumes that "
"it must be a very dangerous place. The crew again meet several people they "
"knew from the Light Universe, and from Fire and Water. Only Prince and Priest"
" are able to remember their lives on Fire (though presumably Priest can only "
"do this because Prince allows him to).Kai's soul is stuck because he is undead,"
" and he decides to die to release his soul. To do this, he must regain his "
"mortality. He plays chess with Prince to regain mortality and wins, but Kai "
"remains dead.The Earth is threatened by a being that resembles Lyekka. The crew "
"finds out that the fake \"Lyekka\" destroyed all human life on her way through "
"the Dark Zone. Kai decides to destroy the asteroid that is the source of the "
"entity. Prince keeps his promise and restores Kai's mortality. Minutes later, "
"Kai finally dies destroying the asteroid, saving all inhabitants of the Dark "
"Zone. 790 destroys the Earth using the senile and dying Lexx, Prince and Priest "
"and Bunny escape on a rocket filled with Catholic schoolgirls, and Xev and "
"Stan fly off together on the Lexx's offspring, \"Little Lexx\" to find a new home.";

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH  = 800;

int main(int argc, char** argv) {
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window* win = SDL_CreateWindow("Text Adventure",100,100,WINDOW_WIDTH,WINDOW_HEIGHT,
            SDL_WINDOW_SHOWN);
    
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | 
            SDL_RENDERER_PRESENTVSYNC);
    
    
    FontCharacterSet *fcs = new FontCharacterSet("fonts/test.fnt");
    
    FontRenderer *fr      = new FontRenderer(win,ren,fcs);
    fr->setWindowWidth(WINDOW_WIDTH);
    fr->setWindowHeight(WINDOW_HEIGHT);
    
    bool quit = false;
    SDL_Event e;
    
    while (!quit) {
        
        while(SDL_PollEvent( &e ) != 0 ) { //User requests quit if( e.type == SDL_QUIT ) { quit = true; } }
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                
                switch (e.key.keysym.sym) {
                    case SDLK_f:
                        
                        fr->render(LOREM,0,0);
                     
                        break;
                    
                }
            }
        }  
    }
    
    delete fcs;
    delete fr;
    
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    
    SDL_Quit();
    
    return 0;
}

