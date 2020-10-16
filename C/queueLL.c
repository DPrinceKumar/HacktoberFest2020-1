// Queue using Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front,*rear,*temp,*front1;


int count = 0;

void main()
{
    int value, option, e;
    printf("\n=== QUEUE OPERATIONS ===");
    printf("\n 1) ENQUEUE");
    printf("\n 2) DEQUEUE");
    printf("\n 3) DISPLAY");
    printf("\n 4) EXIT");
    while (1)
    {
        printf("\nEnter option: ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Invalid Character!");
            break;
        }
    }
}


void enqueue(int value)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear -> next = NULL;
        rear -> data = value;
        front = rear;
        printf("Successfully Inserted!\n");
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->next = temp;
        temp->data = value;
        temp->next = NULL;
        rear = temp;
        printf("Successfully Inserted!\n");
    }
    count++;
}




void display()
{
    front1 = front;
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("EMPTY QUEUE");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->data);
        front1 = front1->next;
    }
    if (front1 == rear)
        printf("%d", front1->data);
}



void dequeue()
{
    front1 = front;
    if (front1 == NULL)
    {
        printf("\nERROR");
        return;
    }
    else
    {
        if (front1->next != NULL)
        {
            front1 = front1->next;
            printf("\nDEQUEUED: %d", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("\nDEQUEUED: %d", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
    }
    count--;
}

