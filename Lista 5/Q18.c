/*
    Faça uma função que receba, por parâmetro, uma matriz A contendo seis linhas e 
    seis colunas. Essa função deve retornar, por referência, a soma dos elementos da 
    sua diagonal principal e da sua diagonal secundária.
*/

#include <stdio.h>

// Função que calcula as somas das diagonais
void somarDiagonais(int A[6][6], int *somaPrincipal, int *somaSecundaria) {
    *somaPrincipal = 0;
    *somaSecundaria = 0;

    for (int i = 0; i < 6; i++) {
        *somaPrincipal += A[i][i];           // Diagonal principal: linha == coluna
        *somaSecundaria += A[i][5 - i];      // Diagonal secundária: coluna = 5 - linha
    }
}

int main() {
    int A[6][6];
    int somaP, somaS;

    // Leitura da matriz
    printf("Digite os elementos da matriz 6x6:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Chamada da função
    somarDiagonais(A, &somaP, &somaS);

    // Exibição dos resultados
    printf("Soma da diagonal principal: %d\n", somaP);
    printf("Soma da diagonal secundária: %d\n", somaS);

    return 0;
}
