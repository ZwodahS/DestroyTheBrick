#include "FadeInstruction.hpp"
#include "AnimationObject.hpp"
#include <iostream>
FadeInstruction::FadeInstruction(int startingAlpha, int endingAlpha, float time)
{
    this->_done = false;
    this->_currentAlpha = startingAlpha;
    this->_targetAlpha = endingAlpha;
    this->_changeAlpha = (endingAlpha - startingAlpha)/time;
}
FadeInstruction::FadeInstruction(const FadeInstruction &fi)
{
    this->_done = fi._done;
    this->_currentAlpha = fi._currentAlpha;
    this->_targetAlpha = fi._targetAlpha;
    this->_changeAlpha = fi._changeAlpha;
}
FadeInstruction::~FadeInstruction()
{
}
// fade assume that the target alpha is always less than current alpha.
bool FadeInstruction::update(sf::RenderWindow* window, sf::Time delta, AnimationObject* object)
{
    if(!_done)
    {
        _currentAlpha += _changeAlpha * delta.asSeconds();
        object->setAlpha(_currentAlpha);
        if(_currentAlpha <= _targetAlpha)
        {
            _done = true;
        }
    }
    return _done;
}

bool FadeInstruction::isDone(AnimationObject* object)
{
    return _done;
}
