#include "ncurses.h"
#include "stdio.h"
#include "stdlib.h"
#include "itemval.h"






//enemy

struct enemy {

int health;

int damage;

};


struct weapon{

int range;

int damage;

int accuracy;

int ammo_cap;

};


// inventory


struct inventory  {


int amount[50];


};

struct inventory player_inv;




//struct for all living things

struct entity {


// charecter stats 



//basic stats
//determines how much xp charecter earns and how well he can do pretty much anything from making things to climbing. adds a small bonus to all skills.

int smarts;

//determines hitpoints, capacity to do physical work,  and mele damage among other skills.

int fitness;

// determines healing rate, immunity to disease, and reduces negative affects of drugs.

int vitality;

//determines preciseness of hand movements

int coordination;



//charecter skills

//improving skills can improve your base stats for example using a sword will make you stronger

//chance of successfully completing a task is based on the task difficulty and the players skill
// chance = player skill divided by difficulty max player skill is 100 
//skill difficulties



// actual skill bases

int small_electronics_base;
int computers_base;
int mechanics_base;
int locksmith_base;
int chemistry_base;
int fighting_base;
int shooting_base;




//final skill values

int small_electronics;
int computers;
int mechanics;
int locksmith;
int chemistry;
int fighting;
int shooting;



// other values 

int HP;
int C_HP;
int regen;
int imunity;


//experience 

int level;

int xp;

int xp_to_next;

//position values

int X;
int Y;





//weapon values




int weapon_damage;

int weapon_accuracy;

int weapon_range;

int C_ammo;

int C_weapon;

};



struct mass {

int X;

int Y;

char name[20];

char description[100];

int impassible;

} object[100];




//used to generate large structure


struct proto_struct{

int X;

int Y;

int Nside[2];
int Eside[2];
int Sside[2];
int Wside[2];

char name[20];

char description[100];

};












//this function initializes the landscape and impassible objects

landscape(){
	
object[0].X=1;
object[0].Y=2;




}




struct entity player;


//main starting point

