#include <stdio.h>
#include "lista.h"
#include <string.h>
int main(int argc,char **argv){
	Cidade *x;
	int i;
	x=iniciacid();
	FILE *arq;
	if(argv[1]!=NULL){
	programa(arq,argv[1],x);
	printf("Memoria liberada e Programa encerrado com sucesso.\n");
	}
	else printf("Arquivo a ser utilizado na inicialização do programa não existe.\n");
	FREECIDADE(x);
	return 0;
}

