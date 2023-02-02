#include "info.h"

void criarLista(lista **l);
void excluirLista(lista *l);
int listaVazia(lista **l);
void inserirInicio(lista **l, int d);
void inserirFinal(lista **l, int d);
void inserirPosK(lista **l, int d, int k);
int removerInicio(lista **l);
int removerFinal(lista **l);
int removerPosK(lista **l, int k);
void inserirOrdenada(lista **l, int d);
void imprime(lista **l);