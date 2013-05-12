#ifndef _ZF_SFML_COMPOSITEINSTRUCTION_H_
#define _ZF_SFML_COMPOSITEINSTRUCTION_H_
#include "AnimationInstruction.hpp"
#include "FadeInstruction.hpp"
#include "MoveInstruction.hpp"
#include <vector>
class AnimationObject;
class CompositeInstruction : public AnimationInstruction
{
    public:
        CompositeInstruction();
        ~CompositeInstruction();
        bool update(sf::RenderWindow* window, sf::Time delta,AnimationObject* object);
        bool isDone(AnimationObject* object);
        
        void addInstruction(FadeInstruction fi);
        CompositeInstruction* fade(int startingAlpha, int endingAlpha, float time); // allow for chaining


        void addInstruction(MoveInstruction mi);
        CompositeInstruction* move(sf::Vector2f source, sf::Vector2f target, float delta);
    private:
        std::vector<AnimationInstruction*> _instructions;
        bool _done;
};

#endif
