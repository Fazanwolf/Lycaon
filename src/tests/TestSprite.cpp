#include "tests/TestSprite.hpp"
#include <ctime>
#include <memory>

int TestSpriteBasic()
{
    Window win(Mode(1000, 600), "UwU", STYLE::Close);

    Sprite sprite;
    sprite.setTexture("../assets/sprite/death.jpg");
    sprite.setPosition(Position(100, 100));
    sprite.setScale(Scale(1, 1));

    time_t deadline = time(nullptr) + 3;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);
        sprite.draw(win);
        win.display();
    }
    win.close();
    return (0);
}

int TestSpriteName()
{
    Window win(STYLE::Close);
    Sprite sprite("../assets/sprite/death.jpg");

    time_t deadline = time(nullptr) + 3;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);
        sprite.draw(win);
        win.display();
    }
    win.close();
    return (0);
}

int TestSpriteNamePosScale()
{
    Window win(STYLE::Close);
    Sprite sprite("../assets/sprite/death.jpg", Position(100, 50), Scale(0.8, 0.8));

    time_t deadline = time(nullptr) + 3;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);
        sprite.draw(win);
        win.display();
    }
    win.close();
    return (0);
}

int TestSpriteUsingPtr()
{
    Window win(STYLE::Close);
    Sprite *sprite = new Sprite("../assets/sprite/death.jpg", Position(100, 50), Scale(0.8, 0.8));

    time_t deadline = time(nullptr) + 3;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);
        sprite->draw(win);
        win.display();
    }
    win.close();
    delete sprite;
    return (0);
}

int TestSpriteUsingUniquePtr()
{
    Window win(STYLE::Close);
    std::unique_ptr<Sprite> sprite = std::make_unique<Sprite>("../assets/sprite/death.jpg", Position(100, 50), Scale(0.8, 0.8));

    time_t deadline = time(nullptr) + 3;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);
        sprite->draw(win);
        win.display();
    }
    win.close();
    return (0);
}

int TestSpriteUsingSharedPtr()
{
    Window win(STYLE::Close);
    std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("../assets/sprite/death.jpg", Position(100, 50), Scale(0.8, 0.8));

    time_t deadline = time(nullptr) + 3;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);
        sprite->draw(win);
        win.display();
    }
    win.close();
    return (0);
}

int TestSprite()
{
    TestSpriteBasic();
    TestSpriteName();
    TestSpriteNamePosScale();

    TestSpriteUsingPtr();
    TestSpriteUsingSharedPtr();
    TestSpriteUsingUniquePtr();
    return (0);
}