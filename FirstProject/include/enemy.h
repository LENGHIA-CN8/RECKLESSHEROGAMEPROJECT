#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "entity.h"
using namespace sf;

class enemy:public entity
{
    public:
        enemy();
        virtual ~enemy();
        void Update();
        void Updatemovement(float dt);
        void Updatemovement1(float dt);
        void Draw(RenderWindow& window);
        Vector2f enemypos;
        int score;

    private:
        float Ranposx;
        int row;
        Vector2f enemyvec;
        Vector2f enemyacc;


};

#endif // ENEMY_H
