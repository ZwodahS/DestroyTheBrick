#ifndef _GAME_GAMEDATA_H_
#define _GAME_GAMEDATA_H_
class Board;
class Brick;
struct GameData
{
    Board* board;
    Brick* nextBrick;

};
#endif
