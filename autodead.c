#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FUNCAO_ALVO "void funcao_autodestrutiva()"

void funcao_autodestrutiva() {
    printf("Esta função se autodestruirá após a execução.\n");

    
    const char *nome_arquivo = "autodead.c";

    
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    
    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char *conteudo = malloc(tamanho_arquivo + 1);
    if (!conteudo) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    fread(conteudo, 1, tamanho_arquivo, arquivo);
    conteudo[tamanho_arquivo] = '\0'; //terminador nulo
    fclose(arquivo);

    //linha onde a função está definida
    char *inicio_funcao = strstr(conteudo, FUNCAO_ALVO);
    if (!inicio_funcao) {
        printf("Função não encontrada no arquivo.\n");
        free(conteudo);
        exit(EXIT_FAILURE);
    }

    char *fim_funcao = strstr(inicio_funcao, "}\n");
    if (!fim_funcao) {
        printf("Fim da função não encontrado.\n");
        free(conteudo);
        exit(EXIT_FAILURE);
    }
    fim_funcao += 2; //caractere '}' e a nova linha

    // excluindo
    size_t novo_tamanho = strlen(conteudo) - (fim_funcao - inicio_funcao);
    memmove(inicio_funcao, fim_funcao, strlen(fim_funcao) + 1);

    // novo conteudo 
    arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para escrita");
        free(conteudo);
        exit(EXIT_FAILURE);
    }

    fwrite(conteudo, 1, novo_tamanho, arquivo);
    fclose(arquivo);

    free(conteudo);
}

int main() {
    // Chama a função
    funcao_autodestrutiva();

    return 0;
}
