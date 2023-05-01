#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack {
    int data[MAX_SIZE];
    int top;
};

void push(struct stack* s, int data) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = data;
}

int pop(struct stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = s->data[s->top];
    s->top--;
    return data;
}

int isEmpty(struct stack* s) {
    return s->top == -1;
}

struct queue {
    struct stack s1;
    struct stack s2;
};

void enqueue(struct queue* q, int data) {
    push(&q->s1, data);
}

int dequeue(struct queue* q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            int data = pop(&q->s1);
            push(&q->s2, data);
        }
    }
    return pop(&q->s2);
}

int main() {
    struct queue q;
    q.s1.top = -1;
    q.s2.top = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    enqueue(&q, 4);
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("\n");

    return 0;
}
