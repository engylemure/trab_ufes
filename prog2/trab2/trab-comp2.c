/*UFES - UNIVERSIDADE FEDERAL DO ESPIRITO SANTO
 *DATA: 07/12/2014
 *NOME: JORDAO RODRIGUES OLIVEIRA ROSARIO E RAQUEL FERNANDEZ PUNAL DE ARAUJO
 *TRABALHO DE PROGRAMACAO 2
 * PROFESSORA: MARIA CRISTINA RANGEL
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "libcity.h"//Biblioteca de funcoes e declaracao do struct a ser utilizado no trabalho.
#define N 30
int main(){
  EstCidade cidade[N];//Declaracao do vetor de struct criado na biblioteca "libcity.h"
  int opcao,i;
  float Diaria[N],Distancia[N][N],Custo[N][N],auxiliar[N];//Declaracao dos vetores.
  lernomecoord(cidade);//Funcao para a leitura e armazenagem das informacoes contidas no arquivo nome-coord.txt no vetor de struct "cidade"
  lerdiariacusto(cidade);//Funcao para a leitura e armazenagem das informacoes contidas no arquivo diaria-custo.txt no vetor cidade;
  distancia(cidade,Distancia);/*Funcao para o calculo e inserção da distancia entre cada uma das cidades em uma matriz nxn impressa no arquivo distancia.txt*/
  custos(cidade,Distancia,Custo);/*Funcao para o calculo do custo conforme formula apresentada na descricao do trabalho.*/
  for(i=0;i>=0;i++){//Loop usado para a criacao de um menu de opcoes.
    printf("Menu de opcoes:\n1 - Funcao Posicao\n2 - Funcao Caminho\n3 - Funcao Lei de Formacao 1\n4 - Funcao Lei de Formacao 2\n5 - Funcao Usuario\n6 - Funcao para a verificacao dos codigos e nome das cidades\n7 - Sair\nOpcao:");
    scanf("%d",&opcao);
    if(opcao==7)break;
    else if(opcao>1 || opcao<6) switch(opcao){
      case 1:posicao(cidade,auxiliar);/*Funcao para a verificacao da posicao relativa das cidades mais ao norte, sul, leste, oeste e centro.*/;break;
      case 2:caminho(cidade,Distancia,Custo);/*Funcao que imprime o caminho da cidade 1->2->...->n passando por todas as cidades com seu custo e distancia total.*/;break;
      case 3:formacao1(cidade,Distancia,Custo);/*Funcao para a lei de formacao 1*/;break;
      case 4:formacao2(cidade,Custo,Distancia);/*Funcao para a lei de formacao 2*/;break;
      case 5:usuario(cidade,Distancia,Custo);/*Funcao para a utilizacao das informacoes inseridas pelo usuario utilizando a lei de formacao 1 e lei de formacao 2*/;break;
      case 6:cidades(cidade);break;/*Funcao para a impressao das informacoes correspondentes ao coeficiente e nome de cada uma das cidades*/
    }
    else
      printf("Digite uma opcao valida!");
  }
  return(0);
}
