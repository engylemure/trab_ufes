package trabalho;

import java.io.*;
import trabalho.exception.*;

/**
 * <i>Documentação da classe Graduando </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Graduando extends Aluno implements Serializable {

    Curso atual;

    public Graduando(int matricula, String nome, Curso atual) {
        super(matricula, nome);
        this.atual = atual;
    }

    public Curso getCurso() {
        return atual;
    }

    @Override
    public String toString() {
        return super.toString() + ",codigo do Curso: " + atual.getCodigo();
    }

    @Override
    public String getTipo() {
        return atual.getNome();
    }
}
