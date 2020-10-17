/*
  Name: Cyb3rM3rlin
  Program Name: Sum of n elements
  */
#include<stdio.h>
#include<conio.h>
void main(){
  int n,sum=0,temp;
  printf("Enter the no of elements to be added");
  scanf("%d",&n);
  printf("Enter the elements");
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    sum+=temp;
  }
printf("Sum of the given %d elements is %d",n,sum);
  }
