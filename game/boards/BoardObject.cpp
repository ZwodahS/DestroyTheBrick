#include "BoardObject.hpp"
#include "Board.hpp"
#include "../consts.hpp"
#include "../Game.hpp"

#define MOVESPEED 175
BoardObject::BoardObject(Game* game, Board* board)
{
    this->_board = board;
    this->_game = game;
    this->_currentLocation = Grid(0,0);
    this->_targetLocation = Grid(0,0);
    this->_position = sf::Vector2f(0,0);
}

BoardObject::~BoardObject()
{
}

sf::Vector2f BoardObject::getCurrentPosition()
{
    return _position;
}

sf::Vector2f BoardObject::getTargetPosition()
{
    return sf::Vector2f(_targetLocation.col * gameconsts::BRICK_SIZE , _targetLocation.row * gameconsts::BRICK_SIZE);
}

bool BoardObject::isMoving()
{
    return _moveVector != sf::Vector2f(0,0);
}

bool BoardObject::isInPosition()
{
    return _position == getTargetPosition();
}

void BoardObject::setLocation(int row, int col)
{
    this->_currentLocation = Grid(row,col);
    this->_targetLocation = Grid(row,col);
    this->_position = getTargetPosition();
}

void BoardObject::moveToLocation(int row, int col)
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

void BoardObject::moveBy(int row, int col)
{
    this->moveToLocation(_currentLocation.row + row , _currentLocation.col + col);
}

void BoardObject::update(sf::RenderWindow* window, sf::Time delta)
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
