#include<stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
//pre order
struct node* create(int data){

    struct node* newNode = malloc(sizeof(struct node));
    newNode -> data=data;
    newNode -> left=NULL;
    newNode -> right=NULL;
}
// post order
void postorder(struct node* root){
    if(root == NULL)
    {
        
    }
}

int main(){

    return 0;
}