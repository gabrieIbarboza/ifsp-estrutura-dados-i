#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Funcao de particao para o QuickSort com Mediana de Tres
int medianOfThree(int *array, int a, int b, int c) {
    if ((array[a] < array[b]) != (array[a] < array[c]))
        return a;
    else if ((array[b] < array[a]) != (array[b] < array[c]))
        return b;
    else
        return c;
}

int partition(int *array, int start, int end) {
    int mid = start + (end - start) / 2;
    int pivotIndex = medianOfThree(array, start, mid, end);
    int pivot = array[pivotIndex];

    // Swap pivot with end
    int temp = array[pivotIndex];
    array[pivotIndex] = array[end];
    array[end] = temp;

    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (array[j] < pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;
    return (i + 1);
}

// Funcao QuickSort
void quickSort(int *array, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, end);
    }
}

// Funcao para alocar e preencher um array com valores aleatorios
int* allocateAndFillArray(int size, int min, int max) {
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }

    return array;
}

// Funcao para embaralhar o array
void shuffleArray(int* array, int size) {
    for (int i = size - 2; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

// Funcao para ordenar o array em ordem decrescente
void sortArrayDescending(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Funcao para calcular o tempo medio de execucao
double calculateAverageTime(double executionTimes[], int numberOfExecutions) {
    double sum = 0.0;
    for(int i = 0; i < numberOfExecutions; i++) {
        sum += executionTimes[i];
    }
    double average = sum / numberOfExecutions;
    printf("\n\nMedia dos tempos: %f microssegundos", average);
    return average;
}

// Funcao para executar QuickSort e calcular os tempos
void choiceQuick(int* array, int size, struct timeval startTime, struct timeval endTime, double arrayExecutionTime[], int i, double* ascOrderTime, double* decOrderTime) {
    gettimeofday(&startTime, NULL);
    quickSort(array, 0, size - 1);
    gettimeofday(&endTime, NULL);
    arrayExecutionTime[i] = ((endTime.tv_sec * 1000000.0 + endTime.tv_usec ) -
                    (startTime.tv_sec * 1000000.0 + startTime.tv_usec));
    if(i == 9){
        // Tempo para ordenar array crescente
        gettimeofday(&startTime, NULL);
        quickSort(array, 0, size - 1);
        gettimeofday(&endTime, NULL);
        *ascOrderTime = ((endTime.tv_sec * 1000000.0 + endTime.tv_usec ) -
                    (startTime.tv_sec * 1000000.0 + startTime.tv_usec));

        // Tempo para ordenar array decrescente
        sortArrayDescending(array, size);
        gettimeofday(&startTime, NULL);
        quickSort(array, 0, size - 1);
        gettimeofday(&endTime, NULL);
        *decOrderTime = ((endTime.tv_sec * 1000000.0 + endTime.tv_usec ) -
                    (startTime.tv_sec * 1000000.0 + startTime.tv_usec));
    }
    free(array);
}

// Funcao para salvar os tempos medios em um arquivo
void salvarTemposMediosEmArquivo(const char *algoritmo, double mediaTempos, double tempoAsc, double tempoDesc, double *temposExecucao, int numTempos) {
    FILE *arquivo = fopen("tempos_medios.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arquivo, "%s:\n", algoritmo);
    fprintf(arquivo, "Tempo medio: %f microssegundos, Tempo crescente: %f microssegundos, Tempo decrescente: %f microssegundos\n", mediaTempos, tempoAsc, tempoDesc);
    fprintf(arquivo, "Tempos de execucao: ");
    for (int i = 0; i < numTempos; i++) {
        fprintf(arquivo, "%f ", temposExecucao[i]);
    }
    fprintf(arquivo, "\n");
    fclose(arquivo);
}

// Funcao para mostrar o menu de quantidade de elementos
void showElementQuantityMenu() {
    printf("\n\tEscolha a quantidade de elementos a serem ordenados");
    printf("\n1- 50.000");
    printf("\n2- 100.000");
    printf("\nDigite o numero equivalente a quantidade escolhida: ");
}

int main() {
    int* array;
    double arrayExecutionTime[10];
    double averageTimes, ascOrderTime, decOrderTime;
    int choiceElement, size;
    int sizeMin = 1, sizeMax = 1000000;
    struct timeval startTime, endTime;
    const char *algorithmName = "Quick Sort";

    // Mostrar menu de escolha de quantidade de elementos
    showElementQuantityMenu();
    scanf("%d", &choiceElement);

    switch (choiceElement) {
        case 1:
            size = 10000;
            break;
        case 2:
            size = 100000;
            break;
        default:
            printf("Opcao invalida escolhida!\n");
            return 1;
    }

    for (int i = 0; i < 8; i++) {
        array = allocateAndFillArray(size, sizeMin, sizeMax);
        choiceQuick(array, size, startTime, endTime, arrayExecutionTime, i, &ascOrderTime, &decOrderTime);
    }

    // Array crescente
    array = allocateAndFillArray(size, sizeMin, sizeMax);
    quickSort(array, 0, size - 1); // Ordenar para obter array crescente
    choiceQuick(array, size, startTime, endTime, arrayExecutionTime, 8, &ascOrderTime, &decOrderTime);

    // Array decrescente
    array = allocateAndFillArray(size, sizeMin, sizeMax);
    sortArrayDescending(array, size); // Ordenar para obter array decrescente
    choiceQuick(array, size, startTime, endTime, arrayExecutionTime, 9, &ascOrderTime, &decOrderTime);

    printf("\nTempos de execucao (microssegundos):\n");
    for (int i = 0; i < 10; i++) {
        printf("%f ", arrayExecutionTime[i]);
    }

    averageTimes = calculateAverageTime(arrayExecutionTime, 10);
    printf("\nTempo para ordenar array crescente: %f microssegundos", ascOrderTime);
    printf("\nTempo para ordenar array decrescente: %f microssegundos\n", decOrderTime);

    salvarTemposMediosEmArquivo(algorithmName, averageTimes, ascOrderTime, decOrderTime, arrayExecutionTime, 10);

    return 0;
}
