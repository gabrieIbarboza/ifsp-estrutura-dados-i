#include <stdio.h>
#include <stdlib.h>
#include "arvoreLLBR.h"

int main()
{
    int x, valor;
    arvoreLLRB *raiz = cria_arvoreLLRB();

    x = insere_arvoreLLRB(raiz, 150);
    confirmaInsercao(x);
    x = insere_arvoreLLRB(raiz, 110);
    confirmaInsercao(x);
    x = insere_arvoreLLRB(raiz, 100);
    confirmaInsercao(x);
    x = insere_arvoreLLRB(raiz, 130);
    confirmaInsercao(x);
    x = insere_arvoreLLRB(raiz, 120);
    confirmaInsercao(x);
    x = insere_arvoreLLRB(raiz, 140);
    confirmaInsercao(x);
    x = insere_arvoreLLRB(raiz, 160);
    confirmaInsercao(x);

    printf("Digite um numero para deletar: \n");
    scanf("%d", &valor);
    x = remove_arvoreLLRB(raiz, valor);
    if(x){
        printf("Elemento removido com sucesso!");
    }else{
        printf("Erro, nao foi possivel remover o elemento");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
