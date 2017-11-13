//
// Created by jordao on 22/06/17.
//
#include "string.h"
#include "word_struct.h"
#include <ctype.h>

Word* new_word(char* content)
{
    Word* new = malloc(sizeof(Word));
    new->content = strdup(content);
    new->ocrb = NULL;
    new->ocrf = NULL;
    return new;
}

void print_word(Word* word)
{
    if(word==NULL) return;

    printf("%-20s", word->content);
    print_list(word->ocrb);
    printf("\n");
}

int cmp_word(Word* word1, Word* word2)
{
    return strcasecmp (word1->content, word2->content);
}
