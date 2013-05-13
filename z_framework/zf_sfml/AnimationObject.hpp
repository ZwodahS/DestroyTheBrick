#ifndef _ZF_SFML_ANIMATIONOBJECT_H_
#define _ZF_SFML_ANIMATIONOBJECT_H_

#include <SFML/Graphics.hpp>
class AnimationInstruction;
class AnimationObject
{
    public:
        AnimationObject();
        ~AnimationObject();
        
        // return if this object is done animating
        bool done();
        // return done().
        bool update(sf::RenderWindow* window, sf::Time delta);
        void setInstruction(AnimationInstruction* _instruction);
        virtual void draw(sf::RenderWindow* window, sf::Time delta) = 0;
        virtual void setAlpha(float alpha) = 0;
        virtual void setPosition(sf::Vector2f position) = 0;
        virtual void movePosition(sf::Vector2f move) = 0;
    private:
        AnimationInstruction* _instruction;
};
#endif
