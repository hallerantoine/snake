#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "include/snake.h"
#include "include/background.h"
#include "include/internals.h"
#include "include/display.h"
#include "include/food.h"
#include "src/game.cpp"


int main(){
    snake snk;
    snk.create();
    background bg;
    bg.create();
    food fd;


    jeu(snk,bg,fd);

}