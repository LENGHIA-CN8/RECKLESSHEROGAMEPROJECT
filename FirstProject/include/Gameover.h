#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "entity.h"
#include "player.h"
using namespace sf;

class Gameover:public entity
{
    public:
        Gameover();
        virtual ~Gameover();
        void DrawGameOver(RenderWindow& window,int& _currentscore);
        void DrawPlayerDeath(RenderWindow& window,player& player1);
    protected:

    private:
};

#endif // GAMEOVER_H
