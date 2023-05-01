#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size of the queue

int queue[MAX_SIZE]; // Array to store the elements of the queue
int front = -1; // Index of the front element of the queue
int rear = -1; // Index of the rear element of the queue

int stack[MAX_SIZE]; // Array to store the elements of the stack
int top = -1; // Index of the top element of the stack

// Function to check if the queue is empty
int is_empty() {
    return front == -1;
}

// Function to check if the queue is full
int is_full() {
    return rear == MAX_SIZE - 1;
}

// Function to add an element to the queue
void enqueue(int element) {
    if (is_full()) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
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
            front++;
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
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Function to push an element onto the stack
void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full.\n");
    } else {
        top++;
        stack[top] = element;
    }
}

// Function to pop an element from the stack and return it
int pop() {
    int element;
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        element = stack[top];
        top--;
        return element;
    }
}

// Function to reverse the elements of the queue
void reverse() {
    while (!is_empty()) {
        push(dequeue());
    }
    while (top != -1) {
        enqueue(pop());
    }
}

int main() {
    // Demonstrate the reversal of a normal queue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    reverse();
    display();
    return 0;
}
