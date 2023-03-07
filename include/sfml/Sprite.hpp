#pragma once

#include <memory>
#include "sfml/Texture.hpp"
#include <sfml/Window.hpp>
#include "tools/Types.hpp"

class Sprite {
    public:
        Sprite() = default;

        explicit Sprite(const std::string &filename)
        {
            _texture = new Texture(filename);
            _sprite.setTexture(_texture->getTexture());
        }

        Sprite(const std::string &filename, Position position, Scale scale)
        {
            _texture = new Texture(filename);
            _sprite.setTexture(_texture->getTexture());
            _sprite.setPosition(position.x, position.y);
            _sprite.setScale(scale.x, scale.y);
        }

        Sprite(const std::string &filename, Rectangle rect, Position position, Scale scale)
        {
            _texture = new Texture(filename, rect);
            _sprite.setTexture(_texture->getTexture());
            _sprite.setPosition(position.x, position.y);
            _sprite.setScale(scale.x, scale.y);
        }

        Sprite(Texture *texture, Position position, Scale scale)
        {
            _texture = texture;
            _sprite.setTexture(_texture->getTexture());
            _sprite.setPosition(position.x, position.y);
            _sprite.setScale(scale.x, scale.y);
        }

        Sprite(Texture *texture, Rectangle rect, Position position, Scale scale)
        {
            _texture = texture;
            _sprite.setTexture(_texture->getTexture());
            _sprite.setPosition(position.x, position.y);
            _sprite.setScale(scale.x, scale.y);
        }

        void setTexture(const std::string &filename)
        {
            _texture->loadFromFile(filename);
            _sprite.setTexture(_texture->getTexture());
        }

        void applyTexture()
        {
            _sprite.setTexture(_texture->getTexture());
        }

        void setPosition(Vector2<float> position)
        {
            _sprite.setPosition(position.x, position.y);
        }

        void setScale(Vector2<float> scale)
        {
            _sprite.setScale(scale.x, scale.y);
        }

        sf::Sprite &getSprite()
        {
            return _sprite;
        }

        sf::Texture &getTexture()
        {
            return _texture->getTexture();
        }

        void draw(Window &window)
        {
            window.getWindow().draw(_sprite);
        }

    private:
        sf::Sprite _sprite;
        Texture *_texture;
};
