#include <stdio.h>
#include <string.h>
  
#define Max 500000
  
void insert(int); 
void find(int, int);
int successor(int);
void delete(int);
void Preorder(int);    /* ??????????????? */
void Inorder(int);     /* ??????????????? */
  
  
typedef struct{    /* p = parent, l = child, s = brother */
  int key;
  int p;
  int l[2];
} Node;
  
Node T[Max];
  
int main(){
  int i, n, k;
  char s[7];
  
  scanf("%d", &n);
  
  T[0].key = -1;
  
   
  for(i = 0; i < n; i++){
    T[i].l[0] = -1;
    T[i].l[1] = -1;
  
    scanf("%s", s);
  
    if(strcmp(s, "insert") == 0){
      scanf("%d", &T[i].key);
      insert(i);
    }
    else if(strcmp(s, "print") == 0){
      Inorder(0);
      printf("\n");
      Preorder(0);
      printf("\n");
    }
    else if(strcmp(s, "find") == 0){
      scanf("%d", &k);
      find(0, k);
    }
    else if(strcmp(s, "delete") == 0){
      scanf("%d", &k);
      delete(k);
    }
  }
    
  return 0;
}
  
  
void insert(int z){
  int x, y;
  
  y = -1;
  x = 0;
  
  if(z != 0){
    while(x != -1){
      y = x;
      if(T[z].key < T[x].key) x = T[x].l[0];
      else x = T[x].l[1];
    }
  }
  
  T[z].p = y;
  
  if(y != -1){
    if(T[z].key < T[y].key) T[y].l[0] = z;
    else T[y].l[1] = z;
  }
}
  
void find(int x, int k){
  
  if(x == -1) printf("no\n");
  else if(T[x].key == k) printf("yes\n");
  else if(k < T[x].key) find(T[x].l[0], k);
  else find(T[x].l[1], k);
}
  
int successor(int x){
  int y;
  
  if(T[x].l[1] != -1){
    x = T[x].l[1];
    while(T[x].l[0] != -1) x = T[x].l[0];
    return x;
  }
    
  else {
    y = T[x].p;
    while(y != -1 && x == T[y].l[1]){
      x = y;
      y = T[y].p;
    }
    return y;
  }
}
  
void delete(k){
  int x, y, z = 0;
  
  while(1){
    if(T[z].key == k) break;
    else if(k < T[z].key) z = T[z].l[0];
    else z = T[z].l[1];
  }
  
  if(T[z].l[0] == -1 || T[z].l[1] == -1) y = z;
  else y = successor(z);
  
  if(T[y].l[0] != -1) x = T[y].l[0];
  else x = T[y].l[1];
  
  if(x != -1) T[x].p = T[y].p;
  
  if(T[y].p != -1){
    if(y == T[T[y].p].l[0]) T[T[y].p].l[0] = x;
    else T[T[y].p].l[1] = x;
  }
  
  if(y !=  z) T[z].key = T[y].key;
  
}
  
  
void Preorder(int a){
  printf(" %d", T[a].key);
  
  if(T[a].l[0] != -1) Preorder(T[a].l[0]);
  if(T[a].l[1] != -1) Preorder(T[a].l[1]);
}
  
  
void Inorder(int a){
  if(T[a].l[0] == -1){
    printf(" %d", T[a].key);
    if(T[a].l[1] != -1) Inorder(T[a].l[1]);
  }
  else{
    Inorder(T[a].l[0]);
    printf(" %d", T[a].key);
    if(T[a].l[1] != -1) Inorder(T[a].l[1]);
  }
}