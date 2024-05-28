#include <stdio.h>
#include "01_lista_dinamica/01_lista_dinamica.h" // Inclui o cabeçalho da lista dinâmica
#include "02_lista_duplamente_encadeada/02_lista_duplamente_encadeada.h" // Inclui o cabeçalho da lista duplamente encadeada
#include "03_lista_tarefas/03_lista_tarefas.h" // Inclui o cabeçalho da lista de tarefas

int main(void) {
    int opcao;

    printf("Iniciando o programa\n");

    do {
        // Exibindo o menu de opções
        printf("\nMenu:\n");
        printf("1. Exemplo Lista Dinamica\n");
        printf("2. Exemplo Lista Duplamente Encadeada\n");
        printf("3. Exemplo Lista de Tarefas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Verificando a opção escolhida e chamando a função correspondente
        switch (opcao) {
            case 1:
                exemploListaDinamica();
                break;
            case 2:
                exemploListaDuplamenteEncadeada();
                break;
            case 3:
                exemploListaTarefas();
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    } while (opcao != 0);

    return 0;
}
