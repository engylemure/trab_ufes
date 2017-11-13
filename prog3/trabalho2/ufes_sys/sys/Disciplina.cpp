/*
 * File:   disciplina.cpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 08:58
 */

#include "Disciplina.hpp"
namespace ufes_sys {

    Disciplina::Disciplina(string codigo, string nome) {
        this->codigo = codigo;
        this->nome = nome;
    }

    void Disciplina::print() {
        cout << "DISCIPLINA -> Código: " << codigo << ". Nome: " << nome << "\n";
    }

    //Add aluno na disciplina
    bool Disciplina::addAluno(Aluno *a) {
        //Par contendo a posição em que foi inserido o par de (matricula,aluno) e um bool caso a inserção tenha ocorrido com sucesso.
        pair<map<int, Aluno *>::iterator, bool> inseriu = this->alunos.insert(pair<int, Aluno *>(a->getMatricula(), a));
        if (inseriu.second == true) {
            a->addDisciplina(this);
            return true;
        } else return false;
    }

    //Add avaliação na disciplina
    bool Disciplina::addAvaliacao(Avaliacao *ava) {
        pair<string, Avaliacao *> par_ava(ava->getCodigo(), ava); //Cria o par para adicionar no mapa
        pair<map<string, Avaliacao *>::iterator, bool> inseriu = this->avaliacoes.insert(par_ava);
        vector_avaliacoes.push_back(par_ava);
        return inseriu.second;
    }

    Disciplina::~Disciplina() {
        for (map<string, Avaliacao *>::iterator it = avaliacoes.begin(); it != avaliacoes.end(); it++) {
            delete it->second;
        }

    }

}