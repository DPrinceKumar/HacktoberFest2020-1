#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int h; 
    scanf("%d",&h);
    int m; 
    scanf("%d",&m);
    char *count[]= {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quater", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"};
    
    if(m==0)
        printf("%s o' clock",count[h-1]);
    else if(m>30){
        if(m==59)           
            printf("%s minute to %s",count[m-1],count[h]);
        if(m==45)
             printf("quarter to %s",count[h]);
        else
              printf("%s minutes to %s",count[60-m-1],count[h]);       
    }
    else if(m<30){
        if(m==1)
        printf("%s minute past %s",count[m-1],count[h-1]);
        if(m==15)
             printf("quarter past %s",count[h-1]);
        else if(m!=1)
             printf("%s minutes past %s",count[m-1],count[h-1]);
    }
    else
        printf("half past %s",count[h-1]); 
}
