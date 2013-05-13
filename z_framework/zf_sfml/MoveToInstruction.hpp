#ifndef _ZF_SFML_MOVETOINSTRUCTION_H_
#define _ZF_SFML_MOVETOINSTRUCTION_H_
#include "AnimationInstruction.hpp"
class MoveToInstruction : public AnimationInstruction
{
    public:
        MoveToInstruction(sf::Vector2f source, sf::Vector2f target, float delta);
        MoveToInstruction(const MoveToInstruction &mi);
        ~MoveToInstruction();
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
