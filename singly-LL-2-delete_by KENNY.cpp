#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void create();
void display();
void delete_head();
void delete_last();
void delete_val();

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *start=NULL;

int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Delete Head\n4.Delete Last\n5.Delete val\n6.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
         {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3: delete_head();
            break;
        case 4:delete_last();
            break;
        case 5:delete_val();
            break;
        case 6:
            exit(1);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
void create()
{
    int c;
    node *neww,*curr;
    start=(node *) malloc(sizeof(node));
    curr=start;
    printf("Enter element\n");
    scanf("%d",&start->data);
    while(1)
    {
        printf("Do you want to add another element(1/0)\n");
        scanf("%d",&c);
        if(c==1)
        {
            neww=(node *) malloc(sizeof(node));
            printf("Enter element\n");
            scanf("%d",&neww->data);
            curr->link = neww;
            curr=neww;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}
void display()
{
    node *temp;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->link;
    }
}
void delete_head(){
    node *ptr;
    ptr = start;
    start=start->link;
    free(ptr);
}
void delete_last(){
    node *ptr,*prevptr;
    ptr = start;
    prevptr = start;
    while(ptr->link != NULL)
	{
        prevptr = ptr;
        ptr = ptr->link;
    }
    prevptr->link = NULL;
    free(ptr);
}
void delete_val(){
    int val;
    node *ptr,*prevptr;
    prevptr = start;
    ptr = start;
    printf("enter value to be deleted");
    scanf("%d",&val);
    while(ptr->data!=val){
        prevptr = ptr;
        ptr = ptr->link;
    }
    prevptr->link = ptr->link;
    free(ptr);
}
