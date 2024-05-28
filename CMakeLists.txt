cmake_minimum_required(VERSION 3.28)
project(unicesumar_aula5_estrutura_dados C)

set(CMAKE_C_STANDARD 11)

add_executable(unicesumar_aula5_estrutura_dados main.c
        01_lista_dinamica/01_lista_dinamica.h
        01_lista_dinamica/01_lista_dinamica.c
        02_lista_duplamente_encadeada/02_lista_duplamente_encadeada.h
        02_lista_duplamente_encadeada/02_lista_duplamente_encadeada.c
        03_lista_tarefas/03_lista_tarefas.c)
