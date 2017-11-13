/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graduando.hpp
 * Author: jordao
 *
 * Created on 6 de Junho de 2016, 22:42
 */

#ifndef GRADUANDO_HPP
#define GRADUANDO_HPP


#include "Aluno.hpp"
#include "Curso.hpp"

namespace ufes_sys {
    class Graduando : public Aluno {

    private:
        Curso *curso;

    public:
        Graduando();

        Graduando(int, string, Curso *);

        void print() override {
            Aluno::print();
            curso->print();
        }

        string getTipo() override { return curso->getNome(); }

        virtual ~Graduando();

    };
}
#endif /* GRADUANDO_HPP */

