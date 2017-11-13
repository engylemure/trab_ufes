#ifndef RAND_FILE_H
#define RAND_FILE_H

#include "lib_sort.h"
#include <math.h>

//Tipo de dados com 32 bytes utilizando 1 char como chave
typedef struct char_register{
    char key;
    char content[31];
}Char_register;

//Tipo de dados com 32 bytes utilizando 1 int como chave
typedef struct int_register{
    int key;
    char content[28];
}Int_register;

/*Funcao de comparacao para o tipo Int_register
 * >0, se a > b
 * 0, se a==b
 * <0, se a < b
 */
int cmp_int(const void* a,const void* b);

/*Funcao de comparacao para o tipo Char_register
 * >0, se a > b
 * 0, se a==b
 * <0, se a < b
 */
int cmp_char(const void* a,const void* b);

/*Construtor de M elementos do tipo Int_register com chaves aleatórias*/
void create_int(int M);

/*Construtor de M elementos do tipo Char_register com chaves aleatórias (entre 'A' e 'Z')*/
void create_char(int M);

/*Construtor de elementos do tipo Char_register com chaves baseadas no conteudo do arquivo nome_arq. Retorna o numero de elementos criados */
int create_char_from_file(char* nome_arq);

/*Imprime a chave de um elemento do tipo Int_register*/
int print_int(const void *v);

/*Imprime a chave de um elemento do tipo Char_register*/
int print_char(const void *v);

#endif	// RAND_FILE_H