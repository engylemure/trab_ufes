package trabalho;

import java.io.*;
import java.util.*;

/**
 * <i>Documentação da classe Curso </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Curso implements Serializable {

    private int codigo;
    private String nome;

    public Curso(int codigo, String nome) {
        this.codigo = codigo;
        this.nome = nome;
    }

    @Override
    public String toString() {
        return ("Codigo do curso: " + codigo + ", nome: " + nome);
    }

    public String getNome() {
        return nome;
    }

    public int getCodigo() {
        return codigo;
    }

}
