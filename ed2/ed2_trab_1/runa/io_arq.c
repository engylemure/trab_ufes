#include "io_arq.h"
#include "rand_file.h"
#include <stdlib.h>


size_t fill_page(void *V, int M, FILE* in,size_t size){
    int i;
    for(i=0;i<M;i++){
        if(fread(V+i*size,size,1,in)!=1)return 0;
    }
    return i;
}

char* nome_arq(int N){
    char *nome = malloc(sizeof(char)*33);
    sprintf(nome,".arquivo_saida%d.bin",N);
    return nome;
}

void print_file(char* out,void *V, int n,size_t size)
{
    FILE* arq_out = fopen(out,"wb");
    fwrite(V,size,n,arq_out);
    fclose(arq_out);
}
