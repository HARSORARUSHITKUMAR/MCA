#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
}*headl=NULL,*temp,*t,*head1,*prev;

void op()
{
	
		printf("\n\n========================== \n");
		printf("1 = CREATE 2 LINK LIST    ||\n");
		printf("2 = MERGE 2 LIST          ||\n");
		printf("==========================\n");
		
	
}

struct node *sort(struct node *head)
{	
	
	if(head==NULL)
	{
		printf("List not available");
		exit(1);
	}
	else
	{
		int temp1;
		prev=head;
		while(prev!=NULL)
		{
			temp=prev->next;
			while(temp!=NULL)
			{
				if(prev->data>temp->data)
				{
					temp1=prev->data;
					prev->data=temp->data;
					temp->data=temp1;
				}
						
		
				temp=temp->next;
			}
			prev=prev->next;
			
			
		}
		return head;
	}
		


}
struct node *create(int a)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	
	
	if(new_node==NULL)
	{
		printf("Node is note available ");
		exit(1);
	}
	
	
	new_node->next=NULL;
	new_node->data=a;
	return_new;
	
	
	
}


struct node *inlast(struct node *head,int a)
{
	struct node *new_node=create(a);
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
	temp=head;
	
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	
	temp->next=new_node
	;
	}
	return head;
	

}

void disp(struct node * head)
{
	if(head==NULL)
	{
		
		printf("List is empty");
		exit(0);
		
	}
	
	else
	{
	temp=head;
	printf(".....YOUR LIST IS.....\n");
	
	while(temp != NULL)
	{
		
		printf(" %d ",temp->data);
		
		temp=temp->next;
	}

}

}	
int main(int argc,char *argv[])
{
	op();
	int ch;
//	printf(" this is %d\n",atoi(argv[1])+1);
	for(;;)
	{
		printf("\nENTER YOUR CHOICE :=");
		scanf("%d",&ch);
		
		if(ch==1)
		{
			if(argc<32)
			{
				
				for(int i=1;i<argc;i++)
				{
				
					if(i<16)
						
				headl=inlast(headl,atoi(argv[i]));
					else
					head1=inlast(head1,atoi(argv[i]));
				}			
			}
			else
			{
			
				printf("no is not valid %d",argc);
			}
		}
		
		else if(ch==2)
		{
			sort(headl);
			sort(head1);
			temp=headl;
			while(temp->next!=NULL)
			{
			
				temp=temp->next;
			}
			temp->next=head1;
			disp(headl);
			
		}
		
	}
}
	
