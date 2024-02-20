#include <stdio.h>
#include <math.h>

int main() {
    int numeros[10];
    int i, j, temp;

    printf("Digite 10 números:\n");
    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // ordenando usando o bubble sort
    for (i = 0; i < 10 - 1; i++) {
        for (j = 0; j < 10 - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
    int menor = numeros[0];
    int contMenor = 1;

    int maior = numeros[9];
    int contMaior = 1;

    for (i = 1; i < 10; i++) {
        if (numeros[i] == menor) {
            contMenor++;
        }
        if (numeros[i] == maior) {
            contMaior++;
        }
    }
    printf("\nNúmeros ordenados: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\nMenor número: %d (aparece %d vezes)\n", menor, contMenor);
    printf("Maior número: %d (aparece %d vezes)\n", maior, contMaior);

    return 0;
}
