#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
};

struct Node* head = NULL;

struct Node* createNewNode(int data)
{
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        return newNode;
}

void printList() 
{
            struct Node* preNode = head;
            while (preNode != NULL) {
            printf("%d ", preNode->data);
            preNode = preNode->next;
            }
            printf("\n");
}

void deleteDuplicates() 
{
            struct Node* preNode = head;
            while (preNode != NULL) {
            struct Node* runner = preNode;

            while (runner->next != NULL) {
            if (runner->next->data == preNode->data) 
            {
            struct Node* duplicate = runner->next;
            runner->next = runner->next->next;
            free(duplicate);
            } 
            else 
            {
            runner = runner->next;
}
}
            preNode = preNode->next;
}
}

int main() {
            head = createNewNode(5);
            head = createNewNode(4);
            head = createNewNode(4);
            head = createNewNode(3);
            head = createNewNode(5);
            head = createNewNode(6);
            head = createNewNode(5);

    printf("Original List: ");
    printList();

    deleteDuplicates();

    printf("List after deleting duplicates: ");
    printList();

return 0;

}