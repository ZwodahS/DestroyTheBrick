#ifndef _ZF_SFML_TEXTANIMATION_H_
#define _ZF_SFML_TEXTANIMATION_H_
#include "AnimationObject.hpp"

#include <SFML/Graphics.hpp>
class TextAnimationObject : public AnimationObject
{
    public:
        TextAnimationObject(sf::Text text);
        ~TextAnimationObject();
        sf::Text _text;
        void draw(sf::RenderWindow* window, sf::Time delta);
        void setAlpha(float alpha);
        void setPosition(sf::Vector2f position);
        void movePosition(sf::Vector2f move);
};
#endif
