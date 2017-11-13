package trabalho.exception;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author jordao
 */
public class DisciplinaNaoEncontradaException extends Exception{
    public DisciplinaNaoEncontradaException(){
        super();
    }
    public DisciplinaNaoEncontradaException(String message){
        super(message);
    }
}
