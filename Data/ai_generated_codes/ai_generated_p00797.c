#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20
#define MAX_TREE_SIZE 1000
#define MAX_STATEMENT_SIZE 1000

// Structure to represent a node in the family tree
typedef struct Node {
    char name[MAX_NAME_LEN];
    struct Node *parent;
    struct Node *children;
} Node;

// Function to create a new node
Node *newNode(char *name, Node *parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->parent = parent;
    node->children = NULL;
    return node;
}

// Function to add a child to a node
void addChild(Node *parent, Node *child) {
    child->parent = parent;
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        Node *temp = parent->children;
        while (temp->children != NULL) {
            temp = temp->children;
        }
        temp->children = child;
    }
}

// Function to find a node by its name
Node *findNode(Node *root, char *name) {
    if (strcmp(root->name, name) == 0) {
        return root;
    }
    Node *temp = root->children;
    while (temp != NULL) {
        Node *found = findNode(temp, name);
        if (found != NULL) {
            return found;
        }
        temp = temp->children;
    }
    return NULL;
}

// Function to check if a node is a descendant of another node
int isDescendant(Node *ancestor, Node *descendant) {
    if (descendant == NULL) {
        return 0;
    }
    if (strcmp(ancestor->name, descendant->name) == 0) {
        return 1;
    }
    return isDescendant(ancestor, descendant->parent);
}

// Function to check if a node is an ancestor of another node
int isAncestor(Node *ancestor, Node *descendant) {
    return isDescendant(descendant, ancestor);
}

// Function to check if two nodes are siblings
int isSibling(Node *node1, Node *node2) {
    if (node1->parent == NULL || node2->parent == NULL) {
        return 0;
    }
    return strcmp(node1->parent->name, node2->parent->name) == 0;
}

// Function to process a statement
void processStatement(Node *root, char *statement) {
    char *name1 = strtok(statement, " ");
    char *relation = strtok(NULL, " ");
    char *name2 = strtok(NULL, " ");

    Node *node1 = findNode(root, name1);
    Node *node2 = findNode(root, name2);

    if (strcmp(relation, "is") == 0) {
        relation = strtok(NULL, " ");
        if (strcmp(relation, "a") == 0) {
            relation = strtok(NULL, " ");
            if (strcmp(relation, "child") == 0) {
                relation = strtok(NULL, " ");
                if (strcmp(relation, "of") == 0) {
                    if (node1->parent != NULL && strcmp(node1->parent->name, name2) == 0) {
                        printf("True\n");
                    } else {
                        printf("False\n");
                    }
                }
            } else if (strcmp(relation, "parent") == 0) {
                relation = strtok(NULL, " ");
                if (strcmp(relation, "of") == 0) {
                    if (node2->parent != NULL && strcmp(node2->parent->name, name1) == 0) {
                        printf("True\n");
                    } else {
                        printf("False\n");
                    }
                }
            } else if (strcmp(relation, "sibling") == 0) {
                relation = strtok(NULL, " ");
                if (strcmp(relation, "of") == 0) {
                    if (isSibling(node1, node2)) {
                        printf("True\n");
                    } else {
                        printf("False\n");
                    }
                }
            } else if (strcmp(relation, "descendant") == 0) {
                relation = strtok(NULL, " ");
                if (strcmp(relation, "of") == 0) {
                    if (isDescendant(node2, node1)) {
                        printf("True\n");
                    } else {
                        printf("False\n");
                    }
                }
            } else if (strcmp(relation, "ancestor") == 0) {
                relation = strtok(NULL, " ");
                if (strcmp(relation, "of") == 0) {
                    if (isAncestor(node1, node2)) {
                        printf("True\n");
                    } else {
                        printf("False\n");
                    }
                }
            }
        }
    }
}

int main() {
    int n, m;
    char familyTree[MAX_TREE_SIZE][MAX_NAME_LEN];
    char statement[MAX_STATEMENT_SIZE];

    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }

        // Read the family tree
        for (int i = 0; i < n; i++) {
            scanf("%s", familyTree[i]);
        }

        // Build the family tree
        Node *root = newNode(familyTree[0], NULL);
        Node *current = root;
        for (int i = 1; i < n; i++) {
            int indent = 0;
            while (familyTree[i][indent] == ' ') {
                indent++;
            }
            if (indent > 0) {
                current = current->parent;
            }
            Node *child = newNode(familyTree[i], current);
            addChild(current, child);
            current = child;
        }

        // Process statements
        for (int i = 0; i < m; i++) {
            scanf("%[^\n]", statement);
            getchar(); // Consume the newline character
            processStatement(root, statement);
        }

        printf("\n");
    }

    return 0;
}