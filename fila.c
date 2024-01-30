#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da fila
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Função para criar uma fila vazia
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Erro: Não foi possível alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Função para inserir um elemento no final da fila
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro: Não foi possível alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Elemento %d inserido na fila.\n", data);
}

// Função para retirar um elemento do início da fila
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia. Não é possível retirar elementos.\n");
    } else {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        printf("Elemento %d retirado da fila.\n", temp->data);
        free(temp);
    }
}

// Função para imprimir o conteúdo da fila
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
    } else {
        Node* current = queue->front;
        printf("Conteúdo da fila: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* queue = createQueue();
    int choice, element;

    while (1) {
        printf("\nOpções:\n");
        printf("1 - Inserir um elemento no final da fila\n");
        printf("2 - Retirar um elemento do início da fila\n");
        printf("3 - Imprimir o conteúdo da fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printQueue(queue);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}