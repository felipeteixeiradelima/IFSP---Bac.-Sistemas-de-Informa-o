/*
Programa que simula o funcionamento de listas
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int isPilhaCheia(struct listasimples *p) {
    unsigned int contador = 0;
    struct listasimples *aux;
    aux = p;
    
    while (aux->prox != NULL){
        contador++;
        aux = aux->prox;
    }
    
    aux = NULL;
    free(aux);
    
    if (contador == TAM_MAX) return 1;
    return 0;
}

//função de inserir na pilha
int inserirPilha(struct listasimples *topo) {

    //se a pilha estiver cheia (TAM_MAX) retorna 0
    if (isPilhaCheia(pilha)) return 0;
    
    //criação de um ponteiro auxiliar
    struct listasimples *aux;
    aux = (struct listasimples*) malloc(sizeof(struct listasimples));
    
    scanf("%d", &aux->valor);
    
    //topo->prox aponta para o novo topo
    topo->prox = aux;
    
    //topo recebe aux (novo topo)
    topo = topo->prox;
    topo->prox = NULL;
    
    //limpa o ponteiro aux
    //aux = NULL;
    //free(aux);
    topo+=10;
    printf("\n%i %p %p\n", topo->valor, topo->prox, topo);
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
    } while (aux->prox != NULL);
    
    //limpa o ponteiro aux
    aux = NULL;
    free(aux);
    //retorna 1 indicando sucesso
    return 1;
}

unsigned short getOption() {
    unsigned short o;
    do {
        printf("Escolha uma opção: ");
        o =0;
        if (!scanf("%hu", &o)) getchar();
    } while (o < 1 && o > 4);
    return o;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    pilha = (struct listasimples*) malloc(sizeof(struct listasimples));
    pilha->prox = NULL;
    topoPilha = pilha;
    
    unsigned short opcao;
    
    do {
        puts("Opções:\n");
        puts("1. Inserir");
        puts("2. Remover");
        puts("3. Exibir");
        puts("4. Sair\n");
        opcao = getOption();
        switch (opcao) {
            case 1:
                if (!inserirPilha(topoPilha)) puts("A pilha está cheia!\n");
                break;
            case 2:
                if (!removerPilha(pilha, topoPilha)) puts("A pilha está vazia!\n");
                break;
            case 3:
                if (!exibirPilha(pilha)) puts("A pilha está vazia!\n");
                break;
        }
        printf("\n%i %p %p\n\n", topoPilha->valor, topoPilha->prox, topoPilha);
    } while (opcao != 4);
    
}
