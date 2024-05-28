#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "03_lista_tarefas.h"

// Função para criar uma nova tarefa
Tarefa* criaTarefa(const char* titulo, const char* descricao, int completada) {
    Tarefa* novaTarefa = (Tarefa*)malloc(sizeof(Tarefa));
    strncpy(novaTarefa->titulo, titulo, MAX_TITLE_LENGTH);
    strncpy(novaTarefa->descricao, descricao, MAX_DESC_LENGTH);
    novaTarefa->completada = completada;
    novaTarefa->proximo = NULL;
    return novaTarefa;
}

// Função para adicionar uma tarefa no início da lista
void adicionaTarefa(Tarefa** tarefa, const char* titulo, const char* descricao, int completada) {
    Tarefa* novaTarefa = criaTarefa(titulo, descricao, completada);
    novaTarefa->proximo = *tarefa;
    *tarefa = novaTarefa;
}

// Função para adicionar uma tarefa na posição X
int adicionaTarefaPosicao(Tarefa** head_ref, const char* titulo, const char* descricao, int completada, int pos) {
    if (pos < 0) return 0;

    Tarefa* novaTarefa = criaTarefa(titulo, descricao, completada);
    if (pos == 0) {
        novaTarefa->proximo = *head_ref;
        *head_ref = novaTarefa;
        return 1;
    }

    Tarefa* atual = *head_ref;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL) return 0;

    novaTarefa->proximo = atual->proximo;
    atual->proximo = novaTarefa;
    return 1;
}

// Função para alterar uma tarefa na posição X
int alteraTarefaPosicao(Tarefa* head, int pos, const char* novoTitulo, const char* novaDescricao, int novaCompletada) {
    if (pos < 0) return 0;

    Tarefa* atual = head;
    for (int i = 0; atual != NULL && i < pos; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL) return 0;

    strncpy(atual->titulo, novoTitulo, MAX_TITLE_LENGTH);
    strncpy(atual->descricao, novaDescricao, MAX_DESC_LENGTH);
    atual->completada = novaCompletada;
    return 1;
}

// Função para listar uma tarefa específica
void exibeTarefaPosicao(Tarefa* head, int pos) {
    if (pos < 0) {
        printf("Posicao invalida.\n");
        return;
    }

    Tarefa* atual = head;
    for (int i = 0; atual != NULL && i < pos; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Posicao invalida.\n");
        return;
    }


    printf("Titulo: %s\n", atual->titulo);
    printf("Descricao: %s\n", atual->descricao);
    printf("Completada: %s\n", atual->completada ? "Sim" : "Nao");
    printf("------\n");

}

// Função para marcar uma tarefa como concluída
void completarTarefa(Tarefa* tarefa, const char* titulo) {
    Tarefa* temp = tarefa;
    while (temp != NULL) {
        if (strcmp(temp->titulo, titulo) == 0) {
            temp->completada = 1;
            printf("Tarefa '%s' marcada como concluida.\n", titulo);
            return;
        }
        temp = temp->proximo;
    }
    printf("Tarefa '%s' nao encontrada.\n", titulo);
}

// Função para imprimir todas as tarefas
void exibirTodasTarefas(Tarefa* tarefa) {
    Tarefa* temp = tarefa;
    while (temp != NULL) {
        printf("Titulo: %s\n", temp->titulo);
        printf("Descricao: %s\n", temp->descricao);
        printf("Completada: %s\n", temp->completada ? "Sim" : "Nao");
        printf("------\n");
        temp = temp->proximo;
    }
}

// Função para excluir uma tarefa na posição X
int excluirTarefaPosicao(Tarefa** head_ref, int pos) {
    if (pos < 0 || *head_ref == NULL) return 0;

    Tarefa* temp = *head_ref;

    if (pos == 0) {
        *head_ref = temp->proximo;
        free(temp);
        return 1;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->proximo;
    }

    if (temp == NULL || temp->proximo == NULL) return 0;

    Tarefa* next = temp->proximo->proximo;
    free(temp->proximo);
    temp->proximo = next;
    return 1;
}

