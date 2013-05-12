#ifndef _ZF_SFML_MOUSE_H_
#define _ZF_SFML_MOUSE_H_

#include "../zf_common/InputState.hpp"

#include <SFML/Graphics.hpp>
namespace zf
{
    // There is no need to keep track of the position , since you can get it directly.
    class Mouse
    {
        public:
            InputState _left;
            InputState _right;
            InputState _middle;
            int _wheelDelta;
            void update(sf::Time delta);
            void update(sf::Time delta, int wheelDelta);
            sf::Vector2i getPosition();
            sf::Vector2i getPosition(sf::Window &window);
            sf::Vector2f getWorldPosition(sf::RenderWindow &window);
            Mouse();
            ~Mouse();
    };
}
#endif
