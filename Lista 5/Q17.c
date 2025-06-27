/* 
    Elabore uma função que receba três notas de um aluno como parâmetros e uma 
    letra. Se a letra for “A”, a função deverá calcular a média aritmética das notas do 
    aluno; se for “P”, deverá calcular a média ponderada, com pesos 5, 3 e 2. Retorne a 
    média calculada para o programa principal. 
*/


#include <stdio.h>

// Função para calcular a média
float calcularMedia(float n1, float n2, float n3, char tipo) {
    if (tipo == 'A' || tipo == 'a') {
        return (n1 + n2 + n3) / 3;
    } else if (tipo == 'P' || tipo == 'p') {
        return (n1 * 5 + n2 * 3 + n3 * 2) / 10;
    } else {
        // Tipo inválido
        printf("Tipo de média inválido!\n");
        return -1;  // Valor de erro
    }
}

int main() {
    float nota1, nota2, nota3, media;
    char tipo;

    // Entrada das notas
    printf("Digite as três notas do aluno: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    // Escolha do tipo de média
    printf("Digite 'A' para média aritmética ou 'P' para média ponderada: ");
    scanf(" %c", &tipo);  // Espaço antes do %c é importante para ignorar o Enter

    // Chamada da função
    media = calcularMedia(nota1, nota2, nota3, tipo);

    if (media != -1) {
        printf("Média calculada: %.2f\n", media);
    }

    return 0;
}
