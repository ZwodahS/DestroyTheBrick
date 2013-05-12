#include "Game.hpp"

#include "g_screens.hpp"
#include <SFML/Graphics.hpp>


#define CLEAR_COLOR sf::Color(20,20,20,255)


Game::Game()
{
    _width = 320;
    _height = 320;
    _title = "Destroy the Brick";
    loadAssets();
    _window = new sf::RenderWindow(sf::VideoMode(_width,_height),_title);

    _mouse = new zf::Mouse();
    _animator = new SimpleAnimator();
}

Game::~Game()
{
    delete _window;
    delete _mouse;
    delete _animator;
}

void Game::run()
{
    sf::Clock clock; // set up the clock for delta

    bool quit = false;
    GameScreen* screen = new GameScreen(this);
    _currentScreen = screen;
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
    if(_currentScreen != 0)
    {
        _currentScreen->update(_window,delta);
    }
    _animator->update(_window,delta);
}

void Game::draw(sf::Time delta)
{
    _window->clear(CLEAR_COLOR);
    if(_currentScreen != 0)
    {
        _currentScreen->draw(_window,delta);   
    }
    _animator->draw(_window,delta);
    _window->display();
}
