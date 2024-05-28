#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <stdbool.h>

// Estrutura de um nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para adicionar um nó ao final da lista
void append(Node** head_ref, int new_data);

// Função para imprimir todos os elementos da lista
void printList(Node* node);

// Função para incluir números fornecidos pelo usuário
void incluirNumerosUsuario(Node** head_ref);

// Função para incluir um número em uma posição específica
bool incluirNumeroPosicao(Node** head_ref, int new_data, int pos);

// Função para incluir 30 números aleatórios na lista
void incluirNumerosAleatorios(Node **head_ref);

// Função para liberar a memória alocada para a lista
void liberarLista(struct Node* no);

// Função principal para demonstrar a lista encadeada
void exemploListaDinamica();

#endif // LISTA_DINAMICA_H
