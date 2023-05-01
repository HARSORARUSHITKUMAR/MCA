#include <stdio.h>

#define MAX_SIZE 10 // Maximum size of the queue

int queue[MAX_SIZE]; // Array to store the elements of the queue
int front = -1; // Index of the front element of the queue
int rear = -1; // Index of the rear element of the queue

// Function to check if the queue is empty
int is_empty() {
    return front == -1;
}

// Function to check if the queue is full
int is_full() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to add an element to the queue
void enqueue(int element) {
    if (is_full()) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
        printf("Inserted %d into the queue.\n", element);
    }
}

// Function to remove an element from the queue and return it
int dequeue() {
    int element;
    if (is_empty()) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        element = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Removed %d from the queue.\n", element);
        return element;
    }
}

// Function to display the elements of the queue
void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    } else {
        int i;
        printf("Elements of the queue are: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    // Demonstrate the operations on the circular queue
    enqueue(4);
    enqueue(3);
    display();
    dequeue();
    enqueue(7);
    enqueue(2);
    enqueue(5);
    enqueue(9);
    display();
    dequeue();
    enqueue(3);
    enqueue(9);
    display();
    return 0;
}
