#include<stdio.h>
#include<stdlib.h>

typedef struct No
{
    int info;
    struct No *prox;
} No;

void remove_negativo(No *F)
{
    No *aux = F;

    while(aux!=NULL && aux->info<0)
    {
        No *temp = aux;
        *F = *F->prox;
        free(temp);
    }

    while(aux!=NULL && aux->prox!=NULL)
    {
        if(aux->prox->info<0)
        {
            No *temp = aux->prox;
            aux->prox = aux->prox->prox;
            free(temp);
        }
        else aux = aux->prox;
    }
}

void libera_lista(No *lista) {
    No *aux;
    while (lista != NULL) {
        aux = lista;          // Salva o ponteiro atual
        lista = lista->prox;  // Avança para o próximo nó
        free(aux);            // Libera o nó atual
    }
}

No *separa_lista(No* lista, int n) // lista sera a lista2
{
    No *aux = lista;
    
    if(lista==NULL)    return NULL;
    
    if(lista->info==n) return lista;

    while(aux->prox!=NULL)
    {
        if(aux->prox->info==n)
        {
            No *nova_lista = aux->prox;
            aux->prox=NULL;
            return nova_lista;
        }
        aux=aux->prox;
    }
    return NULL;
}

No* insere_pilha(No* topo, int valor)
{
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    novo_no->info = valor;
    novo_no->prox = topo; // Aponta para o antigo topo

    return novo_no; 
}

No *intercala_pilha(No *p1, No *p2)
{
    if(p1==NULL) return p2;
    if(p2==NULL) return p1;

    No *p3 = NULL;

    while(p1!=NULL && p2!=NULL)
    {
        p3 = insere_pilha(p3, p1->info);
        p3 = insere_pilha(p3, p2->info);
        p1=p1->prox;
        p2=p2->prox;
    }

    return p3;
}

No* remove_maior_que_limite(No* pilha, int L)
{
    if(pilha==NULL)  return NULL;

    while(pilha!=NULL && pilha->info>L)
    {
        No* temp = pilha;
        pilha=pilha->prox;
        free(temp);
    }

    No *topo = pilha;

    while(topo!=NULL && topo->prox!=NULL)
    {
        if(topo->prox->info > L)
        {
            No *temp = topo->prox;
            topo->prox = temp->prox;
            free(temp);
        }
        else 
            topo=topo->prox;
    }
    return pilha;
}

No *mover_max_para_inicio(No* fila)
{
    if(fila==NULL || fila->prox==NULL) return fila;

    No *aux = fila;
    No *new = NULL;
    int max = fila->info;
    
    // procurar o no com maior valor
    while(aux!=NULL){
        if(aux->info > max){
            max = aux->info;
            new = aux;
        }
        aux = aux->prox;
    }
    // se o maior estiver no inicio
    if(new==fila) return fila;

    // encontar o no que aponta p o maior valor
    aux=fila;
    while(aux->prox!=new)
        aux = aux->prox;

    // ajustando os ponteiros pra mover o maior pro inicio
    aux->prox = new->prox;
    new->prox = fila;
    fila = new;

    return fila;
}