// Função para liberar a memória alocada para a lista
void liberarMemoria(Tarefa* tarefa) {
    Tarefa* temp;
    while (tarefa != NULL) {
        temp = tarefa;
        tarefa = tarefa->proximo;
        free(temp);
    }
}
// Função para aguardar um Enter do usuário
void aguardarEnter() {
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
}

// Função principal para demonstrar a lista de tarefas
void exemploListaTarefas() {
    Tarefa* tarefa = NULL;
    int opcao, pos, completada;
    char titulo[MAX_TITLE_LENGTH], descricao[MAX_DESC_LENGTH];

    while (1) {
        printf("\nMenu de Lista de Tarefas:\n");
        printf("1. Incluir uma tarefa no inicio\n");
        printf("2. Incluir uma tarefa na posicao X\n");
        printf("3. Exibir todas as tarefas\n");
        printf("4. Completar a tarefa\n");
        printf("5. Alterar a tarefa da posicao X\n");
        printf("6. Listar a tarefa\n");
        printf("7. Excluir a tarefa\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada
        printf("\n***********************\n");
        switch (opcao) {
            case 1:
                printf("Digite o titulo da tarefa: ");
                fgets(titulo, MAX_TITLE_LENGTH, stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remover o caractere de nova linha
                printf("Digite a descricao da tarefa: ");
                fgets(descricao, MAX_DESC_LENGTH, stdin);
                descricao[strcspn(descricao, "\n")] = 0;
                printf("A tarefa esta completa? (0 para nao, 1 para sim): ");
                scanf("%d", &completada);
                adicionaTarefa(&tarefa, titulo, descricao, completada);
                break;
            case 2:
                printf("Digite o titulo da tarefa: ");
                fgets(titulo, MAX_TITLE_LENGTH, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                printf("Digite a descricao da tarefa: ");
                fgets(descricao, MAX_DESC_LENGTH, stdin);
                descricao[strcspn(descricao, "\n")] = 0;
                printf("Digite a posicao em que deseja inserir a tarefa: ");
                scanf("%d", &pos);
                printf("A tarefa esta completa? (0 para nao, 1 para sim): ");
                scanf("%d", &completada);
                if (adicionaTarefaPosicao(&tarefa, titulo, descricao, completada, pos)) {
                    printf("Tarefa adicionada com sucesso.\n");
                } else {
                    printf("Posicao invalida.\n");
                }
                break;
            case 3:
                printf("Lista de Tarefas:\n");
                exibirTodasTarefas(tarefa);
                break;
            case 4:
                printf("Digite o titulo da tarefa a ser marcada como completa: ");
                fgets(titulo, MAX_TITLE_LENGTH, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                completarTarefa(tarefa, titulo);
                break;
            case 5:
                printf("Digite a posicao da tarefa a ser alterada: ");
                scanf("%d", &pos);
                getchar(); // Limpar o buffer de entrada
                printf("Digite o novo titulo da tarefa: ");
                fgets(titulo, MAX_TITLE_LENGTH, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                printf("Digite a nova descricao da tarefa: ");
                fgets(descricao, MAX_DESC_LENGTH, stdin);
                descricao[strcspn(descricao, "\n")] = 0;
                printf("A tarefa esta completa? (0 para nao, 1 para sim): ");
                scanf("%d", &completada);
                if (alteraTarefaPosicao(tarefa, pos, titulo, descricao, completada)) {
                    printf("Tarefa alterada com sucesso.\n");
                } else {
                    printf("Posicao invalida.\n");
                }
                break;
            case 6:
                printf("Digite a posicao da tarefa a ser exibida: ");
                scanf("%d", &pos);
                exibeTarefaPosicao(tarefa, pos);
                break;
            case 7:
                printf("Digite a posicao da tarefa a ser excluida: ");
                scanf("%d", &pos);
                if (excluirTarefaPosicao(&tarefa, pos)) {
                    printf("Tarefa excluida com sucesso.\n");
                } else {
                    printf("Posicao invalida.\n");
                }
                break;
            case 0:
                liberarMemoria(tarefa);
                printf("Voltando ao menu principal...\n");
                return;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
        aguardarEnter();
    }
}
