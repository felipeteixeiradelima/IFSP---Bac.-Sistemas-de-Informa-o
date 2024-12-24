#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SAIR 11

unsigned char autoRandom = TRUE;

// UTILIDADES
int randomizarVetor(int vetor[], unsigned int tam_vetor) {
    for(int i = 0; i < tam_vetor; i++) {
        do {
            vetor[i] = rand() % 1000;
        } while (vetor[i] > 1000 && vetor[i] < 0);
    }
    return 0;
}

void printVetor(int vetor[], unsigned int tam_vetor) {
    for (unsigned short i = 0; i < tam_vetor; i++) printf("%i ", vetor[i]);
    putchar('\n');
}

int trocarValores(int* a, int*b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    return 0;
}
// ========================================================================================

// BUBBLE SORT
int bubbleSort(int vetor[], unsigned int tam_vetor) {
    int aux;

    for (int i = tam_vetor-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vetor[i] < vetor[j]) {
                trocarValores(&vetor[i], &vetor[j]);
            }
        }
    }
}
// ========================================================================================

// SELECTION SORT
int selectionSort(int vetor[], unsigned int tam_vetor) {
    int pos_menor;

    for (int i = 0; i < tam_vetor; i++) {
        pos_menor = i;

        for (int j = i+1; j < tam_vetor; j++) {
            if (vetor[j] < vetor[pos_menor]) pos_menor = j;
        }

        trocarValores(&vetor[pos_menor], &vetor[i]);

    }
}
// ========================================================================================

// INSERTION SORT
int insertionSort(int vetor[], unsigned int tam_vetor) {

    for (int i = 0; i < tam_vetor - 1; i++) {
        if (vetor[i] > vetor[i+1]) {
            for (int j = i+1; j != 0; j--) {
                if (vetor[j-1] <= vetor[j]) break;

                trocarValores(&vetor[j-1], &vetor[j]);
            }
        }
    }
}
// ========================================================================================

// HEAP SORT
void sift(int heap[], int i) {
    int j = i, indice_pai = j/2;

    do {
        if (heap[j] >= heap[indice_pai]) break;

        trocarValores(&heap[j], &heap[indice_pai]);
        j = indice_pai;
        indice_pai = j/2;

    } while (j > 0);
}

void converterParaHeap(int vetor[], unsigned int tam_vetor) {
    int heap[tam_vetor];

    for (int i = 0; i < tam_vetor; i++) {
        heap[i] = vetor[i];
        sift(heap, i);
    }

    for (int i = 0; i < tam_vetor; i++) {
        vetor[i] = heap[i];
    }
}

void inserirPrimeiroNoFinalHeap(int heap[], unsigned int tam_heap) {
    for (int i = 0; i < tam_heap-1; i++) trocarValores(&heap[i], &heap[i+1]);
}

int heapSort(int vetor[], unsigned int tam_vetor) {

    converterParaHeap(vetor, tam_vetor);

    for (unsigned short i = 0; i < tam_vetor; i++) {
        inserirPrimeiroNoFinalHeap(vetor, tam_vetor);
        converterParaHeap(vetor, tam_vetor-1-i);
    }
}
// ========================================================================================

// MERGE SORT
void merge(int vetor_original[], int esquerda, int meio, int direita) {

    unsigned int tam_esquerda = meio-esquerda+1, tam_direita = direita-meio, tam_original = direita-esquerda+1;
    int vetor_esquerda[tam_esquerda], vetor_direita[tam_direita];
    unsigned int i;

    for (i = 0; i < tam_esquerda; ++i) {
        vetor_esquerda[i] = vetor_original[esquerda + i];
    }

    for (i = 0; i < tam_direita; ++i) {
        vetor_direita[i] = vetor_original[meio + i + 1];
    }

    unsigned int indice_esquerda = 0, indice_direita = 0, indice_original = esquerda;

    while (indice_esquerda < tam_esquerda && indice_direita < tam_direita) {
        if (vetor_esquerda[indice_esquerda] <= vetor_direita[indice_direita]) {
            vetor_original[indice_original] = vetor_esquerda[indice_esquerda];
            ++indice_esquerda;
        }
        else {
            vetor_original[indice_original] = vetor_direita[indice_direita];
            ++indice_direita;
        }
        ++indice_original;
    }
    
    while (indice_esquerda < tam_esquerda) {
        vetor_original[indice_original] = vetor_esquerda[indice_esquerda];
        ++indice_esquerda;
        ++indice_original;
    }

    while (indice_direita < tam_direita) {
        vetor_original[indice_original] = vetor_direita[indice_direita];
        ++indice_direita;
        ++indice_original;
    }
}

void mergeSort(int vetor[], unsigned int esquerda, unsigned int direita) {

    if (esquerda >= direita) return;

    unsigned int meio = (direita+esquerda)/2;

    mergeSort(vetor, esquerda, meio);
    mergeSort(vetor, meio+1, direita);

    merge(vetor, esquerda, meio, direita);
}
// ========================================================================================

