#include "string.h"
#include "stdio.h"




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

int ammotype;

} item[50];



FILE *data;




itemload(){

//bandaids





data = fopen("itemlist.list", "r");

char  name[20];
int type;
int mod;
int damage;
int range;
int accuracy;
int ammocap;
int weapon;
int number;
int ammotype;
while(fscanf(data,"%s %d  %d %d %d %d %d %d %d %d",name,&type,&mod,&damage,&range,&accuracy,&ammocap,&weapon,&ammotype,&number)!= EOF){
	strcpy(item[number].name, name);
	item[number].type = type;
	item[number].mod = mod;
	item[number].damage = damage;
	item[number].range = range;
	item[number].accuracy = accuracy;
	item[number].ammocap = ammocap;
	item[number].weapon = weapon;
	item[number].ammotype = ammotype;

}

fclose(data);
}


itemloadold(){

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



