//
// Created by jordao on 22/06/17.
//

#include "reverse_hfile.h"
#include <math.h>
#include "alphabet.h"
#include "search_rhf.h"

#define TAM_LINHA 20480

int h_f(char *s,int n){
    unsigned int h,c=n,i=1;
    while(h=*s++)
        c =(c<<5+c)+(h-i++)*i;
    return c%(n);
}
int cmp_w(const void *s1,const void *s2){
    Word* w1 = *(Word**)s1;
    Word* w2 = *(Word**)s2;
    return strcmp(w1->content,w2->content);
}
void print_lines(char* arq,List ocr){
	FILE* farq = fopen(arq,"r");
	char Line[TAM_LINHA];
	int i=1,line;
	while(ocr!=NULL && !feof(farq)){
		line = ocr->info;
		while(!feof(farq)){
			fgets(Line,TAM_LINHA-1,farq);
			i++;
			if(i-1==line){
				printf("%d %s",line,Line);
				ocr = ocr->next;
				break;
			}
		}
	}
	fclose(farq);
}
int main(int argc,char *argv[]){

	if(argc != 5)
	{
		printf ("./a.out Texto.txt Palavras_Chave.txt Alfabeto.txt opcao\n");
		return 1;
	}

	int option = atoi(argv[4]);
	FILE* text_file,*key_word_file,*alphabet_file;
	text_file = fopen(argv[1],"r");
	key_word_file = fopen(argv[2],"r");

	//Cria alfabeto
	typeAlphabet alphabet;
	create_alphabet(argv[3],alphabet);

    struct timeval inicio,final;
    double t;
    int n=0;


    char* pal= malloc(sizeof(char)*256);
    char* line = malloc(sizeof(char)*256);
	*line = '\0';

    while(fscanf(key_word_file,"%s",pal)==1)
	{
		n++;
	}
	fclose(key_word_file);
	*pal = '\0';

    Word* aux_word;

    n = (int)10*pow(n,0.6);

    RHF* invertido = new_rhf(n,n*1.43,&h_f);

    key_word_file = fopen(argv[2],"r");

    int i=1,i_l=1,j,k=0;


    while(!feof(key_word_file)){
        line = read_word(key_word_file,alphabet,&j);
        aux_word = new_word(256,line);
        insert_rhf(invertido,aux_word);
    }
    fclose(key_word_file);

    text_file = fopen(argv[1],"r");
	//Leitura do texto e associação da posição de cada uma das palavras do vocabulario
    do
    {
        pal = read_word(text_file,alphabet,&i_l);
        List ocr = new_list(i);
        if(i_l)i++;
        aux_word = new_word(256,pal);
        insert_ocrl(aux_word,ocr);
        Word* searched = search_rhf(invertido,aux_word,strcmp);
        if(searched!=NULL)
		{
			insert_rhf(invertido,aux_word);
		}
        *pal = '\0';
    }while(!feof(text_file));
	fclose(text_file);
	//Numero de linhas no Texto
	invertido->n_lines = i;

	// Impressão do indice remissivo
	if(option == 1)
	{
		Word* words[invertido->M];
		for(j=0;j<invertido->M;j++)
		{
			Word* aux = invertido->hash_v[j];
			while(aux!=NULL)
			{
				words[k] = aux;
				aux = aux->next;
				k++;
			}
		}

		printf("Indice Remissivo:\n");
		qsort(words,k,sizeof(Word*),cmp_w);
		for(j=0;j<k;j++)
		{
			print_word(words[j]);
			printf("\n");
		}
		return 0;
	}

	//Realiza Busca
	if(option!=2){
		return 1;
	}

    printf("BUSCA(CS-Case Sensitive):\n");
	int search_times;
	printf("Quantidade de buscas?\n");
	scanf("%d", &search_times);
	for(i=0;i<search_times;i++)
	{
		printf("Digite sua Busca:");
		scanf("\n%[^\n]",line);
		printf("Resultado da Busca:\n");
		Word* searched = search_query(line,alphabet,invertido);
		if(searched!=NULL){
			printf("%s:\n",searched->content);
			print_lines(argv[1],searched->ocrb);
		}
		else printf("%s",line);
		printf("\n\n");
	}
	return 0;
}


