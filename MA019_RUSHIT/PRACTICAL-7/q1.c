#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* rear = NULL;
void enqueue(int value) {
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
newNode->data = value;
if (rear == NULL) {
rear = newNode;
rear->next = rear;
} else {
newNode->next = rear->next;
rear->next = newNode;
rear = newNode;
}
printf("%d has been enqueued to the queue.\n", value);
}
void dequeue() {
if (rear == NULL) {
printf("The queue is empty.\n");
} else if (rear == rear->next) {
printf("%d has been dequeued from the queue.\n", rear->data);
free(rear);
rear = NULL;
} else {
struct Node* temp = rear->next;
printf("%d has been dequeued from the queue.\n", temp->data);
rear->next = temp->next;
free(temp);
}
}
void display() {
if (rear == NULL) {
printf("The queue is empty.\n");
} else {
struct Node* current = rear->next;
printf("Elements in the queue are: ");
do {
printf("%d ", current->data);
current = current->next;
} while (current != rear->next);
printf("\n");
}
}
int main() {
enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
display();
dequeue();
dequeue();
display();
enqueue(50);
enqueue(60);
display();
return 0;
}