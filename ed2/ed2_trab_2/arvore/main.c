#include "btree_unb.h"
#include "word_struct.h"
#include "alphabet.h"
#include <string.h>

#define TAM_PALAVRA 256
#define TAM_LINHA 20480
#define MAX_LINHAS 99999999

void imprime_linhas(int* imprime, char* arq, int qtd_pal)
{
	//Abre texto para exibir conteudo das linhas
	FILE* f_texto = fopen(arq,"r");

	char linha[TAM_LINHA];

    //imprime linhas em comum
    int j=1;
	while(!feof(f_texto))
	{
		
		//fscanf(f_texto, "%[^\n]\n", linha);
		fgets(linha, TAM_LINHA-1, f_texto);

        if(imprime[j]==qtd_pal)
			printf("%d %s", j, linha);

		j++;	
	}

	fclose(f_texto);
}

//Nao eh case sensitive

int main(int argc,char *argv[])
{
    if(argc != 5)
    {
        printf ("./a.out Texto.txt Palavras_Chave.txt Alfabeto.txt opcao\n");
        return 1;
    }

    typeAlphabet alphabet;
    create_alphabet(argv[3],alphabet);

    char pal[TAM_PALAVRA];

    *pal = '\0';

    //Inicializa vocabulario
    FILE* f_vocabulario = fopen(argv[2],"r");

    //Uma palavra por linha
    fscanf(f_vocabulario,"%[^\n]\n",pal);
    Word* wrd = new_word(pal);

    BinTree* btree = new_BinTree(wrd); //raiz

    while(fscanf(f_vocabulario,"%[^\n]\n",pal)!=EOF)
    {
        wrd = new_word(pal);

        insert_BinTree_init(btree, new_BinTree(wrd), cmp_word);
    }

    fclose(f_vocabulario);


    //Retira palavras do texto e as adiciona na arvore
    FILE* f_texto = fopen(argv[1],"r");

    int i=1;
    short have_in_alphabet = false;
    char letra;
    int is_end = 0;

    *pal = '\0';
    do
    {
        is_end = (fscanf(f_texto,"%c",&letra) != 1);
        if(alphabet[letra])
        {
            sprintf(pal+strlen(pal),"%c",letra);
            have_in_alphabet = true;
        }
        else if(have_in_alphabet)
        {
            //add palavra na arvore

            List ocr = new_list(i);
            wrd = new_word(pal);
            wrd->ocrb=ocr;
            wrd->ocrf=ocr;
            //printf("::%s", pal);
            insertLine_BinTree(btree, new_BinTree(wrd), cmp_word);
            //desalocar wrd

            have_in_alphabet = false;
            *pal = '\0';
        }

        //Atualiza linha atual
        if(letra=='\n')i++;

        if(is_end){
            List ocr = new_list(i);
            wrd = new_word(pal);
            wrd->ocrb=ocr;
            wrd->ocrf=ocr;

            insertLine_BinTree(btree, new_BinTree(wrd), cmp_word);
            //desalocar wrd

            have_in_alphabet = false;
            *pal = '\0';
        }

    }while(!is_end);

    fclose(f_texto);

    //Imprime Indice Remissivo
    if(argv[4][0] == '1')
        print_BinTree(btree, print_word);

    //Busca no Indice Remissivo
    if(argv[4][0] != '2')
        return 0;

    if(i > MAX_LINHAS)
    {
        printf("Arquivo muito grande para busca em O(n).\n");
        return 1;
    }

    int cont = 1;
    int qtd_buscas = 0;

    printf("Quantidade de buscas?\n");
    scanf("%d\n", &qtd_buscas);

    while(cont <= qtd_buscas)
    {
        //Numero maximo de linhas = MAX_LINHAS
        int comum[i+1];
        memset(comum, 0, sizeof(comum));

        char aux='\0';
        int qtd_pal = 0;

        while(aux!='\n')
        {
            scanf("%s%c", pal, &aux);
            wrd = new_word(pal);

            printf("%s ", pal);

            List lr = searchListOcr_BinTree(btree, wrd, cmp_word);


            update_common_list(comum, lr);
            qtd_pal++;
            //desalocar wrd
        }

		printf(":\n");
		imprime_linhas(comum, argv[1], qtd_pal);
		printf("\n");

        cont++;
    }

    return 0;
}
