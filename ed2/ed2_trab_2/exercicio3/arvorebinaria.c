#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <math.h>
typedef long TipoChave;
typedef struct TipoRegistro {
    TipoChave Chave;
    /* outros componentes */
} TipoRegistro;
typedef struct TipoNo * TipoApontador;
typedef struct TipoNo {
    TipoRegistro Reg;
    TipoApontador Esq, Dir;
} TipoNo;
typedef TipoApontador TipoDicionario;

void Pesquisa(TipoRegistro *x, TipoApontador *p)
{ if (*p == NULL)
    { printf("Erro: Registro nao esta presente na arvore\n");
        return;
    }
    if (x->Chave < (*p)->Reg.Chave)
    { Pesquisa(x, &(*p)->Esq);
        return;
    }
    if (x->Chave > (*p)->Reg.Chave)
        Pesquisa(x, &(*p)->Dir);
    else *x = (*p)->Reg;
}

void Insere(TipoRegistro x, TipoApontador *p)
{ if (*p == NULL)
    { *p = (TipoApontador)malloc(sizeof(TipoNo));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave)
    { Insere(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave)
        Insere(x, &(*p)->Dir);
    else printf("Erro : Registro ja existe na arvore\n");
}

void Inicializa(TipoApontador *Dicionario)
{ *Dicionario = NULL; }

void Antecessor(TipoApontador q, TipoApontador *r)
{ if ((*r)->Dir != NULL)
    { Antecessor(q, &(*r)->Dir);
        return;
    }
    q->Reg = (*r)->Reg;
    q = *r;
    *r = (*r)->Esq;
    free(q);
}

void Retira(TipoRegistro x, TipoApontador *p)
{  TipoApontador Aux;
    if (*p == NULL)
    { printf("Erro : Registro nao esta na arvore\n");
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) { Retira(x, &(*p)->Esq); return; }
    if (x.Chave > (*p)->Reg.Chave) { Retira(x, &(*p)->Dir); return; }
    if ((*p)->Dir == NULL)
    { Aux = *p;  *p = (*p)->Esq;
        free(Aux);
        return;
    }
    if ((*p)->Esq != NULL)
    { Antecessor(*p, &(*p)->Esq);
        return;
    }
    Aux = *p;  *p = (*p)->Dir;
    free(Aux);
}

void Central(TipoApontador p)
{ if (p == NULL) return;
    Central(p->Esq);
    printf("%ld\n", p->Reg.Chave);
    Central(p->Dir);
}

void TestaI(TipoNo *p, int pai)
{ if (p == NULL) return;
    if (p->Esq != NULL)
    { if (p->Reg.Chave < p->Esq->Reg.Chave)
        { printf("Erro: Pai %ld menor que filho a esquerda %ld\n", p->Reg.Chave,
                 p->Esq->Reg.Chave);
            exit(1);
        }
    }
    if (p->Dir != NULL)
    { if (p->Reg.Chave > p->Dir->Reg.Chave)
        { printf("Erro: Pai %ld maior que filho a direita %ld\n",  p->Reg.Chave,
                 p->Dir->Reg.Chave);
            exit(1);
        }
    }
    TestaI(p->Esq, p->Reg.Chave);
    TestaI(p->Dir, p->Reg.Chave);
}

int Altura(TipoApontador p)
{
    int e, d;
    if (p == NULL)
        return -1;
    e = Altura(p->Esq);
    d = Altura(p->Dir);
    if (e > d)
        return e+1;
    else
        return d+1;
}
void Testa(TipoNo *p)
{ if (p != NULL)
        TestaI(p, p->Reg.Chave);
}

double rand0a1() {
    double resultado=  (double) rand()/ RAND_MAX; /* Dividir pelo maior inteiro */
    if(resultado>1.0) resultado = 1.0;
    return resultado;
}

void Permut( TipoChave A[], int n) {
    int i,j; TipoChave b;
    for(i = n; i>0; i --)
    { j = (i * rand0a1());
        b = A[i];
        A[i] = A[j];
        A[j] = b;
    }
}

int main(int argc, char *argv[])
{
    struct timeval t,inicio,final;
    TipoNo *Dicionario;
    TipoRegistro x;

    int i, j, k, n;
    long int MAX;
    double tempo;
    Inicializa(&Dicionario);
    for(i=6;i<=14;i+=2) {
        /* Gera uma permutação aleatoria de chaves entre 1 e MAX */
        MAX = pow(2,i);
        TipoChave vetor1[1024];
        int altura = 0;
        tempo = 0;
        TipoChave vetor[MAX];
        for(j=0;j<3;j++) {
            for (k = 0; k < MAX; k++) vetor[k] = k + 1;
            for (k = 0; k < 1024; k++) vetor1[k] = k%MAX+1;
            gettimeofday(&t, NULL);
            srand((unsigned int) t.tv_usec);
            Permut(vetor, MAX - 1);

            /* Insere cada chave na arvore e testa sua integridade apos cada insercao */
            for (k = 0; k < MAX; k++) {
                x.Chave = vetor[k];
                Insere(x, &Dicionario);
                //printf("Inseriu chave: %d\n", x.Chave);
                Testa(Dicionario);
            }
            altura+= Altura(Dicionario);

            for(k=0;k<1024;k++){
                x.Chave = vetor1[k];
                gettimeofday(&inicio, NULL);
                Pesquisa(&x,&Dicionario);
                gettimeofday(&final, NULL);
                tempo+= (final.tv_sec-inicio.tv_sec)*1000.0+(final.tv_usec-inicio.tv_usec)/1000.0;
            }


            for (k = 0; k < MAX; k++)
            { x.Chave = Dicionario->Reg.Chave;
                Retira(x, &Dicionario);
                Testa(Dicionario);
                //printf("Retirou chave: %ld\n", x.Chave);
            }
        }
        printf("n=(2^%d) e h = %d e t=%lfms\n",i,altura/3,tempo/3);
    }
    /* Retira uma chave aleatoriamente e realiza varias pesquisas */
    /*
    for (i = 0; i <= MAX; i++)
    { k = (int) (10.0*rand()/(RAND_MAX+1.0));
        n = vetor[k];
        x.Chave = n;
        Retira(x, &Dicionario);
        Testa(Dicionario);
        printf("Retirou chave: %ld\n", x.Chave);
        for (j = 0; j < MAX; j++)
        { x.Chave = vetor[(int) (10.0*rand()/(RAND_MAX+1.0))];
            if (x.Chave != n)
            { printf("Pesquisando chave: %ld\n", x.Chave);
                Pesquisa(&x, &Dicionario);
            }
        }
        x.Chave = n;
        Insere(x, &Dicionario);
        printf("Inseriu chave: %ld\n", x.Chave);
        Testa(Dicionario);
    }
    */
    /* Retira a raiz da arvore ate que ela fique vazia */
    /*
    for (i = 0; i < MAX; i++)
    { x.Chave = Dicionario->Reg.Chave;
        Retira(x, &Dicionario);
        Testa(Dicionario);
        printf("Retirou chave: %ld\n", x.Chave);
    }*/
    return 0;
}