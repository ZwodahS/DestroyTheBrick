#ifndef _GAME_SCREENS_GAMESCREEN_H_
#define _GAME_SCREENS_GAMESCREEN_H_
#include "Screen.hpp"
#include <SFML/Graphics.hpp>

class Board;
class GameScreen : public Screen
{
    public:
        GameScreen(Game* game);
        ~GameScreen();
    
        virtual void draw(sf::RenderWindow* window, sf::Time delta);
        virtual void update(sf::RenderWindow* window, sf::Time delta);


    protected:
        Board* _board;
};

#endif
