#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void insert(int val) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = val;
   new_node->next = NULL;

   if (head == NULL) {
      head = new_node;
      tail = new_node;
   }
   else {
      tail->next = new_node;
      tail = new_node;
   }
}

void delete(int val) {
   struct Node* temp = head;
   struct Node* prev = NULL;

   while (temp != NULL && temp->data != val) {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL) {
      printf("Element not found\n");
      return;
   }

   if (temp == head) {
      head = head->next;
   }
   else if (temp == tail) {
      tail = prev;
      tail->next = NULL;
   }
   else {
      prev->next = temp->next;
   }

   free(temp);
}

void display() {
   struct Node* temp = head;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(40);

   printf("Linked List: ");
   display();

   delete(20);
   delete(30);

   printf("\nLinked List after deletion: ");
   display();

   return 0;
}
