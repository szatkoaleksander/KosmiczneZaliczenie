#ifndef BULLET_H
#define BULLET_H

class Bullet : public Object
{
    private:

    public:
        Bullet(sf::Vector2f pos)
        {
            texture.loadFromFile("gfx/bullet.png");
            sprite.setTexture(texture);
            sprite.setOrigin(16, 16);

            speed = 0.13;

            position.x = pos.x;
            position.y = pos.y;
        }
        virtual ~Bullet() {}

        void BulletMovement(double FPS)
        {
            position.y -= speed * FPS;

            sprite.setPosition(position);
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

#endif // BULLET_H
