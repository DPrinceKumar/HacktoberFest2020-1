#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<time.h>
#include<unistd.h>

//Semester project of programming.... Saim Akhtar,Mauvia Atif, Saad//

int t(void);
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int gotoxy(short x,short y);
int gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int design() {
	char des1[]="**|||",des2[]="|||**";
	int a=2,i;
	
	for(i=1;i<=50;i++){
		gotoxy(1,a);
		printf("%s",des1);
		gotoxy(118,a);
		printf("%s",des2);
		a++;
		delay(20);
	}
}
int layout() {
	char des1[]="**|||",des2[]="|||**";
	int a=3,i,j;
	for(i=60,j=61;i>=0,j<=120;i--,j++){
		gotoxy(i+1,1);
		printf("*");
		gotoxy(j+1,1);
		printf("*");
		delay(10);
	}
	for(i=60,j=61;i>=0,j<=120;i--,j++){
		gotoxy(i+1,2);
		printf("|");
		gotoxy(j+1,2);
		printf("|");
		delay(10);
	}
	for(i=1;i<=30;i++){
		gotoxy(1,a);
		printf("%s",des1);
		gotoxy(118,a);
		printf("%s",des2);
		a++;
		delay(10);
	}
	for(i=0,j=120;i<=60,j>=61;i++,j--){
		gotoxy(i+1,31);
		printf("|");
		gotoxy(j+1,31);
		printf("|");
		delay(10);
	}
	for(i=0,j=120;i<=60,j>=61;i++,j--){
		gotoxy(i+1,32);
		printf("*");
		gotoxy(j+1,32);
		printf("*");
		delay(10);
	}
	
}
int loading(){
	
	int i,a=45;
	system("cls");
	gotoxy(55,8);
	printf("LOADING");
	for(i=a;i<=80;i++){
		gotoxy(a,10);
		printf("\xCD");
		a++;
		delay(15);
	}
	system("cls");
}  
    

int password(){
	char pass_real[]="Saim";
	
	char ch,pass[100];
	int i,co=4,tr=6,p,count=1,attempts=2,flag=1;
	
	do{gotoxy(35,co);
	printf("Enter the password ");
		flag=1;
		p=0;
		while((ch=getch()) != '\r'){
			pass[p]=ch;
			p++;
			printf("*");
		}
		pass[p]='\0';
		if(strcmp(pass,pass_real) != 0){
			flag=0;
			if(count != 3){
				gotoxy(35,tr);
			printf("\aWrong pin code! You have %d attempts left.Try again",attempts);
			attempts--;
			tr=tr+4;
		}
		}
		count++;
		co=co+4;
	}while(strcmp(pass,pass_real) != 0 && count <4);
	system("cls");
	gotoxy(35,5);
	if(flag == 0){
		printf("\aSorry you are not authorized");
	}
	return flag;
}
int t(void){
	time_t t;
	time(&t);
	gotoxy(94,45);
	printf("%s",ctime(&t));
}

float batting_sr(int r,int b){
     float res;
     res=(float)(r*100)/b;
     return res;
}

float bowling_sr(int b,int w){
	float ans;
	ans=(float)b/w;
	return ans;
}

float avg(int matches,int runs){
	float average;
	average=(float)runs/matches;
	return average;
}

