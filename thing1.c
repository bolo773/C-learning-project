#include "ncurses.h"
#include "definitions.h"

//main starting point

main (){



init_monsters();
itemload();




int a;


landscape("map1.map");

initscr();

createw();

player_inv.amount[0] = 1;
player_inv.amount[2] = 1;
player_inv.amount[3] = 40;
player_inv.amount[4]= 20;
player_inv.amount[5]= 1;

mvwprintw(out,1,1,"what would you like to do? (1)game (2)dev_godmode \n");

wrefresh(out);

mvwscanw(in,1,1,"%d",&a);

if(a == 1){

wprintw(out," warning game is very incomplete \n" );

wrefresh(out);
wgetch(in);

wclear(out);


charc();

}

else {


printw("dev_godmode enabled \n");
printw(" warning game is very incomplete \n" );
player.fitness = 100;
player.vitality = 100;
player.smarts = 100;
player.coordination = 100;

getch();

clear();


plot();

}



}



















