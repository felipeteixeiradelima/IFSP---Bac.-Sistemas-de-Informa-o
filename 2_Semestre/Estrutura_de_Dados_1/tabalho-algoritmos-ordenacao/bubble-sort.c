#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int tamanho_vetor;
    double tempo_decorrido;
} Resultado;

int lerArquivo(int* vetor) {
    FILE *leitor_arq;
    leitor_arq = fopen("arq_teste.txt", "r");
    
    if (!leitor_arq) {
        perror("Nao foi possivel abrir o arquivo");
        return 1;
    }

    for (unsigned short i = 0; !feof(leitor_arq);) {
        if (!fscanf(leitor_arq, "%i", &vetor[i])) getc(leitor_arq);
        else ++i;
    }

    free(leitor_arq);
    return 0;
}

void trocar(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void sort(int* vetor, unsigned short tamanho_vetor) {
    for (short i = tamanho_vetor; i >= 0; i--) {
        for (unsigned short j = 0; j < i ; j++) {
            if (vetor[j] > vetor[j+1])
                trocar(&vetor[j], &vetor[j+1]);
        }
    }
}

Resultado gerarResultado(unsigned short tamanho_vetor, int vetor[tamanho_vetor]) {
    Resultado resultado;

    puts("Vetor original:");
    for (unsigned short i = 0; i < tamanho_vetor; i++) printf("%i ", vetor[i]);

    clock_t inicio = clock();

    sort(vetor, tamanho_vetor);

    clock_t fim = clock();

    puts("\n\nVetor ordenado:");
    for (unsigned short i = 0; i < tamanho_vetor; i++) printf("%i ", vetor[i]);
    puts("\n");

    resultado.tempo_decorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;
    resultado.tamanho_vetor = tamanho_vetor;

    return resultado;
}

int main() {
    int vetor_completo[5000];

    lerArquivo(vetor_completo);

    for (unsigned int contador = 500; contador <= 5000; contador+=500) {

        Resultado resultado = gerarResultado(contador, vetor_completo);

        printf("O tempo decorrido para organizar %i ELEMENTOS foi de %f SEGUNDOS\n\n", resultado.tamanho_vetor, resultado.tempo_decorrido);

        system("pause");
    }
}