int add_title(){
	char addstr[]="|||| ADDING A PLAYER IN THE TEAM SQUAD ||||";
	int i;
	for(i=0;addstr[i] != '\0';i++){
		gotoxy(i+35,2);
		printf("%c",addstr[i]);
		delay(20);
	}
}
int list_title(){
	char liststr[]="|||| DISPLAYING THE LIST OF PAKISTAN CRICKET SQUAD ||||";
    int i;
    for(i=0;liststr[i] != '\0';i++){
		gotoxy(i+35,2);
		printf("%c",liststr[i]);
		delay(20);
	}
}
int search_title(){
	char searchstr[]="|||| SEARCHING THE DATA IN THE TEAM SQUAD ||||";
    int i;
    for(i=0;searchstr[i] != '\0';i++){
		gotoxy(i+35,2);
		printf("%c",searchstr[i]);
		delay(20);
	}
}
int mod_title(){
	char modstr[]="|||| MODIFYING THE DATA IN THE TEAM SQUAD ||||";
    int i;
    for(i=0;modstr[i] != '\0';i++){
		gotoxy(i+35,2);
		printf("%c",modstr[i]);
		delay(20);
	}
}
int del_title(){
	char delstr[]="||| DELETING A PLAYER IN THE TEAM |||";
	int i;
    for(i=0;delstr[i] != '\0';i++){
		gotoxy(i+35,2);
		printf("%c",delstr[i]);
		delay(20);
	}
}
int team_bowlers(){
	char bstr[]="||| BOWLERS IN THE TEAM |||";
	int i;
    for(i=0;bstr[i] != '\0';i++){
		gotoxy(i+35,2);
		printf("%c",bstr[i]);
		delay(20);
	}
}
int team_batsmen(){
	char bstr[]="||| BATSMEN IN THE TEAM |||";
	int i;
    for(i=0;bstr[i] != '\0';i++){
		gotoxy(i+35,2);
		printf("%c",bstr[i]);
		delay(20);
	}
}

int add();
int list(int,int);
int search();
int rem();
int modify();
struct bowling_averages{
	char bowling_style[100];
	int balls;
	int wkts;
	float bowl_sr;
};
struct batting_averages{
	char batting_style[100];
	int runs;
	int ball_played;
	float average;
	float bat_sr;
};

struct player_data{
	char name[100];
	int age;
	char ID[100];
	char playing_role[100];
	int matches;
	struct batting_averages bat;
	struct bowling_averages bowl;
	
}p;

long int recsize=sizeof(p);
FILE *fp,*ft;

int main () {
	system("color 2F");
	t();
	struct player_data p;
	int i,j=1,k=4,flag_password,function,count_players=0;
	char another,start,username[100];
	char st1[]=" --------- SAIM AKHTAR   CT-059 ---------",st2[]=" --------- MOHAMMAD MAVIA    CT-074 ---------",st3[]=" --------- SAAD MUHAMMAD SYED   CT-057 ---------";
	char topic[]="||||| CRICKET TEAM SQUAD PROJECT PROTECTED |||||";
	char proj[]="/////------PAKISTAN ODI CRICKET TEAM------/////";
	fp=fopen("mavia.DAT","rb+");
	if(fp== NULL){
		fp=fopen("mavia.DAT","wb+");
		if(fp== NULL){
			puts("Cannot open file");
			exit(1);
		}
	}
	
	gotoxy(35,1);
	printf(" GROUP PROJECT MEMBERS : ");
	gotoxy(35,5);
	printf("1) ");
	for(i=0;st1[i] != '\0';i++){
		printf("%c",st1[i]);
		delay(20);
	}
	printf("\n");
	gotoxy(35,7);
	printf("2) ");
	for(i=0;st2[i] != '\0';i++){
		printf("%c",st2[i]);
		delay(20);
	}
	gotoxy(35,9);
	printf("3) ");
	for(i=0;st3[i] != '\0';i++){
		printf("%c",st3[i]);
		delay(20);
	}
	gotoxy(1,13);
	printf("Press any key to start the project");
	start=getch();
    system("cls");
    t();
    delay(200);
    design();
    gotoxy(33,1);
	for(i=0;topic[i] != '\0';i++){
		printf("%c",topic[i]);
		delay(50);
	}
    gotoxy(35,2);
    printf("Enter Your Name : ");
    gets(username);
    flag_password=password();
    if(flag_password ==0){
    	delay(1000);
	}
    system("cls");
    loading();
    t();
    if(flag_password == 1){
    	while(1){
    		t();
		layout();
		gotoxy(35,5);
    	for(i=0;proj[i] != '\0';i++){
    		printf("%c",proj[i]);
    		delay(20);
		}
		delay(100);
		gotoxy(25,10);
		printf("**************      1.Add A Player In The Team            *************");
		delay(100);
		gotoxy(25,12);
		printf("**************      2.Display The Team Squad             *************");
		delay(100);
		gotoxy(25,14);
		printf("**************      3.Search A Player/Data               *************");
		delay(100);
		gotoxy(25,16);
		printf("**************      4.Delete A Player                    *************");
		delay(100);
		gotoxy(25,18);
		printf("**************      5.Modify A Player/Player's Data      *************");
		delay(100);
		gotoxy(25,20);
		printf("**************      6.Exit                               *************");
		delay(100);
		gotoxy(25,24);
		printf("Enter The Function You Want To Check: ");
		scanf("%d",&function);
		system("cls");	
	switch(function){
		case 1:
			do{
			fflush(stdin);
			add();
			gotoxy(35,25);
			printf("Enter another player(Y/N) :");
			another=getche();
			system("cls");
			}while(another == 'Y'|| another == 'y');
			system("cls");
			break;
		case 2:
			do{
			list(k,j);
		}while((another=getch()) != '\r');
			system("cls");
			break;
		case 3:
				search();
			system("cls");
			break;
		case 4:
			rem();
			system("cls");
		break;
		case 5:
			modify();
			system("cls");
		break;	
		case 6:
			loading();
					gotoxy(35,8);
	printf("||||||| Thanks Mr.%s For Your Kind Support |||||||",username);
    design();
    fclose(fp);
    gotoxy(25,12);
    printf("WAIT.... EXITING IN 3 SECONDS");
    delay(3000);
			exit(1);
	default:
		printf("\nInvalid function ");
		system("cls");
		break;
	}
	}
}
	
}

