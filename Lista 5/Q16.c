/*
    Elabore uma função para verificar se um número é um quadrado perfeito. Um 
    quadrado perfeito é um número inteiro não negativo que pode ser expresso como 
    o quadrado de outro número inteiro. Exemplos: 1, 4, 9. 
*/

#include <stdio.h>
#include <math.h>

void isqrt(int x) {

    if (x < 0) {
        printf("Nao e um quadrado perfeito!\n");
        return;
    }

    double raiz = sqrt(x);
    int raiz_i  = (int)raiz;

    if(raiz_i * raiz_i == x) {
        printf("Quadrado perfeito!");
    } else {
        printf("Quadrado nao perfeito!");
    }
}

int main() {

    int t;

    printf("Insira um numero: ");
    scanf("%d", &t);

    isqrt(t);
}