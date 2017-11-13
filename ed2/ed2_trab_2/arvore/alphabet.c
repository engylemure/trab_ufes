//
// Created by jordao on 04/07/17.
//

#include "alphabet.h"
void create_alphabet(char *filename, short *alphabet){
    FILE* file = fopen(filename,"r");
    char symbols[MAX_A+1],*temp;
    fgets(symbols,MAX_A+1,file);
    int i;
    for(i=0;i<=MAX_A;i++)alphabet[i] = false;
    temp = strchr(symbols,'\n');
    if(temp!=NULL)*temp = 0;
    int n_symbols = strlen(symbols);
    for(i=0;i<n_symbols;i++)
        alphabet[symbols[i]]= true;
    alphabet[0] = false;
    fclose(file);
}