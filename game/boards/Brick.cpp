#include "Brick.hpp"
#include "Board.hpp"
#include "../consts.hpp"
#include "../Game.hpp"



Brick::Brick(Game* game,Board* board)
    :BoardObject(game, board)
{
    this->_brickSprite = _game->_assets.bricks.brick.createSprite();
    int r = rand() % 4;
    if(r == 0)
    {
        setType(brick::RED);
    }    
    else if(r == 1)
    {
        setType(brick::GREEN);
    }
    else if(r == 2)
    {
        setType(brick::BLUE);
    }
    else 
    {
        setType(brick::YELLOW);
    }
}

Brick::Brick(Game* game,Board* board, brick::BrickType type)
    :BoardObject(game,board)
{
    this->_brickSprite = _game->_assets.bricks.brick.createSprite();
    this->setType(type);
}

Brick::~Brick()
{
}


void Brick::draw(sf::RenderWindow* window, sf::Time delta)
{
    _brickSprite.setPosition(_position);
    window->draw(_brickSprite);
}

brick::BrickType Brick::getType()
{
    return _type;
}

void Brick::setType(brick::BrickType type)
{
    this->_type = type;
    switch(type)
    {
        case brick::RED:
            this->_brickSprite.setColor(sf::Color(255,0,0));
            break;
        case brick::GREEN:
            this->_brickSprite.setColor(sf::Color(0,255,0));
            break;
        case brick::BLUE:
            this->_brickSprite.setColor(sf::Color(0,0,255));
            break;
        case brick::YELLOW:
            this->_brickSprite.setColor(sf::Color(0,255,255));
            break;
        default:
            break;

    }
}

