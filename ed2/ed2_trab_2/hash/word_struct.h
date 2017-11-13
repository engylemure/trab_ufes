//
// Created by jordao on 22/06/17.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ocr_list.h"

#ifndef ED2_TRAB_2_BINTREE_WORD_STRUCT_H
#define ED2_TRAB_2_BINTREE_WORD_STRUCT_H

/*
 * Estrutura de palavra: Word
 * size : tamanho do content;
 * content: palavra a ser armazenada;
 * ocrb: Ponteiro de lista de ocorrencias apontando para o inicio da lista;
 * ocrf: Ponteiro de lista de ocorrencias apontando para o fim da lista;
 * next: Ponteiro apontando para a proxima palavra na lista de palavras armazenada;
 */

typedef struct word{
    size_t size;
    char* content;
    List ocrb,ocrf;
    struct word* next;
}Word;
Word* new_word(int size,char* content);
Word* insert_word(Word* head,Word* inserted);
Word* search_word(Word* head,Word* searched,int (*cmp)(const char*,const char*));
Word* insert_ocrl(Word* aux, List ocr);
void print_word(Word* word);
#endif //ED2_TRAB_2_BINTREE_WORD_STRUCT_H
