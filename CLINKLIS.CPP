#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct list
{
	int data;
	struct list *next;
};
typedef struct list node;
node *head=NULL;
node *last;
void creatr_clist()
{
	node *new1,*temp;
	int i,a;
	printf("Enter total number of node you want:\t");
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		new1=(node*)malloc(sizeof(node));
		printf("Enter data in %d node:\t",i);
		scanf("%d",&new1->data);
		if(head==NULL)
		{
			head=new1;
			new1->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=new1;
			new1->next=head;
		}
	}
	printf("Add successfully");
}
void insert_beg()
{
	node *new2;
	new2=(node*)malloc(sizeof(node));
	printf("Enter element:\t");
	scanf("%d",&new2->data);
	if(head==NULL)
	{
		head=new2;
		last=head;
		new2->next=head;
	}
	else
	{
		new2->next=head;
		head=new2;
		last->next=head;
	}
	printf("Add successfully");
}
void insert_end()
{
	node *new3,*sec;
	new3=(node*)malloc(sizeof(node));
	printf("Enter element in end:\t");
	scanf("%d",&new3->data);
	if(head==NULL)
	{
		head=new3;
		new3->next=head;
	}
	else
	{
		sec=head;
		while(sec->next!=head)
		{
			sec=sec->next;
		}
		sec->next=new3;
		new3->next=head;
	}
	printf("Add successfully");
}
void insert_any()
{
	int i,pos,count=0;
	node *new4,*as,*ho;
	new4=(node*)malloc(sizeof(node));
	printf("\nEnter position:");
	scanf("%d",&pos);
	as=head;
	ho=head;
	while(as->next!=head)
	{
		as=as->next;
		count++;
	}
	if(head==NULL)
	{
		printf("\nList is empty \n Cannot insert an elementat this position!");
	}
	else
	{
		if(pos>count+1)
		{
			printf("Invalid position!");
		}
		else
		{
			for(i=0;i<pos-1;i++)
			{
				ho=ho->next;
			}
			printf("\nEnter element:\t");
			scanf("%d",&new4->data);
			new4->next=ho->next;
			ho->next=new4;
		}
	}
}
void display()
{
	node *ptr;
	int count=0;
	ptr=head;
	if(ptr==NULL)
	{
		printf("Empty linked list!\n");
	}
	else
	{
		printf("Link list element is:\t");
		do
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
			count++;
		}while(ptr!=head);
	}
	printf("\nTotal element in c_list:%d",count);
}
void main()
{
	clrscr();
	int ch;
	while(1)
	{
		printf("\n1.creatr_clist()\t2.insert_beg()\t3.insert_end()\t4.insert_any()\t5.display()\t6.exit()\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:creatr_clist();
			break;

			case 2:insert_beg();
			break;

			case 3:insert_end();
			break;

			case 4:insert_any();
			break;

			case 5:display();
			break;

			case 6:exit(0);
			break;
		}
	}
}