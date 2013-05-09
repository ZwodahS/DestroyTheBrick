#include "GameScreen.hpp"

#include "../Game.hpp"
#include "../g_boards.hpp"
GameScreen::GameScreen(Game* game)
    :Screen(game)
{
    _board = new Board(_game);
}

void GameScreen::draw(sf::RenderWindow* window, sf::Time delta)
{
    _board->draw(window,delta);
}

void GameScreen::update(sf::RenderWindow* window, sf::Time delta)
{
    _board->update(window,delta);
}
