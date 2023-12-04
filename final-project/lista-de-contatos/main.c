// Gabriel Vinicius Rocha Barboza - GU3042715
#include <stdio.h>
#include <stdlib.h>
#include "lista-de-contatos.h"
#define VERSION "v1.0"

int main()
{
    char nome[60];
    int success, cod; // Para testar se as funcoes do lista-de-contatos.h estao se comportando como planejado
    LISTA *lista; //Criando ponteiro para lista
    CLIENTE cliente;

    lista = criar_lista(); // Iniciando lista de contatos
    restore_contatos(lista);

    char choice;
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
        fflush(stdin);
        scanf(" %c", &choice);
        system("cls");

        switch(choice)
        {
        case '1':
            cliente = coletar_cliente();
            if(inserir_contato(lista, cliente))
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
            cod = coletar_codigo();
            listar_contatos_codigo(lista, cod);
            break;
        case '4':
            coletar_nome(&nome);
            listar_contatos_nome(lista, nome);
            break;
        case '5':
            editar_contato_processo(lista); //TODO: TERMINAR
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
    while(choice != '0');

    backup_contatos(lista);

    apagar_lista(lista);


    //TODO: Salvar 10 contatos

    //(OPCIONAL): Exibir total de contatos

    //TODO: Comentar todo codigo

    //TODO: PDF de instrucoes

    printf("Dados salvos com sucesso! Tudo pronto para voce sair do programa!\n\n");
    system("pause");
    return 0;
}
