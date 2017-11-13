/* 
 * File:   disciplina.hpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 08:58
 */

#ifndef DISCIPLINA_HPP
#define	DISCIPLINA_HPP

#include "Avaliacao.hpp"
#include "Printable.hpp"
#include "Aluno.hpp"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
namespace ufes_sys {
    class Aluno;
    class Avaliacao;

    class Disciplina : public Printable {
    private:
        string nome, codigo;
        map<int, ufes_sys::Aluno *> alunos;

    public:
        map<string, Avaliacao *> avaliacoes;
        vector<pair<string,Avaliacao*>> vector_avaliacoes;
        //Construtor:
        Disciplina(string codigo, string nome);

        //Funções:
        virtual bool addAvaliacao(Avaliacao *);

        map<int, ufes_sys::Aluno *>::iterator getInicioAlunos() { return alunos.begin(); }

        map<int, ufes_sys::Aluno *>::iterator getFimAlunos() { return alunos.end(); }

        string getNome() { return nome; }

        string getCodigo() { return codigo; }

        virtual bool addAluno(Aluno *);

        void print() override;

        //Destrutor:
        virtual ~Disciplina();

    };
}
#endif	/* DISCIPLINA_HPP */

