#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NIL NULL

typedef struct Node {
    int key;
    int priority;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *newNode(int key, int priority) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->priority = priority;
    node->left = NIL;
    node->right = NIL;
    return node;
}

// Function to perform right rotation
Node *rightRotate(Node *t) {
    Node *s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

// Function to perform left rotation
Node *leftRotate(Node *t) {
    Node *s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

// Function to insert a node into the Treap
Node *insert(Node *t, int key, int priority) {
    if (t == NIL) {
        return newNode(key, priority);
    }
    if (key == t->key) {
        return t;
    }

    if (key < t->key) {
        t->left = insert(t->left, key, priority);
        if (t->priority < t->left->priority) {
            t = rightRotate(t);
        }
    } else {
        t->right = insert(t->right, key, priority);
        if (t->priority < t->right->priority) {
            t = leftRotate(t);
        }
    }
    return t;
}

// Function to delete a node from the Treap
Node *_delete(Node *t, int key) {
    if (t->left == NIL && t->right == NIL) {
        free(t);
        return NIL;
    } else if (t->left == NIL) {
        t = leftRotate(t);
    } else if (t->right == NIL) {
        t = rightRotate(t);
    } else {
        if (t->left->priority > t->right->priority) {
            t = rightRotate(t);
        } else {
            t = leftRotate(t);
        }
    }
    return _delete(t, key);
}

// Function to delete a node from the Treap (wrapper function)
Node *delete(Node *t, int key) {
    if (t == NIL) {
        return NIL;
    }
    if (key < t->key) {
        t->left = delete(t->left, key);
    } else if (key > t->key) {
        t->right = delete(t->right, key);
    } else {
        return _delete(t, key);
    }
    return t;
}

// Function to search for a key in the Treap
int find(Node *t, int key) {
    if (t == NIL) {
        return 0;
    }
    if (key == t->key) {
        return 1;
    }
    if (key < t->key) {
        return find(t->left, key);
    } else {
        return find(t->right, key);
    }
}

// Function to perform inorder traversal
void inorder(Node *t) {
    if (t != NIL) {
        inorder(t->left);
        printf(" %d", t->key);
        inorder(t->right);
    }
}

// Function to perform preorder traversal
void preorder(Node *t) {
    if (t != NIL) {
        printf(" %d", t->key);
        preorder(t->left);
        preorder(t->right);
    }
}

// Function to print the Treap
void print(Node *t) {
    printf("\n");
    inorder(t);
    printf("\n");
    preorder(t);
    printf("\n");
}

int main() {
    srand(time(NULL));
    Node *root = NIL;
    int m;
    scanf("%d", &m);
    while (m--) {
        char op[10];
        int key, priority;
        scanf("%s", op);
        if (op[0] == 'i') {
            scanf("%d %d", &key, &priority);
            root = insert(root, key, priority);
        } else if (op[0] == 'f') {
            scanf("%d", &key);
            if (find(root, key)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (op[0] == 'd') {
            scanf("%d", &key);
            root = delete(root, key);
        } else if (op[0] == 'p') {
            print(root);
        }
    }
    return 0;
}