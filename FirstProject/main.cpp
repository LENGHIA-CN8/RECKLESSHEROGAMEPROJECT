#include <SFML/Graphics.hpp>
#include <iostream>
#include <bits/stdc++.h>
#include "player.h"
#include "enemy.h"
#include "textdisplay.h"
#include <conio.h>
#include <windows.h>
#include "Collision.h"
#include "Gameover.h"
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;
int width=600;
int height=700;
bool gamepause=false,gamestart=false,gameover=false;
bool active=false;
enum Direction{ Left,Right };
int main()
{

    RenderWindow window(VideoMode(600, 700), "RecklessHero",Style::Default);
    //start_game
    Texture game_brand;
    Texture start_button;
    game_brand.loadFromFile("start_game.png");
    start_button.loadFromFile("playbutton.png");
    Sprite button_play;
    Sprite gamebrand;
    button_play.setTexture(start_button);
    gamebrand.setTexture(game_brand);
    gamebrand.setPosition(120,100);
    gamebrand.setScale(1.2,1.2);
    button_play.setPosition(160,250);
    button_play.setScale(0.8,0.8);
    //enemy
    vector<enemy> enemyarray;
    vector<enemy>::iterator iter;
    Texture fire;
    fire.loadFromFile("Rocks.png");
    enemy enemy1;
    enemy1.sprite.setTexture(fire);
    //setup rocks
    for(int i=0;i<15;i++){
           float Ranposx=rand()% 500+100;
           enemy1.enemypos.x=Ranposx;
           enemy1.enemypos.y=0;
           enemyarray.push_back(enemy1);
       }
    // text
    vector<textdisplay>::iterator iter2;
    vector<textdisplay> textdisplayarray;
    textdisplay textdisplay1;
    //splash_effect
    vector<textdisplay>::iterator iter4;
    vector<textdisplay> splasharray;
    textdisplay splash_effect;
    Texture splash;
    splash.loadFromFile("sss3.png");
    splash_effect.sprite.setTexture(splash);
    //background
    Texture background;
    background.loadFromFile("background2.png");
    Sprite sprite(background,IntRect(0,0,1920,1000));
    //hero
    Texture hero;
    hero.loadFromFile("heroanimation.png");
    //hero animation
    player player1(hero,Vector2u(3,2),0.3f );
    //time
    float deltatime=0.0f;
    Clock clock;
    Vector2f backgroundpos[2]={{0,0},{600,0}};
    Vector2i source(0,Left);
    //collision class
    Collision collided1;
    //game over setup
    Gameover gameoverstate;
    //sound effect
    SoundBuffer bufferrocks;
    SoundBuffer buferscream;
    SoundBuffer bufferfire;
    SoundBuffer bufferclick;
    bufferrocks.loadFromFile("Splash_Small.wav");
    buferscream.loadFromFile("scream.wav");
    bufferfire.loadFromFile("jungle.wav");
    bufferclick.loadFromFile("Button.wav");
    Sound soundrock;
    Sound screamsound;
    Sound soundfire;
    Sound clicksound;
    soundrock.setBuffer(bufferrocks);
    screamsound.setBuffer(buferscream);
    soundfire.setBuffer(bufferfire);
    clicksound.setBuffer(bufferclick);
    soundfire.play();
    soundfire.setLoop(true);
    while (window.isOpen())
    {
        deltatime=clock.restart().asSeconds();
        //cout<<deltatime<<endl;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Escape)
                    window.close();
            }
            if(event.type ==Event::KeyPressed){
                if(gameover==true){
                if(event.key.code == Keyboard::Return){
                    textdisplay1.destroyinstruction=false;
                    textdisplay1.counter2=0;
                    gameover=false;
                    active=true;
                    window.clear();
                }
                    }
            }
            if(event.type ==Event::MouseButtonPressed){
                if(gamestart==false){
                if(event.mouseButton.y>=200){
                        gamestart=true;
                        clicksound.play();
            }
            }
            }


        }
        if(!gameover){
        if((Keyboard::isKeyPressed(Keyboard::Key::Right))&&((player1.spritehero.getPosition().x+75) <  width)){

            player1.spritehero.move(1.2,0.0);
            source.y=Right;

        }
        if((Keyboard::isKeyPressed(Keyboard::Key::Left))&&(player1.spritehero.getPosition().x>-8)){

            player1.spritehero.move(-1.21,0.0);
            source.y=Left;

        }
        }
        window.clear();
