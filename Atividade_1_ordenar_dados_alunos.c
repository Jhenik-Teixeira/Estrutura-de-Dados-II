#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    float nota1;
    float nota2;
    float media;
};
int main() {
    struct Aluno alunos[8];
    struct Aluno temp;
    int i, j;
    printf("Digite os dados dos alunos:\n");
    for (i = 0; i < 8; i++) {
        printf("---------------Aluno %d:------------\n", i + 1);
        printf("digite o nome aluno: ");
        scanf("%s", alunos[i].nome);
        printf("digite a nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("digite a nota 2: ");
        scanf("%f", &alunos[i].nota2);
        alunos[i].media = (2 * alunos[i].nota1 + 3 * alunos[i].nota2) / 5;
    }
    printf("-------------------------------\n");
    // Ordenação dos alunos pela média ponderada
    for (i = 0; i < 8 - 1; i++) {
        for (j = 0; j < 8 - i - 1; j++) {
            if (alunos[j].media < alunos[j + 1].media) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    printf("------------------------------------------\n");
    printf("\nAlunos ordenados pela média ponderada:\n");
    for (i = 0; i < 8; i++) {
        printf("%s - Média: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    // Ordenação nota 1 (crescente)
    for (i = 0; i < 8 - 1; i++) {
        for (j = 0; j < 8 - i - 1; j++) {
            if (alunos[j].nota1 > alunos[j + 1].nota1) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
     printf("------------------------------------------\n");
    printf("\nAlunos ordenados por nota 1 (crescente):\n");
    for (i = 0; i < 8; i++) {
        printf("%s - Nota 1: %.2f\n", alunos[i].nome, alunos[i].nota1);
    }

    // reprovados em ordem alfabética
    printf("\nAlunos reprovados em ordem alfabética:\n");
    for (i = 0; i < 8; i++) {
        if (alunos[i].media < 7) {
            printf("%s - Média: %.2f\n", alunos[i].nome, alunos[i].media);
        }
    }

    return 0;
}

