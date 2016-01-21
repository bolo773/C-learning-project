
#include "itemval.h"

//data files
FILE *data2;
FILE *mapdata;

//globalstuff

int parent_x;
int parent_y;


WINDOW * out;

WINDOW * in;

WINDOW * map;

WINDOW * stats;

WINDOW * bor;
//enemy values that are initialized during combat

struct enemy {

int max_health;

int damage;

int C_health;

int accuracy;

int hitdif;

};

//weapon values (outdated)
struct weapon{

int range;

int damage;

int accuracy;

int ammo_cap;

int melee;


};

//this is the possible enemies 
struct penemy{

char name[20];
int max_damage;
int max_health;
int accuracy;
int hitdif;

} monster[50];

// inventory


struct inventory  {


int amount[50];


};



//struct for player and possible npcs

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

int C_ammocap;
int C_ammotype;
int C_weapon_melee;
};

// impassible object in game world
struct mass {

int X;

int Y;

char name[20];

char description[100];

int impassible;

} object[100];



// a group of masses used to generate buildings
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


// necessary entities




struct inventory player_inv;

struct entity player;





// functions


//window creator

createw(){

getmaxyx(stdscr, parent_y, parent_x);
map = newwin(parent_y/2, parent_x/2,parent_y/2-3,0);
stats = newwin(parent_y/2, parent_x/2, parent_y/2-3,parent_x/2);
out = newwin(parent_y/2-5,parent_x-2,1,1);
bor = newwin(parent_y/2 - 3, parent_x,0,0);
in = newwin(3, parent_x, parent_y - 3,0);

wborder(map,'+','+','+','+','+','+','+','+');
wborder(stats,'+','+','+','+','+','+','+','+');
wborder(bor,'+','+','+','+','+','+','+','+');
wborder(in,'+','+','+','+','+','+','+','+');


idlok(out,TRUE);
scrollok(out,TRUE);
keypad(in,TRUE);

wrefresh(bor);
wrefresh(out);
wrefresh(in);
wrefresh(stats);
wrefresh(map);


}



//this function initializes the landscape and impassible objects
//(unfinished and unimplemented)
landscape(char *map){


mapdata = fopen(map,"r");

int x;

int y;

int i;

for( i=0;fscanf(mapdata,"%d %d",&x,&y)!= EOF;i++){

object[i].X = x;

object[i].Y = y;




}

fclose(mapdata);




}

//charecter creation function

charc(){


wprintw(out,"welcome to the charecter creation tool \n");



player.vitality = 20;
player.fitness = 20;
player.coordination = 20;
player.smarts = 20;




int i;
int a;
int b;
int w;

for(i=40;i>0;){
	wprintw(out,"vitality");
	for(b= player.vitality/5;b>0;b--){wprintw(out,"+");}
	wprintw(out,"\n");
	wprintw(out,"fitness");
	for(b= player.fitness/5;b>0;b--){wprintw(out,"+");}
	wprintw(out,"\n");
	wprintw(out,"smarts");
	for(b= player.smarts/5;b>0;b--){wprintw(out,"+");}
	wprintw(out,"\n");
	wprintw(out,"coordination");
	for(b= player.coordination/5;b>0;b--){wprintw(out,"+");}
	wprintw(out,"\n");
	


wprintw(out,"choos 1 to increase \n (1)vitality (2)fitness (3)smarts (4)coordination \n (%d left)",i);

wrefresh(out);




mvwscanw(in,1,1,"%d",&a);

wclear(out);




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
	wprintw(out,"unrecognized choice");
	break;
}


	
}


wprintw(out,"done \n ");









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
 
wclear(out);

wprintw(out,"resulting stats:\n");

wprintw(out,"small electronics: %d \n", player.small_electronics);
wprintw(out,"computers: %d \n",player.computers);
wprintw(out,"mechanics: %d \n",player.mechanics);
wprintw(out,"locksmith: %d \n",player.locksmith);
wprintw(out,"chemistry: %d \n", player.chemistry);
wprintw(out,"fighting: %d \n ", player.fighting);
wprintw(out,"shooting: %d \n", player.shooting);


wrefresh(out);

wprintw(out,"press any key to continue \n");
wgetch(in);

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


printw("current weapon %d",player.C_weapon);

printw("weapon damage: %d \n",player.weapon_damage);
printw("weapon range: %d \n",player.weapon_range);
printw("weapon accurracy: %d \n", player.weapon_range);

printw("ammo in gun:%d",player.C_ammo);
}

//this loads the information on the enemies

