#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
  int key;
  struct Node* prev;
  struct Node* next;
};

// Function to create a new node
struct Node* newNode(int key) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->key = key;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

// Function to insert a node at the beginning of the list
void insert(struct Node** head, int key) {
  // Create a new node
  struct Node* new_node = newNode(key);

  // If list is empty
  if (*head == NULL) {
    *head = new_node;
    return;
  }

  // Insert the new node at the beginning
  new_node->next = *head;
  (*head)->prev = new_node;
  *head = new_node;
}

// Function to delete the first node with the given key
void delete(struct Node** head, int key) {
  // Iterate through the list and find the node with the key
  struct Node* current = *head;
  while (current != NULL) {
    if (current->key == key) {
      // If the node is the head
      if (current == *head) {
        *head = current->next;
      } else {
        // Update the prev and next pointers of the adjacent nodes
        current->prev->next = current->next;
        if (current->next != NULL) {
          current->next->prev = current->prev;
        }
      }
      free(current);
      return;
    }
    current = current->next;
  }
}

// Function to delete the first node in the list
void deleteFirst(struct Node** head) {
  // If the list is empty
  if (*head == NULL) {
    return;
  }

  // Update the head pointer
  struct Node* temp = *head;
  *head = (*head)->next;

  // If there is a next node, update its prev pointer
  if (*head != NULL) {
    (*head)->prev = NULL;
  }

  free(temp);
}

// Function to delete the last node in the list
void deleteLast(struct Node** head) {
  // If the list is empty
  if (*head == NULL) {
    return;
  }

  // If there is only one node
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  // Iterate through the list to find the last node
  struct Node* current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  // Update the prev pointer of the second last node
  current->prev->next = NULL;
  free(current);
}

// Function to print the list
void printList(struct Node* head) {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d ", current->key);
    current = current->next;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  // Initialize the head of the list
  struct Node* head = NULL;

  // Process the commands
  char command[10];
  int key;
  for (int i = 0; i < n; i++) {
    scanf("%s", command);
    if (command[0] == 'i') {
      scanf("%d", &key);
      insert(&head, key);
    } else if (command[0] == 'd') {
      if (command[1] == 'e') {
        if (command[6] == 'F') {
          deleteFirst(&head);
        } else {
          deleteLast(&head);
        }
      } else {
        scanf("%d", &key);
        delete(&head, key);
      }
    }
  }

  // Print the list
  printList(head);
  printf("\n");

  return 0;
}