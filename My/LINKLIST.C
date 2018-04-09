#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;

int n;
struct node* CreateNode()
{
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter Node Data");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	return(newNode);
}

void accept()
{
	struct node *newNode,*temp;
	int i;
	head=NULL;
	printf("\nEnter How Many Nodes You Want Accept");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		struct node *newNode=CreateNode();
		if(head==NULL)
		{
			head=newNode;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}

			temp->next=newNode;
		}
	}
}

void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}

void insertAtBegin()
{
	struct node *newNode=CreateNode();
	newNode->next=head;
	head=newNode;
}

void insertAtEnd()
{
	struct node *temp;
	struct node *newNode=CreateNode();
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newNode;
}

void insertAfter()
{
	struct node *temp,*temp1;
	int n;
	struct node *newNode=CreateNode();
	temp=head;
	printf("\nEnter After You Insert");
	scanf("%d",&n);
	while(temp->data!=n)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=newNode;
	newNode->next=temp;
}

void deleteAtBegin()
{
	struct node *temp;
	temp=head;
	head=head->next;
	temp->next=NULL;
	free(temp);
}

void deleteAtEnd()
{
	struct node *temp,*old;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	old->next=NULL;
	free(temp);
}

void deleteAfter()
{
	struct node *temp,*temp1,*temp2;
	int n;
	printf("\nAfter Which node You Want to Delete");
	scanf("%d",&n);
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp2=temp1->next;
	temp->next=temp2;
	free(temp1);
}

void Search()
{
	struct node *temp,*data;
	int flag,n;
	flag=0;
	printf("\nEnter Node To be Search ");
	scanf("%d",&n);
	temp=head;
	while(temp!=NULL)
	{
		if(n==temp->data)
		{
			flag=1;
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(flag==1)
	{
		printf("\nNode Found");
	}
	else
	{
		printf("\nNode is not Found");
	}
}

void Update()
{
	struct node *temp,*head;
	int flag=0;
	int n;
	temp=head;
	printf("\nEnter Data Which You Want To Update");
	scanf("%d",&n);
	while(temp!=NULL)
	{
		if(n==temp->data)
		{
			printf("\nEnter New Data");
			scanf("%d",&temp->data);
			flag=1;
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(flag==0)
	{
		printf("\nNo Data Found To Update");
	}
	else
	{
		printf("\nUpdate SuccessFull");
	}
}

void reverse()
{
	struct node *oldold,*old,*temp;
	temp=head;
	while(temp!=NULL)
	{
		oldold=old;
		old=temp;
		temp=temp->next;
		old->next=oldold;

	}
	head->next=NULL;
	head=old;
}

int main()
{
	int ch;
	do{
	printf("\nMENU\n1.Accept Link List \n3.Display");
	printf("\n4.Insert At Begin \n5.Insert At End \n6.Insert After");
	printf("\n7.Delete At Begin \n8.Delete At End \n9.Delete After");
	printf("\n10.Search \n11.Update \n12.reverse \n13.Exit");
	printf("\nEnter Your Choice ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: accept();
		break;
	case 3: display();
		break;
	case 4: insertAtBegin();
		break;
	case 5: insertAtEnd();
		break;
	case 6: insertAfter();
		break;
	case 7: deleteAtBegin();
		break;
	case 8: deleteAtEnd();
		break;
	case 9: deleteAfter();
		break;
	case 10: Search();
		break;
	case 11: Update();
		break;
	case 12: reverse();
		break;
	case 13: exit(0);
	}
	}while(ch);
	return 0;
}
