/* 
 * File:   Trabalho.hpp
 * Author: 2014100665
 *
 * Created on 17 de Junho de 2016, 10:00
 */

#ifndef TRABALHO_HPP
#define	TRABALHO_HPP

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "../../util/DateUtils.h"
#include "Disciplina.hpp"
#include "Avaliacao.hpp"

using namespace std;
using namespace cpp_util;
namespace ufes_sys {
    class Trabalho : public Avaliacao {
    public:
        int tamanho_grupo;

        Trabalho(Disciplina *disciplina, string codigo, string nome, string data, string tipo, double peso, int tam_grupo);

        virtual ~Trabalho();

    private:

    };
}
#endif	/* TRABALHO_HPP */

