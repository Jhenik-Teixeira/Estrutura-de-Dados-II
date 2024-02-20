#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char descricao[50];
    float preco;
};

// ordena os produtos por código usando o bubble sort
void ordenarProdutos(struct Produto produtos[], int n) {
    int i, j;
    struct Produto temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (produtos[j].codigo > produtos[j + 1].codigo) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

// busca sequencial
int buscaSequencial(struct Produto produtos[], int n, int codigo, int *comparacoes) {
    int i;
    for (i = 0; i < n; i++) {
        (*comparacoes)++;
        if (produtos[i].codigo == codigo) {
            return i; 
        }
    }
    return -1; 
}

// busca binária
int buscaBinaria(struct Produto produtos[], int inicio, int fim, int codigo, int *comparacoes) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        (*comparacoes)++;
        if (produtos[meio].codigo == codigo) {
            return meio;
        }
        else if (produtos[meio].codigo < codigo) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1; 
}

int main() {
    struct Produto produtos[12];
    int i, codigoBusca, posicao;
    int comparacoesSequencial = 0, comparacoesBinaria = 0;

    printf("Cadastro de produtos:\n");
    for (i = 0; i < 12; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &produtos[i].codigo);
        printf("Descrição: ");
        scanf(" %[^\n]s", produtos[i].descricao);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
    }
    ordenarProdutos(produtos, 12);
    printf("\nDigite o código para busca sequencial: ");
    scanf("%d", &codigoBusca);
    
    posicao = buscaSequencial(produtos, 12, codigoBusca, &comparacoesSequencial);
    if (posicao != -1) {
        printf("Produto encontrado na posição %d.\n", posicao);
    } else {
        printf("Produto não encontrado.\n");
    }
    printf("Número de comparações na busca sequencial: %d\n", comparacoesSequencial);

    // Busca binária
    printf("\nDigite o código para busca binária: ");
    scanf("%d", &codigoBusca);
    posicao = buscaBinaria(produtos, 0, 11, codigoBusca, &comparacoesBinaria);
    if (posicao != -1) {
        printf("Produto encontrado na posição %d.\n", posicao);
    } else {
        printf("Produto não encontrado.\n");
    }
    printf("Número de comparações na busca binária: %d\n", comparacoesBinaria);

    return 0;
}
