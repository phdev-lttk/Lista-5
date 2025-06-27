/*
    Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma 
    pessoa. Agora, escreva um programa que leia os dados de seis pessoas. Calcule e 
    exiba os nomes da pessoa mais nova e da mais velha. 
*/

#include <stdio.h>
#include <string.h>
#define personas 2

struct Pessoas {
    char nome[100];
    int dia;
    int mes;
    int ano;
    int idadeA;
};

int main() {

    int i, j;
    char older[100];
    char newer[100];

    struct Pessoas p[personas];

    for (i = 0; i < personas; i++) {

        printf("Nome %d: ", i + 1);
        fgets(p[i].nome, sizeof(p[i].nome), stdin);
        p[i].nome[strcspn(p[i].nome, "\n")] = '\0';

        printf("Insira o dia do seu aniversario: ");
        scanf("%d", &p[i].dia);
        getchar();
        printf("Insira o mes do seu aniversario: ");
        scanf("%d", &p[i].mes);
        getchar();
        printf("Insira o ano do seu aniversario: ");
        scanf("%d", &p[i].ano);
        getchar();

        p[i].idadeA = 2025 - p[i].ano;
    }

        int maior = p[0].idadeA;
        int menor = p[0].idadeA;

        strcpy(older, p[0].nome);
        strcpy(newer, p[0].nome);


        for (j = 1; j < personas; j++) {
            if(p[j].idadeA > maior) {
               maior = p[j].idadeA;
               strcpy(older, p[j].nome);
            } else if (p[j].idadeA < menor) {
                menor = p[j].idadeA;
                strcpy(newer, p[j].nome);
            }
        }

    printf("\nMenor elemento: %s, %d", newer, menor);
    printf("\nMaior elemento: %s, %d\n", older, maior);

}