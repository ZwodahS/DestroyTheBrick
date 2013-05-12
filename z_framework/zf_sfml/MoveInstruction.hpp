#ifndef _ZF_SFML_MOVEINSTRUCTION_H_
#define _ZF_SFML_MOVEINSTRUCTION_H_
#include "AnimationInstruction.hpp"
class MoveInstruction : public AnimationInstruction
{
    public:
        MoveInstruction(sf::Vector2f source, sf::Vector2f target, float delta);
        MoveInstruction(const MoveInstruction &mi);
        ~MoveInstruction();
        bool update(sf::RenderWindow* window, sf::Time delta, AnimationObject* object);
        bool isDone(AnimationObject* object);
    
    private:
        sf::Vector2f _position;
        sf::Vector2f _move;
        sf::Vector2f _target;
        bool _done;

        bool overShootDestination();
};
#endif
