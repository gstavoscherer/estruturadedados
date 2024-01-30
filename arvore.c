#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

No* inserirElemento(No* raiz, int dado) {
    if (raiz == NULL) {
        return criarNo(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerda = inserirElemento(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = inserirElemento(raiz->direita, dado);
    }
    return raiz;
}

int buscarElemento(No* raiz, int dado) {
    if (raiz == NULL) {
        return 0;
    }
    if (dado == raiz->dado) {
        return 1;
    } else if (dado < raiz->dado) {
        return buscarElemento(raiz->esquerda, dado);
    } else {
        return buscarElemento(raiz->direita, dado);
    }
}

void imprimirPreordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        imprimirPreordem(raiz->esquerda);
        imprimirPreordem(raiz->direita);
    }
}

void imprimirOrdemCrescente(No* raiz) {
    if (raiz != NULL) {
        imprimirOrdemCrescente(raiz->esquerda);
        printf("%d ", raiz->dado);
        imprimirOrdemCrescente(raiz->direita);
    }
}

void imprimirPosordem(No* raiz) {
    if (raiz != NULL) {
        imprimirPosordem(raiz->esquerda);
        imprimirPosordem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

void exibirMenu() {
    printf("\nOpções:\n");
    printf("1 - Inserir um elemento na árvore\n");
    printf("2 - Buscar um elemento na árvore\n");
    printf("3 - Imprimir árvore em pré-ordem\n");
    printf("4 - Imprimir árvore em ordem crescente\n");
    printf("5 - Imprimir árvore em pós-ordem\n");
    printf("6 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    No* raiz = NULL;
    int escolha, elemento, resultado;

    do {
        exibirMenu();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                raiz = inserirElemento(raiz, elemento);
                break;
            case 2:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &elemento);
                resultado = buscarElemento(raiz, elemento);
                if (resultado) {
                    printf("Elemento encontrado na árvore.\n");
                } else {
                    printf("Elemento não encontrado na árvore.\n");
                }
                break;
            case 3:
                printf("Árvore em pré-ordem: ");
                imprimirPreordem(raiz);
                printf("\n");
                break;
            case 4:
                printf("Árvore em ordem crescente: ");
                imprimirOrdemCrescente(raiz);
                printf("\n");
                break;
            case 5:
                printf("Árvore em pós-ordem: ");
                imprimirPosordem(raiz);
                printf("\n");
                break;
            case 6:
                liberarArvore(raiz);
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}
