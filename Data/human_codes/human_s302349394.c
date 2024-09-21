#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        int data;
        struct node *next;
        struct node *prev;
        struct node *head;
        struct node *last;
}stack;
typedef struct {
        stack pair;
        stack area;
}areapair;
void Push_back(stack**, stack**, int);
int Pop_back(stack**, stack**);
main()
{
        int i, ch, count = 0, sum = 0;
        char str[20001];
        stack S1, *p;
        areapair S2;
        S1.head = S1.last = S2.pair.head = S2.pair.last
                = S2.area.head = S2.area.last = NULL;
        scanf("%s", str);
        for(i = 0; str[i]; i++){
                if(str[i] == '\\'){
                        Push_back(&(S1.head), &(S1.last), i);
                }else if(S1.head != NULL && str[i] == '/'){
                        int j = Pop_back(&(S1.head), &(S1.last));
                        int a = i - j;
                        sum += i - j;
                        count++;
                        while(S2.pair.head != NULL && S2.pair.last -> data > j){
                                a += S2.area.last -> data;
                                Pop_back(&(S2.pair.head), &(S2.pair.last));
                                Pop_back(&(S2.area.head), &(S2.area.last));
                                count--;
                        }
                        Push_back(&(S2.pair.head), &(S2.pair.last), j);
                        Push_back(&(S2.area.head), &(S2.area.last), a);
                }
        }
        printf("%d\n%d", sum, count);
        p = S2.area.head;
        while(p != NULL){
                printf(" %d", p -> data);
                p = p -> next;
        }
        putchar('\n');
}
void Push_back(stack **head, stack **last, int data)
{
        stack *p;
        if((p = (stack*)malloc(sizeof(stack))) == NULL){
                fprintf(stderr, "Memory cannot allocate\n");
                exit(0);
        }
        p -> data = data;
        p -> next = NULL;
        p -> prev = *last;
        if(*head == NULL){
                        *head = p;
        }else{
                        (*last) -> next = p;
        }
        *last = p;
}
int Pop_back(stack **head, stack **last)
{
        int pop_data;
        stack *p = *last;
        if(*head == NULL){
                return EOF;
        }
        pop_data = (*last) -> data;
        if((*last) -> prev == NULL){
                *head = NULL;
        }else{
                        (*last) -> prev -> next = NULL;
        }
                *last = (*last) -> prev;
        free(p);
        return pop_data;
}