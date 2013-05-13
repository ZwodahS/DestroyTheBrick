#ifndef _GAME_GAMEDATA_H_
#define _GAME_GAMEDATA_H_

#include "boards/Board.hpp"
#include "boards/Brick.hpp"
struct GameData
{
    Board* board;
    Brick* nextBrick;
    bool nextHammer;
    int brickCount;
    int score;
    bool gameover;
    float hammerTurn;
    int nextHammerTurn;
    GameData()
    {
        board = 0;
        nextBrick = 0;
        nextHammer = false;
        brickCount = 0;
        score = 0;
        gameover = false;
        hammerTurn = 5;
        nextHammerTurn = 5;
    }
    ~GameData()
    {
        if(board != 0)
        {
            delete board;
        }
        if(nextBrick != 0)
        {
            delete nextBrick;
        }
    }
};
#endif
