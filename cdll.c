#include<stdio.h>
#include<stdlib.h>
//cdll
struct node
{
	struct node *prev;
	int info;
	struct node *next;
};
struct node *head = NULL, *tail = NULL;

void atfront();
void atend();
void afterkey();
void addatposition();
void deletefront();
void deleterear();
void display();

void main()
{
	int ch;
	do{
		printf("\n1.insert front");
		printf("\n2.insert rear");
		printf("\n3.insert after key");
		printf("\n4.insert at some position");
		printf("\n5.delete front");
		printf("\n6.delete rear");
		printf("\n7.display");
		printf("\n8.exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:atfront();break;
			case 2:atend();break;
			case 3:afterkey();break;
			case 4:addatposition();break;
			case 5:deletefront();break;
			case 6:deleterear();break;
			case 7:display();break;
			case 8:break;
			default:printf("\nEnter a valid choice..\n");break;
		}
	}while(ch!=8);
}

void atfront()
{
	struct node *temp, *p;
	p=head;
	int data;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the element:");
	scanf("%d",&data);
	temp->info=data;
	if(head == NULL)
	{
		head = temp;
		temp->next = head;
		temp->prev = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		while(p!=tail)
			p=p->next;
		p->next = temp;
		temp->prev = p;
		head = temp;
	}
}

void atend()
{
	struct node *temp, *p;
        p=head;
	int data;
        if(head == NULL)
        {
              atfront();
        }
        else
        {
		temp = (struct node *)malloc(sizeof(struct node));
        	printf("\nEnter the element:");
        	scanf("%d",&data);
        	temp->info=data;
                while(p!=tail)
                        p=p->next;
                temp->prev = p;
		temp->next = p->next;
		p->next = temp;
		head->prev = temp;
		tail=temp;
        }

}

void afterkey()
{
	struct node *temp, *p;
        p=head;
	int val,data;
	int flag=0;
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the element value:");
        scanf("%d",&val);
	while(p!=tail)
	{
		if(p->info ==val)
		{
			printf("\nEnter the element to be inserted:");
			scanf("%d",&data);
			temp->info=data;
			temp->prev=p;
			p->next->prev=temp;
			temp->next=p->next;
			p->next=temp;
			flag++;
		}
		p=p->next;
	}
	if(flag==0)
		printf("\nThe entered element is not present in the list\n");
	
}

/*void addbefore(int key)
{
	struct node *temp, *p;
        p=head;
	int track=1,data,length=1;
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the element:");
        scanf("%d",&data);
	temp->info=data;
	if(tail==NULL && key!=1)
		printf("\nList is empty\n");
	else
	{	
		while(p!=tail)
		{
			p=p->next;
			length++;
		}
		p=head;
		while(track<length)
		{
		 p=p->next;
		 track++;
		}
		temp->next=p->next;
		p->next->prev=temp;
		p->next=temp;
		temp->prev=p;
	}
}
*/
void addatposition()
{
	int pos,length=1,l=1;
	struct node *p;
	p=head;
	printf("\nEnter the position:");
	scanf("%d",&pos);
	while(p!=tail)
	{
		length++;
		p=p->next;
	}
	if(pos == 0)
                atfront();
	else if(pos == length)
		atend();
	else if(pos>length)
		printf("\nEntry not allowed\n");
	else
	{
		struct node *temp;
		int data;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter the element:");
		scanf("%d",&data);
		temp->info=data;
		p=head;
                while(l<pos)
                {
                 p=p->next;
                 ++l;
                }
                temp->next=p->next;
                p->next->prev=temp;
                p->next=temp;
                temp->prev=p;
		l=1;
	}

}

void deletefront()
{
	struct node *temp,*p;
	p=head;
	if(head ==NULL)
		printf("\nNo elements to delete\n");
	else if(tail == head)
	{
		temp = head;
		head = NULL;
	}
	else
	{
		temp = head;
		while(p!=tail)
			p=p->next;
		p->next = head->next;
		head->next->prev = p;
		head = head->next;
	}
	free(temp);
}

void deleterear()
{
        struct node *temp,*p;
        p=head;
        if(head ==NULL)
                printf("\nNo elements to delete\n");
        else if(tail == head)
        {
                temp = head;
                head = NULL;
		tail = NULL;
        }
        else
        {
                while(p!=tail)
                        p=p->next;
                p->prev->next = p->next;
		head->prev = p->prev;
		temp = p;
		tail=p->prev;
        }
        free(temp);
}

void display()
{
	struct node *p;
	p=head;
	printf("\nThe list is:\n");
	if(head == NULL)
		printf("\nList is empty\n");
	else if(head == tail)
		printf("<-%d->\n",p->info);
	else
	{
		while(p!=tail)
		{
			printf("<-%d->",p->info);
			p=p->next;
		}
		  printf("<-%d->",p->info);
	}
	printf("\n");
}
