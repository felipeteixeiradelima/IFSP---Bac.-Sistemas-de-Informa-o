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

//definição do tamanho máximo da pilha/fila
#define TAM_MAX 10

bool confirmar(char mensagem[100]) {			//imprime uma mensagem na tela e captura um char do teclado, retornando True se char = 'S' e False se char = 'N'
	char resposta;						//char que armazena o input do usutário
	do {						//<----------------------------------------------------------------------------
		puts(mensagem);					//imprime a mensagem						       |
		scanf(" %c", &resposta);			//captura o char do teclado					       |
		resposta = toupper(resposta);			//torna a resposta maiúscula (caso o usuário digite char minúsculo)    |
	} while(!(resposta == 'S' || resposta == 'N'));		//se o char for diferente de 'S' e 'N', repete o processo -------------
	if (resposta == 'S') return true;			//se resposta = 'S' retorna True
	else return false;					//senão retorna Fase
}

void capa() {		//imprime a capa do programa
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

unsigned short menu() {						//imprime o menu principal do programa; captura e retorna um número do usuário que é a opção escolhida
	unsigned short opcao;						//número para armazenar a opção escolhida
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
	do{							//<---------------------------------------------------------------------------------------------------
		opcao = 0;						//reseta o número opcao para 0								      |
		printf("Digite uma opção: ");				//											      |
		if (!scanf("%hu", &opcao)) getchar();			//opcao recebe input do usuário; se for um caractere, getchar() para exception handling       |
	} while(opcao < 1 || opcao > 10);				//se opcao não estiver entre o intervalo [1,10], repete o processo ---------------------------
	system("CLS");
	return opcao;
}

void inserirPilha(int *ptrPilha, unsigned short *tam_Pilha) {		//insere um valor na PILHA, parâmetros são um ponteiro para a pilha em que se deseja inserir o elemento e outro ponteiro para o tamanho da pilha
	printf("Digite o valor a ser inserido na pilha: ");
	while (!scanf("%i", &ptrPilha[*tam_Pilha])) {				//armazena o input do usuário na pilha; se o usuário digitar um char: <------
		getchar();							//getchar() para receber o char do stdin				     |
		printf("Digite o valor a ser inserido na pilha: ");		//									     |
	}									//---------------------------------------------------------------------------
	system("CLS");
	printf("O valor %i foi inserido na pilha!\n\n", ptrPilha[*tam_Pilha]);	//confirma a inserção do elemento na pilha
	++*tam_Pilha;								//aumenta em 1 o tamanho da pilha
}

void removerPilha(int *ptrPilha, unsigned short *tam_Pilha) {		//remove um valor da PILHA, parâmetros são um ponteiro para a pilha em que se deseja remover o elemento e outro ponteiro para o tamanho da pilha
	--*tam_Pilha;								//remove em 1 o tamanho da pilha
	puts("O elemento no topo da pilha foi removido!\n");
}

void exibirTopoPilha(int pilha[TAM_MAX], unsigned short tam_Pilha) {			//exibe o topo da PILHA, parâmetros são a pilha cujo topo se deseja imprimir e o tamanho da pilha
	puts("Índice | Valor | Endereço\n");
	printf("%hu | %i | %p\n\n", tam_Pilha, pilha[tam_Pilha-1], pilha+tam_Pilha-1);		//imprime o índice, o valor e o endereço do elemento no topo
}

void verificarCheiaVazia(unsigned short tamanho, char tipo[6]) {		//verifica se a PILHA ou a FILA está cheia ou vazia
	if (tamanho == 0) printf("A %s está vazia!\n", tipo);
	else if (tamanho == 1) printf("A %s ainda não está cheia! No momento, ela possui 1 elemento.\n", tipo);
	else if (tamanho < TAM_MAX) printf("A %s ainda não está cheia! No momento, ela possui %hu elementos.\n", tipo, tamanho);
	else printf("A %s está cheia!\n", tipo);
	putchar('\n');
}

void inserirFila(int *ptrFila, unsigned short *tam_Fila) {		//insere um valor na FILA, parâmetros são um ponteiro para a fila em que se deseja inserir o elemento e outro ponteiro para o tamanho da fila
	printf("Digite o valor a ser inserido na fila: ");
	while (!scanf("%i", &ptrFila[*tam_Fila])) {				//armazena o input do usuário na fila; se o usuário digitar um char: <-------
		getchar();							//getchar() para receber o char do stdin				     |
		printf("Digite o valor a ser inserido na fila: ");		//									     |
	}									//---------------------------------------------------------------------------
	system("CLS");
	printf("O valor %i foi inserido na fila!\n\n", ptrFila[*tam_Fila]);	//confirma a inserção do elemento na pilha
	++*tam_Fila;								//aumenta em 1 o tamanho da pilha
}

void removerFila(int *ptrFila, unsigned short *tam_Fila) {			//remove um valor da FILA, parâmetros são um ponteiro para a fila em que se deseja remover o elemento e outro ponteiro para o tamanho da fila
	--*tam_Fila;								//remove em 1 o tamanho da fila
	for (unsigned i = 0; i < *tam_Fila; i++) {				//loop que passa por toda a fila
		ptrFila[i] = ptrFila[i+1];					//desloca o elemento 1 valor para a esquerda
	}
	puts("O elemento no começo da fila foi removido!\n");
}

void exibirFila(int fila[TAM_MAX], unsigned short tam_Fila) {		//exibe toda a FILA, parâmetros são a fila que se deseja exibir e o tamanho da fila
	puts("Índice | Valor | Endereço\n");
	for (unsigned short i = 0; i < tam_Fila; i++) {				//loop que passa por toda a fila
		printf("%hu | %i | %p\n", i, fila[i], &fila[i]);		//imprime o índice, o valor e o endereço de cada elemento da fila
	}
	putchar('\n');
}

void buscarFila(int fila[TAM_MAX], unsigned short tam_Fila) {						//busca um valor na FILA parâmetros são a fila que se deseja exibir e o tamanho da fila
	int valor;												//armazena o número que o usuário quer buscar
	unsigned short i, contador;										//i = auxiliar para os loops, contador = conta quantas aparições do valor pesquisado ocorrem na fila
	while (true) {												//loop infinito (até uma quebra manual - break)
		contador = 0;											//reseta contador para 0
		printf("Digite o valor a ser pesquisado (digite 'S' para voltar ao menu principal): ");
		if (!scanf("%i", &valor)) {									//recebe o valor digitado pelo usuário; se falhar:
			if (toupper(getchar()) == 'S') {								//se o que foi digitado for um char e esse char for igual a 'S':
				if (confirmar("Deseja voltar ao menu principal? (S/N)")) break;					//se a função confirmar() retornar verdadeiro, sai do loop infinito
			}
		}
		else {												//se não falhar (ou seja, se valor foi capturado com sucesso):
			putchar('\n');
			for (i = 0; i < tam_Fila; i++) if (fila[i] == valor) ++contador;				//loop que passa pela fila intera; se o elemento da fila == valor pesquisado aumenta em 1 o contador
			if (contador == 0) printf("O valor %i não foi encontrado na pilha!\n", valor);			//se contador == 0, não há ocorrências do valor pesquisado
			else {												//senão:
				if (contador == 1) printf("Há 1 ocorrência de %i na fila. Eis o índice e endereço dessa ocorrência:\n\n", valor);	//se contador == 1, imprimir mensagem especial
				else printf("Há %hu ocorrências de %i na fila. Eis os índices e endereços de cada ocorrência:\n\n", contador, valor);	//senão, imprimir mensagem genérica
				puts("Índice|Valor|Endereço");
				for (i = 0; i < tam_Fila; i++) {							//loop que passa por toda a fila
					if (fila[i] == valor) {								//se valor do elemento da fila == valor pesquisado:
						printf("%hu | %i | %p\n", i, fila[i], &fila[i]);			//imprimir índice, valor e endereço do elemento
					}
				}
			}
		}
		putchar('\n');
		system("pause");
		system("CLS");
	}
}

//função principal
int main() {
	setlocale(LC_ALL, "Portuguese");		//define a linguagem como "Português"

	//declaração de variáveis:
	bool exit = false;				//variável para testar se a saída do programa foi requisitada
	int pilha[TAM_MAX], fila[TAM_MAX];		//declaração da pilha e da fila
	unsigned short tam_Pilha = 0, tam_Fila = 0;	//armazenam, respectivamente, o tamanho da pilha e da fila

	system("CLS");
	
	capa();		//exibir capa do programa
	
	system("pause");

	//loop
	do {
		system("CLS");

		//switch case que testa a opção escolhida pelo usuário
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
				//se o usuário confirmar a saída, exit = true
				if (confirmar("Você deseja encerrar o programa? (S/N)")) exit = true;
				break;
		}
		//se exit == true, imprime na tela mensagem confirmando saída do programa
		if (exit) {
			system("CLS");
			puts("Encerrando o programa...\n");
		}
		system("pause");
	} while(!exit);		//executa o loop enquanto exit == false

	system("CLS");
	return 0;
}
