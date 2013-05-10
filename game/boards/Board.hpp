#ifndef _GAME_BOARDS_BOARD_H_
#define _GAME_BOARDS_BOARD_H_

#include "../../z_framework/zf_common/Grid.hpp"
#include "../../z_framework/zf_common/Direction.hpp"
#include <SFML/Graphics.hpp>
class Game;
class Brick;
class Board
{
    public:
        Board(Game* game);
        bool inRange(int row , int col);
        bool inShootableRange(int row, int col);
        Brick* getBrickAt(int row, int col);
        Brick* getBrickAt(Grid grid);
        bool putBrickInto(int row, int col, Brick* brick);
        void update(sf::RenderWindow* window, sf::Time delta);
        void draw(sf::RenderWindow* window, sf::Time delta);
        bool fire(Grid location, Brick* nextBrick , zf::Direction direction);
        bool isMoving();

    private:
        Grid _currentMovingDirection;
        Game* _game;
        int _knock;
        std::vector<Brick*> _bricks;
        std::vector<std::vector<Brick*> > _bricksActualPosition;
        std::vector<Brick*> _movingBricks;
        int getKnockValue();
        void addMovingBricks(Brick* brick, std::vector<Brick*> &movingBricks,Grid moveDirection);
};
#endif
