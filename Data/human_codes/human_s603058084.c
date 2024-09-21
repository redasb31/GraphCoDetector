#include <stdio.h>
#include <stdlib.h>

#define MAX 500000

typedef struct _list{
    int data;
    struct _list *next;
}list;
typedef struct{
    list *head;
    list *tail;
}LIST;

void dump(LIST l){
    list *p=l.head;
    while(p!=NULL){
        if(p==l.head)printf("%d",p->data);
        else printf(" %d",p->data);
        p=p->next;
    }
    printf("\n");
}
void freeAll(LIST l[],int n){
    int i;
    list *p,*pp;
    for(i=0;i<n;i++){
        p=l[i].head;
        while(p!=NULL){
            pp=p;
            free(p);
            p=pp->next;
        }
    }
}

int main(){
    int i;
    
    int n,q;
    scanf("%d %d\n",&n,&q);
    
    LIST l[n];
    for(i=0;i<n;i++){
        l[i].head=NULL;
        l[i].tail=NULL;
    }
    
    int com,t,x,s;
    while(q--){
        scanf("%d ",&com);
        switch(com){
            case 0:
                //insert
                scanf("%d %d\n",&t,&x);
                if(l[t].head==NULL){
                    l[t].head=(list*)malloc(sizeof(list));
                    l[t].head->data=x;
                    l[t].head->next=NULL;
                    l[t].tail=l[t].head;
                }else{
                    l[t].tail->next=(list*)malloc(sizeof(list));
                    l[t].tail=l[t].tail->next;
                    l[t].tail->data=x;
                    l[t].tail->next=NULL;
                }
                break;
            case 1:
                //dump
                scanf("%d\n",&t);
                dump(l[t]);
                break;
            case 2:
                //splice
                scanf("%d %d\n",&s,&t);
                if(l[t].tail!=NULL)l[t].tail->next=l[s].head;
                else l[t].head=l[s].head;
                l[t].tail=l[s].tail;
                l[s].head=NULL;
                l[s].tail=NULL;
                break;
        }
    }
    
    freeAll(l,n);
    
    return 0;
}
