#include "tests/TestWindow.hpp"

int TestWindowBasic()
{
    Window win;
    win.clear(sf::Color::Red);
    win.display();
    sleep(1);
    win.close();
    return (0);
}

int TestWindowStyle()
{
    Window win(STYLE::Close);
    win.clear(sf::Color::Red);
    win.display();
    sleep(1);
    win.close();
    return (0);
}

int TestWindowName()
{
    Window win("UwU");
    win.clear(sf::Color::Red);
    win.display();
    sleep(1);
    win.close();
    return (0);
}

int TestWindowMode()
{
    Window win(Mode(1000, 600));
    win.clear(sf::Color::Red);
    win.display();
    sleep(1);
    win.close();
    return (0);
}

int TestWindowModeName()
{
    Window win(Mode(1000, 600), "UwU");
    win.clear(sf::Color::Red);
    win.display();
    sleep(1);
    win.close();
    return (0);
}

int TestWindowModeStyle()
{
    Window win(Mode(1000, 600), STYLE::Close);
    win.clear(sf::Color::Red);
    win.display();
    sleep(1);
    win.close();
    return (0);
}

int TestWindowNameStyle()
{
    Window win("UwU", STYLE::Close);
    win.clear(sf::Color::Red);
    win.display();
    sleep(1);
    win.close();
    return (0);
}

int TestWindowModeNameStyle()
{
    Window win(Mode(1000, 600), "UwU", STYLE::Close);
    win.clear(sf::Color::Red);
    win.display();
    sleep(1);
    win.close();
    return (0);
}

int TestWindow()
{
    TestWindowBasic();

    TestWindowMode();
    TestWindowName();
    TestWindowStyle();

    TestWindowModeName();
    TestWindowModeStyle();
    TestWindowNameStyle();

    TestWindowModeNameStyle();
    return (0);
}
