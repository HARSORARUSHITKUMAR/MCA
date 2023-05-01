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

void insert(struct stack** top, int data) {
    if (isEmpty(*top) || data > (*top)->data) {
        push(top, data);
    }
    else {
        int temp = pop(top);
        insert(top, data);
        push(top, temp);
    }
}

void sortStack(struct stack** top) {
    if (!isEmpty(*top)) {
        int temp = pop(top);
        sortStack(top);
        insert(top, temp);
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
    push(&top, 30);
    push(&top, -5);
    push(&top, 18);
    push(&top, 14);
    push(&top, -3);
    printf("Stack elements before sorting:\n");
    printStack(top);
    sortStack(&top);
    printf("Stack elements after sorting:\n");
    printStack(top);
    return 0;
}
