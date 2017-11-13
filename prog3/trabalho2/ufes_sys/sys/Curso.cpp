/* 
 * File:   curso.cpp
 * Author: nicole e jordao
 * 
 * Created on 7 de Junho de 2016, 08:15
 */

#include "Curso.hpp"
namespace ufes_sys {
    Curso::Curso(int codigo, string nome) {
        this->codigo = codigo;
        this->nome = nome;
    }

    void Curso::print() {
        cout << "CURSO -> Código: " << codigo << ". Nome: " << nome << "\n";
    }

    Curso::~Curso() {
        //cout << "Destruindo curso: " <<this->nome << "\n";
    }

}