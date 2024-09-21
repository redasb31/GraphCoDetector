#include <stdio.h>
#include <string.h>

#define QUEUE_ELEMENT 1000
#define TRUE 1
#define FALSE 0

typedef struct
{
    int buf[QUEUE_ELEMENT];
    int front;
    int rear;
}Queue;

int IsEmpty(Queue *pQue)
{
    return (pQue->front == pQue->rear) ? TRUE : FALSE;
}

void Enqueue(Queue *pQue, int key)
{
    pQue->buf[pQue->front++] = key;
    return;
}
void Front(Queue *pQue)
{
    if(IsEmpty(pQue))
    {
        return;
    }
    printf("%d\n", pQue->buf[pQue->rear]);
    
    return;
}
void Dequeue(Queue *pQue, int *pKey)
{
    if(IsEmpty(pQue))
    {
        return;
    }
    
    *pKey = pQue->buf[pQue->rear++];
    return;
}



Queue que[QUEUE_ELEMENT];

int main()
{
    memset(&que, 0, sizeof(que));
    
    int queNum;
    scanf("%d", &queNum);
    
    int queryNum;
    scanf("%d", &queryNum);

    for(int i = 0; i < queryNum; i++)
    {
        int query;
        int target;
        int key;
        int getKey;
        scanf("%d", &query);
        scanf("%d", &target);
        switch(query)
        {
            case 0:
                scanf("%d", &key);
                Enqueue(&que[target], key);
                break;
            case 1:
                Front(&que[target]);
                break;
            case 2:
                Dequeue(&que[target], &getKey);
                break;
        }
    }
    return 0;
}

