#include "CompositeInstruction.hpp"
#include "AnimationObject.hpp"
CompositeInstruction::CompositeInstruction()
{
    _instructions = std::vector<AnimationInstruction*>(0);
    _done = false;
}

CompositeInstruction::~CompositeInstruction()
{
    for(int i = 0 ; i < _instructions.size() ; i++)
    {
        delete _instructions[i]; 
    }
}

void CompositeInstruction::addInstruction(FadeInstruction fi)
{
    FadeInstruction* f = new FadeInstruction(fi);
    this->_instructions.push_back(f);
}

void CompositeInstruction::addInstruction(MoveInstruction mi)
{
    MoveInstruction* m = new MoveInstruction(mi);
    this->_instructions.push_back(m);
}

bool CompositeInstruction::update(sf::RenderWindow* window, sf::Time delta, AnimationObject* object)
{
    if(!_done)
    {
        _done = true;
        for(int i = 0 ; i < _instructions.size() ; i++)
        {
            if(!_instructions[i]->update(window,delta,object))
            {
                _done = false;
            }
        }
    }
    return _done;
}

bool CompositeInstruction::isDone(AnimationObject* object)
{
    return _done;
}

CompositeInstruction* CompositeInstruction::fade(int startingAlpha, int endingAlpha, float time)
{
    FadeInstruction* fi = new FadeInstruction(startingAlpha, endingAlpha, time);
    this->_instructions.push_back(fi);
    return this;
}

CompositeInstruction* CompositeInstruction::move(sf::Vector2f source, sf::Vector2f target, float delta)
{
    MoveInstruction* mi = new MoveInstruction(source,target,delta);
    this->_instructions.push_back(mi);
    return this;
}
