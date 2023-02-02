#include "algoritmos.c"
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL)); // Seta a seed para sortear números

    int length = 10;
    double tempoAux = 0.0; //Para ajudar nos testes de tempo

    //---------------------------BUBBLESORT---------------------------

    int *arr = criaVetorEmbaralhado(length); //Cria o vetor embaralhado
    printf("Array embaralhado: ");
    imprime(arr, length); //Imprime o vetor embaralhado

    //Fazemos o bubblesort e calculamos o tempo
    comecaTempo();
    bubbleSort(length, arr);
    tempoAux = retornaTempo();

    //Imprimimos os resultados do bubblesort
    printf("Array após BubbleSort: ");
    imprime(arr, length);
    printf("O tempo tomado pelo bubblesort foi de %f segundos\n", tempoAux);

    //---------------------------QUICKSORT---------------------------

    arr = criaVetorEmbaralhado(length); //Cria o vetor embaralhado
    printf("Array embaralhado: ");
    imprime(arr, length); //Imprime o vetor embaralhado

    //Fazemos o quicksort e calculamos o tempo
    comecaTempo();
    quickSort(length, arr);
    tempoAux = retornaTempo();

    //Imprimimos os resultados do quicksort
    printf("Array após QuickSort: ");
    imprime(arr, length);
    printf("O tempo tomado pelo quicksort foi de %f segundos\n", tempoAux);

    //---------------------------BUSCA---------------------------

    for (int i = 1; i <= 5; i++)
    {
        length = pow(10,i); //Faremos 5 buscas diferentes, 10¹, 10², 10³, 10⁴ e 10⁵ elementos cada
        int numeroSorteado = sortearNumero(0, length-1); //Sortearemos um número para encontramos no vetor

        //Cabeçalho para ficar mais agradável a visualização
        printf("\n----------------------//----------------------\n\n");
        printf("Tamanho: %d\n", length);
        printf("Número: %d\n\n", numeroSorteado);

        //Criamos e ordenamos o vetor para usarmos as buscas
        arr = criaVetorEmbaralhado(length);
        quickSort(length, arr);

        //Fazemos a busca linear, assim como calculamos o tempo dela
        comecaTempo();
        printf("Pela busca linear, o elemento está na posição %d\n",buscaLinear(length, arr, numeroSorteado));
        printf("O tempo tomado para a busca linear foi de %f segundos\n\n", retornaTempo());

        //Fazemos a busca binária, assim como calculamos o tempo dela
        comecaTempo();
        printf("Pela busca binária, o elemento está na posição %d\n",buscaBinaria(length, arr, numeroSorteado));
        printf("O tempo tomado para a busca binária foi de %f segundos\n", retornaTempo());
    }

    return 0;
}