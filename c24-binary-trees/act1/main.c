#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

int main() {
    int x; // sera usado como retorno
    ArvBin *raiz;

    raiz = cria_arvBin();

    if(vazia_arvBin(raiz))
    {
        printf("\nA arvore esta vazia.");
    }
    else
    {
        printf("\nA arvore possui elementos.");
    }

    x = altura_arvBin(raiz);
    printf("\n\nAltura da arvore: %d", x);

    x = totalNO_arvBin(raiz);
    printf("\n\nTotal de nos na arvore: %d", x);

    preOrdem_arvBin(raiz);
    emOrdem_arvBin(raiz);
    posOrdem_arvBin(raiz);



    liberar_arvBin(raiz);
    printf("\n\n");
    system("pause");
    return 0;
}
