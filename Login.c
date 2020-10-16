//Login Screen In C Language.
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct signup{
char uid[10];
char pwd[10];
}s[10];
struct temp{
char uid[10];
char pwd[10];
}t[10];
void logout();
void home();
void login();
void signup();
void main(){
int opt,j=2,i;
char s;
clrscr();
s=(char)j;
printf("\n\t\t\t **Welcome**");
printf("\n\t\tEnter \t1- Register \n\t\t\t2- Login \n\t\t\t3- Exit\n");
scanf("%d",&opt);
if(opt==1){
signup();
}
else if(opt==2)
login();
else if(opt==3){
clrscr();
for(i=0;i<=5;i++)
printf("\t\t\t%c",s);
getch();}
else{
clrscr();
printf("\nEnter correct options");
getch();
main();
}
getch();
}
void signup(){
FILE *fp1,*fp2;
static int x=0;
clrscr();
printf("\n\t\t\t **Welcome**");
printf("\n\n\t\t Enter User Name\t:");
scanf("%s",&s[x].uid);
printf("\n\n\t\t Enter Password\t\t:");
scanf("%s",&s[x].pwd);
fp1=fopen("venky.txt","w");
fprintf(fp1,"%s\n",s[x].uid);
fp2=fopen("m.txt","w");
fprintf(fp2,"%s\n",s[x].pwd);
fclose(fp1);
fclose(fp2);
clrscr();
printf("\n\t** You have successfully registered**");
getch();
x++;
main();

}
void login(){
FILE *fp1,*fp2;
char pwd[10],uid[10],ch,flag;
int i,k,l,n=0,opt;
static int x;
clrscr();
printf("\n\t\t\t **Welcome**");
printf("\n\n\t\t Enter User Name\t:");
scanf("%s",&uid);
printf("\n\n\t\t Enter Password\t\t:");
while(1){
ch=getch();
if(ch==13)
{
pwd[n]='\0';
break;
}
pwd[n]=ch;
n++;
printf("*");
}
clrscr();
printf("\n\t\t Enter 1 to see password\n \tEnter 2 to enter password again\t:\n \tEnter any key to login" );
scanf("%d",&opt);
if(opt==1){

printf("\n%s",pwd);
getch();
}
 if(opt==2){
login();
}else{
getch();}
fp1=fopen("venky.txt","r");
fgets(t[x].uid,15,fp1);
printf("\n%s",t[x].uid);
fp2=fopen("m.txt","r");
fgets(t[x].pwd,15,fp2);
printf("\n%s",t[x].pwd);
for(i=0;i<10;i++){
k=strcmp(t[i].uid,uid);
l=strcmp(t[i].pwd,pwd);
if((k==0)||(l==0)){

clrscr();
printf("\n\t** You Have Successfully Logged- In**");
home();
}
else flag=1;
 //printf("\n\t\tYou have Entered wrong details");
 }
if(flag==1)
printf("\nenter correct details");
getch();
}
void home()
{
int opt;
clrscr();
printf("\n\t\t\t  **Welcome**");
printf("\n\t \t Thanks for registration & logging in");
getch();
clrscr();
printf("\n\t Enter 1-logout\t:");
scanf("%d",&opt);
if(opt==1){
logout();
}
else{
 printf("\n\t Enter correct option");

home();
}
getch();
}
void logout(){
clrscr();
printf("\n\t\t\t ** Thank You**");
main();
}



