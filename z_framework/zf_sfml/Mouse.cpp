#include "Mouse.hpp"
#include "../zf_common/f_inputs.hpp"

zf::Mouse::Mouse()
{
    _wheelDelta = 0;
}

zf::Mouse::~Mouse()
{
}

void zf::Mouse::update(sf::Time delta)
{
    update(delta,0);
}

void zf::Mouse::update(sf::Time delta, int wheelDelta)
{
    zf_inputs::processKey(_left, sf::Mouse::isButtonPressed(sf::Mouse::Left));
    zf_inputs::processKey(_right, sf::Mouse::isButtonPressed(sf::Mouse::Right));
    zf_inputs::processKey(_middle, sf::Mouse::isButtonPressed(sf::Mouse::Middle));
}

sf::Vector2i zf::Mouse::getPosition()
{
    return sf::Mouse::getPosition();
}

sf::Vector2i zf::Mouse::getPosition(sf::Window &window)
{
    return sf::Mouse::getPosition(window);
}

sf::Vector2f zf::Mouse::getWorldPosition(sf::RenderWindow &window)
{
    return window.mapPixelToCoords(getPosition(window));
}
