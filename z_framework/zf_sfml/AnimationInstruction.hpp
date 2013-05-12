#ifndef _ZF_SFML_ANIMATIONINSTRUCTION_H_
#define _ZF_SFML_ANIMATIONINSTRUCTION_H_

#include <SFML/Graphics.hpp>
class AnimationObject;
class AnimationInstruction
{
    public:
        AnimationInstruction();
        ~AnimationInstruction();
        virtual bool update(sf::RenderWindow* window, sf::Time delta,AnimationObject* object) = 0;
        virtual bool isDone(AnimationObject* object) = 0;
};
#endif

