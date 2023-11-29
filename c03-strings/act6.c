#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*

Utilizando agora as fun��es dispon�veis na biblioteca <ctype.h>, leia do teclado uma string e
inverta a caixa dos seus caracteres. Se o caractere for mai�sculo, transforme-o em min�sculo. Se
for min�sculo, modifique-o para mai�sculo. No mesmo programa implemente as fun��es (escreva
o c�digo delas) strupr() e strlwr(), apresentadas no final dos slides e efetue a mesma opera��o de
invers�o mai�sculas/min�sculas.

*/

char *strupr(char *str);
char *strlwr(char *str);

int main()
{
    char str[100];
    int strlength = 0;

    printf("Digite uma frase: ");
    gets(str);
    printf("\n\nFrase digitada:  %s", str);

    strlength = strlen(str);

    for(int i = 0; i < strlength; i++)
    {
        str[i] = (isupper(str[i])
                  ? tolower(str[i])
                  : toupper(str[i])
                 );
    }

    printf("\nFrase invertida: %s", str);
    strlwr(str);
    printf("\nFrase minuscula: %s", str);
    strupr(str);
    printf("\nFrase maiuscula: %s", str);

    printf("\n\n");
    system("pause");
    return 0;
}

char *strupr(char *str)
{
    while(*str)
    {
        *str = toupper(*str);
        str++;
    }
    return str;
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