init_monsters(){
	data2 = fopen("enemylist.list","r");

	char name[20];
	int max_damage;
	int max_health;
	int accuracy;
	int hitdif;
	int a;
while(fscanf(data2,"%s %d  %d %d %d",name,&max_damage,&max_health,&accuracy,&hitdif)!= EOF){
strcpy(monster[a].name,name);
monster[a].max_damage = max_damage;
monster[a].max_health = max_health;
monster[a].accuracy = accuracy;
monster[a].hitdif = hitdif;
a++;
}
fclose(data2);
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
scanw("%d",&a);

if (a == 1){


printw("what item? \n ");

refresh();
scanw("%d",&a);

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

use(int itemnum ){

int i;
	switch(item[itemnum].type){
	case 1:
	if (player_inv.amount[itemnum] > 0){
	player.C_HP = player.C_HP + item[itemnum].mod;
	player_inv.amount[itemnum]--;
	printw("used item actually \n");
	}
	break;


	case 2:
		if((itemnum == player.C_ammotype) && player_inv.amount[itemnum]) {
				printw("ammo match \n");
				while(player.C_ammo != player.C_ammocap){
				player_inv.amount[itemnum]--;
				player.C_ammo ++;
			printw("used ammo");				
			}
		}

	break;
	
	case 3:

	if (player_inv.amount[itemnum]>0 && player.C_weapon != itemnum){
	
		if (player.C_weapon > 0 ) player_inv.amount[player.C_ammotype] = player_inv.amount[player.C_ammotype] + player.C_ammo;
	player.C_ammo = 0;

	player.C_ammotype = item[itemnum].ammotype;

	player.weapon_damage = item[itemnum].damage;

 	player.weapon_accuracy = item[itemnum].accuracy;

 	player.weapon_range = item[itemnum].range; 

	player.C_weapon = itemnum;
	
	player.C_ammocap = item[itemnum].ammocap;

	player.C_weapon_melee = item[itemnum].melee;
	
	printw("equipped weapon \n ");
	}
	break;

	default :
	break;
	}

	




}


// this function will do a few thiings:
//it will print out important information for the player nice and neat
//secondly it will provide a place where the player will make the //////majority of the choices



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
scanw("%d",&a);
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
scanw("%d",&a);
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

int roll = (rand()%3)+1;

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
	player_inv.amount[3] = player_inv.amount[3] + (rand()%20 + 1);
	printw("you found some pistol ammo \n ");
	break;
case 3: 
	player_inv.amount[7] = player_inv.amount[7] + (rand()%20 + 1);
	printw("you found some rifle ammo \n");
	break;
case 4:
	player_inv.amount[4] = player_inv.amount[4] + (rand()%20 + 1);
	printw("you found some shotgun shells \n");
	break;
case 5: 
	player_inv.amount[1]++;
	printw("you found a knife \n");
	break;
case 6:	
	player_inv.amount[8]++;
	printw("you found a bomb \n ");
	break;


default:
	break;

}

printw("press any key to continue \n ");
getch();


}


//combat function

combat(){


int a;

struct enemy enemy1 ;
			//make this random sometime (based on area)
enemy1.max_health = monster[0].max_health;
enemy1.C_health = monster[0].max_health;	
enemy1.damage = monster[0].max_damage;
enemy1.accuracy = monster[0].accuracy;
enemy1.hitdif = monster[0].hitdif;
//add 2 new properties hit difficulty and experience bonus

while (player.C_HP > 0){
printw("a %s appears \n",monster[0].name);
printw("its hp is %d",monster[0].max_health);
printw("What do you wawnt to do? \n ");

printw("(1) attack (2) run (3)item \n ");

refresh();
scanw("%d",&a);
clear();

switch(a){

case 1:
	if (player.C_weapon_melee){
		if((player.weapon_accuracy/2 +  player.fighting/2 + rand()%100) >= enemy1.hitdif){	

	enemy1.C_health = enemy1.C_health - ((player.fighting/4 + player.weapon_damage) + (rand() % (player.fighting/2)+1));}
	else {printw("you missed!! \n ");} 

	}

	if(player.C_weapon_melee != true){
		if(player.C_ammo > 0){
			if((player.weapon_accuracy/2 +  player.shooting/2 + rand()%100) >= 100){
			enemy1.C_health = enemy1.C_health - ((player.shooting/4 + player.weapon_damage) + (rand() % (player.shooting/2)+1));
			player.C_ammo--;
	}else{printw("you missed! \n");
			player.C_ammo--;}
	}
	}
	
	printw("enemy HP: %d \n", enemy1.C_health);
	break;
case 2:
	printw("you attempt to run.... \n " );
	if(rand()%100 > 50 ) return;
	else printf("it failed \n");
	break;

case 3:
	 printw("inventory stuff goes here.\n ");
	list_Pinv();
	break;

default:
	printw("something went wrong");
	break;


}

if (enemy1.C_health  <= 0 ) return;



player.C_HP = player.C_HP - ((rand() % enemy1.damage)/2 + enemy1.damage/2 );

if (player.C_HP <= 0 ) death();


printw(" HP: %d \n", player.C_HP );






}

}

//death function
death(){printw("you died");}


//level up function
levelup(){


player.level++;

player.xp_to_next = player.xp_to_next + player.level * player.xp_to_next/4;




}

