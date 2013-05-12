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
        // if ordered is true , then the instruction is executed one after another.
        // if not ordered , the instruction is executed all at the same time.
        CompositeInstruction();
        CompositeInstruction(bool ordered);
        ~CompositeInstruction();
        bool update(sf::RenderWindow* window, sf::Time delta,AnimationObject* object);
        bool isDone(AnimationObject* object);
        
        CompositeInstruction* addInstruction(FadeInstruction fi);
        CompositeInstruction* fade(int startingAlpha, int endingAlpha, float time); // allow for chaining


        CompositeInstruction* addInstruction(MoveInstruction mi);
        CompositeInstruction* move(sf::Vector2f source, sf::Vector2f target, float delta);
    private:
        std::vector<AnimationInstruction*> _instructions;
        bool _ordered;
        bool _done;
};

#endif
