#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "include/snake.h"
#include "include/background.h"
#include "include/internals.h"
#include "include/display.h"
#include "include/food.h"



void jeu(snake snk,background bg,food fd){

    /*constantes*/
    const static int ny = 25;
    const static int nx = 50;
    const int lap=100;

    /*initialisations diverses*/

    char key='s';

    bool vivant=snk.isVivant();
    bool eat=false;

    /*nouvelle graine de l'aléatoire*/
    srand(time(NULL));

    /*initiation du snk et de la food*/

    int* pos=snk.getpos();
    int len=snk.getlen();
    fd.create(pos,len);

    int* fdpos=fd.get();
    bg.addfood(fdpos);



    while (vivant){
        internal::frameSleep(lap);
        /*gestion des mouvements*/
        if( internal::keyEvent() ){
            std::cin >> key;
        }
        /*décide la prochaine direciton*/
        snk.deplacement(key);
        /*déplace*/
        snk.mvt(key,eat);


        
        backgroundClear();

        /*ajout du snake sur le background*/
        int* pos=snk.getpos();
        int len=snk.getlen();
        bg.addsnake(len,pos);
   

        /*affichage*/
        int* grille=bg.getbg();
        printFrame(nx, ny, grille);

        /*eneleve le snake du background*/
        bg.removesnake(len,pos);


        /*gestion de la nourriture*/
        eat=snk.eat(fdpos);
        if (eat){
            fd.reset();
            fd.create(pos,len);
            fdpos=fd.get();
            bg.addfood(fdpos);
        }


        /*on vérifie qu'on peut continuer*/
        snk.check_vivant();
        vivant=snk.isVivant();
        if (vivant==false){
            std::cout<< "vous êtes mort" << std::endl;
        }




    }
}


int main(){
    snake snk;
    snk.create();
    background bg;
    bg.create();
    food fd;


    jeu(snk,bg,fd);

}