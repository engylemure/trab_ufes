#include "lib_sort.h"
#include "rand_file.h"
#include <stdlib.h>
#include <sys/time.h>
/*Testador do item B
 * n: Numero de itens a serem ordenados
 * m: Espaco da memoria interna em numero de itens
 * f: ordem de intercalacao
 */
double testeb(long long int n, long long int m,long long int f, char* nome_arq_saida){

    struct timeval inicio, final;
    //Gera n elementos de 32 bytes com chaves do tipo int e escreve no disco
    create_int(n);
    //Executa o algoritmo de ordenacao externa e mede o tempo para tal operacao
    gettimeofday(&inicio, NULL);
    sort_away("int_in.bin",nome_arq_saida,n,m,f,sizeof(Int_register),cmp_int,qsort,NULL);
    gettimeofday(&final, NULL);

    double ini = (inicio.tv_sec)*1000.0 + inicio.tv_usec/1000.0;
    double fim = (final.tv_sec)*1000.0 + final.tv_usec/1000.0;

    return fim-ini;
}

int main(int argc, char** argv){

    double tmedio=0.0;
    int pot = atoi(argv[1]);
    if(argc!=3 || pot <8)
        exit(1);

    long long int i,j,f,k,n,m;

    for(f=2;f<=4;f++) {
        printf("f=%lld\n", f);
        printf("n\tm=n/4\tm=n/16\tm=n/256\n");
        for (k = pot; k < pot+3; k++) {
            n = (long long int)pow(2, k);
            printf("2^(%lld)\t", k);
            m = 4;
            for (j = 0; j < 3; j++) {
                for (i = 0; i < 3; i++) {
                    tmedio += testeb(n, n / m, f, argv[2]);
                }
                printf("%lf\t", tmedio / (i-1));
                tmedio = 0;
                m =(long long int) pow(m, 2);
            }
            printf("\n");
        }
    }

}
