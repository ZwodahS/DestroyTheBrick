#include "Hammer.hpp"
#include "Board.hpp"
#include "../consts.hpp"
#include "../Game.hpp"

Hammer::Hammer(Game* game, Board* board)
    :BoardObject(game,board)
{
    this->_hammerSprite = _game->_assets.bricks.hammer.createSprite();
    this->_hammerSprite.setColor(sf::Color(255,255,255));
}

Hammer::~Hammer()
{
}

void Hammer::draw(sf::RenderWindow* window, sf::Time delta)
{
    _hammerSprite.setPosition(_position);
    window->draw(_hammerSprite);
}
