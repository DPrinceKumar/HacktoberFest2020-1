#include<stdio.h>
int main(){
	int i,j,k,r;
	printf("Enter number of rows:");
	scanf("%d",&r);
	for(i=0;i<r;i++){
		for(k=0;k<(r-i);k++){
			printf(" ");
		}
		for(j=0;j<i+1;j++){
			printf("*");
		}
		for(j=0;j<i;j++){
		    printf("*");
		}
		printf("\n");
	}
}

