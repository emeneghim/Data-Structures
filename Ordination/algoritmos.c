#include "algoritmos.h"
#include <time.h>

double tempo = 0.0;
clock_t inicioTimer;

//Responsável por iniciar o temporizador
void comecaTempo()
{
    inicioTimer = clock();
}

//Responsável por retornar o tempo total de execução
double retornaTempo()
{
    tempo = 0;
    clock_t fimTimer = clock();
    tempo += (double)(fimTimer - inicioTimer) / CLOCKS_PER_SEC;
    return tempo;
}

int sortearNumero(int min, int max)
{
    // Código para gerar um número aleatório entre um mínimo e um máximo
    return min + fmod(rand(), (max - min + 1));
}

int *criaVetorEmbaralhado(int n)
{
    int *vetor = (int *)malloc(n * sizeof(int));
    int tmp;

    for (int i = 0; i < n; i++)
        vetor[i] = i;

    for (int i = 0; i < n; i++)
    {
        int nAleat = sortearNumero(0, n - 1);
        tmp = vetor[i];
        vetor[i] = vetor[nAleat];
        vetor[nAleat] = tmp;
    }

    return vetor;
}

void imprime(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

void bubbleSort(int n, int *v)
{

    for (int i = n - 1; i > 0; i--)
    {
        int troca = 0;

        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
            troca = 1;
        }
        if (troca != 1)
            break;
    }
    printf("Array após BubbleSort: ");
    imprime(v, n);
}

void quickSort(int n, int *v)
{
    int inicio = v[0];
    int tmp;
    int x = 1;
    int j = n - 1;
    if (n <= 1)
        return;
    while (x <= j)
    {
        while (x < n && v[x] <= inicio)
            x++;
        while (v[j] > inicio)
            j--;
        if (x < j)
        {
            tmp = v[x];
            v[x] = v[j];
            v[j] = tmp;
            x++;
            j--;
        }
    } 
    v[0] = v[j];
    v[j] = inicio;
    quickSort(j, v);
    quickSort(n - x, &v[x]);
}

int buscaLinear(int n, int* vet, int elem)
{
    if (vet != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            if (vet[i] == elem)
                return i;
        }
    }

    return -1;
}

int buscaBinaria(int n, int* vet, int elem)
{
    
    if (vet != NULL)
    {
        int ini = 0;
        int fim = n-1;
        int meio = 0;
        while (ini <= fim)
        {
            meio = (ini+fim)/2; //Pega o meio do treco do array
            if (elem < vet[meio])
                fim = meio-1;
            else
            if (elem > vet[meio])
                ini = meio+1;
            else
            {
                return meio;
            }
        }
    }

    return -1;
}

void mergeSort(int n, int* v)
{
    
}