#ifndef SOUND_H
#define SOUND_H

class Sound
{
    private:
        static sf::SoundBuffer buffer;
        static sf::Sound sound;

        Sound() {}

    public:
        static void PlaySound(string name)
        {
            buffer.loadFromFile("sfx/" + name + ".wav");
            sound.setBuffer(buffer);
            sound.play();
        }
};
sf::SoundBuffer Sound::buffer;
sf::Sound Sound::sound;


#endif // SOUND_H
