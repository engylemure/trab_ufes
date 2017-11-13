#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define VAZIO  "!!!!!!!!!!"
#define RETIRADO  "**********"
int M;
int TAM_H;
#define N  11   /* Tamanho da chave */

typedef unsigned int TipoApontador;
typedef char TipoChave[N];
typedef unsigned TipoPesos[N];
typedef struct TipoItem {
  /* outros componentes */
  TipoChave Chave;
} TipoItem;
typedef unsigned int TipoIndice;
//typedef TipoItem TipoDicionario[M];

TipoPesos p;
TipoItem Elemento;
FILE *arq;
int j, i;

void GeraPesos(TipoPesos p)
{  /* -Gera valores randomicos entre 1 e 10.000- */
  int i; struct timeval semente;
  /* Utilizar o tempo como semente para a funcao srand() */
  gettimeofday(&semente,NULL);
  srand((time(NULL)));
  for (i = 0; i < N; i++)
     p[i] = 1 + ((int)((10000.0 * rand()))%((int)(TAM_H + 1)));
}

TipoIndice h(TipoChave Chave, TipoPesos p)
{ int i; unsigned int Soma = 0; int comp = strlen(Chave);
  for (i = 0; i < comp; i++)
    Soma += (unsigned int)Chave[i]*p[i];
  return (Soma % TAM_H);
}

void Inicializa(TipoItem* T)
{ int i;
 for (i = 0; i < TAM_H; i++) memcpy(T[i].Chave, VAZIO, N);
} 

TipoApontador Pesquisa(TipoChave Ch, TipoPesos p, TipoItem* T)
{ unsigned int  i = 0; unsigned int  Inicial;
  Inicial = h(Ch, p);
  while (strcmp(T[(Inicial + i) % TAM_H].Chave,VAZIO) != 0 &&
         strcmp (T[(Inicial + i) % TAM_H].Chave, Ch) != 0 && i < TAM_H)
    i++;
  if (strcmp( T[(Inicial + i) % TAM_H].Chave, Ch) == 0)
  return ((Inicial + i) % TAM_H);
  else return TAM_H;  /* Pesquisa sem sucesso */
} 

void Insere(TipoItem x, TipoPesos p, TipoItem* T)
{ unsigned int i = 0; unsigned int Inicial;
  if (Pesquisa(x.Chave, p, T) < TAM_H)
  { printf("Elemento ja esta presente\n"); return; }
  Inicial = h(x.Chave, p);
  while (strcmp(T[(Inicial + i) % TAM_H].Chave,VAZIO) != 0 &&
         strcmp(T[(Inicial + i) % TAM_H].Chave, RETIRADO) != 0 && i < TAM_H)
     i++;
  if (i < TAM_H)
  { strcpy(T[(Inicial + i) % TAM_H].Chave, x.Chave);
    /* Copiar os demais campos de x, se existirem */   
  }
  else printf(" Tabela cheia\n");
} 

void Retira(TipoChave Ch, TipoPesos p, TipoItem* T)
{ TipoIndice i;
  i = Pesquisa(Ch, p, T);
  if (i < TAM_H)
  memcpy(T[i].Chave, RETIRADO, N);
  else printf("Registro nao esta presente\n");
} 

void Imprime(TipoItem* tabela)
{ int  i, j, tam;
  for (i = 0; i < TAM_H; i++)
  { printf("%d  ", i);
    tam = strlen(tabela[i].Chave);
    for (j = 0; j < tam; j++)
      putchar(tabela[i].Chave[j]);
    putchar('\n');
  }
}  /* Imprime */

void LerPalavra(char *p, int Tam)
{ char c; int i, j;
  fflush(stdin); j=0;
  while (((c=getchar())!='\n') && (j < (Tam - 1))) p[j++]= c;
  p[j] = '\0';
  while(c != '\n') c = getchar();
  /* Desconsiderar espacos ao final da cadeia como ocorre no Pascal.*/
  for(i = j - 1;(i >= 0 && p[i] == ' ');i--) p[i] = '\0';
}
char* gera_palavra(int n){
  int i,j;
  char* palavra = malloc(sizeof(char)*11);
  for(i=1;i<=6;i++){
    palavra[i-1]=(n%((int)pow(10,i)))/(pow(10,i-1))+97;
  }
  palavra[i-1]='\0';
  return palavra;
}
int main(int argc, char *argv[])
{ M = atoi(argv[1]);
  TAM_H =(int)(M*1.43);
  TipoItem Tabela[TAM_H];
  arq = NULL;
  Inicializa(Tabela);
  srand(time(NULL));
  struct timeval t,inicio,final;
  double tempo=0;

  /*
    assign(arq, 'hash.dat');
    reset(arq);
  */
  int i,j,k;
  for(k=0;k<3;k++) {
    GeraPesos(p);
    for (i = 0; i < M; i++) {
      strcpy(Elemento.Chave, gera_palavra(i));
      Insere(Elemento, p, Tabela);
    }
    /*while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
      { Insere(Elemento, p, Tabela);
        LerPalavra(Elemento.Chave, N);
      }*/
    /*
      close(arq);
    */
    //printf("Tabela apos insercao:\n");
    //Imprime(Tabela);
    /*
      reset(arq);
    */
    //printf("Pesquisar :  "); //LerPalavra(Elemento.Chave, N);
    /*while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
      { i = Pesquisa(Elemento.Chave, p, Tabela);
        if (i < M) printf("sucesso na posicao %d \n", i);
        else printf("pesquisa sem sucesso \n");
        printf("Pesquisar :  ");
        LerPalavra(Elemento.Chave, N);
      }*/

    for (i = 0; i < 1024; i++) {
      strcpy(Elemento.Chave, gera_palavra(rand()% M));
      gettimeofday(&inicio, NULL);
      j = Pesquisa(Elemento.Chave, p, Tabela);
      gettimeofday(&final, NULL);
      tempo+= (final.tv_sec-inicio.tv_sec)*1000.0+(final.tv_usec-inicio.tv_usec)/1000.0;
      //if (j < M) printf("sucesso na posicao %d \n", j);
      //else printf("pesquisa sem sucesso \n");
    }
    /*
      close(arq);
      reset(arq);
    */
    //printf("Retirar seguintes chaves:\n");
    //LerPalavra(Elemento.Chave, N);
    /*while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0) {
      Retira(Elemento.Chave, p, Tabela);
      LerPalavra(Elemento.Chave, N);
    }*/
    for (i = 0; i < M; i++) {
      strcpy(Elemento.Chave, gera_palavra(i));
      Retira(Elemento.Chave, p, Tabela);
    } /*
      close(arq);
    */
    //printf("Tabela apos retiradas:\n");
    //Imprime(Tabela);
    /*
      reset(arq);
    */
    /*printf("Inserir de novo os elementos seguintes:\n");
    LerPalavra(Elemento.Chave, N);
    while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0) {
      Insere(Elemento, p, Tabela);
      LerPalavra(Elemento.Chave, N);
    }*/
    /*
      close(arq);
    */
    //printf("Tabela apos novas insercoes:\n");
    //Imprime(Tabela);
    //if (arq != NULL) fclose(arq);
  }
  printf("tempo em %d: %lfms\n",M,tempo/(3*1024));
  return 0;

}  /* hashing_by_open_addressing */
/* End. */
