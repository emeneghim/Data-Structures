#include "lista.h"

int listaVazia(plista l)
{
    return (l->dimensao == 0);
}

void criarLista(pplista l)
{
    *l = (struct lista *)malloc(sizeof(struct lista)); // mudei a forma de declaracao do malloc e resolveu o segmentation fault
    (*l)->inicio = NULL;
    (*l)->final = NULL;
    (*l)->dimensao = 0;
}

void inserirInicio(pplista l, char c)
{

    pbloco b = (bloco *)malloc(sizeof(bloco));
    b->plv = c;

    if ((*l)->dimensao != 0)
    {
        b->prox = (*l)->inicio;
        (*l)->inicio = b;
        (*l)->final->prox = b;
    }
    else
    {
        b->prox = b;
        (*l)->inicio = b;
        (*l)->final = b;
    }

    (*l)->dimensao += 1;
}

// int removerPosK(pplista l, int p)
// {

//     if ((*l)->dimensao > 0)
//     {
//         int num;
//         if (p == 1)
//             num = removerInicio(l);
//         else
//         {
//             if (p > (*l)->dimensao)
//                 num = removerFinal(l);
//             else
//             {
//                 int pos = 1;
//                 bloco *tmp = (*l)->inicio;
//                 bloco *ant = NULL;

//                 while (pos < p)
//                 {
//                     ant = tmp;
//                     tmp = tmp->prox;
//                     pos++;
//                 }

//                 num = tmp->num;
//                 ant->prox = tmp->prox;
//                 (*l)->dimensao--;
//                 free(tmp);
//             }
//         }

//         return num;
//     }
// }

int sortearNumero(int min, int max)
{
    // Código para gerar um número aleatório entre um mínimo e um máximo
    return min + fmod(rand(), (max - min + 1));
}

void imprimirLista(pplista l)
{

    if ((*l)->dimensao > 0)
    {
        int i = 1;
        bloco *tmp = (*l)->inicio;

        while (i <= (*l)->dimensao)
        {
            printf("Elemento: %c\n", tmp->plv);
            tmp = tmp->prox;
            i++;
        }
    }
}

void josephus(pplista l)
{
    while ((*l)->dimensao > 1)
    {
        imprimirLista(l);
        printf("\n");

        pbloco tmp = (*l)->inicio;
        pbloco ant = NULL; // Cria a varíavel anterior

        int i = sortearNumero(1, (*l)->dimensao); // Sorteia o índice do soldado

        for (int j = 0; j < i; j++) // Encontra o soldado do índice
        {
            tmp = tmp->prox;
        }

        int d = sortearNumero(1, (*l)->dimensao * 2); // Sorteia o número

        for (int i = 0; i < d; i++) // Percorre a lista de acordo com o número sorteado
        {
            ant = tmp;
            tmp = tmp->prox;
        }

        ant->prox = tmp->prox; // Altera a ordem da lista substituindo o soldado removido
        (*l)->dimensao--;

        // Caso o soldado removido seja o início, substituímos
        if ((*l)->inicio->plv == tmp->plv)
            (*l)->inicio = ant->prox;

        free(tmp); // Libera a memória do soldado removido
    }
    printf("Último elemento:\n");
    imprimirLista(l);
}
