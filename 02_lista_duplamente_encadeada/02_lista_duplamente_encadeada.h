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
void inseriNoInicio(NoListD** noDRef, int dado);

// Função para imprimir todos os elementos da lista
void exibeTodosElementosLista(NoListD* noD);

// Função para liberar a memória alocada para a lista
void liberarMemoriaAlocada(NoListD* noD);

// Função para inserir um novo nó em uma posição específica
int inserirNoPosicao(NoListD** noDRef, int dado, int pos);

// Função para incluir números fornecidos pelo usuário
void incluirNumerosUsuarioD(NoListD** noDRef);

// Função para incluir 30 números aleatórios na lista
void incluirNumerosAleatoriosD(NoListD** noDRef);

// Função principal para demonstrar a lista duplamente encadeada
void exemploListaDuplamenteEncadeada();

#endif // LISTA_DUPLAMENTE_ENCADEADA_H
