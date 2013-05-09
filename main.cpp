#include <stdlib.h>
#include <time.h>
#include "game/Game.hpp"
int main(int argc , char * argv[])
{
    srand(time(NULL));
    
    Game* g = new Game();
    g->run();
    delete g;
    
}
