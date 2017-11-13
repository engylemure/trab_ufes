/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open
/*
 * File:   manipula_string.hpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 19:42
 */

#ifndef MANIPULA_STRING_HPP
#define MANIPULA_STRING_HPP

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include "Curso.hpp"

using namespace std;

namespace ufes_sys{

    string remove_char(const string& s, char c);

    vector<string> split_string(const string& s, char r);

    string remove_bandechar(const string& s, char c);

}


#endif /* MANIPULA_STRING_HPP */
