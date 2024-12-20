#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#define TAM_VETOR 10
#define TRUE 1
#define FALSE 0

int iniciarVetorRandomizado(int* vetor) {
    for(int i = 0; i < TAM_VETOR; i++) {
        do {
            vetor[i] = rand() % 1000;
        } while (vetor[i] < 100 && vetor[i] < 0);
    }
    return 0;
}

void printVetor(int vetor[], size_t tam_vetor) {
    for (unsigned short i = 0; i < (int) tam_vetor; i++) printf("%i ", vetor[i]);
    putchar('\n');
}

int trocarValores(int* a, int*b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    return 0;
}

int descobrirDigitos(int vetor[], size_t tam_vetor) {
    int d = 0, aux, aux_d;

    for (unsigned int i = 0; i < (int) tam_vetor; ++i) {
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

unsigned int descobrirMaximo(int vetor[], size_t tam_vetor) {
    unsigned int max = vetor[0];

    for (unsigned int i = 1; i < (int) tam_vetor; ++i) {
        if (vetor[i] > max) max = vetor[i];
    }

    return max;
}

void sift(int* heap, int i) {
    int j = i, indice_pai = j/2;

    do {
        if (heap[j] >= heap[indice_pai]) break;

        trocarValores(&heap[j], &heap[indice_pai]);
        j = indice_pai;
        indice_pai = j/2;

    } while (j > 0);
}

void converterParaHeap(int* vetor, int tam_vetor) {
    int heap[tam_vetor];

    for (int i = 0; i < tam_vetor; i++) {
        heap[i] = vetor[i];
        sift(heap, i);
    }

    for (int i = 0; i < tam_vetor; i++) {
        vetor[i] = heap[i];
    }
}

void inserirPrimeiroNoFinalHeap(int* heap, int tam_heap) {
    for (int i = 0; i < tam_heap-1; i++) trocarValores(&heap[i], &heap[i+1]);
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

int radixSubrotinaCountingSort(int vetor[], size_t tam_vetor, unsigned int digito) {
    unsigned char tam_count = 10;

    int vetor_count[tam_count], vetor_sorted[(int)tam_vetor];
    
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

int bubbleSort(int* vetor) {
    int aux;
    
    printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );

    for (int i = TAM_VETOR-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vetor[i] < vetor[j]) {
                trocarValores(&vetor[i], &vetor[j]);
            }
        }
        
        printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );
    }

    printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );
}

int selectionSort(int* vetor) {
    int pos_menor;
    
    printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );

    for (int i = 0; i < TAM_VETOR; i++) {
        pos_menor = i;
        for (int j = i+1; j < TAM_VETOR; j++) {
            if (vetor[j] < vetor[pos_menor]) pos_menor = j;
        }

        trocarValores(&vetor[pos_menor], &vetor[i]);

        printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );
    }

    printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );
}

int insertionSort(int* vetor) {

    printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );

    for (int i = 0; i < TAM_VETOR - 1; i++) {
        if (vetor[i] > vetor[i+1]) {
            for (int j = i+1; j != 0; j--) {
                if (vetor[j-1] <= vetor[j]) break;

                trocarValores(&vetor[j-1], &vetor[j]);

                printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );
            }
        }
    }
}

int heapSort(int* vetor) {

    printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );

    converterParaHeap(vetor, TAM_VETOR);

    for (unsigned short i = 0; i < TAM_VETOR; i++) {
        inserirPrimeiroNoFinalHeap(vetor, TAM_VETOR);
        converterParaHeap(vetor, TAM_VETOR-1-i);
    }

    printVetor(vetor, ( sizeof(vetor) / sizeof(vetor[0]) ) );
}

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

int radixSort(int vetor[], size_t tam_vetor) {
    int totalDigitos = descobrirDigitos(vetor, tam_vetor);

    for (unsigned int i = 1; i <= totalDigitos; ++i) {
        radixSubrotinaCountingSort(vetor, tam_vetor, i);
    }
}

int countingSort(int vetor[], size_t tam_vetor) {
    unsigned int tam_count = descobrirMaximo(vetor, tam_vetor) + 1;

    int vetor_count[tam_count], vetor_sorted[(int)tam_vetor];
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

int main() {
    srand(time(NULL));

    int vetor[TAM_VETOR];

    size_t tam_vetor = sizeof(vetor) / sizeof(vetor[0]);

    iniciarVetorRandomizado(vetor);

    printVetor(vetor, tam_vetor);
    
    // bubbleSort(vetor);

    // selectionSort(vetor);

    // insertionSort(vetor);

    // heapSort(vetor);

    // mergeSort(vetor, 0, (int) tam_vetor - 1);

    // countingSort(vetor, tam_vetor);

    // radixSort(vetor, tam_vetor);

    printVetor(vetor, tam_vetor);

    return 0;
}
