#include <stdio.h>

int main() {
    int numeros[15];
    int i, numero, posicao;

    // Cadastro sem permitir repetições
    printf("Digite 15 números (não permitindo repetições):\n");
    for (i = 0; i < 15; i++) {
        do {
            printf("Número %d: ", i + 1);
            scanf("%d", &numero);

            if (verificaRepeticao(numeros, i, numero)) {
                printf("Número já cadastrado. Tente novamente.\n");
            } else {
                numeros[i] = numero;
                break;
            }
        } while (1);
    }
    ordenaVetor(numeros, 15);
    printf("\nNúmeros ordenados: ");
    for (i = 0; i < 15; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\nDigite um número para verificar sua posição no vetor: ");
    scanf("%d", &numero);
    posicao = buscaSequencial(numeros, 15, numero);

    if (posicao != -1) {
        printf("Número encontrado na posição %d (índice %d) usando busca sequencial.\n", posicao + 1, posicao);

        // Verifica se está em posição par ou ímpar
        if ((posicao + 1) % 2 == 0) {
            printf("Está em uma posição par.\n");
        } else {
            printf("Está em uma posição ímpar.\n");
        }
    } else {
        printf("Número não encontrado usando busca sequencial.\n");
    }

    // Busca binária
    posicao = buscaBinaria(numeros, 0, 14, numero);

    if (posicao != -1) {
        printf("Número encontrado na posição %d (índice %d) usando busca binária.\n", posicao + 1, posicao);

        // Verifica se está em posição par ou ímpar
        if ((posicao + 1) % 2 == 0) {
            printf("Está em uma posição par.\n");
        } else {
            printf("Está em uma posição ímpar.\n");
        }
    } else {
        printf("Número não encontrado usando busca binária.\n");
    }

    return 0;
}
int verificaRepeticao(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return 1; 
        }
    }
    return 0; 
}

//  ordenar usando bubble sort
void ordenaVetor(int vetor[], int tamanho) {
    int i, j, temp;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// busca sequencial
int buscaSequencial(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return i;
        }
    }
    return -1; // se o numero nao for encontrado
}

//busca binaria
int buscaBinaria(int vetor[], int inicio, int fim, int numero) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == numero) {
            return meio;
        }

        if (vetor[meio] < numero) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // se o numeri não encontrado
}