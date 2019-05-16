#include "textdisplay.h"

textdisplay::textdisplay()
{
    font.loadFromFile("RushHeroFont.ttf");
    text.setFont(font);
    text.setColor(Color::White);
    text.setCharacterSize(30);
    font1.loadFromFile("Pacifico.ttf");
    text2.setFont(font1);
    text2.setColor(Color::White);
    text2.setCharacterSize(30);
    text2.setString("Use <= && => to move the hero");
    text2.setPosition(100,80);
    text3.setFont(font1);
    text3.setColor(Color::White);
    text3.setCharacterSize(30);
    text3.setString("Watch out for falling rocks!!");
    text3.setPosition(120,120);

    //ctor
}

textdisplay::~textdisplay()
{
    //dtor
}
void textdisplay::instruction(){
    counter2++;
    if(counter2>=lifetime2){
        destroyinstruction=true;
    }
}
void textdisplay::update(){
    text.move(0,-movementspeed);
    counter++;
    if(counter>=lifetime){
        destroy=true;
    }
}
void textdisplay::updatesplash(){
    counter1++;
    if(counter1>=lifetime1){
        destroysplash=true;
    }
}
