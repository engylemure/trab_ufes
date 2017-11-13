package trabalho;

import java.util.*;
import java.io.*;

/**
 * <i>Documentação da classe Avaliacao </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Notas implements Serializable {

    public List<Nota> notas;

    public Notas() {
        notas = new ArrayList<Nota>();
    }

    public void imprimeNotas() {
        for (Nota inota : notas) {
            System.out.println(inota);
        }
    }

    public double getNotaAluno(int matricula) {
        for (Nota inota : notas) {
            for (Aluno aux : inota.getAlunos()) {
                if (aux.getMatricula() == matricula) {
                    return inota.getValor();
                }
            }
        }
        return 0.0;//Não achou o aluno
    }

    public void ordenaNotas() {
        Collections.sort(notas);
    }
}
