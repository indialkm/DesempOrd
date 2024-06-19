#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "sort.h"

int* alocaArray(int n)
{
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return arr;
}

void liberaArray(int *arr)
{
    free(arr);
}

void transformarEmDecrescente(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void medirTempo(void(*menuOrdencao)(int, int[], int), int escolha, int n)
{
    int *arr;
    struct timeval tempo_antes, tempo_depois;
    double delta_T;
    double tempo[10];
    double tempoSoma;
    double mediaDesempenho;
    int i = 0;

    //Mádia com as 10
    for(i = 0; i < 10; i++){

    arr = alocaArray(n);

    gerandoArray(arr, n);

    gettimeofday(&tempo_antes, NULL);

    menuOrdencao(escolha, arr, n);

    gettimeofday(&tempo_depois, NULL);

    delta_T = (tempo_depois.tv_sec + tempo_depois.tv_usec / 1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_usec / 1000000.0);
    //printf("O tempo dentro execucao foi de %f\n", delta_T);

    tempo[i] = delta_T;

    liberaArray(arr);
    }


    for(i = 0; i < 10; i++){
        tempoSoma += tempo[i];
    }

    mediaDesempenho = tempoSoma / 10 ;
    printf("\nEssa e a media %f\n", mediaDesempenho);
    melhorCaso(menuOrdencao,escolha, n);
    piorCaso(menuOrdencao,escolha, n);



}

void melhorCaso(void(*menuOrdencao)(int, int[], int),int escolha, int n){

    int *arr;
    arr = alocaArray(n);
    int i;
    struct timeval tempo_antes, tempo_depois;
    double delta_T;

    //Criando array crescente ordenado
    for(i = 0; i < n; i++){
        arr[i] = i;
    }

    gettimeofday(&tempo_antes, NULL);

    menuOrdencao(escolha, arr, n);

    gettimeofday(&tempo_depois, NULL);

    delta_T = (tempo_depois.tv_sec + tempo_depois.tv_usec / 1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_usec / 1000000.0);
    printf("\nO tempo para ordenar um array ordenado e de: %f\n", delta_T);
}

void piorCaso(void(*menuOrdencao)(int, int[], int),int escolha, int n){

    int *arr;
    arr = alocaArray(n);
    int i;
    struct timeval tempo_antes, tempo_depois;
    double delta_T;


    //Criando array crescente ordenado
    for(i = 0; i < n; i++){
        arr[i] = i;
    }

    //criando array decrescente

    transformarEmDecrescente(arr, n);

    gettimeofday(&tempo_antes, NULL);

    menuOrdencao(escolha, arr, n);

    gettimeofday(&tempo_depois, NULL);


    delta_T = (tempo_depois.tv_sec + tempo_depois.tv_usec / 1000000.0) - (tempo_antes.tv_sec + tempo_antes.tv_usec / 1000000.0);
    printf("\nO tempo para ordenar um array invertido e de: %f\n", delta_T);

}


void gerandoArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

/****************FUNÇÕES DE ORDENAÇÃO*****************/

/*BubbleSort*/

void bubbleSort(int *v, int n)
{
    int i, continua, aux, fim = n;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    }
    while (continua != 0);
}

voi timSort(int v, int n)
{

}



