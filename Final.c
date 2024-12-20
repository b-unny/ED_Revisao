#include<stdio.h>
#include<stdlib.h>

// auxiliares 
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
    novo->prox = NULL;

    if (l == NULL)  return novo;

    // Encontrar o último nó
    Lista *aux = l;
    while (aux->prox != NULL)
        aux = aux->prox;

    // Inserir no fim
    aux->prox = novo;

    return l;
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

// Questao 1
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

// Questao 2
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
        aux = aux->prox;
    }
    aux = l;
    while(aux->prox->info != min)
        aux = aux->prox;

    aux->prox = novo->prox;
    novo->prox = l->prox;
    l = novo;
    
    return l;
}

int main() {
    // Testando a lista encadeada
    Lista *lista = NULL;

    // Inserindo elementos
    lista = inserir(lista, 5);
    lista = inserir(lista, 3);
    lista = inserir(lista, 7);
    lista = inserir(lista, 2);

    printf("Lista original:\n");
    imprimir(lista);

    // Movendo o menor elemento para o início
    lista = move_menor_inicio(lista);
    printf("Lista após mover o menor elemento para o início:\n");
    imprimir(lista);

    // Testando bubble_sort e contar_pares
    int vetor[] = {4, 3, 7, 4, 3, 7, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Frequência dos elementos sem pares:\n");
    contar_pares(vetor, tamanho);

    printf("\nVetor ordenado:\n");
    bubble_sort(vetor, tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}