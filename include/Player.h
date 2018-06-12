#ifndef PLAYER_H
#define PLAYER_H

class Player : public Object
{
    private:

    public:
        Player()
        {
            texture.loadFromFile("gfx/player.png");
            sprite.setTexture(texture);
            sprite.setOrigin(24, 24);

            speed = 0.1;

            position.x = 100;
            position.y = 650;
        }

        virtual ~Player() {}

        void Movement(double FPS)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                position.x -= speed * FPS;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                position.x += speed * FPS;
            }

            if(position.x < 0)
                position.x = 1000;
            else if(position.x > 1000)
                position.x = 0;

            sprite.setPosition(position);
        }

        void Shooting(vector<Bullet*> &bullet)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                bullet.push_back(new Bullet(position));
                Sound::PlaySound("shoot");
            }
        }

        sf::Vector2f GetPosition()
        {
            return position;
        }

        sf::Sprite GetSprite()
        {
            return sprite;
        }
};

#endif // PLAYER_H
