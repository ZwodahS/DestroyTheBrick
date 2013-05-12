#ifndef _ZF_FRAMEWORK_PROBABILITY_H_
#define _ZF_FRAMEWORK_PROBABILITY_H_


// the idea of the this probability class is to define a chance in maxRow to return true or false.
struct Probability
{
    int chance;
    int maxRoll;
    // This will assume max Roll to be 100.
    Probability();
    Probability(int chance);
    Probability(int chance, int max);
    
    bool roll();
};
#endif
