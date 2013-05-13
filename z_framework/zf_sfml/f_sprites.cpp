#include "f_sprites.hpp"

namespace zfsprites
{
    std::vector<sf::Sprite> split4(sf::Sprite sprite)
    {
        std::vector<sf::Sprite> splits = std::vector<sf::Sprite>(0);
        const sf::Texture* texture = sprite.getTexture();
        sf::IntRect baseRect = sprite.getTextureRect();
        sf::Vector2f position = sprite.getPosition();
        splits.push_back(sf::Sprite(*texture, sf::IntRect(baseRect.left,baseRect.top,baseRect.width/2,baseRect.height/2)));
        splits[0].setPosition(position.x,position.y);
        splits[0].setColor(sprite.getColor());
        splits.push_back(sf::Sprite(*texture, sf::IntRect(baseRect.left+(baseRect.width/2), baseRect.top, baseRect.width/2, baseRect.height/2)));
        splits[1].setPosition(position.x+baseRect.width/2,position.y);
        splits[1].setColor(sprite.getColor());
        splits.push_back(sf::Sprite(*texture, sf::IntRect(baseRect.left, baseRect.top+(baseRect.height/2), baseRect.width/2 , baseRect.height/2)));
        splits[2].setPosition(position.x,position.y+baseRect.height/2);
        splits[2].setColor(sprite.getColor());
        splits.push_back(sf::Sprite(*texture, sf::IntRect(baseRect.left+(baseRect.width/2), baseRect.top+(baseRect.height/2), baseRect.width/2 , baseRect.height/2)));
        splits[3].setPosition(position.x+baseRect.width/2,position.y+baseRect.height/2);
        splits[3].setColor(sprite.getColor());
        return splits;
    }
}
