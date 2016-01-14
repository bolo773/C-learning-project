#include "ncurses.h"
#include "definitions.h"

//main starting point

main (){


init_monsters();
itemload();




int a;


landscape();

initscr();



player_inv.amount[0] = 1;
player_inv.amount[2] = 1;
player_inv.amount[3] = 40;
player_inv.amount[4]= 20;
player_inv.amount[5]= 1;
printw("what would you like to do? (1)game (2)dev_godmode \n");

refresh();

scanw("%d",&a);

if(a == 1){

printw(" warning game is very incomplete \n" );


getch();

clear();


charc();

}

else {


printw("dev_godmode enabled \n");

}



}



















