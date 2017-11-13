/*UNIVERSIDADE FEDERAL DO ESPIRITO SANTO (UFES)
  TRABALHO DE PROGRAMAÇÂO 2
  Curso: Engenharia de Computação
  Jordão Rodrigu?s Oliveira Rosario e Raquel Fernandez Puñal de Araujo.
  Professora: Maria Cristina Rangel.
*/
#include <stdio.h>
void legab(char *vetor,int tam);//Função para a leitura do gabarito do teste realizado. Tem como entrada um vetor de caracteres e o tamanho do mesmo.	
void lematricularesposta(int *vetor,int *vetor1, int *nm);/*Função para a leitura das matriculas e respostas dos candidatos. Tem como entrada tres vetores,
um vetor armazenará somente as matriculas o segundo vetor armazenara somente as respostas e o terceiro armazenara o numero de candidatos inscritos.*/
void listag(int *R,char *GS, int t);/*Função para a conversão do sistema binario de respostas para o sistema de caracteres adotado pelo gabarito, tem como
entrada o vetor de respostas dos candidatos, um vetor de caracteres e o numero de candidatos inscritos.*/
void listanota(char *gabarito,char *respostas,float *acertos,int nm);/*Função para a contabilização das notas referentes a cada uma das disciplinas do teste.
Tem como entrada o vetor gabarito, o vetor de caracteres de resposta dos candidatos, o vetor de acertos para todos os candidatos e o numero de candidatos inscritos*/
void resultado(float *lista, int *eliminado, int t);/*Função para a verificação dos candidatos elminados. Tem como entrada um vetor que lista 
a matricula, notas das disciplinas e nota total do mesmo no teste, respectivamente, também tem como entrada um vetor que armazena o numero de inscrição dos candidatos eliminados
e o numero de candidatos inscritos*/
void matrizinha(float A[100][6],int l,float *vet);//Função para a inserção das informações dos candidatos em uma matriz.
void maiores(float A[100][6],float *m,float *sm,int numerodematriculas);//Função para calculo das maiores notas.
void habilitados(float A[100][6], float maior, float segundomaior, int *vetormaior,int *vetorsmaior, int numerodematriculas, int *vetor, int *svetor);  //Função para a verificação dos candidatos habilitados.
void listainfo(float *matlista,int *matricula,float *acertos,int nmatriculas);/*Função de loop para a implementação das informações contidas nos vetores matricula, acertos e a soma dos acertos no vetor matlista, que é responsavel por
	armazenar essas informações.*/
