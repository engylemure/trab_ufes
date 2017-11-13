#include <stdio.h> 
#include <stdlib.h>
typedef struct tipocidade Cidade;// Lista de Bairros
typedef struct tipobairro Bairro;// Lista de Ruas e nome do Bairo
typedef struct tiporua Rua;// Lista de Casas e nome da Rua
typedef struct tipocasa Casa;// Elemento primario que armazena as informações do numero da casa, id consumidor, consumo e nome do consumidor
typedef struct celulacasa CelulaCasa;// Celula que armazena um ponteiro pro elemento seguinte a ele dentro da lista de casas, contendo o tipocasa como elemento.
typedef struct celularua CelulaRua;// Celula que armazena o id da rua, a rua e um ponteiro pro elemento seguinte a ele dentro da lista de ruas.
typedef struct celulabairro CelulaBairro;// Celula que armazena o id do bairro, o bairro e um ponteiro pro elemento seguinte a ele dentro da lista de de bairros.
typedef struct celulacidade CelulaCidade;// Tipo não necessario dentro do programa.


// FUNÇÕES QUE NÃO DEVEM SER UTILIZADAS PELO USUARIO POIS SE RESTRINGEM A IMPLEMENTAÇÃO DA BIBLIOTECA CRIADA PARA O FUNCIONAMENTO DO PROGRAMA.
Bairro* iniciabairro();//Função para a inicialização do tipobairro, retornando um ponteiro contendo a memoria alocada para o mesmo tipo.
Rua* iniciarua();//Função para a inicialização do tiporua, retornando um ponteiro contendo a memoria alocada para o mesmo tipo.
Casa* iniciacasa();//Função para a inicialização do tipocasa, retornando um ponteiro contendo a memoria alocada para o mesmo tipo.
CelulaRua* iniciacelrua();//Função para a inicialização do tipo CelulaRua, retornando um ponteiro contendo a memoria alocada para o mesmo tipo.
CelulaCidade* iniciacelcid();//Função para a inicialização do tipo CelulaCidade, retornando um ponteiro contendo a memoria alocada para o mesmo tipo.
CelulaCasa* iniciacelcasa();//Função para a inicialização do tipo CelulaCasa, retornando um ponteiro contendo a memoria alocada para o mesmo tipo.
CelulaBairro* iniciacelbairro();//Função para a inicialização do tipo CelulaBairro, retornando um ponteiro contendo a memoria alocada para o mesmo tipo.
void FREERUA(CelulaRua* x);//Função que libera o espaço de memoria correspondente a CelulaRua inserida.
void FREEBAIRRO(CelulaBairro* x);//Função que libera o espaço de memoria correspondente a CelulaBairro inserida.
void FREECASA(CelulaCasa* x);//Função que libera o espaço de memoria correspondente a CelulaCasa inserida.

// FUNÇÕES QUE PODEM SER UTILIZADAS PARA A IMPLEMENTAÇÃO DO PROGRAMA QUE UTILIZARA A BIBLIOTECA RESPONSAVEL POR GERIR ESSE SISTEMA DE LISTAS E DADOS
Cidade* iniciacid();//Função para a inicialização do tipocidade, retornando um ponteiro contendo a memoria alocada para o mesmo tipo, esse tipo podera ser utilizado pelo usuario.
void imprimecasa(Cidade* x,int a, int b,int idc,FILE *saida);//Função que dada a estrutura cidade, busca imprimir as informações da casa correspondente ao id do consumidor inserido, no bairro e rua informados.
void IncluirBairro(Cidade* x,int a, char *nome,FILE *saida);//Função que Insere um Bairro com identificador e nome inseridos dentro da cidade
void IncluirRua(Cidade* x,int a, int b,char *nome,FILE *saida);//Função que Insere uma rua dentro da cidade com identificador e nome inseridos dentro do bairro correspondente.
void IncluirCasa(Cidade* x,int a, int b,int idc, int nc, char *nome,FILE *saida);//Função que insere uma Casa dentro da cidade com informações correspondentes as inseridas pelo usuario na rua correspondente.
void EliminarBairro(Cidade* x,int a,FILE *saida);//Função que elimina um determinado bairro com identificador correspondente ao inserido pelo usuario na cidade inserida.
void EliminarRua(Cidade* x,int a, int b,FILE *saida);//Função que elimina do bairro uma determinada rua com identificador correspondente ao inserido pelo usuario na cidade inserida.
void EliminarCasa(Cidade* x,int a, int b,int idc,FILE *saida);//Função que elimina da rua uma determinada casa com identificador correspondente ao inserido pelo na cidade inserida.
void Consumir(Cidade* x,int a, int b,int idc,float cons,FILE *saida);//Função que insere o consumo de uma determinada casa, conforme identificadores na cidade inserida. 
float medirConsumoCidade(Cidade* x,FILE *saida);//Função que mede o consumo total da cidade inserida.
float medirConsumoBairro(Cidade* x, int a,FILE *saida);//Função que mede o consumo total do bairro na cidade inserida, conforme o identificador apresentado.
float medirConsumoRua(Cidade* x, int a, int b,FILE *saida);//Função que mede o consumo total da rua na cidade inserida, conforme os identificadores apresentados.
float medirConsumoCasa(Cidade* x,int a, int b, int idc,FILE *saida);//Função que mede o consumo da casa na cidade inserida, conforme os identificadores apresentados.
void scanstring(FILE *arq,char* nome);//Função auxiliar para a leitura de um conjunto de palavras até o \n
void strlower(char *a);//Função auxiliar para a transformação de uma string com lestras maiusculas, apenas para letras minusculas.
void ImprimeCidade(Cidade *x,FILE *saida);
void programa(FILE *arq,char *nome,Cidade *x);


//( DEVE SER CHAMADA AO FIM DO PROGRAMA PARA A LIBERAÇÃO DO ESPAÇO ALOCADO PARA O ARMAZENAMENTO DAS INFORMAÇÕES DO TIPO CIDADE)
void FREECIDADE(Cidade* x);//Função que libera o espaço de memoria correspondente a Cidade inserida.
