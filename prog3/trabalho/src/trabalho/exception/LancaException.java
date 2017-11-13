/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho.exception;

import java.util.*;

/**
 *
 * @author jordao
 */
public class LancaException {

    public static void E1(int matricula, String saux) throws DadoInconsistenteException {
        throw new DadoInconsistenteException("Tipo de aluno de pós-graduação desconhecido para " + matricula + ":" + saux + ".");
    }

    public static void E2(int matricula, String tipo) throws DadoInconsistenteException {
        throw new DadoInconsistenteException("Tipo de aluno desconhecido para " + matricula + ":" + tipo + ".");
    }

    public static void E3(int matricula) throws ElementoRepetidoException {
        throw new ElementoRepetidoException("Matrícula repetida para aluno: " + matricula + ".");
    }

    public static void E4(String codigoAvaliacao, double peso) throws DadoInconsistenteException {
	String Peso = Double.toString(peso).replace(".",",");
        throw new DadoInconsistenteException("Peso de avaliação inválido para " + codigoAvaliacao + ":" + Peso + ".");
    }

    public static void E5(String codigoAvaliacao, int tamanho) throws DadoInconsistenteException {
        throw new DadoInconsistenteException("Tamanho máximo de grupo inválido para trabalho " + codigoAvaliacao + ":" + tamanho + ".");
    }

    public static void E6(String codigoAvaliacao, int tamanho) throws DadoInconsistenteException {
        throw new DadoInconsistenteException("Tamanho máximo de grupo especificado para a prova "
                + codigoAvaliacao + ":" + tamanho + ".");
    }

    public static void E7(String codigo, String s, double nota) throws DadoInconsistenteException {
      	String Nota = Double.toString(nota);
	Nota = Nota.replace(".",",");
        throw new DadoInconsistenteException("Nota inválida para avaliação " + codigo + " do(s) aluno(s) " + s + ": " + Nota + ".");
    }
    
    public static void E8(String s, String codigo) throws DadoInconsistenteException {
        throw new DadoInconsistenteException("Código de avaliação não definido usado na planilha de notas, associado ao(s) aluno(s)" + s + ":" + codigo + ".");
    }
}
