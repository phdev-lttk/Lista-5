/*
    Faça um programa que receba do usuário um vetor X com 10 posições. Em seguida 
    deverão ser impressos o maior e o menor elemento desse vetor. 
*/

#include <stdio.h>

int main() {

    int vetor[10];

    printf("Digite 10 valores inteiros para o vetor:\n");

    for (int i = 0; i < 10; i++) {
        printf("Posicao %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int maior = vetor[0];
    int menor = vetor[0];

    for (int j = 0; j < 10; j++) {
        if (vetor[j] > maior)
            maior = vetor[j];
        if (vetor[j] < menor)
            menor = vetor[j];
    }

    printf("\nMenor elemento: %d", menor);
    printf("\nMaior elemento: %d\n", maior);
}