#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "02_lista_duplamente_encadeada.h"

// Função para criar um novo nó
NoListD* criaNoListD(int data) {
    NoListD* newNode = (NoListD*)malloc(sizeof(NoListD));
    newNode->dado = data;
    newNode->proximo = NULL;
    newNode->anterior = NULL;
    return newNode;
}

// Função para inserir um novo nó no início da lista
void inseriNoInicio(NoListD** no, int dado) {
    NoListD* novoNo = criaNoListD(dado);
    novoNo->proximo = *no;
    if (*no != NULL) {
        (*no)->anterior = novoNo;
    }
    *no = novoNo;
}

// Função para imprimir todos os elementos da lista
void exibeTodosElementosLista(NoListD* no) {
    NoListD* temp = no;
    while (temp != NULL) {
        printf("%d <-> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função para liberar a memória alocada para a lista
void liberarMemoriaAlocada(NoListD* no) {
    NoListD* temp;
    while (no != NULL) {
        temp = no;
        no = no->proximo;
        free(temp);
    }
}

// Função para inserir um novo nó em uma posição específica
int inserirNoPosicao(NoListD** head_ref, int dado, int pos) {
    if (pos < 0) return 0;

    NoListD* novoNo = criaNoListD(dado);
    if (pos == 0) {
        novoNo->proximo = *head_ref;
        if (*head_ref != NULL) {
            (*head_ref)->anterior = novoNo;
        }
        *head_ref = novoNo;
        return 1;
    }

    NoListD* atual = *head_ref;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL) return 0;

    novoNo->proximo = atual->proximo;
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo;
    }
    atual->proximo = novoNo;
    novoNo->anterior = atual;
    return 1;
}

// Função para incluir números fornecidos pelo usuário
void incluirNumerosUsuarioD(NoListD** head_ref) {
    int num, val;

    printf("Quantos numeros voce deseja adicionar? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &val);
        inseriNoInicio(head_ref, val);
    }
}

// Função para incluir 30 números aleatórios na lista
void incluirNumerosAleatoriosD(NoListD** head_ref) {
    srand(time(0));

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100;
        inseriNoInicio(head_ref, rand_num);
    }
}

// Função principal para demonstrar a lista duplamente encadeada
void exemploListaDuplamenteEncadeada() {
    NoListD* no = NULL;

    int opcao, val, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Incluir no inicio uma quantidade X de numeros\n");
        printf("2. Incluir um numero em uma posicao especifica\n");
        printf("3. Incluir 30 numeros aleatorios no inicio\n");
        printf("4. Exibir a lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirNumerosUsuarioD(&no);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &val);
                printf("Digite a posicao em que deseja inserir (0 para inicio): ");
                scanf("%d", &pos);
                if (inserirNoPosicao(&no, val, pos)) {
                    printf("Valor inserido com sucesso.\n");
                } else {
                    printf("Posicao invalida.\n");
                }
                break;
            case 3:
                incluirNumerosAleatoriosD(&no);
                break;
            case 4:
                printf("Lista duplamente encadeada: ");
                exibeTodosElementosLista(no);
                break;
            case 0:
                liberarMemoriaAlocada(no);
                printf("Saindo....\n");
                return;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }
}
