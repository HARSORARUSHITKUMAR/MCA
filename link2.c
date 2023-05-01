#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL, *tail = NULL;

struct Node* createNode(int d){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = d;
    temp->next = NULL;
    return temp;
}
bool isEmpty(){
    return head == NULL;
}

void insertAtFirst(int element){
    struct Node *newNode = createNode(element);
    if(isEmpty()){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}

void insertAtLast(int element){
    struct Node *newNode = createNode(element);
    if(tail == NULL){
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPos(int pos, int element){
    if(pos == 1){
        insertAtFirst(element);
    }else{
        int count = 1;
        struct Node *temp = head;
        while(count <= pos - 1){
            count++;
            temp = temp->next;
        }
        if(temp->next == tail){
            insertAtLast(element);
        }
        struct Node *newNode = createNode(element);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void display(){
    if(isEmpty()){
        printf("List is Empty! \n");
        return;
    }else{
        struct Node *temp = head;
        while(temp != NULL){    
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    insertAtFirst( 10);
    insertAtFirst( 20);
    insertAtFirst( 30);
    insertAtFirst( 40);
    display();
    printf("\n head: %d -- tail: %d \n", head->data, tail->data);
    insertAtLast(9);
    // insertAtLast(8);
    display();
    printf("\n head: %d -- tail: %d \n", head->data, tail->data);
    insertAtPos(6, 777);
    display();
    printf("\n head: %d -- tail: %d \n", head->data, tail->data);
}