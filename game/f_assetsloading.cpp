#include "Game.hpp"

void Game::loadAssets()
{
    _assets.scoreFont.loadFromFile("assets/fonts/sofachrome.ttf");

    _assets.bricks.spriteSheet = SpriteSheet(sf::IntRect(0,0,64,64),5,5);

    sf::Image group;
    sf::Image image;

    group.create(64,64,sf::Color(0,0,0,0));
    image.loadFromFile("assets/img/brick.png");
    group.copy(image,0,0,sf::IntRect(0,0,0,0),true);
    image.loadFromFile("assets/img/grid.png");
    group.copy(image,32,0,sf::IntRect(0,0,0,0),true);
    image.loadFromFile("assets/img/hammer.png");
    group.copy(image,0,32,sf::IntRect(0,0,0,0),true);

    TextureRegion region =_assets.bricks.spriteSheet.createRegion(group);
    sf::IntRect srcClip = region.srcClip;

    _assets.bricks.brick = TextureRegion(region.texture,sf::IntRect(srcClip.left, srcClip.top,32,32));
    _assets.bricks.grid = TextureRegion(region.texture,sf::IntRect(srcClip.left+32,srcClip.top,32,32));
    _assets.bricks.hammer = TextureRegion(region.texture,sf::IntRect(srcClip.left, srcClip.top+32,32,32));


    group.create(64,64,sf::Color(0,0,0,0));
    image.loadFromFile("assets/img/arrows/up.png");
    group.copy(image,0,0,sf::IntRect(0,0,0,0),true);
    image.loadFromFile("assets/img/arrows/down.png");
    group.copy(image,32,0,sf::IntRect(0,0,0,0),true);
    image.loadFromFile("assets/img/arrows/left.png");
    group.copy(image,0,32,sf::IntRect(0,0,0,0),true);
    image.loadFromFile("assets/img/arrows/right.png");
    group.copy(image,32,32,sf::IntRect(0,0,0,0),true);


    region = _assets.bricks.spriteSheet.createRegion(group);
    srcClip = region.srcClip;

    _assets.arrows.up = TextureRegion(region.texture, sf::IntRect(srcClip.left, srcClip.top, 32, 32));
    _assets.arrows.down = TextureRegion(region.texture, sf::IntRect(srcClip.left+32,srcClip.top, 32, 32));
    _assets.arrows.left = TextureRegion(region.texture, sf::IntRect(srcClip.left, srcClip.top+32, 32, 32));
    _assets.arrows.right = TextureRegion(region.texture, sf::IntRect(srcClip.left+32, srcClip.top+32, 32, 32));
}
