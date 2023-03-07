#include "tests/TestAudio.hpp"
#include <ctime>
#include <memory>

int TestAudio()
{
    Audio sound("../assets/audio/censor.mp3", false);
    std::unique_ptr<Audio> pew = std::make_unique<Audio>("../assets/audio/pew-pew.mp3");

    sound.play();
    pew->play();

    time_t deadline = time(nullptr) + 3;

    while (true) {
        time_t curr = time(nullptr);
        if (curr == deadline - 1)
            sound.stop();
        if (curr > deadline)
            break;
    }
    return (0);
}