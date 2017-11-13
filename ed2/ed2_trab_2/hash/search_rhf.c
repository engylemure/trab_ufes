//
// Created by jordao on 04/07/17.
//

#include "search_rhf.h"

Word* search_query(char* query,short *alphabet,RHF* hash){
    int i=0,j=0,n=0,n_query= strlen(query);
    Word* query_w = new_word(256,query);
    int n_equal;
    char *pal=malloc(sizeof(char)*256);
	*pal = '\0';
    Word* hi;
    int aux = false;
    int n_s=1;
    for(i=0;i<n_query;i++)if(query[i]==' ')n_s++;
    Word* query_v[n_s];
    for(i=0;i<n_query;i++){
        if (alphabet[query[i]])
        { sprintf(pal + strlen(pal), "%c", query[i]);
            aux = true;
        }
        else
        if (aux)
        {
			sprintf(pal+strlen(pal),"%c",'\0');
            hi = new_word(256,pal);
            query_v[n] = search_rhf(hash,hi,strcmp);
            n++;
            *pal = '\0';
            aux = false;
        }
    }
    if (aux)
    {
		sprintf(pal+strlen(pal),"%c",'\0');
        hi = new_word(256,pal);
        query_v[n] = search_rhf(hash,hi,strcmp);
        n++;
    }
    List ocr_v[n];
    int is_end=0;
    for(j=0;j<n;j++){
        if(query_v[j]!=NULL)
		{
			ocr_v[j]=query_v[j]->ocrb;
			//print_word(query_v[j]);
			//printf("\n");
		}
        else {is_end++;ocr_v[j]=NULL;}
    }
    if(n==1){
        if(query_v[0]!=NULL)
            return query_v[0];
        else return query_w;
    }
    int query_inline[hash->n_lines+1];
    for(j=0;j<hash->n_lines;j++)
        query_inline[j]=0;
    for(j=0;j<n;j++)
            while(ocr_v[j]!=NULL){
                query_inline[ocr_v[j]->info]+=1;
                ocr_v[j]=ocr_v[j]->next;
            }
    for(j=0;j<hash->n_lines;j++)
        if(query_inline[j]==n){
            //printf("inline=%d,n=%d\n",query_inline[j],n);
            List ocr_q = new_list(j);
            if(query_w->ocrb==NULL){
                query_w->ocrb = ocr_q;
                query_w->ocrf = ocr_q;
            }
            else {
                query_w->ocrf->next = ocr_q;
                query_w->ocrf = ocr_q;
            }
        }

    return query_w;
}