int add() {
	int bat,bowl;
	struct player_data p;
	fp=fopen("mavia.DAT","rb+");
	if(fp== NULL){
		fp=fopen("mavia.DAT","wb+");
		if(fp== NULL){
			puts("Cannot open file");
			exit(1);
		}
	}
	t();
	fflush(stdin);
	fseek(fp,0,SEEK_END);
	design();
	add_title();
	delay(500);
    gotoxy(35,4);
	printf("Enter the name of player: ");
    gets(p.name);
    strupr(p.name);
    gotoxy(35,5);
	printf("Enter the player ID ");
    gets(p.ID);
    strupr(p.ID);
    gotoxy(35,7);
	printf("Enter the age of the player ");
    scanf("%d",&p.age);
    gotoxy(35,9);
	fflush(stdin);
    printf("Enter the playing role of player ");
    gets(p.playing_role);
    strupr(p.playing_role);
    gotoxy(35,11);
	printf("Enter the number of matches played ");
    scanf("%d",&p.matches);
    gotoxy(15,13);
	printf("Press 1 To Enter the Batting Data ");
    scanf("%d",&bat);
    if(bat == 1){
    gotoxy(15,15);	
	printf("!!!!PLAYER'S BATTING DATA!!!!");
    gotoxy(15,17);
	fflush(stdin);
	printf("Enter the batting style ");
	gotoxy(15,18);
	printf("Enter the total runs ");
    gotoxy(15,19);
	printf("Enter the balls faced ");
	gotoxy(40,17);
	gets(p.bat.batting_style);
	strupr(p.bat.batting_style);
    gotoxy(40,18);
	scanf("%d",&p.bat.runs);
    gotoxy(40,19);
	scanf("%d",&p.bat.ball_played);
    p.bat.average=avg(p.matches,p.bat.runs);
    p.bat.bat_sr=batting_sr(p.bat.runs,p.bat.ball_played);
    gotoxy(15,20);
	printf("Players Average=%.2f ",p.bat.average);
	gotoxy(15,21);
	printf("Players Strike rate=%.2f ",p.bat.bat_sr);
	
}
else if (bat != 1){
	fflush(stdin);
	p.bat.runs=0;
	p.bat.ball_played=0;
	p.bat.average=0.00;
	p.bat.bat_sr=0.00;
	gotoxy(15,15);	
	printf("!!!!PLAYER'S BATTING DATA!!!!");
	fflush(stdin);
	gotoxy(15,18);
	printf("Total runs = %d",p.bat.runs);
    gotoxy(15,19);
	printf("Balls faced = %d",p.bat.ball_played);
    gotoxy(15,20);
	printf("Players Average=%.2f ",p.bat.average);
	gotoxy(15,21);
	printf("Players Strike rate=%.2f ",p.bat.bat_sr);
}
    gotoxy(65,13);
    printf("Enter 1 to Enter the bowling data ");
    scanf("%d",&bowl);
    if(bowl == 1){
    gotoxy(65,15);
	printf("!!!!PLAYER'S BOWLING DATA!!!!");
	fflush(stdin);
	gotoxy(67,17);
	printf("Enter the bowling style: ");
	gotoxy(67,18);
	printf("Enter the wickets taken: ");
	gotoxy(67,19);
	printf("Enter the balls bowled: ");
	gotoxy(95,17);
	gets(p.bowl.bowling_style);
	strupr(p.bowl.bowling_style);
	gotoxy(95,18);
	scanf("%d",&p.bowl.wkts);
	gotoxy(95,19);
	scanf("%d",&p.bowl.balls);
	p.bowl.bowl_sr=bowling_sr(p.bowl.balls,p.bowl.wkts);
	gotoxy(67,20);
	printf("Bowling strike rate: %.2f",p.bowl.bowl_sr);
}
else if (bowl != 1){
	fflush(stdin);
	p.bowl.wkts=0;
	p.bowl.balls=0;
	p.bowl.bowl_sr=0.00;
	gotoxy(65,15);
	printf("!!!!PLAYER'S BOWLING DATA!!!!");
	fflush(stdin);
	gotoxy(67,18);
	printf("Wickets taken = %d ",p.bowl.wkts);
	gotoxy(67,19);
	printf("Balls bowled = %d",p.bowl.balls);
	gotoxy(67,20);
	printf("Bowling strike rate: %.2f",p.bowl.bowl_sr);

}
	fwrite(&p,recsize,1,fp);
	fflush(stdin);
	fclose(fp);
}

