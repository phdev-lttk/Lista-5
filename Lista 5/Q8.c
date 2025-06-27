/*
    Leia uma string do teclado e conte quantas vogais (a, e, i, o, u) ela possui. Entre com 
    um caractere (vogal ou consoante) e substitua todas as vogais da palavra dada por 
    esse caractere. Ao final, imprima a nova string e o número de vogais que ela possui.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char str[100];
    char caractere;
    int vogais = 0;

    printf("Digite uma palavra: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Vogal ou Consante para substituir: ");
    scanf("%c", &caractere);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            str[i] = caractere;
            vogais++;
        }
    }

    printf("\nNova string: %s\n", str);
    printf("Numero de vogais substituidas: %d\n", vogais);
}