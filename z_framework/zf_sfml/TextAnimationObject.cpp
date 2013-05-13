#include "TextAnimationObject.hpp"

TextAnimationObject::TextAnimationObject(sf::Text text)
{
    this->_text = text;
}
TextAnimationObject::~TextAnimationObject()
{
}

void TextAnimationObject::draw(sf::RenderWindow* window, sf::Time delta)
{
    window->draw(this->_text);
}

void TextAnimationObject::setAlpha(float alpha)
{
    sf::Color color = this->_text.getColor();
    color.a = alpha;
    this->_text.setColor(color);
}

void TextAnimationObject::setPosition(sf::Vector2f position)
{
    this->_text.setPosition(position);
}

void TextAnimationObject::movePosition(sf::Vector2f move)
{
    sf::Vector2f position = this->_text.getPosition();
    this->_text.setPosition(position+move);
}
