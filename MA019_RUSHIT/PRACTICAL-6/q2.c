//Stack using LinkList
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*top=NULL;

struct node*new;

void push()
{
    int x;
    new = (struct node*) malloc (sizeof(struct node));
    printf("Enter Value : ");
    scanf("%d",&x);
    new->data = x;
    new->next = top;
    top = new;
}

int pop()
{
    if(top==NULL)
    {
        printf("Underflow...\n");
        return 0;
    }
    struct node* temp = top;
    top = top->next;
    return temp->data;
    free(temp);
}

void peek()
{
    if(top==NULL)
    {
        printf("Underflow...\n");
        return;
    }
    printf("Top is %d\n",top->data);
}

void peep()
{
    if(top==NULL)
    {
        printf("UnderFlow...\n");
        return;
    }
    int x;
    printf("Enter Value to Search : ");
    scanf("%d",&x);
    int count=1;
    struct node* temp = top;
    while(temp!=NULL && temp->data != x)
    {
        temp = temp->next;
        count++;
    }
    if(count > 0 && temp != NULL)
        printf("Found at Location %d\n",count);
    else
        printf("Not Found\n");
    
}

void display()
{
    if(top==NULL)
    {
        printf("Underflow...\n");
        return;
    }
    struct node* temp = top;
    while(temp!=NULL)
    {
        printf("---");
        printf("|%d|",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int c;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Peep\n4.Peek\n5.Display\n6.Exit\nChoose:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                push();
                break;
            case 2:
                printf("Popped Element : %d\n",pop());
                break;
            case 3:
                peep();
                break;
            case 4:
                peek();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("HAVE A NICE DAY!.....\n");
                exit(1);
            default:
                printf("Invalid Option....\n");
                break;
        }
    } while(c!=6);
    return 0;
}