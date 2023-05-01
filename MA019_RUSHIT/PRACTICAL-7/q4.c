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
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->prev = NULL;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
tail = newNode;
head->prev = tail;
tail->next = head;
} else {
newNode->next = head;
head->prev = newNode;
head = newNode;
head->prev = tail;
tail->next = head;
}
printf("%d has been inserted at the first position.\n", value);
}
void insertLast(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->prev = NULL;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
tail = newNode;
head->prev = tail;
tail->next = head;
} else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
head->prev = tail;
tail->next = head;
}
printf("%d has been inserted at the last position.\n", value);
}
void insertAt(int value, int position) {
if (position < 1) {
printf("Invalid position. Try again.\n");
return;
}
if (position == 1) {
insertFirst(value);
return;
}
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->prev = NULL;
newNode->next = NULL;
struct Node* current = head;
int i;
for (i = 1; i < position - 1 && current != NULL; i++) {
current = current->next;
}
if (current == NULL) {
printf("Invalid position. Try again.\n");
return;
}
if (current == tail) {
insertLast(value);
return;
}
newNode->next = current->next;
newNode->prev = current;
current->next->prev = newNode;
current->next = newNode;
printf("%d has been inserted at position %d.\n", value, position);
}
void deleteFirst() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
if (head == tail) {
printf("%d has been deleted from the first position.\n", head->data);
free(head);
head = NULL;
tail = NULL;
return;
}
struct Node* temp = head;
head = head->next;
head->prev = tail;
tail->next = head;
printf("%d has been deleted from the first position.\n", temp->data);
free(temp);
}
void deleteLast() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
if (head == tail) {
printf("%d has been deleted from the last position.\n", tail->data);
free(tail);
head = NULL;
tail = NULL;
return;
}
struct Node* temp = tail;
tail = tail->prev;
tail->next;
head->prev = tail;
tail->next = head;
printf("%d has been deleted from the last position.\n", temp->data);
free(temp);
}
void deleteAt(int position) {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
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
struct Node* current = head;
printf("The circular doubly linked list is: ");
do {
printf("%d ", current->data);
current = current->next;
} while (current != head);
printf("\n");
}
int main() {
insertFirst(10);
insertLast(20);
insertAt(15, 2);
display();
deleteAt(2);
deleteFirst();
deleteLast();
display();
return 0;
}