/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   relatorios.cpp
 * Author: nicole e jordao
 *
 * Created on 25 de Junho de 2016, 17:37
 */

#include "Relatorios.hpp"
namespace ufes_sys {

    //Função para ser utilizada no sort: Ordenar aluno por nome
    bool ordena_aluno_por_nome(pair<int, Aluno*> a, pair<int, Aluno*> b) {
        locale mylocale("");

        //Declaração do Collate com use_facet para pegar o collate da localização da máquina.
        const std::collate<char>& coll = std::use_facet<std::collate<char> >(mylocale);
        int i = coll.compare(a.second->getNome().data(),a.second->getNome().data()+a.second->getNome().length(),b.second->getNome().data(),b.second->getNome().data()+b.second->getNome().length());
        if(i > 0)return false;
        return true;
    }

    //Função para ser utilizada no sort: Ordenar avaliação por data
    bool ordena_avaliacoes_por_data(pair<string, Avaliacao*> a, pair<string, Avaliacao*> b) {
        return a.second->getData() < b.second->getData();
    }

    //Função para ser utilizada no sort: Ordenar estatistica por nota
    bool ordena_estatistica_por_nota(pair<string, Estatistica*> a, pair<string, Estatistica*> b) {
        bool x = ((a.second->calculaMedia() > b.second->calculaMedia()));
        if (!x) {
            return (a.second->getNomeCurso() < b.second->getNomeCurso());
        }
        return x;
    }

    //Struct auxiliar para poder imprimir os números com , ao invés do .
    struct no_separator : std::numpunct<char> {
    public:

        no_separator(locale& l) {
            decimal_p = use_facet < numpunct<char> >(l).decimal_point();
        }
    protected:
        char decimal_p;

        //Sobrescreve a função que faz a separação de inteiros a cada 3 algarismos com ponto pois não queremos isso no relatório.
        virtual string_type do_grouping() const override {
            return "\000";
        } // groups of 0 (disable)

        //Pega a vírgula ao invés do ponto.
        virtual char_type do_decimal_point() const override {
            return decimal_p;
        }
    };

    //Criação do arquivo de saída de acordo com o relatório a ser gerado.
    void cria_e_adequa_arquivo(ofstream& arq_saida, string nome_do_arquivo) {
        locale mylocale("");
        /* Modificação do locale para impressão de doubles com ponto decimal de acordo com a localização padrão do sistema */
        locale localemod(mylocale, new no_separator(mylocale));
        arq_saida.open(nome_do_arquivo);
        arq_saida.imbue(localemod);
        arq_saida << setprecision(2) << fixed; //Imprimir apenas duas casas decimais e corrigir possiveis erros

    }

