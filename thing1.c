
#include "stdio.h"




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



int easy = 50;
int difficult = 100;
int really_hard = 125;
int nearly_impossible = 175;

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

//position values

int X;
int Y;







main (){

printf(" Warning this program contains content innapropriate for audiences of all ages. Please avoid \n" );

charc();
}






// this is the charecter creation function
charc(){


printf("welcome to the charecter creation tool \n");
printf("\n \n \n \n \n \n");


vitality = 20;
fitness = 20;
coordination = 20;
smarts = 20;




int i;
long a;
int b;

for(i=40;i>0;){
	printf("\n \n \n \n \n \n \n \n \n \n \n \n \n ");

	
	printf("vitality");
	for(b=vitality/5;b>0;b--){printf("+");}
	printf("\n");
	printf("fitness");
	for(b=fitness/5;b>0;b--){printf("+");}
	printf("\n");
	printf("smarts");
	for(b=smarts/5;b>0;b--){printf("+");}
	printf("\n");
	printf("coordination");
	for(b=coordination/5;b>0;b--){printf("+");}
	printf("\n");


printf("choos 1 to increase \n (1)vitality (2)fitness (3)smarts (4)coordination \n (%d left)",i);



scanf("%li",&a);
if (a<1 || a>4) continue;

switch(a){
case 1:
	vitality++;
	i--;
	break;
case 2:
	fitness++;
	i--;
	break;
case 3:
	smarts++;
	i--;
	break;
case 4:
	coordination++;
	i--;
	break;
default:
	printf("unrecognized choice");
	break;
}


	
}


printf("done \n ");









small_electronics = small_electronics_base + smarts/2;
computers= computers_base + smarts/2;
mechanics = mechanics_base + smarts/2;
locksmith = locksmith_base + smarts/4 + coordination/4;
chemistry = chemistry_base + smarts/2;
fighting  = fighting_base + smarts/4 + fitness/4;
shooting = shooting_base + smarts/4 + coordination/4;


HP = fitness;
regen = fitness/4;
imunity = vitality;
 


printf("resulting stats:\n");

printf("small electronics: %d \n",small_electronics);
printf("computers: %d \n",computers);
printf("mechanics: %d \n",mechanics);
printf("locksmith: %d \n",locksmith);
printf("chemistry: %d \n", chemistry);
printf("fighting: %d \n ", fighting);
printf("shooting: %d \n", shooting);








}


// this function will do a few thiings:
//it will print out important information for the player nice and neat
//secondly it will provide a place where the player will make the majority of the choices

plot(){

C_HP = HP;

while(C_HP>0){






}


}


//this function initializes the landscape and impassible objects

landscape(){}
