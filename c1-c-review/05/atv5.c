#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declaração da matriz com 5 linhas e 5 colunas
    int mtrx[5][5], v[10];
    int i = 0, j = 0, soma = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("Digite os valores da matriz na posicao: %d e %d: ", i, j);
            //efetua a leitura de todos os campos da matriz
            scanf("%d", &mtrx[i][j]);
        }
    }
}
