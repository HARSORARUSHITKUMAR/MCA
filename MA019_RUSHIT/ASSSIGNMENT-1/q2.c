#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char data[MAX_SIZE];
} Stack;

void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }

    s->top++;
    s->data[s->top] = value;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }

    char value = s->data[s->top];
    s->top--;

    return value;
}

char peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }

    return s->data[s->top];
}

void sortString(char *str) {
    Stack mainStack, auxStack;
    mainStack.top = -1;
    auxStack.top = -1;

    push(&mainStack, str[0]);

    int i = 1;
    while (str[i] != '\0') {
        if (str[i] >= peek(&mainStack)) {
            push(&mainStack, str[i]);
        } else {
            while (mainStack.top != -1 && peek(&mainStack) > str[i]) {
                push(&auxStack, pop(&mainStack));
            }
            push(&mainStack, str[i]);
            while (auxStack.top != -1) {
                push(&mainStack, pop(&auxStack));
            }
        }
        i++;
    }

    printf("Sorted string: ");
    while (mainStack.top != -1) {
        printf("%c", pop(&mainStack));
    }
}

int main() {
    char str[] = "hello3569world12478";

    printf("Input string: %s\n", str);

    sortString(str);

    return 0;
}
