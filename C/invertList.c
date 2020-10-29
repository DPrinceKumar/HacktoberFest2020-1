#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tnode{
    struct tnode *next,*prev;
    char letra;
}Node;

Node *criaLista(){
    return NULL;
}

Node *criaNode(char letra){
    Node *novo;
    if(!(novo=(Node *)malloc(sizeof(Node)))) return NULL;
    novo->next=novo->prev=NULL;
    novo->letra=letra;
    return novo;
}

Node *insereLista(Node *lst,char letra){
    Node *ptr,*aux;
    if(!(ptr=criaNode(letra))) return lst;
    ptr->letra=letra;
    if(!lst) return ptr;
    for(aux=lst;aux->next!=NULL;aux=aux->next);
    aux->next=ptr;
    ptr->prev=aux;
    return lst;
}

Node *inverteString(Node *inicio,Node *fim){
    //prev guarda anterior ao limite da esquerda e next posterior ao limite da direita
    Node *prev=inicio->prev,*current=inicio,*next=fim->next,*pptr,*nptr;
    inicio->prev=pptr=fim->next=NULL; //faz os apontamentos antes e depois serem nulos para inverter como DList
    while(current){
        nptr=current->next;
        current->prev=nptr;
        current->next=pptr;
        pptr=current;
        current=nptr;
    }
    if(!prev && next){
        inicio->next=next;
        next->prev=inicio;
        return fim;
    }
    if(!next && prev){
        fim->prev=prev;
        prev->next=fim;
        return prev;
    }
    if(!prev && !next) return fim;
    fim->prev=prev;
    prev->next=fim;
    inicio->next=next;
    next->prev=inicio;
    return prev;
}

Node *codifica(Node *lst){
    Node *aux1,*aux2,*ant,*aux3=lst;
    if(!lst) return lst;
    for(aux1=lst;aux1!=NULL;aux1=aux1->next){
        if(aux1->letra!='a' && aux1->letra!='e' && aux1->letra!='i' && aux1->letra!='o' && aux1->letra!='u'){
            for(aux2=aux1->next,ant=aux1;(aux2!=NULL) && (aux2->letra!='a' && aux2->letra!='e' && aux2->letra!='i'
                && aux2->letra!='o' && aux2->letra!='u');ant=aux2,aux2=aux2->next);
            if(lst==aux1) lst=ant;
            if(aux1!=ant)
                aux3=inverteString(aux1,ant);
            aux1=aux2;
            if(!aux2) return lst;
        }
    }
    return lst;
}

void imprimeLista(Node *lst){
    Node *ptr;
    for(ptr=lst;ptr!=NULL;ptr=ptr->next){
        printf("%c",ptr->letra);
    }
}

int main(){

    char palavra[50];
    int i;

    Node *lista=criaLista();

    printf("Insira a palavra:");
    gets(palavra);

    for(i=0;i<strlen(palavra);i++){
        lista=insereLista(lista,palavra[i]);
    }

    lista=codifica(lista);

    imprimeLista(lista);
    return 1;

}
