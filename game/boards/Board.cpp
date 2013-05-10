#include "Board.hpp"

#include "../Game.hpp"
#include "../consts.hpp"
#include "Brick.hpp"

Board::Board(Game* game)
{
    this->_game = game;
    this->_knock = -1;
    this->_currentMovingDirection = Grid(0,0);
    for(int r = 0 ; r < gameconsts::BOARD_SIZE ; r++)
    {
        _bricksActualPosition.push_back(std::vector<Brick*>(0));
        for(int c = 0 ; c < gameconsts::BOARD_SIZE ; c++)
        {
            _bricksActualPosition[r].push_back(0);
        }
    }
    this->_movingBricks = std::vector<Brick*>(0);

}

Brick* Board::getBrickAt(int row, int col)
{
    if(!inRange(row,col))
    {
        return 0;
    }
    if(_bricksActualPosition[row][col] == 0)
    {
        return 0;
    }
    return _bricksActualPosition[row][col]; // could still be null.
}
Brick* Board::getBrickAt(Grid grid)
{
    return getBrickAt(grid.row,grid.col);
}
bool Board::inRange(int row, int col)
{
    if(row < 0 || row >= _bricksActualPosition.size() || col < 0 || col >= _bricksActualPosition[row].size())
    {
        return false;
    }
    return true;
}

bool Board::inShootableRange(int row, int col)
{
    if(row < 1 || row >= _bricksActualPosition.size() -1 || col < 1 || col >= _bricksActualPosition[row].size() -1 )
    {
        return false;
    }
    return true;
}

void Board::update(sf::RenderWindow* window, sf::Time delta)
{
    for(int i = 0 ; i < _bricks.size(); i++)
    {
        _bricks[i]->update(window,delta);
    }

    bool stillMoving = false;
    for(int i = 0 ; i < _bricks.size() ; i++)
    {
        if(_bricks[i]->isMoving())
        {
            stillMoving = true;
            break;
        }
    }

    if(isMoving() && !stillMoving)
    {
        for(int i = 0 ; i < _bricks.size() ; i++) // update all their position
        {
            Grid oldL = _bricks[i]->_currentLocation;
            Grid newL = _bricks[i]->_targetLocation;
            if(_bricksActualPosition[oldL.row][oldL.col] == _bricks[i])
            {
                _bricksActualPosition[oldL.row][oldL.col] = 0;
            }
            _bricksActualPosition[newL.row][newL.col] = _bricks[i];
            _bricks[i]->_currentLocation = _bricks[i]->_targetLocation;
        }
        if(_knock == -1) // the first bricks
        {
            Brick* brick = _movingBricks.size() > 0 ? _movingBricks[0] : 0;
            if(brick != 0)
            {
                Grid knockGrid = brick->_currentLocation + _currentMovingDirection;
                Brick* knockBrick = getBrickAt(knockGrid);
                if(knockBrick == 0)
                {
                    // do nothing
                }
                else
                {
                    _knock = getKnockValue();
                }
            }
        }        
        if(_knock > 0)
        {
            _knock--;
            std::vector<Brick*> mBricks = std::vector<Brick*>(0);
            for(int i = 0 ; i < _bricks.size() ; i++)
            {
                _bricks[i]->tmp_moves = false;
            }
            for(int i = 0 ; i < _movingBricks.size() ; i++)
            {
                mBricks.push_back(_movingBricks[i]);
                _movingBricks[i]->tmp_moves = true;
            }
            for(int i = 0 ; i < _movingBricks.size() ; i++) // for the old moving bricks, only knock those that are in the path
            {
                Grid knockGrid = _movingBricks[i]->_currentLocation + _currentMovingDirection;
                Brick* knockBrick = getBrickAt(knockGrid);
                if(knockBrick == 0)
                {
                }
                else if(!(knockBrick->tmp_moves))
                {
                    mBricks.push_back(knockBrick);
                    knockBrick->tmp_moves = true;
                }
            }
            for(int i = _movingBricks.size() ; i < mBricks.size() ; i++)
            {
                addMovingBricks(mBricks[i],mBricks,_currentMovingDirection);
            }
            for(int i = 0 ; i < mBricks.size() ; i++)
            {
                mBricks[i]->moveBy(_currentMovingDirection.row, _currentMovingDirection.col);
            }
        }
        else 
        {
            _currentMovingDirection = Grid(0,0);
            _movingBricks = std::vector<Brick*>(0);
        }
    }
}

