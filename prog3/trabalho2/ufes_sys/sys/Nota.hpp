/* 
 * File:   nota.hpp
 * Author: nicole e jordao
 *
 * Created on 21 de Junho de 2016, 11:17
 */

#ifndef NOTA_HPP
#define	NOTA_HPP

#include "Avaliacao.hpp"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "../../util/DateUtils.h"
#include "Aluno.hpp"

using namespace std;
namespace ufes_sys {

    class Aluno;
    class Avaliacao;

    class Nota {

    public:
        Nota(Aluno **alunos, double valor, Avaliacao *ava, int nAlunos);

        virtual ~Nota();

        Aluno **getVetorAlunos() { return alunos; }

        double getValor() { return valor; }

        int getQtd() { return qtd; }

        void print();

    private:
        Aluno **alunos;
        int qtd;
        double valor;
    };
}
#endif	/* NOTA_HPP */

