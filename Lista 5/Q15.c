/*
    Crie uma enumeração representando os meses do ano. Agora, escreva um 
    programa que leia um valor inteiro do teclado e exiba o nome do mês 
    correspondente e quantos dias ele possui.
*/

#include <stdio.h>
#include <string.h>

typedef enum {
    JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO,
    JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO
} Mes;

int main() {

    const char *nomesMeses[] = {
        "", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    int diasMeses[] = {
        0, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    int mes;

    printf("Insira o numero de um mes (1 a 12): ");
    scanf("%d", &mes);

    if(mes >= JANEIRO && mes <= DEZEMBRO){
        printf("%s - %d dias \n", nomesMeses[mes], diasMeses[mes]);
    } else {
        printf("Mes invalido!");
    }
}