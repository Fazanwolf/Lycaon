#ifndef LYCAON_AUDIO_HPP
#define LYCAON_AUDIO_HPP

#include <iostream>
#include <SFML/Audio.hpp>

class Audio {
    public:
        Audio()
        {
            _sound.setBuffer(_buffer);
        }

        Audio(const std::string &filename)
        {
            _buffer.loadFromFile(filename);
            _sound.setBuffer(_buffer);
        }

        Audio(const std::string &filename, bool loop)
        {
            _buffer.loadFromFile(filename);
            _sound.setBuffer(_buffer);
            _sound.setLoop(loop);
        }

        void loadSound(const std::string &filename)
        {
            _buffer.loadFromFile(filename);
        }

        void play()
        {
            _sound.play();
        }

        void pause()
        {
            _sound.pause();
        }

        void setLoop(bool status)
        {
            _sound.setLoop(status);
        }

        sf::Sound getSound()
        {
            return _sound;
        }

        bool getLoop() const
        {
            return (_sound.getLoop());
        }

        void stop()
        {
            _sound.stop();
        }

    private:
        sf::Sound _sound;
        sf::SoundBuffer _buffer;
};

#endif //LYCAON_AUDIO_HPP
