#include<stdio.h>
#include<stdlib.h>

typedef struct tnode{
    struct tnode *next;
    int valor;
}Node;

Node *criaLista(){
    return NULL;
}

Node *criaNode(int valor){
    Node *novo;
    if(!(novo=(Node *)malloc(sizeof(Node)))) return NULL;
    novo->next=NULL;
    novo->valor=valor;
    return novo;
}

Node *removeInicio(Node *lst){
    Node *ptr;
    if(!lst) return lst;
    if(lst->next==lst){
        free(lst);
        return NULL;
    }
    for(ptr=lst;ptr->next!=lst;ptr=ptr->next);
    ptr->next=lst->next;
    free(lst);
    return ptr->next;
}

Node *removeFim(Node *lst){
    Node *ptr;
    if(!lst) return lst;
    if(lst->next==lst){
        free(lst);
        return NULL;
    }
    for(ptr=lst;ptr->next->next!=lst;ptr=ptr->next);
    free(ptr->next);
    ptr->next=lst;
    return lst;
}

Node *removeChave(Node *lst,int chave){
    Node *ptr,*aux;
    if(!lst) return lst;
    for(ptr=lst,aux=ptr;ptr->next!=lst && ptr->valor!=chave;aux=ptr,ptr=ptr->next);
    if(ptr->valor==chave){
        if(ptr->next==ptr){ //verifica se existe apenas 1 elemento
            free(ptr);
            return NULL;
        }
        if(aux==ptr){       //verifica se eh o primeiro e se existem mais elementos
            for(;ptr->next!=lst;ptr=ptr->next);
            lst=lst->next;
            ptr->next=lst;
            free(aux);
        }else{
            aux->next=ptr->next;
            free(ptr);
        }
    }
    return lst;
}

Node *insereInicio(Node *lst,int valor){
    Node *ptr,*aux;
    if(!(ptr=criaNode(valor))) return lst;
    if(!lst){
        ptr->next=ptr;
    }else{
        for(aux=lst;aux->next!=lst;aux=aux->next);
        aux->next=ptr;
        ptr->next=lst;
    }
    return ptr;
}

Node *insereFim(Node *lst,int valor){
    Node *ptr,*aux;
    if(!(ptr=criaNode(valor))) return lst;
    if(!lst){
        ptr->next=ptr;
        return ptr;
    }else{
        for(aux=lst;aux->next!=lst;aux=aux->next);
        aux->next=ptr;
        ptr->next=lst;
    }
    return lst;
}

void imprime(Node *lst){
    Node *ptr;
    if (!lst){
        printf("Lista vazia.");
        return;
    }
    for(ptr=lst;ptr->next!=lst;ptr=ptr->next){
        printf("\t%d ",ptr->valor);
    }
    printf("\t%d \t%d",ptr->valor,ptr->next->valor);

}


int main(){

    Node *lista1,*lista2;

    lista1=criaLista();
    lista2=criaLista();

    lista1=insereFim(lista1,1);
    lista1=insereInicio(lista1,50);
    lista1=insereInicio(lista1,25);
    lista1=insereFim(lista1,2);
    lista1=insereFim(lista1,3);
    lista1=insereFim(lista1,4);

    lista2=insereInicio(lista2,1);
    lista2=insereFim(lista2,99);
    lista2=insereInicio(lista2,2);
    lista2=insereInicio(lista2,3);
    lista2=insereInicio(lista2,4);

    imprime(lista1);
    printf("\n");
    imprime(lista2);

    lista2=removeInicio(lista2);

    printf("\n");
    imprime(lista2);

    lista1=removeChave(lista1,25);
    lista1=removeChave(lista1,50);
    lista1=removeChave(lista1,4);
    lista1=removeChave(lista1,1);
    lista1=removeChave(lista1,2);
    lista1=removeChave(lista1,33);

    printf("\n");
    imprime(lista1);


    return 1;
}