main (){

itemload();

int a;


landscape();

initscr();

player_inv.amount[0] = 1;
player_inv.amount[2] = 1;
player_inv.amount[3] = 40;

printw("what would you like to do? (1)game (2)dev_godmode \n");

refresh();

scanf("%d",&a);

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






// this is the charecter creation function
charc(){


printw("welcome to the charecter creation tool \n");



player.vitality = 20;
player.fitness = 20;
player.coordination = 20;
player.smarts = 20;




int i;
long a;
int b;

for(i=40;i>0;){
	printw("\n \n \n \n \n \n \n \n \n \n \n \n \n ");

	
	printw("vitality");
	for(b= player.vitality/5;b>0;b--){printw("+");}
	printw("\n");
	printw("fitness");
	for(b= player.fitness/5;b>0;b--){printw("+");}
	printw("\n");
	printw("smarts");
	for(b= player.smarts/5;b>0;b--){printw("+");}
	printw("\n");
	printw("coordination");
	for(b= player.coordination/5;b>0;b--){printw("+");}
	printw("\n");
	


printw("choos 1 to increase \n (1)vitality (2)fitness (3)smarts (4)coordination \n (%d left)",i);

refresh();


scanf("%li",&a);

clear();


if (a<1 || a>4) continue;

switch(a){
case 1:
	player.vitality++;
	i--;
	break;
case 2:
	player.fitness++;
	i--;
	break;
case 3:
	player.smarts++;
	i--;
	break;
case 4:
	player.coordination++;
	i--;
	break;
default:
	printw("unrecognized choice");
	break;
}


	
}


printw("done \n ");









player.small_electronics = player.small_electronics_base + player.smarts/2;
player.computers= player.computers_base + player.smarts/2;
player.mechanics = player.mechanics_base + player.smarts/2;
player.locksmith = player.locksmith_base + player.smarts/4 + player.coordination/4;
player.chemistry = player.chemistry_base +player.smarts/2;
player.fighting  = player.fighting_base + player.smarts/4 + player.fitness/4;
player.shooting = player.shooting_base + player.smarts/4 + player.coordination/4;


player.HP = player.fitness;
player.regen = player.fitness/4;
player.imunity = player.vitality;
 
clear();

printw("resulting stats:\n");

printw("small electronics: %d \n", player.small_electronics);
printw("computers: %d \n",player.computers);
printw("mechanics: %d \n",player.mechanics);
printw("locksmith: %d \n",player.locksmith);
printw("chemistry: %d \n", player.chemistry);
printw("fighting: %d \n ", player.fighting);
printw("shooting: %d \n", player.shooting);


refresh();

printw("press any key to continue \n");
getch();

plot();




}




//lists player stats

liststats(){

printw("small electronics: %d \n",player.small_electronics);
printw("computers: %d \n", player.computers);
printw("mechanics: %d \n",player.mechanics);
printw("locksmithing: %d \n",player.locksmith);
printw("chemistry: %d \n",player.chemistry);
printw("fighting: %d \n",player.fighting);
printw("shooting: %d \n",player.shooting);


printw("weapon damage: %d \n",player.weapon_damage);
printw("weapon range: %d \n",player.weapon_range);
printw("weapon accurracy: %d \n", player.weapon_range);

printw("ammo in gun:%d",player.C_ammo);
}



//this will list the inventory

list_Pinv(){

int e = 0;
int a;
int i;
int b;

clear();


for(b = 0; b<51;b++)
	if(player_inv.amount[b]) {


printw("%s:%d \n",item[b].name,player_inv.amount[b]);

	e++;

	item[b].callnum = e;
}




printw("what would you like to do? \n");
printw(" (1) use  (2) nothing \n ");

refresh();
scanf("%d",&a);

if (a == 1){


printw("what item? \n ");

refresh();
scanf("%d",&a);

	for(i=0; i < 51; ){
		if( item[i].callnum == a) {
			printw("found item \n");
			use(i);
			
		
		}

i++;


}

}
printw("press any key to continue");
getch();

return;
}


//this function is used to use items
//sssssssssssssss
//ssssssssssssss
use(int itemnum ){


int i;
	switch(item[itemnum].type){
	case 1:
	player.C_HP = player.C_HP + item[itemnum].mod;
	player_inv.amount[itemnum]--;
	printw("used item actually \n");
	break;


	case 2:
	for(i=player_inv.amount[itemnum]; (i > 0) && ((player.C_ammo -1) < item[itemnum].ammocap); i--){
		if(item[itemnum].weapon == player.C_weapon) {
				player.C_ammo++;
				player_inv.amount[itemnum]--;
			}
		}
	printw("used ammo \n");
	break;
	
	case 3:

	player.weapon_damage = item[itemnum].damage;

 	player.weapon_accuracy = item[itemnum].accuracy;

 	player.weapon_range = item[itemnum].range; 

	player.C_ammo = item[itemnum].ammocap;

	player.C_weapon = itemnum;
	
	break;

	default :
	break;
	}

	




}




// this function will do a few thiings:
//it will print out important information for the player nice and neat
//secondly it will provide a place where the player will make the majority of the choices

int plot(){

player.C_HP = player.HP;
player.X=0;
player.Y=0;

int a;

while(player.C_HP>0){

a = 0;

printw("Health: %d / %d \n ",player.C_HP,player.HP);

printw("What to do?: (1)go (2)open inventory (3)scavange (4) quit game (5) list stats \n");

refresh();
scanf("%d",&a);
clear();

switch(a){
case 1:
	shift();
	break;
case 2: 
	list_Pinv();
	break;

case 3:
	

case 4:
	endwin();
	return 1;
	
case 5:
	liststats();
	break;
default:
	break;



}



}


}

//this is the movement function for the main charecter

shift(){

int a;
int i;

printw("move where? \n ");
printw("(1)right  (2)left  (3)down  (4)up  \n");

refresh();
scanf("%d",&a);
clear();

switch (a){
case 1:
	for(i=0; i<101; i++){
	if(((object[i].X) == player.X+1) && (object[i].Y== player.Y)){
		printw("cant go there something in way");
		break;}
		}
	

	if (i==101) player.X++;
	break;
case 2:
	for(i=0; i<101; i++){
	if(((object[i].X) == player.X-1) && (object[i].Y== player.Y)){
		printw("cant go there something in way");
		break;}
		}
	if (i==101 )player.X--;
	break;
case 3:
	for(i=0; i<101; i++){
	if(((object[i].X) == player.X) && (object[i].Y == player.Y-1)){
		printw("cant go there something in way");
		break;}
		}

	if(i==101) player.Y--;
	break;
case 4:
	for(i=0; i<101; i++){
	if(((object[i].X) == player.X) && (object[i].Y== player.Y+1)){
		printw("cant go there something in way");
		break;}
		}
	if(i == 101) player.Y++;
	break;
default:
	break;

}

printw("position %d,%d \n ",player.X,player.Y);
encounter();

}



//this function rolls for random encounter

encounter(){

int roll = (rand()%5)+1;

switch(roll){

case 1:
	printw("encounter 1 will be combat \n ");
	combat();
	break;
case 2:
	printw("encounter 2 will be an obstacle or trap \n ");
	break;

case 3:
	printw("encounter 3 will be some sort fo low grade loot \n ");
	looting();
	break;
case 4: 
	printw("encounter 4 willl be some sort of useful loot like food or bandages \n ");
	break;
case 5:
	printw("encounter 5 will be some larger amount of 4's loot \n ");
	break;
case 6: 
	printw("encounter 6 will be a new weapon or high grade loot \n");

default:
	printw("something has gone wrong");
	break;

refresh();


}


}



//split this function into 2 parts
looting(){

int a = (rand()%6 +1);

switch(a){

case 1:
	player_inv.amount[0]++;
	printw("you found some bandages \n ");
	break;
case 2: 
	player_inv.amount[7] = player_inv.amount[7] + (rand()%20 + 1);
	printw("you found some pistol ammo \n ");
	break;
case 3: 
	player_inv.amount[8] = player_inv.amount[8] + (rand()%20 + 1);
	printw("you found some rifle ammo \n");
	break;
case 4:
	player_inv.amount[6] = player_inv.amount[6] + (rand()%20 + 1);
	printw("you found some shotgun shells \n");
	break;
case 5: 
	player_inv.amount[1]++;
	printw("you found a knife \n");
	break;
case 6:	
	player_inv.amount[5]++;
	printw("you found a bomb \n ");
	break;


default:
	break;

}

printw("press any key to continue \n ");
getch();


}





combat(){


int a;

struct enemy enemy1 ;

enemy1.health = 30;

enemy1.damage = 6;



while (player.C_HP > 0){

printw("What do you wawnt to do? \n ");

printw("(1) attack (2) run (3)item \n ");

refresh();

scanf("%d",&a);

switch(a){

case 1:
	enemy1.health = enemy1.health - ((player.fighting/2) + (rand() % (player.fighting/2)+1));
	printw("enemy HP: %d \n", enemy1.health);
	break;
case 2:
	printw("you attempt to run.... \n " );
	return;

case 3:
	 printw("inventory stuff goes here.\n ");
	break;

default:
	printw("something went wrong");
	break;


}

if (enemy1.health  <= 0 ) return;



player.C_HP = player.C_HP - (rand() % enemy1.damage +1 );

if (player.C_HP <= 0 ) death();


printw(" HP: %d \n", player.C_HP );






}

}


death(){printw("you died");}

levelup(){


player.level++;

player.xp_to_next = player.xp_to_next + player.level * player.xp_to_next/4;




}
