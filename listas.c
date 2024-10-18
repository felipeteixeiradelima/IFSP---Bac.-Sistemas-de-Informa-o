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

int isPilhaCheia() {
    unsigned int contador = 0;
    struct listasimples *aux;
    aux = pilha;
    do {
        contador++;
        aux = aux->prox;
    } while (aux);

    if (contador == TAM_MAX) return 1;
    return 0;
}

//função de inserir na pilha
int inserirPilha() {

    //se a pilha estiver cheia (TAM_MAX) retorna 1 indicando erro
    if (isPilhaCheia()) return 1;
    
    //se a pilha estiver vazia
    else if (!topoPilha) {
        scanf("%d", &pilha->valor);
        topoPilha = pilha;
    }
    
    //se a pilha tiver pelo menos 1 elemento
    else {
        //criação de um ponteiro auxiliar
        struct listasimples *aux;
        aux = (struct listasimples*) malloc(sizeof(struct listasimples));

        scanf("%d", &aux->valor);
        aux->prox = NULL;
    
        //topo->prox aponta para o novo topo
        topoPilha->prox = aux;

        //topo recebe aux (novo topo)
        topoPilha = aux;
        
        if (aux) printf("\naux - inserir: %i %p %p\n", aux->valor, aux->prox, aux);
    }
    
    printf("\ntopoPilha - inserir: %i %p %p\n", topoPilha->valor, topoPilha->prox, topoPilha);
    //retorna 0 indicando sucesso
    return 0;
}

//função de remover da pilha
int removerPilha() {
    //se a pilha estiver vazia retorna 1 indicando erro
    if (!topoPilha) return 1;
    
    //caso haja apenas 1 elemento na pilha:
    else if (topoPilha == pilha) {
        //aponta o topo para NULL
        topoPilha = NULL;
    }
    
    //se houver >1 elementos na pilha:
    else {
        //cria 1 ponteiro auxiliar
        struct listasimples *aux;
        aux = pilha;

        //achar o penultimo item da pilha (1 antes do topo) e atribuir a aux
        while (aux->prox != topoPilha) aux = aux->prox;

        //removendo o topo
        free(topoPilha);
        
        //removendo o proximo do aux (novo topo)
        aux->prox = NULL;
        
        //topo recebe aux (novo topo)
        topoPilha = aux;
    }

    //retorna 0 indicando sucesso
    return 0;
}

//função para exibir a pilha
int exibirPilha() {
    //se a pilha estiver vazia retorna 1 indicando erro
    if (!topoPilha) return 1;
    
    //caso haja apenas 1 elemento na pilha
    else if (topoPilha == pilha) {
        printf("%i %p\n", pilha->valor, pilha);
    }
    
    //se houver >1 elementos na pilha
    else {
        //criação de um ponteiro auxiliar
        struct listasimples *aux;

        //aux recebe o início da pilha
        aux = pilha;

        //exibe todos os elementos da pilha (valor e endereço)
        do {
            printf("%i %p\n", aux->valor, aux);
            aux = aux->prox;
        } while (aux);
    }
    
    //retorna 0 indicando sucesso
    return 0;
}

unsigned short getOption() {
    unsigned short o;
    do {
        printf("Escolha uma opção: ");
        o = 0;
        if (!scanf("%hu", &o)) getchar();
    } while (o < 1 && o > 4);
    return o;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    pilha = (struct listasimples*) malloc(sizeof(struct listasimples));
    pilha->prox = NULL;
    topoPilha = NULL;

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
                if (inserirPilha(topoPilha)) puts("A pilha está cheia!\n");
                break;
            case 2:
                if (removerPilha(pilha, topoPilha)) puts("A pilha está vazia!\n");
                break;
            case 3:
                if (exibirPilha(pilha)) puts("A pilha está vazia!\n");
                break;
        }
        if (topoPilha) printf("\ntopoPilha - main: %i %p %p\n\n", topoPilha->valor, topoPilha->prox, topoPilha);
    } while (opcao != 4);
}