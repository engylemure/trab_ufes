/* 
 * File:   Trabalho.cpp
 * Author: nicole e jordao
 * 
 * Created on 17 de Junho de 2016, 10:00
 */

#include "Trabalho.hpp"
namespace ufes_sys {

    Trabalho::Trabalho(Disciplina *disciplina, string codigo, string nome, string data, string tipo, double peso,int tamanho_grupo)
            : Avaliacao(disciplina, codigo, nome, data, tipo, peso) {
        this->tamanho_grupo = tamanho_grupo;
    }


    Trabalho::~Trabalho() {
    }
}
