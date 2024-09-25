/*
     ___  ______  ______  ______
    /  / /  ___/ /  ___/ / __  /
   /  / /  /__  /  /__  / /_/ /
  /  / /  ___/ /__   / /  ___/
 /  / /  /    ___/  / /  /
/__/ /__/    /_____/ /__/


INSTITUTO FEDERAL DE EDUCACAO, CIENCIA E TECNOLOGIA DE SAO PAULO (IFSP)

SPOEDD1 - Estrutura de Dados 1 | Profº Antônio Ferreira Viana

Aluno: Felipe Teixeira de Lima
RA: SP3515048

Tarefa: criação de pilha e fila em linguagem C
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#define TAM_MAX 10

bool confirmar(char mensagem[100]) {
	char resposta;
	do {
		puts(mensagem);
		scanf(" %c", &resposta);
		resposta = toupper(resposta);
	} while(!(resposta == 'S' || resposta == 'N'));
	if (resposta == 'S') return true;
	else return false;
}

void capa() {
	puts("---------------------------------------------------------------------------");
	puts("|                                                                         |");
	puts("| INSTITUTO FEDERAL DE EDUCACAO, CIENCIA E TECNOLOGIA DE SAO PAULO (IFSP) |");
	puts("|                                                                         |");
	puts("|      SPOEDD1 - Estrutura de Dados 1 | Profº Antônio Ferreira Viana      |");
	puts("|                                                                         |");
	puts("|                     Aluno: Felipe Teixeira de Lima                      |");
	puts("|                                                                         |");
	puts("|                              RA: SP3515048                              |");
	puts("|                                                                         |");
	puts("|             TAREFA: criação de pilha e fila em linguagem C              |");
	puts("|                                                                         |");
	puts("---------------------------------------------------------------------------\n\n");
}

unsigned short menu() {
	unsigned short opcao;
	puts("Bem vindo ao menu principal!\n");
	puts("Opções de PILHA:");
	puts("1. Inserir valor na pilha");
	puts("2. Remover valor da pilha");
	puts("3. Exibir o topo da pilha");
	puts("4. Verificar se a pilha está vazia ou cheia\n");
	puts("Opções de FILA:");
	puts("5. Inserir valor na fila");
	puts("6. Remover valor da fila");
	puts("7. Exibir elementos e posições da fila");
	puts("8. Verificar se a fila está vazia ou cheia");
	puts("9. Localizar um elemento na fila\n");
	puts("10. Sair do programa\n");
	do{
		opcao = 0;
		printf("Digite uma opção: ");
		if (!scanf("%hu", &opcao)) getchar();
	} while(opcao < 1 || opcao > 10);
	system("CLS");
	return opcao;
}

void inserirPilha(int *ptrPilha, unsigned short *tam_Pilha) {
	printf("Digite o valor a ser inserido na pilha: ");
	while (!scanf("%i", &ptrPilha[*tam_Pilha])) {
		getchar();
		printf("Digite o valor a ser inserido na pilha: ");
	}
	system("CLS");
	printf("O valor %i foi inserido na pilha!\n\n", ptrPilha[*tam_Pilha]);
	++*tam_Pilha;
}

void removerPilha(int *ptrPilha, unsigned short *tam_Pilha) {
	--*tam_Pilha;
	ptrPilha[*tam_Pilha] = 0;
	puts("O elemento no topo da pilha foi removido!\n");
}

void exibirTopoPilha(int pilha[TAM_MAX], unsigned short tam_Pilha) {
	puts("Índice | Valor | Endereço\n");
	printf("%hu | %i | %p\n\n", tam_Pilha, pilha[tam_Pilha-1], pilha+tam_Pilha-1);
}

void verificarCheiaVazia(unsigned short tamanho, char tipo[6]) {
	if (tamanho == 0) printf("A %s está vazia!\n", tipo);
	else if (tamanho == 1) printf("A %s ainda não está cheia! No momento, ela possui 1 elemento.\n", tipo);
	else if (tamanho < TAM_MAX) printf("A %s ainda não está cheia! No momento, ela possui %hu elementos.\n", tipo, tamanho);
	else printf("A %s está cheia!\n", tipo);
	putchar('\n');
}

void inserirFila(int *ptrFila, unsigned short *tam_Fila) {
	printf("Digite o valor a ser inserido na fila: ");
	while (!scanf("%i", &ptrFila[*tam_Fila])) {
		getchar();
		printf("Digite o valor a ser inserido na fila: ");
	}
	system("CLS");
	printf("O valor %i foi inserido na fila!\n\n", ptrFila[*tam_Fila]);
	++*tam_Fila;
}

void removerFila(int *ptrFila, unsigned short *tam_Fila) {
	--*tam_Fila;
	for (unsigned i = 0; i < *tam_Fila; i++) {
		ptrFila[i] = ptrFila[i+1];
	}
	puts("O elemento no começo da fila foi removido!\n");
}

void exibirFila(int fila[TAM_MAX], unsigned short tam_Fila) {
	puts("Índice | Valor | Endereço\n");
	for (unsigned short i = 0; i < tam_Fila; i++) {
		printf("%hu | %i | %p\n", i, fila[i], &fila[i]);
	}
	putchar('\n');
}

void buscarFila(int fila[TAM_MAX], unsigned short tam_Fila) {
	int valor;
	unsigned short i, contador;
	while (true) {
		contador = 0;
		printf("Digite o valor a ser pesquisado (digite 'S' para voltar ao menu principal): ");
		if (!scanf("%i", &valor)) {
			if (toupper(getchar()) == 'S') {
				if (confirmar("Deseja voltar ao menu principal? (S/N)")) break;
			}
		}
		else {
			putchar('\n');
			for (i = 0; i < tam_Fila; i++) if (fila[i] == valor) ++contador;
			if (contador == 0) printf("O valor %i não foi encontrado na pilha!\n", valor);
			else {
				if (contador == 1) printf("Há 1 ocorrência de %i na fila. Eis o índice e endereço dessa ocorrência:\n\n", valor);
				else printf("Há %hu ocorrências de %i na fila. Eis os índices e endereços de cada ocorrência:\n\n", contador, valor);
				puts("Índice|Valor|Endereço");
				for (i = 0; i < tam_Fila; i++) {
					if (fila[i] == valor) {
						printf("%hu | %i | %p\n", i, fila[i], &fila[i]);
					}
				}
			}
		}
		putchar('\n');
		system("pause");
		system("CLS");
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	bool exit = false;
	int pilha[TAM_MAX], fila[TAM_MAX];
	unsigned short tam_Pilha = 0, tam_Fila = 0;

	system("CLS");
	capa();
	system("pause");
	do {
		system("CLS");
		switch (menu()) {
			case 1:
				if (tam_Pilha == TAM_MAX) puts("A pilha está cheia! Remova ao menos um elemento da pilha para executar essa ação!\n");
				else inserirPilha(pilha, &tam_Pilha);
				break;
			case 2:
				if (tam_Pilha == 0) puts("A pilha está vazia! Insira ao menos um elemento da pilha para executar essa ação!\n");
				else removerPilha(pilha, &tam_Pilha);
				break;
			case 3:
				if (tam_Pilha == 0) puts("A pilha está vazia! Insira ao menos um elemento da pilha para executar essa ação!\n");
				else exibirTopoPilha(pilha, tam_Pilha);
				break;
			case 4:
				verificarCheiaVazia(tam_Pilha, "pilha");
				break;
			case 5:
				if (tam_Fila == TAM_MAX) puts("A fila está cheia! Remova ao menos um elemento da fila para executar essa ação!\n");
				else inserirFila(fila, &tam_Fila);
				break;
			case 6:
				if (tam_Fila == 0) puts("A fila está vazia! Insira ao menos um elemento da fila para executar essa ação!\n");
				else removerFila(fila,&tam_Fila);
				break;
			case 7:
				if (tam_Fila == 0) puts("A fila está vazia! Insira ao menos um elemento da fila para executar essa ação!\n");
				else exibirFila(fila,tam_Fila);
				break;
			case 8:
				verificarCheiaVazia(tam_Fila, "fila");
				break;
			case 9:
				if (tam_Fila == 0) puts("A fila está vazia! Insira ao menos um elemento da fila para executar essa ação!\n");
				else {
					buscarFila(fila,tam_Fila);
					system("CLS");
					puts("Voltando ao menu principal...\n");
				}
				break;
			case 10:
				if (confirmar("\nVocê deseja encerrar o programa? (S/N)")) exit = true;
				break;
		}
		if (exit) {
			system("CLS");
			puts("Encerrando o programa...\n");
		}
		system("pause");
	} while(!exit);

	system("CLS");
	return 0;
}
