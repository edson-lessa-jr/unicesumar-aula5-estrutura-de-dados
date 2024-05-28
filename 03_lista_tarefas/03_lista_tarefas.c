#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "03_lista_tarefas.h"

// Função para criar uma nova tarefa
Tarefa *criaTarefa(const char *titulo, const char *descricao, int completada) {
    // Aloca dinamicamente memória para uma nova estrutura de Tarefa
    Tarefa *novaTarefa = (Tarefa *) malloc(sizeof(Tarefa));

    // Copia o título fornecido para o campo 'titulo' da nova tarefa, garantindo que não exceda o tamanho máximo
    strncpy(novaTarefa->titulo, titulo, TAMANHO_MAXIMO_TITULO);

    // Copia a descrição fornecida para o campo 'descricao' da nova tarefa, garantindo que não exceda o tamanho máximo
    strncpy(novaTarefa->descricao, descricao, TAMANHO_MAXIMO_DESCRICAO);

    // Define o status de conclusão da tarefa com o valor fornecido
    novaTarefa->completada = completada;

    // Inicializa o ponteiro 'proximo' como NULL, indicando que este é o último nó na lista por enquanto
    novaTarefa->proximo = NULL;

    // Retorna um ponteiro para a nova tarefa criada
    return novaTarefa;
}


// Função para adicionar uma tarefa no início da lista
void adicionaTarefa(Tarefa **tarefa, const char *titulo, const char *descricao, int completada) {
    // Cria uma nova tarefa com os dados fornecidos
    Tarefa *novaTarefa = criaTarefa(titulo, descricao, completada);

    // Faz a nova tarefa apontar para o próximo nó da lista, que é o nó atual (cabeça da lista)
    novaTarefa->proximo = *tarefa;

    // Atualiza o ponteiro de cabeça da lista para apontar para a nova tarefa, tornando-a o novo nó inicial
    *tarefa = novaTarefa;
}


// Função para adicionar uma tarefa na posição X
int adicionaTarefaPosicao(Tarefa **tarefaRef, const char *titulo, const char *descricao, int completada, int pos) {
    // Verifica se a posição é válida (não negativa)
    if (pos < 0)
        return 0;

    // Cria uma nova tarefa com os dados fornecidos
    Tarefa *novaTarefa = criaTarefa(titulo, descricao, completada);

    // Se a posição for 0, insere a tarefa no início da lista
    if (pos == 0) {
        novaTarefa->proximo = *tarefaRef;
        *tarefaRef = novaTarefa;
        return 1;
    }

    // Percorre a lista até a posição desejada
    Tarefa *atual = *tarefaRef;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->proximo;
    }

    // Se a posição desejada não existe (a lista acabou antes), retorna 0
    if (atual == NULL)
        return 0;

    // Insere a nova tarefa após o nó na posição desejada
    novaTarefa->proximo = atual->proximo;
    atual->proximo = novaTarefa;
    return 1;
}


// Função para alterar uma tarefa na posição X
int alteraTarefaPosicao(Tarefa *tarefa, int pos, const char *novoTitulo, const char *novaDescricao, int novaCompletada) {
    // Verifica se a posição é válida (não negativa)
    if (pos < 0)
        return 0;

    // Percorre a lista até a posição desejada
    Tarefa *atual = tarefa;
    for (int i = 0; atual != NULL && i < pos; i++) {
        atual = atual->proximo;
    }

    // Se a posição desejada não existe (a lista acabou antes), retorna 0
    if (atual == NULL)
        return 0;

    // Atualiza os campos da tarefa na posição desejada com os novos valores
    strncpy(atual->titulo, novoTitulo, TAMANHO_MAXIMO_TITULO);
    strncpy(atual->descricao, novaDescricao, TAMANHO_MAXIMO_DESCRICAO);
    atual->completada = novaCompletada;
    return 1;
}


// Função para listar uma tarefa específica
void exibeTarefaPosicao(Tarefa *tarefa, int pos) {
    // Verifica se a posição é válida (não negativa)
    if (pos < 0) {
        printf("Posicao invalida.\n");
        return;
    }

    // Percorre a lista até a posição desejada
    Tarefa *atual = tarefa;
    for (int i = 0; atual != NULL && i < pos; i++) {
        atual = atual->proximo;
    }

    // Se a posição desejada não existe (a lista acabou antes), exibe mensagem de erro
    if (atual == NULL) {
        printf("Posicao invalida.\n");
        return;
    }

    // Exibe os detalhes da tarefa na posição desejada
    printf("Titulo: %s\n", atual->titulo);
    printf("Descricao: %s\n", atual->descricao);
    printf("Completada: %s\n", atual->completada ? "Sim" : "Nao");
    printf("------\n");
}

