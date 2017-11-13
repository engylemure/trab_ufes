package trabalho;

import java.io.*;

/**
 * <i>Documentação da classe Avaliacao </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Nota implements Serializable, Comparable<Nota> {

    private final double nota;
    private final Avaliacao avaliacao;
    private final Aluno[] alunos; //matricula do aluno que tem essa nota

    public Nota(double nota, Avaliacao avaliacao, Aluno[] alunos) {
        this.nota = nota;
        this.avaliacao = avaliacao;
        this.alunos = alunos;
    }

    public double getValor() {
        return nota;
    }

    public Avaliacao getAvaliacao() {
        return avaliacao;
    }

    public Aluno[] getAlunos() {
        return alunos;
    }

    public String toString() {
        String st = "";
        for (Aluno ialuno : alunos) {
            st = st.concat(ialuno.toString() + ",");
        }
        return alunos.length + " " + st + " Nota:" + nota;
    }

    @Override
    public int compareTo(Nota o) {
        return (int) (100 * (this.nota - o.getValor()));
    }
}
