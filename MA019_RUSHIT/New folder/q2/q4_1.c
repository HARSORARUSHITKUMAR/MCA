#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next_node;
}*head_node=NULL,*new_node;

void insert_last(int data)
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = data;
    new_node->next_node = NULL;

    if(head_node == NULL)
    {
        head_node = new_node;
    }
    else{
        struct node *temp_node = head_node;
        while(temp_node->next_node != NULL)
        {
            temp_node = temp_node->next_node;
        }
        temp_node->next_node = new_node;
    }
}

void display_list()
{
    struct node *temp_node=head_node;
    while(temp_node!=NULL)
    {
        printf("%d-->",temp_node->value);
        temp_node = temp_node->next_node;
    } 
    printf("\n");    
}

void display_middle_node()
{
    struct node *count_node1,*count_node2;
    count_node1 = head_node;
    count_node2 = head_node;

    while(count_node2!=NULL && count_node2->next_node!=NULL)
    {
        count_node2 = count_node2->next_node->next_node;
        count_node1 = count_node1->next_node;
    }
    printf("Middle Node Is %d",count_node1->value);
}

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++){
        insert_last(atoi(argv[i]));
    }
    
    display_list();
    display_middle_node();
    return 0;
}
