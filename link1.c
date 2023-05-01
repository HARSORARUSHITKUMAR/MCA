#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void insert(int value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(int value) {
    struct Node* current_node = head;
    struct Node* prev_node = NULL;

    while (current_node != NULL && current_node->data != value) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Node not found\n");
        return;
    }

    if (prev_node == NULL) {
        head = current_node->next;
    } else {
        prev_node->next = current_node->next;
    }

    if (tail == current_node) {
        tail = prev_node;
    }

    free(current_node);
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    printf("Original list: ");
    display();

    delete(3);

    printf("After deleting 3: ");
    display();

    return 0;
}
