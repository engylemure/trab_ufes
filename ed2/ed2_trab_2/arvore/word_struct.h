//
// Created by jordao on 22/06/17.
//
#ifndef ED2_TRAB_2_WORD_STRUCT_H
#define ED2_TRAB_2_WORD_STRUCT_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ocr_list.h"



/*
 * Estrutura de palavra: Word
 * size : tamanho do content;
 * content: palavra a ser armazenada;
 * ocrb: Ponteiro de lista de ocorrencias apontando para o inicio da lista;
 * ocrf: Ponteiro de lista de ocorrencias apontando para o fim da lista;
 */

typedef struct word{
    char* content;
    List ocrb,ocrf;
} Word;

Word* new_word(char* content);

void print_word(Word* word);

int cmp_word(Word* word1, Word* word2);

#endif //ED2_TRAB_2_WORD_STRUCT_H
