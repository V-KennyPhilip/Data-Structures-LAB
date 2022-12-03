#include <stdio.h>
# define size 3
void insert();
void delete1();
void dispaly();
int array[size];
int Rear = - 1, Front = - 1;
main()
{
    int choice;
    while (1)
    {
        printf("\n1.insert\n2.delete\n3.Display\n4.Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete1();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("\nIncorrect choice \n");
        } 
    } 
} 
 
void insert()
{
    int item;
    if (Rear == size- 1)
       printf("\nqueue overflow \n");
    else
    {
        if (Front == - 1)
      
        Front = 0;
        printf("\nenter element to be inserted:\n ");
        scanf("%d", &item);
        Rear = Rear + 1;
        array[Rear] = item;
    }
} 
 
void delete1()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("\nqueue underflow\n");
        return ;
    }
    else
    {
        printf("\nElement deleted is: %d\n", array[Front]);
        Front = Front + 1;
    }
} 
 
void display()
{
    int i;
    if (Front == - 1)
        printf("\nEmpty Queue\n");
    else
    {
        printf("\nQueue:\n");
        for (i= Front; i <= Rear; i++)
            printf("%d ",array[i]);
        printf("\n");
    }
}
