#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void criarLista(lista **l)
{
    *l = NULL;
}

// void excluirLista(lista *l);

int listaVazia(lista **l)
{
    return (*l == NULL);
}

void inserirInicio(lista **l, int d)
{
    bloco *b = (bloco *)malloc(sizeof(bloco));

    b->dado = d;
    b->prox = *l;
    *l = b;
}

void inserirFinal(lista **l, int d)
{
    bloco *b = (bloco *)malloc(sizeof(bloco));
    bloco *tmp = *l;

    b->dado = d;
    b->prox = NULL;

    while (tmp->prox != NULL)
        tmp = tmp->prox;
    tmp->prox = b;
}

void inserirPosK(lista **l, int d, int k)
{

    if (!listaVazia(l))
    {
        if (k == 1)
            inserirInicio(l, d);

        else
        {

            int pos = 1;
            bloco *b = (bloco *)malloc(sizeof(bloco));
            bloco *tmp = *l;
            bloco *ant = NULL;

            b->dado = d;
            b->prox = NULL;

            while (pos < k && tmp->prox != NULL)
            {
                ant = tmp;
                tmp = tmp->prox;
                pos++;
            }
            ant->prox = b;
            b->prox = tmp;
        }
    }
}

int removerInicio(lista **l)
{
    if (!listaVazia(l))
    {
        bloco *tmp = *l;
        int dado = tmp->dado;
        *l = tmp->prox;

        free(tmp);

        return dado;
    }
}

int removerFinal(lista **l)
{
    if (!listaVazia(l))
    {
        bloco *tmp = *l;
        int dado = tmp->dado;
        bloco *ant = NULL;

        while (tmp->prox != NULL)
        {
            ant = tmp;
            tmp = tmp->prox;
        }

        ant->prox = NULL;
        free(tmp);

        return dado;
    }
}

int removerPosK(lista **l, int k)
{
    int dado;
    if (!listaVazia(l))
    {
        if (k == 1)
            dado = removerInicio(l);
        else
        {
            int pos = 1;
            bloco *tmp = *l;
            bloco *ant = NULL;

            while (pos < k && tmp->prox != NULL)
            {
                ant = tmp;
                tmp = tmp->prox;
                pos++;
            }
            dado = tmp->dado;
            ant->prox = tmp->prox;
            free(tmp);
        }
        return dado;
    }
}

void imprime(lista **l)
{

    bloco *tmp = *l;
    while (tmp != NULL)
    {
        printf("Dado: %d\n", tmp->dado);
        tmp = tmp->prox;
    }
}

void inserirOrdenada(lista **l, int d)
{
    bloco *b = (bloco *)malloc(sizeof(bloco)); // Cria um bloco
    bloco *tmp = *l;                           // Tmp = primeiro bloco
    bloco *ant = NULL;                         // Anterior não existe já que começamos no primeiro bloco

    b->dado = d;    // b recebe dado
    b->prox = NULL; // b não possui próximo ainda

    if (!listaVazia(l))
    {
        if (b->dado <= tmp->dado) // Se o dado do b for menor que o dado do 1º bloco -> Insere início
            inserirInicio(l, d);

        else if (b->dado > tmp->dado) // Se o dado do b for maior que o dado do 1º bloco ->
        {                             // Percore de bloco em bloco até achar o local certo
            while (tmp->prox != NULL)
            {
                b->prox = tmp->prox;
                ant = tmp;
                tmp = tmp->prox;

                if (b->dado > ant->dado && b->dado <= tmp->dado)
                    break;
            }
            if (tmp->prox == NULL && b->dado > tmp->dado) // Se a lista ja foi percorrida e o dado de b ainda for
                inserirFinal(l, d);                       //  maior, insere no fim
            else
                ant->prox = b;
        }
    }
    else
        inserirInicio(l,d);
}

int main()
{
    lista *a;
    criarLista(&a);

    inserirOrdenada(&a, 21);
    inserirOrdenada(&a, 355);
    inserirOrdenada(&a, 2);
    inserirOrdenada(&a, 89);
    inserirOrdenada(&a, 12);

    imprime(&a);
}
