#include "Brick.hpp"
#include "../consts.hpp"
#include "Board.hpp"
#include "../Game.hpp"
Brick::Brick(Game* game,Board* board, brick::BrickType type)
{
    this->_board = board;
    this->_currentLocation = Grid(0,0);
    this->_targetLocation = Grid(0,0);
    this->_position = sf::Vector2f(0,0);
    this->_game = game;
    this->_brickSprite = _game->_assets.bricks.brick.createSprite();
    this->setType(type);
}

Brick::~Brick()
{
}

sf::Vector2f Brick::getCurrentPosition()
{
    return _position;
}

sf::Vector2f Brick::getTargetPosition()
{
    return sf::Vector2f(_targetLocation.col * gameconsts::BRICK_SIZE , _targetLocation.row * gameconsts::BRICK_SIZE);
}

bool Brick::isMoving()
{
    getCurrentPosition() != getTargetPosition();
}

bool Brick::isInPosition()
{
    return _currentLocation == _targetLocation;
}

void Brick::setLocation(int row, int col)
{
    this->_currentLocation = Grid(row,col);
    this->_targetLocation = Grid(row,col);
    this->_position = getTargetPosition();
}

void Brick::moveToLocation(int row, int col)
{
    this->_targetLocation = Grid(row,col);
}

void Brick::update(sf::RenderWindow* window, sf::Time delta)
{
}

void Brick::draw(sf::RenderWindow* window, sf::Time delta)
{
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
