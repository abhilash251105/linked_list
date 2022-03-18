#include<conio.h>
#include<stdio.h>
#include<alloc.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
};
typedef struct list node;
node *head=NULL;
int count=0;
void create()
{
	int i,c;
	printf("enetr total node number:");
	scanf("%d",&c);
	for(i=0;i<c;i++)
	{
		node *a,*b;
		a=(node *)malloc(sizeof(node));
		printf("enter %d element : \t",i);
		scanf("%d",&a->data);
		a->next=NULL;
		if(head==NULL)
		{
			b=head=a;
		}
		else
		{
			b->next=a;
			b=a;
		}
	   //sorted_list();
	}
}
void insert_beg()
{
	node *new1;
	new1=(node *)malloc(sizeof(node));
	printf("enter the element:\n");
	scanf("%d",&new1->data);
	new1->next=NULL;
	if(head==NULL)
	{
	 head=new1;
	}
	else
	{
	 new1->next=head;
	 head=new1;
	 //sorted_list();
	}
	printf("Add successfully");
       //	sorted_list();
}
void insert_end()
{
	node *new2,*last;
	new2=(node *)malloc(sizeof(node));
	printf("enter the element at end:\n");
	scanf("%d",&new2->data);
	new2->next=NULL;
	if(head==NULL)
		head=new2;
	else
	{
		last=head;
		while(last->next!=NULL)
		{
			last=last->next;
		}
		last->next=new2;
	}
	printf("Add successfully");
       //	sorted_list();
}
void insert_mid()
{
	node *new3,*temp,*pt;
	int pos,i=1,count=0;
	new3=(node *)malloc(sizeof(node));
	new3->next=NULL;
	pt=head;
	printf("enter position:\n");
	scanf("%d",&pos);
	while(pt!=NULL)
	{
		pt=pt->next;
		count++;
	}
	if(head==NULL)
	{
		new3->next=NULL;
		head=new3;
	}
	else
	{
			if(pos>count)
			{
				printf("invalid position!");
			}
			else
			{
			temp=head;
			for(i=0;i<pos-1;i++)
			{
				temp=temp->next;
			}
			printf("enter element:\n");
			scanf("%d",&new3->data);
			new3->next=temp->next;
			temp->next=new3;
			printf("Add successfully\n");
			}
	}
	//sorted_list();

}
void display()
{
	printf("head:%d\n",head->data);
	node *ptr;
	int count=0;
	ptr=head;
	printf("\nlist of element:");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
		count++;
		//printf("\nptr:%d\n",ptr->next);
	}
	printf("\nptr:%d\n",ptr->next);
	printf("\nTotel element in link list:%d\n",count);
       //	sorted_list();
}
void delete_beg()
{
	node *temp;
	temp=head;
	if(temp==NULL)
	    printf("\nempty list:\n");
	else
	{
	    head=temp->next;
	    free(temp);
	}
	printf("Deletet successfully!\n");
	//sorted_list();
}
void delete_end()
{
	node *last,*lastp;
	if(head==NULL)
	{
		printf("Empty list:\n");
	}
	else
	{
		last=head;
		while(last->next!=NULL)
		{
			lastp=last;
			last=last->next;
		}
		lastp->next=NULL;
		free(last);
	}
	printf("Deletet successfully!\n");
	//sorted_list();

}
void delete_any()
{
	node *last,*temp,*pt;
	int pos,i=1,count=0;
	temp=head;
	pt=head;
	printf("Enter position:\n");
	scanf("%d",&pos);
	while(pt!=NULL)
	{
		pt=pt->next;
		count++;
	}
	if(pos>count)
	{
		printf("Invalid position\n");
	}
	else
	{
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		last=temp->next;
		temp->next=last->next;
		free(last);
		printf("Delete sucessfully!\n");
	}
	//sorted_list();
}
void sorted_list()
{
	node *cu=head,*ind=NULL;
	int temp;
	if(head==NULL)
	{
		printf("list empty:\n");
	}
	while(cu!=NULL)
		{
			ind=cu->next;
			while(ind!=NULL)
			{
				if(cu->data>ind->data)
				{
					temp=cu->data;
					cu->data=ind->data;
					ind->data=temp;
				}
				ind=ind->next;
			}
			cu=cu->next;
		}
		display();
}
int main()
{
	//sorted_list();
	//clrscr();
	int ch;
	while(1)
	{
		printf("\n1.create()\t2.insert_beg()\t3.insert_end()\t4.insert_mid()\t5.display()\t6.delete_beg()\t7.delete_end()\t8.delete_any()\t9.sorted_list()\t10.exit()\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
			break;

			case 2:insert_beg();
			break;

			case 3:insert_end();
			break;

			case 4:insert_mid();
			break;

			case 5:display();
			break;

			case 6:delete_beg();
			break;

			case 7:delete_end();
			break;

			case 8:delete_any();
			break;

			case 9:sorted_list();
			break;

			case 10:exit(0);
			break;

		}

	}
       /*	create();
	display();
	getch(); */
}
