
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *Llink;
	struct NODE *Rlink;
};
typedef struct NODE node;
node *start, *curr, *neww;

void create();
void display();
void insert_beg();
void delete_val();

int main()
{
	int ch;
	printf("Doubly Linked List\n");
	while(1)
	{
		printf("1.Create  2.Display  3.Insert_beg  4.Delete_val  5.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2: display();
					break;
			case 3: insert_beg();
					break;
			case 4: delete_val();
					break;
			case 5: exit(0);
			default: printf("Invalid Choice!!\n");
		}
	}
	return 0;
}

void create()
{
	int ch;
	start=(node*)malloc(sizeof(node));
	printf("Enter ele:\n");
	scanf("%d",&start->data);
	start->Llink=NULL;
	curr=start;
	while(1)
	{
		printf("Do u want to add another ele:(1/0)\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			neww=(node*)malloc(sizeof(node));
			curr->Rlink=neww;
			neww->Llink=curr;
			printf("Enter ele:\n");
			scanf("%d",&neww->data);
			curr=neww;
		}
		else
		{
			curr->Rlink=NULL;
			break;
		}
	}
}

void display()
{
	node *temp;
	if(start==NULL)
	{
		printf("DLL is empty\n");
		return;
	}
	temp=start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->Rlink;
	}
}

void insert_beg()
{
	neww=(node*)malloc(sizeof(node));
	printf("Enter ele:\n");
	scanf("%d",&neww->data);
	if(start==NULL)
	{
		neww->Llink=NULL;
		neww->Rlink=NULL;
		start=neww;
		return;
	}
	neww->Rlink=start;
	start->Llink=neww;
	neww->Llink=NULL;
	start=neww;
}

void delete_val()
{
	int ele;
	node *temp;
	if(start==NULL)
	{
		printf("DLL is empty\n");
		return;
	}
	printf("Enter element to be deleted\n");
	scanf("%d",&ele);
	if(start->data==ele && start->Rlink!=NULL)
	{
		temp=start;
		start=start->Rlink;
		start->Llink=NULL;
		free(temp);
	}
	temp=start;
	while(temp->Rlink!=NULL && temp->data!=ele)
	{
		temp=temp->Rlink;
	}
	if(temp->data && temp->Rlink==NULL)
	{
		temp->Llink->Rlink=NULL;
		free(temp);
	}
	if(temp->data==ele && temp->Rlink!=NULL)
	{
		temp->Llink->Rlink=temp->Rlink;
		temp->Rlink->Llink=temp->Llink;
		free(temp);
		return;
	}
	printf("element not found\n");
}
