/*
 * File:   main.cpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 08:13
 */

#include "main.h"

/*
 *
 */
int main(int argc, char** argv) {

    string nome_arquivos[5];
    Ufes *Professor = new Ufes();
    try {
        //Processamento de entrada
        Professor->processamentoDeEntrada(argv, nome_arquivos, argc);

        //Leituras
        Professor->leitura_curso(nome_arquivos[0]);
        Professor->leitura_disciplina(nome_arquivos[1]);
        Professor->leitura_avaliacao(nome_arquivos[2]);
        Professor->leitura_aluno(nome_arquivos[3]);
        Professor->leitura_nota(nome_arquivos[4]);

        //Produção de relatórios
        Professor->relatorio_disciplinas();
        Professor->relatorio_estatistica_por_disciplina();
        Professor->relatorio_avaliacao();
    }catch( ufes_sys_Exception e ) {
        cout << e.what() << endl;
    }
delete Professor;
    return 0;

}

