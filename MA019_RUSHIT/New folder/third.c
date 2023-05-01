#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node** current = &mergedList;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            *current = list1;
            list1 = list1->next;
        } else {
            *current = list2;
            list2 = list2->next;
        }
        current = &((*current)->next);
    }
    
    if (list1 == NULL) {
        *current = list2;
    } else {
        *current = list1;
    }
    
    return mergedList;
}

void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(struct Node* head) {
    struct Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc != 21) {
        printf("Please enter 20 integers.\n");
        scanf("%d");
        return -1;
    }
    
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    
    for (int i = 1; i <= 20; i++) {
        int data = atoi(argv[i]);
        if (i <= 10) {
            insert(&list1, data);
        } else {
            insert(&list2, data);
        }
    }
    
    printf("List 1 before sorting: ");
    printList(list1);
    printf("List 2 before sorting: ");
    printList(list2);
    
    // sort the two lists
    // ...

    printf("List 1 after sorting: ");
    printList(list1);
    printf("List 2 after sorting: ");
    printList(list2);
    
    // merge the two lists
    struct Node* mergedList = merge(list1, list2);
    
    printf("Merged list: ");
    printList(mergedList);
    
    return 0;
}
