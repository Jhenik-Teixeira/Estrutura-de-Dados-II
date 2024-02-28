#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    srand((unsigned int)time(NULL));


    int tamanho= 100000;
    int vetorOrdenado[tamanho], vetorInvertido[tamanho], vetorAleatorio[tamanho];

    // gerar vetores vetorOrdenado, vetorInvertido e vetorAleatorio
     for (int i = 0; i < tamanho; i++) {
        vetorOrdenado[i] = i + 1;
        vetorInvertido[i] = tamanho - i;
        vetorAleatorio[i] = i + 1;
    }
    // vetor aleatório
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        trocar(&vetorAleatorio[i], &vetorAleatorio[j]);
    }

    // salvar vetores em arquivos para uso posterior
    FILE *arqOrdenado = fopen("vetor_ordenado.txt", "w");
    FILE *arqInvertido = fopen("vetor_invertido.txt", "w");
    FILE *arqAleatorio = fopen("vetor_aleatorio.txt", "w");

    for (int i = 0; i < tamanho; i++) {
        fprintf(arqOrdenado, "%d\n", vetorOrdenado[i]);
        fprintf(arqInvertido, "%d\n", vetorInvertido[i]);
        fprintf(arqAleatorio, "%d\n", vetorAleatorio[i]);
    }

    fclose(arqOrdenado);
    fclose(arqInvertido);
    fclose(arqAleatorio);

    // faz a leitura dos vetores a partir dos arquivos txt
    lerDoArquivo("vetor_ordenado.txt", vetorOrdenado, tamanho);
    lerDoArquivo("vetor_invertido.txt", vetorInvertido, tamanho);
    lerDoArquivo("vetor_aleatorio.txt", vetorAleatorio, tamanho);

    clock_t inicio, fim;
    // testando os valores do bubble sort para cada vetor
    inicio = clock();
    bubbleSort(vetorOrdenado, tamanho);
    fim = clock();
    printf("Bubble Sort para vetor ordenado: %.5f segundos\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);
    inicio = clock();
    bubbleSort(vetorInvertido, tamanho);
    fim = clock();
    printf("Bubble Sort para vetor invertido: %.5f segundos\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    bubbleSort(vetorAleatorio, tamanho);
    fim = clock();
    printf("Bubble Sort para vetor aleatório: %.5f segundos\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    printf("----------------------------------------\n"); 



    // testando os valores do Insertion sort para cada vetor
    long comparacoesInsertionOrd, trocasInsertionOrd;
    long comparacoesInsertionInv, trocasInsertionInv;
    long comparacoesInsertionAleat, trocasInsertionAleat;

    inicio = clock();
    insertionSort(vetorOrdenado, tamanho, &comparacoesInsertionOrd, &trocasInsertionOrd);
    fim = clock();
    printf("Insertion Sort para vetor ordenado: %.5f segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparacoes: %ld, Trocas: %ld\n", comparacoesInsertionOrd, trocasInsertionOrd);

    inicio = clock();
    insertionSort(vetorInvertido, tamanho, &comparacoesInsertionInv, &trocasInsertionInv);
    fim = clock();
    printf("Insertion Sort para vetor invertido: %.5f segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparacoes: %ld, Trocas: %ld\n", comparacoesInsertionInv, trocasInsertionInv);

    inicio = clock();
    insertionSort(vetorAleatorio, tamanho, &comparacoesInsertionAleat, &trocasInsertionAleat);
    fim = clock();
    printf("Insertion Sort para vetor aleatório: %.5f segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparacoes: %ld, Trocas: %ld\n", comparacoesInsertionAleat, trocasInsertionAleat);

    printf("----------------------------------------\n");

    // testando os valores do selection sort para cada vetor
    inicio = clock();
    selectionSort(vetorOrdenado, tamanho);
    fim = clock();
    printf("selection Sort para vetor ordenado: %.5f segundos\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    selectionSort(vetorInvertido, tamanho);
    fim = clock();
    printf("selection Sort  para vetor invertido: %.5f segundos\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    selectionSort(vetorAleatorio, tamanho);
    fim = clock();
    printf("selection Sort para vetor aleatório: %.5f segundos\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC);

    printf("----------------------------------------\n"); 

    // Testando os valores do merge para cada vetor

    long comparacoes_merge_ord = 0, trocas_merge_ord = 0;
    inicio = clock();
    mergeSort(vetorOrdenado, 0, tamanho - 1, &comparacoes_merge_ord, &trocas_merge_ord);
    fim = clock();
    printf("Merge Sort para vetor ordenado: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparações: %ld, Trocas: %ld\n", comparacoes_merge_ord, trocas_merge_ord);

    long comparacoes_merge_inv = 0, trocas_merge_inv = 0;
    inicio = clock();
    mergeSort(vetorInvertido, 0, tamanho - 1, &comparacoes_merge_inv, &trocas_merge_inv);
    fim = clock();
    printf("Merge Sort para vetor invertido: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparações: %ld, Trocas: %ld\n", comparacoes_merge_inv, trocas_merge_inv);

    long comparacoes_merge_aleat = 0, trocas_merge_aleat = 0;
    inicio = clock();
    mergeSort(vetorAleatorio, 0, tamanho - 1, &comparacoes_merge_aleat, &trocas_merge_aleat);
    fim = clock();
    printf("Merge Sort para vetor aleatório: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparações: %ld, Trocas: %ld\n", comparacoes_merge_aleat, trocas_merge_aleat);

    printf("----------------------------------------\n");
    

    // Testando os valores do heap Sort para cada vetor
    inicio = clock();
    heapSort(vetorOrdenado, tamanho);
    fim = clock();
    printf("Heap Sort para vetor ordenado: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    heapSort(vetorInvertido, tamanho);
    fim = clock();
    printf("Heap Sort para vetor invertido: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);

    inicio = clock();
    heapSort(vetorAleatorio, tamanho);
    fim = clock();
    printf("Heap Sort para vetor aleatório: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);

     printf("----------------------------------------\n");

    // Testando os valores do Quick Sort para cada vetor
     long comparacoes_quick_ord = 0, trocas_quick_ord = 0;
    inicio = clock();
    quickSort(vetorOrdenado, 0, tamanho - 1, &comparacoes_quick_ord, &trocas_quick_ord);
    fim = clock();
    printf("Quick Sort para vetor ordenado: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparações: %ld, Trocas: %ld\n", comparacoes_quick_ord, trocas_quick_ord);

    long comparacoes_quick_inv = 0, trocas_quick_inv = 0;
    inicio = clock();
    quickSort(vetorInvertido, 0, tamanho - 1, &comparacoes_quick_inv, &trocas_quick_inv);
    fim = clock();
    printf("Quick Sort para vetor invertido: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparações: %ld, Trocas: %ld\n", comparacoes_quick_inv, trocas_quick_inv);

    long comparacoes_quick_aleat = 0, trocas_quick_aleat = 0;
    inicio = clock();
    quickSort(vetorAleatorio, 0, tamanho - 1, &comparacoes_quick_aleat, &trocas_quick_aleat);
    fim = clock();
    printf("Quick Sort para vetor aleatório: %.5e segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    printf("Comparações: %ld, Trocas: %ld\n", comparacoes_quick_aleat, trocas_quick_aleat);

    printf("----------------------------------------\n");

    return 0;
}


//  Bubble Sort
void bubbleSort(int arr[], int n) {
    long troca_numero= 0;
    long comparacoes= 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            comparacoes+=1;
            if (arr[j] > arr[j+1]){
                trocar(&arr[j], &arr[j+1]);
                troca_numero+=1;
            }
        }  
     }
    printf("Número de comparações: %ld\n", comparacoes);
    printf("Número de trocas: %ld\n", troca_numero);
     printf("----------------------------------------\n");
}

// Insertion Sort
void insertionSort(int arr[], int n, long *comparacoes, long *trocas) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*comparacoes)++;
            (*trocas)++;
        }
        arr[j + 1] = key;

        printf("Passo %d: Trocas = %ld, Comparações = %ld\n", i, *trocas, *comparacoes);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    long troca_numero= 0;
    long comparacoes= 0;
    for (i = 0; i < n-1; i++) {
        comparacoes+=1;
        min_idx = i;
        for (j = i+1; j < n; j++){

            if (arr[j] < arr[min_idx]){
                min_idx = j;
                trocar(&arr[min_idx], &arr[i]);
                troca_numero+=1;
            }
        }
    }
   printf("Número de comparações: %ld\n", comparacoes);
   printf("Número de trocas: %ld\n", troca_numero);
    printf("----------------------------------------\n");
}

// Merge Sort
void merge(int arr[], int l, int m, int r, long *comparacoes, long *trocas) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        (*comparacoes) += 1;  // Contagem da comparação
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*trocas) += 1;  // Contagem da troca
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, long *comparacoes, long *trocas) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparacoes, trocas);
        mergeSort(arr, m + 1, r, comparacoes, trocas);
        merge(arr, l, m, r, comparacoes, trocas);
    }
}

//  Quick Sort
    int particionar(int arr[], int baixo, int alto, long *comparacoes, long *trocas) {
    int pivot = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        (*comparacoes) += 1;  // Contagem da comparação
        if (arr[j] < pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
            (*trocas) += 1;  // Contagem da troca
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    (*trocas) += 1;  // Contagem da troca
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto, long *comparacoes, long *trocas) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto, comparacoes, trocas);
        quickSort(arr, baixo, pi - 1, comparacoes, trocas);
        quickSort(arr, pi + 1, alto, comparacoes, trocas);
    }
}

//  Heap Sort
void heapify(int arr[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        trocar(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// ler o vetor do arquivo .txt
void lerDoArquivo(char *nomeArquivo, int vetor[], int tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanho; i++) {
        if (fscanf(arquivo, "%d", &vetor[i]) != 1) {
            fprintf(stderr, "Erro ao ler do arquivo\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(arquivo);
}
