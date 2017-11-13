/*
 * File:   aluno.cpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 09:09
 */

#include "Aluno.hpp"
namespace ufes_sys {

    Aluno::Aluno(const int matricula, const string nome) {
        this->matricula = matricula;
        this->nome = nome;
    }

    void Aluno::print() {
        cout << "ALUNO -> Matricula: " << matricula << ". Nome: " << nome << "\n";
    }

    bool Aluno::addDisciplina(Disciplina *d) {
        pair<map<string, Disciplina *>::iterator, bool> inseriu = this->disciplinas.insert(
                pair<string, Disciplina *>(d->getCodigo(), d));
        if (inseriu.second) {
            d->addAluno(this);
            return true;
        } else return false;
    }

    //Função para reornar as notas do aluno this na disciplina d
    double *Aluno::notas_disciplina(Disciplina *d, int &nNotas) {
        int i = 0, aux = 0;
        double *notas;

        //Procura as avaliações na disciplina em questão
        for (map<string, Avaliacao *>::iterator it = d->avaliacoes.begin(); it != d->avaliacoes.end(); it++) {
            if (it->second->getTipo() == "F")aux = 1;
        }

        //Se aux = 1 é porque tem prova final, senão é porque não tem prova final (todos passaram direto)
        if (aux == 1) {
            nNotas = d->avaliacoes.size() + 2;
        }
        else {
            nNotas = d->avaliacoes.size() + 3;
        }

        //Criação do vetor de notas
        notas = (double *) malloc(sizeof(double) * (nNotas));
        double mediaparcial = 0, pesototal = 0, provafinal = 0;

        //Percorre o vetor de avaliações procurando a nota do aluno e associando ela a uma posição no vetor de notas
        for (vector<pair<string, Avaliacao *>>::iterator it = d->vector_avaliacoes.begin(); it != d->vector_avaliacoes.end(); it++) {
            if (it->second->getTipo() != "F") {
                notas[i] = it->second->getNotaAluno(this->matricula); //Pega a nota do aluno na avaliação
                mediaparcial += notas[i] * it->second->getPeso();
                pesototal += it->second->getPeso();
                i++;
            } else {
                provafinal = it->second->getNotaAluno(this->matricula);
            }
        }
        mediaparcial = mediaparcial / pesototal;
        mediaparcial += 0.0005;
        notas[i] = mediaparcial;
        notas[i + 1] = provafinal;
        notas[i + 2] = mediaparcial;
        if (notas[i + 2] < 7.0) {
            notas[i + 2] = (mediaparcial + provafinal) / 2;
        }
        return notas;
    }

    Aluno::~Aluno() {
        //cout << "Destruindo aluno de matricula: " << matricula << "\n";
    }

}