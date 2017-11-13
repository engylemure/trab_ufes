/*
UFES - UNIVERSIDADE FEDERAL DO ES
ESTRUTURA DAS FUNCOES PARA O 2° TRABALHO DE ESTRUTURA DE DADOS
PROFESSOR : THOMAS HAUBER
ALUNOS : JORDÃO RODRIGUES OLIVEIRA ROSARIO E TADEU ALVES HASTENREITER
*/
#include "arv.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.141592653589793

static char buf[201];
static FILE *ps = NULL;

Arvore *IniciaArv(char info, int ordem){/* Função para Inicialização do strcut Arvore, tem como entrada os parametros 
char info e int ordem(ordem dentro da Arvore)*/
	Arvore *a=malloc(sizeof(Arvore));
	a->info=info;
	a->ordem=ordem;
	a->filho=NULL;
	a->irmao=NULL;
	return a;
}
Regra *IniciaReg(char info,char *string){/* Função para Inicialização do strcut Regra, tem como entrada os parametros 
char info e char *string */
	int b=strlen(string);
	Regra* a=malloc(sizeof(Regra));
	a->info=info;
	a->string=malloc((b+1)*sizeof(char));
	strcpy(a->string,string);
	a->Prox=NULL;
	return a;
}
Ponto* IniciaPonto(double x, double y,double orient){/*Função para Inicialização do struct Ponto, tem como entrada os parametros
double x, double y, double orient */
	Ponto* a =malloc(sizeof(Ponto));
	a->x=x;
	a->y=y;
	a->orient=orient;
	a->ant=NULL;
	return a;
}
Tartapilha* IniciaTPilha(){/* Função para Inicialização do struct Tartapilha */
	Tartapilha* a=malloc(sizeof(Tartapilha));
	a->topo=NULL;
	return a;
}
String *IniciaLis(char info,int b){/* Função para Inicialização do struct String */
	String *a=malloc(sizeof(String));
	a->c=info;
	a->num=b;
	a->Prox=NULL;
	a->Ant=NULL;
	return a;
}
void LimpaStr(String* a){ /* Função para Liberação da memoria alocada para o tipo struct String */
	if(a!=NULL){
		if(a->Prox!=NULL)LimpaStr(a->Prox);
		free(a);
	}
}
void InsereReg(Regra* rul, Regra* rul1){ /* Função para Inserção de um struct Regra em outro struct Regra */
	rul->Prox=rul1;
}
void Aplica(Arvore *arv, Regra *rul, int a,int ordem){ /* Função para aplicação de uma regra em uma Arvore */
	int b=strlen(rul->string);
	if(a<b){
		arv->irmao=IniciaArv(rul->string[a],ordem);
		Arvore *irmao=arv->irmao;
		Aplica(irmao,rul,a+1,ordem);
	}
}
void AplicaReg(Arvore *arv,Regra *rul){ /* Função para aplicação de uma lista de regras em uma Arvore */
	if(arv!=NULL && rul!=NULL){
		Arvore *filho=arv->filho;
		AplicaReg(arv->irmao,rul);
		if(arv->filho==NULL && arv->info==rul->info){
			arv->filho=IniciaArv(rul->string[0],arv->ordem+1);
			Aplica(arv->filho,rul,1,arv->ordem+1);
		}
		else AplicaReg(filho,rul);
		AplicaReg(arv,rul->Prox);
	}
	else return;
}
void ImprimeArv(Arvore *arv){ /* Função para Impressão dos elementos do Struct Arvore */
	if(arv!=NULL){
		printf("<");
		printf("%c",arv->info);
		ImprimeArv(arv->filho);
		printf(">");		
		if(arv->irmao!=NULL)
			ImprimeArv(arv->irmao);
	}
}
void ImprimeFolha(Arvore *arv){ /* Função para Impressão das folhas do struct Arvore */
	if(arv!=NULL){
		printf("<");
		if(arv->filho==NULL)printf("%c",arv->info);
		else ImprimeFolha(arv->filho);
		printf(">");
		if(arv->irmao!=NULL)ImprimeFolha(arv->irmao);
	}
}
void ImprimeFolhas(Arvore *arv){ /*Função para Impressão das folhas do struct Arvore sem os caracteres '<','>' */
	if(arv!=NULL){
		if(arv->filho==NULL)printf("%c",arv->info);
		else ImprimeFolhas(arv->filho);
		if(arv->irmao!=NULL)ImprimeFolhas(arv->irmao);
	}
}
void ImprimeFolhaTurtle(Arvore *arv,String **lista){ /* Função para criação de uma lista do tipo String utilizando como informações 
os elementos folha da arvore */
	String *novo,*aux=*lista;
	if(arv!=NULL){
		if(arv->filho==NULL){
			if(arv->info=='F' || arv->info=='G' || arv->info=='+' || arv->info=='-' || arv->info=='[' || arv->info==']' ){
				if(aux==NULL)*lista=IniciaLis(arv->info,arv->ordem);
				else {
					novo=IniciaLis(arv->info,arv->ordem);
					while(aux->Prox!=NULL)
						aux=aux->Prox;
					aux->Prox=novo;
				}
			}
		}
		else ImprimeFolhaTurtle(arv->filho,lista);
		if(arv->irmao!=NULL)ImprimeFolhaTurtle(arv->irmao,lista);
	}
}
void LimpaArv(Arvore *arv){ /* Função recursiva para limpeza da Arvore */
	if(arv!=NULL){
		if(arv->irmao!=NULL)LimpaArv(arv->irmao);
		if(arv->filho!=NULL)LimpaArv(arv->filho);
		free(arv);
	}
	return;
}
void LimpaReg(Regra *reg){ /* Função recursiva para limpeza da lista de regras */
	if(reg!=NULL){
		if(reg->Prox!=NULL)LimpaReg(reg->Prox);
		free(reg->string);
		free(reg);
	}
}
void LimpaPonto(Ponto* ponto){ /* Função recursvia para limpeza do struct ponto */
	if(ponto!=NULL){
		if(ponto->ant!=NULL)
		LimpaPonto(ponto->ant);
		ponto->ant=NULL;
		free(ponto);
	}
}
void LimpaPilha(Tartapilha *pilha){ /* Função recursiva para limpeza da Pilha de pontos */
	Ponto *ponto=pilha->topo;
	if(pilha!=NULL){
		LimpaPonto(ponto);
		free(pilha);
	}
}
void Desempilha(Tartapilha *pilha){ /* função desempilha(pop) de uma pilha de pontos */
	Ponto* lixo=pilha->topo;
	if(pilha->topo!=NULL){
		if(pilha->topo->ant!=NULL)
		pilha->topo=pilha->topo->ant;
		else pilha->topo=NULL;
		free(lixo);
	}
}
void LinguaDeTartaruga(String *string1,FILE *ftart,int angle, int rotate){ /* função que converte os comandos de tartaruga em comandos 
interpretados pelo postscript, recebe a lista final de comandos de tartaruga o angle e rotate e os trata imprindo em um arquivo de saida ftart */
	double x=0,y=0,alpha,z=100;
	alpha=0;
	int ordem=1;
	String *aux1=string1;
	Tartapilha *pilha=IniciaTPilha();
	Ponto* ponto,*aux;
	char comand;
	while(aux1!=NULL){
		if(aux1->c=='F'){
			/* Considerando um sistema de arvore procuramos implementar a ideia de que os elementos da
			arvore de menor ordem possuem uma largura maior, cor mais escura similar a uma arvore da vida real. */
			fprintf(ftart,"%d setlinewidth\n",73-9*aux1->num);
			fprintf(ftart,".%d setgray\n",aux1->num-1);
			fprintf(ftart,"n %.2f %.2f ",x,y);
			x=x+cos(alpha)*z/aux1->num*2;
			y=y+sin(alpha)*z/aux1->num*2;
			fprintf(ftart,"m %.2f %.2f l s\n",x,y);
		}
		else if(aux1->c=='G'){
			x=x+cos(alpha)*z/aux1->num*2;
			y=y+sin(alpha)*z/aux1->num*2;
		}
		else if(aux1->c=='+'){
			alpha+=2*PI/angle;
		}
		else if(aux1->c=='-'){
			alpha+=-2*PI/angle;
		}
		else if(aux1->c=='['){
			if(pilha->topo==NULL)pilha->topo=IniciaPonto(x,y,alpha);
			else {
				aux=pilha->topo;
				pilha->topo=IniciaPonto(x,y,alpha);
				pilha->topo->ant=aux;
			}
		}
		else if(aux1->c==']'){
			x=pilha->topo->x;
			y=pilha->topo->y;
			alpha=pilha->topo->orient;
			Desempilha(pilha);
		}
		aux1=aux1->Prox;
	}
	LimpaPilha(pilha);
}
void  readLsys( int argc, char **argv){ /* Programa final para leitura do arquivo de entrada e impressão dos arquivos de saida
 tem como parametro de entrada as variaveis int argc , e char **argv (lista de strings) */
	Regra* regra=NULL,*regras=NULL,*ant,*novo;
	Arvore *arv,*prim=NULL;
	int i,varbreak=0, angle=0,order=0,rotate=0;
	char antpal[21],pal[21],pal1[21],axiom[101],*finaltartstring;
	if(argc<2){printf("Uso: ./lsystem <arquivo_entrada> <arquivo_saida_ps> <arquivo_saida_turtle>");return ;}/* Verificação do numero de argumentos na chamada
	do programa */
	else{
	FILE* lsys=fopen(argv[1],"r");
	if(lsys == NULL){
   		printf("Nao foi possivel abrir o arquivo!");
   		return;
   	}
	while(varbreak==0 && fscanf(lsys,"%s",pal)== 1){
		// Leitura das variaveis angulo,order, rotate e da string axiom e tratamento
		if(strlen(pal)==5){
			if(strcmp(pal,"angle")==0){
				fscanf(lsys,"%d",&(angle));
			}
			else if(strcmp(pal,"order")==0 ){
				fscanf(lsys,"%d",&(order));
			}
			else if(strcmp(pal,"rotate")==0){
				fscanf(lsys,"%d",&(rotate));
			}	
			else if(strcmp(pal,"axiom")==0 ){
				varbreak=1;
				fscanf(lsys,"%s",axiom);
				prim=IniciaArv(axiom[0],1);
				arv=prim;
				for(i=1;i<strlen(axiom);i++){
					arv->irmao=IniciaArv(axiom[i],1);
					arv=arv->irmao;
				}
			}
		}
		}
	while(fscanf(lsys,"%s",pal)==1){
		// Leitura das regras e armazenamento das mesmas
		if(strcmp(pal,"=")==0){
			fscanf(lsys,"%s",pal);
			if(regras==NULL){regras=IniciaReg(pal1[0],pal);}
			else {
				regra=regras;
				while(regra->Prox!=NULL)regra=regra->Prox;
				regra->Prox=IniciaReg(pal1[0],pal);
			}
		}
		strcpy(pal1,pal);
		}
		printf("\n");
		// Aplicacao da lista de regras no axioma da arvore de acordo com a ordem de aplicacao
		for(i=0;i<order;i++){
			AplicaReg(prim,regras);
		}
		fclose(lsys);
		// Tratamento das demais partes como geração dos arquivos finais e liberação da memoria alocada.
		FILE* turtle=fopen(argv[3],"w");
		String* string1=NULL,*tc;
		ImprimeFolhaTurtle(prim,&string1);
		printf("\n");
		tc=string1;
		printf("\n");
		genps(angle,order,rotate,turtle,argv[2],string1);
		LimpaStr(string1);
		fclose(turtle);
		LimpaArv(prim);
		LimpaReg(regras);
			return ;
	}
}



