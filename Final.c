#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} Lista;

Lista* inserir(Lista *l, int valor) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->info = valor;
    novo->prox = l;
    return novo;
}

void imprimir(Lista *l) {
    if (l == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Lista *aux = l;
    while (aux != NULL) {
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void bubble_sort(int vet[], int tam)
{
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam-i-1; j++){
            if(vet[j]>vet[j+1]){
                int temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}

void contar_pares(int vet[], int n)
{
    if(n==0) return;

    bubble_sort(vet, n);

    int todos = 1;
    int frequencia[1000]={0};

    for(int i=0; i<n; i++)
        frequencia[vet[i]]++;
    
    for(int i=0; i<n; i++)
    {
        if(frequencia[vet[i]]%2 != 0)
        {
            printf("%d ", vet[i]);
            todos = 0;
        }
    }
    if(todos) printf("Todos possuem pares.\n");
}

Lista *move_menor_inicio(Lista *l)
{
    if(l==NULL || l->prox==NULL) return l;

    int min = l->info;
    Lista *novo = NULL;
    Lista *aux  = l;

    while(aux!=NULL)
    {
        if(aux->info < min)
        {
            min = aux->info;
            novo = aux;
        }
    }
    aux = l;
    while(aux->prox->info != min)
        aux = aux->prox;

    aux->prox = novo->prox;
    novo->prox = l->prox;
    l = novo;
    
    return l;
}

int main()
{
    printf("Teste 1\n");
    int vet1[]={5,1,1,3,3,5,5};
    int vet2[]={1,3,5,1,5,5,2,2};

    contar_pares(vet1, 7);
    contar_pares(vet2, 8);

    printf("Teste 1\n");
    Lista *lista=NULL;
    for(int i=0; i<10; i++)
    {
        int num;
        scanf("%d", &num);
        inserir(lista, num);
    }
    move_menor_inicio(lista);
    imprimir(lista);

    Lista *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

    return 0;
}