#include "AnimationObject.hpp"
#include "AnimationInstruction.hpp"
AnimationObject::AnimationObject()
{
    this->_instruction = 0;
}

AnimationObject::~AnimationObject()
{
    if(_instruction != 0)
    {
        delete _instruction;
    }
}

bool AnimationObject::update(sf::RenderWindow* window, sf::Time delta)
{
    if(done())
    {
        return true;
    }
    
    return _instruction->update(window,delta,this);
}

void AnimationObject::setInstruction(AnimationInstruction* instruction)
{
    if(_instruction != 0)
    {
        delete _instruction;
    }
    this->_instruction = instruction;
}

bool AnimationObject::done()
{
    return _instruction == 0 ? true : _instruction->isDone(this);
}
