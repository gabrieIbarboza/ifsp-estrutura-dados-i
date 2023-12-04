#include <stdio.h>
#include <stdlib.h>
#include "lista-de-contatos.h"
#include <string.h>

typedef struct contato{
    CLIENTE dados;
    struct contato *prox_contato;
}CONTATO;

LISTA *criar_lista()
{
    LISTA *li;
    li = (LISTA*) malloc(sizeof(LISTA));
    if(li != NULL)
    {
        *li = NULL;
    }
    return li;
}

int lista_existe(LISTA *li)
{
    if(li == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int tamanho_lista(LISTA *li)
{
    if(lista_existe(li))
    {
        int total = 0;
        CONTATO *c = *li;
        while(c != NULL)
        {
            total++;
            c = c->prox_contato;
        }
        return total;
    }
    else
    {
        return 0;
    }

}

int lista_vazia(LISTA *li)
{
    if(tamanho_lista(li) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int verificar_cliente_cadastrado(LISTA *li, CLIENTE cliente)
{
    if(tamanho_lista(li) > 0)
    {
        CONTATO *aux = *li;
        do
        {
            if(aux->dados.cod == cliente.cod)
            {
                return 1;
            }
            aux = aux->prox_contato;
        }
        while(aux != NULL);
    }
    return 0;
}

CLIENTE coletar_cliente()
{
    CLIENTE cl;
    char str[100];

    fflush(stdin);
    printf("\n\nInforme o codigo do cliente: ");
    scanf("%d", &cl.cod);
    fflush(stdin);

    printf("\nInforme o nome do cliente: ");
    fgets(str, 59, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.nome, str);
    fflush(stdin);

    printf("\nInforme a empresa: ");
    fgets(str, 59, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.empresa, str);
    fflush(stdin);

    printf("\nInforme o departamento: ");
    fgets(str, 29, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.departamento, str);
    fflush(stdin);

    printf("\nInforme o telefone: ");
    fgets(str, 19, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.telefone, str);
    fflush(stdin);

    printf("\nInforme o celular: ");
    fgets(str, 20, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.celular, str);
    fflush(stdin);

    printf("\nInforme o email: ");
    fgets(str, 59, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.email, str);
    fflush(stdin);

    system("cls");

    return cl;
}

CLIENTE coletar_atualizacao_cliente()
{
    CLIENTE cl;
    char str[100];

    fflush(stdin);
    printf("\nInforme o nome do cliente atualizado: ");
    fgets(str, 59, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.nome, str);
    fflush(stdin);

    printf("\nInforme a empresa atualizada: ");
    fgets(str, 59, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.empresa, str);
    fflush(stdin);

    printf("\nInforme o departamento atualizado: ");
    fgets(str, 29, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.departamento, str);
    fflush(stdin);

    printf("\nInforme o telefone atualizado: ");
    fgets(str, 19, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.telefone, str);
    fflush(stdin);

    printf("\nInforme o celular atualizado: ");
    fgets(str, 20, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.celular, str);
    fflush(stdin);

    printf("\nInforme o email atualizado: ");
    fgets(str, 59, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(cl.email, str);
    fflush(stdin);

    system("cls");

    return cl;
}

int coletar_codigo()
{
    int cod;

    fflush(stdin);
    printf("\n\nInforme o codigo do cliente: ");
    scanf("%d", &cod);

    system("cls");

    return cod;
}

void coletar_nome(char *nome[60])
{
    char str[60];

    fflush(stdin);
    printf("\nInforme o nome para buscar: ");
    fgets(str, 59, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(nome, str);
    fflush(stdin);

    system("cls");
}

int inserir_contato(LISTA *li, CLIENTE cliente)
{
    if(lista_existe(li))
    {
        if(!verificar_cliente_cadastrado(li, cliente))
        {
            CONTATO *c = (CONTATO*) malloc(sizeof(CONTATO));
            if(c == NULL) {
                return 0;
            }
            c->dados = cliente;

            if(lista_vazia(li)){//insere no inicio
                c->prox_contato = (*li);
                *li = c;
                return 1;
            }
            else
            {
                CONTATO *c_anterior, *c_atual = *li;
                while(c_atual != NULL && c_atual->dados.cod < cliente.cod)
                {
                    c_anterior = c_atual;
                    c_atual = c_atual->prox_contato;
                }
                if(c_atual == *li) //insere se estiver na primeira posicao
                {
                    c->prox_contato = (*li);
                    *li = c;
                }
                else //insere em qualquer outra posicao
                {
                    c->prox_contato = c_anterior->prox_contato;
                    c_anterior->prox_contato = c;
                }
                return 1;
            }
        }
    }

    return 0;
}

void exibir_contato(CLIENTE cliente)
{
    printf("\n\nCodigo.......: %d", cliente.cod);
    printf("\nNome.........: %s", cliente.nome);
    printf("\nEmpresa......: %s", cliente.empresa);
    printf("\nDepartamento.: %s", cliente.departamento);
    printf("\nTelefone.....: %s", cliente.telefone);
    printf("\nCelular......: %s", cliente.celular);
    printf("\nEmail........: %s", cliente.email);
}

int buscar_codigo(LISTA *li, int cod, LISTA *contato)
{
    if(!lista_vazia(li))
    {
        CONTATO *c = *li;
        while(c != NULL && c->dados.cod != cod)
        {
            c = c->prox_contato;
        }

        if(c != NULL)
        {
            *contato = c;
            return 1;
        }
    }
    return 0;
}

int buscar_nome(LISTA *li, char nome[], LISTA *contatos_encontrados)
{
    char lower_nome[60], lower_selected_nome[60];
    char copy_nome[60];

    strcpy(copy_nome, nome);
    strlwr(copy_nome);
    strcpy(lower_nome, copy_nome);

    if(!lista_vazia(li))
    {
        CONTATO *c = *li;
        while(c != NULL)
        {
            strcpy(copy_nome, c->dados.nome);
            strlwr(copy_nome);
            strcpy(lower_selected_nome, copy_nome);

            if(strstr(lower_selected_nome, lower_nome) != NULL)
            { //strstr devolve valor diferente de 0, ou seja, true, caso encontre o nome a ser buscado no contato atual selecionado
                inserir_contato(contatos_encontrados, c->dados);
            }

            c = c->prox_contato;
        }

        if(!lista_vazia(contatos_encontrados))
        {
            return 1;
        }
    }
    return 0;
}

void listar_contatos(LISTA *li)
{
    if(!lista_vazia(li))
    {
        CONTATO *c = *li;
        while(c != NULL)
        {
            exibir_contato(c->dados);
            c = c->prox_contato;
        }
    }
    else
    {
        printf("\n\n\tNada para mostrar, lista esta vazia!");
    }
}

void listar_contatos_codigo(LISTA *li, int cod)
{
    LISTA *c = criar_lista();
    int success = buscar_codigo(li, cod, c);

    if(success)
    {
        printf("~~~~~~ Relatorio Individual ~~~~~~");
        listar_contatos(c);
    }
    else
    {
        printf("Codigo %d nao encontrado na lista de contatos!", cod);
    }
}

void listar_contatos_nome(LISTA *li, char nome[])
{
    LISTA *contatos_encontrados = criar_lista();
    int success;

    success = buscar_nome(li, nome, contatos_encontrados);
    if(success)
    {
        printf("~~~~~~ Relatorio ~~~~~~");
        listar_contatos(contatos_encontrados);
    }
    else
    {
        printf("Nome %s nao encontrado na lista de contatos!", nome);
    }

    apagar_lista(contatos_encontrados);
}

void editar_contato_processo(LISTA *li)
{
    LISTA *c = criar_lista();
    int cod = coletar_codigo(), success;

    success = buscar_codigo(li, cod, c);
    if(success)
    {
        printf("~~~~~~ Contato Encontrado ~~~~~~");
        listar_contatos(c);

        success = confirmar_operacao(li, "editar", c);
        if(success)
        {
            system("cls");
            printf("~~~~~~ Dados Antigos ~~~~~~");
            listar_contatos(c);
            printf("\n\n~~~~~~ Novos   Dados ~~~~~~");
            CLIENTE cl = coletar_atualizacao_cliente();
            cl.cod = cod;

            if(remover_contato(li, cod))
            {
                if(inserir_contato(li, cl))
                {
                    printf("Edicao concluida com sucesso!");
                }
            }
        }
        else
        {
            system("cls");
            printf("Edicao cancelada!");
        }

    }
    else
    {
        printf("Codigo %d nao encontrado na lista de contatos!", cod);
    }
}

void remover_contato_processo(LISTA *li)
{
    LISTA *c = criar_lista();
    int cod = coletar_codigo(), success;

    success = buscar_codigo(li, cod, c);
    if(success)
    {
        printf("~~~~~~ Contato Encontrado ~~~~~~");
        listar_contatos(c);

        success = confirmar_operacao(li, "remover", c);
        system("cls");
        if(success)
        {
            success = remover_contato(li, cod);
            if(success)
            {
                printf("Contato removido com sucesso!");
            }
            else
            {
                printf("Falha ao tentar remover contato!");
            }
        }
        else
        {
            printf("Remocao cancelada! O contato segue cadastrado.");
        }

    }
    else
    {
        printf("Codigo %d nao encontrado na lista de contatos!", cod);
    }
}

int remover_contato(LISTA *li, int cod)
{
    if(!lista_vazia(li))
    {
        CONTATO *ant, *atual = *li;
        while(atual != NULL && atual->dados.cod != cod)
        {
            ant = atual;
            atual = atual->prox_contato;
        }
        if(atual == NULL)
        {
            return 0;
        }
        if(atual == *li)
        {
            *li = atual->prox_contato;
        }
        else
        {
            ant->prox_contato = atual->prox_contato;
        }
        free(atual);
        return 1;
    }
    else
    {
        return 0;
    }
}

int confirmar_operacao(LISTA *li, char operacao[], LISTA *contato)
{
    char choice;

    fflush(stdin);
    printf("\n\nDeseja realmente %s o contato?", operacao);
    printf("\nDigite 1 para confirmar, qualquer outra tecla cancela a operacao: ");
    scanf(" %c", &choice);

    switch(choice)
    {
    case '1':
        return 1;
    default:
        return 0;
        break;
    }
}

void backup_contatos(LISTA *li)
{
    int total_gravado; // Para monitorar se a lista toda foi salva no arquivo
    int total_contatos = tamanho_lista(li);

    if(total_contatos > 0)
    {
        // Criando variavel do tipo arquivo
        FILE *f;

        // Tentando abrir arquivo usando modo de escrita binaria (wb)
        f = fopen("backup_lista_de_contatos.bin", "wb");
        if(f == NULL)
        { // Se nao conseguir abrir o arquivo, emitir erro e fechar programa
            printf("Erro na abertura de 'backup_lista_de_contatos.bin'!\n\n");
            system("pause");
            exit(1); // fechar programa com código de erro
        }

        // Alocando vetor para armazenar toda a lista atual
        CLIENTE *vetor_de_contatos = (CLIENTE*) calloc(total_contatos, sizeof(CLIENTE));

        CONTATO *c = *li; // pegando primeiro contato da lista
        for(int i = 0; i < total_contatos; i++)
        {
            vetor_de_contatos[i] = c->dados;
            c = c->prox_contato;
        }

        total_gravado = fwrite(vetor_de_contatos, sizeof(CLIENTE), total_contatos, f);
        if(total_gravado != total_contatos)
        {
            printf("Erro na gravacao dos contatos em 'backup_lista_de_contatos.bin'!\n\n");
            system("pause");
            exit(1);
        }

        /*for(int i = 0; i < total_contatos; i++)
        {
            free(vetor_de_contatos[i]);
        }*/
        free(vetor_de_contatos);
        fclose(f);
    }
}

void restore_contatos(LISTA *li)
{
    FILE *f;

    f = fopen("backup_lista_de_contatos.bin", "rb");
    if(f == NULL)
    {
        printf("Nenhum contato restaurado!\n\n");
        system("pause");
        //exit(1);
    }
    else
    {
        CLIENTE cliente;

        // O while abaixo le e insere um cliente do arquivo binario por vez, ate encontrar o caracter de EOF

        int i = 0;
        char c = fgetc(f); // Ler caratere atual do arquivo (primeiro)
        while(c != EOF) // Enquanto o ultimo caractere lido nao for End Of File
        {
            fseek(f, i*sizeof(CLIENTE), SEEK_SET); // Colocar ponteiro de leitura na contagem atual de elementos (i*tamanho estrutura de cliente)

            fread(&cliente, sizeof(CLIENTE), 1, f); // Ler o elemento a partir do ponteiro posicionado em fseek
            inserir_contato(li, cliente); // Inserir cliente lido na lista

            c = fgetc(f); // Armazenar proximo caractere
            i++;
        }
    }

    fclose(f); // Fechando arquivo para manter integridade dos dados e evitar bugs
}

void apagar_lista(LISTA *li)
{
    if(li != NULL)
    {
        CONTATO *c;
        while((*li) != NULL)
        {
            c = *li;
            *li = (*li)->prox_contato;
            free(c);
        }
        free(li);
    }
}

char *strlwr(char *str)
{
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
    return str;
}
