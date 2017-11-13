//
// Created by jordao on 22/06/17.
//

#include "ocr_list.h"

List new_list(int info)
{
    List new= malloc(sizeof(linked_list));
    new->info = info;
    new->next = NULL;
    return new;
}

List update_list(List head,List inserted)
{
    if(head==NULL) return inserted;
    
    if(inserted==NULL) return head;
    
    if(head->info == inserted->info) return head;
    
    head->next = inserted;
    return inserted;
}

void print_list(List head)
{
    if(head==NULL)return;
    List aux=head;
    while(aux!=NULL){
        printf("%d ",aux->info);
        aux=aux->next;
    }
}

void update_common_list(int* comum, List l)
{
    while(l)
    {
        comum[l->info]++;
        l=l->next;
    }
}