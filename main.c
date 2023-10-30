#include <stdio.h>
#include <string.h>

#define MAX_DESPESAS 100
#define MAX_RECEITAS 100
#define MAX_CATEGORIAS 10

struct Despesa {
    float valor;  // Armazena o valor da despesa
    char data[11];  // Armazena a data da despesa no formato DD/MM/AAAA
    char categoria[50];  // Armazena a categoria associada à despesa
    char nota[200];  // Armazena uma nota adicional (opcional) para a despesa
};

struct Receita {
    float valor;  // Armazena o valor da receita
    char data[11];  // Armazena a data da receita no formato DD/MM/AAAA
    char fonte[50];  // Armazena a fonte da receita (por exemplo, salário, investimento, etc.)
};

struct Categoria {
    char nome[50];  // Armazena o nome de uma categoria
};

// Função para calcular o saldo total
float calcularSaldo(struct Despesa despesas[], int numDespesas, struct Receita receitas[], int numReceitas) {
    float totalDespesas = 0;  // Inicializa o total de despesas como zero
    float totalReceitas = 0;  // Inicializa o total de receitas como zero

    // Calcula o total das despesas somando os valores de todas as despesas registradas
    for (int i = 0; i < numDespesas; i++) {
        totalDespesas += despesas[i].valor;
    }

    // Calcula o total das receitas somando os valores de todas as receitas registradas
    for (int i = 0; i < numReceitas; i++) {
        totalReceitas += receitas[i].valor;
    }

    // Retorna o saldo total, que é a diferença entre as receitas e despesas
    return totalReceitas - totalDespesas;
}

