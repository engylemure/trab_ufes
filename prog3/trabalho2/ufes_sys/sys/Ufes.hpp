/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ufes.hpp
 * Author: nicole e jordao
 *
 * Created on 30 de Junho de 2016, 16:22
 */


#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "Curso.hpp"
#include "ManipulaString.hpp"
#include "Aluno.hpp"
#include "Graduando.hpp"
#include "PosGraduando.hpp"
#include "../../util/Tokenizer.h"
#include "../../util/NumberUtils.h"
#include "../../util/StringUtils.h"
#include "Trabalho.hpp"
#include "Disciplina.hpp"
#include "../exception/ufes_sys_Exception.hpp"
using namespace cpp_util;
using namespace std;

namespace ufes_sys {

    class Ufes {
    public:
        Ufes();

        ~Ufes();

        map<int, Curso *> cursos;
        map<string, Disciplina *> disciplinas;
        map<string, Avaliacao *> avaliacoes;
        map<int, Aluno *> alunos;

        int processamentoDeEntrada(char **argv, string s[5], int argc);

        void leitura_curso(const string &nome_arquivo);

        void leitura_disciplina(const string &nome_arquivo);

        void leitura_aluno(const string &nome_arquivo);

        void leitura_avaliacao(const string &nome_arquivo);

        void leitura_nota(const string &nome_arquivo);

        void relatorio_disciplinas();

        void relatorio_avaliacao();

        void relatorio_estatistica_por_disciplina();

    };

}


#endif /* PROFESSOR_HPP */