// COUNTING SORT
unsigned int descobrirMaximo(int vetor[], unsigned int tam_vetor) {
    unsigned int max = vetor[0];

    for (unsigned int i = 1; i < tam_vetor; ++i) {
        if (vetor[i] > max) max = vetor[i];
    }

    return max;
}

int countingSort(int vetor[], unsigned int tam_vetor) {
    unsigned int tam_count = descobrirMaximo(vetor, tam_vetor) + 1;

    int vetor_count[tam_count], vetor_sorted[tam_vetor];
    for (unsigned int i = 0; i < tam_count; ++i) vetor_count[i] = 0;
    
    for (unsigned int i = 0; i < tam_vetor; ++i) {
        ++vetor_count[vetor[i]];
    }
    
    for (unsigned int i = 1; i < tam_count; ++i) {
        vetor_count[i] += vetor_count[i-1];
    }
    
    for (unsigned int i = tam_vetor - 1;; --i) {
        vetor_sorted[vetor_count[vetor[i]] - 1] = vetor[i];
        --vetor_count[vetor[i]];

        if (i == 0) break;
    }
    
    for (unsigned int i = 0; i < tam_vetor; ++i) vetor[i] = vetor_sorted[i];
}
// ========================================================================================

// RADIX SORT
int descobrirDigitos(int vetor[], unsigned int tam_vetor) {
    int d = 0, aux, aux_d;

    for (unsigned int i = 0; i < tam_vetor; ++i) {
        aux = vetor[i];
        aux_d = 0;

        while (aux != 0) {
            aux /= 10;
            ++aux_d;
        }

        if (aux_d > d) d = aux_d;
    }

    return d;
}

unsigned char pegarValorNoDigito(int valor_original, unsigned int digito) {
    int valor_digito = valor_original % (int) round(pow(10, digito));
    
    for (unsigned int i = 1; i < digito; ++i) {
        
        while (valor_digito % (int) round(pow(10, i)) != 0) {
            valor_digito -= (int) round(pow(10, i-1));
        }
    }

    return valor_digito / (int) round(pow(10, digito-1));
}

int radixSubrotinaCountingSort(int vetor[], unsigned int tam_vetor, unsigned int digito) {
    unsigned char tam_count = 10;

    int vetor_count[tam_count], vetor_sorted[tam_vetor];
    
    for (unsigned int i = 0; i < tam_count; ++i) vetor_count[i] = 0;

    for (unsigned int i = 0; i < tam_vetor; ++i) {
        ++vetor_count[pegarValorNoDigito(vetor[i], digito)];
    }
    
    for (unsigned int i = 1; i < tam_count; ++i) {
        vetor_count[i] += vetor_count[i-1];
    }
    
    for (unsigned int i = tam_vetor - 1;; --i) {
        vetor_sorted[vetor_count[pegarValorNoDigito(vetor[i], digito)] - 1] = vetor[i];
        --vetor_count[pegarValorNoDigito(vetor[i], digito)];

        if (i == 0) break;
    }
    
    for (unsigned int i = 0; i < tam_vetor; ++i) vetor[i] = vetor_sorted[i];
}

int radixSort(int vetor[], unsigned int tam_vetor) {
    int totalDigitos = descobrirDigitos(vetor, tam_vetor);

    for (unsigned int i = 1; i <= totalDigitos; ++i) {
        radixSubrotinaCountingSort(vetor, tam_vetor, i);
    }
}
// ========================================================================================

// QUICKSORT
int novoIndicePivo(int esquerda, int direita) {
    return (rand() % (direita - esquerda + 1)) + esquerda;
}

void organizarVetorPivo(int vetor[], int esquerda, int direita, int* indice_pivo) {
    trocarValores(&vetor[*indice_pivo], &vetor[direita]);
    
    int i, j;

    for (i = esquerda - 1, j = esquerda; j < direita; ++j) {
        if (vetor[j] < vetor[direita]) {
            ++i;
            trocarValores(&vetor[i], &vetor[j]);
        }
    }

    *indice_pivo = i+1;

    trocarValores(&vetor[*indice_pivo], &vetor[direita]);
}

void quickSort(int vetor[], int esquerda, int direita) {
    if (esquerda >= direita) return;
    
    int indice_pivo = novoIndicePivo(esquerda, direita);

    organizarVetorPivo(vetor, esquerda, direita, &indice_pivo);


    quickSort(vetor, esquerda, indice_pivo-1);
    quickSort(vetor, indice_pivo+1, direita);
}
// ========================================================================================

// IDIOMAS
int detectarIdioma() {
    const char* idioma = setlocale(LC_ALL, "");

    if (!idioma) return -1;

    if (strstr(idioma, "Portuguese")) return 1;

    if (strstr(idioma, "English")) return 2;

    if (strstr(idioma, "Spanish")) return 3;

    return -1;
}
// ========================================================================================

// INTERFACE
unsigned int novoTamanhoVetor() {
    int tam_vetor = -1;

    do {
        printf("Escolha o tamanho do vetor desejado: ");
        if (!scanf("%i", &tam_vetor)) getchar();
    } while(tam_vetor <= 0);

    return tam_vetor;
}

