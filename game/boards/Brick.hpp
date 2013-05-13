#ifndef _GAME_BOARDS_BRICK_H_
#define _GAME_BOARDS_BRICK_H_

#include "BoardObject.hpp"
#include "../../z_framework/zf_common/Grid.hpp"
#include <SFML/Graphics.hpp>

namespace brick
{
    enum BrickType
    {
        RED,
        GREEN,
        BLUE,
        YELLOW,
    };

}

class Board;
class Game;
class Brick : public BoardObject
{
    public:
        Brick(Game* game,Board* board);
        Brick(Game* game,Board* board,brick::BrickType type);
        ~Brick();

        brick::BrickType getType();
        void setType(brick::BrickType type);
        void draw(sf::RenderWindow* window, sf::Time delta);

    private:
        brick::BrickType _type;
        sf::Sprite _brickSprite;
};

#endif
