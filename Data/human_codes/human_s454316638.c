#include <stdio.h>
#include <stdlib.h>

#define infty 999

typedef struct{
  int v1;
  int v2;
  int weight;
} Edge;

void heapsort(Edge *array, int n);
void downheap(Edge *array, int k, int n);
int find(int value1, int value2, int head, int tail, Edge *array);
int check_tree(int value1, int value2);

int *tree;

int main(int argc, char **argv)
{
  int n, i, j, tmp, head, tail, total_weight;
  Edge *label, *edge,  value;

  while(scanf("%d", &n) != EOF){
  edge = (Edge *)calloc((n+1)*(n+1), sizeof(Edge));
  tree = (int *)calloc((n+1), sizeof(int));
  head = tail = total_weight = 0;
  for(i = 1; i <= n; i++){
    tmp = i * n;
    for(j = 1; j <= n; j++){
      edge[tmp+j].v1 = i;
      edge[tmp+j].v2 = j;
      scanf("%d", &edge[tmp+j].weight);
      if(edge[tmp+j].weight == 0){
	edge[tmp+j].weight = infty;
      } else if(edge[tmp+j].weight < edge[j*n+i].weight){
	edge[tmp+j].weight = edge[j*n+i].weight;
      } else if(edge[tmp+j].weight > edge[j*n+i].weight){
	edge[j*n+i].weight = edge[tmp+j].weight;
      }
    }
  }

  heapsort(edge, (n*n));

  for(i = 0; i <= n; i++){
    tmp = i * n;
    for(j = 0; j <= n; j++){
      if(head == 0 && edge[tmp+j].weight >0) head = tmp+j;
      else if(tail == 0 && edge[tmp+j].weight == infty){ 
	tail = tmp+j;
	break;
      }
    }
  }

  i = 0;
  label = (Edge *)calloc(tail-head, sizeof(Edge));
  while(head < tail){
    value = edge[head++];
    if(check_tree(value.v1, value.v2)){
      label[i++] = value;
      if(i == (n-1)) break;
    }
  }
  for(j = 0; j < i; j++){
    total_weight += label[j].weight;
  }

  printf("%d\n", total_weight);

  free(label);
  free(edge);
  free(tree);
  }

  return 0;
}

void heapsort(Edge *array, int n)
{
  int i;
  Edge tmp;

  for(i = n/2; i >= 1; i--) downheap(array, i, n);
  for(i = n; i >= 2; i--){
    tmp = array[1];
    array[1] = array[i];
    array[i] = tmp;
    downheap(array, 1, i-1);
  }
}

void downheap(Edge *array, int k, int n)
{
  int j;
  Edge value = array[k];

  while(k <= n/2){
    j = k + k;
    if(j < n && array[j].weight < array[j+1].weight) j++;
    if(value.weight >= array[j].weight) break;
    array[k] = array[j];
    k = j;
  }
  array[k] = value;
}

int check_tree(int value1, int value2)
{
  int val1 = value1, val2 = value2;

  while(tree[val1] > 0) val1 = tree[val1];
  while(tree[val2] > 0) val2 = tree[val2];
  if(val1 != val2) tree[val2] = val1;

  return val1 != val2;
}