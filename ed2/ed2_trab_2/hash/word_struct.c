//
// Created by jordao on 22/06/17.
//

#include "word_struct.h"
Word* new_word(int size,char* content){
    Word* new = malloc(sizeof(Word));
    new->size=(size_t)size;
    new->content=strdup(content);
    new->ocrb = NULL;
    new->ocrf = NULL;
    new->next = NULL;
    return new;
}
Word* insert_ocrl(Word* aux, List ocr){
    if(aux==NULL)return NULL;
    if(aux->ocrf==NULL){
        aux->ocrf = ocr;
        aux->ocrb = ocr;
        return aux;
    }
    if(aux->ocrf->info==ocr->info) return aux;
    aux->ocrf->next=ocr;
    aux->ocrf=ocr;
    return aux;
}
Word* insert_word(Word* head,Word* inserted){
    if(head==NULL){head=inserted;return inserted;}
    else{
        Word* aux = head;
        while(aux->next!=NULL || !strcmp(aux->content,inserted->content)){
            if(!strcmp(aux->content,inserted->content)){
                insert_ocrl(aux,inserted->ocrb);
                return head;
            }
            aux=aux->next;
        }
        aux->next=inserted;
    }
    return head;
}
Word* search_word(Word* head,Word* searched,int (*cmp)(const char*,const char*)){
    if(head==NULL)return NULL;
    else{
        Word* aux = head;
        while(aux!=NULL){
            if(!cmp(aux->content,searched->content)){
                return aux;
            }
            aux=aux->next;
        }
        return NULL;
    }
}
void print_word(Word* word){
    if(word==NULL)return;
    printf("%-20s",word->content);
    print_list(word->ocrb);
}