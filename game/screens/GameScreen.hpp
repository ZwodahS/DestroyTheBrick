#ifndef _GAME_SCREENS_GAMESCREEN_H_
#define _GAME_SCREENS_GAMESCREEN_H_
#include "Screen.hpp"
#include "../GameData.hpp"

#include "../../z_framework/zf_common/Grid.hpp"
#include "../../z_framework/zf_common/Direction.hpp"
#include <SFML/Graphics.hpp>

#include <vector>

class Board;
class GameScreen;
class LaunchArrow
{
    public:
        LaunchArrow();
        LaunchArrow(Game* game,GameScreen* screen,zf::Direction direction, int row, int col);
        Grid _location;
        zf::Direction _direction;

        void draw(sf::RenderWindow* window, sf::Time delta);
        void update(sf::RenderWindow* window, sf::Time delta);

        void setDirection(zf::Direction direction);
    private:
        GameScreen* _screen;
        Game* _game;
        sf::Sprite _arrowSprite;
};

class GameScreen : public Screen
{
    public:
        GameScreen(Game* game);
        ~GameScreen();
    
        virtual void draw(sf::RenderWindow* window, sf::Time delta);
        void drawHud(sf::RenderWindow* window, sf::Time delta);
        virtual void update(sf::RenderWindow* window, sf::Time delta);

        void launch(LaunchArrow* arrow);        

    protected:
        GameData _data;
        std::vector<sf::Sprite> _floorGrid;
        std::vector<LaunchArrow> _arrows;
        
        sf::Text* _next;
        sf::Sprite* _hammerSprite;
        sf::Text* _score;
        sf::Text* _scoreValue;
};

#endif
