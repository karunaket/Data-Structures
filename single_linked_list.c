#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory for the new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  // Set the data of the new node
  new_node->data = new_data;
  // Set the next pointer of the new node to the current head of the list
  new_node->next = *head_ref;
  // Set the head of the list to the new node
  *head_ref = new_node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
  // Allocate memory for the new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  // Set the data of the new node
  new_node->data = new_data;
  // Set the next pointer of the new node to NULL
  new_node->next = NULL;
  // If the list is empty, set the head of the list to the new node
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  // Traverse the list to find the last node
  struct Node* last_node = *head_ref;
  while (last_node->next != NULL) {
    last_node = last_node->next;
  }
  // Set the next pointer of the last node to the new node
  last_node->next = new_node;
}

// Function to insert a node in between two nodes of the linked list
void insertInBetween(struct Node* prev_node, int new_data) {
  // Check if the previous node is NULL
  if (prev_node == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }
  // Allocate memory for the new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  // Set the data of the new node
  new_node->data = new_data;
  // Set the next pointer of the new node to the next node of the previous node
  new_node->next = prev_node->next;
  // Set the next pointer of the previous node to the new node
  prev_node->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

// Driver code to test the linked list functions
int main() {
  // Initialize an empty linked list
  struct Node* head = NULL;
  // Insert nodes at the beginning of the list
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 1);
  // Print the list
  printf("Linked list after inserting nodes at the beginning: ");
  printList(head);
  // Insert nodes at the end of the list
  insertAtEnd(&head, 4);
  insertAtEnd(&head, 5);
  insertAtEnd(&head, 6);
  // Print the list
  printf("Linked list after inserting nodes at the end: ");
  printList(head);
  // Insert a node in between two nodes of the list
  insertInBetween(head->next, 7);
  // Print the list
  printf("Linked list after inserting a node in between: ");
  printList(head);
  return 0;
}
