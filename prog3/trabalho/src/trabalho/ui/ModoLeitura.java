/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho.ui;

import trabalho.Planilhas;
import trabalho.Disciplina;
import java.awt.event.*;
import java.io.FileNotFoundException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
import trabalho.exception.DadoInconsistenteException;
import trabalho.exception.ElementoRepetidoException;

/**
 *
 * @author Jordão
 */
public class ModoLeitura extends Modo{
    protected JButton botaoLerCursos ;
    protected JButton botaoLerDisciplinas ;
    protected JButton botaoLerAvaliacoes ;
    protected JButton botaoLerAluno ;
    protected JButton botaoLerNota ;
    protected final JTable tabelaC = criaTable();
    protected JScrollPane sC;
    protected final JTable tabelaD = criaTable();
    protected JScrollPane sD;
    protected final JTable tabelaAv = criaTable();
    protected JScrollPane sAv;
    protected final JTable tabelaA = criaTable();
    protected JScrollPane sA;
    protected final JTable tabelaN = criaTable();
    protected JScrollPane sN;
    public ModoLeitura() {
       
    }
    public void geraBotaoRelatorio(){
        if(A.criaListaOrdenadaAlunos().size()>0 && D.criaListaDisciplinasOrdenada().size()>0 && !estadoBotaoRelatorio){
            painel.add(relatorio);
            estadoBotaoRelatorio = true;
        }
    }
    
}
