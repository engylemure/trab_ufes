#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
void strlower(char *a){
	int i,j=strlen(a);
	for(i=0;i<j;i++){
		a[i]=tolower(a[i]);
	}
}
void scanstring(FILE *arq,char* nome){
  char a,i;
  for(i=0;i>=0;i++){
    fscanf(arq,"%c",&a);
    if(a=='\n'){nome[i]='\0';return;}
    else nome[i]=a;
  }
}
struct tipocasa{						//struct das casas, contendo id do consumidor, numero da casa e nome do consumidor
	int idConsumidor,Ncasa;
	float Consumo;
	char *NConsumidor;	
};
struct tiporua{							//struct das ruas, contendo nome da rua e celulas das casas
	char *NRua;
	CelulaCasa *Primeiro, *Ultimo;
};
struct tipobairro{						//struct dos bairos, contendo o nome do bairro e a celulas das casas
	char *NBairro;
	CelulaRua *Primeiro, *Ultimo;
};
struct tipocidade{						//struct da cidade, contendo o nome da cidade e celulas dos bairros
	char *NCidade;
	CelulaBairro *Primeiro, *Ultimo;
};
struct celulacasa{						//struct da celulas das casas, contendo um ponteiro de uma casa e da proxima casa
	Casa *casa;
	CelulaCasa* Prox;
};
struct celularua{						//struct das celulas das ruas, contendo o id da rua, um ponteiro de uma celula e um ponteiro da proxima celula
	int idRua;
	Rua *rua;
	CelulaRua* Prox;
};
struct celulabairro{						//struct das celulas dos bairros, contendo id do bairro, um ponteiro de um celula e da proxima celula
	int idBairro;
	Bairro *bairro;
	CelulaBairro* Prox;
};
struct celulacidade{						//struct das celulas das cidades, contendo ponteiro de uma cidade e o ponteiro da proxima celula
	Cidade *cidade;
	CelulaCidade* Prox;
};	
Casa* iniciacasa(){						//ponteiro para cada casa
	Casa *casa=malloc(sizeof(Casa));
	casa->idConsumidor=0;
	casa->Ncasa=0;
	casa->Consumo=0;
	return casa;
}
CelulaCasa* iniciacelcasa(){					//ponteiro para celula de cada casa
	CelulaCasa* novo = (CelulaCasa*) malloc(sizeof(CelulaCasa));
	novo->casa=iniciacasa();
	novo->Prox=NULL;
	return(novo);
}
Cidade* iniciacid(){						//ponteiro para cada cidade
	Cidade* cidade=malloc(sizeof(Cidade));
	cidade->Primeiro=NULL;
	cidade->Ultimo=NULL;
	return cidade;
};
CelulaCidade* iniciacelcid(){					//ponteiro para celula de cidade
	CelulaCidade* novo = (CelulaCidade*) malloc(sizeof(CelulaCidade));
	novo->cidade=iniciacid();
	novo->Prox=NULL;
	return(novo);
}
Bairro* iniciabairro(){						//ponteiro para cada bairro
	Bairro* bairro=malloc(sizeof(Bairro));
	bairro->Primeiro=NULL;
	bairro->Ultimo=NULL;
	return bairro;
};
CelulaBairro* iniciacelbairro(){				//ponteiro para celula de bairro
	CelulaBairro* novo = (CelulaBairro*)malloc(sizeof(CelulaBairro));
	novo->idBairro=0;
	novo->bairro=iniciabairro();
	novo->Prox=NULL;
	return(novo);
}
Rua* iniciarua(){						//ponteiro para cada rua
	Rua* rua=(Rua*)malloc(sizeof(Rua));
	rua->Primeiro=NULL;
	rua->Ultimo=NULL;
	return rua;
};
CelulaRua* iniciacelrua(){					//ponteiro para celula de rua
	CelulaRua* novo = (CelulaRua*)malloc(sizeof(CelulaRua));
	novo->idRua=0;
	novo->rua=iniciarua();
	novo->Prox=NULL;
	return(novo);
}
void imprimecasa(Cidade* x,int a, int b,int idc,FILE *saida){
	if(x->Primeiro==NULL){fprintf(saida,"Cidade Vazia\n"); return;}				//ira veirificar se a variavel Cidade* x é nula, se for irá printar cidade vazia
	else {
	CelulaBairro* p=x->Primeiro;								//celulabairro recebe o ponteiro do primeiro elemento dos bairros
	while( p!=NULL && p->idBairro!=a){							//verifica se existe um bairro com o id designado
	p=p->Prox;
	}
	if(p==NULL){fprintf(saida,"Bairro não Encontrado\n"); return;}				//se o id do bairro não for encontrado, será printado bairro não encontrado
	else {
		if(p->bairro->Primeiro==NULL){fprintf(saida,"Bairro Vazio\n"); return;}		//se o id for encontrado mas se a celula de casas for nula, não teria nenhuma rua cadastrada nesse bairro
		else {										//caso bairro for encontrado e não ser nulo, logo ruas foram encontradas nesse bairro
			CelulaRua* pr=p->bairro->Primeiro;					//celularua recebe o ponteiro do primeiro elemento das ruas
			while(pr!=NULL && pr->idRua!=b){					//verifica se existe uma rua com o id designado
			pr=pr->Prox;
			}
			if(pr==NULL){fprintf(saida,"Rua não encontrada\n");return;}		//se o id da rua não for encontrada, será printado rua não encontrada
			else {
				CelulaCasa* pc = pr->rua->Primeiro;				//caso a rua  for encontrada e não ser nula, logo casas foram encontradas nessa rua
				while (pc != NULL && pc->casa->idConsumidor != idc)		//verifica se existe uma casa com o id designado na rua
				{ 
				pc = pc->Prox;}
				if(pc==NULL){fprintf(saida,"Casa não encontrada\n");return;}	//caso a casa não for encontrada, logo a casa não existe
				fprintf(saida,"Id do Bairro:	%d\n",a);			//se a casa for encontrada será printado o id do bairro
				fprintf(saida,"Id da Rua:	%d\n",b);			//se a casa for encontrada será printado o id da rua
			    fprintf(saida,"Id do Consumidor:	%d\n",pc->casa->idConsumidor);	//se a casa for encontrada será printado o id do consumidor
			    fprintf(saida,"Numero da Casa:		%d\n",pc->casa->Ncasa);	//se a casa for encontrada será printado o numero da casa
			    fprintf(saida,"Consumo:	%.2f KWh\n ",pc->casa->Consumo);	//se a casa for encontrada será printado o consumo
			    fprintf(saida,"Nome do Consumidor:	%s\n",pc->casa->NConsumidor);	//se a casa for encontrada será printado o nome do consumidor
			}
		}
	  }
	}
}
void FREE(void *x){
	free(x);
}
void IncluirCasa(Cidade* x,int a, int b,int idc, int nc, char *nome,FILE *saida){
	if(x->Primeiro==NULL){fprintf(saida,"ERRO:Casa nao incluida. Bairro ID: %d Rua ID: %d Id Consumidor: %d Numero Casa: %d Nome do Consumidor: %s\n",a,b,idc,nc,nome); return;}	//verifica se existe uma cidade, caso não exista será printado um ERROR
	else {
	CelulaBairro* p=x->Primeiro;
	while(p!=NULL && p->idBairro!=a){
	p=p->Prox;
	}
	if(p==NULL){fprintf(saida,"ERRO:Casa nao incluida. Bairro ID: %d Rua ID: %d Id Consumidor: %d Numero Casa: %d Nome do Consumidor: %s\n",a,b,idc,nc,nome); return;}	//verifica se existe um bairro, caso não exista será printado um ERROR para a casa não incluida
	else {
		if(p->bairro->Primeiro==NULL){fprintf(saida,"ERRO:Casa nao incluida. Bairro ID: %d Rua ID: %d Id Consumidor: %d Numero Casa: %d Nome do Consumidor: %s\n",a,b,idc,nc,nome); return;}		//verifica se existe um bairro com o id fornecido, caso não exista será printado um ERROR para a casa não incluida
		else {
			CelulaRua* pr=p->bairro->Primeiro;
			while(pr!=NULL && pr->idRua!=b){
			pr=pr->Prox;
			}
			if(pr==NULL){fprintf(saida,"ERRO:Casa nao incluida. Bairro ID: %d Rua ID: %d Id Consumidor: %d Numero Casa: %d Nome do Consumidor: %s\n",a,b,idc,nc,nome);return;}		//verifica se existe uma rua, caso não exista será printado um ERROR para a casa não incluida
			else {
			    Rua* pontlistacasa=pr->rua;
			    CelulaCasa* novo = iniciacelcasa();
			    if (pontlistacasa->Ultimo == NULL)
			    pontlistacasa->Primeiro = pontlistacasa->Ultimo = novo;
			    else	
			    {	
			    	CelulaCasa* ant = NULL;
					CelulaCasa* pc = pr->rua->Primeiro;
					while (pc != NULL && pc->casa->idConsumidor != idc && pc->casa->Ncasa != nc && pc->casa->Ncasa < nc)
					{ ant = pc;
					pc = pc->Prox;}
					if(pc==NULL){
						pontlistacasa->Ultimo->Prox = novo;
						pontlistacasa->Ultimo = novo;
						novo->Prox =NULL;
					}
					else if(pc->casa->idConsumidor==idc){fprintf(saida,"ERRO:Casa nao incluida. Bairro ID: %d Rua ID: %d Id Consumidor: %d Numero Casa: %d Nome do Consumidor: %s\n",a,b,idc,nc,nome);free(novo->casa);free(novo);return;}		//verifica se existe uma rua com o id designado, caso não exista será printado um ERROR para a casa não incluida
					else if(pc==pontlistacasa->Primeiro){
						ant=pc;
						pontlistacasa->Primeiro = novo;
						novo->Prox = ant;
					}
					else{
						ant->Prox = novo;
						novo->Prox=pc;
					}
			    }
			    fprintf(saida,"Casa incluida com sucesso. Bairro ID: %d Rua ID: %d Id Consumidor: %d Numero Casa: %d Nome do Consumidor: %s\n",a,b,idc,nc,nome);
			    novo->casa->idConsumidor=idc;
			    novo->casa->Ncasa=nc;
			    novo->casa->Consumo=0;
			    novo->casa->NConsumidor=malloc((strlen(nome)+1)*sizeof(char));
			    strcpy(novo->casa->NConsumidor,nome);
			}
		}
	  }
	}
}
void IncluirRua(Cidade* x,int a, int b,char *nome,FILE *saida){
	if(x->Primeiro==NULL){fprintf(saida,"ERRO: Rua nao incluida.Bairro ID: %d Rua ID: %d Rua Nome: %s\n",a,b,nome); return;}	//verifica se existe uma cidade, caso não exista será printado um ERROR para a rua não incluida
	else {
	CelulaBairro* p=x->Primeiro;
	while(p!=NULL && p->idBairro!=a){
	p=p->Prox;
	}	
	if(p==NULL){fprintf(saida,"ERRO: Rua nao incluida.Bairro ID: %d Rua ID: %d Rua Nome: %s\n",a,b,nome); return;}		//verifica se existe um bairro com o id fornecido, caso não exista será printado um ERROR para a rua não incluida
	else {
			    Bairro* pontlistabairro=p->bairro;
			    CelulaRua* novo = iniciacelrua();
			    if (pontlistabairro->Ultimo == NULL)
			    pontlistabairro->Primeiro = pontlistabairro->Ultimo = novo;
			    else	
			    {	
				    CelulaRua* ant = NULL;
					CelulaRua* pr = p->bairro->Primeiro;
						while (pr != NULL && pr->idRua != b && pr->idRua <b)
						{
						ant = pr;
						pr = pr->Prox;}
						if(pr==NULL){
							pontlistabairro->Ultimo->Prox = novo;
							pontlistabairro->Ultimo = novo;
							novo->Prox = NULL;
						}
						else if(pr->idRua==b){fprintf(saida,"ERRO: Rua nao incluida.Bairro ID: %d Rua ID: %d Rua Nome: %s\n",a,b,nome);free(novo->rua);free(novo);return;}		//verifica se ja existe uma rua com o id fornecido, caso exista será printado um ERROR para a rua não incluida
						else if(pr==p->bairro->Primeiro){
							ant=pr;
							pontlistabairro->Primeiro = novo;
							novo->Prox = ant;
						}
						else {
							ant->Prox = novo;
							novo->Prox= pr;
						}
			    }
			    novo->idRua = b;
			    novo->rua->NRua=malloc((strlen(nome)+1)*sizeof(char));
			    strcpy(novo->rua->NRua,nome);
			    fprintf(saida,"Rua incluida com sucesso. Bairro ID: %d Rua ID: %d Rua Nome: %s\n",a,b,nome);
			}
		}
}
void IncluirBairro(Cidade* x,int a, char *nome,FILE *saida){
				CelulaBairro* novo=iniciacelbairro();
			    if (x->Ultimo == NULL)
			    x->Primeiro = x->Ultimo = novo;
			    else	
			    {
			    CelulaBairro* p = x->Primeiro;
				CelulaBairro* ant = NULL;
				while (p != NULL && p->idBairro != a && p->idBairro < a)
					   { ant = p;
					     p = p->Prox;}
					     if(p==NULL){
					     	x->Ultimo->Prox = novo;
					     	x->Ultimo = novo;
					     	novo->Prox = NULL; 
					     }
					     else if(p->idBairro==a){fprintf(saida,"ERRO: Bairro nao incluido. Bairro ID: %d Bairro Nome: %s\n",a,nome);free(novo->bairro);free(novo);return;}	//verifica se existe um bairro com id fornecido, caso exista será printado um ERROR para a rua não incluida
					     else if(p==x->Primeiro){
					     	ant=p;
					     	x->Primeiro = novo;
					     	novo->Prox = ant;
					     } 
					     else {
					     	ant->Prox = novo;
					     	novo->Prox = p;
					     }
			    }
			    fprintf(saida,"Bairro incluido com sucesso. Bairro ID: %d Bairro Nome: %s\n",a,nome);
			    novo->idBairro = a;
			    novo->bairro->NBairro=malloc((strlen(nome)+1)*sizeof(char));
			    strcpy(novo->bairro->NBairro,nome);
}
void Vazio(void *x){
	if(x==NULL)printf("SIM\n");
	else printf("NAO\n");
}
void FREECASA(CelulaCasa* x){			//quando uma casa é eliminada ess afuncao elimina a memoria usada por ela
	if(x!=NULL){
		FREE(x->casa->NConsumidor);
		FREE(x->casa);
		FREE(x);
	}
}
void FREEBAIRRO(CelulaBairro* x){		//quando um bairro é eliminado essa afuncao elimina a memoria usada por ele
	if(x!=NULL){
		if(x->bairro!=NULL)
		if(x->bairro->Primeiro!=NULL){
		CelulaRua* ant=NULL;
		CelulaRua* cr=x->bairro->Primeiro;
		while(cr!=NULL){
			ant=cr;
			cr=cr->Prox;
			FREERUA(ant);
		}	
		}
		FREE(x->bairro->NBairro);
		FREE(x->bairro);
		FREE(x);
	}
}
void FREERUA(CelulaRua* x){			//quando uma rua é eliminada essa afuncao elimina a memoria usada por ela
	if(x!=NULL){
		if(x->rua!=NULL)
		if(x->rua->Primeiro!=NULL){
		CelulaCasa* ant=NULL;
		CelulaCasa* cc=x->rua->Primeiro;
		while(cc!=NULL){
			ant=cc;
			cc=cc->Prox;
			FREECASA(ant);
		}
		}
		FREE(x->rua->NRua);
		FREE(x->rua);
		FREE(x);
	}
}
void FREECIDADE(Cidade* x){			//quando uma cidade é eliminada ess afuncao elimina a memoria usada por ela
	if(x!=NULL){
		if(x->Primeiro!=NULL){
			CelulaBairro* ant=NULL;
			CelulaBairro* cb=x->Primeiro;
			while(cb!=NULL){
				ant=cb;
				cb=cb->Prox;
				FREEBAIRRO(ant);
			}
		}
			free(x);
		}
}
void EliminarBairro(Cidade* x,int a,FILE *saida){
		if(x->Primeiro==NULL){fprintf(saida,"ERRO: Bairro nao eliminado.Bairro ID: %d\n",a); return;}	//verifica se existe uma cidade, caso não exista será printado um ERROR para o bairo não eliminado
		else {
		CelulaBairro* ant=NULL;
		CelulaBairro* p=x->Primeiro;

		while(p!=NULL && p->idBairro!=a){
		ant=p;
		p=p->Prox;
		}
		if(p==NULL){fprintf(saida,"ERRO: Bairro nao eliminado.Bairro ID: %d\n",a); return;}	//verifica se existe o bairro, caso não exista será printado um ERROR para o airo não eliminado
		else {
				fprintf(saida,"Bairro Eliminado com Sucesso.Bairro ID: %d\n",a);
				if (p == x->Primeiro && p == x->Ultimo){
			    x->Primeiro = x->Ultimo = NULL;
			    FREEBAIRRO(p);
				return; }
				if (p == x->Ultimo){
				x->Ultimo = ant; ant->Prox = NULL; FREEBAIRRO(p); return;}
				if (p == x->Primeiro){
					x->Primeiro=p->Prox;
				}
				else{
				ant->Prox = p->Prox;
				}
				FREEBAIRRO(p);		
		}
	}
}
void EliminarRua(Cidade* x,int a, int b,FILE *saida){
	if(x->Primeiro==NULL){fprintf(saida,"ERRO: Rua nao Eliminada. Bairro id: %d Rua id: %d \n",a,b); return;}	//verifica se existe uma cidade, caso não exista será printado um ERROR para a rua não eliminada
	else {
	CelulaBairro* p=x->Primeiro;
	while(p!=NULL && p->idBairro!=a){
	p=p->Prox;
	}
	if(p==NULL){fprintf(saida,"ERRO: Rua nao Eliminada. Bairro id: %d Rua id: %d \n",a,b); return;}		//verifica se existe um bairro, caso não exista será printado um ERROR para a rua não eliminada
	else {
		if(p->bairro->Primeiro==NULL){fprintf(saida,"ERRO: Rua nao Eliminada. Bairro id: %d Rua id: %d \n",a,b); return;}
		else {
			CelulaRua* ant=NULL;
			CelulaRua* pr=p->bairro->Primeiro;
			CelulaRua* prox=p->bairro->Primeiro->Prox;
			while(pr!=NULL && pr->idRua!=b){
			ant=pr;
			pr=pr->Prox;

			}
			if(pr==NULL){fprintf(saida,"ERRO: Rua nao Eliminada. Bairro id: %d Rua id: %d \n",a,b);return;}	//verifica se existe uma rua com id designado, caso não exista será printado um ERROR para a rua não eliminada
			else {
				fprintf(saida,"Rua Eliminada com Sucesso. Bairro id: %d Rua id: %d \n",a,b);
				if (pr == p->bairro->Primeiro && pr == p->bairro->Ultimo){
			    p->bairro->Primeiro = p->bairro->Ultimo = NULL;
			    FREERUA(pr);
				return; }
				if (pr == p->bairro->Ultimo){
				p->bairro->Ultimo = ant; ant->Prox = NULL; FREERUA (pr); return;}
				if (pr == p->bairro->Primeiro){
					p->bairro->Primeiro=pr->Prox;
				}
				else{
				ant->Prox = pr->Prox;
			}
				FREERUA(pr);
		}
	  }
	}
}
}
void EliminarCasa(Cidade* x,int a, int b,int idc,FILE *saida){
	if(x->Primeiro==NULL){fprintf(saida,"ERRO: Casa nao eliminada. Bairro ID: %d Rua ID: %d Consumidor ID: %d\n",a,b,idc); return;}		//verifica se existe uma cidade, caso não exista será printado um ERROR para a casa não eliminada
	else {
	CelulaBairro* p=x->Primeiro;
	while(p!=NULL && p->idBairro!=a ){
	p=p->Prox;
	}
	if(p==NULL){fprintf(saida,"ERRO: Casa nao eliminada. Bairro ID: %d Rua ID: %d Consumidor ID: %d\n",a,b,idc); return;}		//verifica se existe um bairro, caso não exista será printado um ERROR para a casa não eliminada
	else {
		if(p->bairro->Primeiro==NULL){fprintf(saida,"ERRO: Casa nao eliminada. Bairro ID: %d Rua ID: %d Consumidor ID: %d\n",a,b,idc); return;}		//verifica se existe um bairro com o id designado, caso não exista será printado um ERROR para a casa não eliminada
		else {
			CelulaRua* pr=p->bairro->Primeiro;
			while(pr!=NULL && pr->idRua!=b){
			pr=pr->Prox;
			}
			if(pr==NULL){fprintf(saida,"ERRO: Casa nao eliminada. Bairro ID: %d Rua ID: %d Consumidor ID: %d\n",a,b,idc);return;}	//verifica se existe uma rua, caso não exista será printado um ERROR para a casa não eliminada
			else {
			    CelulaCasa* ant = NULL;
				CelulaCasa* pc = pr->rua->Primeiro;
				while (pc != NULL && pc->casa->idConsumidor != idc)
				{ ant = pc;
				pc = pc->Prox;}
				if (pc == NULL){fprintf(saida,"ERRO: Casa nao eliminada. Bairro ID: %d Rua ID: %d Consumidor ID: %d\n",a,b,idc);return;}	//verifica se existe uma rua com o id designado, caso não exista será printado um ERROR para a casa não eliminada
				fprintf(saida,"Casa eliminada com sucesso. Bairro ID: %d Rua ID: %d Consumidor ID: %d\n",a,b,idc);	   	
				if (pc == pr->rua->Primeiro && pc == pr->rua->Ultimo){
				FREECASA (pc);
			    pr->rua->Primeiro = pr->rua->Ultimo = NULL;
				return; }
				if (pc == pr->rua->Ultimo){
				pr->rua->Ultimo = ant; ant->Prox = NULL; FREECASA (pc); return;}
				if (pc == pr->rua->Primeiro) 
				pr->rua->Primeiro = pc->Prox;
				else
				ant->Prox = pc->Prox;
				FREECASA(pc);
			}
		}
	  }
	}
}
void Consumir(Cidade* x,int a, int b,int idc,float cons,FILE *saida){
	if(x->Primeiro==NULL){fprintf(saida,"ERRO: Consumo não atualizado. Bairro ID: %d, Rua ID: %d, Casa IDC: %d, Consumo Inserido: %.2f\n",a,b,idc,cons); return;} 	//verifica se existe uma cidade, caso não existir será printado um ERROR de consumo nao atualizado
	else {
	CelulaBairro* p=x->Primeiro;
	while( p!=NULL && p->idBairro!=a){
	p=p->Prox; 
	}
	if(p==NULL){fprintf(saida,"ERRO: Consumo não atualizado. Bairro ID: %d, Rua ID: %d, Casa IDC: %d, Consumo Inserido: %.2f\n",a,b,idc,cons); return;}	//verifica se existe um bairro, caso não existir será printado um ERROR de consumo nao atualizado
	else {
		if(p->bairro->Primeiro==NULL){fprintf(saida,"ERRO: Consumo não atualizado. Bairro ID: %d, Rua ID: %d, Casa IDC: %d, Consumo Inserido: %.2f\n",a,b,idc,cons); return;}	//verifica se existe o bairro designado, caso não existir será printado um ERROR de consumo nao atualizado
		else {
			CelulaRua* pr=p->bairro->Primeiro;
			while(pr!=NULL && pr->idRua!=b){
			pr=pr->Prox;
			}
			if(pr==NULL){fprintf(saida,"ERRO: Consumo não atualizado. Bairro ID: %d, Rua ID: %d, Casa IDC: %d, Consumo Inserido: %.2f\n",a,b,idc,cons);return;}		//verifica se existe uma rua, caso não existir será printado um ERROR de consumo nao atualizado
			else {
			    CelulaCasa* ant = NULL;
				CelulaCasa* pc = pr->rua->Primeiro;
				while (pc != NULL && pc->casa->idConsumidor != idc)
				{ 
				ant = pc;
				pc = pc->Prox;
				}
				if (pc == NULL){fprintf(saida,"ERRO: Consumo não atualizado. Bairro ID: %d, Rua ID: %d, Casa IDC: %d, Consumo Inserido: %.2f\n",a,b,idc,cons);return;}	//verifica se existe a rua designada, caso não existir será printado um ERROR de consumo nao atualizado	   	
				pc->casa->Consumo+=cons;
				fprintf(saida,"Consumo Atualizado.Bairro ID: %d, Rua ID: %d, Casa IDC: %d, Consumo Inserido: %.2f\n",a,b,idc,cons);
			}
		}
	  }
	}
}
float medirConsumoCasa(Cidade* x,int a, int b, int idc,FILE *saida){
	float consumototal=0;
	if(x->Primeiro==NULL){fprintf(saida,"Cidade Vazia\n"); return 0;}	//verifica se existe alguma informação na cidade designada
	else {
	CelulaBairro* p=x->Primeiro;
	while(p!=NULL && p->idBairro!=a){
	p=p->Prox;
	}
	if(p==NULL){fprintf(saida,"Bairro não Encontrado\n"); return 0;}	//verifica se existe o bairro designado
	else {
		if(p->bairro->Primeiro==NULL){fprintf(saida,"Bairro Vazio\n"); return 0;}	//verifica se existe uma rua no bairro
		else {
			CelulaRua* pr=p->bairro->Primeiro;
			while(pr!=NULL && pr->idRua!=b){
			pr=pr->Prox;
			}
			if(pr==NULL){fprintf(saida,"Rua não encontrada\n");return 0;}		//verifica se existe a rua designada no bairro
			else {
			    CelulaCasa* ant = NULL;
				CelulaCasa* pc = pr->rua->Primeiro;
				while (pc != NULL && pc->casa->idConsumidor != idc)
				{ 
				fprintf(saida,"!!COns ID\n%d\n\n",	pc->casa->idConsumidor);		
				ant = pc;
				pc = pc->Prox;}
				if (pc == NULL || pc->casa->idConsumidor==0){fprintf(saida,"Casa não existe.!!\n");return 0;}	//verifica se existe a casa na rua designada	   	
				consumototal+=pc->casa->Consumo;
				return (consumototal);
			}
		}
	  }
	}
}
float medirConsumoRua(Cidade* x, int a, int b,FILE *saida){
		float consumototal=0;
		if(x->Primeiro==NULL){fprintf(saida,"Cidade Vazia\n"); return 0;}		//verifica se existe alguma informação na cidade designada
		else {
		CelulaBairro* p=x->Primeiro;
		while( p!=NULL && p->idBairro!=a){
		p=p->Prox;
		}
		if(p==NULL){fprintf(saida,"Bairro não Encontrado\n"); return 0;}	//verifica se existe o bairro designado
		else {
			if(p->bairro->Primeiro==NULL){fprintf(saida,"Bairro Vazio\n"); return 0;}	//verifica se existe alguma informaçao no bairro designado
			else {
				CelulaRua* pr=p->bairro->Primeiro;
				while(pr!=NULL && pr->idRua!=b){
				pr=pr->Prox;
				}
				if(pr==NULL){fprintf(saida,"Rua não encontrada\n");return 0;}	//verifica se existe a rua no bairro
				else {
					CelulaCasa* ant = NULL;
					CelulaCasa* pc = pr->rua->Primeiro;
					while (pc != NULL)
					{ 
						consumototal+=pc->casa->Consumo;						
						ant = pc;
						pc = pc->Prox;
						
					}	   	
					return (consumototal);
				}
			}
		  }
		}
}

