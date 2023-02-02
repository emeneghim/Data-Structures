#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <math.h>
#include <time.h>

int main(void)
{
    plista lst;

    srand(time(NULL)); // Seta a seed para sortear números

    criarLista(&lst);

    inserirInicio(&lst, 'n');
    inserirInicio(&lst, 'm');
    inserirInicio(&lst, 'l');
    inserirInicio(&lst, 'k');
    inserirInicio(&lst, 'j');
    inserirInicio(&lst, 'i');
    inserirInicio(&lst, 'h');
    inserirInicio(&lst, 'g');
    inserirInicio(&lst, 'f');
    inserirInicio(&lst, 'e');
    inserirInicio(&lst, 'd');
    inserirInicio(&lst, 'c');
    inserirInicio(&lst, 'b');
    inserirInicio(&lst, 'a');



    josephus(&lst);

}