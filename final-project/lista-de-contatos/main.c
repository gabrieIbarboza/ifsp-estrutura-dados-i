// Gabriel Vinicius Rocha Barboza - GU3042715
#include <stdio.h>
#include <stdlib.h>
#include "lista-de-contatos.h"
#define VERSION "v1.0"

int main()
{
    char nome[60];
    LISTA *lista; //Criando ponteiro para lista

    lista = criar_lista(); // Iniciando lista de contatos

    restore_contatos(lista); // Povoando listas com dados da ultima sessao (salvos no arquivo)

    // Menu em Loop
    char choice; // Guarda o primeiro character do que o usuario digitar para decidir no switch o que fazer com o que o usuario digitou
    do
    {
        system("cls");
        printf("~~~~~~ Lista de Contatos ACME S.A. - %s ~~~~~~\n", VERSION);
        printf("1 - Inserir de novo contato\n");
        printf("2 - Gerar relatorio total\n");
        printf("3 - Gerar relatorio individual\n");
        printf("4 - Gerar relatorio por nome\n");
        printf("5 - Editar contato\n");
        printf("6 - Excluir contato\n");
        printf("0 - Sair do programa\n");
        printf("\nInforme o numero da acao que deseja: ");
        fflush(stdin); // Para garantir que somente o que o usuario digitar sera guardado
        scanf(" %c", &choice);
        system("cls");

        switch(choice)
        {
        case '1':
            if(inserir_contato(lista, coletar_cliente()))
            {
                printf("Contato inserido com sucesso!");
            }
            else
            {
                printf("Falha ao cadastrar contato!");
            }
            break;
        case '2':
            printf("~~~~~~ Relatorio Geral ~~~~~~");
            listar_contatos(lista);
            break;
        case '3':
            listar_contatos_codigo(lista, coletar_codigo());
            break;
        case '4':
            coletar_nome(&nome);
            listar_contatos_nome(lista, nome);
            break;
        case '5':
            editar_contato_processo(lista);
            break;
        case '6':
            remover_contato_processo(lista);
            break;
        case '0':
            break;
        default:
            printf("Escolha um numero de acao valido no menu!\n\n");
            break;
        }

        if(choice != '0')
        {
            printf("\n\n");
            system("pause");
        }
    }
    while(choice != '0'); // Sair do menu quando usuario digitar 0

    backup_contatos(lista); // Salvando lista de contatos no arquivo.bin

    apagar_lista(lista); // liberando memoria alocada pela lista

    printf("Dados salvos com sucesso! Tudo pronto para voce sair do programa!\n\n");
    system("pause");
    return 0;
}
