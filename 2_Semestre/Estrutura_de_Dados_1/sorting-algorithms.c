#include <stdio.h>
#include <stdlib.h>

#define TAM_VETOR 10

int iniciarVetorRandomizado(int* vetor) {
    for(int i = 0; i < TAM_VETOR; i++) {
        vetor[i] = rand() % 100;
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
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
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
    int aux, pos_menor;
    
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%i ", vetor[i]);
    }

    putchar('\n');

    for (int i = 0; i < TAM_VETOR; i++) {
        pos_menor = i;
        for (int j = i+1; j < TAM_VETOR; j++) {
            if (vetor[j] < vetor[pos_menor]) {
                pos_menor = j;
            }
        }
        aux = vetor[pos_menor];
        vetor[pos_menor] = vetor[i];
        vetor[i] = aux;

        for (int k = 0; k < TAM_VETOR; k++) {
            printf("%i ", vetor[k]);
        }

        putchar('\n');
    }

    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%i ", vetor[i]);
    }
}

int main() {
    int vetor_bubble[TAM_VETOR], vetor_selection[TAM_VETOR], vetor_insert[TAM_VETOR];

    iniciarVetorRandomizado(vetor_bubble);
    iniciarVetorRandomizado(vetor_selection);
    iniciarVetorRandomizado(vetor_insert);

    // bubbleSort(vetor_bubble);
    // selectionSort(vetor_selection);

}
