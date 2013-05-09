#include "Board.hpp"

#include "../Game.hpp"
#include "Brick.hpp"

#define BOARD_SIZE 13
Board::Board(Game* game)
{
    this->_game = game;

    for(int r = 0 ; r < BOARD_SIZE ; r++)
    {
        _bricks.push_back(std::vector<Brick*>(0));
        for(int c = 0 ; c < BOARD_SIZE ; c++)
        {
            _bricks[r].push_back(0);
        }
    }
}

Brick* Board::getBrickAt(int row, int col)
{
    if(!inRange(row,col))
    {
        return 0;
    }
    return _bricks[row][col]; // could still be null.
}

bool Board::inRange(int row, int col)
{
    if(row < 0 || row >= _bricks.size() || col < 0 || col >= _bricks[row].size())
    {
        return false;
    }
    return true;
}

void Board::update(sf::RenderWindow* window, sf::Time delta)
{
    for(int r = 0 ; r < _bricks.size(); r++)
    {
        for(int c = 0 ; c < _bricks[r].size() ; c++)
        {
            if(_bricks[r][c] != 0)
            {
                _bricks[r][c]->update(window,delta);
            }
        }
    }
}

void Board::draw(sf::RenderWindow* window, sf::Time delta)
{
    for(int r = 0 ; r < _bricks.size(); r++)
    {
        for(int c = 0 ; c < _bricks[r].size() ; c++)
        {
            if(_bricks[r][c] != 0)
            {
                _bricks[r][c]->draw(window,delta);
            }
        }
    }
}

bool Board::putBrickInto(int row, int col , Brick* brick)
{
    if(brick!= 0 && inRange(row,col) && getBrickAt(row,col) == 0)
    {
        brick->setLocation(row,col);
        _bricks[row][col] = brick;
    }
    return false;
}

void Board::reachTarget(Brick* brick, sf::Vector2f moveVector)
{
}
