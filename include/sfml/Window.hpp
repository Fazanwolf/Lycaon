#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "tools/Types.hpp"

enum STYLE
{
    None       = 0,
    Titlebar   = 1 << 0,
    Resize     = 1 << 1,
    Close      = 1 << 2,
    Fullscreen = 1 << 3,
    Default = Titlebar | Resize | Close
};

class Window {
    public:
        Window()
        {
            _window = new sf::RenderWindow(DEFAULT_MODE, DEFAULT_TITLE);
        }

        explicit Window(const std::string &title)
        {
            _window = new sf::RenderWindow(DEFAULT_MODE, title);
        }

        explicit Window(Mode mode)
        {
            _window = new sf::RenderWindow(sf::VideoMode(mode.x, mode.y), DEFAULT_TITLE);
        }

        explicit Window(STYLE style)
        {
            _window = new sf::RenderWindow(DEFAULT_MODE, DEFAULT_TITLE, style);
        }

        explicit Window(Mode mode, const std::string &title)
        {
            _window = new sf::RenderWindow(sf::VideoMode(mode.x, mode.y), title);
        }

        explicit Window(Mode mode, STYLE style)
        {
            _window = new sf::RenderWindow(sf::VideoMode(mode.x, mode.y), DEFAULT_TITLE, style);
        }

        explicit Window(const std::string &title, STYLE style)
        {
            _window = new sf::RenderWindow(DEFAULT_MODE, title, style);
        }

        explicit Window(Mode mode, const std::string &title, STYLE style)
        {
            _window = new sf::RenderWindow(sf::VideoMode(mode.x, mode.y), title, style);
        }

        ~Window() = default;

        void clear(const sf::Color& color)
        {
            _window->clear(color);
        }

//        void draw(const sf::Drawable &drawable)
//        {
//            _window->draw(drawable);
//        }
//
//        void draw(const Sprite &sprite)
//        {
//            _window->draw(sprite.getSprite());
//        }

        void display()
        {
            _window->display();
        }

        bool isOpen()
        {
            return _window->isOpen();
        }

        sf::RenderWindow &getWindow()
        {
            return *_window;
        }

        void close()
        {
            _window->close();
        }

    private:
        sf::RenderWindow *_window;
};
