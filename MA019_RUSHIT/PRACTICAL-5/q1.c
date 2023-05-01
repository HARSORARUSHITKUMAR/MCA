#include <stdio.h>

#define MAX_SIZE 10 // Maximum size of the queue

int queue[MAX_SIZE]; // Array to store the elements of the queue
int front = -1; // Index of the front element of the queue
int rear = -1; // Index of the rear element of the queue

// Function to check if the queue is empty
int is_empty() {
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
int is_full() {
    return (rear+1)%MAX_SIZE == front ? 1 : 0;
}

// Function to add an element to the queue
void enqueue(int element) {
    if (is_full()) {
        printf("Queue is full.\n");
    }
    else if (is_empty()) {
        front = rear = 0;
        queue[rear] = element;
    }
    else {
        rear = (rear+1)%MAX_SIZE;
        queue[rear] = element;
    }
}

// Function to remove an element from the queue and return it
int dequeue() {
    int element;
    if (is_empty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if (front == rear) {
        element = queue[front];
        front = rear = -1;
    }
    else {
        element = queue[front];
        front = (front+1)%MAX_SIZE;
    }
    return element;
}

// Function to display the elements of the queue
void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else {
        int i;
        printf("Elements of the queue are: ");
        for (i=front; i!=rear; i=(i+1)%MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    // Demonstrate the operations mentioned in the question
    enqueue(4);
    enqueue(3);
    display();
    printf("Dequeued element: %d\n", dequeue());
    enqueue(7);
    enqueue(2);
    enqueue(5);
    enqueue(9);
    display();
    printf("Dequeued element: %d\n", dequeue());
    enqueue(3);
    enqueue(9);
    display();
    return 0;
}
