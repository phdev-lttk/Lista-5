/*
    Faça um programa que leia um vetor de oito posições. Em seguida, leia também dois 
    valores X e Y quaisquer correspondentes a duas posições no vetor. Seu programa 
    deverá exibir a soma dos valores encontrados nas respectivas posições X e Y. 
*/

#include <stdio.h>

int main() {

    int vetor[9];
    int x, y, i;

    printf("Digite 8 valores inteiros para o vetor:\n");

    for (i = 1; i <= 8; i++) {
        printf("Posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite a posicao X (1 a 8): ");
    scanf("%d", &x);
    printf("Digite a posicao Y (1 a 8): ");
    scanf("%d", &y);

    if (x <= 0 || x > 8 || y <= 0 || y > 8) {
        printf("ERRO!");
    } else {
        printf("\n");
        printf("Soma: %d", vetor[x] + vetor[y]);
    }

}