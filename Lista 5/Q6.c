/*
    Leia uma matriz de tamanho 3×3. Em seguida, imprima a soma dos valores contidos 
    em sua diagonal principal. 
*/

#include <stdio.h>

int main() {
    
    int matriz[3][3];
    int i, j;
    int soma = 0;

    printf("Insira o valor da matriz (3x3)\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);

            if(i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("\nSoma da diagonal principal: %d\n", soma);
}
