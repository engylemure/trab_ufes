/* 
 * File:   avaliacao.hpp
 * Author: nicole e jordao
 *
 * Created on 17 de Junho de 2016, 09:09
 */
#ifndef AVALIACAO_HPP
#define	AVALIACAO_HPP

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "../../util/DateUtils.h"
#include <list>
#include <vector>
#include "Nota.hpp"
#include "Disciplina.hpp"

using namespace std;
using namespace cpp_util;

namespace ufes_sys{
    class Disciplina;

    class Nota;

class Avaliacao {
    private:

    Disciplina *disciplina;
    string codigo, nome;
    time_t data;
    double peso;
    string tipo; // Deve ser T para trabalho, P para Prova, F para prova final

    public:
    vector<Nota *> notas;  // notas dos alunos na avaliação x

    Avaliacao(Disciplina * disciplina, string
    codigo, string
    nome, string
    data, string
    tipo, double
    peso);

    virtual ~Avaliacao();

    string getCodigo() { return codigo; }

    string getNome() { return nome; }

    string getTipo() { return tipo; }

    time_t getData() { return data; }

    double getNotaAluno(int matricula);

    double getPeso() { return peso; }

    Disciplina *getDisciplina() { return disciplina; }

    bool addNota(Nota *nota);

    void print() {
        cout << "AVALIACAO-- Nome: " << nome << ". Código: " << codigo << "\n";
    }
};
}
#endif	/* AVALIACAO_HPP */

