#include "SpriteAnimationObject.hpp"
#include <iostream>
SpriteAnimationObject::SpriteAnimationObject(sf::Sprite sprite)
{
    this->sprite = sprite;
}

SpriteAnimationObject::~SpriteAnimationObject()
{
}

void SpriteAnimationObject::setAlpha(float alpha)
{
    sf::Color color = this->sprite.getColor();
    color.a = alpha;
    this->sprite.setColor(color);
}

void SpriteAnimationObject::setPosition(sf::Vector2f position)
{
    this->sprite.setPosition(position);
}
void SpriteAnimationObject::draw(sf::RenderWindow* window, sf::Time delta)
{
    window->draw(sprite);
}
