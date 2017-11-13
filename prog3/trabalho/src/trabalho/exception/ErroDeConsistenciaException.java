/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho.exception;

/**
 *
 * @author nicole
 */
public class ErroDeConsistenciaException extends Exception{
    public ErroDeConsistenciaException(){
        super();
    }
    public ErroDeConsistenciaException(String e){
        super(e);
    }
}
