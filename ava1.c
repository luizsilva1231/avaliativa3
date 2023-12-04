#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Produto
typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;

// Definição da estrutura No para a lista encadeada
typedef struct No {
    Produto produto;
    struct No* proximo;
} No;

// Função para inicializar uma lista vazia
No* inicializarLista() {
    return NULL;
}

// Função para adicionar um novo produto à lista de estoque
No* adicionarProduto(No* lista) {
    No* novoNo = (No*)malloc(sizeof(No));
    
    printf("Informe o codigo do produto: ");
    scanf("%d", &novoNo->produto.codigo);
    printf("Informe a descricao do produto: ");
    scanf(" %[^\n]s", novoNo->produto.descricao);
    printf("Informe a quantidade do produto: ");
    scanf("%d", &novoNo->produto.quantidade);
    printf("Informe o valor do produto: ");
    scanf("%f", &novoNo->produto.valor);

    novoNo->proximo = lista;

    printf("Produto adicionado com sucesso!\n");

    return novoNo;
}

// Função para percorrer a lista de estoque e imprimir um relatório
void gerarRelatorio(No* lista) {
    printf("\nRelatorio de Produtos:\n");
    printf("-------------------------------------------------\n");
    while (lista != NULL) {
        printf("Codigo: %d\n", lista->produto.codigo);
        printf("Descricao: %s\n", lista->produto.descricao);
        printf("Quantidade: %d\n", lista->produto.quantidade);
        printf("Valor: %.2f\n", lista->produto.valor);
        printf("-------------------------------------------------\n");
        lista = lista->proximo;
    }
}

// Função para pesquisar um produto pelo código
void consultarProduto(No* lista, int codigo) {
    while (lista != NULL) {
        if (lista->produto.codigo == codigo) {
            printf("\nProduto Encontrado:\n");
            printf("Codigo: %d\n", lista->produto.codigo);
            printf("Descricao: %s\n", lista->produto.descricao);
            printf("Quantidade: %d\n", lista->produto.quantidade);
            printf("Valor: %.2f\n", lista->produto.valor);
            return;
        }
        lista = lista->proximo;
    }
    printf("Produto nao encontrado.\n");
}

// Função para remover um produto do estoque
No* removerProduto(No* lista, int codigo) {
    No* anterior = NULL;
    No* atual = lista;

    while (atual != NULL && atual->produto.codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            lista = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }

        free(atual);
        printf("Produto removido com sucesso!\n");
    } else {
        printf("Produto nao encontrado.\n");
    }

    return lista;
}

// Função principal (menu)
int main() {
    No* listaEstoque = inicializarLista();
    int opcao, codigo;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Gerar Relatorio\n");
        printf("3. Consultar Produto\n");
        printf("4. Remover Produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listaEstoque = adicionarProduto(listaEstoque);
                break;
            case 2:
                gerarRelatorio(listaEstoque);
                break;
            case 3:
                printf("Informe o codigo do produto a ser consultado: ");
                scanf("%d", &codigo);
                consultarProduto(listaEstoque, codigo);
                break;
            case 4:
                printf("Informe o codigo do produto a ser removido: ");
                scanf("%d", &codigo);
                listaEstoque = removerProduto(listaEstoque, codigo);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Liberar memória da lista (não esqueça de implementar a função de liberação)
    // ...

    return 0;
}
