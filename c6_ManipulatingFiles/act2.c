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
    file = fopen("funcs.bin", "wb");
    if(file == NULL)
    {
        printf("\n\tErro ao abrir funcs.bin!\n");
        system("pause");
        exit(1);
    }

    fwrite(funcs, sizeof(FUNC), 5, file);

    fclose(file);

    printf("\n\n");
    system("pause");
    return 0;
}

FUNC coletaDados(int cont)
{
    //Cria variavel tipo FUNC (que � um struct)
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
