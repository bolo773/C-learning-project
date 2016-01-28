
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

WINDOW * bor2;

WINDOW * bor3;

WINDOW * bor4;
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
map = newwin(parent_y/2-2, parent_x/2-2,parent_y/2-2,1);
stats = newwin(parent_y/2-2, parent_x/2-2, parent_y/2-2,parent_x/2+1);
out = newwin(parent_y/2-5,parent_x-2,1,1);
in = newwin(3, parent_x, parent_y-3,0);
//out window border
bor = newwin(parent_y/2 - 3, parent_x,0,0);
//map border
bor2 = newwin(parent_y/2, parent_x/2,parent_y/2-3,0);
//stats border
bor3 = newwin(parent_y/2, parent_x/2, parent_y/2-3,parent_x/2);
//in border
bor4 = newwin(3, parent_x, parent_y - 3,0);




wborder(bor,'+','+','+','+','+','+','+','+');

wborder(bor2,'+','+','+','+','+','+','+','+');
wborder(bor3,'+','+','+','+','+','+','+','+');
wborder(bor4,'+','+','+','+','+','+','+','+');
idlok(out,TRUE);
scrollok(out,TRUE);
keypad(in,TRUE);



wrefresh(bor);
wrefresh(bor2);
wrefresh(bor3);
wrefresh(bor4);
wrefresh(out);
wrefresh(in);
wrefresh(stats);
wrefresh(map);


}

cgamewindows(){

wclear(out);
wclear(in);
wclear(stats);
wclear(map);



}
rgamewindows(){

wrefresh(bor);
wrefresh(bor2);
wrefresh(bor3);
wrefresh(bor4);
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



//map drawing function
drawmap(){


int cpx; 
int cpy;
int i;
int q;
int c;
int emptys;
cpy = player.Y+4;

for(q=0; q<=8;q++){

	for(emptys = 0; emptys <= ((parent_x/2-9)/2);emptys++) wprintw(map," ");
 cpx = player.X-4;
	for(i = 0;i<=8;i++){
		for(c=0;c<=100;c++){
			if ((object[c].X==cpx)&&(object[c].Y==cpy)){
			wprintw(map,"X");
			break;
				}
			}
		if (c==101) wprintw(map,"O");
		cpx++;
			}
		
wprintw(map,"\n");


cpy--;

}





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

cgamewindows();
plot();




}


//lists player stats

liststats(){

wprintw(out,"small electronics: %d \n",player.small_electronics);
wprintw(out,"computers: %d \n", player.computers);
wprintw(out,"mechanics: %d \n",player.mechanics);
wprintw(out,"locksmithing: %d \n",player.locksmith);
wprintw(out,"chemistry: %d \n",player.chemistry);
wprintw(out,"fighting: %d \n",player.fighting);
wprintw(out,"shooting: %d \n",player.shooting);


wprintw(out,"current weapon %d",player.C_weapon);

wprintw(out,"weapon damage: %d \n",player.weapon_damage);
wprintw(out,"weapon range: %d \n",player.weapon_range);
wprintw(out,"weapon accurracy: %d \n", player.weapon_range);

wprintw(out,"ammo in gun:%d",player.C_ammo);
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


wprintw(out,"%s:%d \n",item[b].name,player_inv.amount[b]);

	e++;

	item[b].callnum = e;
}




wprintw(out,"what would you like to do? \n");
wprintw(out," (1) use  (2) nothing \n ");

rgamewindows();
mvwscanw(in,1,1,"%d",&a);

if (a == 1){


wprintw(out,"what item? \n ");

rgamewindows();
mvwscanw(in,1,1,"%d",&a);

	for(i=0; i < 51; ){
		if( item[i].callnum == a) {
			wprintw(out,"found item \n");
			use(i);
			
		
		}

i++;


}

}
wprintw(out,"press any key to continue");
wgetch(in);

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
	wprintw(out,"used item actually \n");
	}
	break;


	case 2:
		if((itemnum == player.C_ammotype) && player_inv.amount[itemnum]) {
				wprintw(out,"ammo match \n");
				while(player.C_ammo != player.C_ammocap){
				player_inv.amount[itemnum]--;
				player.C_ammo ++;
			wprintw(out,"used ammo \n");				
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
	
	wprintw(out,"equipped weapon \n ");
	}
	break;

	default :
	break;
	}

	




}


// this function will do a few thiings:
//it will print out important information for the player nice and neat
//secondly it will provide a place where the player will make the //////majority of the choices


int printstats(){


wprintw(stats,"Health: %d / %d \n ",player.C_HP,player.HP);



}


int plot(){


player.C_HP = player.HP;
player.X=0;
player.Y=0;


while(player.C_HP>0){



printstats();

wprintw(out,"type 'help' for a list of commands");
drawmap();
rgamewindows();
command();

cgamewindows();




}



}


//this is the movement function for the main charecter

