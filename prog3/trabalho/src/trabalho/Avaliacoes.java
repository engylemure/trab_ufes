package trabalho;

import java.io.*;
import java.util.*;
import trabalho.exception.*;

/**
 * <i>Documentação da classe Avaliações </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Avaliacoes implements Serializable {

    private final Map<String, Avaliacao> avaliacoes;

    public Avaliacoes() {
        avaliacoes = new HashMap<>();
    }

    public void addAvaliacao(Avaliacao a) {
        avaliacoes.put(a.getCodigo(), a);
    }

    //Busca na lista uma avaliação específica.
    public Avaliacao buscaAvaliacao(String codigoAvaliacao) {
        return avaliacoes.get(codigoAvaliacao);
    }

    //Verica se já existe a avaliação no vetor de avaliações.
    public void verificaAvaliacaoRepetida(String codigoAvaliacao) throws ElementoRepetidoException {
        if (buscaAvaliacao(codigoAvaliacao) != null) {
            throw new ElementoRepetidoException("Código repetido para avaliação: " + codigoAvaliacao);
        }

    }

    public Collection<Avaliacao> getCollectionAvaliacao() {
        return avaliacoes.values();
    }

    public List<Avaliacao> criaListaOrdenadaAvaliacao() {
        List<Avaliacao> avaliacoes = new ArrayList<Avaliacao>();
        avaliacoes.addAll(this.getCollectionAvaliacao());
        Collections.sort(avaliacoes);
        return avaliacoes;
    }
}
