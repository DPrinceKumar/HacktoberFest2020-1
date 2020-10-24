#include<stdio.h>
#include<conio.h>
#define SIZE 50
typedef struct item
{
	int item_id, quantity ;
	char item_name[20] ;
	float price ;
}Item ;
int front = -1 ;
int rear = -1 ;
float bill = 0 ;
Item i_queue[SIZE] ;
void show(Item i)
{
	printf("\nitem id : %d\n", i.item_id) ;
	printf("item name : ") ;
	puts(i.item_name) ;
	printf("price : %f", i.price) ;
	printf("\nquantity : %d\n", i.quantity) ;
}
void insert(Item i)
{
	if(rear == SIZE-1)
	{
		printf("Cannot add more items!!") ;
	}
	else
	{
		if(rear == -1)
		{
			front++ ;
		}
		rear++ ;
		i_queue[rear] = i ;
	}
}
void remove_()
{
	if(front == -1)
	{
		printf("No item there to delete!!") ;
	}
	else
	{
		printf("item deleted from queue is: ") ;
		show(i_queue[front]) ;
		bill = bill + i_queue[front].price * i_queue[front].quantity ;
		front++ ;
	}
	if(front > rear)
	{
		rear = -1 ;
		front = -1 ;
	}
}
void peek()
{
	if(front == -1)
	{
		printf("queue is empty") ;
	}
	else
	{
		printf("item at front is: ") ;
		show(i_queue[front]) ;
	}
}
void display()
{
	int i ;
	if(front == -1)
	{
		printf("\nThe list is empty\n") ;
	}
	else
	{
		for(i = front ; i <= rear ; i++)
		{
			show(i_queue[i]) ;
			printf("\n") ;
		}
	}
}
void main()
{
	Item i ;
	int ch ;
	clrscr() ;
	while(1)
	{
		printf("Menu:\n1.Insert 2.Remove 3.Peek 4.Display 5.Exit\n") ;
		printf("Enter choice: ") ;
		scanf("%d", &ch) ;
		switch(ch)
		{
			case 1: printf("Enter item id: ") ;
				scanf("%d", &i.item_id) ;
				printf("Enter item name: ") ;
				gets(i.item_name) ;
				gets(i.item_name) ;
				printf("Enter price: ") ;
				scanf("%f", &i.price) ;
				printf("Enter quantity: ") ;
				scanf("%d", &i.quantity) ;
				insert(i) ;
				break ;
			case 2: remove_() ;
				break ;
			case 3: peek() ;
				break ;
			case 4: display() ;
				break ;
			case 5: if(front == -1 && rear == -1)
				{
					printf("\nYour bill is %f", bill) ;       \
					delay(20000) ;
					exit(0) ;
				}
				else
				{
					printf("\nplease empty the items first\n") ;
				}
				break ;
			default: printf("Enter the valid choice!!") ;
		}
	}
	getch() ;
}