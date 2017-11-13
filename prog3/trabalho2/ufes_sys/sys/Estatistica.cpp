/* 
 * File:   Estatistica.cpp
 * Author: nicole e jordao
 * 
 * Created on 28 de Junho de 2016, 10:38
 */

#include "Estatistica.hpp"

namespace ufes_sys {
    Estatistica::Estatistica(double nota, string nomeDoCurso) {
        this->nota = nota;
        this->nomeDoCurso = nomeDoCurso;
        numeroDeAlunos = 1;
        porcentagem = 0;
        if (this->nota >= 5.0) {
            qtdAlunosPassaram = 1;
        } else {
            qtdAlunosPassaram = 0;
        }
    }

    void Estatistica::poeNota(double nota) {

        if (nota >= 5.0) {
            this->qtdAlunosPassaram++;
        }
        this->nota += nota;
        this->numeroDeAlunos++;
    }

    double Estatistica::calculaMedia() {
        return (nota / numeroDeAlunos);
    }

    string Estatistica::getNomeCurso() {
        return nomeDoCurso;
    }

    double Estatistica::calculaPorcentagem() {
        return (100.0 * qtdAlunosPassaram / numeroDeAlunos);
    }


    Estatistica::~Estatistica() {
    }
}
