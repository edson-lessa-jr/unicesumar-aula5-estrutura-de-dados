#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "01_lista_dinamica.h"

// Funcao para adicionar um nó ao final da listaRef
void adicionarNo(Lista **listaRef, int novoNumero) {
    Lista *novoNo = (Lista *) malloc(sizeof(Lista)); // Aloca memória para o novo nó
    Lista *ultimo = *listaRef; // Inicializa o ponteiro 'ultimo' com a lista

    novoNo->dado = novoNumero; // Atribui o novo número ao dado do novo nó
    novoNo->proximo = NULL; // Define o próximo do novo nó como NULL

    // Se a lista estiver vazia, o novo nó será o primeiro nó da lista
    if (*listaRef == NULL) {
        *listaRef = novoNo;
        return;
    }

    // Encontra o último nó da lista
    while (ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }

    // Adiciona o novo nó como próximo do último nó da lista
    ultimo->proximo = novoNo;
}

// Funcao para imprimir todos os elementos da lista
void listarTodosElementos(Lista *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->dado); // Imprime o dado do nó atual
        lista = lista->proximo; // Move para o próximo nó
    }
    printf("NULL\n"); // Indica o fim da lista
}

// Funcao para incluir números fornecidos pelo usuário
void incluirNumerosUsuario(Lista **listaRef) {
    int num, val;

    printf("Quantos numeros voce deseja adicionar? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &val); // Obtém o número fornecido pelo usuário
        adicionarNo(listaRef, val); // Adiciona o número à lista
    }
}

// Funcao para incluir um número em uma posicao específica
bool incluirNumeroPosicao(Lista **listaRef, int novoNumero, int pos) {
    Lista *novoNo = (Lista *) malloc(sizeof(Lista)); // Aloca memória para o novo nó
    novoNo->dado = novoNumero; // Atribui o novo número ao dado do novo nó

    // Verifica se a posição é o início da lista
    if (pos == 0) {
        novoNo->proximo = *listaRef; // O próximo do novo nó aponta para o início da lista atual
        *listaRef = novoNo; // Atualiza o início da lista para o novo nó
        return true; // Retorna verdadeiro, indicando que a inclusão foi bem-sucedida
    }

    Lista *temp = *listaRef; // Cria um ponteiro temporário para percorrer a lista
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->proximo; // Move para o próximo nó na lista até alcançar a posição desejada
    }

    // Verifica se a posição é válida
    if (temp == NULL || temp->proximo == NULL) {
        return false; // Retorna falso se a posição for inválida ou se o nó atual for o último
    }

    novoNo->proximo = temp->proximo; // O próximo do novo nó aponta para o próximo do nó atual
    temp->proximo = novoNo; // O próximo do nó atual aponta para o novo nó
    return true; // Retorna verdadeiro, indicando que a inclusão foi bem-sucedida
}

// Funcao para incluir 30 números aleatórios na lista
void incluirNumerosAleatorios(Lista **listaRef) {
    srand(time(0)); // Define a semente para a geração de números aleatórios

    // Loop para incluir 30 números aleatórios na lista
    for (int i = 0; i < 30; i++) {
        int numeroAleatorio = rand() % 100; // Gera um número aleatório entre 0 e 99
        adicionarNo(listaRef, numeroAleatorio); // Chama a função para adicionar o número à lista
    }
}

// Funcao para liberar a memória alocada para a lista
void liberarLista(struct Lista *lista) {
    struct No *temp; // Cria um ponteiro temporário para armazenar o nó a ser liberado

    // Loop para percorrer toda a lista e liberar a memória de cada nó
    while (lista != NULL) {
        temp = lista; // Armazena o nó atual em temp
        lista = lista->proximo; // Move para o próximo nó da lista
        free(temp); // Libera a memória do nó armazenado em temp
    }
}

// Funcao principal para demonstrar a lista dinâmica de inteiros
void exemploListaDinamica() {
    Lista *lista = NULL; // Inicializa a lista como vazia

    // Loop para exibir o menu e processar as opções do usuário
    do {
        int val, pos, opcao; // Declara as variáveis para armazenar valores e opções do usuário

        // Exibe o menu de opções
        printf("\nMenu:\n");
        printf("1. Incluir varios numeros\n");
        printf("2. Incluir um numero\n");
        printf("3. Incluir 30 numeros aleatorios\n");
        printf("4. Exibe a Lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // Lê a opção do usuário

        // Realiza a ação de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                incluirNumerosUsuario(&lista); // Chama a função para incluir vários números fornecidos pelo usuário
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &val);
                printf("Digite a posicao em que deseja inserir (0 para inicio): ");
                scanf("%d", &pos);
                if (incluirNumeroPosicao(&lista, val, pos)) {
                    printf("Valor inserido com sucesso.\n");
                } else {
                    printf("Posicao invalida.\n");
                }
                printf("Lista apos insercao na posicao especifica:\n");
                listarTodosElementos(lista);
                break;
            case 3:
                incluirNumerosAleatorios(&lista); // Chama a função para incluir 30 números aleatórios na lista
                printf("Lista apos incluir 30 numeros aleatorios:\n");
                listarTodosElementos(lista); // Exibe a lista após a inclusão dos números aleatórios
                break;
            case 4:
                listarTodosElementos(lista); // Exibe todos os elementos da lista
                break;
            case 0:
                liberarLista(lista); // Libera a memória alocada para a lista
                return; // Retorna para encerrar o programa
        }
    } while (true); // Loop infinito para exibir o menu até que o usuário escolha sair
}

