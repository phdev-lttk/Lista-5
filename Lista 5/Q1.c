/*
    Faça um programa que leia cinco valores e os armazene em um vetor. Em seguida, 
    mostre todos os valores lidos juntamente com a média dos valores.
*/

#include <stdio.h>

int main() {

    int vetor[5];
    int i, j, l;
    int soma = 0;

    for (i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    } 

    printf("\n");


    for (j = 0; j < 5; j++) {
        printf("Valor %d lido: %d \n", j + 1,  vetor[j]);
    }

    printf("\n");

    for (l = 0; l < 5; l++) {
        printf("%d ", vetor[l]);
    }

    printf("\nMedia dos valores: %d", soma / 5);
}