static void preambulo( double angle, unsigned int order, double rotimage,const char *psfname )/* Função passada pelo professor para criação do preambulo do
arquivo postscript */
{
	ps = fopen( psfname, "w" );
	if( ps == NULL )	{
		fprintf(stderr,"Erro: Impossivel abrir arq de saida '%s'.\n", psfname );
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Gerando arquivo de saida PostScript '%s'.\n", psfname );
	// PS header
	fprintf(ps,"%%!PS-Adobe-2.0 EPSF-2.0\n");
	fprintf(ps,"%%%%BoundingBox: 0 0 1000 1000\n");
	fprintf(ps,"\n\n\n");
	fprintf(ps,"%% Preambulo\n\n");
	fprintf(ps,"\n");
	fprintf(ps,"/angle %.2lf def\n", angle);
	fprintf(ps,"/order %d def\n", order);
	fprintf(ps,"/rotateimage %.2lf def\n", rotimage);
	fprintf(ps,"\n");
	fprintf(ps,"/a { 360 angle div } def\n");

	fprintf(ps,"/scal { 2 order neg exp } def\t%% 1/2^(order)\n");
	fprintf(ps,"/sinv { 2 order exp } def\t%% 2^(order)\n");
	fprintf(ps,"\n");
	fprintf(ps,"/len 72 def\n");
	fprintf(ps,"\n");
	fprintf(ps,"\n");
	fprintf(ps,"/F { len 0 rlineto } def\n");
	fprintf(ps,"/G   { len 0 rmoveto } def\n");
	fprintf(ps,"/+ {a rotate} def\n");
	fprintf(ps,"/- {a neg rotate} def\n");
	fprintf(ps,"\n");
	fprintf(ps,"/S { gsave } def\n/R { stroke grestore } def\n");
	fprintf(ps,"\n");
	fprintf(ps,"/n {newpath} def\n");
	fprintf(ps,"/l {lineto} def\n");
	fprintf(ps,"/m {moveto} def\n");
	fprintf(ps,"/s {stroke} def\n");
	fprintf(ps,"\n");
	fprintf(ps,"/pageLetterCenter { 297.72 421.2 } def\n");
	fprintf(ps,"/linewidth 0.1 def\n");
	fprintf(ps,"\n");
	fprintf(ps,"gsave\n");
	fprintf(ps,"\n");
	fprintf(ps,"pageLetterCenter translate\n");
	fprintf(ps,"rotateimage rotate\n");
	fprintf(ps,"scal scal scale\n");
	fprintf(ps,"linewidth setlinewidth\n");
	fprintf(ps,"newpath 0 0 moveto\n");
}

void genps( double angle, unsigned int order, double rotimage,FILE* fturtle, const char *psfname ,String* string1)/* Função para criação final dos arquivos de
saida, foi passada pelo professor mas sofreu algumas modificações para se adequar ao trabalho */ 
{
	char c;
	String* tc=string1;
	preambulo( angle, order, rotimage, psfname );
	LinguaDeTartaruga(string1,ps,angle,0);
	while(tc!=NULL){
			fprintf(fturtle,"%c",tc->c);
			tc=tc->Prox;
		}
	fprintf(ps,"stroke\n\ngrestore\n\nshowpage\n");
	fprintf(ps,"quit\n");
	fclose( ps );
}

