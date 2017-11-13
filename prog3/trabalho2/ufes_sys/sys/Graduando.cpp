/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graduando.cpp
 * Author: nicole e jordao
 * 
 * Created on 6 de Junho de 2016, 22:42
 */

#include "Graduando.hpp"
namespace ufes_sys {

    Graduando::Graduando(int a, string b, Curso *c) : Aluno(a, b) {
        this->curso = c;
    }

    Graduando::~Graduando() {
    }
}
