#include <stdio.h>
#include <stdlib.h>

#define MAXPRIOR 4

typedef struct node{
    int prior;
    int value;
    struct node *next;
}Node;

typedef struct{
    int size;
    Node *lst;
}Queue;

typedef struct{
    int size;
    Queue queues[MAXPRIOR];
}PQueue;

PQueue *createPQueue(){
    PQueue *ptr;
    if(!(ptr=(PQueue *)malloc(sizeof(PQueue)))) return NULL;
    for(int i=0;i<MAXPRIOR;i++){
        ptr->queues[i].lst=NULL;
        ptr->queues[i].size=0;
    }
    ptr->size=0;
    return ptr;
}

Node *createNode(int prior,int value){
    Node *ptr;
    if(!(ptr=(Node *)malloc(sizeof(Node)))) return NULL;
    ptr->prior=prior;
    ptr->value=value;
    ptr->next=NULL;
    return ptr;
}

int isEmptyPQueue(PQueue *pqueue)
{
    return (!pqueue || pqueue->size==0);
}

void printPQueue(PQueue *pq){
    Node *ptr;
	int i;
    if(isEmptyPQueue(pq)) return;
    for(i=0;i<MAXPRIOR && pq->queues[i].lst==NULL;i++)
    {    printf("\n%d ",i);}
    if(pq->queues[i].lst!=NULL)
    {
		printf("\n[ ");
		ptr=pq->queues[i].lst;
		for(;ptr;ptr=ptr->next) printf("(%d) ",ptr->value);
		printf(" ]");
	}
}

//recupera o elemento anterior ao que será inserido na sublista
Node *getPreviousPriority(PQueue *pq,int prior){
    Node *aux;
    if(!pq || prior<0 || prior>=MAXPRIOR) return NULL;
    int i=prior-1,j;
    while(i>0 && pq->queues[i].lst==NULL) i--;
    if(i<0) return NULL;
    aux=pq->queues[i].lst;
    for(j=1;j<(pq->queues[i].size);j++,aux=aux->next);
    return aux;
}

//recupera o elemento posterior ao que será inserido na sublista
Node *getNextPriority(PQueue *pq,int prior){
    int i=0;
    if(!pq || prior<0 || prior>=MAXPRIOR) return NULL;
    for(i=prior+1;pq->queues[i].size==0;i++){
        if(i==MAXPRIOR)
            return NULL;
    }
    return pq->queues[i].lst;
}

//insere o elemento na sublista da sua prioridade
void insertPQueue(PQueue *pq,int prior, int value){
    Node *ptr,*auxAntes,*auxDepois;
    if(prior<0 || prior>=MAXPRIOR) return;
    if(!pq || !(ptr=createNode(prior,value))) return;

    if(pq->queues[prior].size==0){
        auxAntes=getPreviousPriority(pq,prior);
        auxDepois=getNextPriority(pq,prior);
        if(auxAntes) auxAntes->next=ptr;
        ptr->next=auxDepois;
        pq->queues[prior].lst=ptr;
    }
    else{
        int i;
        auxDepois=pq->queues[prior].lst;
        for(i=1;i<pq->queues[prior].size;i++,auxDepois=auxDepois->next);
        ptr->next=auxDepois->next;
        auxDepois->next=ptr;
    }
    pq->size++;
    pq->queues[prior].size++;
    return;
}

int main(){
    PQueue *pqueue=createPQueue();
    insertPQueue(pqueue,0,253);
    insertPQueue(pqueue,2,78111);
    insertPQueue(pqueue,3,789);
    insertPQueue(pqueue,2,8);
    insertPQueue(pqueue,1,7);
    insertPQueue(pqueue,0,5);
    printPQueue(pqueue);

    return 1;
}