float medirConsumoBairro(Cidade* x, int a,FILE *saida){
		float consumototal=0;
		if(x->Primeiro==NULL){ return 0;}	//verifica se existe alguma informação na cidade designada, caso nao existir retorna 0
		else {
		CelulaBairro* p=x->Primeiro;
		while(p!=NULL && p->idBairro!=a){
		p=p->Prox;
		}
		if(p==NULL){ return 0;}			//verifica se existe alguma informação no bairro designado, caso nao existir retorna 0
		else {
			if(p->bairro->Primeiro==NULL){ return 0;}
			else {
				CelulaRua* ant = NULL;
				CelulaRua* pr=p->bairro->Primeiro;
				while(pr!=NULL){
				ant=pr;
				CelulaCasa* ant1 = NULL;
					CelulaCasa* pc = pr->rua->Primeiro;
					while (pc != NULL)
					{ 
						consumototal+=pc->casa->Consumo;						
						ant1 = pc;
						pc = pc->Prox;
					}
				pr=pr->Prox;
				}	   	
					return (consumototal);
				}
			}
		  }
}
float medirConsumoCidade(Cidade *x,FILE *saida){
	float consumototal=0;
	if(x->Primeiro==NULL){ return 0;}	//verifica se existe alguma informação na cidade designada, caso nao existir retorna 0
		else {
		CelulaBairro* p=x->Primeiro;
		while(p!=NULL){
		if(p!=NULL){
			if(p->bairro->Primeiro==NULL){ return 0;}	//verifica se existe alguma informação no bairro designado, caso nao existir retorna 0
			else {
				CelulaRua* ant = NULL;
				CelulaRua* pr=p->bairro->Primeiro;
				while(pr!=NULL){
				ant=pr;
				CelulaCasa* ant1 = NULL;
					CelulaCasa* pc = pr->rua->Primeiro;
					while (pc != NULL)
					{ 
						consumototal+=pc->casa->Consumo;						
						ant1 = pc;
						pc = pc->Prox;
					}
				pr=pr->Prox;
				}	   	
				
				}
			}
			p=p->Prox;
		}
		return (consumototal);
		  }
}
void programa(FILE *arq,char *nome,Cidade *x){
	char unid[20],funcao[20],Nome[150];
	int uni,fun,idb,idr,idc,nc;
	float cons;
	FILE *saida= fopen("protocolo_saida.txt","w");
	printf("Abrindo arquivo de saida 'protocolo_saida.txt'...\n"); 
	arq = fopen(nome, "r");
	if(arq == NULL){
			fprintf(saida,"Erro, nao foi possivel abrir o arquivo\n");
			fclose(saida);
			return;
			}
	else{
			while( (fscanf(arq,"%s", unid))!=EOF ){
				if(strcmp(unid,"bairro")==0)uni=1;
				else if(strcmp(unid,"rua")==0 )uni=2;
				else if(strcmp(unid,"casa")==0 )uni=3;
				fscanf(arq,"%s",funcao);
				if(strcmp(funcao,"incluir")==0)fun=1;
				else if(strcmp(funcao,"eliminar")==0)fun=2;
				else if(strcmp(funcao,"medir")==0)fun=3;
				else if(strcmp(funcao,"consumir")==0)fun=4;
				switch(uni){
				case 1: switch(fun){
								case 1: 
									fscanf(arq,"%d",&idb);
									scanstring(arq,Nome);
									IncluirBairro(x,idb,Nome,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %s'\n",unid,funcao,uni,fun,idb,Nome);break;
								case 2:
									fscanf(arq,"%d",&idb);
									EliminarBairro(x,idb,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %s'\n",unid,funcao,uni,fun,idb,Nome);break;
								case 3:
									fscanf(arq,"%d",&idb);
									medirConsumoBairro(x,idb,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %s'\n",unid,funcao,uni,fun,idb,Nome);break;
								}break;
				case 2: switch(fun){
							 case 1:
							 fscanf(arq,"%d %d",&idb,&idr);
							 scanstring(arq,Nome);
							 IncluirRua(x,idb,idr,Nome,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %d %s'\n",unid,funcao,uni,fun,idb,idr,Nome);break;
							 case 2:
							 fscanf(arq,"%d %d",&idb,&idr);
							 EliminarRua(x,idb,idr,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %d %s'\n",unid,funcao,uni,fun,idb,idr,Nome);break;
							 case 3:
							 fscanf(arq,"%d %d",&idb,&idr);
							 medirConsumoRua(x,idb,idr,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %d %s'\n",unid,funcao,uni,fun,idb,idr,Nome);break;
							 }break;
				case 3: switch(fun){
							  case 1:
							  fscanf(arq,"%d %d %d %d",&idb,&idr,&idc,&nc);
							  scanstring(arq,Nome);
							  IncluirCasa(x,idb,idr,idc,nc,Nome,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %d %d %d %s'\n",unid,funcao,uni,fun,idb,idr,idc,nc,Nome);break;
							  case 2:
							  fscanf(arq,"%d %d %d",&idb,&idr,&idc);
							  EliminarCasa(x,idb,idr,idc,saida);break;	
							  case 4:
							  fscanf(arq,"%d %d %d %f",&idb,&idr,&idc,&cons);
							  Consumir(x,idb,idr,idc,cons,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %d %d %f '\n",unid,funcao,uni,fun,idb,idr,idc,cons);break;
							  case 3:
							  fscanf(arq,"%d %d %d",&idb,&idr,&idc);
							  imprimecasa(x,idb,idr,idc,saida);printf("infoComando> acao= %s %s u= %d c= %d pstr=' %d %d %d'\n",unid,funcao,uni,fun,idb,idr,idc);break;
							  }break;
							}
						}
					}
					ImprimeCidade(x,saida);		
					fclose(arq);
					printf("Fechando arquivo de saida 'protocolo_saida.txt'...\n");
					fclose(saida);
}
void ImprimeCidade(Cidade *x,FILE *saida){//Função Para a impressão dos elementos contidos na cidade em um arquivo e no terminal.
	CelulaBairro *p=x->Primeiro;
					while(p!=NULL){
					fprintf(saida,"Id do Bairro: %d , Nome do Bairro: %s \n",p->idBairro,p->bairro->NBairro);
					printf("Id do Bairro: %d , Nome do Bairro: %s \n",p->idBairro,p->bairro->NBairro);
					CelulaRua *pr=p->bairro->Primeiro;
					while(pr!=NULL){
						fprintf(saida,"\tId da Rua: %d , Nome da Rua: %s \n",pr->idRua,pr->rua->NRua);
						printf("\tId da Rua: %d , Nome da Rua: %s \n",pr->idRua,pr->rua->NRua);
						CelulaCasa *pc=pr->rua->Primeiro;
						while(pc!=NULL){
							fprintf(saida,"\t\tId do Consumidor: %d, Numero da Casa: %d\n\t\tNome do Consumidor: %s, Consumo: %f KWh\n\n",pc->casa->idConsumidor,pc->casa->Ncasa,pc->casa->NConsumidor,pc->casa->Consumo);
							printf("\t\tId do Consumidor: %d, Numero da Casa: %d\n\t\tNome do Consumidor: %s, Consumo: %f KWh\n\n",pc->casa->idConsumidor,pc->casa->Ncasa,pc->casa->NConsumidor,pc->casa->Consumo);
							pc=pc->Prox;
						}
						pr=pr->Prox;
					}	
					p=p->Prox;
					printf("\n");
					}
}