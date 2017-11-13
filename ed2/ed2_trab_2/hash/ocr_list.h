//
// Created by jordao on 22/06/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef ED2_TRAB_2_BINTREE_OCR_LIST_H
#define ED2_TRAB_2_BINTREE_OCR_LIST_H
//Estrutura que lista as ocorrencias por meio de uma lista.
typedef struct linked_list *List;
typedef struct linked_list{
    int info;
    List next;
}linked_list;
List new_list(int info);
List insert_list(List head,List inserted);
void print_list(List head);
#endif //ED2_TRAB_2_BINTREE_OCR_LIST_H
