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

// Função para imprimir todas as tarefas
void exibiTodasTarefas(Tarefa* tarefa) {
    Tarefa* temp = tarefa;
    while (temp != NULL) {
        printf("Title: %s\n", temp->titulo);
        printf("Description: %s\n", temp->descricao);
        printf("Completed: %s\n", temp->completada ? "Yes" : "No");
        printf("------\n");
        temp = temp->proximo;
    }
}

// Função para marcar uma tarefa como concluída
void completarTarefa(Tarefa* tarefa, const char* titulo) {
    Tarefa* temp = tarefa;
    while (temp != NULL) {
        if (strcmp(temp->titulo, titulo) == 0) {
            temp->completada = 1;
            printf("Tarefa '%s' marcada como concluída.\n", titulo);
            return;
        }
        temp = temp->proximo;
    }
    printf("Tarefa '%s' não encontrada.\n", titulo);
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

// Função principal para demonstrar a lista de tarefas
void exemploListaTarefas() {
    Tarefa* tarefa = NULL;

    adicionaTarefa(&tarefa, "Comprar leite", "Comprar 2 litros de leite", 0);
    adicionaTarefa(&tarefa, "Estudar C", "Estudar alocação dinâmica de memória", 0);
    adicionaTarefa(&tarefa, "Fazer exercícios", "Fazer 30 minutos de exercícios", 0);

    printf("Lista de Tarefas:\n");
    exibiTodasTarefas(tarefa);

    completarTarefa(tarefa, "Estudar C");

    printf("\nLista de Tarefas Atualizada:\n");
    exibiTodasTarefas(tarefa);

    liberarMemoria(tarefa);
}
