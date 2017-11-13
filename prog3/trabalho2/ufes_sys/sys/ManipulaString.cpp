/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   manipula_string.cpp
 * Author: nicole e jordao
 *
 * Created on 7 de Junho de 2016, 19:42
 */
#include "ManipulaString.hpp"
namespace ufes_sys {

    //Remove um char específico da string
    string remove_char(const string& s, char c) {
        string nova = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != c)nova += s[i];
        }
        return nova;
    }

    //Remove um char do inicio e do final
    string remove_bandechar(const string& s, char c){
        string nova = "";
        int aux = 0;
        if(s[0]==c)aux = 1;
        for(int i =aux; i < s.length()-1; i++ ){
            nova+=s[i];
        }
        bool x = s[s.length()-1]==c;
        if(x)return nova;
        else {
            nova+=s[s.length()-1];
            return nova;
        }
    }

    //Separa uma string em n string contendo como separador o char r
    vector<string> split_string(const string& s, char r) {
        stringstream s_stream(s);
        vector<string> array;
        int i = 0;
        string aux;
        while (!s_stream.eof()) {
            getline(s_stream, aux, r);
            array.push_back(aux);
        }
        return array;
    }
}
