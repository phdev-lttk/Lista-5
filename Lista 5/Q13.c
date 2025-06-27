/*
    Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma 
    pessoa. Agora, escreva um programa que leia os dados de seis pessoas. Calcule e 
    exiba os nomes da pessoa mais nova e da mais velha. 
*/

#include <stdio.h>
#include <string.h>

#define personas 6

struct Pessoas {
    char nome[100];
    int dia;
    int mes;
    int ano;
};

int mais_velho(struct Pessoas a, struct Pessoas b) {
    if (a.ano < b.ano) return 1;
    if (a.ano == b.ano && a.mes < b.mes) return 1;
    if (a.ano == b.ano && a.mes == b.mes && a.dia < b.dia) return 1;
    return 0;
}

int mais_novo(struct Pessoas a, struct Pessoas b) {
    if (a.ano > b.ano) return 1;
    if (a.ano == b.ano && a.mes > b.mes) return 1;
    if (a.ano == b.ano && a.mes == b.mes && a.dia > b.dia) return 1;
    return 0;
}

int main() {
    struct Pessoas p[personas];
    int i;

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
    }

    struct Pessoas maisVelho = p[0];
    struct Pessoas maisNovo = p[0];

    for (i = 1; i < personas; i++) {
        if (mais_velho(p[i], maisVelho)) {
            maisVelho = p[i];
        }
        if (mais_novo(p[i], maisNovo)) {
            maisNovo = p[i];
        }
    }

    printf("\nPessoa mais velha: %s (%02d/%02d/%04d)", maisVelho.nome, maisVelho.dia, maisVelho.mes, maisVelho.ano);
    printf("\nPessoa mais nova: %s (%02d/%02d/%04d)\n", maisNovo.nome, maisNovo.dia, maisNovo.mes, maisNovo.ano);

    return 0;
}
