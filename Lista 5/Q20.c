/*
    Elabore uma função que receba por parâmetros os coeficientes de uma equação do 
    segundo grau. Em seguida, calcule e mostre as raízes dessa equação.  
    Lembre-se de que as raízes são calculadas com a formula de Bhaskara: 
    em que ∆ = b2 – 4 * a*c e ax2 +bx+c= 0 representa uma equação do segundo grau. A 
    variável a tem de ser diferente de zero. Caso seja igual, imprima a mensagem “Não 
    é equação de segundo grau” e retorne o valor −1.  
    Do contrário, retorne o número de raízes e as raízes (por referência) se elas 
    existirem: 
    
    a Se ∆ < 0, não existe real. Número de raízes: 0. 
    b Se ∆ = 0, existe uma raiz real. Número de raízes: 1. 
    c Se ∆ > 0, existem duas raízes reais. Número de raízes: 2
*/

#include <stdio.h>
#include <math.h>

// Função que calcula as raízes da equação de segundo grau
int calcularRaizes(float a, float b, float c, float *raiz1, float *raiz2) {
    if (a == 0) {
        printf("Não é equação de segundo grau.\n");
        return -1;
    }

    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        return 0;  // Nenhuma raiz real
    } else if (delta == 0) {
        *raiz1 = -b / (2 * a);
        return 1;  // Uma raiz real
    } else {
        *raiz1 = (-b + sqrt(delta)) / (2 * a);
        *raiz2 = (-b - sqrt(delta)) / (2 * a);
        return 2;  // Duas raízes reais
    }
}

int main() {
    float a, b, c, r1, r2;
    int numRaizes;

    // Leitura dos coeficientes
    printf("Digite os coeficientes a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    // Chamada da função
    numRaizes = calcularRaizes(a, b, c, &r1, &r2);

    // Exibição dos resultados
    if (numRaizes == -1) {
        // Mensagem já foi exibida na função
    } else if (numRaizes == 0) {
        printf("Não existem raízes reais.\n");
    } else if (numRaizes == 1) {
        printf("Existe uma raiz real: %.2f\n", r1);
    } else {
        printf("Existem duas raízes reais: %.2f e %.2f\n", r1, r2);
    }

    return 0;
}