int list(int i,int j) { 
	fp=fopen("mavia.DAT","rb+");
	if(fp == NULL){
		fp=fopen("mavia.DAT","wb+");
		if(fp == NULL){
			puts("Cannot open file");
			exit(1);
		}
	}
	t();
	
	fflush(stdin);
		design();
		list_title();
		rewind(fp);
	while(fread(&p,recsize,1,fp) == 1){
		if(strcmp(p.ID,"NULL") != 0)
		{
		fflush(stdin);
		delay(20);
		gotoxy(20,i);
		printf("%d)%s",j,p.name);
		fflush(stdin);
		gotoxy(45,i);
		printf("ID=%s",p.ID);
		fflush(stdin);
		gotoxy(53,i);
		printf("Playing Role=%s ",p.playing_role);
	fflush(stdin);
	i++;
	j++;
}
	}
	fclose(fp);
}

int search(){
	int choice,count_search,id,bt,bl;
	char another;
	static char find_player[20],find_id[20],find_name[20];
	fp=fopen("mavia.DAT","rb");
	if(fp == NULL){
			puts("Cannot open file");
			exit(1);
	}
	t();
	do{
	fflush(stdin);
		rewind(fp);
		design();
		search_title();
		gotoxy(30,5);
		printf("1) SEARCH FOR A PLAYER IN THE TEAM ");
		gotoxy(30,7);
		printf("2) SHOW THE BOWLERS IN THE TEAM ");
		gotoxy(30,9);
		printf("3) SHOW THE BATSMEN IN THE TEAM ");
		gotoxy(30,10);
		printf("4) Go Back To Menu");
		gotoxy(30,12);
		scanf("%d",&choice);
		system("cls");
		if(choice == 1){
			design();
			count_search=0;
			fflush(stdin);
			gotoxy(30,2);
			printf("Enter the name of the player ");
			gets(find_player);
			strupr(find_player);
			while(fread(&p,recsize,1,fp) == 1){
				fflush(stdin);
				if(strcmp(p.ID,"NULL") != 0){
				if(strstr(p.name,find_player) != 0){
				fflush(stdin);
				count_search++;
				}
			}
			}
			if(count_search == 0){
				gotoxy(30,5);
				printf("%s Is Not In The Squad",find_player);
				
			}
			rewind(fp);
			if(count_search == 1){
				design();
				while(fread(&p,recsize,1,fp) == 1){
				if(strstr(p.name,find_player) != 0){
				fflush(stdin);
				gotoxy(35,4);
				printf("%s",p.name);
				fflush(stdin);
				gotoxy(35,5);
				printf("ID=%s",p.ID);
				gotoxy(35,6);
				printf("Age = %d",p.age);
				fflush(stdin);
				gotoxy(35,7);
				printf("Playing role = %s",p.playing_role);
				fflush(stdin);
				gotoxy(35,8);
				printf("Number of matches played = %d",p.matches);
				if(p.bat.runs != 0  && p.bat.ball_played != 0){
				gotoxy(15,10);
				printf("!!!!PLAYER'S BATTING DATA!!!!");
                fflush(stdin);
				gotoxy(15,11);
	            printf("Batting style = %s",p.bat.batting_style);
	            fflush(stdin);
				gotoxy(15,12);
	            printf("Total runs = %d",p.bat.runs);
                fflush(stdin);
				gotoxy(15,13);
	            printf("Balls faced =%d ",p.bat.ball_played);
                fflush(stdin);
				gotoxy(15,14);
				printf("Batting Average = %.2f",p.bat.average);
				fflush(stdin);
				gotoxy(15,15);
				printf("Batting Strike rate = %.2f",p.bat.bat_sr);
				
			}
			else if(p.bat.runs == 0  && p.bat.ball_played == 0){
				gotoxy(15,8);	
	printf("!!!!PLAYER'S BATTING DATA!!!!");
	fflush(stdin);
	gotoxy(15,11);
	printf("Batting Style = \"NULL\"");
	gotoxy(15,12);
	printf("Total runs = %d",p.bat.runs);
    gotoxy(15,13);
	printf("Balls faced = %d",p.bat.ball_played);
    gotoxy(15,14);
	printf("Players Average=%.2f ",p.bat.average);
	gotoxy(15,15);
	printf("Players Strike rate=%.2f ",p.bat.bat_sr);
			}
				if(p.bowl.wkts == 0 && p.bowl.balls == 0){
					gotoxy(65,10);
				printf("!!!!PLAYER'S BOWLING DATA!!!!");
				fflush(stdin);
				gotoxy(67,11);
				printf("Bowling style = \"NULL\" ");
				fflush(stdin);
				gotoxy(67,12);
				printf("Wickets taken= %d ",p.bowl.wkts);
				fflush(stdin);
				gotoxy(67,13);
				printf("Balls bowled= %d ",p.bowl.balls);
				fflush(stdin);
				gotoxy(67,14);
				printf("Bowling Strike Rate = %.2f",p.bowl.bowl_sr);
				}
				else {
				gotoxy(65,10);
				printf("!!!!PLAYER'S BOWLING DATA!!!!");
				fflush(stdin);
				gotoxy(67,11);
				printf("Bowling style= %s ",p.bowl.bowling_style);
				fflush(stdin);
				gotoxy(67,12);
				printf("Wickets taken= %d ",p.bowl.wkts);
				fflush(stdin);
				gotoxy(67,13);
				printf("Balls bowled= %d ",p.bowl.balls);
				fflush(stdin);
				gotoxy(67,14);
				printf("Bowling Strike Rate = %.2f",p.bowl.bowl_sr);	
			}
					}
				}
			
			}
		if(count_search >1){
			design();
			id=5;
			rewind(fp);
			while(fread(&p,recsize,1,fp) == 1){
				fflush(stdin);
				if(strcmp(p.ID,"NULL") != 0){
				if(strstr(p.name,find_player) != 0){
					gotoxy(30,3);
					printf("There are %d %s in the list",count_search,find_player);
					fflush(stdin);
					gotoxy(30,id);
					printf("%s ID = %s",p.name,p.ID);
				id++;
				}
			}
			}
			gotoxy(30,id+1);
			fflush(stdin);
			printf("Enter the full name of the player");
			gotoxy(30,id+2);
			fflush(stdin);
			printf("Enter the ID of the player ");
			gotoxy(70,id+1);
			gets(find_name);
			gotoxy(70,id+2);
			gets(find_id);
			system("cls");
			design();
			rewind(fp);
			while(fread(&p,recsize,1,fp) == 1){
				fflush(stdin);
				if(strcmp(p.ID,"NULL") != 0) {
				if((strcmpi(p.name,find_name) ==0) && (strcmp(p.ID,find_id) == 0)){
				fflush(stdin);
				gotoxy(35,4);
				printf("%s",p.name);
				fflush(stdin);
				gotoxy(35,5);
				printf("ID=%s",p.ID);
				gotoxy(35,6);
				printf("Age = %d",p.age);
				fflush(stdin);
				gotoxy(35,7);
				printf("Playing role = %s",p.playing_role);
				fflush(stdin);
				gotoxy(35,8);
				printf("Number of matches played = %d",p.matches);
				if(p.bat.runs != 0  && p.bat.ball_played != 0){
				gotoxy(15,10);
				printf("!!!!PLAYER'S BATTING DATA!!!!");
                fflush(stdin);
				gotoxy(15,11);
	            printf("Batting style = %s",p.bat.batting_style);
	            fflush(stdin);
				gotoxy(15,12);
	            printf("Total runs = %d",p.bat.runs);
                fflush(stdin);
				gotoxy(15,13);
	            printf("Balls faced =%d ",p.bat.ball_played);
                fflush(stdin);
				gotoxy(15,14);
				printf("Batting Average = %.2f",p.bat.average);
				fflush(stdin);
				gotoxy(15,15);
				printf("Batting Strike rate = %.2f",p.bat.bat_sr);
				
			}
			else if(p.bat.runs == 0  && p.bat.ball_played == 0){
				gotoxy(15,8);	
	printf("!!!!PLAYER'S BATTING DATA!!!!");
	fflush(stdin);
	gotoxy(15,11);
	printf("Batting Style = \"NULL\"");
	gotoxy(15,12);
	printf("Total runs = %d",p.bat.runs);
    gotoxy(15,13);
	printf("Balls faced = %d",p.bat.ball_played);
    gotoxy(15,14);
	printf("Players Average=%.2f ",p.bat.average);
	gotoxy(15,15);
	printf("Players Strike rate=%.2f ",p.bat.bat_sr);
			}
				if(p.bowl.wkts == 0 && p.bowl.balls == 0){
					gotoxy(65,10);
				printf("!!!!PLAYER'S BOWLING DATA!!!!");
				fflush(stdin);
				gotoxy(67,11);
				printf("Bowling style = \"NULL\" ");
				fflush(stdin);
				gotoxy(67,12);
				printf("Wickets taken= %d ",p.bowl.wkts);
				fflush(stdin);
				gotoxy(67,13);
				printf("Balls bowled= %d ",p.bowl.balls);
				fflush(stdin);
				gotoxy(67,14);
				printf("Bowling Strike Rate = %.2f",p.bowl.bowl_sr);
				}
				else {
				gotoxy(65,10);
				printf("!!!!PLAYER'S BOWLING DATA!!!!");
				fflush(stdin);
				gotoxy(67,11);
				printf("Bowling style= %s ",p.bowl.bowling_style);
				fflush(stdin);
				gotoxy(67,12);
				printf("Wickets taken= %d ",p.bowl.wkts);
				fflush(stdin);
				gotoxy(67,13);
				printf("Balls bowled= %d ",p.bowl.balls);
				fflush(stdin);
				gotoxy(67,14);
				printf("Bowling Strike Rate = %.2f",p.bowl.bowl_sr);	
			}
				}
		}
			}
		}	
			
		}
		if(choice == 2){
			bl=1;
		design();
			count_search=4;
			gotoxy(30,2);
			team_bowlers();
	rewind(fp);
	fflush(stdin);
	while(fread(&p,recsize,1,fp) == 1){
		fflush(stdin);
				if(strcmp(p.ID,"NULL") != 0) {
		if(p.bowl.wkts != 0 && p.bowl.balls != 0){
			fflush(stdin);
			gotoxy(35,count_search);
			printf("%d) %s",bl,p.name);
			fflush(stdin);
			gotoxy(65,count_search);
			printf("%s",p.ID);
			count_search++;
			bl++;
		}
}
	}
	        
}
    if(choice == 3){
    	bt=1;
    	design();
    	count_search=4;
			gotoxy(30,2);
			team_batsmen();
	rewind(fp);
	fflush(stdin);
	while(fread(&p,recsize,1,fp) == 1){
	fflush(stdin);
				if(strcmp(p.ID,"NULL") != 0){	
		if(p.bat.runs != 0  && p.bat.ball_played != 0){
			fflush(stdin);
			gotoxy(35,count_search);
			printf("%d) %s",bt,p.name);
			fflush(stdin);
			gotoxy(65,count_search);
			printf("%s",p.ID);
			count_search++;
			bt++;
		}
}
	}
	        
	}
	if(choice == 4){
		break;
		system("cls");
	}
	t();
        fflush(stdin);
		gotoxy(15,20);
		printf("Press 'Y' To Go Back In Search Panel Otherwise Press 'N' to Go Back To Main Menu (Y/N) ");
		fflush(stdin);
		another=getche();
		system("cls");
		}while(another == 'Y' || another =='y');
	fclose(fp);
			
}

