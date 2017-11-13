/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Printable.hpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 17:15
 */

#ifndef PRINTABLE_HPP
#define PRINTABLE_HPP
namespace ufes_sys {
    class Printable {
    public:
        Printable() { };

        virtual void print() = 0;

        virtual ~Printable() { };
    private:

    };
}
#endif /* PRINTABLE_HPP */

