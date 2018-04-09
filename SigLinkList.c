#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}node;

struct node *head;

node *create()
{
  int n,i;
  node *head=NULL,*p,*temp;
  printf("\n ENTER THE LENGTH OF LIST : ");
  scanf("%d",&n);
  printf("\n ENTER THE ELEMENTS IN THE LIST : ");
  for(i=0;i<n;i++)
  {
   temp=(node*)malloc(sizeof(node));
   scanf("%d",&temp->data);
   if(head==NULL)
    {
      head=temp;
         p=temp;
    }
    else
    {
      p->next=temp;
            p=temp;
    }  
  }
 return head;
}

void display()
{
  node *temp=head;
  printf("\nLIST :- ");
  while(temp!=NULL)
   {
     printf("%d\t",temp->data);
     temp=temp->next;
   }
  
}

void insertF()
{
  node *temp;
  temp=(node*)malloc(sizeof(node));
  printf("\n ENTER THE ELEMENT TO ADD IN  THE LIST : ");
  scanf("%d",&temp->data);
  temp->next=NULL;

  temp->next=head;
  head=temp;
}
void insertML()
{ 
  int n;
  
  node *temp1;
  temp1=(node*)malloc(sizeof(node));
  printf("\n ENTER THE ELEMENT TO ADD IN THE LIST : ");
  scanf("%d",&temp1->data);
  temp1->next=NULL;
  
  printf("\n AFTER WHICH ELEMENT TO BE INSERTED : ");
  scanf("%d",&n);
  
  node *temp2=head;
  while(temp2->data!=n)
   {
     temp2=temp2->next;
   }
  temp1->next=temp2->next;
  temp2->next=temp1;
}

void delete()
{
  int n,i;
  
  printf("ENTER THE POSITION TO DELETE : ");
  scanf("%d",&n);
  node *temp1=head;
  if(n==1)
   {
    head=temp1->next;
    free (temp1);
   }
  else
  {
   for(i=1;i<n-1;i++)
    {
     temp1=temp1->next;
    }
    node *temp2;
    temp2=temp1->next;
    temp1->next=temp2->next;
    free (temp2);
  }
}

void displayR(node *temp)
{
  if(temp==NULL)
   {
     printf("\n");
     return;
   }
  displayR(temp->next);
  printf("%d\t",temp->data);
}

void reverse()
{
 node *current,*next,*prev;
 
 current=head;
 prev=NULL;
 while(current != NULL)
  {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
head=prev;
}

void main()
{
  head=NULL;
  head=create();
  int choice,c;
 do
 {
   printf("\n**********MENU********* \n 1.DISPLAY \n 2.INSERT \n 3.DELETE \n 4.DISPLAY IN REVERSE \n 5.REVERSE \n 6.EXIT \n");
   printf("\n ENTER YOUR CHOICE : ");
   scanf("%d",&choice);
   switch(choice)
   {
     
	case 1: //display
                display();
	            break;

	case 2: //insert
	        do
		{
                 printf("\n 1.BEGINING \n 2.MID OR LAST \n 3.BACK TO MAIN MENU \n");
                 scanf("%d",&c);
                 switch(c)
   		  {               
		    case 1: //begining
                              insertF();
                              display();
                              break;

                    case 2: //at mid or last
                              insertML();
                              display();
                              break;
                  
                    case 3: //exit
 	      		      break;
                  } 
                }while(c!=3); 

                break;

	case 3: //delete
                delete();
                display();
	        break;

	case 4: //display in reverse
		displayR(head);    
		break;

	case 5: //reverse
                reverse();
                display();
	        break;

	case 6: //exit
	            break;
   
      default : printf("\n INVALID CHOICE"); 
   }
 }while(choice!=6);
}
