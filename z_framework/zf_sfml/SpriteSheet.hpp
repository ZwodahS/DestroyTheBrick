#ifndef _ZF_SFML_SPRITESHEET_H_
#define _ZF_SFML_SPRITESHEET_H_
#include "TextureRegion.hpp"
#include <SFML/Graphics.hpp>
struct SpriteSheet
{
    bool managed; //if managed, then we assumed that all sprite on this sheet is of the same size,
    
    int currRow;
    int currCol;

    int maxrow;
    int maxcol;

    sf::Texture texture;
    sf::IntRect size; //size of this spritesheet.
    sf::IntRect spriteSize;
    SpriteSheet();    
    SpriteSheet(sf::IntRect spriteSize,int row, int col);
    
    TextureRegion createRegion(sf::Image image);
    
};


#endif
