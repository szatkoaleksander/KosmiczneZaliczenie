#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
    private:
        Collision() {}

    public:
        static bool DetectingCollision(Object *obj1, Object *obj2)
        {
            if(obj1->GetPosition().x < obj2->GetPosition().x + 38 &&
               obj1->GetPosition().x > obj2->GetPosition().x - 38 &&
               obj1->GetPosition().y < obj2->GetPosition().y + 38 &&
               obj1->GetPosition().y > obj2->GetPosition().y - 38)
                return 1;
            else
                return 0;
        }
};

#endif // COLLISION_H
