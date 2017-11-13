package trabalho;

import java.io.*;
import java.util.*;

/**
 * <i>Documentação da classe Cursos </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Cursos implements Serializable {

    private final Map<Integer, Curso> cursos;

    public Cursos() {
        cursos = new HashMap<>();
    }

    public void addCurso(Curso c) {
        cursos.put(c.getCodigo(), c);
    }

    public Curso procuraCurso(int codigocurso) {

        return cursos.get(codigocurso);
    }

    public Collection getCollectionCursos() {
        return cursos.values();
    }

}
