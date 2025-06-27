/*
    Faça um programa que preencha um vetor com 10 números reais. Em seguida, 
    calcule e mostre na tela a quantidade de números negativos e a soma dos números 
    positivos desse vetor. 
*/

#include <stdio.h>

int main() {

    float vetor[10];
    int negativos = 0;
    float positivos = 0.0;

    for (int i = 0; i < 3; i++) {
        printf("%d: ", i + 1);
        scanf("%f", &vetor[i]);

        if(vetor[i] < 0) {
            negativos++;
        } else {
            positivos += vetor[i];
        }
    }

    
    printf("\nSoma dos numeros positivos: %.1f\n", positivos);
    printf("Quantidade de numeros negativos: %d\n", negativos);
}