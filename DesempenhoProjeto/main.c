#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

int main()
{
    int escolhaMenu, escolhaQuantidadeDados, n;

    srand(time(0));

    while (escolhaMenu != 11){
        /*Criando o menu para escolher a ordenação*/
        printf("\n\n");
        printMenu();
        scanf("%d", &escolhaMenu);

        if(escolhaMenu == 11){
            return 0;
        }

        /*Menu da quantidade de dados*/
        printQuantidadeDados();
        scanf("%d", &escolhaQuantidadeDados);

        n = escolhaQuantidade(escolhaQuantidadeDados);
        if (n == -1)
        {
            continue;
        }

        medirTempo(menuOrdencao,escolhaMenu, n);
        printf("\n\n");
        system("pause");
        system("cls");
    }

}
