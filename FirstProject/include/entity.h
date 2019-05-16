#ifndef ENTITY_H
#define ENTITY_H
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace sf;
using namespace std;
class entity
{
    public:
        float top,bottom,left,right;
        Image image;
        Texture texture1,texture2,texturemedal;
        RectangleShape shape;
        Sprite sprite,sprite2,spritemedal;
        Text text,text2,text3,text4;
        Font font,font1;
        bool enablecount;
        IntRect uvRect;
        entity();
        ~entity();


    protected:

    private:
};

#endif // ENTITY_H
