#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int buscaMaisProximo(int v[], int n, int x)
{
    if(n==0) return -1;

    int ini=0, fim=n-1;
    int maisProx = v[0];

    while(ini<=fim)
    {
        int meio = (ini+fim)/2;

        if(abs(v[meio]- x) < abs(maisProx - x) ||
          (abs(v[meio] -x) == abs(maisProx - x) && v[meio] < maisProx))
        {
            maisProx = v[meio];
        }

        if(v[meio] == x)
            return v[meio]; // se o valor for igual a x, abs=0

        else if (v[meio] < x)
            ini = meio + 1;
        
        else
            fim = meio - 1;
        
    }
    return maisProx;
}

void contarRegistros(int vet[], int n)
{
    bubble_sort(vet, n);

    int lim = n/3;
    int cont = 1;
    int flag = 1;

    for(int i=1; i<n; i++)
    {
        if(vet[i] == vet[i-1])
            cont++;
        else
        {
            if(cont > lim ){
                printf("%s%d", flag?"":" ", vet[i-1]);
                flag = 0;
            }
            cont = 1;
        }
    }
    if(cont > lim)  
        printf("%s%d", flag?"":" ", vet[n-1]);

    if(flag)
        printf("Nao possui registros.\n");
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

void elementos_intervalo(int vet[], int n, int a, int b)
{
    int flag = 1;
    
    for(int i=0; i<n; i++)
    {
        if(vet[i]>a && vet[i]<b)
        {
            printf("%d ", vet[i]);
            flag = 0;
        }
    }
    if(flag)
        printf("Sem elementos no intervalo\n");
}

void ordenarPorParidade(int vet[], int n)
{
    int pares[n], impares[n];
    int contPar=0, contImpar=0;

    for(int i=0; i<n; i++)
    {
        if(vet[i]%2==0)
            pares[contPar++];
        else
            impares[contImpar++];
    }
    bubble_sort(pares, contPar);
    bubble_sort(impares, contImpar);

    for(int i=0; i<contPar; i++)
        vet[i]=pares[i];
    for(int i=0; i<contImpar; i++);
        vet[contPar + i] = impares[i];

}

void verificarSoma(int vet[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((vet[i]+vet[j]) == x)
            {
                printf("Sim.\n");
                return;
            }
        }
    }
    printf("Nao.\n");
}