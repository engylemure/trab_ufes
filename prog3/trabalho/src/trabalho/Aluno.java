package trabalho;

import java.io.*;
import java.util.*;

/**
 * <i>Documentação da classe Aluno </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public abstract class Aluno implements Comparable<Aluno>, Serializable {

    private final String nome;
    private final int matricula;
    /**
     * Disciplinas na qual o aluno se encontra matriculado.
     */
    private final Disciplinas disciplinas;
    /**
     * Notas que o aluno possui em avaliações.
     */
    private final Notas notas;

    /**
     * Construtor da classe Aluno.
     *
     * @param matricula Numero de matricula do aluno.
     * @param nome Nome do aluno.
     */
    public Aluno(int matricula, String nome) {
        this.matricula = matricula;
        this.nome = nome;
        this.notas = new Notas();
        this.disciplinas = new Disciplinas();
    }

    /**
     *
     * @return O numero de matricula do aluno.
     */
    public int getMatricula() {
        return matricula;
    }

    /**
     *
     * @return O nome do aluno.
     */
    public String getNome() {
        return nome;
    }

    /**
     *
     * @return Disciplinas em que o aluno está matriculado.
     */
    public Disciplinas getDisciplinas() {
        return disciplinas;
    }

    /**
     *
     * @return Notas que o aluno possui em avaliações.
     */
    public Notas getNotas() {
        return notas;
    }

    @Override
    public String toString() {
        return "Aluno :" + nome + ", Matricula: " + matricula;
    }

    /**
     *
     * @param o Aluno a ser comparado.
     * @return O resultado da comparação entre o nome do Aluno a ser comparado e
     * this Aluno.
     */
    @Override
    public int compareTo(Aluno o) {
        return nome.compareTo(o.getNome());
    }

    /**
     *
     * @param d Disciplina da qual se quer obter o vetor de notas.
     * @return Um vetor double contendo as notas contidas em cada uma das
     * disciplinas levando em consideração a ordem das avaliações por codigo,
     * contendo a media parcial, prova final e media final. O vetor possui
     * tamanho igual a Nº de avaliações+3.
     */
    public double[] getVetorNotas(Disciplina d) {
        double mediaParcial = 0.0;
        double pesoTotal = 0.0;
        List<Avaliacao> aux = d.getAvaliacoes().criaListaOrdenadaAvaliacao();
        double[] notas;
        int x = 0;
        for (Avaliacao iavaliacao : aux){
            if (iavaliacao.getTipo().equals("F")){
                x = 1;
                break;
            }
        }
        if (x == 1){
            notas = new double[aux.size() + 2];
        } else {
            notas = new double[aux.size() + 3];
        }
        int i = 0;
        double provafinal = 0;
        if (aux.size() > 0) {
            for (Avaliacao iavaliacao : aux) {
                Notas avalnotas = iavaliacao.getNotas();

                if (!iavaliacao.getTipo().equals("F")) {
                    notas[i] = avalnotas.getNotaAluno(this.matricula);
                    mediaParcial += notas[i] * iavaliacao.getPeso();
                    pesoTotal += iavaliacao.getPeso();
                    i++;
                } else {
                    provafinal = avalnotas.getNotaAluno(this.matricula);
                }
            }
        } else {
            System.out.println("ERRO");
        }
        mediaParcial = mediaParcial / pesoTotal;

        notas[i] = mediaParcial;
        notas[i + 1] = provafinal;
        notas[i + 2] = mediaParcial;
        if (notas[i + 2] < 7.0) {
            notas[i + 2] = (mediaParcial + provafinal) / 2;
        }
        return notas;
    }
    public abstract String getTipo();
}
