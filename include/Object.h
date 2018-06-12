#ifndef OBJECT_H
#define OBJECT_H

class Object
{
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f position;
        double speed;

    public:
        Object() {}
        virtual ~Object() {}

        virtual sf::Sprite GetSprite() = 0;
        virtual sf::Vector2f GetPosition() = 0;
};

#endif // OBJECT_H
