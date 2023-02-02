#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int* criaVetorEmbaralhado(int n);
int sortearNumero(int min, int max);
void imprime(int *array, int n);
void bubbleSort(int n, int* v);
void quickSort(int n, int* v);
void mergeSort(int n, int* v);

void comecaTempo();
double retornaTempo();

int buscaLinear(int n, int* vet, int elem);
int buscaBinaria(int n, int* vet, int elem);



#endif