/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho.ui;

import java.util.*;
import javax.swing.table.*;

/**
 *
 * @author jordao
 */
public class RelatorioTableModel extends AbstractTableModel{
    List<String[]> info;
    String[] cabecalho;
    public RelatorioTableModel(List<String[]> info){
        this.info = info;
        cabecalho = info.get(0);
    }
    @Override
    public int getRowCount() {
        return info.size()-1;
    }

    @Override
    public int getColumnCount() {
        return info.get(0).length;
    }
    @Override
    public Object getValueAt(int arg0, int arg1) {
        String[] aux = info.get(arg0+1);
        return aux[arg1];
    }
    @Override
    public String getColumnName(int column) {
        return cabecalho[column];
    }
    
}
