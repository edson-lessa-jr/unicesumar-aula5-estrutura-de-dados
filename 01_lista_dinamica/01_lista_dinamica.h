#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <stdbool.h>

// Estrutura de um nó da lista
typedef struct Lista {
    int dado;
    struct Lista* proximo;
} Lista;

// Função para adicionar um nó ao final da listaRef
void adicionarNo(Lista** listaRef, int novoNumero);

// Função para imprimir todos os elementos da lista
void listarTodosElementos(Lista* lista);

// Função para incluir números fornecidos pelo usuário
void incluirNumerosUsuario(Lista** listaRef);

// Função para incluir um número em uma posição específica
bool incluirNumeroPosicao(Lista** listaRef, int novoNumero, int pos);

// Função para incluir 30 números aleatórios na lista
void incluirNumerosAleatorios(Lista **listaRef);

// Função para liberar a memória alocada para a lista
void liberarLista(struct Lista* lista);

// Função principal para demonstrar a lista encadeada
void exemploListaDinamica();

#endif // LISTA_DINAMICA_H
