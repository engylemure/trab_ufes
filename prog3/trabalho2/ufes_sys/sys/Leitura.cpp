/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Ufes.hpp"


namespace ufes_sys {

    void Ufes::leitura_curso(const string& nome_arquivo) {
        ifstream arq;
        arq.open(nome_arquivo);
        int codigo = 0;
        string lixo, nome, codigo_string;

        if (arq.is_open()) {
            arq.imbue(locale(""));
            getline(arq, lixo);
            while (!getline(arq, codigo_string, ';').eof()) {
                if (!isNumber(codigo_string)) {
                    throw ufes_sys::ufes_sys_Exception("Erro de formatação");
                }
                codigo = parseDouble(codigo_string, locale(""));
                getline(arq, nome);
                nome = ufes_sys::remove_bandechar(nome,' ');
                nome = ufes_sys::remove_bandechar(nome,'\n');
                nome = ufes_sys::remove_bandechar(nome,'\r');
                Curso* curso = new Curso(codigo, nome);
                //Adiciona curso no mapa de cursos:
                pair<int, Curso*> par_curso(codigo, curso);
                if (!cursos.insert(par_curso).second) {
                    stringstream e;
                    e << par_curso.first;
                    throw ufes_sys::ufes_sys_Exception("Código repetido para curso: " + e.str() + ".");
                } //ver se inseriu certo!
            }
        }
        arq.close();
    }

    void Ufes::leitura_disciplina(const string& nome_arquivo) {
        // Cria as variaveis a serem utilizadas incluindo o buffer do arquivo:
        ifstream arq;
        string lixo, codigo_disciplina, nome_disciplina;
        arq.open(nome_arquivo);
        // Realiza a leitura da primeira linha associando ela a uma variavel lixo:
        getline(arq, lixo);
        // Inicia o loop de repetição perguntando se o arquivo se encontra no fim:
        if (arq.is_open()) {
            while (!getline(arq, codigo_disciplina, ';').eof()) {
                //Realiza as leituras:
                codigo_disciplina = ufes_sys::remove_char(codigo_disciplina, ' ');
                getline(arq, nome_disciplina);
                nome_disciplina = ufes_sys::remove_bandechar(nome_disciplina,' ');
                nome_disciplina = ufes_sys::remove_bandechar(nome_disciplina,'\n');
                nome_disciplina = ufes_sys::remove_bandechar(nome_disciplina,'\r');
                // Constroi a Disciplina:
                Disciplina* disciplina = new Disciplina(codigo_disciplina, nome_disciplina);
                // Associa a disciplina a um par contendo seu conteudo e codigo para referencia:
                pair<string, Disciplina*> par_disciplina(codigo_disciplina, disciplina);
                // Adiciona a disciplina ao map de Disciplina verificando se ocorreu:
                if (!disciplinas.insert(par_disciplina).second) {
                    throw ufes_sys::ufes_sys_Exception("Código repetido para disciplina: " + par_disciplina.first + ".");
                };
            }
        }
        arq.close();
    }

