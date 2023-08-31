#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario
{
    int id;
    char nome[30];
    int idade;
    float salario;
}FUNC;

FUNC coletaDados(int cont);

int main()
{
    // Coletando 5 funcionarios

    FUNC funcs[5];

    for(int i = 0; i < 5; i++)
    {
        funcs[i] = coletaDados(i+1);
        printf("\n");
    }

    // Limpa tela
    system("cls");

    // Guardando struct num arquivo binario
    FILE *file;
    file = fopen("struct.txt", "wb");
    if(file == NULL)
    {
        printf("\n\tErro ao abrir struc.txt!\n");
        system("pause");
        exit(1);
    }

    fwrite(funcs, sizeof(FUNC), 4, file);

    fclose(file);

















/*
    FILE *arq1, *arq2;
    char str[100], strLida[100] = "", c;

    // Receber string
    printf("Digite uma frase: ");
    fgets(str, 99, stdin);

    // Abre arquivo e verifica se foi aberto com sucesso
    arq1 = fopen("arq1.txt", "w");
    if(arq1 == NULL)
    {
        printf("\n\tErro ao abrir arq1.txt!\n");
        system("pause");
        exit(1);
    }

    // Grava a string, character a character
    for(int i = 0; i < strlen(str); i++)
    {
        fputc(str[i], arq1);
    }

    // Fecha arquivo
    fclose(arq1);

    //
    // Gera um novo arquivo com tudo em CAPS
    //

    // Abri arq1.txt no modo leitura
    arq1 = fopen("arq1.txt", "r");
    if(arq1 == NULL)
    {
        printf("\n\tErro ao abrir arq1.txt!\n");
        system("pause");
        exit(1);
    }

    // Guarda arquivo numa string
    for(int i = 0; i < strlen(str); i++)
    {
        strLida[i] = fgetc(arq1);
    }

    // Fecha arq1.txt
    fclose(arq1);

    // Abre arq2.txt no modo escrita
    arq2 = fopen("arq2.txt", "w");
    if(arq2 == NULL)
    {
        printf("\n\tErro ao abrir arq2.txt!\n");
        system("pause");
        exit(1);
    }

    // Grava a string, character a character maiusculo no arquivo
    for(int i = 0; i < strlen(strLida); i++)
    {
        fputc(toupper(strLida[i]), arq2);
    }

    // Fecha arquivo
    fclose(arq2);

    //
    // Imprime os dois arquivos em tela
    //
    printf("\n\narq1.txt\n");

    arq1 = fopen("arq1.txt", "r");
    if(arq1 == NULL)
    {
        printf("\n\tErro ao abrir arq1.txt!\n");
        system("pause");
        exit(1);
    }

    c = fgetc(arq1);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(arq1);
    }

    printf("\n\narq2.txt\n");

    arq2 = fopen("arq2.txt", "r");
    if(arq1 == NULL)
    {
        printf("\n\tErro ao abrir arq2.txt!\n");
        system("pause");
        exit(1);
    }

    c = fgetc(arq2);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(arq2);
    }
*/


    printf("\n\n");
    system("pause");
    return 0;
}

FUNC coletaDados(int cont)
{
    //Cria variavel tipo FUNC (que é um struct)
    FUNC f;

    //Povoa FUNC
    printf("\nInforme o ID da pessoa colaboradora (%d): ", cont);
    scanf(" %d", &f.id);

    fflush(stdin);
    printf("Informe o nome da pessoa colaboradora (%d): ", cont);
    fgets(f.nome, 29, stdin);
    f.nome[
        strlen(f.nome)- 1
    ] = '\0';

    printf("Informe a idade da pessoa colaboradora (%d): ", cont);
    scanf(" %d", &f.idade);

    printf("Informe o salario da pessoa colaboradora (%d): ", cont);
    scanf(" %f", &f.salario);

    // Retorna FUNC
    return f;
}
