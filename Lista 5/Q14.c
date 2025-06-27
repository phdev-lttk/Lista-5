/*
    Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do 
    atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados 
    de cinco atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define atletas 5


struct Atleta {
    char nome[100];
    char esporte[50];
    int idade;
    float altura;
};

int main() {

    struct Atleta a[atletas];

    char older[100];
    char taller[100];

    for (int i = 0; i < atletas; i++) {
        printf("Atleta %d\n", i + 1);

        printf("Nome: ");
        fgets(a[i].nome, sizeof(a[i].nome), stdin);
        a[i].nome[strcspn(a[i].nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &a[i].idade);
        getchar();

        printf("Esporte: ");
        fgets(a[i].esporte, sizeof(a[i].esporte), stdin);
        a[i].esporte[strcspn(a[i].esporte, "\n")] = '\0';

        printf("Altura: ");
        scanf("%f", &a[i].altura);
        getchar();
    }

    int maisVelho = a[0].idade;
    float maisAlto  = a[0].altura;

    strcpy(older, a[0].nome);
    strcpy(taller, a[0].nome);

    for (int j = 0; j < atletas; j++) {

        if (a[j].idade > maisVelho) {
            maisVelho = a[j].idade;
            strcpy(older, a[j].nome);
        }

        if(a[j].altura > maisAlto) {
            maisAlto = a[j].altura;
            strcpy(taller, a[j].nome);
        }
    }

    printf("\nMais velho: %s, %d", older, maisVelho);
    printf("\nMais alto: %s, %.2f\n", taller, maisAlto);

}