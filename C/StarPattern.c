
#include<stdio.h>
int main(){
	int i,j,k,r;
	printf("how many rows u want:");
	scanf("%d",&r);
	for(i=1;i<r+1;i++){
		for(k=0;k<(r+1-i);k++){
			printf(" ");
		}
		for(j=0;j<2*i-1;j++){
			printf("*");
		}
		printf("\n");

	}
	re
