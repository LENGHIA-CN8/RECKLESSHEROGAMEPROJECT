#include "Gameover.h"
#include "player.h"
Gameover::Gameover()
{
    texture1.loadFromFile("GameOverTitle.png");
    texture2.loadFromFile("GameOverBody.png");
    texturemedal.loadFromFile("prize.png");
    sprite.setTexture(texture1);
    sprite.setPosition(70,100);
    sprite2.setTexture(texture2);
    sprite2.setScale(0.8,0.8);
    sprite2.setPosition(80,200);
    spritemedal.setTexture(texturemedal);
    spritemedal.setScale(0.8,0.8);
    spritemedal.setPosition(130,280);

    //ctor
}

Gameover::~Gameover()
{
    //dtor
}
void Gameover::DrawPlayerDeath(RenderWindow& window,player& player1){
     if(player1.playerdeath==true){
        player1.spritehero.setOrigin(30.0f,30.0f);
        player1.spritehero.rotate(player1.angle);
        player1.spritehero.move(-0.5f,player1.speeddeath);
        if(player1.spritehero.getPosition().y <= 400){
                player1.speeddeath=-(player1.speeddeath);
                player1.spritehero.setRotation(-30.0f);
                player1.angle=0.0f;
        }

        if(player1.spritehero.getPosition().x <= 0){
                player1.playerdeath=false;
        }
     }
     sleep(milliseconds(2));
     window.draw(player1.spritehero);
}
void Gameover::DrawGameOver(RenderWindow& window,int& _currentscore){
    window.draw(sprite);
    window.draw(sprite2);
    if(_currentscore>=500&&_currentscore<=1000){
        spritemedal.setTextureRect(IntRect(170,0,180,200));
    } else if(_currentscore<=500){
        spritemedal.setTextureRect(IntRect(360,0,180,200));
    } else {
        spritemedal.setTextureRect(IntRect(0,0,180,200));
    }
    window.draw(spritemedal)
    ;
}
