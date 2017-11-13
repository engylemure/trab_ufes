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

char* read_word(FILE* file,short *alphabet,int *i){
    char* word = malloc(sizeof(char)*(MAX_A+1));
    *word = '\0';
    char letra;
    int is_end,in_alphabet;
    while(!feof(file)) {
        is_end = fscanf(file, "%c", &letra) != 1;
        if(letra=='\n')(*i)=1;
        else *i = 0;
        if (alphabet[letra]) {
            sprintf(word + strlen(word), "%c", letra);
            in_alphabet = true;
        } else if(in_alphabet)
            {
                sprintf(word+strlen(word),"%c",'\0');
                return word;
            }
        if(is_end){
            sprintf(word+strlen(word),"%c",'\0');
            return word;
        }
    }
}