// Função para marcar uma tarefa como concluída
void completarTarefa(Tarefa *tarefa, const char *titulo) {
    // Variável temporária para percorrer a lista de tarefas
    Tarefa *temp = tarefa;
    // Percorre a lista de tarefas
    while (temp != NULL) {
        // Verifica se o título da tarefa atual corresponde ao título fornecido
        if (strcmp(temp->titulo, titulo) == 0) {
            // Marca a tarefa como concluída (completada = 1)
            temp->completada = 1;
            // Exibe uma mensagem informando que a tarefa foi marcada como concluída
            printf("Tarefa '%s' marcada como concluída.\n", titulo);
            return;
        }
        // Avança para a próxima tarefa na lista
        temp = temp->proximo;
    }
    // Se não encontrar a tarefa com o título fornecido, exibe uma mensagem de erro
    printf("Tarefa '%s' não encontrada.\n", titulo);
}

// Função para imprimir todas as tarefas
void exibirTodasTarefas(Tarefa *tarefa) {
    // Variável temporária para percorrer a lista de tarefas
    Tarefa *temp = tarefa;
    // Percorre a lista de tarefas
    while (temp != NULL) {
        // Exibe os detalhes da tarefa atual
        printf("Titulo: %s\n", temp->titulo);
        printf("Descricao: %s\n", temp->descricao);
        printf("Completada: %s\n", temp->completada ? "Sim" : "Nao");
        printf("------\n");
        // Avança para a próxima tarefa na lista
        temp = temp->proximo;
    }
}


// Função para excluir uma tarefa na posição X
int excluirTarefaPosicao(Tarefa **tarefaRef, int pos) {
    // Verifica se a posição é inválida ou se a lista está vazia
    if (pos < 0 || *tarefaRef == NULL) {
        return 0;
    }

    // Variável temporária para percorrer a lista de tarefas
    Tarefa *temp = *tarefaRef;

    // Se a posição for 0, remove o primeiro nó da lista
    if (pos == 0) {
        *tarefaRef = temp->proximo; // Atualiza a cabeça da lista para o próximo nó
        free(temp); // Libera a memória alocada para o nó removido
        return 1; // Retorna 1 para indicar que a operação foi bem-sucedida
    }

    // Percorre a lista até a posição anterior à posição a ser excluída
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->proximo;
    }

    // Verifica se a posição é inválida ou se chegou ao final da lista
    if (temp == NULL || temp->proximo == NULL) return 0;

    // Variável para armazenar o próximo nó após o nó a ser excluído
    Tarefa *next = temp->proximo->proximo;
    free(temp->proximo); // Libera a memória alocada para o nó a ser excluído
    temp->proximo = next; // Atualiza o ponteiro do nó anterior para o próximo nó
    return 1; // Retorna 1 para indicar que a operação foi bem-sucedida
}

// Função para liberar a memória alocada para a lista
void liberarMemoria(Tarefa *tarefa) {
    // Variável temporária para percorrer a lista de tarefas
    Tarefa *temp;
    // Percorre a lista e libera a memória alocada para cada nó
    while (tarefa != NULL) {
        temp = tarefa;
        tarefa = tarefa->proximo;
        free(temp);
    }
}

// Função para aguardar um Enter do usuário
void aguardarEnter() {
    printf("Pressione Enter para continuar..."); // Exibe a mensagem para o usuário
    while (getchar() != '\n'); // Aguarda até que o usuário pressione Enter
    getchar(); // Limpa o buffer do caractere Enter
}