    void Ufes::leitura_aluno(const string& nome_arquivo) {
        // Criação das variavies:
        ifstream arq;
        arq.open(nome_arquivo);
        string lixo, nome, s_disciplinas, tipo, codigo, s_matricula, s_codigocurso;
        int matricula;

        if (arq.is_open()) {
            getline(arq, lixo);
            while (!getline(arq, s_matricula, ';').eof()) {
                s_matricula = ufes_sys::remove_char(s_matricula,' ');
                if (!isNumber(s_matricula)) {
                    throw ufes_sys::ufes_sys_Exception("Erro de formatação");
                }
                // Realiza a leitura das informações:
                matricula = parseDouble(s_matricula, locale(""));
                getline(arq, nome, ';');
                nome = ufes_sys::remove_bandechar(nome,' ');
                nome = ufes_sys::remove_bandechar(nome,'\r');
                getline(arq, s_disciplinas, ';');
                getline(arq, tipo, ';');
                getline(arq,s_codigocurso);
                // Remove os espaços desnecessarios das strings:
                s_disciplinas = ufes_sys::remove_char(s_disciplinas, ' ');
                tipo = ufes_sys::remove_char(tipo, ' ');
                pair<int, Aluno*> par_aluno;
                s_codigocurso = ufes_sys::remove_char(s_codigocurso, ' ');
                s_codigocurso = ufes_sys::remove_char(s_codigocurso, ';');
                s_codigocurso = ufes_sys::remove_char(s_codigocurso, '\n');
                s_codigocurso = ufes_sys::remove_char(s_codigocurso, '\r');
                s_codigocurso = ufes_sys::remove_char(s_codigocurso, '\t');
                // Verifica o tipo do Aluno a ser Criado:
                if (tipo == "G") {
                    if (!isNumber(s_codigocurso) && atoi(s_codigocurso.c_str()) == 0) {
                        throw ufes_sys::ufes_sys_Exception("Erro de formatação");
                    }
                    // Realiza a leitura do codigo do curso e busca a existencia do mesmo:
                    int codigocurso;

                    codigocurso = parseDouble(s_codigocurso, locale(""));
                    map<int, Curso*>::iterator itcurso = cursos.find(codigocurso);
                    if (itcurso == cursos.end()) {
                        throw ufes_sys::ufes_sys_Exception("Código de curso não definido usado no aluno " + s_matricula + ": " + s_codigocurso + ".");
                    }
                    Curso* graduando = itcurso->second;
                    // Constroi o Graduando associando o mesmo ao par a ser adicionado a lista de alunos:
                    Graduando* aluno = new Graduando(matricula, nome, graduando);
                    par_aluno.first = matricula;
                    par_aluno.second = aluno;
                } else if (tipo == "P") {
                    // Realiza a leitura do tipo de pos graduação
                    if (!(s_codigocurso == "M" || s_codigocurso == "D")) {
                        throw ufes_sys::ufes_sys_Exception("Tipo de aluno de pós-graduação desconhecido para " + s_matricula + ": " + s_codigocurso + ".");
                    };
                    // Constroi o PosGraduando associando o mesmo ao par a ser adicionado a lista de alunos:
                    PosGraduando* aluno = new PosGraduando(matricula, nome, s_codigocurso[0]);
                    par_aluno.first = matricula;
                    par_aluno.second = aluno;
                } else {
                    throw ufes_sys::ufes_sys_Exception("Tipo de aluno desconhecido para " + s_matricula + ": " + tipo + ".");
                }
                // Separa os codigos de disciplina em que o aluno está matriculado:
                vector<string> vetor_disciplinas = ufes_sys::split_string(s_disciplinas, ',');
                // Busca cada uma das disciplinas no map de Disciplina adicionando o aluno ao map
                // de Alunos daquela disciplina e a Disciplina ao Aluno
                for (string s : vetor_disciplinas) {
                    map<string, Disciplina*>::iterator it = disciplinas.find(s);
                    if (it == disciplinas.end()) {
                        stringstream e;
                        e << par_aluno.first;
                        throw ufes_sys::ufes_sys_Exception("Código de disciplina não definido usado no aluno " + e.str() + ": " + s + ".");
                    }
                    Disciplina* disciplina = it->second;
                    par_aluno.second->addDisciplina(disciplina);
                }
                vetor_disciplinas.clear();
                // Insere o aluno ao map de Aluno verificando se ocorreu:
                if (!alunos.insert(par_aluno).second) {
                    stringstream e;
                    e << par_aluno.first;
                    throw ufes_sys::ufes_sys_Exception("Matrícula repetida para aluno: " + e.str() + ".");
                };
            }
        }
        arq.close();
    }

    void Ufes::leitura_avaliacao(const string& nome_arquivo) {
        ifstream arq;
        arq.open(nome_arquivo);
        string lixo;
        string cod_dis, cod_ava, nome_ava, tipo, data, s_peso, s_tam;
        double peso;
        int tam_max;
        if (arq.is_open()) {
            getline(arq, lixo);
            while (!getline(arq, cod_dis, ';').eof()) {
                map<string, Disciplina*>::iterator itdis = disciplinas.find(cod_dis);
                getline(arq, cod_ava, ';');
                cod_ava = ufes_sys::remove_char(cod_ava, ' ');
                getline(arq, nome_ava, ';');
                nome_ava = ufes_sys::remove_bandechar(nome_ava,' ');
                nome_ava = ufes_sys::remove_bandechar(nome_ava,'\r');
                getline(arq, s_peso, ';');
                peso = parseDouble(s_peso, locale(""));
                if (peso <= 0) {
                    stringstream e;
                    e << peso;
                    throw ufes_sys::ufes_sys_Exception("Peso de avaliação inválido para " + cod_ava + ": " + e.str() + ".");
                }
                getline(arq, tipo, ';');
                tipo = ufes_sys::remove_char(tipo, ' ');
                if (itdis == disciplinas.end()) {
                    throw ufes_sys::ufes_sys_Exception("Código de disciplina não definido usado na avaliação " + cod_ava + ": " + cod_dis + ".");
                }
                Disciplina* disciplina = itdis->second;
                pair<string, Avaliacao*> par_ava;
                getline(arq, data);
                Tokenizer token(data, ';');
                vector<string> resto_linha = token.remaining();
                vector<string>::iterator it = resto_linha.begin();
                data = *it++;
                if (!validDate(data, DATE_FORMAT_PT_BR_SHORT)) {
                    throw ufes_sys::ufes_sys_Exception("Erro de formatação");
                }
                if (tipo == "T") {
                    s_tam = *it;
                    tam_max = parseDouble(s_tam, locale(""));
                    if (tam_max <= 0) {
                        stringstream e;
                        e << tam_max;
                        throw ufes_sys::ufes_sys_Exception("Tamanho máximo de grupo inválido para trabalho " + cod_ava + ": " + e.str() + ".");
                    }
                    par_ava.first = cod_ava;
                    par_ava.second = new Trabalho(disciplina, cod_ava, nome_ava, data, tipo, peso, tam_max);
                } else if (tipo == "P" || tipo == "F") {
                    if (resto_linha.size() > 1) {
                        string e = *it;
                        throw ufes_sys::ufes_sys_Exception("Tamanho máximo de grupo especificado para a prova " + cod_ava + ": " + e + ".");
                    }
                    par_ava.first = cod_ava;
                    par_ava.second = new Avaliacao(disciplina, cod_ava, nome_ava, data, tipo, peso);
                } else {
                    throw ufes_sys::ufes_sys_Exception("Tipo de avaliação desconhecido para " + cod_ava + ": " + tipo + ".");
                }

                if (!avaliacoes.insert(par_ava).second) {
                    throw ufes_sys::ufes_sys_Exception("Código repetido para avaliação: " + par_ava.first + ".");
                }
            }
        }
        for (map<string, Disciplina*>::iterator itdis = disciplinas.begin(); itdis != disciplinas.end(); itdis++) {
            Disciplina *disciplina = itdis->second;
            if (disciplina->avaliacoes.size() == 0) {
                throw ufes_sys::ufes_sys_Exception("A disciplina " + disciplina->getCodigo() + " não possui nenhuma avaliação cadastrada.");
            }
        }
        arq.close();
    }

