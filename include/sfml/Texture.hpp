#pragma once

#include <SFML/Graphics.hpp>

class Texture {
    public:
        Texture() {};

        Texture(const std::string &filename)
        {
            _texture.loadFromFile(filename);
        }

        Texture(const Vector2<int> &size)
        {
            _texture.create(size.x, size.y);
        }

        Texture(const std::string &filename, sf::IntRect rect)
        {
            _texture.loadFromFile(filename, rect);
        }

        Texture(const std::string &filename, const Vector4<int> &rect)
        {
            _texture.loadFromFile(filename, sf::IntRect(rect.a, rect.b, rect.c, rect.d));
        }

        ~Texture() = default;

        void loadFromFile(const std::string &filename)
        {
            _texture.loadFromFile(filename);
        }

        void loadFromFile(const std::string &filename, sf::IntRect rect)
        {
            _texture.loadFromFile(filename, rect);
        }

        void loadFromFile(const std::string &filename, const Vector4<int> &rect)
        {
            _texture.loadFromFile(filename, sf::IntRect(rect.a, rect.b, rect.c, rect.d));
        }

        void create(Vector2<int> size)
        {
            _texture.create(size.x, size.y);
        }

        void update(sf::Image img)
        {
            _texture.update(img);
        }

        sf::Texture &getTexture()
        {
            return _texture;
        }

        void setSmooth(bool status)
        {
            _texture.setSmooth(status);
        }

        void setRepeated(bool status)
        {
            _texture.setRepeated(status);
        }

        Texture &operator=(const Texture &other) = default;

    private:
        sf::Texture _texture;
};
