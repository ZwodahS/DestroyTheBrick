#ifndef _GAME_BOARDS_BOARDOBJECT_H_
#define _GAME_BOARDS_BOARDOBJECT_H_

#include "../../z_framework/zf_common/Grid.hpp"
#include <SFML/Graphics.hpp>
class Board;
class Game;
class BoardObject
{
    public:
        BoardObject(Game* game, Board* board);
        ~BoardObject();

        Grid _currentLocation;
        Grid _targetLocation;

        virtual sf::Vector2f getCurrentPosition();
        virtual sf::Vector2f getTargetPosition();
        virtual bool isMoving();
        virtual bool isInPosition(); 
    
        virtual void setLocation(int row, int col);
        virtual void moveToLocation(int row , int col);
        virtual void moveBy(int row, int col); 

        virtual void update(sf::RenderWindow* window, sf::Time delta);
        virtual void draw(sf::RenderWindow* window, sf::Time delta) = 0;

        bool tmp_moves; // a temp variable used when checking
    protected:
        sf::Vector2f _position;
        sf::Vector2f _moveVector;
        Board* _board;
        Game* _game;
};

#endif
