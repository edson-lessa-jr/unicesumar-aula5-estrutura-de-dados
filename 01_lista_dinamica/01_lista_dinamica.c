#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "01_lista_dinamica.h"

// Funcao para adicionar um nó ao final da lista
void append(Node **head_ref, int new_data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Funcao para imprimir todos os elementos da lista
void printList(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Funcao para incluir números fornecidos pelo usuário
void incluirNumerosUsuario(Node **head_ref) {
    int num, val;

    printf("Quantos numeros voce deseja adicionar? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &val);
        append(head_ref, val);
    }
}

// Funcao para incluir um número em uma posicao específica
bool incluirNumeroPosicao(Node **head_ref, int new_data, int pos) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = new_data;

    if (pos == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return true;
    }

    Node *temp = *head_ref;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return false;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return true;
}

// Funcao para incluir 30 números aleatórios na lista
void incluirNumerosAleatorios(Node **head_ref) {
    srand(time(0));

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100; // Números aleatórios entre 0 e 99
        append(head_ref, rand_num);

    }
}

// Funcao para liberar a memória alocada para a lista
void liberarLista(struct Node *no) {
    struct No *temp;
    while (no != NULL) {
        temp = no;
        no = no->next;
        free(temp);
    }
}

// Funcao principal para demonstrar a lista dinâmica de inteiros
void exemploListaDinamica() {
    Node *head = NULL;


/*    printf("Lista após incluir números do usuário:\n");
    printList(head);*/
    do {
        int val, pos, opcao;
        printf("\nMenu:\n");
        printf("1. Incluir varios numero\n");
        printf("2. Incluir um numero\n");
        printf("3. Incluir 30 numeros aleatorios\n");
        printf("4. Exibe a Lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirNumerosUsuario(&head);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &val);
                printf("Digite a posicao em que deseja inserir (0 para inicio): ");
                scanf("%d", &pos);
                if (incluirNumeroPosicao(&head, val, pos)) {
                    printf("Valor inserido com sucesso.\n");
                } else {
                    printf("Posicao invalida.\n");
                }
                printf("Lista apos insercao na posicao especifica:\n");
                printList(head);
                break;
            case 3:
                incluirNumerosAleatorios(&head);
                printf("Lista apos incluir 30 números aleatorios:\n");
                printList(head);
                break;
            case 4:
                printList(head);
                break;
            case 0:
                return;
        }
    } while (true);
    liberarLista(head);
}
