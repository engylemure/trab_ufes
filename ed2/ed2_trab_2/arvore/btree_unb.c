#include "btree_unb.h"

//
// Created by jordao on 02/06/17.
//

BinTree* new_BinTree(Word* element)
{
    BinTree* new_bt = malloc(sizeof(BinTree));
    new_bt->element = element;
    new_bt->height = 0;
    new_bt->right = NULL;
    new_bt->left = NULL;

    return new_bt;
}

void insert_BinTree_init(BinTree* tree,BinTree* inserted, int(*cmp)(Word*,Word*))
{
    if(tree == NULL) return;

    if(inserted == NULL) return;

    inserted->height+=1;

    int comp = cmp(inserted->element,tree->element);

    if(!comp) return;

    if(comp < 0)
    {
        if(tree->left==NULL)
        {
            tree->left = inserted;
            return;
        }

        insert_BinTree_init(tree->left,inserted,cmp);
        return;
    }

    if(tree->right==NULL)
    {
        tree->right = inserted;
        return;
    }

    insert_BinTree_init(tree->right,inserted,cmp);
    return;
}

void insertLine_BinTree(BinTree* tree,BinTree* inserted, int(*cmp)(Word*,Word*))
{
    if(tree == NULL) return;

    if(inserted == NULL) return;

    int comp = cmp(inserted->element,tree->element);

    if(!comp)
    {
        tree->element->ocrf = update_list(tree->element->ocrf, inserted->element->ocrf);

        if(tree->element->ocrb==NULL)
            tree->element->ocrb = tree->element->ocrf;

        return;
    }

    if(comp < 0)
    {
        insertLine_BinTree(tree->left,inserted,cmp);
        return;
    }

    insertLine_BinTree(tree->right,inserted,cmp);
    return;
}

List searchListOcr_BinTree(BinTree* tree, Word* look_for, int(*cmp)(Word*,Word*))
{
    if(tree == NULL) return NULL;

    if(look_for == NULL) return NULL;

    int comp = cmp(look_for, tree->element);

    if(comp == 0)
      return tree->element->ocrb;

    if(comp<0)
        return searchListOcr_BinTree(tree->left,look_for,cmp);

    return searchListOcr_BinTree(tree->right,look_for,cmp);
}

void print_BinTree(BinTree* tree, void (*print)(Word*))
{
    if(tree==NULL) return;

    print_BinTree(tree->left, print);

    print(tree->element);

    print_BinTree(tree->right, print);
}

int tree_height(BinTree* tree)
{
    if(tree==NULL)return 0;

    if(tree->left==NULL && tree->right==NULL)
    {
        return tree->height;
    }

    int h_right = tree_height(tree->right),h_left=tree_height(tree->left);
    if(h_right>h_left)
    {
        return h_right;
    }
    return h_left;
}

int qtdNos_BinTree(BinTree* tree)
{
    if(tree == NULL) return 0;

    return 1 + qtdNos_BinTree(tree->left) + qtdNos_BinTree(tree->right);
}

void free_BinTree(BinTree* tree)
{
    if(tree!=NULL){
        free_BinTree(tree->left);
        free_BinTree(tree->right);
        free(tree->element);
        free(tree);
    }
}
