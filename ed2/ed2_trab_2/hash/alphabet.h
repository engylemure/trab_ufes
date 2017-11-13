//
// Created by jordao on 04/07/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EXERCICIO3_ALPHABET_H
#define EXERCICIO3_ALPHABET_H
#define MAX_A 255
#define true 1
#define false 0
void create_alphabet(char *filename, short *alphabet);
char* read_word(FILE* file,short *alphabet,int *i);
typedef short typeAlphabet[MAX_A+1];

#endif //EXERCICIO3_ALPHABET_H
