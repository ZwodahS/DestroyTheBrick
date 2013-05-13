#include "SimpleAnimator.hpp"
#include "AnimationObject.hpp"
#include "SpriteAnimationObject.hpp"
#include "TextAnimationObject.hpp"
SimpleAnimator::SimpleAnimator()
{
}

SimpleAnimator::~SimpleAnimator()
{
    for(int i = 0 ; i < objects.size() ; i++)
    {
        delete objects[i];
    }
}

void SimpleAnimator::draw(sf::RenderWindow* window, sf::Time delta)
{
    for(int i = 0 ; i < objects.size() ; i++)
    {
        objects[i]->draw(window,delta);
    }
}

void SimpleAnimator::update(sf::RenderWindow* window, sf::Time delta)
{
    for(int i = objects.size() - 1 ; i >= 0 ; i--)
    {
        if(objects[i]->update(window,delta))
        {
            delete objects[i];
            objects.erase(objects.begin() + i);
        }
    }
}

void SimpleAnimator::fade(sf::Sprite sprite, int targetAlpha, float time)
{
    SpriteAnimationObject* obj = new SpriteAnimationObject(sprite);
    FadeInstruction* fi = new FadeInstruction(sprite.getColor().a, targetAlpha, time);
    obj->setInstruction(fi);
    objects.push_back(obj);
}

void SimpleAnimator::moveTo(sf::Sprite sprite, sf::Vector2f target , float time)
{
    SpriteAnimationObject* obj = new SpriteAnimationObject(sprite);
    MoveToInstruction* mi = new MoveToInstruction(sprite.getPosition(),target,time);
    obj->setInstruction(mi);
    objects.push_back(obj);
}

void SimpleAnimator::move(sf::Sprite sprite, sf::Vector2f moveVec, float duration)
{
    SpriteAnimationObject* obj = new SpriteAnimationObject(sprite);
    MoveInstruction* mi = new MoveInstruction(moveVec, duration);
    obj->setInstruction(mi);
    objects.push_back(obj);
}


CompositeInstruction* SimpleAnimator::composite(bool ordered)
{
    return new CompositeInstruction(ordered);
}

void SimpleAnimator::composite(sf::Sprite sprite, CompositeInstruction* instruction)
{
    SpriteAnimationObject* obj = new SpriteAnimationObject(sprite);
    obj->setInstruction(instruction);
    objects.push_back(obj);
    
}

void SimpleAnimator::composite(sf::Text text, CompositeInstruction* instruction)
{
    TextAnimationObject* obj = new TextAnimationObject(text);
    obj->setInstruction(instruction);
    objects.push_back(obj);
}
