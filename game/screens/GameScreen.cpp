#include "GameScreen.hpp"

#include "../Game.hpp"
#include "../g_boards.hpp"
GameScreen::GameScreen(Game* game)
    :Screen(game)
{
    _data.board = new Board(_game);
    Brick* b = new Brick(_game,_data.board,brick::RED);
    _data.board->putBrickInto(5,0,b);
    b->moveToLocation(5,10);
}

void GameScreen::draw(sf::RenderWindow* window, sf::Time delta)
{
    _data.board->draw(window,delta);
}

void GameScreen::update(sf::RenderWindow* window, sf::Time delta)
{
    _data.board->update(window,delta);
}
