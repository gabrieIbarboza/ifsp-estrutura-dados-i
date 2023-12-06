#include <stdio.h>
#include <stdlib.h>
#include "lista-de-contatos.h"
#include <string.h>

typedef struct contato{
    CLIENTE dados;
    struct contato *prox_contato;
}CONTATO; // Elemento da lista

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
    if(tamanho_lista(li) > 0) // Verifica se existe ao menos um elemento na lista
    {
        CONTATO *aux = *li;
        do
        {
            if(aux->dados.cod == cliente.cod) // Verifica se o cod do cliente no elemento atual da lista e igual ao codigo passado como parametro
            {
                return 1; // Se sim, retorna positivo
            }
            aux = aux->prox_contato;
        }
        while(aux != NULL); // Vai ate listar acabar
    }
    return 0;
}

CLIENTE coletar_cliente()
{
    CLIENTE cl;
    char str[100];

    fflush(stdin); // Muitos desse para evitar bugs e sempre permitir que o usuario digite
    printf("\n\nInforme o codigo do cliente: ");
    scanf("%d", &cl.cod);
    fflush(stdin);

    printf("\nInforme o nome do cliente: ");
    fgets(str, 59, stdin); // Guardar ate 59 caracteres do que o usuario digitar na variavel auxiliar (str)
    str[strlen(str)-1] = '\0'; // fgets salva com \n no ultimo caractere da string, entao trocando esse \n por \0 (caractere que informa que o array acabou)
    strcpy(cl.nome, str); // Copiando string da variavel auxiliar (str) para o nome do cliente a ser retornado (cl)
    fflush(stdin); // Impedindo bugs
    // Mesma logica em todo resto da funcao abaixo e na proxima funcao tambem :)

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

    system("cls"); // limpar console

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
    char str[60]; // string auxiliar

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
    if(lista_existe(li)) // se lista existir
    {
        if(!verificar_cliente_cadastrado(li, cliente)) // e se o codigo desse cliente ja nao estiver cadastrado
        {
            CONTATO *c = (CONTATO*) malloc(sizeof(CONTATO));
            if(c == NULL) {
                return 0;
            }
            c->dados = cliente;

            if(lista_vazia(li)){ // insere novo contato no inicio da lista se lista ainda estiver sem elementos
                c->prox_contato = (*li);
                *li = c;
                return 1;
            }
            else // caso contrario, insere ordenamente na lista
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

int buscar_codigo(LISTA *li, int cod, CLIENTE *contato)
{
    if(!lista_vazia(li)) // se lista nao estiver vazia
    {
        CONTATO *c = *li;
        while(c != NULL && c->dados.cod != cod)
        {
            c = c->prox_contato;
        }

        if(c != NULL) // se tiver encontrado um contato com mesmo codigo
        {
            *contato = c->dados; // guarda o CLIENTE encontrado na variável apontada por *contato
            return 1;
        }
    }
    return 0;
}

int buscar_nome(LISTA *li, char nome[], LISTA *contatos_encontrados)
{
    // strings auxiliares para nao ter alterar a orginal, ja que strlwr() altera diretamete a string na memoria
    char lower_nome[60], lower_selected_nome[60];
    char copy_nome[60];

    strcpy(copy_nome, nome);
    strlwr(copy_nome); // transformando nome do parametro totalmente em minusculo
    strcpy(lower_nome, copy_nome);

    if(!lista_vazia(li))
    {
        CONTATO *c = *li;
        while(c != NULL)
        {
            strcpy(copy_nome, c->dados.nome);
            strlwr(copy_nome); // tranformando nome do contato atual totalmente me minusculo
            strcpy(lower_selected_nome, copy_nome);

            if(strstr(lower_selected_nome, lower_nome) != NULL) // ja que c e case sensitive, e importante transformar todos os caracteres em minuscula para buscar a segunda string dentro da primeira
            { //strstr devolve valor diferente de 0, ou seja, true, caso encontre o nome a ser buscado dentro do nome do contato atual selecionado
                inserir_contato(contatos_encontrados, c->dados); // cadastra o contato que passar na verificacao na lista de contatos encontrados recebida como parametro
            }

            c = c->prox_contato;
        }

        if(!lista_vazia(contatos_encontrados)) // se a lista de contatos_encontrados nao estiver vazia, retornar sucesso (1)
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
        while(c != NULL) // passa por cada um dos elementos da lista
        {
            exibir_contato(c->dados); // passa os dados do contato para metodo que os imprime no console
            c = c->prox_contato;
        }
    }
    else
    {
        printf("\n\nNada para mostrar, lista esta vazia!");
    }
}

void listar_contatos_codigo(LISTA *li, int cod)
{
    CLIENTE c;
    int success = buscar_codigo(li, cod, &c); // encontra contato com esse codigo na lista

    if(success) // se a busca der certo
    {
        printf("~~~~~~ Relatorio Individual ~~~~~~");
        exibir_contato(c); // imprime esse contato (mesmo sendo uma lista, vai ser apenas 1, pois nao deveria ser possivel existir o mesmo cod mais de uma vez na lista)
    }
    else
    {
        printf("Codigo %d nao encontrado na lista de contatos!", cod);
    }
}

void listar_contatos_nome(LISTA *li, char nome[])
{
    LISTA *contatos_encontrados = criar_lista(); // lista auxiliar para armazenar temporariamente os contatos encontrados na busca por nome
    int success;

    success = buscar_nome(li, nome, contatos_encontrados); // preenche a lista contatos_encontrados de contatos que possuem a string nome (do parametro) no nome
    if(success) // se alguem contato for enccontrado
    {
        printf("~~~~~~ Relatorio ~~~~~~");
        listar_contatos(contatos_encontrados); // imprimir cada um
    }
    else
    {
        printf("Nome %s nao encontrado na lista de contatos!", nome);
    }

    apagar_lista(contatos_encontrados); // liberando memoria alocada pela lista auxiliar, pois nao sera mais necessaria
}

void editar_contato_processo(LISTA *li)
{
    CLIENTE c;
    int cod = coletar_codigo(), success; // pede um codigo de contato para o usuario

    success = buscar_codigo(li, cod, &c);
    if(success) // se encontrar codigo na lista
    {
        printf("~~~~~~ Contato Encontrado ~~~~~~");
        exibir_contato(c); // mostra contato encontrado

        success = confirmar_operacao("editar"); // pergunta ao usuario se deseja confirmar edicao
        if(success) // caso usuario confirme a operacao
        {
            system("cls");
            printf("~~~~~~ Dados Antigos ~~~~~~");
            exibir_contato(c); // mostrar dados atuais do contato
            printf("\n\n~~~~~~ Novos   Dados ~~~~~~");
            CLIENTE cl = coletar_atualizacao_cliente(); // coletar dados para a atualizacao
            cl.cod = cod;

            if(remover_contato(li, cod)) // remove contato atual
            {
                if(inserir_contato(li, cl)) // aloca contato novo com as informacoes atualizadas, mantem somente codigo intocado
                {
                    printf("Edicao concluida com sucesso!");
                }
            }
        }
        else // caso usuario nao queria mais editar contato com o codigo informado
        {
            system("cls");
            printf("Edicao cancelada!");
        }

    }
    else // caso nao encontre codigo
    {
        printf("Codigo %d nao encontrado na lista de contatos!", cod);
    }
}

// a estrutura do metodo abaixo e parecido com editar_contato_processo, vou destacar somente diferencas...
void remover_contato_processo(LISTA *li)
{
    CLIENTE c;
    int cod = coletar_codigo(), success;

    success = buscar_codigo(li, cod, &c);
    if(success)
    {
        printf("~~~~~~ Contato Encontrado ~~~~~~");
        exibir_contato(c);

        success = confirmar_operacao("remover");
        system("cls");
        if(success) // se usuario confirmar que quer excluir contato selecionado
        {
            success = remover_contato(li, cod); // chamar funcao que remove contato da lista
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
    if(!lista_vazia(li)) // se lista nao estiver vazia
    {
        CONTATO *ant, *atual = *li;
        while(atual != NULL && atual->dados.cod != cod) // percorre lista buscando cod recebido por parametro
        {
            ant = atual;
            atual = atual->prox_contato;
        }
        if(atual == NULL) // se nao encontrar codigo na lista
        {
            return 0; // retorna que operacao nao deu certo
        }
        if(atual == *li) // se cod encontrado for o primeiro da lista
        {
            *li = atual->prox_contato; // aponta o inicio da lista do primeiro elemento para o segundo (que agora se torna o primeiro)
        }
        else // se cod encontrado estiver no meio ou final da lista
        {
            ant->prox_contato = atual->prox_contato;
        }
        free(atual); // libera memoria alocada pelo elemento da lista a ser removido
        return 1; // retorna que agora e oficial, elemento/contato foi removido com sucesso!
    }
    else
    {
        return 0;
    }
}

int confirmar_operacao(char operacao[])
{
    char choice; // variavel para receber escolha do usuario

    fflush(stdin);
    printf("\n\nDeseja realmente %s o contato?", operacao);
    printf("\nDigite 1 para confirmar, qualquer outra tecla cancela a operacao: ");
    scanf(" %c", &choice); // recebe o primeiro caracter do que o usuario digitou

    switch(choice)
    {
    case '1': // se o caracter for 1, retorna 1 (ou seja, usuario confirmou operacao!)
        return 1;
    default: // em qualquer outro caso, retorna 0 (usuario cancelou operacao)
        return 0;
        break;
    }
}

void backup_contatos(LISTA *li)
{
    int total_gravado; // Para monitorar se a lista toda foi salva no arquivo
    int total_contatos = tamanho_lista(li);

    // Criando variavel do tipo arquivo
    FILE *f;

    // Tentando abrir arquivo usando modo de escrita binaria (wb)
    f = fopen("backup_lista_de_contatos.bin", "wb");
    if(f == NULL)
    { // Se nao conseguir abrir o arquivo, emitir erro e fechar programa
        printf("Erro na abertura de 'backup_lista_de_contatos.bin'!\n\n");
        system("pause");
        exit(1); // fechar programa com c�digo de erro
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

void restore_contatos(LISTA *li)
{
    FILE *f;

    f = fopen("backup_lista_de_contatos.bin", "rb");
    if(f == NULL)
    {
        printf("Nenhum contato restaurado!\n\n");
        system("pause");
        //exit(1); nao e necessario retornar erro, pois caso a leitura nao ocorra, pode ser que seja a primeira vez que o usuario esta usando a aplicacao
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
    if(lista_existe(li))
    {
        CONTATO *c;
        while((*li) != NULL) // enquanto o inicio da lista estiver apontando para outro elemento
        {
            c = *li; // contato auxiliar aponta para contato atual
            *li = (*li)->prox_contato; // lista aponta para o proximo elemento
            free(c); // liberar elemento atual
        }
        free(li); // libera o ultimo elemento da lista que esta faltando
    }
}

char *strlwr(char *str)
{
    while(*str) // foreach character da string
    {
        *str = tolower(*str); // transformar character em sua versao minuscula
        str++;
    }
    return str;
}
