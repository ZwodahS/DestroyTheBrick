#ifndef _ZF_SFML_SPRITEANIMATIONOBJECT_H_
#define _ZF_SFML_SPRITEANIMATIONOBJECT_H_

#include "AnimationObject.hpp"

#include <SFML/Graphics.hpp>
class SpriteAnimationObject : public AnimationObject
{
    public:
        SpriteAnimationObject(sf::Sprite sprite);
        ~SpriteAnimationObject();
        sf::Sprite _sprite;
        void setAlpha(float alpha);
        void setPosition(sf::Vector2f position);
        void movePosition(sf::Vector2f position);
        void draw(sf::RenderWindow* window, sf::Time delta);

};

#endif
