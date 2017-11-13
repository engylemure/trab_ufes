//
// Created by jordao on 22/06/17.
//

#ifndef ED2_TRAB_2_BINTREE_OCR_LIST_H
#define ED2_TRAB_2_BINTREE_OCR_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Estrutura que lista as ocorrencias por meio de uma lista.
typedef struct linked_list* List;

typedef struct linked_list{
    int info;
    List next;
}linked_list;

//Cria nova lista
List new_list(int info);

//Adiciona novo elemento na lista e retorna ponteiro para ultima posicao
List update_list(List head,List inserted);

//Imprime lista de elementos
void print_list(List head);

//Marca elementos presentes na lista em um vetor
void update_common_list(int* comum, List l);

#endif //ED2_TRAB_2_BINTREE_OCR_LIST_H
