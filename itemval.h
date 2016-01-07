#include "string.h"


struct tools{

char  name[20];

int type;

int callnum;

int value;

int mod;

int heal;

int weapon;

int damage;

int range;

int ammocap;

int accuracy;



} item[50];








itemload(){

//bandaids

strcpy(item[0].name,"bandages");

item[0].type = 1;

item[0].mod = 5;



//knife
strcpy(item[1].name,"knives");

item[1].type = 3;

item[1].damage = 10;

item[1].range = 1;

item[1].accuracy = 90;

//handgun


item[2].type = 3;

item[2].damage = 20;

item[2].range = 10;

item[2].accuracy = 70;

item[2].ammocap = 10;


//pistol rounds;


item[3].type = 2;

item[3].weapon = 2;




}



