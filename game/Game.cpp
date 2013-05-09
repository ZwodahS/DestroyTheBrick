#include "Game.hpp"

#include "screens/Screen.hpp"

#include <SFML/Graphics.hpp>


#define CLEAR_COLOR sf::Color(20,20,20,255)


Game::Game()
{
    _width = 640;
    _height = 640;
    _title = "Destroy the Brick";
    loadAssets();
    _window = new sf::RenderWindow(sf::VideoMode(_width,_height),_title);

}

Game::~Game()
{

}

void Game::run()
{
    sf::Clock clock; // set up the clock for delta

    bool quit = false;

    while(!quit && _window->isOpen())
    {
        // update clock 
        sf::Time delta = clock.restart();
        // update mouse.
        _mouse->update(delta);
        

        // check for events, especially mousewheel
        sf::Event event;
        while(_window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                _window->close();
                quit = true;
            }
            else if(event.type == sf::Event::MouseWheelMoved)
            {
                _mouse->_wheelDelta = event.mouseWheel.delta;
            }
        }

        // if not quit , update then draw.
        if(!quit)
        {
            update(delta);
            draw(delta);
        }
    }
}

void Game::update(sf::Time delta)
{

}

void Game::draw(sf::Time delta)
{
    _window->clear(CLEAR_COLOR);
    if(_currentScreen != 0)
    {
        _currentScreen->draw(_window,delta);   
    }
    _window->display();
}
