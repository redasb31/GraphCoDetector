#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the list
struct Node {
  int data;
  struct Node *next;
};

// Function to insert a new node at the specified position
void insert(struct Node **head, struct Node **cursor, int x) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->next = *cursor;
  if (*head == *cursor) {
    *head = newNode;
  } else {
    struct Node *temp = *head;
    while (temp->next != *cursor) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  *cursor = newNode;
}

// Function to move the cursor by a specified distance
void move(struct Node **head, struct Node **cursor, int d) {
  if (d > 0) { // Move cursor to the end
    for (int i = 0; i < d; i++) {
      if ((*cursor)->next != NULL) {
        *cursor = (*cursor)->next;
      }
    }
  } else if (d < 0) { // Move cursor to the front
    for (int i = 0; i < -d; i++) {
      if (*head == *cursor) {
        break;
      }
      struct Node *temp = *head;
      while (temp->next != *cursor) {
        temp = temp->next;
      }
      *cursor = temp;
    }
  }
}

// Function to erase the node pointed to by the cursor
void erase(struct Node **head, struct Node **cursor) {
  if (*head == *cursor) { // Deleting the head node
    *head = (*cursor)->next;
    free(*cursor);
    *cursor = *head;
  } else {
    struct Node *temp = *head;
    while (temp->next != *cursor) {
      temp = temp->next;
    }
    temp->next = (*cursor)->next;
    free(*cursor);
    *cursor = temp->next;
  }
}

// Function to print the elements of the list
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d\n", head->data);
    head = head->next;
  }
}

int main() {
  int q;
  scanf("%d", &q);

  // Initialize an empty list and cursor pointing to END
  struct Node *head = NULL;
  struct Node *cursor = NULL;

  for (int i = 0; i < q; i++) {
    int operation, x, d;
    scanf("%d", &operation);

    switch (operation) {
      case 0: // Insert
        scanf("%d", &x);
        insert(&head, &cursor, x);
        break;

      case 1: // Move
        scanf("%d", &d);
        move(&head, &cursor, d);
        break;

      case 2: // Erase
        erase(&head, &cursor);
        break;
    }
  }

  printList(head);
  return 0;
}