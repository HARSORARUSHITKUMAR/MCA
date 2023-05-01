#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* last = NULL;
    void insertFirst(int value)
    {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
        if (last == NULL) 
        {
            last = newNode;
            last->next = last;
        } else
        {
            newNode->next = last->next;
            last->next = newNode;
        }
        printf("%d has been inserted as the first node.\n", value);
    }
    void insertAt(int value, int position)
     {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            newNode->data = value;
                if (last == NULL)
                {
                    last = newNode;
                    last->next = last;
                } else 
        {
                    struct Node* current = last->next;
                        int i = 1;
                while (i < position - 1 && current != last) 
                {
                    current = current->next;
                    i++;
                }
                    if (i < position - 1) 
        {
            printf("The list has less than %d nodes. %d has not been inserted.\n", position,value);
            free(newNode);
        }
         else 
        {
            newNode->next = current->next;
            current->next = newNode;
            if (current == last) 
            {
                    last = newNode;
            }
            printf("%d has been inserted at position %d.\n", value, position);
        }
        }
    }
void insertLast(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
        if (last == NULL) {
            last = newNode;
                last->next = last;
        } else {
    newNode->next = last->next;
    last->next = newNode;
        last = newNode;
    }
        printf("%d has been inserted as the last node.\n", value);
}
void deleteFirst() {
        if (last == NULL) {
        printf("The list is empty.\n");
        } else if (last == last->next) {
        printf("%d has been deleted.\n", last->data);
        free(last); 
        last = NULL;
        } else {
                struct Node* temp = last->next;
        printf("%d has been deleted.\n", temp->data);
        last->next = temp->next;
        free(temp);
        }
    }
void deleteLast() {
            if (last == NULL) {
                printf("The list is empty.\n");
        } else if (last == last->next) {
                printf("%d has been deleted.\n", last->data);
                    free(last);
                    last = NULL;
        } else {
                    struct Node* current = last->next;
                    while (current->next != last) {
                    current = current->next;
                }
                    printf("%d has been deleted.\n", last->data);
                        free(last);
                        last = current;
                        last->next = last->next->next;
                    }
        }
void deleteAt(int position) {
            if (last == NULL) {
                printf("The list is empty.\n");
        } else {
            struct Node* current = last->next;
                int i = 1;
                while (i < position - 1 && current != last) {
                current = current->next;
                    i++;
            }
            if (i < position - 1) {
            printf("The list has less than %d nodes. No node has been deleted.\n", position);
            }
            else {
                    struct Node* temp = current->next;
                    current->next = temp->next;
                        if (temp == last) {
                            last = current;
                }
                            printf("%d has been deleted from position %d.\n", temp->data, position);
                            free(temp);
                }
            }
        }
void displayList() {
                if (last == NULL) {
                    printf("The list is empty.\n");
                } else {
                        printf("The list is: ");
                            struct Node* current = last->next;
                        do {
                            printf("%d ", current->data);
                            current = current->next;
                            } while (current != last->next);
                                printf("\n");
                        }
                }
int main() {
            int choice, value, position;
            while (1) {
                printf("Choose an operation:\n");
                printf("1. Insert as first node\n");
                printf("2. Insert at a specific location\n");
                printf("3. Insert as last node\n");
                printf("4. Delete the first node\n");
                printf("5. Delete the last node\n");
                printf("6. Delete a specific node\n");
                printf("7. Display the list\n");
                printf("8. Exit\n");
                scanf("%d", &choice);
                switch (choice) {
             
                    case 1:
                            printf("Enter the value to be inserted: ");
                            scanf("%d", &value);
                            insertFirst(value);
                            break;
                    case 2:
                            printf("Enter the value to be inserted: ");
                            scanf("%d", &value);
                            printf("Enter the position where the value should be inserted: ");
                            scanf("%d", &position);
                            insertAt(value, position);
                            break;
                    case 3:
                            printf("Enter the value to be inserted: ");
                            scanf("%d", &value);
                            insertLast(value);
                            break;
                    case 4:
                            deleteFirst();
                            break;
                    case 5:
                            deleteLast();
                            break;
                    case 6:
                            printf("Enter the position of the node to be deleted: ");
                            scanf("%d", &position);
                            deleteAt(position);
                            break;
                    case 7:
                            displayList();
                            break;
                    case 8:
                            printf("Exiting the program.\n");
                            exit(0);
                    default:
                            printf("Invalid choice. Try again.\n");
                }
            }
            return 0;
}
