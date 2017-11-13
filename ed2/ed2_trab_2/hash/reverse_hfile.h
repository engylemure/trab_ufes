//
// Created by jordao on 22/06/17.
//
#include "word_struct.h"
#include "ocr_list.h"
#ifndef ED2_TRAB_2_BINTREE_REVERSE_HFILE_H
#define ED2_TRAB_2_BINTREE_REVERSE_HFILE_H
/*
 * Estrutra de arquivo reverso usando hash table.
 */
typedef struct reverse_file{
    Word** hash_v;
    int (*h_func)(char*,int);
    int M;
    int N;
    int n_lines;
}RHF;

RHF* new_rhf( int N, int M, int (*h_fun)(char*,int));
Word* insert_rhf(RHF* hash,Word* w);
Word* search_rhf(RHF* hash,Word* w,int (*cmp)(const char*,const char*));
void print_rhf(RHF* hash);

#endif //ED2_TRAB_2_BINTREE_REVERSE_HFILE_H
