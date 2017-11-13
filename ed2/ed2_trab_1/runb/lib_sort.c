#include "lib_sort.h"
#include "io_arq.h"
#include <stdlib.h>
#include <string.h>

void sort_away(char* in, char *out, unsigned long long int N, unsigned long long int M,int f, size_t size,int (*cmp)(const void*,const void*),void (*sort)(void*, size_t, size_t, int (*)(const void*,const void*)),int (*print)(const void *))
{
    if(print==NULL)sort_awayf(in,out,N,M,f,size,cmp,sort);
    else sort_awayp(in,out,N,M,f,size,cmp,sort,print);
}

void sort_awayp(char* in, char *out, unsigned long long int N, unsigned long long int M,int f, size_t size,int (*cmp)(const void*,const void*),void (*sort)(void *, size_t , size_t, int (*)(const void*,const void*)),int (*print)(const void *))
{
    long long int i,OrdemIntercalacao = f, NBlocos = 0, Low, High, Lim;
    unsigned long long int n;
    FILE* arq_in,* arq_out;
    FILE** v_arq_in = malloc(sizeof(FILE*)*OrdemIntercalacao);
    char* name_arq;
    int Fim;
    arq_in = fopen(in,"rb");
    printf("sort_away()\nCreating files with ordered records from the input file:\n\n");
    while(1)
    {
        void *V;
        if(N/M>NBlocos)
            n = M;
        else n = (N%M);

        V = malloc(n*size);
        Fim = !fread(V,size,n,arq_in);

        if(Fim)
        {
            free(V);break;
        }

        sort(V,n,size,cmp);
        name_arq = nome_arq(NBlocos);
        printf("File Name: %s\nContent:\n",name_arq);
        for(i=0;i<n;i++)
            print(V+i*size);
        printf("\n\n");
        print_file(name_arq,V,n,size);
        free(name_arq);
        NBlocos++;
        free(V);
    }
    fclose(arq_in);

    Low = 0;
    High = NBlocos;
    printf("Starting the balanced interleaving of files:\n\n");
    while( Low < High-1 )
    {
        Lim = minimum(Low + OrdemIntercalacao, High);
        for(i=0;i<Lim-Low;i++)
        {
            name_arq = nome_arq(Low+i);
            v_arq_in[i] = fopen(name_arq,"rb");
            free(name_arq);
        }
        name_arq = nome_arq(High);
        arq_out = fopen(name_arq,"wb");
        printf("Low=%lld,Lim=%lld,High=%lld\nFile Name: %s\nContent:\n",Low,Lim,High,name_arq);
        High++;
        free(name_arq);
        interleaves(v_arq_in,size,Lim-Low,arq_out,cmp,print);
        printf("\n\n");
        fclose(arq_out);
        for(i=0;i<Lim-Low;i++)
        {
            fclose(v_arq_in[i]);
            name_arq = nome_arq(Low+i);
            remove(name_arq);
            free(name_arq);
        }
        Low += OrdemIntercalacao;
    }
    name_arq = nome_arq(High-1);
    rename(name_arq,out);
    free(name_arq);
    free(v_arq_in);
}
void sort_awayf(char* in, char *out, unsigned long long int N, unsigned long long int M,int f, size_t size,int (*cmp)(const void*,const void*),void (*sort)(void *, size_t , size_t , int (*)(const void*,const void*)))
{
    long long int i,OrdemIntercalacao = f, NBlocos = 0, Low, High, Lim;
    unsigned long long int n;
    FILE* arq_in,* arq_out;
    FILE** v_arq_in = malloc(sizeof(FILE*)*OrdemIntercalacao);
    char* name_arq;
    int Fim;
    arq_in = fopen(in,"rb");
    while(1)
    {
        void *V;
        if(N/M>NBlocos)
            n = M;
        else n = (N%M);

        V = malloc(n*size);
        Fim = !fread(V,size,n,arq_in);

        if(Fim)
        {
            free(V);break;
        }
        // Ordenação Interna
        sort(V,n,size,cmp);
        name_arq = nome_arq(NBlocos);
        print_file(name_arq,V,n,size);
        free(name_arq);
        NBlocos++;
        free(V);
    }
    fclose(arq_in);

    Low = 0;
    High = NBlocos;
    while( Low < High-1 )
    {
        Lim = minimum(Low + OrdemIntercalacao, High);
        for(i=0;i<Lim-Low;i++)
        {
            name_arq = nome_arq(Low+i);
            v_arq_in[i] = fopen(name_arq,"rb");
            free(name_arq);
        }
        name_arq = nome_arq(High);
        arq_out = fopen(name_arq,"wb");
        High++;
        free(name_arq);
        interleaves(v_arq_in,size,Lim-Low,arq_out,cmp,NULL);
        fclose(arq_out);
        for(i=0;i<Lim-Low;i++)
        {
            fclose(v_arq_in[i]);
            name_arq = nome_arq(Low+i);
            remove(name_arq);
            free(name_arq);
        }
        Low += OrdemIntercalacao;
    }
    name_arq = nome_arq(High-1);
    rename(name_arq,out);
    free(name_arq);
    free(v_arq_in);
}

int minimum(int low, int high)
{
    if(low >= high) return high;
    else return low;
}

/* FUNÇÂO DE INTERCALAÇÂO */
void interleaves(FILE** in, size_t size, int f, FILE* arq_out, int (*cmp)(const void*,const void*),int (*print)(const void *))
{
    int aux = 0,i,j,one;
    void* item_out = malloc(size),*item_in = malloc(size*f);
    int is_end[f];
    for(j=0;j<f;j++)
    {
        if(fread(item_in+j*size,size,1,in[j])==1)
        {
            is_end[j]=0;
            memcpy(item_out,item_in+j*size,size);
            one = j;
        }
        else is_end[j]=1;
    }
    while(aux<f)
    {
        aux = 0;
        for(i=0;i<f;i++)
        {
            if(!is_end[i])
            {
                if(cmp(item_out,item_in+i*size) >= 0)
                {
                    memcpy(item_out,item_in+i*size,size);
                    one = i;
                }
            }
            else aux++;
        }
        if(aux>=f)break;
        fwrite(item_out,size,1,arq_out);
        if(print!=NULL)print(item_out);
        if(fread(item_in+one*size,size,1,in[one])!=1)is_end[one]=1;
        for(i=0;i<f;i++)
            if(!is_end[i])
            {
                memcpy(item_out,item_in+i*size,size);
                break;
            }
    }
    free(item_out);
    free(item_in);
}
