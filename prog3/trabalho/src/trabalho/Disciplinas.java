package trabalho;

import trabalho.exception.DisciplinaNaoEncontradaException;
import java.util.*;
import java.io.*;

/**
 * <i>Documentação da classe Disciplinas </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Disciplinas implements Serializable {

    private final Map<String, Disciplina> disciplinas;

    public Disciplinas() {
        disciplinas = new HashMap<String, Disciplina>();
    }

    public boolean addDisciplina(Disciplina d) {
        disciplinas.put(d.getCodigo(), d);
        return true;
    }

    public Disciplina buscaCodigo(String codigo) {
        Disciplina d = disciplinas.get(codigo);
        if (d != null) {
            return d;
        }
        return null;

    }

    public Collection<Disciplina> getCollectionsDisciplina() {
        return disciplinas.values();
    }

    public List<Disciplina> criaListaDisciplinasOrdenada() {
        List<Disciplina> disciplinas = new ArrayList<Disciplina>();
        disciplinas.addAll(this.disciplinas.values());
        Collections.sort(disciplinas);
        return disciplinas;
    }

}
