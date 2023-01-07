#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node node;
node *start1 = NULL, *start2 = NULL, *start3 = NULL;

void createll1()
{
    int choice;
    start1 = (node *)malloc(sizeof(node));
    node *neww, *curr;
    curr = start1;
    printf("Enter the value\n");
    scanf("%d", &start1->data);
    while (1)
    {
        printf("add another element\n");
        printf("1.yes2.no\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            neww = (node *)malloc(sizeof(node));
            printf("Enter the value\n");
            scanf("%d", &neww->data);
            curr->link = neww;
            curr = neww;
        }
        else
        {
            curr->link = NULL;
            break;
        }
    }
}

void createll2()
{
    int choice;
    start2 = (node *)malloc(sizeof(node));
    node *neww, *curr;
    curr = start2;
    printf("Enter the value\n");
    scanf("%d", &start2->data);
    while (1)
    {
        printf("add another element\n");
        printf("1.yes2.no\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            neww= (node *)malloc(sizeof(node));
            printf("Enter the value\n");
            scanf("%d", &neww->data);
            curr->link = neww;
            curr = neww;
        }
        else
        {
            curr->link = NULL;
            break;
        }
    }
}

void concat()
{
    if (start1 == NULL)
    {
        start3 = start2;
        return;
    }
    if (start2 == NULL)
    {
        start3 = start1;
        return;
    }

    node *temp=NULL;

    temp = start1;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = start2;
    start3 = start1;
}

void display(node *ptr)
{
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
}

void sort(){
    node *ptr,*cpt;
    int temp;
    ptr=start1;
    while(ptr->link!=NULL){
        cpt=ptr->link;
        while(cpt!=NULL){
            if(ptr->data>cpt->data){
                temp=ptr->data;
                ptr->data=cpt->data;
                cpt->data=temp;
            }
            cpt=cpt->link;
        }
        ptr=ptr->link;
    }
}

void reverse(){
    node *prev,*curr,*next;
    prev=NULL;
    curr=next=start1;
    while(next!=NULL){
        next=next->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }start1=prev;
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.createll1\t2.createll2\t3.concatenate\t4.displayll1\t5.displayll2\t6.displayllcnc\t7.sort\t8.reverse\t9.exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createll1();
            break;
        case 2:
            createll2();
            break;

        case 3:
            concat();
            break;
        case 4:
            display(start1);
            break;
        case 5:
            display(start2);
            break;
        case 6:
            display(start3);
            break;
        case 7:
            sort();
            break;
        case 8:reverse();
            break;
        case 9:exit(0);
        }
    }
}