int main() {
    struct Despesa despesas[MAX_DESPESAS];  // Um array de estruturas para armazenar despesas
    struct Receita receitas[MAX_RECEITAS];  // Um array de estruturas para armazenar receitas
    struct Categoria categorias[MAX_CATEGORIAS];  // Um array de estruturas para armazenar categorias
    int numDespesas = 0;  // Variável para controlar o número de despesas registradas
    int numReceitas = 0;  // Variável para controlar o número de receitas registradas
    int numCategorias = 0;  // Variável para controlar o número de categorias registradas

    // Categorias padrão pré-definidas
    // A função strcpy é usada para copiar os nomes das categorias para os elementos do array, pode adicionar ou tirar categorias até o final do programa
    strcpy(categorias[numCategorias++].nome, "Alimentacao");
    strcpy(categorias[numCategorias++].nome, "Moradia");
    strcpy(categorias[numCategorias++].nome, "Transporte");
    strcpy(categorias[numCategorias++].nome, "Lazer");
    strcpy(categorias[numCategorias++].nome, "Saude");

    while (1) {
        //Menu de opções
        printf("\nOpcoes:\n");
        printf("1. Registrar despesa\n");
        printf("2. Registrar receita\n");
        printf("3. Exibir despesas e receitas\n");
        printf("4. Exibir saldo total\n");
        printf("5. Gerenciar categorias\n");
        printf("6. Exibir categorias\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        
        int escolha;
        scanf("%d", &escolha);

        //REGISTRO DE DESPESAS
        if (escolha == 1) {
            if (numDespesas < MAX_DESPESAS) {
                struct Despesa novaDespesa;

                printf("Informe o valor da despesa: R$ ");
                scanf("%f", &novaDespesa.valor);

                printf("Informe a data (DD/MM/AAAA): ");
                scanf("%s", novaDespesa.data);

                printf("Informe a categoria: ");
                scanf(" %[^\n]", novaDespesa.categoria);

                printf("Adicione uma nota adicional (opcional): ");
                scanf(" %[^\n]", novaDespesa.nota);

                despesas[numDespesas] = novaDespesa;
                numDespesas++;

                printf("Despesa registrada com sucesso!\n");
            } else {
                printf("Limite de despesas atingido. Nao e possivel adicionar mais despesas.\n");
            }
        //REGISTRO DE RECEITAS
        } else if (escolha == 2) {
            if (numReceitas < MAX_RECEITAS) {
                struct Receita novaReceita;

                printf("Informe o valor da receita: R$ ");
                scanf("%f", &novaReceita.valor);

                printf("Informe a data (DD/MM/AAAA): ");
                scanf("%s", novaReceita.data);

                printf("Informe a fonte da receita: ");
                scanf(" %[^\n]", novaReceita.fonte);

                receitas[numReceitas] = novaReceita;
                numReceitas++;

                printf("Receita registrada com sucesso!\n");
            } else {
                printf("Limite de receitas atingido. Nao e possivel adicionar mais receitas.\n");
            }
        //EXIBINDO DESPESA REGISTRADA
        } else if (escolha == 3) {
            printf("Despesas registradas:\n");
            for (int i = 0; i < numDespesas; i++) {
                printf("Despesa %d:\n", i + 1);
                printf("Valor: R$ %.2f\n", despesas[i].valor);
                printf("Data: %s\n", despesas[i].data);
                printf("Categoria: %s\n", despesas[i].categoria);
                if (strlen(despesas[i].nota) > 0) {
                    printf("Nota: %s\n", despesas[i].nota);
                }
                printf("\n");
            }
            
            //EXIBINDO RECEITAS REGISTRADAS
            printf("Receitas registradas:\n");
            for (int i = 0; i < numReceitas; i++) {
                printf("Receita %d:\n", i + 1);
                printf("Valor: R$ %.2f\n", receitas[i].valor);
                printf("Data: %s\n", receitas[i].data);
                printf("Fonte: %s\n", receitas[i].fonte);
                printf("\n");
            }
        //CALCULA O SALDO FINAL
        } else if (escolha == 4) {
            float saldo = calcularSaldo(despesas, numDespesas, receitas, numReceitas);
            printf("Saldo total: R$ %.2f\n", saldo);

        //ABRE TRÊS OPÇÔES PARA AS CATEGORIAS
        } else if (escolha == 5) {
            printf("Gerenciamento de categorias:\n");
            printf("1. Adicionar categoria\n");
            printf("2. Editar categoria\n");
            printf("3. Excluir categoria\n");
            printf("Escolha uma opcao: ");
            
            int opcaoCategoria;
            scanf("%d", &opcaoCategoria);
            //OPÇÂO DE ADICIONAR
            if (opcaoCategoria == 1) {
                if (numCategorias < MAX_CATEGORIAS) {
                    printf("Informe o nome da nova categoria: ");
                    scanf(" %[^\n]", categorias[numCategorias].nome);
                    numCategorias++;
                    printf("Categoria adicionada com sucesso!\n");
                } else {
                    printf("Limite de categorias atingido. Nao e possivel adicionar mais categorias.\n");
                }
            //OPÇÃO DE EDITAR
            } else if (opcaoCategoria == 2) {
                printf("Categorias disponiveis:\n");
                for (int i = 0; i < numCategorias; i++) {
                    printf("%d. %s\n", i + 1, categorias[i].nome);
                }
                printf("Selecione a categoria a ser editada (numero): ");
                int categoriaEditar;
                scanf("%d", &categoriaEditar);
                if (categoriaEditar >= 1 && categoriaEditar <= numCategorias) {
                    printf("Informe o novo nome da categoria: ");
                    scanf(" %[^\n]", categorias[categoriaEditar - 1].nome);
                    printf("Categoria editada com sucesso!\n");
                } else {
                    printf("Categoria invalida.\n");
                }
            //OPÇÃO DE EXCLUIR    
            } else if (opcaoCategoria == 3) {
                printf("Categorias disponiveis:\n");
                for (int i = 0; i < numCategorias; i++) {
                    printf("%d. %s\n", i + 1, categorias[i].nome);
                }
                printf("Selecione a categoria a ser excluida (numero): ");
                int categoriaExcluir;
                scanf("%d", &categoriaExcluir);
                if (categoriaExcluir >= 1 && categoriaExcluir <= numCategorias) {
                    for (int i = categoriaExcluir - 1; i < numCategorias - 1; i++) {
                        strcpy(categorias[i].nome, categorias[i + 1].nome);
                    }
                    numCategorias--;
                    printf("Categoria excluida com sucesso!\n");
                } else {
                    printf("Categoria invalida.\n");
                }
            } else {
                printf("Opcao invalida. Tente novamente.\n");
            }
        //EXIBE AS CATEGORIAS REGISTRADAS NO MOMENTO(INCLUINDO AS PRÉ-REGISTRADAS)
        } else if (escolha == 6) {
            printf("Categorias registradas:\n");
            for (int i = 0; i < numCategorias; i++) {
                printf("Categoria %d: %s\n", i + 1, categorias[i].nome);
            }
        //QUEBRANDO O WHILE
        } else if (escolha == 7) {
            printf("Saindo do programa.\n");
            break;
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}