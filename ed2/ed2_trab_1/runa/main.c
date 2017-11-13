#include "lib_sort.h"
#include "rand_file.h"
#include <stdlib.h>
#include <sys/time.h>
/*Testador do item A
 * Valores fixados em:
 * n: Numero de itens a serem ordenados de acordo com a quantidade de chaves no arquivo de chaves de entrada.
 * m: Espaco da memoria interna em numero de itens de acordo com o valor de entrada;
 * f: ordem de intercalacao, de acordo com o valor de entrada;
 */
double testea(char* nome_arq,char* nome_arq_saida,int m,int f){
    int i = 0;
    FILE* file_in;
    void *v;

    unsigned long int n;

    struct timeval inicio, final;
    n = create_char_from_file(nome_arq);
    //Gera n elementos de 32 bytes com chaves do tipo int e escreve no disco
    printf("Criando %ld elementos de 32 bytes e salvando no disco.\n", n);
    printf("OK\n");

    printf("Executando algoritmo de ordenacao externa.\n");
    gettimeofday(&inicio, NULL);
    sort_away("char_in.bin",nome_arq_saida,n,m,f,sizeof(Char_register),cmp_char,qsort,print_char);
    gettimeofday(&final, NULL);

    v = malloc(sizeof(Char_register)*n);
    file_in = fopen(nome_arq_saida,"rb");
    fread(v,sizeof(Char_register),(size_t)n,file_in);
    printf("sort_away finished\nOutput file name:%s\nContent:\n",nome_arq_saida);
    for(i=0;i<n;i++){
        printf("%c ",((Char_register*)(v+i*sizeof(Char_register)))->key);
    }
    printf("\n\n");
    free(v);
    double t_e = (final.tv_sec - inicio.tv_sec)*1000 +(final.tv_usec- inicio.tv_usec)/1000.0;
    printf("Tempo gasto para n=%d, m=%d, f=%d: %lfms\n\n", n, m, f, t_e);
    fclose(file_in);
    return t_e;
}

int main(int argc, char** argv){

    double tmedio=0.0;

    if(argc!=5)
        exit(1);

    tmedio = testea(argv[1],argv[2],atoi(argv[3]),atoi(argv[4]));
}