int modify(){
	int bat,bowl,mod_found;
	char another;
	static char mod_name[20],mod_id[20];
	fp=fopen("mavia.DAT","rb+");
	if(fp== NULL){
		fp=fopen("mavia.dat","wb+");
		if(fp== NULL){
			puts("Cannot open file");
			exit(1);
		}
	}
	t();
	do{
		mod_found=0;
		design();
		mod_title();
		fflush(stdin);
		gotoxy(33,5);
		printf("Enter the Name of the player to modify ");
		gotoxy(33,7);
		printf("Enter the ID of the player to modify ");
		fflush(stdin);
		gotoxy(75,5);
		gets(mod_name);
		strupr(mod_name);
		fflush(stdin);
		gotoxy(75,7);
		gets(mod_id);
		rewind(fp);
		while(fread(&p,recsize,1,fp) == 1){
			if(strstr(p.name,mod_name) != 0 && strcmp(p.ID,mod_id) == 0){
				mod_found++;
			}
		}
		if(mod_found == 0){
			gotoxy(35,9);
			printf("%s With ID %s Not Found In The Player's Squad ",mod_name,mod_id);
		}
		else {
		system("cls");
	
	rewind(fp);
	while(fread(&p,recsize,1,fp) == 1)
{   if(strstr(p.name,mod_name) != 0 && strcmp(p.ID,mod_id) == 0){
	t();
	design();
	mod_title();
	gotoxy(35,5);
	printf("Enter the New Name of player: ");
    gets(p.name);
    strupr(p.name);
    gotoxy(35,6);
	printf("Enter the player New ID ");
    gets(p.ID);
    strupr(p.ID);
    gotoxy(35,7);
	printf("Enter the New age of the player ");
    scanf("%d",&p.age);
    gotoxy(35,8);
	fflush(stdin);
    printf("Enter the playing role of player ");
    gets(p.playing_role);
    strupr(p.playing_role);
    gotoxy(35,9);
	printf("Enter the number of matches played ");
    scanf("%d",&p.matches);
    gotoxy(10,10);
    gotoxy(15,12);
	printf("Press 1 To Enter the Batting Data ");
    scanf("%d",&bat);
    if(bat == 1){
    gotoxy(15,14);	
	printf("!!!!PLAYER'S BATTING DATA!!!!");
    gotoxy(15,16);
	fflush(stdin);
	printf("Enter the batting style ");
	gotoxy(15,17);
	printf("Enter the total runs ");
    gotoxy(15,18);
	printf("Enter the balls faced ");
	gotoxy(40,16);
	fflush(stdin);
	gets(p.bat.batting_style);
	strupr(p.bat.batting_style);
    gotoxy(40,17);
	scanf("%d",&p.bat.runs);
    gotoxy(40,18);
	scanf("%d",&p.bat.ball_played);
    p.bat.average=avg(p.matches,p.bat.runs);
    p.bat.bat_sr=batting_sr(p.bat.runs,p.bat.ball_played);
    gotoxy(15,19);
	printf("Players Average=%.2f ",p.bat.average);
	gotoxy(15,20);
	printf("Players Strike rate=%.2f ",p.bat.bat_sr);
	
}
else if (bat != 1){
	fflush(stdin);
	p.bat.runs=0;
	p.bat.ball_played=0;
	p.bat.average=0.00;
	p.bat.bat_sr=0.00;
	gotoxy(15,14);	
	printf("!!!!PLAYER'S BATTING DATA!!!!");
	fflush(stdin);
	gotoxy(15,17);
	printf("Total runs = %d",p.bat.runs);
    gotoxy(15,18);
	printf("Balls faced = %d",p.bat.ball_played);
    gotoxy(15,19);
	printf("Players Average=%.2f ",p.bat.average);
	gotoxy(15,20);
	printf("Players Strike rate=%.2f ",p.bat.bat_sr);
}
    gotoxy(65,12);
    printf("Enter 1 to Enter the bowling data ");
    scanf("%d",&bowl);
    if(bowl == 1){
    gotoxy(65,14);
	printf("!!!!PLAYER'S BOWLING DATA!!!!");
	fflush(stdin);
	gotoxy(67,16);
	printf("Enter the bowling style: ");
	gotoxy(67,17);
	printf("Enter the wickets taken: ");
	gotoxy(67,18);
	printf("Enter the balls bowled: ");
	gotoxy(95,16);
	fflush(stdin);
	gets(p.bowl.bowling_style);
	strupr(p.bowl.bowling_style);
	gotoxy(95,17);
	scanf("%d",&p.bowl.wkts);
	gotoxy(95,18);
	scanf("%d",&p.bowl.balls);
	p.bowl.bowl_sr=bowling_sr(p.bowl.balls,p.bowl.wkts);
	gotoxy(67,19);
	printf("Bowling strike rate: %.2f",p.bowl.bowl_sr);
}
else if (bowl != 1){
	fflush(stdin);
	p.bowl.wkts=0;
	p.bowl.balls=0;
	p.bowl.bowl_sr=0.00;
	gotoxy(65,14);
	printf("!!!!PLAYER'S BOWLING DATA!!!!");
	fflush(stdin);
	gotoxy(67,17);
	printf("Wickets taken = %d ",p.bowl.wkts);
	gotoxy(67,18);
	printf("Balls bowled = %d",p.bowl.balls);
	gotoxy(67,19);
	printf("Bowling strike rate: %.2f",p.bowl.bowl_sr);

}
	
    fseek(fp,-recsize,SEEK_CUR);
    fwrite(&p,recsize,1,fp);
    break;
}
		}
	}
		gotoxy(20,25);
		printf("Modify Another Player's Data (Y/N)");
		another=getche();
		system("cls");
	}while(another == 'Y' || another == 'y');
	
	fclose(fp);
}

