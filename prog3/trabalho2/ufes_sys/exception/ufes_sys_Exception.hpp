/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ufes_sys_Exception.hpp
 * Author: jordao
 *
 * Created on 30 de Junho de 2016, 14:50
 */

#ifndef UFES_SYS_EXCEPTION_HPP
#define UFES_SYS_EXCEPTION_HPP
#include <iostream>
using namespace std;
namespace ufes_sys{
                class ufes_sys_Exception : public exception {
                    private:
                    string e;
                public:
                    ufes_sys_Exception();
                    ufes_sys_Exception(string e);
                    virtual const char* what() const throw (){
                        return (e).c_str();
                    }
                };
}


#endif /* UFES_SYS_EXCEPTION_HPP */

