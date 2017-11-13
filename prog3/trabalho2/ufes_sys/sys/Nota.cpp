/* 
 * File:   nota.cpp
 * Author: nicole e jordao
 * 
 * Created on 21 de Junho de 2016, 11:17
 */

#include "Nota.hpp"
namespace ufes_sys {

    Nota::Nota(Aluno **alunos, double valor, Avaliacao *ava, int nAlunos) {
        qtd = nAlunos;
        this->alunos = alunos;
        this->valor = valor;
        ava->addNota(this);
    }

    void Nota::print() {
        cout << "NOTA --> alunos: ";
        for (int i = 0; i < qtd; i++) {
            cout << alunos[i]->getMatricula() << ";";
        }
        cout << " Valor: " << valor << "\n";
    }

    Nota::~Nota() {
        free(alunos);
    }

}