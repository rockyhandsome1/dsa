#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//sll
struct node
{
	char label[20];
	int val;
	struct node *next;
};
struct node *head = NULL;

void insert()
{
	struct node *temp,*p;
	p=head;
	int value;
	char labelname[20];
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the label name:");
	scanf("%s",labelname);
	printf("\nEnter the value:");
	scanf("%d",&value);
	temp->val = value;
	strcpy(temp->label, labelname);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}

void delete()
{
	struct node *temp,*p;
	p=head;
	int value;
	char labelname[20];
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the label name:");
	scanf("%s",labelname);
	if(head==NULL)
	{
		printf("\nSymtab is empty!\n");
	}
	if(strcmp(head->label, labelname)==0)
	{
		temp=head;
		head=head->next;
	}
	else
	{
		while (p != NULL)
		       if (strcmp(p->next->label, labelname)==0)
		       {
		           printf("deleting label: %s\n", labelname);
		           temp = p->next;

		           p->next = p->next->next;
			   break;
		       }
	}
	free(temp);
}
void display()
{
	struct node *p;
	p=head;
	int i=1;
	if(head==NULL)
		printf("Symtab is empty");
	else	
	while(p!=NULL)
	{
		printf("\n%d\t%s\t%d\n",i++,p->label,p->val);
		p=p->next;
	}
}

void main()
{
	int ch;
	do{
	printf("\n1.Enter the content to symtab");
	printf("\n2.Delete the content of the symtab");
	printf("\n3.Display the table");
	printf("\n4.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert();break;
		case 2:delete();break;
		case 3:display();break;
		case 4:break;
		default:printf("\nEnter the valid choice..");break;
	}
	}while(ch!=4);
}
