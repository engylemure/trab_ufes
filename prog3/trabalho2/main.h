//
// Created by jordao on 03/07/16.
//

#ifndef TRABALHO2_MAIN_H
#define TRABALHO2_MAIN_H
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "ufes_sys/sys/Ufes.hpp"
#include "ufes_sys/sys/Printable.hpp"
using namespace ufes_sys;

void print_ableint1(pair<int,ufes_sys::Printable*> p){
    cout << "--";
    p.second->print();
}
void print_ablestring(pair<string,ufes_sys::Printable*> p){
    p.second->print();
}
void print_disciplinainfo(pair<string,ufes_sys::Disciplina*> d){
    d.second->print();
    for_each(d.second->getInicioAlunos(),d.second->getFimAlunos(),print_ableint1);
    for(map<string,ufes_sys::Avaliacao*>::iterator it = d.second->avaliacoes.begin(); it != d.second->avaliacoes.end(); it++){
        it->second->print();
        ufes_sys::Avaliacao* ava = it->second;
        for(vector<Nota*>::iterator it1 = ava->notas.begin();it1!=ava->notas.end();it1++){
            Nota* oii = *it1;
            oii->print();
        }
    }
}
#endif //TRABALHO2_MAIN_H
