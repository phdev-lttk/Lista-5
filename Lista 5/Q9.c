/*
    Faça um programa que leia uma string e imprima uma mensagem dizendo se ela é 
    um palíndromo ou não. Um palíndromo é uma palavra que tem a propriedade de 
    poder ser lida tanto da direita para a esquerda como da esquerda para a direita.  
    Exemplos: ovo, arara, rever, asa, osso etc. 
*/

#include <stdio.h>
#include <string.h>

int main() {
    
    char str[100];
    int size;
    int i, j;
    int palindromo = 0;

    printf("Insira a palavra para verificar se e palindromo: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    size = strlen(str);

    for (i = 0, j = size; i <= size; i++, j--) {
        if (str[i] == str[j]) {
            palindromo = 1;
            break;
        }
    }

    if (palindromo == 1) {
        printf("Nao e palindromo!");
    } else {
        printf("E palindromo!");
    }
}