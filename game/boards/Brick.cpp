#include "Brick.hpp"
#include "../consts.hpp"
#include "Board.hpp"
#include "../Game.hpp"

#define MOVESPEED 100


Brick::Brick(Game* game,Board* board)
{
    this->_board = board;
    this->_currentLocation = Grid(0,0);
    this->_targetLocation = Grid(0,0);
    this->_position = sf::Vector2f(0,0);
    this->_game = game;
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
    return _moveVector != sf::Vector2f(0,0);
}

bool Brick::isInPosition()
{
    return _position == getTargetPosition();
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
    
    if(_currentLocation.row < row)
    {
        this->_moveVector.y = 1;
    }
    else if(_currentLocation.row > row)
    {
        this->_moveVector.y = -1;
    }
    else
    {
        this->_moveVector.y = 0;
    }
    if(_currentLocation.col < col)
    {
        this->_moveVector.x = 1;
    }
    else if(_currentLocation.col > col)
    {
        this->_moveVector.x = -1;
    }
    else
    {
        this->_moveVector.x = 0;
    }
}

void Brick::moveBy(int row, int col)
{
    this->moveToLocation(_currentLocation.row + row , _currentLocation.col + col);
}

void Brick::update(sf::RenderWindow* window, sf::Time delta)
{
    if(!isMoving())
    {
        return;
    }
    float diffx = _moveVector.x * delta.asSeconds() * MOVESPEED;
    float diffy = _moveVector.y * delta.asSeconds() * MOVESPEED;
    if(isMoving())
    {
        _position += sf::Vector2f(diffx,diffy);
    }
    // check for over flow
    sf::Vector2f targetPosition = getTargetPosition();
    if(_moveVector.x > 0)
    {
        if(_position.x > targetPosition.x)
        {
            _position.x = targetPosition.x;
        }
    }
    else if (_moveVector.x < 0)
    {
        if(_position.x < targetPosition.x)
        {
            _position.x = targetPosition.x;
        }
    }

    if(_moveVector.y > 0)
    {
        if(_position.y > targetPosition.y)
        {
            _position.y = targetPosition.y;
        }
    }
    else if(_moveVector.y < 0 )
    {
        if(_position.y < targetPosition.y)
        {
            _position.y = targetPosition.y;
        }
    }
    
    if(isInPosition())
    {
        _moveVector = sf::Vector2f(0,0);    
    }
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

