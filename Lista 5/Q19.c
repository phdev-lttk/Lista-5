/*
    Elabore uma função que receba um vetor contendo N valores e retorne por 
    referência o maior e o menor elemento desse vetor. 
*/

#include <stdio.h>

// Função para encontrar o maior e o menor valor
void encontrarMaiorMenor(int vetor[], int n, int *maior, int *menor) {
    *maior = vetor[0];
    *menor = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] > *maior) {
            *maior = vetor[i];
        }
        if (vetor[i] < *menor) {
            *menor = vetor[i];
        }
    }
}

int main() {
    int n;

    // Leitura do tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];  // Vetor com tamanho N
    int maior, menor;

    // Leitura dos elementos
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Chamada da função
    encontrarMaiorMenor(vetor, n, &maior, &menor);

    // Exibição dos resultados
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}
