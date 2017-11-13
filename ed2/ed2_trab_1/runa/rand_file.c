#include "rand_file.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>

void create_int(int M){
    int i;
    Int_register a;

    srand(time(NULL));
    FILE* int_in = fopen("int_in.bin","wb");

    for(i=0;i<M;i++){
        a.key = rand()%M;
        fwrite(&a,sizeof(Int_register),1,int_in);
    }

    fclose(int_in);
}

void create_char(int M){
    int i;
    Char_register a;

    srand(time(NULL));
    FILE* char_in = fopen("char_in.bin","wb");

    for(i=0;i<M;i++)
    {
        a.key = rand()%('Z'-'A')+'A';
        fwrite(&a,sizeof(Char_register),1,char_in);
    }

    fclose(char_in);
}

int create_char_from_file(char* nome_arq)
{
    int i=0;
    Char_register a;
    FILE* char_in = fopen("char_in.bin","wb"),*arq_in =fopen(nome_arq,"r");

    while(fscanf(arq_in,"%c\n",&a.key)!=EOF){
        fwrite(&a,sizeof(Char_register),1,char_in);
        i++;
    }

    fclose(arq_in);
    fclose(char_in);

    return i;
}

int cmp_int(const void* a,const void* b)
{
    Int_register a1 = *(Int_register*)a;
    Int_register b1 = *(Int_register*)b;
    return ((a1.key) - (b1.key));
}

int cmp_char(const void* a,const void* b)
{
    Char_register a1 = *(Char_register*)a;
    Char_register b1 = *(Char_register*)b;
    return ((a1.key) - (b1.key));
}

int print_int(const void *v){
    Int_register a1 = *(Int_register*)v;
    printf("%d ",a1.key);
}

int print_char(const void *v){
    Char_register a1 = *(Char_register*)v;
    printf("%c ",a1.key);
}
