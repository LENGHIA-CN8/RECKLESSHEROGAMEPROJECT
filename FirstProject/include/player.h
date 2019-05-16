#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "enemy.h"
using namespace sf;
class player:public entity
{
    public:
        Sprite spritehero;
        player(Texture& texture,Vector2u imageCount,float switchTime);
        virtual ~player();
        void update(int row,float deltatime);
        void updatehighscore();
        void reset();
        int score=0;
        int highscore=0;
        int currentscore=63;
        bool playerdeath=false;
        float speeddeath=-1.5f;
        float angle=-30.0f;
//        bool Collision(enemy enemy1);
    protected:

    private:
        Vector2u imageCount;
        Vector2u currentImage;
        float totalTime;
        float switchTime;
};

#endif // PLAYER_H
