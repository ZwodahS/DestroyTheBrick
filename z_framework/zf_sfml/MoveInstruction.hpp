#ifndef _ZF_SFML_MOVEINSTRUCTION_H_
#define _ZF_SFML_MOVEINSTRUCTION_H_
#include "AnimationInstruction.hpp"
class MoveInstruction : public AnimationInstruction
{
    public:
        MoveInstruction(sf::Vector2f moveVector, float moveSecs);
        MoveInstruction(const MoveInstruction &mi);
        ~MoveInstruction();

        bool update(sf::RenderWindow* window, sf::Time delta, AnimationObject* object);
        bool isDone(AnimationObject* object);

    private:
        sf::Vector2f _moveVector;
        float _timeMax;
        float _timeCurrent;

        bool _done;

};
#endif