void Board::addMovingBricks(Brick* brick, std::vector<Brick*> &movingBricks, Grid moveDirection)
{
    // for now , i will just move all "connected block"
    Grid location = brick->_currentLocation;
    Brick* north = getBrickAt(location + Grid(-1,0));
    Brick* south = getBrickAt(location + Grid(1,0));
    Brick* east = getBrickAt(location + Grid(0,1));
    Brick* west = getBrickAt(location + Grid(0,-1));
    
    if(north != 0 ) // not sure why some times short circuit works sometime it doesn't.
    {
        if(!north->tmp_moves)
        {
            if(brick->getType() == north->getType() || moveDirection == Grid(-1,0))
            {
                north->tmp_moves = true;    
                movingBricks.push_back(north);
            }
        }
    }
    if(south != 0 )
    {
        if(!south->tmp_moves)
        {
            if(brick->getType() == south->getType() || moveDirection == Grid(1,0))
            {
                south->tmp_moves = true;    
                movingBricks.push_back(south);
            }
        }
    }
    if(east != 0)
    {
        if(!east->tmp_moves)
        {
            if(brick->getType() == east->getType() || moveDirection == Grid(0,1))
            {
                east->tmp_moves = true;    
                movingBricks.push_back(east);
            }
        }
    }
    if(west != 0 )
    {
        if(!west->tmp_moves)
        {
            if(brick->getType() == west->getType() || moveDirection == Grid(0,-1))
            {
                west->tmp_moves = true;    
                movingBricks.push_back(west);
            }
        }
    }

}


void Board::draw(sf::RenderWindow* window, sf::Time delta)
{
    for(int i = 0 ; i < _bricks.size() ; i++)
    {
        _bricks[i]->draw(window,delta);
    }
}

bool Board::putBrickInto(int row, int col , Brick* brick)
{
    if(brick!= 0 && inRange(row,col) && getBrickAt(row,col) == 0)
    {
        brick->setLocation(row,col);
        _bricksActualPosition[row][col] = brick;
    }
    _bricks.push_back(brick);
    return false;
}


bool Board::fire(Grid location, Brick* nextBrick, zf::Direction direction)
{
    if(isMoving())
    {
        return false;
    }
    Grid directionGrid = Grid(0,0);
    switch(direction)
    {
        case zf::North:
            directionGrid = Grid(-1,0);
            break;
        case zf::South:
            directionGrid = Grid(1,0);
            break;
        case zf::East:
            directionGrid = Grid(0,1);
            break;
        case zf::West:
            directionGrid = Grid(0,-1);
            break;
    }
    Grid nextGrid = location + directionGrid;
    Brick* brick = getBrickAt(nextGrid.row , nextGrid.col);
    if(brick != 0)
    {
        return false; // if there is a brick blocking directly, don't allow it to shoot.
    }
    //find the first block that it will hit
    // move nextGrid back first
    nextGrid -= directionGrid;
    while(brick == 0)
    {
        nextGrid += directionGrid;
        Grid temp = nextGrid + directionGrid;
        if(!inShootableRange(temp.row,temp.col)) // if the next is not in shootable range , break
        {
            // prevent out of bound
            break;
        }
        brick = getBrickAt(temp.row, temp.col);
    }

    _knock = -1;
    putBrickInto(location.row,location.col,nextBrick);
    nextBrick->moveToLocation(nextGrid.row, nextGrid.col);
    _currentMovingDirection = directionGrid; 
    _movingBricks.push_back(nextBrick);
    return true;
}

bool Board::isMoving()
{
    return _currentMovingDirection != Grid(0,0);
}

int Board::getKnockValue()
{
    //INFO this can be used to turn off knocking or make it knock more.
    return 1;
}
