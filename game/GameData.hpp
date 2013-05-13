#ifndef _GAME_GAMEDATA_H_
#define _GAME_GAMEDATA_H_
class Board;
class Brick;
struct GameData
{
    Board* board;
    Brick* nextBrick;
    bool nextHammer;
    int brickCount;
    GameData()
    {
        board = 0;
        nextBrick = 0;
        nextHammer = false;
        brickCount = 0;
    }
};
#endif