shift( int a){

int i;
drawmap();
printstats();


rgamewindows();

clear();

switch (a){
case 1:
	for(i=0; i<101; i++){
	if(((object[i].X) == player.X+1) && (object[i].Y== player.Y)){
		wprintw(out,"cant go there something in way \n");
		break;}
		}
	

	if (i==101) player.X++;
	break;
case 2:
	for(i=0; i<101; i++){
	if(((object[i].X) == player.X-1) && (object[i].Y== player.Y)){
		wprintw(out,"cant go there something in way\n");
		break;}
		}
	if (i==101 )player.X--;
	break;
case 3:
	for(i=0; i<101; i++){
	if(((object[i].X) == player.X) && (object[i].Y == player.Y-1)){
		wprintw(out,"cant go there something in way\n");
		break;}
		}

	if(i==101) player.Y--;
	break;
case 4:
	for(i=0; i<101; i++){
	if(((object[i].X) == player.X) && (object[i].Y== player.Y+1)){
		wprintw(out,"cant go there something in way \n");
		break;}
		}
	if(i == 101) player.Y++;
	break;
default:
	break;

}

wprintw(out,"position %d,%d \n ",player.X,player.Y);
encounter();

}



//this function rolls for random encounter

encounter(){

int roll = (rand()%3)+1;

switch(roll){

case 1:
	wprintw(out,"encounter 1 will be combat \n ");
	combat();
	break;
case 2:
	wprintw(out,"encounter 2 will be an obstacle or trap \n ");
	break;

case 3:
	wprintw(out,"encounter 3 will be some sort fo low grade loot \n ");
	looting();
	break;



default:
	wprintw(out,"something has gone wrong");
	break;

refresh();


}


}



//split this function into 2 parts
//make it so it uses the name stored in item.name
looting(){
cgamewindows();
int a = (rand()%6 +1);

switch(a){

case 1:
	player_inv.amount[0]++;
	wprintw(out,"you found some bandages \n ");
	break;
case 2: 
	player_inv.amount[3] = player_inv.amount[3] + (rand()%20 + 1);
	wprintw(out,"you found some pistol ammo \n ");
	break;
case 3: 
	player_inv.amount[7] = player_inv.amount[7] + (rand()%20 + 1);
	wprintw(out,"you found some rifle ammo \n");
	break;
case 4:
	player_inv.amount[4] = player_inv.amount[4] + (rand()%20 + 1);
	wprintw(out,"you found some shotgun shells \n");
	break;
case 5: 
	player_inv.amount[1]++;
	wprintw(out,"you found a knife \n");
	break;
case 6:	
	player_inv.amount[8]++;
	wprintw(out,"you found a bomb \n ");
	break;


default:
	break;

}

rgamewindows();
wprintw(out,"press any key to continue \n ");
wgetch(in);


}


//combat function

combat(){

cgamewindows();

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

drawmap();
printstats();

wprintw(out,"a %s appears \n",monster[0].name);
wprintw(out,"its hp is %d",monster[0].max_health);
wprintw(out,"What do you wawnt to do? \n ");

wprintw(out,"(1) attack (2) run (3)item \n ");

rgamewindows();
mvwscanw(in,1,1,"%d",&a);
cgamewindows();

switch(a){

case 1:
	if (player.C_weapon_melee){
		if((player.weapon_accuracy/2 +  player.fighting/2 + rand()%100) >= enemy1.hitdif){	

	enemy1.C_health = enemy1.C_health - ((player.fighting/4 + player.weapon_damage) + (rand() % (player.fighting/2)+1));}
	else {wprintw(out,"you missed!! \n ");} 

	}

	if(player.C_weapon_melee != true){
		if(player.C_ammo > 0){
			if((player.weapon_accuracy/2 +  player.shooting/2 + rand()%100) >= 100){
			enemy1.C_health = enemy1.C_health - ((player.shooting/4 + player.weapon_damage) + (rand() % (player.shooting/2)+1));
			player.C_ammo--;
	}else{wprintw(out,"you missed! \n");
			player.C_ammo--;}
	}
	}
	
	wprintw(out,"enemy HP: %d \n", enemy1.C_health);
	break;
case 2:
	wprintw(out,"you attempt to run.... \n " );
	if(rand()%100 > 50 ) return;
	else printf("it failed \n");
	break;

case 3:
	 wprintw(out,"inventory stuff goes here.\n ");
	list_Pinv();
	break;

default:
	wprintw(out,"something went wrong");
	break;


}

if (enemy1.C_health  <= 0 ) return;



player.C_HP = player.C_HP - ((rand() % enemy1.damage)/2 + enemy1.damage/2 );

if (player.C_HP <= 0 ) death();


wprintw(out," HP: %d \n", player.C_HP );






}

}

//death function
death(){printw("you died");}


//level up function
levelup(){


player.level++;

player.xp_to_next = player.xp_to_next + player.level * player.xp_to_next/4;




}

