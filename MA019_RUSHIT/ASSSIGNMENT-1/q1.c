#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int data[MAX_SIZE];
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }

    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }

    int value = s->data[s->top];
    s->top--;

    return value;
}

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }

    return s->data[s->top];
}

void sortStack(Stack *input) {
    Stack tmpStack;
    tmpStack.top = -1;

    while (input->top != -1) {
        int tmp = pop(input);

        while (tmpStack.top != -1 && peek(&tmpStack) > tmp) {
            push(input, pop(&tmpStack));
        }

        push(&tmpStack, tmp);
    }

    while (tmpStack.top != -1) {
        push(input, pop(&tmpStack));
    }
}

int main() {
    Stack inputStack;
    inputStack.top = -1;

    // Get input from user
    int input[] = {34, 3, 31, 98, 92, 23};
    int size = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < size; i++) {
        push(&inputStack, input[i]);
    }

    printf("Input stack: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", inputStack.data[i]);
    }

    sortStack(&inputStack);

    printf("\nSorted stack: ");
    for (int i = size-1; i >= 0; i--) {
        printf("%d ", inputStack.data[i]);
    }

    return 0;
}
