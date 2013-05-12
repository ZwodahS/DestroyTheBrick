#ifndef _ZF_SFML_FADEINSTRUCTION_H_
#define _ZF_SFML_FADEINSTRUCTION_H_
#include "AnimationInstruction.hpp"
class FadeInstruction : public AnimationInstruction
{
    public:
        FadeInstruction(int startingAlpha, int endingAlpha , float time);
        FadeInstruction(const FadeInstruction &fi);
        ~FadeInstruction();
        bool update(sf::RenderWindow* window, sf::Time delta, AnimationObject* object);
        bool isDone(AnimationObject* object);
        
        float _targetAlpha;
        float _changeAlpha; // per seconds
        float _currentAlpha;
        bool _done;
};       
#endif
