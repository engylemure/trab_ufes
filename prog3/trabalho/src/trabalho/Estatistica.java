package trabalho;

/**
 * <i>Documentação da classe Avaliacao </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class Estatistica implements Comparable<Estatistica> {

    private double nota;
    private String nomeDoCurso;
    private int numeroDeAlunos;
    private double porcentagem;
    private int qtdAlunosPassaram;

    public Estatistica(double nota, String nomeDoCurso) {
        this.nota = nota;
        this.nomeDoCurso = nomeDoCurso;
        numeroDeAlunos = 1;
        porcentagem = 0;
        if (this.nota >= 5.0) {
            qtdAlunosPassaram = 1;
        } else {
            qtdAlunosPassaram = 0;
        }
    }

    public void poeNota(double nota) {

        if (nota >= 5.0) {
            this.qtdAlunosPassaram++;
        }
        this.nota += nota;
        this.numeroDeAlunos++;
    }

    public double calculaMedia() {
        return (nota / numeroDeAlunos);
    }

    public String getNomeCurso() {
        return nomeDoCurso;
    }

    public double calculaPorcentagem() {
        return (100.0 * qtdAlunosPassaram / numeroDeAlunos);
    }

    @Override
    public int compareTo(Estatistica o) {
        int x = (int) (100.0 * (o.calculaMedia() - this.calculaMedia()));
        if (x == 0){
            return this.getNomeCurso().compareTo(o.getNomeCurso());
        }
        return x;
    }

}
