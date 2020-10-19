#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>



struct Queue { 
    int front, rear, size; 
    int capacity; 
    int* array; 
}; 

typedef struct Node {
    int data;
    struct Node* next;
}node;
  


struct Queue* createQueue(int capacity) 
{ 
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1; 
    queue->array = (int*)malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  

int isFull(struct Queue* queue) 
{ 
    return (queue->size == queue->capacity); 
} 
  
 
int isEmpty(struct Queue* queue) 
{ 
    return (queue->size == 0); 
} 
  
int front(struct Queue* queue) 
{ 
    if (isEmpty(queue))return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
 
int rear(struct Queue* queue) 
{ 
    if (isEmpty(queue))return INT_MIN; 
    return queue->array[queue->rear]; 
} 

void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) return; 
    queue->rear = (queue->rear + 1)% queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    
} 
  
 
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue))return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)% queue->capacity; 
    queue->size = queue->size - 1;return item; 
} 
  
int n;


void matrixAddingEdge(int graph[][n] , int v ,int u){
    graph[v][u] = 1;
}

void insert(int v,int u,node* Graph[])
{
    node *p,*q;
    
	
	q=(node*)malloc(sizeof(node));
    q->data=u;
    q->next=NULL;
 
    
    if(Graph[v]==NULL)
        Graph[v]=q;
    else
    {
        
        p=Graph[v];
       
		while(p->next!=NULL)
        	p=p->next;
        p->next=q;
    }
}


void addingEdge(node* arr[] , int v , int u){
    
    insert(v, u,arr);
    insert(u, v, arr);
}

void matrixBreadthFirstSearch(int graph[][n] , int size, int start ) {
    bool visited[size] ; 

    for (int i = 0 ; i < size ; i++)
    visited[i] = false;

    struct Queue* q = createQueue(100) ; 

    enqueue(q, start);
    visited[start] = true;

    while (!isEmpty(q)){
        int current = front(q);
        dequeue(q);
        printf("%d ", current);
        for (int i = 0 ; i < size ; i++){
            if (graph[current][i] && !visited[i]){
                enqueue(q,i);
                visited[i] = true;
            }
        }
    }

        
}

void listBreadthFirstSearch (node* arr[] , int start){
    
    struct Queue* q = createQueue(100);
    bool visited[n];

    for (int i = 0 ; i < n ; i++)
    visited[i] = false;

    enqueue(q,start);
    visited[start] = true;
    
    while(!isEmpty(q)){
        int current = front(q);
        dequeue(q);

        printf("%d " , current) ;
        visited[current] = true ;

        node* temp = arr[current];

        while(temp){
            if (!visited[temp->data]){
            enqueue(q,temp->data);
            visited[temp->data] = true;
            }
            temp = temp->next ;
        }

        
    }
    
}

bool checkingBipartite(node* arr[] , int start){
     int nodeCol[n] ;
     for (int i = 0 ; i < n ; i++)
     nodeCol[i] = -1;

     struct Queue* q = createQueue(100) ;
     enqueue(q , start) ;
     nodeCol[start] = 1;
   

     while (!isEmpty(q)){
        int current = front(q);
        dequeue(q);

        node* temp = arr[current] ;
        while(temp){
            if (nodeCol[temp->data] == -1){
                enqueue(q , temp->data) ;
                nodeCol[temp->data] = 1 - nodeCol[current] ; 
            }

            else if (nodeCol[temp->data] == nodeCol[current])
            return false ;

            temp = temp ->next ;
        }
    }
    return true;
}



int main(){
    
    printf("Enter the number of nodes: \n");
    scanf("%d",&n);

    int graph[n][n];

    for (int i = 0 ; i < n ; i++){

         for (int j = 0 ; j < n ; j++)
         graph[i][j] = 0 ;

    }

    int Edge,ve,ue,st;
    printf("Enter number of v u pairs\n");
    scanf("%d",&Edge);

    printf("Enter v and u one by one\n");
    for(int i=0; i<Edge; i++){

        scanf("%d %d",&ve,&ue);
        matrixAddingEdge(graph,ve,ue);
    }

    printf("Enter the starting Node For Search\n");
    scanf("%d",&st);

    matrixBreadthFirstSearch(graph,n,st);

    node* head[n];

    for (int i = 0 ; i < n ; i++)
    head[i] = NULL;

    printf("\nEnter number of v u pairs\n");
    scanf("%d",&Edge);

    printf("Enter v and u one by one\n");
    for(int i = 0 ; i < Edge ; i++){
        scanf("%d %d",&ve,&ue);
         addingEdge(head,ve,ue);
    }

    

    if (checkingBipartite(head,0))printf("Yes\n");
    else 
    printf("No\n");

    return 0;

}
