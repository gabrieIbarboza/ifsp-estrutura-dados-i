#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iHoras, iMinutos, iSegundos, duracao;

    printf("Digite a hora de inicio: ");
    scanf("%d", &iHoras);
    printf("Digite os minutos de inicio: ");
    scanf("%d", &iMinutos);
    printf("Digite os segundos de inicio: ");
    scanf("%d", &iSegundos);
    printf("Informe a duracao do experimento em segundos: ");
    scanf("%d", &duracao);

























    hours = totalseconds / 60 / 60;
    minutes = (totalseconds / 60) - hours * 60;
    seconds = totalseconds - (hours * 60 * 60) - (minutes * 60);

    printf("\nO experimento que comecou as %dh%dm%ds terminou as: %dh%dm%ds", iHoras, iMinutos, iSegundos);

    printf("\n\n");
    system("pause");
    return 0;
}
