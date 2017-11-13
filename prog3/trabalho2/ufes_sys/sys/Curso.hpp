/* 
 * File:   curso.hpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 08:15
 */
#ifndef CURSO_HPP
#define	CURSO_HPP

class Printable;
#include "Printable.hpp"
#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;
namespace ufes_sys {

    class Curso : public Printable {
    private:
        int codigo;
        string nome;

    public:
        //Construtor:
        Curso(int, string);

        //Funções:
        int getCodigo() { return codigo; }

        string getNome() { return nome; }

        void print() override;

        //Destrutor:
        virtual ~Curso();

    };
}
#endif	/* CURSO_HPP */

