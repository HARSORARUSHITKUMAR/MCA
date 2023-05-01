#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
}*head_list1 = NULL, *temp, *t, *head_list2, *prev;

void display_menu() {
    printf("\n\n========================== \n");
    printf("1 = CREATE 2 LINK LIST    ||\n");
    printf("2 = MERGE 2 LIST          ||\n");
    printf("==========================\n");
}

struct Node* sort_list(struct Node* head) {
    if (head == NULL) {
        printf("List is not available");
        exit(0);
    }
    else {
        int temp1;
        prev = head;
        while (prev != NULL) {
            temp = prev->next;
            while (temp != NULL) {
                if (prev->data > temp->data) {
                    temp1 = prev->data;
                    prev->data = temp->data;
                    temp->data = temp1;
                }
                temp = temp->next;
            }
            prev = prev->next;
        }
    }
    return head;
}

struct Node* create_node(int a) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Node is not available ");
        exit(0);
    }
    new_node->next = NULL;
    new_node->data = a;
    return new_node;
}

struct Node* insert_at_end(struct Node* head, int a) {
    struct Node* new_node = create_node(a);
    if (head == NULL) {
        head = new_node;
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

void display_list(struct Node* head) {
    if (head == NULL) {
        printf("List is empty");
        exit(0);
    }
    else {
        temp = head;
        printf(".....YOUR LIST IS.....\n");
        while (temp != NULL) {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(int argc, char* argv[]) {
    display_menu();
    int ch;
    for (;;) {
        printf("\nENTER YOUR CHOICE :=");
        scanf("%d", &ch);
        if (ch == 1) {
            if (argc < 32) {
                for (int i = 1; i < argc; i++) {
                    if (i < 16)
                        head_list1 = insert_at_end(head_list1, atoi(argv[i]));
                    else
                        head_list2 = insert_at_end(head_list2, atoi(argv[i]));
                }
            }
            else {
                printf("Number is not valid %d", argc);
            }
        }
        else if (ch == 2) {
            sort_list(head_list1);
            sort_list(head_list2);
            temp = head_list1;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = head_list2;
            display_list(head_list1);
        }
    }
    return 0;
}
