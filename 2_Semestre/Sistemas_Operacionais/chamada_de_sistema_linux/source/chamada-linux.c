#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

int main () {
    char caminho_original[200], caminho_novo[200];

    printf("Digite o caminho original do arquivo (+ seu nome): ");
    fgets(caminho_original, 200, stdin);
    printf("Digite o novo caminho do arquivo (+ seu nome): ");
    fgets(caminho_novo, 200, stdin);

    caminho_original[strlen(caminho_original)-1] = 0;
    caminho_novo[strlen(caminho_novo)-1] = 0;

    if (rename(caminho_original, caminho_novo) != 0) {
        puts("Erro! Não foi possível mover o arquivo!");
        return 1;
    }

    puts("Arquivos movidos com sucesso!");
    return 0;
}
