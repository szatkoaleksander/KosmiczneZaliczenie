#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Object
{
    private:

    public:
        Enemy()
        {
            int tex = (rand() % 3) + 1;
            if(tex == 1)
                texture.loadFromFile("gfx/e1.png");
            else if(tex == 2)
                texture.loadFromFile("gfx/e2.png");
            else if(tex == 3)
                texture.loadFromFile("gfx/e3.png");

            sprite.setTexture(texture);
            sprite.setOrigin(24, 24);

            speed = 0.05;

            position.x = (rand() % 800) + 1;
            position.y = - (rand() % 4000) + 1;;
        }

        virtual ~Enemy() {}

        void Movement(double FPS)
        {
            position.y += speed * FPS;

            sprite.setPosition(position);
        }

        void SetSpeed(double speed)
        {
            this->speed = speed;
        }

        double GetSpeed()
        {
            return speed;
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

#endif // ENEMY_H
