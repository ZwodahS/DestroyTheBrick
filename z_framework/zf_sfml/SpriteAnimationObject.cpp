#include "SpriteAnimationObject.hpp"
#include <iostream>
SpriteAnimationObject::SpriteAnimationObject(sf::Sprite sprite)
{
    this->_sprite = sprite;
}

SpriteAnimationObject::~SpriteAnimationObject()
{
}

void SpriteAnimationObject::setAlpha(float alpha)
{
    sf::Color color = this->_sprite.getColor();
    color.a = alpha;
    this->_sprite.setColor(color);
}

void SpriteAnimationObject::setPosition(sf::Vector2f position)
{
    this->_sprite.setPosition(position);
}

void SpriteAnimationObject::movePosition(sf::Vector2f moves)
{
    sf::Vector2f position = this->_sprite.getPosition();
    this->_sprite.setPosition(position + moves);
}

void SpriteAnimationObject::draw(sf::RenderWindow* window, sf::Time delta)
{
    window->draw(this->_sprite);
}

