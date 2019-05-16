#include "Collision.h"
#include "enemy.h"
#include "player.h"
#include "entity.h"
Collision::Collision()
{
    //ctor
}

Collision::~Collision()
{
    //dtor
}
bool Collision::collided2(Sprite sprite1,float scale1,Sprite sprite2,float scale2 ){
     sprite1.setScale(scale1,scale2);
     sprite2.setScale(scale1,scale2);
     Rect<float> rect1=sprite1.getGlobalBounds();
     Rect<float> rect2=sprite2.getGlobalBounds();
     if(rect1.intersects(rect2)){
        return true;
     }else{
       return false;
     }
}
