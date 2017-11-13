/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho.ui;

import trabalho.Cursos;
import trabalho.Alunos;
import trabalho.Disciplinas;
import trabalho.Avaliacoes;
import java.awt.Color;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.LineBorder;

/**
 *
 * @author Jordão
 */
public class Modo {
    public Disciplinas D;
    public Alunos A;
    public Cursos C;
    public Avaliacoes Av;
    protected JFrame janela ;
    public EscolheFile escolha ;
    protected JButton botaoSair ;
    
    protected JButton relatorio;
    protected boolean estadoBotaoRelatorio = false;
    public JPanel painel;
    ActionListener sairListener = new ActionListener() {
    @Override
    public void actionPerformed(ActionEvent e) {
        janela.dispose();
      }
    };
    public Modo(){
       D = new Disciplinas();
       A = new Alunos();
       C = new Cursos();
       Av = new Avaliacoes();
       escolha = new EscolheFile();
       botaoSair = new JButton("Sair");
       relatorio = new JButton("Gerar Relatorio");
       painel = new JPanel();
       ActionListener sairListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                janela.dispose();
              }
        };
        botaoSair.addActionListener(sairListener);
    }
    public static JTable criaTable(){
        JTable table = new JTable();
        table.setBorder(new LineBorder(Color.black));
        table.setGridColor(Color.black);
        table.setShowGrid(true);
        return table;
    }  
    public static JScrollPane criaScroll(JTable table){
        JScrollPane scroll = new JScrollPane(); 
        scroll.getViewport().setBorder(null);
        scroll.getViewport().add(table); 
        scroll.setSize(450, 450);
        return scroll;
    }
}