    //Faz o relatório 1: Disciplinas
    void Ufes::relatorio_disciplinas() {

        //Percorre o mapa de disciplinas fazendo o relatório para cada disciplina.
        for (map<string, Disciplina*>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {

            Disciplina* idisciplina = it->second;
            sort(idisciplina->vector_avaliacoes.begin(),idisciplina->vector_avaliacoes.end(),ordena_avaliacoes_por_data);

            //Criação e adequação do arquivo de saída para a idisciplina
            ofstream arq_saida;
            cria_e_adequa_arquivo(arq_saida, "1-pauta-" + idisciplina->getCodigo() + ".csv");

            /* Geração do relatório */
            arq_saida << "Matrícula;Aluno;";

            //Printa os códigos das avaliações dessa disciplina
            for (vector<pair<string,Avaliacao*>>::iterator it1 = idisciplina->vector_avaliacoes.begin(); it1 != idisciplina->vector_avaliacoes.end(); it1++) {
                if (it1->second->getTipo() != "F")
                    arq_saida << it1->second->getCodigo() + ";";
            }

            arq_saida << "Média Parcial;Prova Final;Média Final" << endl;

            //Criação e  ordenação do vector de alunos por nome para impressão das notas
            vector<pair<int, Aluno*>> alunos(idisciplina->getInicioAlunos(), idisciplina->getFimAlunos());
            sort(alunos.begin(), alunos.end(), ordena_aluno_por_nome);

            /* Percorre o vetor de alunos printando os dados deste aluno: matricula, nome, nota em cada avaliação, media parcial,
            prova final e media final */
            for (vector<pair<int, Aluno*>>::iterator it1 = alunos.begin(); it1 != alunos.end(); it1++) {
                Aluno* aluno = it1->second;

                arq_saida << aluno->getMatricula() << ";" + aluno->getNome();

                int tam;
                double* notas = aluno->notas_disciplina(idisciplina,tam);

                //Imprime as notas
                for (int i = 0; i < tam; i++) {
                    if (notas[i] >= 7.0 && i == (tam-3)) {
                        arq_saida << ";" << notas[i] << ";-;" << notas[tam-3];
                        break;
                    }
                    arq_saida << ";" << notas[i];

                }
                free(notas);
                arq_saida << endl;
            }

            arq_saida.close();
        }
    }

    //Faz o relatório 3: Avaliações
    void Ufes::relatorio_avaliacao() {

        //Criação de adequação do arquivo
        ofstream arq_saida;
        cria_e_adequa_arquivo(arq_saida, "3-avaliacoes.csv");

        //Geração do relatório
        arq_saida << "Disciplina;Código;Avaliação;Data;Média" << endl;

        //Como as disciplinas já estão ordenadas no mapa, é só percorrer e ordenar as avaliações por data em cada disciplina
        for (map<string, Disciplina*>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {
            Disciplina* idisciplina = it->second;

            //Ordenação das avaliações por data:
            sort(idisciplina->vector_avaliacoes.begin(), idisciplina->vector_avaliacoes.end(), ordena_avaliacoes_por_data);

            /* Dentro de uma disciplina, vai nas avaliações percorrendo cada avaliacao pegando a média final de cada um dos alunos, gerando
            uma média final referente àquela avaliação */
            for (vector<pair < string, Avaliacao*>>::iterator it1 = idisciplina->vector_avaliacoes.begin(); it1 != idisciplina->vector_avaliacoes.end(); it1++) {
                double media = 0;
                int i = 0;
                Avaliacao* ava = it1->second;

                if (ava->getTipo() != "F") {
                    for (vector<Nota*>::iterator it2 = ava->notas.begin(); it2 != ava->notas.end(); it2++) {
                        Nota* nota = *it2;
                        media += nota->getValor();
                        i++;
                    }
                    media = media / (double) i;
                    media += 0.0005; //Para arredondar 0,5 para cima deve-se corrigir o valor

                    //Impressão:
                    arq_saida << idisciplina->getCodigo() << ";" << ava->getCodigo() << ";" << ava->getNome() << ";" << formatDate(ava->getData(), DATE_FORMAT_PT_BR_SHORT) << ";" << media << endl;
                }
            }
        }
        arq_saida.close();
    }

    //Faz o relatório 2: Estatisticas por disciplina.
    void Ufes::relatorio_estatistica_por_disciplina() {

        //Criação e adequação do arquivo
        ofstream arq_saida;
        cria_e_adequa_arquivo(arq_saida, "2-disciplinas.csv");

        /*Geração do relatório */
        arq_saida << "Código;Disciplina;Curso;Média;% Aprovados" << endl;

        //Percorre o mapa de disciplinas fazendo estatistica para cada disciplina:
        for (map<string, Disciplina*>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {

            map<string, Estatistica*> estatisticas;
            Disciplina* idisciplina = it->second;

            //Pega-se a media de cada aluno naquela disciplina  associando a media do aluno com a disciplina e tipo do aluno
            for (map<int, Aluno*>::iterator it1 = idisciplina->getInicioAlunos(); it1 != idisciplina->getFimAlunos(); it1++) {
                Aluno* ialuno = it1->second;
                string tipo_do_aluno = ialuno->getTipo();
                double media_do_aluno = mediaDoAluno(ialuno, idisciplina);

                //Coloca a média do aluno na estatística da disciplina
                poe_aluno_na_estatistica(estatisticas, media_do_aluno, ialuno->getTipo());
            }
            //Tendo todos as notas de todos os alunos inseridos na estatistica, faz-se a media e a porcentagem e então a ordena.
            vector<pair<string, Estatistica*>> vetor_estatistica(estatisticas.begin(), estatisticas.end());
            sort(vetor_estatistica.begin(), vetor_estatistica.end(), ordena_estatistica_por_nota);

            //Impressão das estatísticas
            for (vector<pair < string, Estatistica*>>::iterator it2 = vetor_estatistica.begin(); it2 != vetor_estatistica.end(); it2++) {
                arq_saida << idisciplina->getCodigo() << ";" << idisciplina->getNome() << ";";
                Estatistica* estatistica_aux = it2->second;
                arq_saida << estatistica_aux->getNomeCurso() << ";" << estatistica_aux->calculaMedia() << ";";
                arq_saida << setprecision(1) << fixed;
                arq_saida << estatistica_aux->calculaPorcentagem() << "%";
                arq_saida << setprecision(2) << fixed;
                arq_saida << endl;
            }

            //Destrução das estatísticas
            for(map<string,Estatistica*>::iterator ites = estatisticas.begin(); ites != estatisticas.end();ites++)
                delete ites->second;
        }

        arq_saida.close();

    }

    //Retorna a media do aluno na disciplina
    double mediaDoAluno(Aluno* aluno, Disciplina* disciplina) {
        int t;
        double* notas = aluno->notas_disciplina(disciplina,t);
        double media = notas[t-1];
        free (notas);
        return media;
    }

    //Poe a media de um aluno no mapa de estatistica, levando em consideração o tipo do aluno (há uma estatística para cada curso)
    void poe_aluno_na_estatistica(map<string, Estatistica*>& estatistica, double media_do_aluno, string nome_do_curso) {
        Estatistica* estatistica_aux = estatistica.find(nome_do_curso)->second;

        /* Se já existir uma estatística para o curso especificado, ocorre a adição da média do aluno àquela estatística
         do contrário, uma nova estatística é criada. */
        if (estatistica_aux == estatistica.end()->second) { //Se não encontrou
            Estatistica* est = new Estatistica(media_do_aluno, nome_do_curso);
            estatistica.insert(pair<string, Estatistica*>(nome_do_curso, est));
        } else {
            estatistica_aux->poeNota(media_do_aluno); //Se encontrou
        }
    }
}

