#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack* next;
};

void push(struct stack** top, int data) {
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct stack** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct stack* temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int isEmpty(struct stack* top) {
    return top == NULL;
}

void insertAtBottom(struct stack** top, int data) {
    if (isEmpty(*top)) {
        push(top, data);
    }
    else {
        int temp = pop(top);
        insertAtBottom(top, data);
        push(top, temp);
    }
}

void reverseStack(struct stack** top) {
    if (!isEmpty(*top)) {
        int temp = pop(top);
        reverseStack(top);
        insertAtBottom(top, temp);
    }
}

void printStack(struct stack* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct stack* top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    push(&top, 5);
    printf("Original Stack: ");
    printStack(top);
    reverseStack(&top);
    printf("Reversed Stack: ");
    printStack(top);
    return 0;
}
