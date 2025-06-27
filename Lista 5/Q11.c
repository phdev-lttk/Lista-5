/*
    Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e 
    armazene esses dados em uma estrutura. Em seguida, imprima na tela os dados da 
    estrutura lida. 
*/

#include <stdio.h>
#include <string.h>

struct Dados {
    char name[100];
    int age;
    char adress[150];
};

int main() {

    struct Dados d;

    printf("Digite o seu nome: ");
    fgets(d.name, sizeof(d.name), stdin);
    d.name[strcspn(d.name, "\n")] = '\0';

    printf("Digite sua idade: ");
    scanf("%d", &d.age);
    getchar();

    printf("Digite o seu endereco: ");
    fgets(d.adress, sizeof(d.adress), stdin);
    d.adress[strcspn(d.adress, "\n")] = '\0';

    printf("\n -------Suas infos------- \n");
    printf("Name: %s\n", d.name);
    printf("Age: %d\n", d.age);
    printf("Adress: %s\n",d.adress);
}