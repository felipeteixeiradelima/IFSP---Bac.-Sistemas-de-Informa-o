/*
Programa que simula o funcionamento de listas
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

struct listasimples {
    int valor;
    struct listasimples* prox;
};

struct listadupla {
    int valor;
    struct listadupla *ant, *prox;
};

struct listasimples *pilha, *topoPilha;

int inserirPilha(struct listasimples *p, struct listasimples *topo) {
    if (p == topo) return 0;

    struct listasimples *aux;
    aux = (struct listasimples*) malloc(sizeof(struct listasimples));
    
    scanf("%d", aux->valor);
    
}

int main() {
    pilha = (struct listasimples*) malloc(TAM_MAX * sizeof(struct listasimples));
    pilha->prox = NULL;
    topoPilha = pilha;
    

}
