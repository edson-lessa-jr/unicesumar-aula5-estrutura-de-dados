#ifndef LISTA_TAREFAS_H
#define LISTA_TAREFAS_H

#define TAMANHO_MAXIMO_TITULO 100
#define TAMANHO_MAXIMO_DESCRICAO 256

// Estrutura de um nó da lista de tarefas
typedef struct Task {
    char titulo[TAMANHO_MAXIMO_TITULO];
    char descricao[TAMANHO_MAXIMO_DESCRICAO];
    int completada;
    struct Task* proximo;
} Tarefa;

// Função para criar uma nova tarefa
Tarefa* criaTarefa(const char* titulo, const char* descricao, int completada);

// Função para adicionar uma tarefa no início da lista
void adicionaTarefa(Tarefa** tarefa, const char* titulo, const char* descricao, int completada);

// Função para adicionar uma tarefa na posição X
int adicionaTarefaPosicao(Tarefa** tarefaRef, const char* titulo, const char* descricao, int completada, int pos);

// Função para alterar uma tarefa na posição X
int alteraTarefaPosicao(Tarefa* tarefa, int pos, const char* novoTitulo, const char* novaDescricao, int novaCompletada);

// Função para imprimir todas as tarefas
void exibirTodasTarefas(Tarefa* tarefa);

// Função para listar uma tarefa específica
void exibeTarefaPosicao(Tarefa* tarefa, int pos);

// Função para marcar uma tarefa como concluída
void completarTarefa(Tarefa* tarefa, const char* titulo);

// Função para excluir uma tarefa na posição X
int excluirTarefaPosicao(Tarefa** tarefaRef, int pos);

// Função para liberar a memória alocada para a lista
void liberarMemoria(Tarefa* tarefa);

// Função para aguardar um Enter do usuário
void aguardarEnter();

// Função principal para demonstrar a lista de tarefas
void exemploListaTarefas();

#endif // LISTA_TAREFAS_H
