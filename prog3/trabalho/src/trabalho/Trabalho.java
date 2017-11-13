package trabalho;

import java.io.*;
import java.util.*;
/**
 * <i>Documentação da classe Trabalho </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Trabalho extends Avaliacao implements Serializable {

    private final int tamanho;
    private int qtdGrupos;

    public Trabalho(Disciplina d, String codigo, String nome, double peso, String tipo, int tamanho, Date data) {
        super(d, codigo, nome, peso, tipo, data);
        this.tamanho = tamanho;
        qtdGrupos = 0;
    }

    int getQuantidadeDeGrupos() {
        return qtdGrupos;
    }

    void setQuantidadeDeGrupos(int n) {
        qtdGrupos = n;
    }

    public int getTamanho() {
        return tamanho;
    }

    @Override
    public String toString() {
        return super.toString() + ", tamanho máximo de alunos por grupo: " + tamanho;
    }
}
