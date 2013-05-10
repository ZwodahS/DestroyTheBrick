#ifndef _GAME_BOARDS_BRICK_H_
#define _GAME_BOARDS_BRICK_H_

#include "../../z_framework/zf_common/Grid.hpp"

#include <SFML/Graphics.hpp>

namespace brick
{
    enum BrickType
    {
        RED,
        GREEN,
        BLUE,
        YELLOW,
    };

}

class Board;
class Game;
class Brick
{
    public:
        Brick(Game* game,Board* board);
        Brick(Game* game,Board* board,brick::BrickType type);
        ~Brick();

        Grid _currentLocation;
        Grid _targetLocation;
        brick::BrickType getType();
        void setType(brick::BrickType type);
        sf::Vector2f getCurrentPosition();
        sf::Vector2f getTargetPosition();
        bool isMoving();
        bool isInPosition(); 
    
        void setLocation(int row, int col);
        void moveToLocation(int row , int col);
        void moveBy(int row, int col); 

        void update(sf::RenderWindow* window, sf::Time delta);
        void draw(sf::RenderWindow* window, sf::Time delta);

        bool tmp_moves; // a temp variable used when checking
    private:
        sf::Vector2f _position;
        
        sf::Vector2f _moveVector;
        Board* _board;
        Game* _game;
        brick::BrickType _type;
        sf::Sprite _brickSprite;
};

#endif
