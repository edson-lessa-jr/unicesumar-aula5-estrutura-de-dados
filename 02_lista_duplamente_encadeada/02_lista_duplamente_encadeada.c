#include <stdio.h>
#include <stdlib.h>
#include "02_lista_duplamente_encadeada.h"

// Função para criar um novo nó
NoListD* criaNoListD(int data) {
    // Aloca dinamicamente memória para um novo nó
    NoListD* newNode = (NoListD*)malloc(sizeof(NoListD));
    // Atribui o valor ao campo dado do nó
    newNode->dado = data;
    // Define os ponteiros proximo e anterior como NULL
    newNode->proximo = NULL;
    newNode->anterior = NULL;
    return newNode;
}

// Função para inserir um novo nó no início da lista
void inseriNoInicio(NoListD** no, int dado) {
    // Cria um novo nó com o valor especificado
    NoListD* novoNo = criaNoListD(dado);
    // Faz o novo nó apontar para o nó atual que é a cabeça da lista
    novoNo->proximo = *no;
    // Se a lista não estiver vazia, atualiza o ponteiro anterior do nó atual da cabeça
    if (*no != NULL) {
        (*no)->anterior = novoNo;
    }
    // Atualiza a cabeça da lista para o novo nó
    *no = novoNo;
}

// Função para imprimir todos os elementos da lista
void exibeTodosElementosLista(NoListD* no) {
    NoListD* temp = no;
    // Percorre a lista e imprime cada valor
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

// Função principal para demonstrar a lista duplamente encadeada
void exemploListaDuplamenteEncadeada() {
    NoListD* no = NULL; // Inicializa a lista como vazia

    // Insere alguns valores na lista
    inseriNoInicio(&no, 3);
    inseriNoInicio(&no, 2);
    inseriNoInicio(&no, 1);

    // Imprime a lista resultante
    printf("Lista duplamente encadeada: ");
    exibeTodosElementosLista(no);

    // Libera a memória alocada para a lista
    liberarMemoriaAlocada(no);
}
