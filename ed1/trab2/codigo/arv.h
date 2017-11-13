/*
UFES - UNIVERSIDADE FEDERAL DO ES
CABECALHO DE FUNCOES PARA O 2° TRABALHO DE ESTRUTURA DE DADOS
PROFESSOR : THOMAS HAUBER
ALUNOS : JORDÃO RODRIGUES OLIVEIRA ROSARIO E TADEU ALVES HASTENREITER
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
// DEFINIÇÂO DE ESTRUTURAS
typedef struct arv Arvore; // Definição do struct Arvore
struct arv{ // Estruturação do struct Arvore
	char info;
	int ordem;
	Arvore *filho;
	Arvore *irmao;
};
typedef struct rule Regra; // Definição do struct regra
struct rule{// Estruturação do struct Regra
	char info;
	char *string;
	Regra* Prox;
};
typedef struct ponto Ponto; // Definiçao do struct ponto
struct ponto{// Estruturação do struct ponto
	double x,y;
	double orient;
	Ponto *ant;
};
typedef struct pilha Tartapilha;// Definiçao do struct pilha
struct pilha{// Estruturaçao do struct pilha
 	Ponto* topo;
};
typedef struct lista String;// Definicao do struct lista
struct lista{// Estruturacao do struct lista
	char c;
	int num;
	String *Prox,*Ant;
};

// DECLARACAO DE FUNÇÔES

// Funcoes de Inicializacao
String *IniciaLis(char info,int b);
Arvore *IniciaArv(char info,int ordem);
Regra *IniciaReg(char info,char *string);

// Funcoes de Limpeza e desempilhamento
void LimpaArv(Arvore *arv);
void LimpaReg(Regra *reg);
void LimpaPilha(Tartapilha *pilha);
void LimpaPonto(Ponto* ponto);
void Desempilha(Tartapilha *pilha);

// Funcoes de Aplicacao de Regra
void Aplica(Arvore *arv, Regra *rul, int a,int ordem);
void AplicaReg(Arvore *arv,Regra *rul);
// Funcoes Gerais
void  readLsys( int argc, char **argv);
void ImprimeFolhaTurtle(Arvore *arv,String **lista);
char* fturtlefinal(char *turtname);
static void preambulo( double angle, unsigned int order, double rotimage,const char *psfname );
void genps( double angle, unsigned int order, double rotimage,FILE* fturtle, const char *psfname ,String* string1);
void LinguaDeTartaruga(String *string1,FILE *ftart,int angle, int rotate);

