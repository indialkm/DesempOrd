#include <stdio.h>

void printMenu() {
    printf("Escolha o algoritmo de ordenacao:\n");
    printf("1. BubbleSort\n");
    printf("2. InsertionSort\n");
    printf("3. SelectionSort\n");
    printf("4. ShellSort\n");
    printf("5. MergeSort\n");
    printf("6. QuickSort\n");
    printf("7. HeapSort\n");
    printf("8. RadixSort\n");
    printf("9. CountingSort\n");
    printf("10. TimSort\n");
    printf("11. Sair\n");
}

void printQuantidadeDados() {
    printf("Escolha a quantidade de dados:\n");
    printf("1. 1000\n");
    printf("2. 5000\n");
    printf("3. 10000\n");
    printf("4. 20000\n");
    printf("5. 50000\n");
    printf("6. 100000\n");
}

int escolhaQuantidade(int escolha) {
    switch (escolha) {
        case 1: return 1000;
        case 2: return 5000;
        case 3: return 10000;
        case 4: return 20000;
        case 5: return 50000;
        case 6: return 100000;
        default: printf("Opção inválida.\n"); return -1;
    }
}

void menuOrdencao(int escolha, int *v, int n) {
    switch (escolha) {
        case 1:
            bubbleSort(v, n);
            break;

        case 2:


        case 10:
            return 10;
            break;

        default:
            printf("Opcao invalida.\n");
            break;
    }
}
