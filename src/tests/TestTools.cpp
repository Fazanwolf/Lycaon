#include "tests/TestTools.hpp"
#include <experimental/random>

int TestToolsSparseArrayBasicFromArray(std::array<Texture, 100> textures)
{
    Window win("Tools: SparseArray Test From Array Texture",STYLE::Close);

    SparseArray<Sprite> sprites;

    sprites.add(Sprite(&textures[0], Position(20, 20), Scale(0.3, 0.3)));
    sprites.add(Sprite("../assets/sprite/death.jpg", Position(300, 20), Scale(0.3, 0.3)));
    sprites.add(Sprite(&textures[1], Position(20, 330), Scale(0.6, 0.6)));
    sprites.add(Sprite("../assets/sprite/mountain.jpg", Position(300, 330), Scale(0.6, 0.6)));

    time_t deadline = time(nullptr) + 3;

    std::cout << "size: " << sprites.size() << std::endl;

    int j = 1;
    int k = 0;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);

        if (curr == deadline - 1) {
            if (j > 0) j--;
            if (j == 0 && k == 0) {
                sprites.remove(2);
                sprites.remove(0);
                std::cout << "size: " << sprites.size() << std::endl;
                k++;
            }
        }

        for (size_t i = 0; i < sprites.size(); i++)
            sprites[i].draw(win);

        win.display();
    }
    std::cout << "size: " << sprites.size() << std::endl;
    win.close();
    return (0);
}

int TestToolsSparseArrayBasicFromMap(std::unordered_map<std::string, Texture> textures)
{
    Window win("Tools: SparseArray Test From Map Texture", STYLE::Close);

    SparseArray<Sprite> sprites;

    sprites.add(Sprite(&textures.at("death"), Position(20, 20), Scale(0.3, 0.3)));
    sprites.add(Sprite("../assets/sprite/death.jpg", Position(300, 20), Scale(0.3, 0.3)));
    sprites.add(Sprite(&textures.at("mountain"), Position(20, 330), Scale(0.6, 0.6)));
    sprites.add(Sprite("../assets/sprite/mountain.jpg", Position(300, 330), Scale(0.6, 0.6)));

    time_t deadline = time(nullptr) + 3;

    std::cout << "size: " << sprites.size() << std::endl;

    int j = 1;
    int k = 0;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);

        if (curr == deadline - 1) {
            if (j > 0) j--;
            if (j == 0 && k == 0) {
                sprites.remove(3);
                std::cout << "size: " << sprites.size() << std::endl;
                k++;
            }
        }

        for (size_t i = 0; i < sprites.size(); i++)
            sprites[i].draw(win);

        win.display();
    }
    std::cout << "size: " << sprites.size() << std::endl;
    win.close();
    return (0);
}


int TestToolsSparseArrayBruteForce(std::unordered_map<std::string, Texture> textures)
{
    const int nbAssets = 5000;
    Window win("Tools: SparseArray Test From Map Texture", STYLE::Close);

    std::srand(std::time(nullptr));
    int rand1;
    int rand2;
    int rand3;

    SparseArray<Sprite, nbAssets> sprites;

    for (int i = 0; i < nbAssets; i++)
        sprites.add(Sprite(&textures.at("death"), Position(20, 20), Scale(0.3, 0.3)));

    time_t deadline = time(nullptr) + 10;

    std::cout << "size: " << sprites.size() << std::endl;

    int j = 1;
    int k = 0;

    while (true) {
        time_t curr = time(nullptr);

        if (curr > deadline)
            break;

        win.clear(sf::Color::Red);

        if (sprites.size() > nbAssets - (nbAssets / 3)) {
            rand1 = std::experimental::randint(0, 100);
            rand2 = std::experimental::randint(101, 200);
            rand3 = std::experimental::randint(201, 300);

            sprites.remove(rand1);
            sprites.remove(rand2);
            sprites.remove(rand3);
            std::cout << "size: " << sprites.size() << std::endl;
        }

        for (size_t i = 0; i < sprites.size(); i++)
            sprites[i].draw(win);

        win.display();
    }
    std::cout << "size: " << sprites.size() << std::endl;
    win.close();
    return (0);
}



int TestToolsSparseArrayString()
{
    SparseArray<std::string> sprites;
    sprites.add("Testa");
    sprites.add("Testo");
    sprites.add("Teste");
    sprites.add("Testu");

    std::cout << "size: " << sprites.size() << std::endl;

    for (size_t i = 0; i < sprites.size(); i++)
        std::cout << sprites[i] << std::endl;

    sprites.remove(2);

    std::cout << "size: " << sprites.size() << std::endl;

    for (size_t i = 0; i < sprites.size(); i++)
        std::cout << sprites[i] << std::endl;

    return (0);
}

int TestTools()
{
    std::array<Texture, 100> texturesFromArray = {
        Texture("../assets/sprite/death.jpg"),
        Texture("../assets/sprite/mountain.jpg"),
    };
    std::unordered_map<std::string, Texture> texturesFromMap = {
        {"death", Texture("../assets/sprite/death.jpg")},
        {"mountain", Texture("../assets/sprite/mountain.jpg")},
    };

    TestToolsSparseArrayBasicFromArray(texturesFromArray);
    TestToolsSparseArrayBasicFromMap(texturesFromMap);
    TestToolsSparseArrayBruteForce(texturesFromMap);
    TestToolsSparseArrayString();
    return (0);
}