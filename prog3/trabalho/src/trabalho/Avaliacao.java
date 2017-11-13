package trabalho;

import java.io.*;
import java.util.*;
/**
 * <i>Documentação da classe Avaliacao </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Avaliacao implements Serializable, Comparable<Avaliacao> {

    private final Disciplina disciplina;
    private final String codigo;
    private final String nome;
    private final double peso;
    private final String tipo; // Deve ser T para trabalho, P para Prova, F para prova final
    private final Date data;
    private final Notas notas; // notas dos alunos na avaliação x
    /**
     * Construtor da classe Avaliacao.
     * @param d Disciplina associada a Avaliacao.
     * @param codigo Codigo da Avaliacao.
     * @param nome Nome da Avaliacao.
     * @param peso Peso da Avaliacao.
     * @param tipo Tipo da Avaliacao.
     * @param data Data em que a Avaliação sera realizada.
     */
    public Avaliacao(Disciplina d, String codigo, String nome, double peso, String tipo, Date data) {
        this.disciplina = d;
        this.codigo = codigo;
        this.nome = nome;
        this.peso = peso;
        this.tipo = tipo;
        this.data = data;
        this.notas = new Notas();
    }

    public String getCodigo() {
        return codigo;
    }

    public Disciplina getDisciplina() {
        return disciplina;
    }

    public double getPeso() {
        return peso;
    }

    public String getTipo() {
        return tipo;
    }

    public String getNome() {
        return nome;
    }

    public Notas getNotas() {
        return notas;
    }

    public Date getData() {
        return data;
    }

    @Override
    public String toString() {
        return ("Avaliacao: " + codigo + " ,nome: " + nome + ", Codigo Disciplina: "
                + disciplina.getCodigo() + ", peso: " + peso + ", tipo: " + tipo);
    }

    @Override
    public int compareTo(Avaliacao o) {
        return this.data.compareTo(o.getData());
    }
}
