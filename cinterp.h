





int command(){
char str1[20];
char str2[20];
char str3[20];


mvwscanw(in,1,1,"%s %s %s",str1,str2,str3);

if (strcmp(str1,"go") == 0){
	

	if (strcmp(str2,"right")==0)shift(1);
	else 
	if(strcmp(str2,"left")==0) shift(2);
	else 
	if(strcmp(str2,"down")==0) shift(3);
	else
	if(strcmp(str2,"up")==0) shift(4);
	else 
	wprintw(out,"command not understood\n");
	}
	
if (strcmp(str1,"list")==0){

	if(strcmp(str2,"stats")==0) liststats();
	else
	if(strcmp(str2,"inventory")==0) list_Pinv();
	else
	wprintw(out,"command not understood");
	}
if(strcmp(str1,"loadmap")==0){
landscape(str2);
}
else
if(strcmp(str1,"save")==0)save();
else 
if (strcmp(str1,"load")==0)load();
else 
if(strcmp(str1,"scroll")==0){

	if(strcmp(str2,"up")==0){
	wscrl(out,1);
	}

	else
	if(strcmp(str2,"down")==0){
	wscrl(out,-1);
	}


}

}
