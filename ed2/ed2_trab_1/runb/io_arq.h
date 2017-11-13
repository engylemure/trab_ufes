#ifndef IO_ARQ_H
#define IO_ARQ_H

#include <stdio.h>

/* Le M elementos do disco(in) para a memoria(V) */
size_t fill_page(void *V, int M, FILE* in,size_t size);

/* Gera um nome de arquivo temporario */
char* nome_arq(int N);

/* Imprime os dados da memoria(V) no disco(out) */
void print_file(char* out, void *V, int n, size_t size);

#endif	// IO_ARQ_H