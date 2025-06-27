#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define o número máximo de receitas que podem ser armazenadas
#define MAX_RECEITAS 50

// Enumeração para as categorias de receitas
typedef enum {
    ENTRADA = 1,
    PRATO_PRINCIPAL,
    SOBREMESA,
    BEBIDA,
    LANCHE,
    OUTRO
} CategoriaReceita;

// Estrutura que representa uma receita
typedef struct {
    char nome[100];
    char ingredientes[500];
    char instrucoes[1000];
    int tempo_preparo_minutos;
    CategoriaReceita categoria;
} Receita;

// Protótipos das funções do programa
void exibirMenu();
void adicionarReceita(Receita receitas[], int *contador);
void listarNomesReceitas(Receita receitas[], int contador);
void verDetalhesReceita(Receita receitas[], int contador);
CategoriaReceita lerCategoria();
void limparBuffer();
const char* obterNomeCategoria(CategoriaReceita cat);

int main() {
    Receita receitas[MAX_RECEITAS];  // Vetor para armazenar receitas
    int contador = 0;                // Contador de receitas armazenadas
    int opcao;

    // Loop principal do menu
    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor, insira um numero valido.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                adicionarReceita(receitas, &contador);
                break;
            case 2:
                listarNomesReceitas(receitas, contador);
                break;
            case 3:
                verDetalhesReceita(receitas, contador);
                break;
            case 4:
                printf("Saindo do programa. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Exibe o menu principal do programa
void exibirMenu() {
    printf("\n-------- LIVRO DE RECEITAS DIGITAL --------\n");
    printf("1. Adicionar nova receita\n");
    printf("2. Listar nomes das receitas\n");
    printf("3. Ver detalhes de uma receita\n");
    printf("4. Sair\n");
    printf("-----------------------------------------------\n");
    printf("Desenvolvido por: Pablo Henrique\n");
}

// Limpa o buffer de entrada para evitar leitura de caracteres indesejados
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Lê a categoria digitada pelo usuário e retorna como enumeração
CategoriaReceita lerCategoria() {
    int opcao;
    printf("Categorias:\n");
    printf("1. Entrada\n2. Prato Principal\n3. Sobremesa\n4. Bebida\n5. Lanche\n6. Outro\n");
    printf("Escolha a categoria (1-6): ");
    while (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 6) {
        printf("Categoria invalida. Tente novamente: ");
        limparBuffer();
    }
    limparBuffer();
    return (CategoriaReceita)opcao;
}

// Adiciona uma nova receita ao vetor de receitas
void adicionarReceita(Receita receitas[], int *contador) {
    if (*contador >= MAX_RECEITAS) {
        printf("Livro de receitas cheio! Não é possível adicionar mais.\n");
        return;
    }

    Receita nova;

    // Lê o nome da receita
    printf("Digite o nome da receita: ");
    fgets(nova.nome, sizeof(nova.nome), stdin);
    nova.nome[strcspn(nova.nome, "\n")] = '\0'; // Remove o '\n'

    // Lê os ingredientes
    printf("Digite os ingredientes: ");
    fgets(nova.ingredientes, sizeof(nova.ingredientes), stdin);
    nova.ingredientes[strcspn(nova.ingredientes, "\n")] = '\0';

    // Lê as instruções
    printf("Digite as instruções: ");
    fgets(nova.instrucoes, sizeof(nova.instrucoes), stdin);
    nova.instrucoes[strcspn(nova.instrucoes, "\n")] = '\0';

    // Lê o tempo de preparo
    printf("Digite o tempo de preparo (em minutos): ");
    while (scanf("%d", &nova.tempo_preparo_minutos) != 1 || nova.tempo_preparo_minutos <= 0) {
        printf("Tempo inválido. Tente novamente: ");
        limparBuffer();
    }
    limparBuffer();

    // Lê a categoria da receita
    nova.categoria = lerCategoria();

    // Armazena a nova receita no vetor
    receitas[*contador] = nova;
    (*contador)++;  // Atualiza contador
    printf("Receita adicionada com sucesso!\n");
}

// Lista os nomes de todas as receitas cadastradas
void listarNomesReceitas(Receita receitas[], int contador) {
    if (contador == 0) {
        printf("Nenhuma receita cadastrada.\n");
        return;
    }

    printf("\n--- LISTA DE RECEITAS ---\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. %s\n", i + 1, receitas[i].nome);
    }
}

// Permite visualizar os detalhes de uma receita por número ou nome
void verDetalhesReceita(Receita receitas[], int contador) {
    if (contador == 0) {
        printf("Nenhuma receita disponível.\n");
        return;
    }

    int opcao;
    char busca[100];

    printf("Deseja buscar por:\n1. Número\n2. Nome\nEscolha: ");
    scanf("%d", &opcao);
    limparBuffer();

    if (opcao == 1) {
        int indice;
        printf("Digite o numero da receita: ");
        scanf("%d", &indice);
        limparBuffer();

        // Verifica se o número está dentro do intervalo válido
        if (indice < 1 || indice > contador) {
            printf("Numero inválido.\n");
            return;
        }

        Receita r = receitas[indice - 1];

        // Exibe todos os detalhes da receita
        printf("\n--- DETALHES DA RECEITA ---\n");
        printf("Nome: %s\n", r.nome);
        printf("Ingredientes: %s\n", r.ingredientes);
        printf("Instruções: %s\n", r.instrucoes);
        printf("Tempo de preparo: %d minutos\n", r.tempo_preparo_minutos);
        printf("Categoria: %s\n", obterNomeCategoria(r.categoria));

    } else if (opcao == 2) {
        printf("Digite o nome da receita: ");
        fgets(busca, sizeof(busca), stdin);
        busca[strcspn(busca, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < contador; i++) {
            if (strcmp(receitas[i].nome, busca) == 0) {
                Receita r = receitas[i];
                printf("\n--- DETALHES DA RECEITA ---\n");
                printf("Nome: %s\n", r.nome);
                printf("Ingredientes: %s\n", r.ingredientes);
                printf("Instrucoes: %s\n", r.instrucoes);
                printf("Tempo de preparo: %d minutos\n", r.tempo_preparo_minutos);
                printf("Categoria: %s\n", obterNomeCategoria(r.categoria));
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Receita nao encontrada.\n");
        }
    } else {
        printf("Opcao invalida.\n");
    }
}

// Converte o valor da enumeração CategoriaReceita em uma string legível
const char* obterNomeCategoria(CategoriaReceita cat) {
    switch (cat) {
        case ENTRADA: return "Entrada";
        case PRATO_PRINCIPAL: return "Prato Principal";
        case SOBREMESA: return "Sobremesa";
        case BEBIDA: return "Bebida";
        case LANCHE: return "Lanche";
        case OUTRO: return "Outro";
        default: return "Desconhecida";
    }
}
