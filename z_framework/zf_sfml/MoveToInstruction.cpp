#include "MoveToInstruction.hpp"
#include "AnimationObject.hpp"
MoveToInstruction::MoveToInstruction(sf::Vector2f source, sf::Vector2f target, float delta)
{
    this->_done = false;
    this->_position = source;
    this->_target = target;
    this->_move = (_target - _position) / delta;
}
MoveToInstruction::MoveToInstruction(const MoveToInstruction &mi)
{
    this->_done = false;
    this->_position = mi._position;
    this->_move = mi._move;
    this->_target = mi._target;
}

MoveToInstruction::~MoveToInstruction()
{
}

bool MoveToInstruction::update(sf::RenderWindow* window, sf::Time delta, AnimationObject* object)
{
    if(!_done)
    {
        this->_position += _move * delta.asSeconds();
        if(overShootDestination())
        {
            _done = true;
        }
        object->setPosition(_position);
    }
    return _done;
}

bool MoveToInstruction::isDone(AnimationObject* object)
{
    return _done;
}

bool MoveToInstruction::overShootDestination()
{
    bool x_done = false;
    bool y_done = false;
    if(_move.x > 0)
    {
        if(_position.x > _target.x)
        {
            x_done = true;
            _position.x = _target.x;
        }
    }
    else if(_move.x < 0)
    {
        if(_position.x < _target.x)
        {
            x_done = true;
            _position.x = _target.x;
        }
    }
    else
    {
        x_done =true;
    }


    if(_move.y > 0)
    {
        if(_position.y > _target.y)
        {
            y_done = true;
            _position.y = _target.y;
        }
    }
    else if(_move.y < 0)
    {
        if(_position.y < _target.y)
        {
            y_done = true;
            _position.y = _target.y;
        }
    }
    else
    {
        x_done =true;
    }
    return x_done && y_done;
}
