#ifndef _GAME_ASSETS_
#define _GAME_ASSETS_
#include "../z_framework/zf_sfml/TextureRegion.hpp"
#include "../z_framework/zf_sfml/SpriteSheet.hpp"
#include <SFML/Graphics.hpp>
struct BrickAssets
{
    SpriteSheet spriteSheet;
    TextureRegion brick;
    TextureRegion grid;
};

struct ArrowAssets
{
    TextureRegion up;
    TextureRegion down;
    TextureRegion left;
    TextureRegion right;
};

struct Assets
{
    sf::Font scoreFont;
    BrickAssets bricks;
    ArrowAssets arrows;

};
#endif
