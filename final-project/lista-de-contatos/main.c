#include <stdio.h>
#include <stdlib.h>
#include "lista-de-contatos.h"

int main()
{
    int success; // Para testar se as funcoes do header estao se comportando como planejado
    LISTA *lista;

    lista = criar_lista(); // Iniciando lista de contatos

    char choice;
    do
    {
        system("cls");
        printf("~~~~~~ Lista de Contatos ACME S.A. - v1.0 ~~~~~~");
        choice = '0';
    }
    while(choice != '0');

    //TODO: MENU NUMERICO
    //TODO: 0 FINALIZA, mas nao esquecer do FREE()

    //TODO: GRAVACAO BINARIA DOS DADOS EM ARQUIVO
    //TODO: Salvar 10 contatos

    //vetores convencionais???

    printf("Hello world!\n");
    printf("\n\n");
    system("pause");
    return 0;
}
