#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

int count();

void insert(int value) {
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;
    if (head == NULL) {
        head = new;
    } else {
        struct Node* pre = head;
        while (pre->next != NULL) {
            pre = pre->next;
        }
        pre->next = new;
    }
}

void print_all_subsets() {
    int n = pow(2, count());
    for (int i = 0; i < n; i++) {
        printf("{");
        int j = 0;
        struct Node* pre = head;
        while (pre != NULL) {
            if ((i / (int)pow(2, j)) % 2 == 1) {
                printf("%d,", pre->data);
            }
            j++;
            pre = pre->next;
        }
        printf("\b}\n");
    }
    printf("{NULL}\n");
}

int count() {
    int count = 0;
    struct Node* pre = head;
    while (pre != NULL) {
        count++;
        pre = pre->next;
    }
    return count;
}

int main() {

    insert(4);
    insert(5);
    insert(6);
    print_all_subsets();
    return 0;
}
