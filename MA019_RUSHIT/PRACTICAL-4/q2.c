#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int val) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluate_postfix(char *expr) {
    int i = 0;
    int val1, val2, result;

    while(expr[i]) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            val2 = pop();
            val1 = pop();
            switch(expr[i]) {
                case '+': 
                    result = val1 + val2; 
                    break;

                case '-': 
                    result = val1 - val2; 
                    break;

                case '*': 
                    result = val1 * val2; 
                    break;

                case '/': 
                    result = val1 / val2; 
                    break;

                default: 
                    printf("Error: Invalid operator\n"); 
                exit(1);
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char expr[100];

    printf("Enter a postfix expression: ");
    scanf("%s", expr);

    int result = evaluate_postfix(expr);

    printf("Result: %d\n", result);

    return 0;
}
