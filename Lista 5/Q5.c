/*
    Faça um programa que receba do usuário dois arrays, A e B, com 10 números 
    inteiros cada. Crie um novo array C calculando C = A – B. Mostre na tela os dados do 
    array C.
*/

#include <stdio.h>

int main() {
    
    int vetorA[10], vetorB[10], vetorC[10];

    printf("Digite os 10 valores do vetor A\n");

    for (int i = 1; i <= 10; i++) {
        printf("%d: ", i);
        scanf("%d", &vetorA[i]);
    }

    printf("Digite os 10 valores do vetor B\n");

    for (int j = 1; j <= 10; j++) {
        printf("%d: ", j);
        scanf("%d", &vetorB[j]);
    }


    for (int l = 1; l <= 10; l++) {
        vetorC[l] = vetorA[l] + vetorB[l];
    }

    printf("\nVetor C (A - B):\n");

    for(int y = 1; y <= 3; y++) {
        printf("C[%d] = %d\n", y, vetorC[y]);
    }



    return 0;
}