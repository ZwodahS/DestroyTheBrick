#ifndef _ZF_SFML_SIMPLEANIMATOR_H_
#define _ZF_SFML_SIMPLEANIMATOR_H_
#include "FadeInstruction.hpp"
#include "MoveToInstruction.hpp"
#include "CompositeInstruction.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
// use this class to do simple animations for particles and entity that does not have collision 
class AnimationObject;
class SimpleAnimator
{
    // DO NOT reuse ANY instruction.
    public:
        SimpleAnimator();
        ~SimpleAnimator();
    
        void update(sf::RenderWindow* window, sf::Time delta);
        void draw(sf::RenderWindow* window, sf::Time delta);

        void fade(sf::Sprite sprite,int targetAlpha,float time);
        void moveTo(sf::Sprite sprite,sf::Vector2f target, float time);
        void move(sf::Sprite sprite, sf::Vector2f moveVec, float duration);
        // easy to construct a one-liner
        // sa.composite(sprite, sa.composite()->move(...)->fade(...));
        CompositeInstruction* composite(bool ordered = false); // use this to construct the instructionn for the method below.
        void composite(sf::Sprite sprite, CompositeInstruction* instruction);
        void composite(sf::Text text, CompositeInstruction* instruction);
        
    private:
        std::vector<AnimationObject*> objects;

};
#endif
