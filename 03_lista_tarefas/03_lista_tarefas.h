#ifndef LISTA_TAREFAS_H
#define LISTA_TAREFAS_H

#define MAX_TITLE_LENGTH 100
#define MAX_DESC_LENGTH 256

// Estrutura de um nó da lista de tarefas
typedef struct Task {
    char titulo[MAX_TITLE_LENGTH];
    char descricao[MAX_DESC_LENGTH];
    int completada;
    struct Tarefa* proximo;
} Tarefa;

// Função para criar uma nova tarefa
Tarefa* criaTarefa(const char* titulo, const char* descricao, int completada);

// Função para adicionar uma tarefa no início da lista
void adicionaTarefa(Tarefa** tarefa, const char* titulo, const char* descricao, int completada);

// Função para imprimir todas as tarefas
void exibiTodasTarefas(Tarefa* tarefa);

// Função para marcar uma tarefa como concluída
void completarTarefa(Tarefa* tarefa, const char* titulo);

// Função para liberar a memória alocada para a lista
void liberarMemoria(Tarefa* tarefa);

// Função principal para demonstrar a lista de tarefas
void exemploListaTarefas();

#endif // LISTA_TAREFAS_H
