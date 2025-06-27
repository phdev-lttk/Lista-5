#include <stdio.h>

int main() {
    
    int opcao;

    do {
        // Menu
        printf("\n==== MENU ====\n");
        printf("1. Dizer Oi\n");
        printf("2. Dizer Tchau\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Tratamento com switch-case
        switch (opcao) {
            case 1:
                printf("Oi!\n");
                break;
            case 2:
                printf("Tchau!\n");
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 3);  // Continua até o usuário digitar 3

    return 0;
}
