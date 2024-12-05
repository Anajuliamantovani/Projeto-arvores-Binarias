cmake_minimum_required(VERSION 3.28)
project(Projeto_arvores_Binarias C)

set(CMAKE_C_STANDARD 23)

add_executable(Projeto_arvores_Binarias main.c
        listaLigada.c
        listaLigada.h
        listaDinamica.c
        listaDinamica.h
        arvoreBinaria.c
        arvoreBinaria.h)
