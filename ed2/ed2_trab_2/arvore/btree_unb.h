//
// Created by jordao on 02/06/17.
//
#ifndef BTREE_UNB_H
#define BTREE_UNB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "word_struct.h"
#include "ocr_list.h"



typedef struct binTree{
    struct binTree *right,*left;
    Word* element;
    int height;
}BinTree;

BinTree* new_BinTree(Word* element);

void insert_BinTree_init(BinTree* tree, BinTree* inserted, int(*cmp)(Word*,Word*));

void insertLine_BinTree(BinTree* tree, BinTree* inserted, int(*cmp)(Word*,Word*));

List searchListOcr_BinTree(BinTree* tree, Word* look_for, int(*cmp)(Word*,Word*));

void print_BinTree(BinTree* tree, void (*print)(Word*));

int tree_height(BinTree* tree);

int qtdNos_BinTree(BinTree* tree);

void free_BinTree(BinTree* tree);

#endif //BTREE_UNB_H
