#include<stdio.h>
#include<stdlib.h>

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

int busca_binaria(int vet[], int n, int chave)
{
    int ini=0, fim=n-1;

    while(ini<=fim)
    {
        int meio=(ini+fim/2);
        if(chave==vet[meio])
            return meio;
        else if(chave<vet[meio])
            ini = meio+1;
        else
            fim = meio-1;

    }
    return -1;
}

int *achar_menores(int vet[], int tam, int k)
{
    int *menores = (int*)malloc(sizeof(int)*k);

    if(!menores) return NULL;

    bubble_sort(vet, tam);

    for(int i=0; i<k; i++)
        menores[i] = vet[i];

    return menores;
}

void encontar_moda(int vet[], int n)
{
    if(n==0)
    {
        printf("Conjunto vazio\n");
        return;
    }
    
    bubble_sort(vet, n);

    int moda = vet[0];
    int freq_max = 1;
    int freq_atual = 1;

    for(int i=1; i<n; i++)
    {
        freq_atual = (vet[i] == vet[i-1]) ? freq_atual+1 : 1;

        if(freq_atual > freq_max)
        {
            freq_max = freq_atual;
            moda = vet[i];
        }
    }
    printf("Moda: %d (Frequência: %d)\n", moda, freq_max);
}

