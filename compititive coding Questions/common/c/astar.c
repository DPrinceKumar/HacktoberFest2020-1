#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct node_array
{
	int a[3][3];
	int depth;
	int f;
	char text[11];
	struct node_array *ch1;
	struct node_array *ch2;
	struct node_array *ch3;
	struct node_array *ch4;
	struct node_array *parent;
	struct node_array *next;
} node;
node *front=NULL,*rear=NULL,*x,*front_list=NULL,*rear_list=NULL;
int up[3][3],dn[3][3],rt[3][3],lt[3][3],goal[3][3],depth_flag=0,f_count=0;

void set_zero(int a[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			a[i][j]=0;
}

void copy_array(int a[3][3],int b[3][3])//copy b to a
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			a[i][j]=b[i][j];
}

int is_equal(int a[3][3],int b[3][3])
{
	int i,j,flag=1;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(a[i][j]!=b[i][j])
				flag=0;
	return flag;
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void print_array(int a[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

int check_zero(int a[3][3])//returns 1 if 0
{
	int i,j,flag=1;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(a[i][j]!=0)
				flag=0;
	return flag;
}

int check_list(node *nd)//returns 0 if  dont match list
{
	node *new_node=NULL;
	if(front_list==NULL)
	return 0;
	else
	{
		new_node=front_list;
		while(new_node!=NULL)
		{
			if(is_equal(new_node->a,nd->a)==1)
				return 1;
			new_node=new_node->next;
		}
		return 0;
	}
}

void insert_queue(node *nd)
{
	nd->next=NULL;
	if(front==NULL)
	{
		front=nd;
		rear=nd;
	}
	else
	{
		rear->next=nd;
		rear=nd;
		rear->next=NULL;
	}
}

void insert_list(node *nd)
{
	nd->next=NULL;
	if(front_list==NULL)
	{
		front_list=nd;
		rear_list=nd;
	}
	else
	{
		rear_list->next=nd;
		rear_list=nd;
		rear_list->next=NULL;
	}
}

int mod(int a)
{
	if(a>=0)
		return a;
	else
		return (-1*a);
}

int calc_heuristic(node *nd)
{
	int i,j,k,l,h=0;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if(nd->a[i][j]!=0)
			{
				for(k=0;k<=2;k++)
				{
					for(l=0;l<=2;l++)
						if(nd->a[i][j]==goal[k][l])
							goto xy;
				}
				xy:
				h+=(mod(i-k)+mod(j-l));
			}
		}
		return h;
	}
	return 0;
}

void next_move(node *nd)
{
	int i,j,x,y;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(nd->a[i][j]==0)
				goto label;
	label:
	x=i;
	y=j;
	if(y+1 >2)
	nd->ch4=NULL;
	else
	{
		nd->ch4=(node*)malloc(sizeof(node));
		copy_array(nd->ch4->a,nd->a);
		swap(&nd->ch4->a[x][y],&nd->ch4->a[x][y+1]);
		if(check_list(nd->ch4)==1)
		{
			nd->ch4=NULL;
			free(nd->ch4);
		}
		else
		{
			nd->ch4->parent=nd;
			nd->ch4->depth=nd->depth+1;
			strcpy(nd->ch4->text,"move right");
			nd->ch4->f=nd->depth+calc_heuristic(nd->ch4)+1;
			insert_list(nd->ch4);
			insert_queue(nd->ch4);
		}
	}
	if(y-1 <0)
	nd->ch3=NULL;
	else
	{
		nd->ch3=(node*)malloc(sizeof(node));
		copy_array(nd->ch3->a,nd->a);
		swap(&nd->ch3->a[x][y],&nd->ch3->a[x][y-1]);
		if(check_list(nd->ch3)==1)
		{
			nd->ch3=NULL;
			free(nd->ch3);
		}
		else
		{
			nd->ch3->parent=nd;
			strcpy(nd->ch3->text,"move left");
			nd->ch3->depth=nd->depth+1;
			nd->ch3->f=nd->depth+calc_heuristic(nd->ch3)+1;
			insert_list(nd->ch3);
			insert_queue(nd->ch3);
		}
	}
	if(x+1 >2)
	nd->ch2=NULL;
	else
	{
		nd->ch2=(node*)malloc(sizeof(node));
		copy_array(nd->ch2->a,nd->a);
		swap(&nd->ch2->a[x][y],&nd->ch2->a[x+1][y]);
		if(check_list(nd->ch2)==1)
		{
			nd->ch2=NULL;
			free(nd->ch2);
		}
		else
		{
			nd->ch2->parent=nd;
			strcpy(nd->ch2->text,"move down");
			nd->ch2->depth=nd->depth+1;
			nd->ch2->f=nd->depth+calc_heuristic(nd->ch2)+1;
			insert_list(nd->ch2);
			insert_queue(nd->ch2);
		}
	}
	if(x-1 <0)
	nd->ch1=NULL;
	else
	{
		nd->ch1=(node*)malloc(sizeof(node));
		copy_array(nd->ch1->a,nd->a);
		swap(&nd->ch1->a[x][y],&nd->ch1->a[x-1][y]);
		if(check_list(nd->ch1)==1)
		{
			nd->ch1=NULL;
			free(nd->ch1);
		}
		else
		{
			nd->ch1->parent=nd;
			strcpy(nd->ch1->text,"move up");
			nd->ch1->depth=nd->depth+1;
			nd->ch1->f=nd->depth+calc_heuristic(nd->ch1)+1;
			insert_list(nd->ch1);
			insert_queue(nd->ch1);
		}
	}
}

int is_goal(node *nd) //return 1 if goal
{
	return is_equal(nd->a,goal);
}

node *pop_queue()
{
	node *nd;
	nd=front;
	front=front->next;
	if(front==NULL)
	rear=NULL;
	return nd;
}

void final_print(node *nd)
{
	while(nd!=NULL)
	{
		printf("\n");
		print_array(nd->a);
		printf("\n%s",nd->text);
		nd=nd->parent;
		f_count++;
	}
	printf("\nNo of steps %d",f_count-1);
}

int count_queue()
{
	int count=0;
	node *temp;
	temp=front;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}

void arrange()
{
	node *t1,*t2,*t3;
	int i,j,k,l;
	i=count_queue();
	j=i;
	for(k=0;k<i;k++)
	{
		t1=front;
		t2=front->next;
		for(l=1;l<j;l++)
		{
			if(t1->next->f>t2->next->f)
			{
				t3=t2;
				t1->next=t2->next;
				t3->next=t3->next->next;
				t1->next->next=t2;
			}
			j--;
			t1=t1->next;
			t2=t2->next;
		}
	}
	t1=front;
	while(t1->next!=NULL)
	t1=t1->next;
	rear=t1;
	rear_list=t1;
}

void A_star(node *root)
{
       {
	node *nd;
	insert_queue(root);
	insert_list(root);
	nd=root;
	while(1)
	{
		nd=front;
		if(is_goal(nd)==1)
		{
			final_print(nd);
			break;
		}
		next_move(nd);
		arrange();
		nd=pop_queue();
	}
	}
}

int main()
{
	node *n;
	int i,j;
	n=(node*)malloc(sizeof(node));
	x=(node*)malloc(sizeof(node));
	printf("Enter the goal state\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&n->a[i][j]);
	n->parent=NULL;
	n->next=NULL;
	n->ch1=NULL;
	n->ch2=NULL;
	n->ch3=NULL;
	n->ch4=NULL;
	n->depth=0;
	printf("Enter the current state\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&goal[i][j]);
	n->f=calc_heuristic(n);
	printf("\nThe seq of steps are\n");
	A_star(n);
	scanf("%d",&i);
	return 0;
}
