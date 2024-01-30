#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50
#define MAX_LIST_SIZE 10

// Estrutura para armazenar uma lista de strings
typedef struct {
    char* strings[MAX_LIST_SIZE];
    int tamanho;
} ListaDeStrings;

void criarLista(ListaDeStrings* lista) {
    lista->tamanho = 0;
    for (int i = 0; i < MAX_LIST_SIZE; i++) {
        lista->strings[i] = NULL;
    }
}

int inserirElemento(ListaDeStrings* lista, const char* elemento) {
    if (lista->tamanho < MAX_LIST_SIZE) {
        lista->strings[lista->tamanho] = (char*)malloc(strlen(elemento) + 1);
        if (lista->strings[lista->tamanho] == NULL) {
            printf("Erro: Não foi possível alocar memória para o elemento.\n");
            return 0;  
        }
        strcpy(lista->strings[lista->tamanho], elemento);
        lista->tamanho++;
        return 1; 
    } else {
        printf("Erro: A lista está cheia. Não é possível inserir mais elementos.\n");
        return 0; 
    }
}

void retirarElemento(ListaDeStrings* lista, int indice) {
    if (indice >= 0 && indice < lista->tamanho) {
        free(lista->strings[indice]);
        for (int i = indice; i < lista->tamanho - 1; i++) {
            lista->strings[i] = lista->strings[i + 1];
        }
        lista->strings[lista->tamanho - 1] = NULL;
        lista->tamanho--;
    } else {
        printf("Erro: Índice fora dos limites da lista.\n");
    }
}

int contarElementos(ListaDeStrings* lista) {
    return lista->tamanho;
}

void exibirLista(ListaDeStrings* lista) {
    if (lista->tamanho == 0) {
        printf("A lista está vazia.\n");
    } else {
        printf("Conteúdo da lista:\n");
        for (int i = 0; i < lista->tamanho; i++) {
            printf("%d: %s\n", i, lista->strings[i]);
        }
    }
}

void liberarLista(ListaDeStrings* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        free(lista->strings[i]);
        lista->strings[i] = NULL;
    }
    lista->tamanho = 0;
}

int main() {
    ListaDeStrings lista;
    criarLista(&lista);

    int escolha;
    char elemento[MAX_STR_LEN];
    int indice;

    while (1) {
        printf("\nOpções:\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Retirar elemento\n");
        printf("3 - Criar lista\n");
        printf("4 - Contar elementos da lista\n");
        printf("5 - Exibir conteúdo da lista\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%s", elemento);
                if (inserirElemento(&lista, elemento)) {
                    printf("Elemento inserido na lista.\n");
                }
                break;
            case 2:
                printf("Digite o índice do elemento a ser retirado: ");
                scanf("%d", &indice);
                retirarElemento(&lista, indice);
                break;
            case 3:
                criarLista(&lista);
                printf("Lista criada.\n");
                break;
            case 4:
                printf("A lista possui %d elementos.\n", contarElementos(&lista));
                break;
            case 5:
                exibirLista(&lista);
                break;
            case 6:
                liberarLista(&lista);
                printf("Encerrando o programa.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
