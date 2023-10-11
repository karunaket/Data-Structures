#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
}
*head = NULL;

/*

The node struct has two members: an integer data and a pointer to another node struct called next. The data member stores the value of the node, while the next member points to the next node in the list.

The excerpt also includes a pointer called head which is initialized to NULL. This pointer is used to keep track of the first node in the linked list. When the list is empty, the head pointer is set to NULL. When a new node is added to the list, the head pointer is updated to point to the new node.

Overall, this code excerpt provides a basic building block for implementing a singly linked list data structure in C. By creating a series of node structs and linking them together using the next pointer, we can create a list of arbitrary length and easily traverse it from beginning to end. The head pointer allows us to keep track of the first node in the list, and is used to insert new nodes at the beginning of the list.

*/

void insertatfirst(int value)
{
  struct node* n = (struct node*)malloc(sizeof(struct node));
  n->data = value;
  n->next = head;
  head = n;
}

void insertatlast(int value)
{
  struct node* n = (struct node*)malloc(sizeof(struct node));
  n->next = NULL;
  n->data = value;
  struct node* temp;
  temp = head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = n;
}

void insertatpos(int value, int pos)
{
  struct node* n = (struct node*)malloc(sizeof(struct node));
  n->data = value;
  struct node* temp = head;

  while(temp->data = NULL)
  {
    if(temp==pos)
    {
      n->next = temp->next;
      temp->next = n;
      return;
    }
    else
    {
      temp = temp->next;
    }
  }
}

void display()
{
  struct node* temp;
  temp = head;
  printf("The list is: ");
  if(head == NULL)
  {
    printf("Empty");
  }
  else
  {
    while(temp != NULL)
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }
  }
}