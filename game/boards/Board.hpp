#ifndef _GAME_BOARDS_BOARD_H_
#define _GAME_BOARDS_BOARD_H_
#include "../../z_framework/zf_common/Grid.hpp"
#include "../../z_framework/zf_common/Direction.hpp"
#include "../../z_framework/zf_sfml/SimpleAnimator.hpp"
#include <SFML/Graphics.hpp>
class Game;
class Brick;
class Hammer;
struct GameData;
class Board
{
    public:
        Board(Game* game,GameData* data);
        bool inRange(int row , int col);
        bool inShootableRange(int row, int col);
        Brick* getBrickAt(int row, int col);
        Brick* getBrickAt(Grid grid);
        bool putBrickInto(int row, int col, Brick* brick);
        bool putHammerInto(int row, int col, Hammer* hammer);
        void update(sf::RenderWindow* window, sf::Time delta);
        void draw(sf::RenderWindow* window, sf::Time delta);
        bool fireBrick(Grid location, Brick* nextBrick , zf::Direction direction);
        bool fireHammer(Grid location, zf::Direction direction);
        bool isMoving();

    private:

        Hammer* _hammer;
        Grid _currentMovingDirection;
        Game* _game;
        GameData* _data;
        int _knock;
        std::vector<Brick*> _bricks;
        std::vector<std::vector<Brick*> > _bricksActualPosition;
        std::vector<Brick*> _movingBricks;
        int getKnockValue();
        void addMovingBricks(Brick* brick, std::vector<Brick*> &movingBricks,Grid moveDirection);
        void fadeHammer();
        void fadeBrick(Brick* brick,int score);
        void addDestroyedBricks(Brick* brick, std::vector<Brick*> &destroyedBricks);
        bool checkForGameOver();
        SimpleAnimator* _animator;
};
#endif