unsigned short escolherOpcao() {
    unsigned short opcao = 0;

    do {
        printf("Escolha uma opção: ");
        if (!scanf("%hu", &opcao)) getchar();
    } while (opcao < 1 || opcao > SAIR);

    return opcao;
}

void printMenu() {
    printf(
        "MENU PRINCIPAL\n\n"

        "Bem-vindo(a) ao meu programa de algoritmos de ordenação (sorting algorithms)!\n"
        "Opções:\n"
        "1. Bubble Sort\n"
        "2. Selection Sort\n"
        "3. Insertion Sort\n"
        "4. Merge Sort\n"
        "5. Quick Sort\n"
        "6. Counting Sort\n"
        "7. Radix Sort\n"
        "8. Heap Sort\n\n"        
    );

    if (autoRandom) printf("9. Desabilitar randomização automática (valor atual: TRUE)\n");

    else printf("9. Habilitar randomização automática (valor atual: FALSE)\n");

    printf(
        "10. Ramdomizar vetor\n"
        "11. Encerrar programa\n\n"

        "Vetor atual:\n"
    );
}
// ========================================================================================

// MAIN
int main() {
    srand(time(NULL));
    system("cls");

    detectarIdioma();

    unsigned int tam_vetor = novoTamanhoVetor();

    int vetor[tam_vetor];

    randomizarVetor(vetor, tam_vetor);

    unsigned short opcao = 0;

    do {
        system("cls");

        printMenu(autoRandom);

        printVetor(vetor, tam_vetor);
        putchar('\n');

        opcao = escolherOpcao();

        system("cls");

        switch (opcao) {
            case 1:
                printf(
                    "A opção escolhida foi 1. Bubble Sort!\n\n"
                    "Vetor original: "
                );
                printVetor(vetor, tam_vetor);

                bubbleSort(vetor, tam_vetor);

                printf("Vetor ordenado: ");
                printVetor(vetor, tam_vetor);

                break;

            case 2:
                printf(
                    "A opção escolhida foi 2. Selection Sort!\n\n"
                    "Vetor original: "
                );
                printVetor(vetor, tam_vetor);

                selectionSort(vetor, tam_vetor);

                printf("Vetor ordenado: ");
                printVetor(vetor, tam_vetor);

                break;

            case 3:
                printf(
                    "A opção escolhida foi 3. Insertion Sort!\n\n"
                    "Vetor original: "
                );
                printVetor(vetor, tam_vetor);

                insertionSort(vetor, tam_vetor);

                printf("Vetor ordenado: ");
                printVetor(vetor, tam_vetor);

                break;

            case 4:
                printf(
                    "A opção escolhida foi 4. Merge Sort!\n\n"
                    "Vetor original: "
                );
                printVetor(vetor, tam_vetor);

                mergeSort(vetor, 0, tam_vetor - 1);

                printf("Vetor ordenado: ");
                printVetor(vetor, tam_vetor);

                break;

            case 5:
                printf(
                    "A opção escolhida foi 5. Quick Sort!\n\n"
                    "Vetor original: "
                );
                printVetor(vetor, tam_vetor);

                quickSort(vetor, 0, tam_vetor - 1);

                printf("Vetor ordenado: ");
                printVetor(vetor, tam_vetor);

                break;

            case 6:
                printf(
                    "A opção escolhida foi 6. Counting Sort!\n\n"
                    "Vetor original: "
                );
                printVetor(vetor, tam_vetor);

                countingSort(vetor, tam_vetor);

                printf("Vetor ordenado: ");
                printVetor(vetor, tam_vetor);

                break;

            case 7:
                printf(
                    "A opção escolhida foi 7. Radix Sort!\n\n"
                    "Vetor original: "
                );
                printVetor(vetor, tam_vetor);

                radixSort(vetor, tam_vetor);

                printf("Vetor ordenado: ");
                printVetor(vetor, tam_vetor);

                break;

            case 8:
                printf(
                    "A opção escolhida foi 8. Heap Sort!\n\n"
                    "Vetor original: "
                );
                printVetor(vetor, tam_vetor);

                heapSort(vetor, tam_vetor);

                printf("Vetor ordenado: ");
                printVetor(vetor, tam_vetor);

                break;

            case 9:
                if (autoRandom) {
                    autoRandom = FALSE;
                    puts("Randomização automática desativada!");
                    puts("Você pode randomizar o vetor manualmente selecionando a opção 10. Randomizar vetor!");
                }

                else {
                    autoRandom = TRUE;
                    puts("Randomização automática ativada!");
                }
                break;

            case 10:
                if (randomizarVetor(vetor, tam_vetor) != 0) perror("Erro ao randomizar vetor");

                else puts("Vetor randomizado com sucesso!");
                break;

            default:
                puts("Encerrando o programa...");
        }

        if (autoRandom) randomizarVetor(vetor, tam_vetor);

        system("pause");

    } while (opcao != SAIR);

    system("cls");
    return 0;
}
