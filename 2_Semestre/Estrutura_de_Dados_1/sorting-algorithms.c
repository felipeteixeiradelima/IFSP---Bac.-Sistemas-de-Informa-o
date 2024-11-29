#include <stdio.h>
#include <stdlib.h>

#define TAM_VETOR 10

int trocarValores(int* a, int*b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    return 0;
}

int descobrirDigitos(int valor) {
    int d = 0, aux = valor;

    while (aux > 1) {
        aux /= 10;
        ++d;
    }

    return d;
}

int iniciarVetorRandomizado(int* vetor) {
    for(int i = 0; i < TAM_VETOR; i++) {
        do {
            vetor[i] = rand() % 1000;
        } while (vetor[i] < 100);
    }
    return 0;
}

int bubbleSort(int* vetor) {
    int aux;
    
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%i ", vetor[i]);
    }

    putchar('\n');

    for (int i = TAM_VETOR-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vetor[i] < vetor[j]) {
                trocarValores(&vetor[i], &vetor[j]);
            }
        }
        
        for (int k = 0; k < TAM_VETOR; k++) {
            printf("%i ", vetor[k]);
        }

        putchar('\n');
    }

    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%i ", vetor[i]);
    }
}

int selectionSort(int* vetor) {
    int pos_menor;
    
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%i ", vetor[i]);
    }

    putchar('\n');

    for (int i = 0; i < TAM_VETOR; i++) {
        pos_menor = i;
        for (int j = i+1; j < TAM_VETOR; j++) {
            if (vetor[j] < vetor[pos_menor]) pos_menor = j;
        }

        trocarValores(&vetor[pos_menor], &vetor[i]);

        for (int k = 0; k < TAM_VETOR; k++) printf("%i ", vetor[k]);

        putchar('\n');
    }

    for (int i = 0; i < TAM_VETOR; i++) printf("%i ", vetor[i]);
}

int insertionSort(int* vetor) {

    for (int k = 0; k < TAM_VETOR; k++) {
        printf("%i ", vetor[k]);
    }
    
    putchar('\n');

    for (int i = 0; i < TAM_VETOR - 1; i++) {
        if (vetor[i] > vetor[i+1]) {
            for (int j = i+1; j != 0; j--) {
                if (vetor[j-1] <= vetor[j]) break;

                trocarValores(&vetor[j-1], &vetor[j]);

                for (int k = 0; k < TAM_VETOR; k++) {
                    printf("%i ", vetor[k]);
                }

                putchar('\n');
            }
        }
    }
}

int radixSort(int* vetor) {
   int d = descobrirDigitos(vetor[TAM_VETOR-1]);
   int vetor_aux; 
}

int main() {
    int vetor_bubble[TAM_VETOR], vetor_selection[TAM_VETOR], vetor_insert[TAM_VETOR], vetor_radix[TAM_VETOR];

    iniciarVetorRandomizado(vetor_bubble);
    iniciarVetorRandomizado(vetor_selection);
    iniciarVetorRandomizado(vetor_insert);
    iniciarVetorRandomizado(vetor_radix);

    
    // bubbleSort(vetor_bubble);

    // selectionSort(vetor_selection);

    // insertionSort(vetor_insert);

    // radixSort(vetor_radix);
    int d = 0, aux = (float) vetor_radix[2];

    while (aux > 1) {
        aux /= 10;
        ++d;
    }

    printf("d = %i\naux = %i\nvetor_radix[2] = %i", d, aux, vetor_radix[2]);

}
