#ifndef COLLISION_H
#define COLLISION_H
#include "enemy.h"
#include "player.h"

class Collision
{
    public:
        Collision();
        virtual ~Collision();
        bool collided2(Sprite sprite1,float scale1,Sprite sprite2,float scale2 );
    protected:

    private:
};

#endif // COLLISION_H
