#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* prev;
struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
void insertFirst(int value) {
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
newNode->data = value;
newNode->prev = NULL;
newNode->next = head;
if (head != NULL) {
head->prev = newNode;
}
head = newNode;
if (tail == NULL) {
tail = newNode;
}
printf("%d has been inserted as the first node.\n", value);
}
void insertAt(int value, int position) {
if (position < 1) {
printf("Invalid position. Try again.\n");
return;
}
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
newNode->data = value;
if (position == 1) {
newNode->prev = NULL;
newNode->next = head;
if (head != NULL) {
head->prev = newNode;
}
head = newNode;
printf("%d has been inserted at position %d.\n", value, position);
return;
}
struct Node* current = head;
int i;
for (i = 1; i < position - 1 && current != NULL; i++) {
current = current->next;
}
if (current == NULL) {
printf("Invalid position. Try again.\n");
return;
}
newNode->prev = current;
newNode->next = current->next;
if (current->next != NULL) {
current->next->prev = newNode;
}
current->next = newNode;
if (newNode->next == NULL) {
tail = newNode;
}
printf("%d has been inserted at position %d.\n", value, position);
}
void insertLast(int value) {
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
newNode->data = value;
newNode->prev = tail;
newNode->next = NULL;
if (tail != NULL) {
tail->next = newNode;
}
tail = newNode;
if (head == NULL) {
head = newNode;
}
printf("%d has been inserted as the last node.\n", value);
}
void deleteFirst() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = head;
head = head->next;
if (head != NULL) {
head->prev = NULL;
}
if (temp == tail) {
tail = NULL;
}
printf("%d has been deleted from the first position.\n", temp->data);
free(temp);
}
void deleteLast() {
if (tail == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = tail;
tail = tail->prev;
if (tail != NULL) {
tail->next = NULL;
}
if (temp == head) {
head = NULL;
}
printf("%d has been deleted from the last position.\n", temp->data);
free(temp);
}
void deleteAt(int position) {
if (position < 1) {
printf("Invalid position. Try again.\n");
return;
}
if (position == 1) {
deleteFirst();
return;
}
struct Node* current = head;
int i;
for (i = 1; i < position && current != NULL; i++) {
current = current->next;
}
if (current == NULL) {
printf("Invalid position. Try again.\n");
return;
}
if (current == tail) {
deleteLast();
return;
}
current->prev->next = current->next;
current->next->prev = current->prev;
printf("%d has been deleted from position %d.\n", current->data, position);
free(current);
}
void display() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
printf("The current list is: ");
struct Node* current = head;
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
int main() {
int choice, value, position;
while (1) {
printf("Please choose an operation to perform:\n");
printf("1. Insert at the first position\n");
printf("2. Insert at a specific position\n");
printf("3. Insert at the last position\n");
printf("4. Delete from the first position\n");
printf("5. Delete from the last position\n");
printf("6. Delete from a specific position\n");
printf("7. Display the current list\n");
printf("8. Exit\n");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter a value to insert: ");
scanf("%d", &value);
insertFirst(value);
break;
case 2:
printf("Enter a value to insert: ");
scanf("%d", &value);
printf("Enter the position to insert at: ");
scanf("%d", &position);
insertAt(value, position);
break;
case 3:
printf("Enter a value to insert: ");
scanf("%d", &value);
insertLast(value);
break;
case 4:
deleteFirst();
break;
case 5:
deleteLast();
break;
case 6:
printf("Enter the position to delete from: ");
scanf("%d", &position);
deleteAt(position);
break;
case 7:
display();
break;
case 8:
exit(0);
default:
printf("Invalid choice. Try again.\n");
}
}
return 0;
}
