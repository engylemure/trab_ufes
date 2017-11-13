/*UFES - UNIVERSIDADE FEDERAL DO ESPIRITO SANTO
 *DATA: 07/12/2014
 *NOME: JORDAO RODRIGUES OLIVEIRA ROSARIO E RAQUEL FERNANDEZ PUNAL DE ARAUJO
 *TRABALHO DE PROGRAMACAO 2
 * PROFESSORA: MARIA CRISTINA RANGEL
 *
 *BIBLIOTECA CRIADA COM AS FUNCOES A SEREM UTILIZADAS NO TRABALHO
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 30
typedef struct{//Struct criado para armazenar as informacoes referentes a cada uma das cidades contendendo nome, coordenadas, diaria e um vetor de custos.
    char Nome[100];//Vetor de Char para armazenar o nome da cidade.
    int Coord[2];//Vetor de inteiros para armazenar as coordenadas x e y.
    float Diaria;//Variavel do tipo float para armazenar a diaria correspondente aquela cidade.
    float CustoC[N];//Vetor de Custo por destino.
  }EstCidade;
void cidades(EstCidade *cidade){/*Funcao criada para imprimir o nome e coeficiente referente a cada uma das cidades.*/
  int i;
  for(i=0;i<N;i++)
    printf("%d - %s",i+1,cidade[i].Nome);
}
void lernomecoord( EstCidade *cidade){/*FunÃcao para a leitura do arquivo nome-coord.txt de modo a armazenar as informacoes nele contidas no vetor de struct EstCidade.*/
	int i; 
	FILE *nomcor;
	nomcor = fopen("nome-coord.txt","r");
	if(nomcor == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	  for(i=0;i<N;i++){
	    fgets(cidade[i].Nome,sizeof(cidade[i].Nome),nomcor);
	      fscanf(nomcor,"%d %d",&cidade[i].Coord[0],&cidade[i].Coord[1]);
		fgetc(nomcor);
	  }
	fclose(nomcor);
}
void lerdiariacusto( EstCidade *cidade){/*Funcao para a leitura do arquivo diaria-custo.txt de modo a armazenar as informacoes nele contidas no vetor de struct EstCidade.*/
	int i,j;
	FILE *diacus;
	diacus = fopen("diaria-custo.txt","r");
	if(diacus == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
	    for(i=0;i<N;i++){
	      fscanf(diacus,"%f",&cidade[i].Diaria);
	  }
	    for(i=0;i<N;i++){
	      for(j=0;j<N;j++){
	      fscanf(diacus,"%f", &cidade[i].CustoC[j]);
	      }
	    }
	}
	fclose(diacus);
}
void distancia(EstCidade *cidade, float (*mat)[N]){/* Funcao que calcula a distancia existente entre cada uma das cidades armazenando essas informacoes em um vetor bidimensional
   (matriz) e o inserindo no arquivo distancia.txt. */
	int i,j;
	FILE *range; 
	range = fopen("distancia.txt","w");
	for(i=0;i<N;i++){
	  for(j=0;j<N;j++){
	      mat[i][j]=sqrt(pow(cidade[i].Coord[0]-cidade[j].Coord[0],2)+pow(cidade[i].Coord[1]-cidade[j].Coord[1],2));
		fprintf(range,"%.2f ",mat[i][j]);
	  }
	  fprintf(range,"\n");
	}
	fclose(range);
}
void custos(EstCidade *cidade, float (*mat)[N], float (*Dis)[N]){/* Funcao que calcula o custo de viagem entre cada uma das cidades armazenando essas informacoes em um vetor bidi-
  mensional(matriz) e o inserindo no arquivo custo.txt. */
	int i,j;
	FILE *C;
	C = fopen("custo.txt","w");
	for(i=0;i<N;i++){
	  for(j=0;j<N;j++){
	    Dis[i][j]=cidade[i].CustoC[j]*mat[i][j]+cidade[j].Diaria;
	      fprintf(C,"%.2f ",Dis[i][j]);
	  }
	  fprintf(C,"\n");
	}
	fclose(C);
}
void posicao(EstCidade *cidade, float *aux){/* Funcao que verifica as cidades mais ao norte, sul, leste, oeste e centro referente ao mapa das cidades fornecidas pelos arquivos de
  entrada */
	int i,j,norte,sul,leste,oeste;
	float centrox,centroy,dcentro;
	leste=cidade[0].Coord[0];
	oeste=cidade[0].Coord[0];
	norte=cidade[0].Coord[1];
	sul=cidade[0].Coord[1];
	for(i=0;i<N;i++){
	  if(cidade[i].Coord[0]>leste)leste=cidade[i].Coord[0];
	  if(cidade[i].Coord[0]<oeste)oeste=cidade[i].Coord[0];
	  if(cidade[i].Coord[1]>norte)norte=cidade[i].Coord[1];
	  if(cidade[i].Coord[1]<sul)sul=cidade[i].Coord[1];
	  }
	  centroy=(norte-sul)/2;
	  centrox=(leste-oeste)/2;
	  for(i=0;i<N;i++){
	    aux[i]=sqrt(pow(cidade[i].Coord[0]-centrox,2)+pow(cidade[i].Coord[1]-centroy,2));
	  }
	  dcentro=aux[0];
	  for(i=0;i<N;i++)
	    if(aux[i]<dcentro)dcentro=aux[i];
	  printf("\nCidade(s) mais ao Leste:\n");
	  for(i=0;i<N;i++){
	    if(cidade[i].Coord[0]==leste)printf("%s",cidade[i].Nome);
	  }
	  printf("Cidade(s) mais a Oeste:\n");
	  for(i=0;i<N;i++){
	    if(cidade[i].Coord[0]==oeste)printf("%s",cidade[i].Nome);
	  }
	  printf("Cidade(s) mais ao Sul:\n");
	  for(i=0;i<N;i++){
	    if(cidade[i].Coord[1]==sul)printf("%s",cidade[i].Nome);
	  }
	  printf("Cidade(s) mais ao Norte:\n");
	  for(i=0;i<N;i++){
	    if(cidade[i].Coord[1]==norte)printf("%s",cidade[i].Nome);
	  }
	  printf("Cidade(s) mais ao Centro:\n");
	  for(i=0;i<N;i++){
	    if(aux[i]==dcentro)printf("%s",cidade[i].Nome);
	  } 
}
void caminho(EstCidade *cidade,float (*mat)[N],float (*mat1)[N]){/*Funcao que imprime o caminho da cidade 1 atÃ© N contabilizando a distancia e custo total desta viagem.*/
	  int i,j;
	  float distanciatotal=0,custototal=0;
	  printf("Caminho:\n");
	  for(i=0;i<N;i++){
	    if(i!=N-1){
	    for(j=0;j<strlen(cidade[i].Nome)-1;j++)
	      printf("%c",cidade[i].Nome[j]);
	      printf(" -> ");
	    }
	    else for(j=0;j<strlen(cidade[i].Nome)-1;j++)
	      printf("%c",cidade[i].Nome[j]);	    
	  }
	  printf("\n");
	  for(j=0;j<N-1;j++)
	    distanciatotal+=mat[j][j+1];
	  printf("Distancia total:\n%.1f\n",distanciatotal);
	  for(j=0;j<N-1;j++)
	    custototal+=mat1[j][j+1];
	  printf("Custo total:\n%.2f\n",custototal);
}
void formacao1(EstCidade *cidade,float (*mat)[N],float (*mat1)[N]){/*Funcao que dada a lei de formacao 1(A cidade seguinte no caminho eh a mais proxima e sempre considerando as cidades	
  a frente na ordem fornecida no arquivo nome-coord.txt) imprime o caminho da cidade 1 ateh a cidade N contabilizando e imprimindo a distancia e o custo total desta viagem.  */
	  int i,j,k,coef=0;
	  float mdistancia,mdistanciatotal=0,custotal=0,custo,menordistancia;
	  printf("Menor distancia Lei de formacao 1:\n");
	    for(j=0;j<strlen(cidade[0].Nome)-1;j++)
	      printf("%c",cidade[0].Nome[j]);
	    printf(" -> ");
	    for(i=0;i<N-1;i++){
		mdistancia=mat[coef][coef+1];
		if(coef==i)
		  for(j=coef;j<N;j++)
		    if(j>coef && mat[i][j]<=mdistancia){
			mdistancia=menordistancia=mat[i][j];
			custo=mat1[i][j];
			coef=j;
		    }
		if(coef-1==i){
			mdistanciatotal+=menordistancia;
			custotal+=custo;
			if(coef!=N-1){
			  for(j=0;j<strlen(cidade[coef].Nome)-1;j++)
			    printf("%c",cidade[coef].Nome[j]);
			  printf(" -> ");
			}
			else for(j=0;j<strlen(cidade[coef].Nome)-1;j++)
			  printf("%c",cidade[coef].Nome[j]);
			}
		}
		printf("\nDistancia total da lei de formacao 1:\n%.1f \n",mdistanciatotal);
		printf("Custo total da lei de formacao 1:\n%.2f \n",custotal);
}
void formacao2(EstCidade *cidade,float (*mat)[N],float (*mat1)[N]){/*Funcao que dada a lei de formacao 2(A cidade seguinte e a menos custosa e sempre considerando as cidades a frente
  na ordem fornecida no arquivo nome-coord.txt) imprime o caminho da cidade 1 ate a cidade N contabilizando e imprimindo a distancia e custo total desta viagem. */
	  int i,j,k,coef=0;
	  float mcusto,mdistanciatotal=0,mcustototal=0,distancia,menorcusto;
	  printf("Menor Custo Lei de formacao 2:\n");
	    for(j=0;j<strlen(cidade[0].Nome)-1;j++)
	      printf("%c",cidade[0].Nome[j]);
	    printf(" -> ");
	  for(i=0;i<N-1;i++){
		mcusto=mat[coef][coef+1];
	    if(coef==i)
	    for(j=coef;j<N;j++)
		if(j>coef && mat[i][j]<=mcusto){
			distancia=mat1[i][j];
			mcusto=menorcusto=mat[i][j];
			coef=j;
		}
		if(coef-1==i){
				mdistanciatotal+=distancia;
				mcustototal+=menorcusto;
			if(coef!=N-1){
			for(j=0;j<strlen(cidade[coef].Nome)-1;j++)
					printf("%c",cidade[coef].Nome[j]);
					printf(" -> ");
				}
				else 
				  for(j=0;j<strlen(cidade[coef].Nome)-1;j++)
				    printf("%c",cidade[coef].Nome[j]);
		}
		}
		printf("\nDistancia total da lei de formacao 2:\n%.1f \n",mdistanciatotal);
		printf("Custo total da lei de formacao 2:\n%.2f \n",mcustototal);
}
void usuario(EstCidade *cidade,float (*mat)[N],float (*mat1)[N]){/*Funcao que utilizando as leis de informacao 1 e 2 imprime o caminho e a distancia e o custo total de viagem entre duas
  cidades fornecidas pelo usuario(prompt). */
	  int i,j,k,coef,origem,destino,coef1;
	  float mdistancia,mdistanciatotal,custotal,custo,mcusto,mcustototal,distancia,menorcusto,menordistancia;
	  mdistanciatotal=custotal=mcustototal=coef=0;
	  for(k=0;k>=0;k++){
		printf("Digite a cidade origem:\n");
		scanf("%d",&origem);
		printf("Digite a cidade destino:\n");
		scanf("%d",&destino);
		if(origem<destino)break;
		else printf("Digite o coeficiente da cidade origem menor do que o da cidade destino!\n"); 	
	  }
	  coef=origem-1;
	  printf("Menor distancia Lei de formacao 1:\n");
	    for(j=0;j<strlen(cidade[origem-1].Nome)-1;j++)
	      printf("%c",cidade[origem-1].Nome[j]);
	    printf(" -> ");
	  for(i=origem-1;i<destino-1;i++){
		mdistancia=mat[coef][coef+1];
	    if(coef==i)
	    for(j=coef;j<destino;j++)
		if(j>coef && mat[i][j]<=mdistancia){
			mdistancia=menordistancia=mat[i][j];
			custo=mat1[i][j];
			coef=j;
		}
		if(coef-1==i){
				mdistanciatotal+=menordistancia;
				custotal+=custo;
			if(coef!=destino-1){
			for(j=0;j<strlen(cidade[coef].Nome)-1;j++)
					printf("%c",cidade[coef].Nome[j]);
					printf(" -> ");
				}
				else 
				  for(j=0;j<strlen(cidade[coef].Nome)-1;j++)
				    printf("%c",cidade[coef].Nome[j]);
				}
		}    
		printf("\nDistancia total da lei de formacao 1:\n%.1f \n",mdistanciatotal);
		printf("Custo total da lei de formacao 1:\n%.2f \n",custotal);
	  coef=origem-1;
	  mdistanciatotal=0;
	  mcustototal=0;
	  printf("Menor Custo Lei de formacao 2:\n");
	    for(j=0;j<strlen(cidade[origem-1].Nome)-1;j++)
	      printf("%c",cidade[origem-1].Nome[j]);
	    printf(" -> ");
	  for(i=origem-1;i<destino-1;i++){
		mcusto=mat1[coef][coef+1];
	    if(coef==i)
	    for(j=coef;j<destino;j++)
		if(j>coef && mat1[i][j]<=mcusto){
			distancia=mat[i][j];
			mcusto=menorcusto=mat1[i][j];
			coef=j;
			coef1=i;
		}
		if(coef-1==i){
				mdistanciatotal+=distancia;
				mcustototal+=menorcusto;
				if(coef!=destino-1){
			for(j=0;j<strlen(cidade[coef].Nome)-1;j++)
					printf("%c",cidade[coef].Nome[j]);
					printf(" -> ");
				}
				else 
				  for(j=0;j<strlen(cidade[coef].Nome)-1;j++)
				    printf("%c",cidade[coef].Nome[j]);
				}
		} 
		printf("\nDistancia total da lei de formacao 2:\n%.1f \n",mdistanciatotal);
		printf("Custo total da lei de formacao 2:\n%.2f \n",mcustototal);	
}
