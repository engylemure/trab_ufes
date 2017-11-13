#ifndef LIB_SORT_H
#define LIB_SORT_H

#include <stdio.h>

/* BIBLIOTECA DE ORDENAÇÂO EXTERNA */
/* FUNÇÂO DE ORDENAÇÂO EXTERNA
 * Entrada
 * char* in : Nome do arquivo de Entrada.
 * char* out : Nome do arquivo de saida.
 * int N : Numero de elementos do Conjunto.
 * int M : Numero de elementos utilizados em Memoria.
 * int f : Numero de arquivos utilizados na intercalação.
 * size_t size : Tamanho do Tipo a ser utilizado na Ordenação.
 * int (*cmp)(const void*,const void*) : Função de comparação entre elementos para a ordenação.
 * void (*sort)(void *v, size_t  tam, size_t size, int (*cmp)(const void*,const void*)) : Funcao utilizada para ordenacao interna.
 * int (*print)(const void *v) : Função a ser utilizada para impressao de cada elemento.
*/
void sort_away(char* in, char *out, unsigned long long int N,unsigned long long int M,int f, size_t size,int (*cmp)(const void*,const void*),void (*sort)(void*, size_t, size_t, int (*)(const void*,const void*)),int (*print)(const void *));
/*
 * Função de ordenação com print.
 */
void sort_awayp(char* in, char *out,unsigned long long int N,unsigned long long int M,int f, size_t size,int (*cmp)(const void*,const void*),void (*sort)(void *, size_t, size_t, int (*)(const void*,const void*)),int (*print)(const void *));
/*
 * Função de ordenação otimizada.
 */
void sort_awayf(char* in, char *out,unsigned long long int N,unsigned long long int M,int f, size_t size,int (*cmp)(const void*,const void*),void (*sort)(void *, size_t, size_t, int (*)(const void*,const void*)));
/*  FUNÇÃO DE INTERCALAÇÃO
 * Entrada
 * FILE** in : Vetor de arquivo de entrada.
 * size_t size : Tamanho do tipo a ser utilizado.
 * int f : Numero de arquivos no vetor de arquivo.
 * int (*cmp)(const void*,const void*) : Função de comparação entre elementos para a ordenação.
 * int (*print)(const void *v) : Função a ser utilizada para impressao de cada elemento.
 * */
void interleaves(FILE** in, size_t size, int f, FILE* arq_out, int (*cmp)(const void*,const void*),int (*print)(const void *v));

/* Função que retorna o minimo entre dois valores */
int minimum(int low, int high);

#endif	// LIB_SORT_H