if(gamestart==true){
//collision with player
        int counter=0;
if(gameover==false){
        for(iter=enemyarray.begin();iter!=enemyarray.end();iter++){
            if(collided1.collided2(enemyarray[counter].sprite,0.8f,player1.spritehero,1.0f)){
               screamsound.play();
               player1.currentscore=player1.score;
               player1.updatehighscore();
               player1.text2.setString(to_string(player1.currentscore));
               player1.text3.setString(to_string(player1.highscore));
               player1.spritehero.move(0,10.0f);
               player1.playerdeath=true;
               gameover=true;
               active=false;
               break;
            }
            counter++;
        }
        }
//collision ground
        counter=0;
        for(iter=enemyarray.begin();iter!=enemyarray.end();iter++){
                if(enemyarray[counter].sprite.getPosition().y>=540){
                        if(gameover==false){
                    soundrock.play();
                    //enemyarray[counter].sprite.rotate(50);
                    textdisplay1.text.setString("+1");
                    textdisplay1.text.setPosition(enemyarray[counter].sprite.getPosition().x,enemyarray[counter].sprite.getPosition().y);
                    splash_effect.sprite.setPosition(enemyarray[counter].sprite.getPosition().x,enemyarray[counter].sprite.getPosition().y);
                    splasharray.push_back(splash_effect);
                    if(enemyarray[counter].enablecount==true){
                            textdisplayarray.push_back(textdisplay1);
                            player1.score++;
                            enemyarray[counter].enablecount=false;
                    }
                    player1.text.setString(to_string(player1.score));
                        }
                }
                counter++;
        }
 //delete text
         counter=0;
        for(iter2=textdisplayarray.begin();iter2!=textdisplayarray.end();iter2++){
                    if(textdisplayarray[counter].destroy==true){
                        textdisplayarray.erase(iter2);
                        break;
                    }
                    counter++;
        }
//delete splash
         counter=0;
         for(iter4=splasharray.begin();iter4!=splasharray.end();iter4++){
                    if(splasharray[counter].destroysplash==true){
                        splasharray.erase(iter4);
                        break;
                    }
                    counter++;
        }

//update player
        player1.update(source.y,deltatime);
        player1.spritehero.setTextureRect(player1.uvRect);

//draw background
        for(int i=0;i<2;i++){
            backgroundpos[i].x -= 0.5;
            if(backgroundpos[i].x <= -1920 ) backgroundpos[i].x=600;
            sprite.setPosition(backgroundpos[i].x,0);
            window.draw(sprite);
        }
//draw enemy
   if(active){
        counter=0;
        for(iter=enemyarray.begin();iter!=enemyarray.end();iter++){
            float Ranposx=rand()% 500+100;
            enemyarray[counter].enemypos.x=Ranposx;
            enemyarray[counter].enemypos.y=0;
            enemyarray[counter].enablecount=true;
            counter++;
            active=false;
            gameover=false;
            player1.text.setString(to_string(player1.score=0));

       }
       player1.reset();
    } else {
        for(int i=0;i<15;i++){
        if(i<=5){
        enemyarray[i].Update();
        enemyarray[i].Updatemovement(deltatime);
        } else {
        enemyarray[i].Update();
        enemyarray[i].Updatemovement1(deltatime);
        }
        enemyarray[i].Draw(window);
    }
    }

    if(gameover==false){
//draw instruction
        if(textdisplay1.destroyinstruction==false){
                textdisplay1.instruction();
                window.draw(textdisplay1.text2);
                window.draw(textdisplay1.text3);
        }
//draw hero
        window.draw(player1.spritehero);

//draw text and splash
        counter=0;
        for(iter2=textdisplayarray.begin();iter2!=textdisplayarray.end();iter2++){
            textdisplayarray[counter].update();
            window.draw(textdisplayarray[counter].text);
            counter++;
        }
//draw splash
       counter=0;
        for(iter4=splasharray.begin();iter4!=splasharray.end();iter4++){
            splasharray[counter].updatesplash();
            window.draw(splasharray[counter].sprite);
            counter++;
        }
//draw score
        window.draw(player1.text);
    } else if(player1.playerdeath){
        gameoverstate.DrawPlayerDeath(window,player1);

    } else if(player1.playerdeath==false && gameover==true) {
// draw game over state
        gameoverstate.DrawGameOver(window,player1.currentscore);
        window.draw(player1.text2);
        window.draw(player1.text3);
        window.draw(player1.text4);
    }
    } else {
        for(int i=0;i<2;i++){
            backgroundpos[i].x -= 0.5;
            if(backgroundpos[i].x <= -1920 ) backgroundpos[i].x=600;
            sprite.setPosition(backgroundpos[i].x,0);
            window.draw(sprite);
        }
        window.draw(button_play);
        window.draw(gamebrand);
    }

    window.display();

    }


    return 0;
}

