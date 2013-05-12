#ifndef _ZF_SFML_TEXTUREREGION_H_
#define _ZF_SFML_TEXTUREREGION_H_

#include <SFML/Graphics.hpp>
#include <iostream>
struct TextureRegion
{
    sf::Texture* texture;
    sf::IntRect srcClip;

    TextureRegion(sf::Texture* t, sf::IntRect srcClip)
    {
        this->texture = t;
        this->srcClip = srcClip;
    }

    TextureRegion()
    {
        this->texture = 0;
        this->srcClip = sf::IntRect(0,0,0,0);
    }
    
    sf::Sprite createSprite();
};
#endif
