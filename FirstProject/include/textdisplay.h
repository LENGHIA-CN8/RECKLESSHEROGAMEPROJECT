#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "entity.h"
#include <string>

class textdisplay:public entity
{
    public:

        textdisplay();
        virtual ~textdisplay();
        void update();
        void updatesplash();
        void instruction();
        float movementspeed=0.1;
        int counter=0,counter1=0,counter2=0;
        int lifetime=500;
        int lifetime1=200,lifetime2=900;
        bool destroy=false;
        bool destroysplash=false;
        bool destroyinstruction=false;

};

#endif // TEXTDISPLAY_H
