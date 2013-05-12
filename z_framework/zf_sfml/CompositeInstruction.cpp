#include "CompositeInstruction.hpp"
#include "AnimationObject.hpp"
CompositeInstruction::CompositeInstruction()
{
    this->_instructions = std::vector<AnimationInstruction*>(0);
    this->_done = false;
    this->_ordered = false;
}
CompositeInstruction::CompositeInstruction(bool ordered)
{
    this->_instructions = std::vector<AnimationInstruction*>(0);
    this->_done = false;
    this->_ordered = ordered;
}

CompositeInstruction::~CompositeInstruction()
{
    for(int i = 0 ; i < _instructions.size() ; i++)
    {
        delete _instructions[i]; 
    }
}

CompositeInstruction* CompositeInstruction::addInstruction(FadeInstruction fi)
{
    FadeInstruction* f = new FadeInstruction(fi);
    this->_instructions.push_back(f);
    return this;
}

CompositeInstruction* CompositeInstruction::addInstruction(MoveInstruction mi)
{
    MoveInstruction* m = new MoveInstruction(mi);
    this->_instructions.push_back(m);
    return this;
}

bool CompositeInstruction::update(sf::RenderWindow* window, sf::Time delta, AnimationObject* object)
{
    if(!_done)
    {
        if(!_ordered)
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
        else
        {
            _done = true;
            for(int i = 0 ; i < _instructions.size() ; i++)
            {
                if(!_instructions[i]->isDone(object))
                {
                    if(!_instructions[i]->update(window,delta,object) || i != _instructions.size() - 1)
                    {
                        _done = false;
                        break;
                    }
                }
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
