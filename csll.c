#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//csll
struct node
{
	int id;
	char name[20];
	struct node *next;
};
struct node *head = NULL, *tail = NULL;

void addcust()
{
	struct node *temp,*p;
	p=head;
	int csid;
	char nam[20];
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the customer id:");
	scanf("%d",&csid);
	printf("\nEnter the customer name:");
	scanf("%s",nam);
	temp->id = csid;
	strcpy(temp->name, nam);
	if(head==NULL)
	{
		head=temp;
		temp->next=head;
		tail=temp;
	}
	else
	{
		while(p!=tail)
			p=p->next;
		temp->next=p->next;
		p->next=temp;
		tail=temp;
	}
}

void displayrecent()
{
	struct node *p;
	p=head;
	printf("\nThe last customer is:\n");
	while(p!=tail)
		p=p->next;
	printf("\nCustomer id:%d",p->id);
	printf("\tCustomer name:%s\n",p->name);
}

void displayall()
{
	struct node *p;
	p=head;
	int i=1;
	while(p!=tail)
	{
		printf("\n%d]\t%d\t%s\n",i++,p->id,p->name);
		p=p->next;
	}
	printf("\n%d]\t%d\t%s\n",i++,p->id,p->name);
}

void main()
{
	int ch;
	do{
	printf("\n1.Enter the customer details");
	printf("\n2.Display the last customer");
	printf("\n3.Display all the customers");
	printf("\n4.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:addcust();break;
		case 2:displayrecent();break;
		case 3:displayall();break;
		case 4:break;
		default:printf("\nEnter the valid choice..");break;
	}
	}while(ch!=4);
}
