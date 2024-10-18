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
struct listasimples *pilha = NULL, *topoPilha = NULL;

//função para iniciar a pilha
int iniciarPilha() {
    if (pilha) return 1;
    pilha = (struct listasimples*) malloc(sizeof(struct listasimples));
    pilha->prox = NULL;
    topoPilha = NULL;

    return 0;
}

//função para verificar se a pilha está cheia
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

    //se a pilha ainda não foi inicializada, retorna 1 indicando erro
    if(pilha == NULL) return 1;

    //se a pilha estiver cheia (TAM_MAX) retorna 2 indicando erro
    if (isPilhaCheia()) return 2;
    
    //se a pilha estiver vazia
    if (!topoPilha) {
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

    //se a pilha ainda não foi inicializada, retorna 1 indicando erro
    if(pilha == NULL) return 1;

    //se a pilha estiver vazia retorna 2 indicando erro
    if (!topoPilha) return 2;
    
    //caso haja apenas 1 elemento na pilha:
    if (topoPilha == pilha) {
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

    //se a pilha ainda não foi inicializada, retorna 1 indicando erro
    if(pilha == NULL) return 1;

    //se a pilha estiver vazia retorna 2 indicando erro
    if (!topoPilha) return 2;
    
    //caso haja apenas 1 elemento na pilha
    if (topoPilha == pilha) {
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

//função para pegar a opção
unsigned short getOption() {
    unsigned short o;
    do {
        printf("Escolha uma opção: ");
        o = 0;
        if (!scanf("%hu", &o)) getchar();
    } while (o < 1 && o > 6);
    return o;
}

//função para limpar a pilha
int limparPilha () {
    //se a pilha não tiver sido inicializada, retorna 1 indicando erro
    if (!pilha) return 1;

    //caso especial em que não há elementos na pilha
    if (!topoPilha) {
        free(pilha);
        pilha = NULL;
    }

    //caso especial em que há apenas 1 elemento na pilha
    else if (topoPilha == pilha) {
        free(pilha);
        pilha = topoPilha = NULL;
    }

    //se a pilha tiver >1 elementos
    else {
        //variável auxiliar para limpar os elementos
        struct listasimples *aux;
        aux = pilha;

        //passa por todos os elementos e os limpa
        do {
            free(aux);
            aux = aux->prox;
        } while (aux);
        
        pilha = topoPilha = NULL;
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    unsigned short opcao;

    do {
        puts("Opções:\n");
        puts("1. Iniciar pilha");
        puts("2. Inserir");
        puts("3. Remover");
        puts("4. Exibir");
        puts("5. Limpar pilha");
        puts("6. Sair\n");
        opcao = getOption();
        switch (opcao) {
            
            //caso opcao = 1 (iniciar pilha)
            case 1:
                
                //se return = 1 erro: a pilha já foi inicializada
                if (iniciarPilha()) puts("A pilha já foi inicializada!\n");

                //se sucesso, imprime que a pilha foi inicializada
                puts("Pilha inicializada com sucesso!\n");
                
                break;
            
            //caso opcao = 2 (inserir na pilha)
            case 2:

                //switch para os erros da função inserirPilha()
                switch (inserirPilha()) {

                    //erro 1 = pilha não inicializada
                    case 1:
                        puts("A pilha ainda não foi inicializada!");
                        puts("Inicie a pilha no menu principal para realizar essa ação!\n");
                        break;
                    
                    //erro 2 = pilha cheia
                    case 2:
                        puts("A pilha está cheia!");
                        puts("Remova um item da pilha para realizar essa ação!");
                        break;
                    
                    //sucesso (não houve erro)
                    default:
                        puts("Valor inserido na pilha com sucesso!");
                        break;
                }
                break;

            case 3:

                //switch para os erros da função removerPilha()
                switch (removerPilha()) {

                    //erro 1 = pilha não inicializada
                    case 1:
                        puts("A pilha ainda não foi inicializada!");
                        puts("Inicie a pilha no menu principal para realizar essa ação!\n");
                        break;
                    
                    //erro 2 = pilha vazia
                    case 2:
                        puts("A pilha está vazia!");
                        puts("Insira um item na pilha para realizar essa ação!");
                        break;
                    
                    //sucesso (não houve erro)
                    default:
                        puts("Valor no topo da pilha removido com sucesso!");
                        break;
                }
                break;

            case 4:
                
                //switch para os erros da função exibirPilha()
                switch (exibirPilha()) {

                    //erro 1 = pilha não inicializada
                    case 1:
                        puts("A pilha ainda não foi inicializada!");
                        puts("Inicie a pilha no menu principal para realizar essa ação!\n");
                        break;
                    
                    //erro 2 = pilha vazia
                    case 2:
                        puts("A pilha está vazia!");
                        puts("Insira um item na pilha para realizar essa ação!");
                        break;
                    
                }
                break;
            
            case 5:
            
                //se return = 1 erro: a pilha ainda não foi inicializada
                if (limparPilha()) {
                    puts("A pilha ainda não foi inicializada!");
                    puts("Inicie a pilha no menu principal para realizar essa ação!\n");
                }
                
                //senão, sucesso
                else {
                    puts("A pilha foi limpa com sucesso!\n");
                }
                
                break;

        }
        if (topoPilha) printf("\ntopoPilha - main: %i %p %p\n\n", topoPilha->valor, topoPilha->prox, topoPilha);
    } while (opcao != 6);

    return 0;
}
