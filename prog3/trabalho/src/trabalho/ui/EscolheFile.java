/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho.ui;

import java.io.*;
import javax.swing.*;
import javax.swing.filechooser.*;

/**
 *
 * @author Jordão
 */
public class EscolheFile {
    public FileReader arqC;
    public FileReader arqD;
    public FileReader arqAv;
    public FileReader arqA;
    public FileReader arqN;
    public static FileReader escolhe(){
        try{
        JFileChooser e = new JFileChooser();
        e.setFileFilter(new FileNameExtensionFilter("Apenas CSV","csv"));
        int retorno = e.showOpenDialog(null);
        if(retorno == JFileChooser.APPROVE_OPTION)return new FileReader(e.getSelectedFile());
        return null;
        }
        catch(FileNotFoundException ex){
            ex.printStackTrace();
        }
        return null;
    }
    
    
}