// Função principal para demonstrar a lista de tarefas
void exemploListaTarefas() {
    Tarefa *tarefa = NULL; // Inicializa a lista de tarefas como vazia
    int opcao, pos, completada;
    char titulo[TAMANHO_MAXIMO_TITULO], descricao[TAMANHO_MAXIMO_DESCRICAO];

    while (1) {
        // Exibe o menu de opções
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
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
        getchar(); // Limpar o buffer de entrada

        printf("\n***********************\n"); // Separador visual

        switch (opcao) {
            case 1:
                // Adiciona uma tarefa no início da lista
                printf("Digite o titulo da tarefa: "); // Solicita ao usuário que digite o título da tarefa
                fgets(titulo, TAMANHO_MAXIMO_TITULO, stdin); // Lê a linha digitada pelo usuário (incluindo espaços) e armazena em 'titulo'.
                // TAMANHO_MAXIMO_TITULO: É o número máximo de caracteres que podem ser lidos, incluindo o caractere nulo de terminação da string. Neste caso, é definido como 100, então fgets lerá até 99 caracteres, reservando o último para o caractere nulo.
                // stdin: É o ponteiro para o fluxo de entrada padrão, que normalmente é o teclado quando o programa é executado no terminal.
                titulo[strcspn(titulo, "\n")] = 0; // Remove o caractere de nova linha do final da string 'titulo'
                printf("Digite a descricao da tarefa: "); // Solicita ao usuário que digite a descrição da tarefa
                fgets(descricao, TAMANHO_MAXIMO_DESCRICAO, stdin); // Lê a linha digitada pelo usuário (incluindo espaços) e armazena em 'descricao'
                descricao[strcspn(descricao, "\n")] = 0; // Remove o caractere de nova linha do final da string 'descricao'
                printf("A tarefa esta completa? (0 para nao, 1 para sim): "); // Solicita ao usuário que indique se a tarefa está completa
                scanf("%d", &completada); // Lê a resposta do usuário e armazena em 'completada'
                adicionaTarefa(&tarefa, titulo, descricao, completada); // Chama a função para adicionar a tarefa à lista
                break;
            case 2:
                // Adiciona uma tarefa em uma posição específica na lista
                printf("Digite o titulo da tarefa: ");
                fgets(titulo, TAMANHO_MAXIMO_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove o caractere de nova linha
                printf("Digite a descricao da tarefa: ");
                fgets(descricao, TAMANHO_MAXIMO_DESCRICAO, stdin);
                descricao[strcspn(descricao, "\n")] = 0; // Remove o caractere de nova linha
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
                // Exibe todas as tarefas da lista
                printf("Lista de Tarefas:\n");
                exibirTodasTarefas(tarefa);
                break;
            case 4:
                // Marca uma tarefa como concluída
                printf("Digite o titulo da tarefa a ser marcada como completa: ");
                fgets(titulo, TAMANHO_MAXIMO_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove o caractere de nova linha
                completarTarefa(tarefa, titulo);
                break;
            case 5:
                // Altera uma tarefa em uma posição específica na lista
                printf("Digite a posicao da tarefa a ser alterada: ");
                scanf("%d", &pos);
                getchar(); // Limpar o buffer de entrada
                printf("Digite o novo titulo da tarefa: ");
                fgets(titulo, TAMANHO_MAXIMO_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove o caractere de nova linha
                printf("Digite a nova descricao da tarefa: ");
                fgets(descricao, TAMANHO_MAXIMO_DESCRICAO, stdin);
                descricao[strcspn(descricao, "\n")] = 0; // Remove o caractere de nova linha
                printf("A tarefa esta completa? (0 para nao, 1 para sim): ");
                scanf("%d", &completada);
                if (alteraTarefaPosicao(tarefa, pos, titulo, descricao, completada)) {
                    printf("Tarefa alterada com sucesso.\n");
                } else {
                    printf("Posicao invalida.\n");
                }
                break;
            case 6:
                // Lista uma tarefa específica
                printf("Digite a posicao da tarefa a ser exibida: ");
                scanf("%d", &pos);
                exibeTarefaPosicao(tarefa, pos);
                break;
            case 7:
                // Exclui uma tarefa de uma posição específica na lista
                printf("Digite a posicao da tarefa a ser excluida: ");
                scanf("%d", &pos);
                if (excluirTarefaPosicao(&tarefa, pos)) {
                    printf("Tarefa excluida com sucesso.\n");
                } else {
                    printf("Posicao invalida.\n");
                }
                break;
            case 0:
                // Libera a memória alocada para a lista de tarefas e retorna ao menu principal
                liberarMemoria(tarefa);
                printf("Voltando ao menu principal...\n");
                return;
            default:
                // Mensagem de opção inválida
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
        aguardarEnter(); // Aguarda o usuário pressionar Enter antes de continuar
    }
}
