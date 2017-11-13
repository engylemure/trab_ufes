/* 
 * File:   avaliacao.cpp
 * Author: nicole e jordao
 * 
 * Created on 17 de Junho de 2016, 09:10
 */

#include <vector>

#include "Avaliacao.hpp"
namespace ufes_sys {

    Avaliacao::Avaliacao(Disciplina *disciplina, string codigo, string nome, string data, string tipo, double peso) {
        this->disciplina = disciplina;
        this->codigo = codigo;
        this->nome = nome;
        this->data = parseDate(data, DATE_FORMAT_PT_BR_SHORT);
        this->tipo = tipo;
        this->peso = peso;
        disciplina->addAvaliacao(this);
    }

    //Add nota na avaliação
    bool Avaliacao::addNota(Nota *nota) {
        notas.push_back(nota);
        return true;
    }

    //Pega a nota de um aluno na avaliação
    double Avaliacao::getNotaAluno(int matricula) {
        for (vector<Nota *>::iterator it = notas.begin(); it != notas.end(); it++) {
            Nota *nota = *it;
            Aluno **alunos = nota->getVetorAlunos();
            for (int i = 0; i < nota->getQtd(); i++)
                if (alunos[i]->getMatricula() == matricula)return nota->getValor();
        }
        return -1;
    }

    Avaliacao::~Avaliacao() {
        //cout <<"Destruindo avaliacao "<<nome<<"\n";
        for (vector<Nota *>::iterator it = this->notas.begin(); it != this->notas.end(); it++) {
            delete *it;
        }
    }

}