int main(){
	int nmaior,nsmaior,maiorc=0,maiorp=0,maiorl=0,maiore=0,maiornmat=0,smaiornmat=0,Maior[100],Maior1[100],sMaior1[100],sMaior[100], eliminado[100],i,j,k,cont,c,a,b,d,nmatriculas=0,matricula[100],respostas[8000];
	//Declaração de variaveis e vetores do tipo inteiro.
	float maior=0,smaior=0,info[100][6],acertos[400],matlista[600];//Declaração de variaveis e vetores do tipo float.
	char gabarito[20],gabaritos[2000];//Vetores do tipo char.
	legab(gabarito,20);//Utilização da função para a leitura do gabarito aplicada ao tamanho do mesmo.	
	lematricularesposta(matricula,respostas,&nmatriculas);//Utilização da função para leitura das respostas e matricula dos candidatos.
	listag(respostas,gabaritos,nmatriculas);//Utilização da função para a conversão das respostas no formato binario para o formato caractere.
	listanota(gabarito,gabaritos,acertos,nmatriculas);//Utilização da função para calculo das notas referentes as notas de cada um dos candidatos em cada disciplina.
	listainfo(matlista,matricula,acertos,nmatriculas);//Utilização da função para armazenamento das informações de todos os candidatos em um unico vetor.
	matrizinha(info,nmatriculas,matlista);//Utilização da função para armazenamento das informações dos candidatos em uma matriz.
	resultado(matlista,eliminado,nmatriculas);//Utilização da função para a verificação dos candidatos eliminados.
	maiores(info,&maior,&smaior,nmatriculas);//Utilização da função para o calculo da maior e segunda maior pontuação total.
	habilitados(info, maior,smaior, Maior,sMaior,nmatriculas,Maior1,sMaior1);//Utilização da função para a verificação dos candidatos habilitados.
	
	    
}
void legab(char *vetor,int tam){
	int i=0;
	do{
	vetor[i]=getchar();
	getchar();
	i++;
	}while(i<tam);
}
void lematricularesposta(int *vetor,int *vetor1,int *nm){
	int i,c=1,cont=0,k=0,j=0;
	for(i=1;vetor[cont-1]!=-1;i++){
	  if (i%c==0){
	    scanf("%d",&vetor[cont]);
	    c=c+81;
	    cont++;
	  }
	  else {
	    scanf("%d",&vetor1[k]);
	    k++;
	  }
	}
	*nm=cont-1;
	
}
void listag(int *R, char *GS,int t){
      int i=0;
      int tam=t*80;
      int cont=0;
      int a,b,c,d;
      do{
	a=b=c=d=0;
	if (R[i]+R[i+1]+R[i+2]+R[i+3]!=1)GS[cont]='0';
	else if (R[i]==1)GS[cont]='a';
	else if (R[i+1]==1)GS[cont]='b';
	else if (R[i+2]==1)GS[cont]='c';
	else if (R[i+3]==1)GS[cont]='d';
	cont++;
	i+=4;
	 }while(i<tam);
}
void listanota(char *gabarito,char *respostas,float *acertos,int nm){
  int i=0,j=0,c=0;
  int t=nm*20;
  int notap,notal,notae,notac;
  while(j<t){
    notap=notal=notae=notac=i=0;
  while(i<5){
  if(gabarito[i]==respostas[j])notap++;
  i++;
  j++;
  }
  while(i<8){
  if(gabarito[i]==respostas[j])notal++;
  i++;
  j++;
  }
  while(i<10){
  if(gabarito[i]==respostas[j])notae++;
  i++;
  j++;
  }
  while(i<20){
  if(gabarito[i]==respostas[j])notac++;
  i++;
  j++;
  }
  acertos[c]=notap*2.5;
  c++;
  acertos[c]=notal*1.5;
  c++;
  acertos[c]=notae;
  c++;
  acertos[c]=notac*3.5;
  c++;
  }
}
void resultado(float *lista, int *eliminado,int t){//Função para calculo dos eliminados.
  int i,j,k,s, cont=0,ins;
  i=1;
  j=0;
  do{
    cont++;
    if(lista[i]<5){
      eliminado[j]=cont;
      j++;
    }
    else if (lista[i+1]<1.5){
      eliminado[j]=cont;
      j++;
    }
    else if (lista[i+2]<1){
      eliminado[j]=cont;
      j++;
    }
    else if (lista[i+3]<14){
      eliminado[j]=cont;
      j++;
    }
    i=i+6;
  }while(i<=t*6);
    if(cont!=0)   for(k=0;k<j;k++){
		ins=(eliminado[k]-1)*6;
		printf("Candidato Eliminado\nMATRICULA=%.0f\n",lista[ins]);
		lista[ins]=0;
		}
}
void matrizinha(float A[][6],int l,float *vet){//Função para a inserção das informações dos candidatos em uma matriz.
  int i,j;
  j=0;
  for(i=0;i<l;i++){
		A[i][0]=vet[j];
		j++;
		//printf("Matricula: %f\n",A[i][0]);
		A[i][1]=vet[j];
		j++;
		//printf("pontuação em portugues: %f\n",A[i][1]);
		A[i][2]=vet[j];
		j++;
		//printf("pontuaçao em logica: %f\n",A[i][2]);
		A[i][3]=vet[j];
		j++;
		//printf("pontuação em etica: %f\n",A[i][3]);
		A[i][4]=vet[j];
		j++;
		//printf("pontuação em conhecimentos especificos: %f\n",A[i][4]);
		A[i][5]=vet[j];
		j++;
		//printf("pontuação total: %f\n\n",A[i][5]);
	}
  }
