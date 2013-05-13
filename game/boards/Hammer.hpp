#ifndef _GAME_BOARDS_HAMMER_H_
#define _GAME_BOARDS_HAMMER_H_
#include "BoardObject.hpp"
#include "../../z_framework/zf_common/Grid.hpp"

#include <SFML/Graphics.hpp>

class Board;
class Game;
class Hammer : public BoardObject
{
    public:
        Hammer(Game* game, Board* board);
        ~Hammer();
        void draw(sf::RenderWindow* window, sf::Time delta);
    private:
        sf::Sprite _hammerSprite;
};
#endif