int rem(){
	char another;
	int flag=0;
	static char d_id[20];
	fp=fopen("mavia.dat","rb+");
	if(fp == NULL){
		fp=fopen("mavia.dat","wb+");
		if(fp == NULL){
			puts("Could not open life");
			exit(1);
		}
	}
	
		
	do{
		t();
		design();
		gotoxy(33,2);
	del_title();
		gotoxy(35,5);
		fflush(stdin);
		printf("Enter the id of player to delete ");
		gets(d_id);
		rewind(fp);
		while(fread(&p,recsize,1,fp) == 1){
			fflush(stdin);
			if(strcmp(p.ID,d_id) == 0){
				flag =1;
				gotoxy(35,7);
				printf("PLAYER DATA FOUND AND SUCCESSFULLY DELETED");
				strcpy(p.ID,"NULL");
				fseek(fp,-recsize,SEEK_CUR);
				fwrite(&p,recsize,1,fp);
				break;
			}
		}
		if (flag == 0){
			gotoxy(35,7);
			printf("ID OF PLAYER NOT FOUND IN THE LIST ");
		}
		gotoxy(20,10);
		fflush(stdin);
		printf("PRESS 'Y' TO REMOVE ANOTHER PLAYER ");
		another=getche();
		system("cls");
	}while(another == 'Y' || another == 'y');
	fclose(fp);
}


