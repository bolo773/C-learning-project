struct tools{

char name[20];

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

item[0].type = 1;

item[0].mod = 5;



//knife

item[1].type = 3;

item[1].damage = 10;

item[1].range = 1;

item[1].accuracy = 90;

}



