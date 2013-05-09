#ifndef _GAME_SCREENS_SCREEN_H_
#define _GAME_SCREENS_SCREEN_H_

#include <SFML/Graphics.hpp>

class Game;
class Screen
{
    public:
        Screen(Game* game);
        ~Screen();
        
        virtual void draw(sf::RenderWindow* window, sf::Time delta);
        virtual void update(sf::RenderWindow* window, sf::Time delta);
    protected:
        
        Game* _game;
        

};
#endif
