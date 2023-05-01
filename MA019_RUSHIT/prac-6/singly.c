#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*head=NULL;
struct node* new;

void create(int x)
{
    new = (struct node*) malloc (sizeof(struct node));
    new->data = x;
    new->next = NULL;
}

void InsertFirst(int x)
{
    create(x);
    if(head==NULL)
    {
        head = new;
        return;
    }
    new->next = head;
    head = new;
}

void InsertLoc(int x,int pos)
{   
    int count=1;
    create(x);
    if(head==NULL || pos == 1)
    {
        head = new;
        return;
    }
    struct node* temp = head;
    while(temp!=NULL && count > pos)
    {
        temp = temp->next;
        count++;
    }
    new->next = temp->next;
    temp->next = new;
}

void InsertLast(int x)
{
    create(x);
    if(head==NULL)
    {
        head = new;
        return;
    }
    struct node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

void DeleteFirst()
{
    if(head==NULL)
    {
        printf("List is Empty...\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    printf("Deleted Element %d\n",temp->data);
    free(temp);
}

void DeleteLast()
{
    if(head==NULL)
    {
        printf("Underflow...\n");
        return;
    }
    struct node* temp = head;
    struct node* p;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    p = temp->next;
    temp->next = NULL;
    printf("Deleted Element %d\n",p->data);
    free(p);

}

void DeleteLoc(int pos){
    struct node *temp=head;
    if(pos==1)
    {
        DeleteFirst();
        return;
    }
    int count=0;
    if(head==NULL){
        printf("List is Empty...\n");
        return;
    }
    while (temp != NULL && count < pos-2 ){
        temp=temp->next;
        count++;
    }
    struct node* p = temp->next;
    temp->next=temp->next->next;
    printf("Delete at %d Position Node is : %d\n",pos,p->data);
    p->next = NULL;
    free(p);
}

void DeleteSpecific(){
    if(head==NULL)
    {
        printf("List is Empty...\n");
        return;
    }
    struct node *temp=head;
    int x;
    printf("Enter Specific value to Delete:");
    scanf("%d",&x);
    while(temp->next != NULL && temp->next->data != x)
    {
        temp = temp->next;
    }
    struct node* dlt = temp->next;
    temp->next = dlt->next;
    printf("Delete Node is %d\n",dlt->data);
    free(dlt);
}
void display()
{
    if(head==NULL)
    {
        printf("Underflow...\n");
        return;
    }
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    InsertLast(10);
    InsertLast(20);
    InsertLast(30);
    InsertLast(40);
    display();
    DeleteLast();
    display();
    InsertFirst(50);
    display();
    DeleteFirst();
    display();
    InsertLoc(60,2);
    display();
    DeleteLoc(2);
    display();
    DeleteSpecific();
    display();
    return 0;
}