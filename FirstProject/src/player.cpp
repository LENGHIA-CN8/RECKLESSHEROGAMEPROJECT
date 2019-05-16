#include "player.h"
#include "entity.h"
#include "enemy.h"
player::player(Texture& texture,Vector2u imageCount,float switchTime)
{
    this->imageCount=imageCount;

    this->switchTime=switchTime;
    totalTime=0.0f;
    currentImage.x=0;
    uvRect.width=texture.getSize().x/float(imageCount.x);
    uvRect.height=texture.getSize().y/float(imageCount.y);
    font.loadFromFile("RushHeroFont.ttf");
    text.setFont(font);
    text.setString("0");
    text2.setFont(font);
    text2.setString("0");
    text3.setFont(font);
    text4.setFont(font);
    text4.setString("Press Enter To Continue !");
    //text score
    text.setCharacterSize(60);
    text.setPosition(280,150);
    //text current score
    text2.setCharacterSize(60);
    text2.setPosition(400,265);
    text2.setScale(0.8,0.8);
    //text high score
    text3.setCharacterSize(60);
    text3.setPosition(400,340);
    text3.setScale(0.8,0.8);
    text4.setCharacterSize(60);
    text4.setPosition(100,450);
    text4.setScale(0.5,0.5);
    //set hero sprite
    spritehero.setPosition(0,500);
    spritehero.setScale(1.2,1.2);
    spritehero.setTexture(texture);

}

player::~player()
{
    //dtor
}
void player::update(int row,float deltatime){
    currentImage.y=row;
    totalTime+=deltatime;
    if(totalTime>=switchTime){
        totalTime-=switchTime;
        currentImage.x++;
        if(currentImage.x >= imageCount.x){
            currentImage.x=0;
        }
    }
    uvRect.left= currentImage.x * uvRect.width;
    uvRect.top= currentImage.y * uvRect.height;
}
void player::reset(){
       spritehero.setOrigin(0,0);
       angle=-30.0f;
       spritehero.setRotation(0.0f);
       speeddeath=-1.5f;
       spritehero.setPosition(0,500);
}
void player::updatehighscore(){
    ifstream readFile;
    readFile.open("Highscore.txt");
    if(readFile.is_open()){
        while(!readFile.eof()){
            readFile >> highscore;
        }
    }
    readFile.close();
    ofstream writeFile("Highscore.txt");
    if(writeFile.is_open()){
        if(score > highscore){
            highscore=score;
        }
        writeFile << highscore;
    }
    writeFile.close();


}
