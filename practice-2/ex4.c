#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numero_invertido(int n);

int main()
{
    int n;

    printf("Digite um valor inteiro: ");
    scanf("%d", &n);

    system("cls");

    printf("Numero lido= %d\n", n);
    printf("\nNumero invertido= %d", numero_invertido(n));

    printf("\n\n");
    system("pause");
    return 0;
}

//Calcula numero de digitos de um numero
//int casas = log10(n)+1);

13
3*10
1*1

    13/10 = 1,3
    +
    (13%10)


130
0*100
3*10
1*1

    130/10 = 13
    130 / 100 = 1,3


1456
6*1000
+
5*100
+
4*10
+
1*1

divide por modulo e mostra so parte inteira
int numero_invertido(int n)
{

    if(n / 10 < 1)
        return n;
    printf("%d", numero_invertido(n%10));
    return n / 10;

}

