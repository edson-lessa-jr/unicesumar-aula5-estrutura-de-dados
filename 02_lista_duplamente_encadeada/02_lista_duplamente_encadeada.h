#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

// Estrutura de um nó da lista duplamente encadeada
typedef struct NoListD {
    int dado;
    struct NoListD* proximo;
    struct NoListD* anterior;
} NoListD;

// Função para criar um novo nó
NoListD* criaNoListD(int data);

// Função para inserir um novo nó no início da lista
void inseriNoInicio(NoListD** no, int dado);

// Função para imprimir todos os elementos da lista
void exibeTodosElementosLista(NoListD* no);

// Função para liberar a memória alocada para a lista
void liberarMemoriaAlocada(NoListD* no);

// Função principal para demonstrar a lista duplamente encadeada
void exemploListaDuplamenteEncadeada();

#endif // LISTA_DUPLAMENTE_ENCADEADA_H
