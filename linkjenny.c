#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;

};
struct node* head,*newnode,*temp;
head = NULL;
newnode = (struct node*) malloc (sizeof(struct node))
printf("enter data: \n");
scanf("%d",&newnode->data);
newnode->next=NULL;
if (head==NULL)
{
    head=temp=newnode;
}
else
{
    temp->next=newnode;
    temp=newnode;
}
