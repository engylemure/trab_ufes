//
// Created by jordao on 22/06/17.
//

#include "reverse_hfile.h"

RHF* new_rhf( int N, int M, int (*h_fun)(char*,int)){
    RHF *new = malloc(sizeof(RHF));
    new->hash_v = malloc(sizeof(Word*)*M);
    int i;
    for(i=0;i<M;i++)new->hash_v[i]=NULL;
    new->M = M;
    new->N = N;
    new->h_func=h_fun;
    return new;
}

Word* insert_rhf(RHF* hash,Word* w){
    int pos =hash->h_func(w->content,hash->M);
   // printf("%d %p\n",pos,hash->hash_v+sizeof(Word*)*pos);
    hash->hash_v[pos]=insert_word(hash->hash_v[pos],w);
    return w;
}
Word* search_rhf(RHF* hash,Word* w,int (*cmp)(const char*,const char*)){
    int pos =hash->h_func(w->content,hash->M);
    return search_word(hash->hash_v[pos],w,cmp);
}
void print_rhf(RHF* hash){
    int i;
    for(i=0;i<hash->M;i++){
        if(hash->hash_v[i]==NULL);
        else {
            printf("[%d]",i);
            Word* word = hash->hash_v[i];
            while(word!=NULL) {
                print_word(word);
                word = word->next;
            }
            printf("\n");
        }
    }
}