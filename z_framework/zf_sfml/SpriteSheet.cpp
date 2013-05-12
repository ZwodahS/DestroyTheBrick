#include "SpriteSheet.hpp"
#include <iostream>
SpriteSheet::SpriteSheet()
{
    managed = false;
    currRow = 0;
    currCol = 0;
    maxrow = 0;
    maxcol = 0;
}

SpriteSheet::SpriteSheet(sf::IntRect spriteSize, int row, int col)
{
    this->spriteSize = spriteSize;
    this->size = sf::IntRect(0,0,spriteSize.width*col,spriteSize.height*row);
    this->texture.create(size.width,size.height);
    currRow = 0;
    currCol = 0;
    maxrow = row;
    maxcol = col;
    bool managed = true;
}

TextureRegion SpriteSheet::createRegion(sf::Image image)
{
    sf::Vector2u imgSize = image.getSize();
    if(imgSize.x != this->spriteSize.width || imgSize.y != this->spriteSize.height)
    {
        return TextureRegion(); 
    }
    texture.update(image,currCol*spriteSize.width, currRow*spriteSize.height);
    TextureRegion returnRegion = TextureRegion(&texture,sf::IntRect(currCol*spriteSize.width,currRow*spriteSize.height,spriteSize.width,spriteSize.height));
    currCol++;
    if(currCol >= maxcol)
    {
        currCol = 0;
        currRow++;
        if(currRow >= maxrow)
        {
            currRow = 0; //just wrap it back. graphics error is better than runtime.
        }
    }
    return returnRegion;
}
