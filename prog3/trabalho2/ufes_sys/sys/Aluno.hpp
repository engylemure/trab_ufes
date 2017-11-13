/* 
 * File:   aluno.hpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 09:09
 */
#ifndef ALUNO_HPP
#define	ALUNO_HPP


#include "Disciplina.hpp"
#include "Printable.hpp"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

namespace ufes_sys{
    class Disciplina;
    class Aluno : public Printable {
        //Variaveis:
    protected:
        string nome;
        int matricula;

    public:
        map<string, ufes_sys::Disciplina *> disciplinas;
        //Construtor:
        Aluno(const int matricula, const string nome);

        //Funções:
        map<string, Disciplina *>::iterator getInicioDisciplinas() { return disciplinas.begin(); }

        map<string, Disciplina *>::iterator getFimDiscilpinas() { return disciplinas.end(); }

        void print() override;

        int getMatricula() { return matricula; }

        string getNome() { return nome; }

        virtual bool addDisciplina(Disciplina *);

        double *notas_disciplina(Disciplina *, int &);

        virtual string getTipo() { };

        //Destrutor:
        virtual ~Aluno();
    };

}
#endif	/* ALUNO_HPP */

