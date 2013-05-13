#include "MoveInstruction.hpp"
#include "AnimationObject.hpp"
MoveInstruction::MoveInstruction(sf::Vector2f moveVector, float moveSecs)
{
    this->_done = false;
    this->_moveVector = moveVector;
    this->_timeMax = moveSecs;
    this->_timeCurrent = 0;
}

MoveInstruction::MoveInstruction(const MoveInstruction &mi)
{
    this->_done = false;
    this->_moveVector = mi._moveVector;
    this->_timeMax = mi._timeMax;
    this->_timeCurrent = 0;
}

MoveInstruction::~MoveInstruction()
{
}

bool MoveInstruction::update(sf::RenderWindow* window, sf::Time delta, AnimationObject* object)
{
    if(!_done)
    {
        float moveTime = delta.asSeconds();
        _timeCurrent += moveTime;
        if(_timeCurrent > _timeMax)
        {
            moveTime -= (_timeCurrent - _timeMax);
            _done = true;
        }
        object->movePosition(moveTime * _moveVector);
    }
    return _done;
}

bool MoveInstruction::isDone(AnimationObject* object)
{
    return _done;
}