    void Ufes::leitura_nota(const string& nome_arquivo) {
        ifstream arq;
        arq.open(nome_arquivo);
        string lixo;

        string cod_ava, s_alunos, s_nota;
        double nota;

        ufes_sys::Avaliacao* ava;
        if (arq.is_open()) {
            getline(arq, lixo);
            while (!getline(arq, cod_ava, ';').eof()) {
                cod_ava = ufes_sys::remove_char(cod_ava, ' ');
                map<string, Avaliacao*>::iterator itava = avaliacoes.find(cod_ava);
                ava = avaliacoes.find(cod_ava)->second;
                getline(arq, s_alunos, ';');
                if (itava == avaliacoes.end()) {
                    throw ufes_sys::ufes_sys_Exception("Código de avaliação não definido usado na planilha de notas, associado ao(s) aluno(s) " + s_alunos + ": " + cod_ava + ".");
                }
                //Auxiliar para retornar o vetor de alunos
                Tokenizer token(s_alunos, ',');
                vector<string> str_alunos = token.remaining();

                int numerodealunos = str_alunos.size();
                ufes_sys::Aluno** alunos_nota = (Aluno**) malloc(numerodealunos * sizeof (Aluno*));
                int i = 0;
                for (vector<string>::iterator it = str_alunos.begin(); it != str_alunos.end(); it++, i++) {
                    string s_matricula = *it;
                    s_matricula = ufes_sys::remove_char(s_matricula, ' ');
                    if (!isNumber(s_matricula)) {
                        throw ufes_sys::ufes_sys_Exception("Erro de formatação");
                    }
                    int matricula = parseDouble(s_matricula, locale(""));
                    if (ava->getNotaAluno(matricula) != -1 && ava->getTipo() == "T") {
                        throw ufes_sys::ufes_sys_Exception("O aluno " + s_matricula + " foi registrado em mais de um grupo para a avaliação " + cod_ava + ".");
                    }
                    map<int, Aluno*>::iterator italuno = alunos.find(matricula);
                    if (italuno == alunos.end()) {
                        throw ufes_sys::ufes_sys_Exception("Matrícula de aluno não definida usada na planilha de notas, associada à avaliação " + cod_ava + ": " + s_matricula + ".");
                    }
                    alunos_nota[i] = italuno->second;
                    if (alunos_nota[i]->disciplinas.find(ava->getDisciplina()->getCodigo()) == alunos_nota[i]->disciplinas.end()) {
                        stringstream e;
                        e << alunos_nota[i]->getMatricula();
                        throw ufes_sys::ufes_sys_Exception("O aluno " + e.str() + " possui nota na avaliação " + cod_ava + " da disciplina " + ava->getDisciplina()->getCodigo() + ", porém não encontra-se matriculado nesta disciplina.");
                    }
                }

                getline(arq, s_nota);
                s_nota = ufes_sys::remove_bandechar(s_nota, ' ');
                s_nota = ufes_sys::remove_bandechar(s_nota, '\t');
                s_nota = ufes_sys::remove_bandechar(s_nota, '\r');
                s_nota = ufes_sys::remove_bandechar(s_nota, '\n');
                double valor = parseDouble(s_nota,locale(""));
                if (valor < 0 || valor > 10) {
                    throw ufes_sys::ufes_sys_Exception("Nota inválida para avaliação " + cod_ava + " do(s) aluno(s) " + s_alunos + ": " + s_nota + ".");
                }
                Nota* nota = new Nota(alunos_nota, valor, ava, numerodealunos);

            }
        } else {
            throw ufes_sys::ufes_sys_Exception("Erro de I/O");
        }
        arq.close();
    }
}