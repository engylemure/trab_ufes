//
// Created by jordao on 22/06/17.
//

#include "ocr_list.h"

List new_list(int info){
    List new= malloc(sizeof(linked_list));
    new->info = info;
    new->next = NULL;
    return new;
}

List insert_list(List head,List inserted){
    if(head==NULL){
        head=inserted;
        return inserted;
    }
    else{
        List aux = head;
        while(aux!=NULL && aux->next!=NULL){aux = aux->next;}
        aux->next = inserted;
    }
    return head;
}

void print_list(List head){
    if(head==NULL)return;
    List aux=head;
    while(aux!=NULL){
        printf("%d ",aux->info);
        aux=aux->next;
    }
}