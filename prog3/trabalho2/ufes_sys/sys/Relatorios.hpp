/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   relatorios.hpp
 * Author: jordao
 *
 * Created on 25 de Junho de 2016, 17:37
 */
#ifndef RELATORIOS_HPP
#define RELATORIOS_HPP

#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
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
#include <iomanip>
#include "Estatistica.hpp"
#include "Ufes.hpp"
using namespace std;
using namespace cpp_util;
namespace ufes_sys {
    bool ordena_aluno_por_nome(pair<int, Aluno*> a, pair<int, Aluno*> b);

    bool ordena_avaliacoes_por_data(pair<string, Avaliacao*> a, pair<string, Avaliacao*> b);

    void cria_e_adequa_arquivo(ofstream& arq_saida, string nome_do_arquivo);

    double mediaDoAluno(Aluno* aluno, Disciplina* disciplina);

    void poe_aluno_na_estatistica(map<string, Estatistica*>& estatistica, double media_do_aluno, string nome_do_curso);
}
#endif /* RELATORIOS_HPP */

