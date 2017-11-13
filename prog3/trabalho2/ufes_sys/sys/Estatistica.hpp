/* 
 * File:   Estatistica.hpp
 * Author: nicole
 *
 * Created on 28 de Junho de 2016, 10:38
 */

#ifndef ESTATISTICA_HPP
#define	ESTATISTICA_HPP

#include "Disciplina.hpp"
#include "Printable.hpp"
#include <cstdlib>
#include <stdio.h>
#include <iostream>

namespace ufes_sys {

    class Estatistica {
    public:

        Estatistica(double nota, string nomeDoCurso);

        void poeNota(double nota);

        double calculaMedia();

        string getNomeCurso();

        double calculaPorcentagem();

        int compareTo(Estatistica *o);

        virtual ~Estatistica();

    private:
        double nota;
        string nomeDoCurso;
        int numeroDeAlunos;
        double porcentagem;
        int qtdAlunosPassaram;
    };
}
#endif	/* ESTATISTICA_HPP */

