#include <stdio.h>
#include <string.h>

#define MAX_CATEGORIAS 10

int main() {
    
    float saldo = 0.0;
    int escolha;
    float despesa;
    char categorias[MAX_CATEGORIAS][50]; // Vetor de categorias de despesas(talvez coloque opções específicas?)
    int numCategorias = 0; // Contador de categorias

    while (1) {
        printf("\nOpcoes:\n");
        printf("1. Registrar despesa\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            if (numCategorias < MAX_CATEGORIAS) {
                printf("Informe o valor da despesa: R$ ");
                scanf("%f", &despesa);
                saldo -= despesa;

                printf("Informe a categoria da despesa: ");
                scanf("%s", categorias[numCategorias]);
                numCategorias++;

                printf("Despesa registrada com sucesso!\n");
            } else {
                printf("Limite de categorias atingido. Não é possível adicionar mais categorias.\n");
            }
        } else if (escolha == 2) {
            printf("Saldo final: R$ %.2f\n", saldo);
            printf("Saindo do programa.\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}