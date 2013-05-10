#include "GameScreen.hpp"
#include "../consts.hpp"
#include "../Game.hpp"
#include "../g_boards.hpp"
GameScreen::GameScreen(Game* game)
    :Screen(game)
{
    _data.board = new Board(_game);
    Brick* b = new Brick(_game,_data.board,brick::RED);
    for(int row = 1 ; row < gameconsts::BOARD_SIZE - 1 ; row ++)
    {
        for(int col = 1 ; col < gameconsts::BOARD_SIZE -1  ; col ++)
        {
            sf::Sprite s = _game->_assets.bricks.grid.createSprite();
            s.setPosition(col * gameconsts::BRICK_SIZE , row * gameconsts::BRICK_SIZE);
            _floorGrid.push_back(s);
        }
    }

    _arrows = std::vector<LaunchArrow>(0);
    for(int row = 1 ; row < gameconsts::BOARD_SIZE-1 ; row++) // col = 0 and col == BOARD_SIZE - 1
    {
        _arrows.push_back(LaunchArrow(_game,zf::East,row,0));
        _arrows.push_back(LaunchArrow(_game,zf::West,row,gameconsts::BOARD_SIZE - 1));
    }
    for(int col = 1 ; col < gameconsts::BOARD_SIZE-1 ; col++)
    {
        _arrows.push_back(LaunchArrow(_game,zf::South,0,col));
        _arrows.push_back(LaunchArrow(_game,zf::North,gameconsts::BOARD_SIZE - 1 , col));
    }
}

void GameScreen::draw(sf::RenderWindow* window, sf::Time delta)
{
    for(int i = 0 ; i < _arrows.size() ; i++)
    {
        _arrows[i].draw(window,delta);
    }
    for(int i = 0 ; i < _floorGrid.size() ; i++)
    {
        window->draw(_floorGrid[i]);
    }
    _data.board->draw(window,delta);
}

void GameScreen::update(sf::RenderWindow* window, sf::Time delta)
{
    _data.board->update(window,delta);
}



LaunchArrow::LaunchArrow()
{
    this->_game = 0;
    this->_location = Grid(0,0);
}

LaunchArrow::LaunchArrow(Game* game,zf::Direction direction, int row, int col)
{
    this->_game = game;
    this->_location = Grid(row,col);
    setDirection(direction);
}


void LaunchArrow::draw(sf::RenderWindow* window, sf::Time delta)
{
    sf::Vector2f position = _game->_mouse->getWorldPosition(*window);
    if(Grid::toGrid((int)position.x,(int)position.y,gameconsts::BRICK_SIZE,0) == _location)
    {
        _arrowSprite.setColor(sf::Color(255,255,0));
    }
    else
    {
        _arrowSprite.setColor(sf::Color(255,255,255));
    }
    window->draw(_arrowSprite);
}

void LaunchArrow::update(sf::RenderWindow* window, sf::Time delta)
{

}

void LaunchArrow::setDirection(zf::Direction direction)
{
    this->_direction = direction;
    if(_direction == zf::North)
    {
        _arrowSprite = _game->_assets.arrows.up.createSprite();
    }
    else if(_direction == zf::East)
    {
        _arrowSprite = _game->_assets.arrows.right.createSprite();
    }
    else if(_direction == zf::South)
    {
        _arrowSprite = _game->_assets.arrows.down.createSprite();
    }
    else 
    {
        _arrowSprite = _game->_assets.arrows.left.createSprite();
    }
    _arrowSprite.setPosition(_location.col * gameconsts::BRICK_SIZE , _location.row * gameconsts::BRICK_SIZE);
}
