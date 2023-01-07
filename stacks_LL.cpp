#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct NODE
{
    int data;
    struct NODE *link;
};
typedef struct NODE node;
node *top = NULL;

void push();
void pop();
void display();

void push()
{
    node *neww;
    neww = (node *)malloc(sizeof(node));
    printf("\nEnter an element: ");
    scanf("%d", &neww->data);
    if (top == NULL)
    {
        top = neww;
        neww->link = NULL;
        return;
    }
    neww->link = top;
    top = neww;
}

void pop()
{
    node *temp;
    if (top == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    temp = top;
    top = top->link;
    printf("\nPopped element is %d\n", temp->data);
    free(temp);
}

void display()
{
    node *temp;
    if (top == NULL)
    {
        printf("\nStack is Empty\n");
        return;
    }
    printf("\nStack Contents\n");
    temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.PUSH\n2.POP\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: push();
            	break;
        case 2:pop();
            	break;
        case 3: display();
            	break;
        case 4: exit(0);
            	break;
        default:printf("wrong choice");
        }
    }
    return 0;
}
