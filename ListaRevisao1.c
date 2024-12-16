#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} Lista;

int contar_nos(Lista *l){
    if(l==NULL)
        return 0;
    return 1+contar_nos(l->prox);
}

Lista *copiar_lista(Lista *l){
    Lista *new = NULL;
    while(l!=NULL){
        new = l;
        l=l->prox;
        new=new->prox;
    }
    return new;
}

Lista *concatena(Lista *l1, Lista *l2)
{
    Lista *aux = l2;
    while (aux->prox!=NULL)
        aux=aux->prox;
    aux->prox=l1;
    return l2;
}

Lista *vet2list(int vet[], int n)
{
    if(n==0) return NULL;
    
    Lista *lista=NULL;
    Lista *aux = NULL;
    
    for(int i=0; i<n; i++)
    {
        Lista *novo = (Lista*)malloc(sizeof(Lista));
        
        novo->info=vet[i];
        novo->prox=NULL;

        if(lista==NULL) lista = novo;

        else aux->prox = novo;

        aux = novo;
    }
    return lista;
}

Lista *remove_n_nos(Lista *l, int n)
{
    if(l==NULL || n<=0) return l;

    for(int i=0; i<n; i++)
    {
        if(l==NULL) break;

        Lista *temp = l;
        l = l->prox;
        free(temp);
    }
    return l;
}

Lista *inverte_lista(Lista *l)
{
    if(l==NULL || l->prox==NULL) return l;

    Lista *anterior = NULL;
    Lista *atual = l;
    Lista *proximo = NULL;

    while(atual!=NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}