#include "GameScreen.hpp"
#include "../consts.hpp"
#include "../Game.hpp"
#include "../g_boards.hpp"

#include "../../z_framework/zf_common/f_conversion.hpp"

#define WORD_COLOR sf::Color(0,0,0,255)
#define ARROW_COLOR sf::Color(0,100,0,255)
GameScreen::GameScreen(Game* game)
    :Screen(game)
{

    newGame();
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
        _arrows.push_back(LaunchArrow(_game,this,zf::East,row,0));
        _arrows.push_back(LaunchArrow(_game,this,zf::West,row,gameconsts::BOARD_SIZE - 1));
    }
    for(int col = 1 ; col < gameconsts::BOARD_SIZE-1 ; col++)
    {
        _arrows.push_back(LaunchArrow(_game,this,zf::South,0,col));
        _arrows.push_back(LaunchArrow(_game,this,zf::North,gameconsts::BOARD_SIZE - 1 , col));
    }
        
    _score = new sf::Text("Score : ", _game->_assets.scoreFont,10);
    _score->setPosition(330, 20);
    _score->setColor(WORD_COLOR);
    
    _scoreValue = new sf::Text("00000",_game->_assets.scoreFont, 10);
    _scoreValue->setPosition(400,20);
    _scoreValue->setColor(WORD_COLOR);

    _hammerIn = new sf::Text("Hammer:", _game->_assets.scoreFont,10);
    _hammerIn->setPosition(330,80);
    _hammerIn->setColor(WORD_COLOR);
   
    _hammerValue = new sf::Text(zf::toString(_data.nextHammerTurn),_game->_assets.scoreFont, 10);
    _hammerValue->setPosition(420,80);
    _hammerValue->setColor(WORD_COLOR);

    _next = new sf::Text("Next :",_game->_assets.scoreFont,10);
    _next->setPosition(330,120);
    _next->setColor(WORD_COLOR);

    _hammerSprite = new sf::Sprite(_game->_assets.bricks.hammer.createSprite());
    _hammerSprite->setPosition(400,120);

    _gameoverText1 = new sf::Text("Game over", _game->_assets.scoreFont,36);
    _gameoverText1->setColor(WORD_COLOR);
    _gameoverText1->setPosition(50,50);
    _gameoverText2 = new sf::Text("Score : 0", _game->_assets.scoreFont,24);
    _gameoverText2->setPosition(150,100);
    _gameoverText2->setColor(WORD_COLOR);
    _gameoverText3 = new sf::Text("Click for new game",_game->_assets.scoreFont,12);
    _gameoverText3->setColor(WORD_COLOR);
    _gameoverText3->setPosition(125,150);

    _bg = sf::RectangleShape(sf::Vector2f(_game->_width,_game->_height));
    _bg.setFillColor(sf::Color(30,30,30,200));

}
GameScreen::~GameScreen()
{
    delete _next;
    delete _hammerSprite;
    delete _score;
    delete _scoreValue;
    delete _next;
    delete _hammerIn;
    delete _hammerValue;
    delete _hammerSprite;
    delete _gameoverText1;
    delete _gameoverText2;
    delete _gameoverText3;
}

void GameScreen::newGame()
{
    _data = GameData();
    _data.board = new Board(_game,&_data);

    _data.board->putBrickInto(4,4,new Brick(_game,_data.board));
    _data.board->putBrickInto(4,5,new Brick(_game,_data.board));
    _data.board->putBrickInto(5,4,new Brick(_game,_data.board));
    _data.board->putBrickInto(5,5,new Brick(_game,_data.board));
    _data.nextBrick = new Brick(_game,_data.board);
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
    drawHud(window,delta);
}

void GameScreen::update(sf::RenderWindow* window, sf::Time delta)
{
    if(!_data.gameover)
    {
        for(int i = 0; i < _arrows.size() ; i++)
        {
            _arrows[i].update(window,delta);
        }
        _data.board->update(window,delta);
    }
    else
    {
        if(_game->_mouse->_left.thisPressed)
        {
            newGame();
        }
    }
}

void GameScreen::launch(LaunchArrow* arrow)
{
    if(_data.nextHammer)
    {
        if(!_data.board->isMoving())
        {
            Grid arrowLocation = arrow->_location;
            bool fired = _data.board->fireHammer(arrowLocation, arrow->_direction);
            if(fired)
            {
                _data.nextHammer = false;
                _data.hammerTurn+=0.5;
                _data.nextHammerTurn = (int)_data.hammerTurn;
                
            }
        }
    }
    else
    {
        if(!_data.board->isMoving())
        {
            Grid arrowLocation = arrow->_location;
            bool fired = _data.board->fireBrick(arrowLocation, _data.nextBrick,arrow->_direction);
            if(fired)
            {
                _data.nextBrick = new Brick(_game,_data.board);
                _data.brickCount++;
                _data.nextHammerTurn--;
                if(_data.nextHammerTurn == 0)
                {
                    _data.nextHammer = true;
                }
            }
        }
    }
}

void GameScreen::drawHud(sf::RenderWindow* window, sf::Time delta)
{
    window->draw(*_next);
    if(_data.nextHammer)
    {
        window->draw(*_hammerSprite);
    }
    else
    {
        _data.nextBrick->draw(window,delta,sf::Vector2f(400,120));
    }
    _scoreValue->setString(zf::toString(_data.score));
    _hammerValue->setString(zf::toString(_data.nextHammerTurn));
    window->draw(*_score);
    window->draw(*_scoreValue);
    window->draw(*_hammerIn);
    window->draw(*_hammerValue); 
    if(_data.gameover)
    {
        window->draw(_bg);
        window->draw(*_gameoverText1);
        _gameoverText2->setString("Score :"+zf::toString(_data.score));
        window->draw(*_gameoverText2);
        window->draw(*_gameoverText3);
    }
}



LaunchArrow::LaunchArrow()
{
    this->_game = 0;
    this->_location = Grid(0,0);
}

LaunchArrow::LaunchArrow(Game* game,GameScreen* screen,zf::Direction direction, int row, int col)
{
    this->_game = game;
    this->_screen = screen;
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
        _arrowSprite.setColor(ARROW_COLOR);
    }
    window->draw(_arrowSprite);
}

void LaunchArrow::update(sf::RenderWindow* window, sf::Time delta)
{
    if(_game->_mouse->_left.thisPressed)
    {
        sf::Vector2f position = _game->_mouse->getWorldPosition(*window);
        if(Grid::toGrid((int)position.x,(int)position.y,gameconsts::BRICK_SIZE,0) == _location)
        {
            _screen->launch(this);
        }
    }
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


