/*
    Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve 
    conter o número de matrícula do aluno, seu nome e as notas de três provas. Agora, 
    escreva um programa que leia os dados de cinco alunos e os armazene nessa 
    estrutura. Em seguida, exiba o nome e as notas do aluno que possui a maior média 
    geral dentre os cinco. 
*/

#include <stdio.h>
#include <string.h>
#define qtd_al 2

struct Aluno {
    int matricula;
    char nome[100];
    float notas[4];
};

int main() {

    struct Aluno a[qtd_al];

    int i, j;
    float media, maiormed = 0.0;
    int indicem = -1;

    for (i = 0; i < qtd_al; i++) {

        printf("Aluno %d \n", i + 1);

        printf("Nome: ");
        fgets(a[i].nome, sizeof(a[i].nome), stdin);
        a[i].nome[strcspn(a[i].nome, "\n")] = '\0';

        printf("Matricula: ");
        scanf("%d", &a[i].matricula);
        getchar();

        for (j = 0; j < 4; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &a[i].notas[j]);
            getchar();
        }

        media = 0;

        for (int l = 0; l < 4; l++) {
            media += a[i].notas[l];
        }

        media /= 4.0;

        if (media > maiormed) {
            maiormed = media;
            indicem = i;
        }
    }

        printf("\n--- Aluno com maior media ---\n");
        printf("Nome: %s\n", a[indicem].nome);
        printf("Notas: %.2f, %.2f, %.2f, %.2f\n",a[indicem].notas[0], a[indicem].notas[1], a[indicem].notas[2], a[indicem].notas[3]);
        printf("Media: %.2f\n", maiormed);

    return 0;

}