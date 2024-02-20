#include<stdio.h>
#include<math.h>
#include <stdlib.h>

struct Funcionario {
    char nome[50];
    float salario;
};

int main(){
    struct Funcionario funcionarios[5];

     for (int i = 0; i < 5; i++) {
        printf("Digite o nome do funcionário %d: ", i + 1);
        scanf("%s", funcionarios[i].nome);
        printf("Digite o salário do funcionário %d: ", i + 1);
        scanf("%f", &funcionarios[i].salario);
    }
    // ordena por salário crescente usando Bubble Sort
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (funcionarios[j].salario > funcionarios[j + 1].salario) {
                struct Funcionario temp = funcionarios[j];
                funcionarios[j] = funcionarios[j + 1];
                funcionarios[j + 1] = temp;
            }
        }
    }
    printf("\n");
    printf("Funcionários em ordem crescente de salário:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %-20s Salário: %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
    }
    printf("\n");
    // ordena por salario decrescente usando o selection sort
    for (int i = 0; i < 5 - 1; i++) {
        int indiceMax = i;
        for (int j = i + 1; j < 5; j++) {
            if (funcionarios[j].salario > funcionarios[indiceMax].salario) {
                indiceMax = j;
            }
        }
        struct Funcionario temp = funcionarios[i];
        funcionarios[i] = funcionarios[indiceMax];
        funcionarios[indiceMax] = temp;
    }
    printf("\n");
    printf("Funcionários em ordem decrescente de salário:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %-20s Salário: %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
    }
    printf("\n");

    // ordena por nome
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (strcmp(funcionarios[j].nome, funcionarios[j + 1].nome) > 0) {
                struct Funcionario temp = funcionarios[j];
                funcionarios[j] = funcionarios[j + 1];
                funcionarios[j + 1] = temp;
            }
        }
    }
    printf("\n");
    printf("Funcionários em ordem alfabética:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %-20s Salário: %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
    }
}