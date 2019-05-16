#include "enemy.h"
using namespace std;
enemy::enemy()
{

    score=1;
    enemypos=sprite.getPosition();
    enemyvec=Vector2f(3,4);
    enemyacc=Vector2f(0,3);
    enablecount=true;
    //ctor
}

enemy::~enemy()
{
    //dtor
}
void enemy::Update(){
        sprite.setPosition(enemypos);
        sprite.setTextureRect(IntRect(0,0,54,50));
}
void enemy::Updatemovement(float dt){
        srand(time(NULL));
        float Posresety=rand()%300;
        enemypos=enemypos+enemyvec*(dt+0.02f);
        enemyvec=enemyvec+enemyacc*(dt+0.02f);
        if(enemypos.y>540) enemyvec.y=-(enemyvec.y);
        if(enemypos.y<-10) enablecount=true;
        if(enemypos.x>=700){
                enablecount=true;
                enemypos=Vector2f(0,Posresety);
        }
}
void enemy::Updatemovement1(float dt){
       float Posresety=rand()%400;
        enemypos.x=enemypos.x-enemyvec.x*(dt+0.01f);
        enemypos.y=enemypos.y+enemyvec.y*(dt+0.01f);
        enemyvec=enemyvec+enemyacc*(dt+0.01f);
        if(enemypos.y>540) enemyvec.y=-(enemyvec.y);
        if(enemypos.y<-10) enablecount=true;
        if(enemypos.x<=0){
                enablecount=true;
                enemypos=Vector2f(700,Posresety);
        }

}
void enemy::Draw(RenderWindow& window){
     window.draw(sprite);
}
