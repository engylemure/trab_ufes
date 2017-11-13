/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PosGraduando.hpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 03:44
 */
#ifndef POSGRADUANDO_HPP
#define POSGRADUANDO_HPP

class Aluno;
#include "Aluno.hpp"
#include <string>
#include <iostream>
#define tipo_code(x) (((x)=='M')? ("Mestrado"):("Doutorado"))

using namespace std;

namespace ufes_sys {

    class PosGraduando : public Aluno {

    public:
        PosGraduando(int, string, char);

        string getTipo() override { return tipo; }

        void print() override {
            Aluno::print();
            cout << "PosGraduação: " << tipo << "\n";
        }

        virtual ~PosGraduando();

    private:
        string tipo;
    };
}
#endif /* POSGRADUANDO_HPP */

