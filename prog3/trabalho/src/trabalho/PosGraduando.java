package trabalho;
import java.io.*;
import trabalho.exception.DadoInconsistenteException;
import trabalho.exception.LancaException;
/**
 * <i>Documentação da classe PosGraduando </i>
 *
 * @version 1.0
 * @since 05/05/2016
 * @author Jordão e Nicole
 */
public class PosGraduando extends Aluno implements Serializable{

    public static String[] tipos = {"Mestrado", "Doutorado"};
    private final String tipo;
    /**
     * Extends a classe Aluno.
     * @see Aluno
     * @param matricula
     * @param nome
     * @param tipo
     * @throws DadoInconsistenteException Lançado quando o tipo de Aluno de pos graduação não é nem M nem D
     */
    public PosGraduando(int matricula, String nome, String tipo) throws DadoInconsistenteException {
        super(matricula, nome);       
        switch (tipo) {
            case "M":
                this.tipo = tipos[0];
                break;
            case "D":
                this.tipo = tipos[1];
                break;
            default:
                this.tipo = "";
                LancaException.E1(matricula, tipo);
                break;
        }
    }
        
    public String getTipo (){
        return tipo;
    }

    @Override
    public String toString() {
        return super.toString() + ",PosGraduacao: " + tipo;
    }
}
