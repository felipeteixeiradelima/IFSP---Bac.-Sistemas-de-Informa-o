/*
Programa que simula o funcionamento de listas
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

//definir lista de encadeamento simples
struct listasimples {
    int valor;
    struct listasimples* prox;
};

//definir lista de encadeamento duplo
struct listadupla {
    int valor;
    struct listadupla *ant, *prox;
};

//criação dos ponteiros pilha (inicio da pilha) e topoPilha (final da pilha)
struct listasimples *pilha, *topoPilha;

//função de inserir na pilha
int inserirPilha(struct listasimples *topo) {

    //criação de um ponteiro auxiliar
    struct listasimples *aux;
    aux = (struct listasimples*) malloc(sizeof(struct listasimples));
    
    //aux->prox recebe NULL (vai virar o topo)
    aux->prox = NULL;
    scanf("%d", aux->valor);
    
    //topo->prox aponta para o novo topo
    topo->prox = aux;
    
    //topo recebe aux (novo topo)
    topo = aux;
    
    //limpa o ponteiro aux
    aux = NULL
    free(aux);
    
    //retorna 1 indicando sucesso
    return 1;
}

//função de remover da pilha
int removerPilha(struct listasimples *p, struct listasimples *topo) {
    //se a pilha estiver vazia retorna 0
    if (p->prox == NULL) return 0;
    
    struct listasimples *aux, *aux2;
    aux = p;
    
    //achar o penultimo item da pilha (1 antes do topo) e atribuir a aux
    while (aux->prox != topo) aux = aux->prox;
    
    //trocar o topo com o aux
    aux2 = aux;
    aux = topo;
    topo = aux2;
    
    //remover o proximo do topo
    topo->prox = NULL;
    
    //limpar os ponteiros
    aux2 = NULL;
    free(aux);
    free(aux2);
    
    //retorna 1 indicando sucesso
    return 1;
}

//função para exibir a pilha
int exibirPilha(struct listasimples *p) {
    //se a pilha estiver vazia retorna 0 indicando erro
    if (p->prox == NULL) return 0;
    
    //criação de um ponteiro auxiliar
    struct listasimples *aux;
    
    //aux recebe o início da pilha
    aux = p;
    
    //exibe todos os elementos da pilha (valor e endereço)
    do {
        printf("%i %p", aux->valor, aux);
    }while (aux->prox != NULL);
    
    //limpa o ponteiro aux
    aux = NULL;
    free(aux);
    //retorna 1 indicando sucesso
    return 1
}

int main() {
    pilha = (struct listasimples*) malloc(sizeof(struct listasimples));
    pilha->prox = NULL;
    topoPilha = pilha;
    

}
