#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.");
    } else {
        Node* current = head;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
}

int main() {
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    printf("Circular linked list: ");
    printList(head);

    return 0;
}
