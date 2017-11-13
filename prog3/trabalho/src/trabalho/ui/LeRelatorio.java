/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho.ui;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

/**
 *
 * @author jordao
 */
public class LeRelatorio {

    public static List<String[]> leRelatorios(String s) throws FileNotFoundException {
        Scanner scan = new Scanner(new FileReader(s));
        List<String[]> info = new ArrayList<>();
        while (scan.hasNext()) {
            String[] aux = scan.nextLine().split(";");
            info.add(aux);
        }
        scan.close();
        return info;
    }

    public static void geraTable(String s) {
        RelatorioTableModel tabelaRelatorio = null;
        List<String[]> relatorio;
        try {
            relatorio = LeRelatorio.leRelatorios(s);
            tabelaRelatorio = new RelatorioTableModel(relatorio);
        } catch (FileNotFoundException ex) {
        }
        JPanel painel = new JPanel();
        final JFrame frame = new JFrame(s);
        JTable table = Modo.criaTable();
        table.setPreferredScrollableViewportSize(new Dimension(800,500));
        table.setModel(tabelaRelatorio);
        JScrollPane scroll = Modo.criaScroll(table);
        painel.add(scroll);
        frame.add(painel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(600, 600);
        frame.pack();
        frame.setVisible(true);
    }
}