void maiores(float A[100][6], float *m,float *sm,int numerodematriculas){//Função para calculo das maiores notas.
    int i,j;
    float maior=0,smaior=0;
  for(i=0;i<numerodematriculas;i++){
	for(j=0;j<numerodematriculas;j++){
	    if(A[i][5]>=A[j][5] && A[i][5]>maior)maior=A[i][5];
	  }
	}
	for(i=0;i<numerodematriculas;i++){
	  for(j=0;j<numerodematriculas;j++){
	    if(A[i][5]>A[j][5] && A[i][5]<maior && A[i][5]>smaior)smaior=A[i][5];
	  }
	}
	*m=maior;
	*sm=smaior;
}
void habilitados(float A[100][6], float maior, float segundomaior, int *vetormaior,int *vetorsmaior, int numerodematriculas, int *vetor, int *svetor){ 
  //Função para a verificação dos candidatos habilitados.
  int i,j,k,numerodemaior=0,numerodesmaior=0, ndemaior=0, ndesmaior=0;
  float cmaior=0,csmaior=0,maiorc,maiorc1;
  for(i=0;i<numerodematriculas;i++){
    if(A[i][5]==maior){
      vetormaior[numerodemaior]=i;
      numerodemaior++;
    }
    else if(A[i][5]==segundomaior){
      vetorsmaior[numerodesmaior]=i;
      numerodesmaior++;
  }
  }
  if(numerodemaior==1){
     printf("Habilitado 1\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetormaior[0]][5]);
     if(numerodesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
     else{
       for(i=0;i<numerodesmaior;i++){
	 for(j=0;j<numerodesmaior;j++){
	 if(A[vetorsmaior[i]][4]>=A[vetorsmaior[j]][4] && A[vetorsmaior[i]][4]>cmaior)cmaior=A[vetorsmaior[i]][4];
	 }
       }
       numerodemaior=0;
       for(i=0;i<numerodesmaior;i++){
	 if(A[vetorsmaior[i]][4]==cmaior){
	  vetormaior[numerodemaior]=vetorsmaior[i];
	  numerodemaior++;
	  }
       }
       printf("%d",numerodemaior);
	    if(numerodemaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetormaior[0]][5]);
	      else{
		  cmaior=0;
		  for(i=0;i<numerodemaior;i++){
		    for(j=0;j<numerodemaior;j++){
			if(A[vetormaior[i]][1]>=A[vetormaior[j]][1] && A[vetormaior[i]][1]>cmaior)cmaior=A[vetormaior[i]][1];
			}
			}
			numerodesmaior=0;
			  for(i=0;i<numerodemaior;i++){
			  if(A[vetormaior[i]][1]==cmaior){
			  vetorsmaior[numerodesmaior]=vetormaior[i];
			  numerodesmaior++;
			  }
			  }
			  if(numerodesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
			    else{
				 cmaior=0;
				 for(i=0;i<numerodesmaior;i++){
				    for(j=0;j<numerodesmaior;j++){
					if(A[vetorsmaior[i]][2]>=A[vetorsmaior[j]][2] && A[vetorsmaior[i]][2]>cmaior)cmaior=A[vetorsmaior[i]][2];
				      }
				      }
				      numerodemaior=0;
				      for(i=0;i<numerodesmaior;i++){
				      if(A[vetorsmaior[i]][2]==cmaior){
				      vetormaior[numerodemaior]=vetorsmaior[i];
				      numerodemaior++;
				      }
				}
				if(numerodemaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetormaior[0]][5]);
			    else{
				 cmaior=0;
				 for(i=0;i<numerodemaior;i++){
				    for(j=0;j<numerodemaior;j++){
					if(A[vetormaior[i]][3]>=A[vetormaior[j]][3] && A[vetormaior[i]][3]>cmaior)cmaior=A[vetormaior[i]][3];
				      }
				      }
				      numerodesmaior=0;
				      for(i=0;i<numerodemaior;i++){
				      if(A[vetormaior[i]][3]==cmaior){
				      vetorsmaior[numerodemaior]=vetormaior[i];
				      numerodesmaior++;
				      }
				}
				if(numerodesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
				else{
				 cmaior=A[vetormaior[0]][0];
				 for(i=0;i<numerodesmaior;i++){
				    for(j=0;j<numerodesmaior;j++){
					if(A[vetorsmaior[i]][0]<A[vetorsmaior[j]][0] && A[vetorsmaior[i]][0]<=cmaior)cmaior=A[vetorsmaior[i]][0];
				      }
				      }
				      for(i=0;i<numerodesmaior;i++){
				      if(A[vetorsmaior[i]][0]==cmaior)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[i]][0],A[vetorsmaior[i]][5]);
				}
				}
			    }
			    }
			    }
			}
		}
		else{
		  for(i=0;i<numerodemaior;i++){
		    for(j=0;j<numerodemaior;j++){
			if(A[vetormaior[i]][4]>=A[vetormaior[j]][4] && A[vetormaior[i]][4]>cmaior)cmaior=A[vetormaior[i]][4];
			}
			}
			
			for(i=0;i<numerodemaior;i++){
			  for(j=0;j<numerodemaior;j++){
			      if(A[vetormaior[i]][4]>=A[vetormaior[j]][4] && A[vetormaior[i]][4]<cmaior && A[vetormaior[i]][4]>csmaior)csmaior=A[vetormaior[i]][4];
			      }
			      }
			          for(i=0;i<numerodemaior;i++){
				    if(A[vetormaior[i]][4]==cmaior){
				      vetor[ndemaior]=vetormaior[i];
				      ndemaior++;
				    }
				    else if(A[vetormaior[i]][4]==csmaior){
				      svetor[ndesmaior]=vetormaior[i];
				      ndesmaior++;
				  }
			      }			      
			      if(ndemaior==1){
				printf("Habilitado 1\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetor[0]][0],A[vetor[0]][5]);
				if(ndesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[svetor[0]][0],A[svetor[0]][5]);
		else{
		  cmaior=0;
		  for(i=0;i<ndesmaior;i++){
		    for(j=0;j<ndesmaior;j++){
		    if(A[svetor[i]][1]>=A[svetor[j]][1] && A[svetor[i]][1]>cmaior && A[svetor[i]][5]==maior)cmaior=A[svetor[i]][1];
		    }
		  }
		  numerodemaior=0;
		  for(i=0;i<ndesmaior;i++){
		    if(A[svetor[i]][1]==cmaior && A[svetor[i]][5]==maior){
		      vetormaior[numerodemaior]=svetor[i];
		      numerodemaior++;
		      }
		  }
			if(numerodemaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetormaior[0]][5]);
			  else{
			      cmaior=0;
			      for(i=0;i<numerodemaior;i++){
				for(j=0;j<numerodemaior;j++){
				    if(A[vetormaior[i]][2]>=A[vetormaior[j]][2] && A[vetormaior[i]][2]>cmaior && A[vetormaior[i]][5]==maior)cmaior=A[vetormaior[i]][2];
				    }
				    }
				    numerodesmaior=0;
				      for(i=0;i<numerodemaior;i++){
				      if(A[vetormaior[i]][2]==cmaior && A[vetormaior[i]][5]==maior){
				      vetorsmaior[numerodesmaior]=vetormaior[i];
				      numerodesmaior++;
				      }
				      }
				      if(numerodesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
					else{
					    cmaior=0;
					    for(i=0;i<numerodesmaior;i++){
						for(j=0;j<numerodesmaior;j++){
						    if(A[vetorsmaior[i]][3]>=A[vetorsmaior[j]][3] && A[vetorsmaior[i]][3]>cmaior)cmaior=A[vetorsmaior[i]][3];
						  }
						  }
						  numerodemaior=0;
						  for(i=0;i<numerodesmaior;i++){
						  if(A[vetorsmaior[i]][3]==cmaior){
						  vetormaior[numerodemaior]=vetorsmaior[i];
						  numerodemaior++;
						  }
					    }
				if(numerodemaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetormaior[0]][5]);
				else{
				    cmaior=A[vetormaior[0]][0];
				    for(i=0;i<numerodesmaior;i++){
					for(j=0;j<numerodesmaior;j++){
					    if(A[vetorsmaior[i]][0]<A[vetorsmaior[j]][0] && A[vetorsmaior[i]][0]<=cmaior)cmaior=A[vetorsmaior[i]][0];
					  }
					  }
					  for(i=0;i<numerodesmaior;i++){
					  if(A[vetorsmaior[i]][0]==cmaior)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[i]][0],A[vetorsmaior[i]][5]);
				    }
				    }
			}
			  }
		}
		}
		else{
		  cmaior=csmaior=0;
		  for(i=0;i<ndemaior;i++){
		    for(j=0;j<ndemaior;j++){
			if(A[vetor[i]][1]>=A[vetor[j]][1] && A[vetor[i]][1]>cmaior && A[vetor[i]][5]==maior)cmaior=A[vetor[i]][1];
			}
			}
			for(i=0;i<ndemaior;i++){
			  for(j=0;j<ndemaior;j++){
			      if(A[vetor[i]][1]>=A[vetor[j]][1] && A[vetor[i]][1]<cmaior && A[vetor[i]][5]==maior && A[vetormaior[i]][1]>csmaior)csmaior=A[vetor[i]][1];
			      }
			      }
			      numerodemaior=numerodesmaior=0;
			      for(i=0;i<ndemaior;i++){
				    if(A[vetor[i]][1]==cmaior && A[vetor[i]][5]==maior){
				      vetormaior[numerodemaior]=vetor[i];
				      numerodemaior++;
				    }
				    else if(A[vetor[i]][1]==csmaior && A[vetor[i]][5]==maior ){
				      vetorsmaior[numerodesmaior]=vetor[i];
				      numerodesmaior++;
				  }
			      }
			      if(numerodemaior==1){
				printf("Habilitado 1\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetorsmaior[0]][5]);
				if(numerodesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
		else{
		  cmaior=0;
		  for(i=0;i<numerodesmaior;i++){
		    for(j=0;j<numerodesmaior;j++){
		    if(A[vetorsmaior[i]][2]>=A[vetorsmaior[j]][2] && A[vetorsmaior[i]][2]>cmaior)cmaior=A[vetorsmaior[i]][2];
		    }
		  }
		  numerodemaior=0;
		  for(i=0;i<numerodesmaior;i++){
		    if(A[vetorsmaior[i]][2]==cmaior){
		      vetormaior[numerodemaior]=vetorsmaior[i];
		      numerodemaior++;
		      }
		  }
			if(numerodemaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetormaior[0]][5]);
			  else{
			      cmaior=0;
			      for(i=0;i<numerodemaior;i++){
				for(j=0;j<numerodemaior;j++){
				    if(A[vetormaior[i]][3]>=A[vetormaior[j]][3] && A[vetormaior[i]][3]>cmaior)cmaior=A[vetormaior[i]][3];
				    }
				    }
				    numerodesmaior=0;
				      for(i=0;i<numerodemaior;i++){
				      if(A[vetormaior[i]][3]==cmaior){
				      vetorsmaior[numerodesmaior]=vetormaior[i];
				      numerodesmaior++;
				      }
				      }
				      if(numerodesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
					else{
				    cmaior=A[vetormaior[0]][0];
				    for(i=0;i<numerodesmaior;i++){
					for(j=0;j<numerodesmaior;j++){
					    if(A[vetorsmaior[i]][0]<A[vetorsmaior[j]][0] && A[vetorsmaior[i]][0]<=cmaior)cmaior=A[vetorsmaior[i]][0];
					  }
					  }
					  for(i=0;i<numerodesmaior;i++){
					  if(A[vetorsmaior[i]][0]==cmaior)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[i]][0],A[vetorsmaior[i]][5]);
				    }
				    }			
				}
			  }
		}
		else{
		  cmaior=csmaior=0;
		  for(i=0;i<numerodemaior;i++){
		    for(j=0;j<numerodemaior;j++){
			if(A[vetormaior[i]][2]>=A[vetormaior[j]][2] && A[vetormaior[i]][2]>cmaior && A[vetormaior[i]][5]==maior )cmaior=A[vetormaior[i]][2];
			}
			}
			for(i=0;i<numerodemaior;i++){
			  for(j=0;j<numerodemaior;j++){
			      if(A[vetormaior[i]][2]>=A[vetormaior[j]][2] && A[vetormaior[i]][2]<cmaior && A[vetormaior[i]][5]==maior && A[vetormaior[i]][2]>csmaior)csmaior=A[vetormaior[i]][2];
			      }
			      }
			      ndemaior=0;
			      for(i=0;i<numerodemaior;i++){
				    if(A[vetormaior[i]][2]==cmaior && A[vetormaior[i]][5]==maior ){
				      vetor[ndemaior]=vetormaior[i];
				      ndemaior++;
				    }
				    else if(A[vetormaior[i]][2]==csmaior && A[vetormaior[i]][5]==maior ){
				      vetorsmaior[numerodesmaior]=vetormaior[i];
				      numerodesmaior++;
				  }
			      }
			      if(ndemaior==1){
				printf("Habilitado 1\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetorsmaior[0]][5]);
				if(numerodesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
		else{
		  cmaior=0;
		  for(i=0;i<numerodesmaior;i++){
		    for(j=0;j<numerodesmaior;j++){
		    if(A[vetorsmaior[i]][3]>=A[vetorsmaior[j]][3] && A[vetorsmaior[i]][3]>cmaior)cmaior=A[vetorsmaior[i]][3];
		    }
		  }
		  numerodemaior=0;
		  for(i=0;i<numerodesmaior;i++){
		    if(A[vetorsmaior[i]][3]==cmaior){
		      vetormaior[numerodemaior]=vetorsmaior[i];
		      numerodemaior++;
		      }
		  }
			if(numerodemaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetormaior[0]][5]);
			 else{
				    cmaior=A[vetormaior[0]][0];
				    for(i=0;i<numerodemaior;i++){
					for(j=0;j<numerodemaior;j++){
					    if(A[vetormaior[i]][0]<A[vetormaior[j]][0] && A[vetormaior[i]][0]<=cmaior)cmaior=A[vetormaior[i]][0];
					  }
					  }
					  for(i=0;i<numerodesmaior;i++){
					  if(A[vetormaior[i]][0]==cmaior)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[i]][0],A[vetormaior[i]][5]);
				    }
				    }
								
				}
			  }
			  else{
			    cmaior=csmaior=0;
			    for(i=0;i<ndemaior;i++){
		    for(j=0;j<ndemaior;j++){
			if(A[vetor[i]][3]>=A[vetor[j]][3] && A[vetor[i]][3]>cmaior && A[vetor[i]][5]==maior )cmaior=A[vetor[i]][3];
			}
			}
			for(i=0;i<ndemaior;i++){
			  for(j=0;j<ndemaior;j++){
			      if(A[vetor[i]][3]>=A[vetor[j]][3] && A[vetor[i]][3]<cmaior && A[vetor[i]][5]==maior && A[vetormaior[i]][3]>csmaior && A[vetormaior[i]][3]>csmaior)csmaior=A[vetor[i]][3];
			      }
			}
			      numerodemaior=numerodesmaior=0;
			      for(i=0;i<ndemaior;i++){
				    if(A[vetor[i]][3]==cmaior && A[vetor[i]][5]==maior ){
				      vetormaior[numerodemaior]=vetor[i];
				      numerodemaior++;
				    }
				    else if(A[vetor[i]][3]==csmaior && A[vetor[i]][5]==maior ){
				      vetorsmaior[numerodesmaior]=vetor[i];
				      numerodesmaior++;
				  }
			      }
			      if(numerodemaior==1){
				printf("Habilitado 1\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetormaior[0]][0],A[vetorsmaior[0]][5]);
				if(numerodesmaior==1)printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
				else{
				    cmaior=A[vetormaior[0]][0];
				    for(i=0;i<numerodesmaior;i++){
					for(j=0;j<numerodesmaior;j++){
					    if(A[vetorsmaior[i]][0]<A[vetorsmaior[j]][0] && A[vetorsmaior[i]][0]<=cmaior && A[vetorsmaior[i]][5]==maior )cmaior=A[vetorsmaior[i]][0];
					  }
					  }
					  for(i=0;i<numerodesmaior;i++){
					  if(A[vetorsmaior[i]][0]==cmaior && A[vetormaior[i]][5]==maior )printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[i]][0],A[vetorsmaior[i]][5]);
				    }
				    }
								
				}
				else{
				  ndemaior=0;
				  cmaior=A[vetormaior[0]][0];
				  for(i=0;i<numerodemaior;i++){
				    for(j=0;j<numerodemaior;j++){
				      if(A[vetormaior[i]][0]<A[vetormaior[j]][0] && A[vetormaior[i]][0]<cmaior && A[vetormaior[i]][5]==maior )cmaior=A[vetormaior[i]][0];
				      }
				      }
				      for(i=0;i<numerodematriculas;i++){
				    if(A[i][0]==cmaior){
				      vetorsmaior[0]=i;
				      printf("Habilitado 1\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
				    }
				      }
				      for(i=0;i<numerodemaior;i++){
					if(A[vetorsmaior[0]][0]!=A[vetormaior[i]][0]){
					  vetor[ndemaior]=vetormaior[i];
					  ndemaior++;
					}
				      }
				      csmaior=A[vetor[0]][0];
				  for(i=0;i<ndemaior;i++){
				    for(j=0;j<ndemaior;j++){
				      if(A[vetor[i]][0]<A[vetor[j]][0] && A[vetor[i]][0]<csmaior && A[vetor[i]][5]==maior )csmaior=A[vetor[i]][0];
				      }
				      }
				      for(i=0;i<numerodematriculas;i++){
				    if(A[i][0]==csmaior){
				      vetorsmaior[0]=i;
				      printf("Habilitado 2\nMATRICULA=%.0f\nPONTUACAO=%.2f\n",A[vetorsmaior[0]][0],A[vetorsmaior[0]][5]);
				    }
				      }			 
				  
				}
			    
		  
		}
		}
		}
		}
}
void listainfo(float *matlista,int *matricula,float *acertos,int nmatriculas){/*Função de loop para a implementação das informações contidas nos vetores matricula, acertos e a soma dos acertos no vetor matlista, que é responsavel por
	armazenar essas informações.*/
  int i,j,k,cont,c,b,d,a;
  i=j=k=cont=c=b=d=a=0;
	do{
	  i=cont=0;
	  while(i<6){
	    matlista[j]=matricula[c];
	    while(cont<4){
	    i++;
	    j++;
	    matlista[j]=acertos[k];
	    k++;
	    cont++;
	    }
	    j++;
	    matlista[j]=matlista[j-4]+matlista[j-3]+matlista[j-2]+matlista[j-1];
	    j++;
	    i=i+2;
	    c++;
	  }
	}while(j<nmatriculas*6);
}