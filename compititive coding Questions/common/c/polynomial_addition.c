#include<stdio.h>
#include<stdlib.h>
struct Node 
{ 
    int coeff; 
    int pow; 
    struct Node *next; 
}; 
void create_node(int x, int y, struct Node **temp) 
{ 
    struct Node *r, *z; 
    z = *temp; 
    if(z == NULL) 
    { 
        r =(struct Node*)malloc(sizeof(struct Node)); 
        r->coeff = x; 
        r->pow = y; 
        *temp = r; 
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
    else
    { 
        r->coeff = x; 
        r->pow = y; 
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
} 
void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly) 
{ 
while(poly1->next && poly2->next) 
    { 
        if(poly1->pow > poly2->pow) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
        else if(poly1->pow < poly2->pow) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        else
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff+poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
        poly->next = (struct Node *)malloc(sizeof(struct Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
while(poly1->next || poly2->next) 
    { 
        if(poly1->next) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        poly->next = (struct Node *)malloc(sizeof(struct Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
} 
void show(struct Node *node) 
{ 
while(node->next != NULL) 
    { 
    printf("%dx^%d", node->coeff, node->pow); 
    node = node->next; 
    if(node->next != NULL) 
        printf(" + "); 
    } 
} 
int main() 
{ 
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 
    int pow1,pow2,num,pow;
    printf("enter 1st equation no of elements: ");
    scanf("%d",&pow1);
    for(int i=0;i<pow1;i++){
     printf("\nenter number: ");
     scanf("%d",&num);
     printf("\n enter power : ");
     scanf("%d",&pow);
     create_node(num,pow,&poly1);
	}
	printf("enter 2nd eqn no of elements: ");
    scanf("%d",&pow2);
	for(int i=0;i<pow2;i++){
     printf("\nenter number: ");
     scanf("%d",&num);
     printf("\n enter power : ");
     scanf("%d",&pow);
     create_node(num,pow,&poly2);
	}
    printf("1st Number: ");  
    show(poly1);  
    printf("\n2nd Number: "); 
    show(poly2); 
    poly = (struct Node *)malloc(sizeof(struct Node));  
    polyadd(poly1, poly2, poly); 
    printf("\nAdded polynomial: "); 
    show(poly); 
return 0; 
} 
