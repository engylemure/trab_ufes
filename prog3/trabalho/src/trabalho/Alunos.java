package trabalho;

import trabalho.exception.*;
import java.io.*;
import java.util.*;

/**
 * <i>Documentação da classe Alunos </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Alunos implements Serializable {
    
    protected Map<Integer, Aluno> alunos;
    /**
     * Construtor da classe Alunos.
     */
    public Alunos() {
        alunos = new HashMap<>();
    }
    /**
     * 
     * @param mat
     * @return Aluno referente a matricula, caso não exista, retorna nulo.
     * @see Aluno
     */
    public Aluno buscaPorMatricula(int mat) {
        return alunos.get(mat);
    }
    /**
     * 
     * @param a Adiciona o aluno aos Alunos. 
     */
    public void addAluno(Aluno a) {
        alunos.put(a.getMatricula(), a);
    }
    /**
     * 
     * @return Collection<Aluno>.
     * @see Collection
     */
    public Collection<Aluno> getCollectionAlunos() {
        return alunos.values();
    }
    /**
     * 
     * @return Lista ordenada por meio da Comparação realizada pela função compareTo de Aluno.
     * @see Aluno
     */
    public List<Aluno> criaListaOrdenadaAlunos() {
        List<Aluno> alunos = new ArrayList<Aluno>();
        alunos.addAll(this.getCollectionAlunos());
        Collections.sort(alunos);
        return alunos;
    }
}
