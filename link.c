#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
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
    struct Node* currnode = head;
    struct Node* prevnode = NULL;

    while (currnode != NULL && currnode->data != value) {
        prevnode = currnode;
        currnode = currnode->next;
    }

    if (currnode == NULL) {
        printf("Node not found\n");
        return;
    }

    if (prevnode == NULL) {
        head = currnode->next;
    } else {
        prevnode->next = currnode->next;
    }

    free(currnode);
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
