/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ufes.cpp
 * Author: nicole e jordao
 * 
 * Created on 30 de Junho de 2016, 16:22
 */

#include "Ufes.hpp"
namespace ufes_sys {

    //Pega os nomes dos arquivos e faz o processamento para ficar na ordem da leitura
    int Ufes::processamentoDeEntrada(char** argv, string s[], int argc){
        int tipoDePrograma = -2;
        if (argc < 1) return tipoDePrograma;
        else tipoDePrograma = 0;
        for (int i = 0; i < argc; i++) {
            string arg(argv[i]);
            if (arg == "-c")s[0] = argv[i + 1];
            else if (arg == "-d")s[1] = argv[i + 1];
            else if (arg == "-p")s[2] = argv[i + 1];
            else if (arg == "-a")s[3] = argv[i + 1];
            else if (arg == "-n")s[4] = argv[i + 1];
            else if (arg == "--read-only")tipoDePrograma = 1;
            else if (arg == "--write-only")tipoDePrograma = 2;
        }
        return tipoDePrograma;
    }

    Ufes::~Ufes() {
        for (map<string, Disciplina*>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) delete it->second;
        for (map<int, Curso*>::iterator it = cursos.begin(); it != cursos.end(); it++) delete it->second;
        for (map<int, Aluno*>::iterator it = alunos.begin(); it != alunos.end(); it++) delete it->second;
    }
    Ufes::Ufes(){
        
    }
}
