/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PosGraduando.cpp
 * Author: nicole e jordao
 * 
 * Created on 7 de Junho de 2016, 03:44
 */

#include "PosGraduando.hpp"
namespace ufes_sys {

    PosGraduando::PosGraduando(int a, string b, char c) : Aluno(a, b) {
        this->tipo = tipo_code(c);
    }

    PosGraduando::~PosGraduando() {
    }
}
