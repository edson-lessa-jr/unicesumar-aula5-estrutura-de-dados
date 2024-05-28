#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "02_lista_duplamente_encadeada.h"

// Função para criar um novo nó na lista duplamente encadeada
NoListD* criaNoListD(int data) {
    // Aloca dinamicamente memória para um novo nó
    NoListD* novoNoD = (NoListD*)malloc(sizeof(NoListD));
    // Define o valor do campo dado do novo nó
    novoNoD->dado = data;
    // Define os ponteiros próximo e anterior como NULL
    novoNoD->proximo = NULL;
    novoNoD->anterior = NULL;
    return novoNoD;
}


// Função para inserir um novo nó no início da lista duplamente encadeada
void inseriNoInicio(NoListD** noDRef, int dado) {
    // Cria um novo nó com o valor especificado
    NoListD* novoNo = criaNoListD(dado);
    // Faz o novo nó apontar para o nó atual que é a cabeça da lista
    novoNo->proximo = *noDRef;
    // Se a lista não estiver vazia, atualiza o ponteiro anterior do nó atual da cabeça
    if (*noDRef != NULL) {
        (*noDRef)->anterior = novoNo;
    }
    // Atualiza a cabeça da lista para o novo nó
    *noDRef = novoNo;
}


// Função para imprimir todos os elementos da lista duplamente encadeada
void exibeTodosElementosLista(NoListD* noD) {
    NoListD* temp = noD;
    // Percorre a lista e imprime cada valor
    while (temp != NULL) {
        printf("%d <-> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função para liberar a memória alocada para a lista duplamente encadeada
void liberarMemoriaAlocada(NoListD* noD) {
    NoListD* temp;
    // Percorre a lista e libera a memória de cada nó
    while (noD != NULL) {
        temp = noD;
        noD = noD->proximo;
        free(temp);
    }
}


// Função para inserir um novo nó em uma posição específica
int inserirNoPosicao(NoListD** noDRef, int dado, int pos) {
    // Verifica se a posição é válida
    if (pos < 0) return 0;

    // Cria um novo nó com o dado especificado
    NoListD* novoNo = criaNoListD(dado);

    // Se a posição for 0, insere no início da lista
    if (pos == 0) {
        novoNo->proximo = *noDRef;
        if (*noDRef != NULL) {
            (*noDRef)->anterior = novoNo;
        }
        *noDRef = novoNo;
        return 1;
    }

    // Procura o nó na posição anterior à posição especificada
    NoListD* atual = *noDRef;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->proximo;
    }

    // Se a posição anterior não existir, retorna 0
    if (atual == NULL) return 0;

    // Insere o novo nó entre o nó atual e o próximo nó
    novoNo->proximo = atual->proximo;
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo;
    }
    atual->proximo = novoNo;
    novoNo->anterior = atual;
    return 1;
}

// Função para incluir números fornecidos pelo usuário
void incluirNumerosUsuarioD(NoListD** noDRef) {
    int num, val;

    // Solicita ao usuário o número de valores a serem inseridos
    printf("Quantos numeros voce deseja adicionar? ");
    scanf("%d", &num);

    // Solicita ao usuário cada número e insere na lista
    for (int i = 0; i < num; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &val);
        inseriNoInicio(noDRef, val);
    }
}

// Função para incluir 30 números aleatórios na lista
void incluirNumerosAleatoriosD(NoListD** noDRef) {
    // Define a semente para geração de números aleatórios
    srand(time(0));

    // Insere 30 números aleatórios na lista
    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100; // Gera um número aleatório entre 0 e 99
        inseriNoInicio(noDRef, rand_num); // Insere o número na lista
    }
}


// Função principal para demonstrar a lista duplamente encadeada
void exemploListaDuplamenteEncadeada() {
    NoListD* no = NULL; // Inicializa a lista como vazia

    int opcao, val, pos;

    // Loop principal do menu
    while (1) {
        printf("\nMenu:\n");
        printf("1. Incluir no inicio uma quantidade X de numeros\n");
        printf("2. Incluir um numero em uma posicao especifica\n");
        printf("3. Incluir 30 numeros aleatorios no inicio\n");
        printf("4. Exibir a lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Switch para tratar as opções do menu
        switch (opcao) {
            case 1:
                incluirNumerosUsuarioD(&no); // Chama a função para incluir números fornecidos pelo usuário
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
                incluirNumerosAleatoriosD(&no); // Chama a função para incluir 30 números aleatórios na lista
                break;
            case 4:
                printf("Lista duplamente encadeada: ");
                exibeTodosElementosLista(no); // Chama a função para exibir todos os elementos da lista
                break;
            case 0:
                liberarMemoriaAlocada(no); // Libera a memória alocada para a lista antes de sair
                printf("Saindo....\n");
                return;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }
}

