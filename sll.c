#include<stdio.h>
#include<stdlib.h>
//sll
struct node
{
	char label[20];
	int val;
	struct node *next;
};
struct node *head = NULL;

void display()
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
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
	}
	else
	{
		while(p!=NULL)
			p=p->next;
		p->next=temp;
		temp->next=NULL;
	}
}

void display()
{
	struct node *p;
	p=head;
	int i=1;
	while(p!=tail)
	{
		printf("\n%d\t%s\t%d\n",i++,p->label,p->val);
		p=p->next;
	}
	printf("\n%d\t%s\t%d\n",i++,p->label,p->val);
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
		//case 2:delete();break;
		case 3:display();break;
		case 4:break;
		default:printf("\nEnter the valid choice..");break;
	}
	}while(ch!=4);
}
