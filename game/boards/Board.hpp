#ifndef _GAME_BOARDS_BOARD_H_
#define _GAME_BOARDS_BOARD_H_

#include <SFML/Graphics.hpp>
class Game;
class Brick;
class Board
{
    public:
        Board(Game* game);
        bool inRange(int row , int col);
        Brick* getBrickAt(int row, int col);
        bool putBrickInto(int row, int col, Brick* brick);
        void reachTarget(Brick* brick, sf::Vector2f moveVector);
        void update(sf::RenderWindow* window, sf::Time delta);
        void draw(sf::RenderWindow* window, sf::Time delta);
    private:
        Game* _game;
        std::vector<std::vector<Brick*> > _bricks;
};
#endif
