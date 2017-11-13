package trabalho;

import java.io.*;
import java.text.*;
import java.util.*;
import trabalho.exception.*;

/**
 * <i>Documentação da classe Relatorios </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Relatorios {

    private static final DecimalFormat df = new DecimalFormat("0.##");
    private static final SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

    public static void geraRelatorioDisciplina(PrintWriter arq, Disciplina disciplina) throws DadoInconsistenteException, DadoAusenteException {
        arq.print("Matrícula;Aluno;");
        List<Avaliacao> avaliacoes = disciplina.getAvaliacoes().criaListaOrdenadaAvaliacao();
        if (disciplina.getAvaliacoes().getCollectionAvaliacao().isEmpty()) {
            throw new DadoAusenteException("A disciplina " + disciplina.getCodigo() + " não possui nenhuma avaliação cadastrada.");
        }
        for (Avaliacao iavaliacao : avaliacoes) {
            if (!iavaliacao.getTipo().equals("F")) {
                arq.print(iavaliacao.getCodigo() + ";");
            }
        }

        arq.println("Média Parcial;Prova Final;Média Final");
        List<Aluno> alunos = disciplina.getAlunos().criaListaOrdenadaAlunos();
        for (Aluno ialuno : alunos) {
            Nota[] notasDoAluno;
            double[] notas = ialuno.getVetorNotas(disciplina);
            
            arq.print(ialuno.getMatricula() + ";" + ialuno.getNome());
            int i =0;
            for (double nota : notas) {
                if (nota >= 7.0 && i == (notas.length - 3)) {
                    arq.printf(";%.2f;-;%.2f", nota, notas[notas.length - 1]);
                    break;
                }
                arq.printf(";%.2f", nota);
                i++;
            }
            arq.println();

        }
        arq.close();
    }

    public static String[] geraRelatorioDisciplinas(Disciplinas D) throws DadoInconsistenteException, DadoAusenteException {
        String[] s =null;
        try {
            List<Disciplina> disciplinas = D.criaListaDisciplinasOrdenada();
            s = new String[disciplinas.size()];
            int i= 0;
            for (Disciplina idisciplina : disciplinas) {
                s[i] = "1-pauta-" + idisciplina.getCodigo() + ".csv";
                Relatorios.geraRelatorioDisciplina(new PrintWriter("1-pauta-" + idisciplina.getCodigo() + ".csv"), idisciplina);
                i++;
            }
        } catch (IOException e) {
            System.out.println(e);
        }
        return s;
    }
    
    public static String geraRelatorioAavaliacoes(Disciplinas d) throws IOException {
        PrintWriter saidaAvaliacoes = new PrintWriter("3-avaliacoes.csv");
            saidaAvaliacoes.println("Disciplina;Código;Avaliação;Data;Média");
            List<Disciplina> disciplinas = d.criaListaDisciplinasOrdenada();
            for (Disciplina idisciplina : disciplinas) {
                //Dentro de uma disciplina, vai nas avaliações percorrendo cada avaliacao
                List<Avaliacao> avaliacoes = idisciplina.getAvaliacoes().criaListaOrdenadaAvaliacao();
                for (Avaliacao iavaliacao : avaliacoes) {
                    if (!iavaliacao.getTipo().equals("F")) {
                        //Dentro de uma avaliacao faz a estatistica:
                        double media = 0;
                        double i = 0;
                        for (Nota inota : iavaliacao.getNotas().notas) {
                            //Percorre o vetor de nota pegando cada nota para a media
                            media += inota.getValor();
                            i++;
                        }
                        media /= i;
                        saidaAvaliacoes.print(idisciplina.getCodigo() + ";" + iavaliacao.getCodigo() + ";" + iavaliacao.getNome()
                                + ";" + sdf.format(iavaliacao.getData()) + ";");
                        saidaAvaliacoes.printf("%.2f%n", media);
                    }
                }
            }
            saidaAvaliacoes.close();
            return "3-avaliacoes.csv"; 
    }

    public static double mediaDoAluno(Aluno ialuno, Disciplina disciplina) {
        double[] notas = ialuno.getVetorNotas(disciplina);
        return notas[notas.length - 1];
    }
    
    public static String geraRelatorioEstatisticaPorDisciplina(Disciplinas d) throws IOException {
        PrintWriter arq = new PrintWriter("2-disciplinas.csv");
        arq.println("Código;Disciplina;Curso;Média;% Aprovados");

        List<Disciplina> disciplinas = d.criaListaDisciplinasOrdenada();
        for (Disciplina idisciplina : disciplinas) {

            //Faz a estatistica para cada disciplina
            List<Estatistica> estatistica = new ArrayList<Estatistica>();
            List<Aluno> alunos = idisciplina.getAlunos().criaListaOrdenadaAlunos();
            for (Aluno ialuno : alunos) {

                String i = null;
                    i = ialuno.getTipo();
                double media = Relatorios.mediaDoAluno(ialuno, idisciplina);
                Relatorios.poeAlunoNaEstatistica(estatistica, media, i);
            }
            //Tendo a lista de estatistica dessa disciplina pronta pode se fazer a media e o percentual
            //Ordenar vetor por nota (descrescente)
            Collections.sort(estatistica);
            for (Estatistica iestatistica : estatistica) {
                //para cada est fazer a media e o percentual!
                arq.print(idisciplina.getCodigo() + ";" + idisciplina.getNome() + ";" + iestatistica.getNomeCurso() + ";");
                arq.printf("%.2f;%.1f", iestatistica.calculaMedia(), iestatistica.calculaPorcentagem());
                arq.println("%");

            }
            //s arq.print(";" + idisciplina.getCodigo() + idisciplina.getNome() + ";");
        }
        arq.close();
        return "2-disciplinas.csv";
    }

    public static void poeAlunoNaEstatistica(List<Estatistica> lista, double mediaAluno, String nome) {
        for (Estatistica i : lista) {
            if (i.getNomeCurso().equals(nome)) {
                i.poeNota(mediaAluno);
                return;
            }
        }
        Estatistica aux = new Estatistica(mediaAluno, nome);
        lista.add(aux);
    }
}
