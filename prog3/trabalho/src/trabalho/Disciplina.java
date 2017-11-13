package trabalho;

import java.io.*;
import java.util.*;

/**
 * <i>Documentação da classe Disciplina </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Disciplina implements Comparable<Disciplina>, Serializable {

    private final String codigo;
    private final String nome;
    protected Avaliacoes avaliacoes;
    protected Alunos alunos;

    public Disciplina(String codigo, String nome) {
        this.avaliacoes = new Avaliacoes();
        this.alunos = new Alunos();
        this.codigo = codigo;
        this.nome = nome;
    }

    public String getCodigo() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public String toString() {
        return "Disciplina  Código: " + codigo + ", Nome: " + nome + "\n";
    }

    /**
     *  Função para comparar se dois objetos são equivalentes levando em consideração o codigo da disciplina.
     * @param o
     * @return true para caso sejam equivalentes e false para o contrario.
     */
    @Override
    public boolean equals(Object o) {
        Disciplina obj;
        if (o instanceof Disciplina) {
            obj = (Disciplina) o;
        } else {
            return false;
        }
        return obj.getCodigo().equals(codigo);
    }

    public Alunos getAlunos() {
        return alunos;
    }

    @Override
    public int compareTo(Disciplina o) {
        return codigo.compareTo(o.getCodigo());
    }

    public Avaliacoes getAvaliacoes() {
        return avaliacoes;
    }
}
