#include <stdio.h>
#include <stdlib.h> 
typedef struct DLL
{
    struct DLL *prev;
    int roll;
    struct DLL *next;
}node; 
node * insert(node *head);
node * insertstart(node *head);
void traversebeg(node *head);
void traverseend(node *head);
void search(node *);
void update(node *);
node * delete(node *);
void main()
{
  node *head;
    int ch; 
    while (1)
    {printf("\n 1 - Insertat start ");
    printf("\n 2 - Insertat end ");
    printf("\n 3 - Delete ");
    printf("\n 4 - Display ");
    printf("\n 5 - Display in Reverse order");
    printf("\n 6 - Search for element");
    printf("\n 7 - Update an element");
    printf("\n anything else ---> Exit\n");   
    printf("\n Enter choice :(1...7)  ");
    scanf("%d", &ch);
        switch (ch)
        {case 1:head=insertstart(head);
               break;     
        case 2:head=insert(head); 
               break;         
        case 3:head=delete(head);
               break;
        case 4:traversebeg(head);
               break;
        case 5:traverseend(head);
               break;
        case 6:search(head);
               break;
        case 7:update(head);
               break;
        default:exit(0);
               break;       
      
        }
    }
}
node * insertstart(node *head)
{ node *temp;
 temp=(node *)malloc(sizeof(node));
 printf("Please enter your roll number.\n");
 scanf("%d",&temp->roll);
 if(head!=NULL)
 {
 temp->next=head;  // link the newly created node in the beginning
 head->prev=temp;
 }
 head=temp;     
return head;
}
node * insert(node *head)
{
  node  *temp,*h1;
  int n, i=0,data;
  h1=head;       
	printf("Please enter the number of inputs to be appended.\n");
	scanf("%d",&n);	
    if (head == NULL)
    {   temp =(node *)malloc(1*sizeof(node)); 
        temp->prev = NULL;
        temp->next = NULL;
        printf("\n Enter value to node : ");
        scanf("%d", &data);
        temp->roll = data;
        h1=head = temp;
       i++;
     }while(h1->next!=NULL)
      h1=h1->next;    
    while(i<n)
    {   temp =(node *)malloc(1*sizeof(node));//allocated memory 
        temp->prev = NULL;
        temp->next = NULL;
        printf("\n Enter value to node : ");
        scanf("%d", &data);
        temp->roll = data;         
        h1->next = temp; 
        temp->prev = h1;
        h1 = temp;
        i++;
    }
  return(head);
}
node * delete(node *head)
{   node *h1, *current,*previous;
	int rol,flag=0;
        h1=head;
       if (head== NULL)
       {printf("Sorry :List is empty \n");
        return head;
       }
	printf("Please enter the roll number, you want to delete from the list.\n");
	scanf("%d",&rol);	
          if(h1->roll==rol)//if roll no to be deleted is the first node
          {head=h1->next;
          if(head!=NULL)
          head->prev=NULL;
          printf("Node deleted from the list");
          free(h1);
          flag=1;
          } 
          else
          {while (h1!=NULL)
              {if(h1->roll==rol)
                  {if(h1->next!=NULL)
                   h1->next->prev=previous;
                  previous->next=h1->next;
                  printf("Node deleted from the list");
                  free(h1);
                  break;
                  }
                  previous=h1;
                  h1= h1->next;
             }
            if(h1==NULL)
            printf("Node not present in the list");
           }
      traversebeg(head);
return head;
}
void traversebeg(node *head)
{ node * temp;
  temp=head; 
    if (temp == NULL)
    {   printf("Sorry :List is empty \n");
        return;
    }
    printf("\n Linked list elements from begining : "); 
    while (temp->next != NULL)
    {   printf("|%d|-->", temp->roll);
        temp = temp->next;
    }
    printf("|%d|", temp->roll);
}
void traverseend(node *head)
{   node *temp;
    temp=head;
    if (temp == NULL)
    {   printf("Sorry :List is empty \n");
        return;
     }
    printf("Double linked list \n");
    while (temp->next != NULL)
    { temp = temp->next;
    }
    while(temp->prev!=NULL)
   {     printf("|%d|-->", temp->roll);
         temp=temp->prev;
   } 
     printf("|%d|", temp->roll);

}
void search(node *head)
{   int data,count;
    node *temp;
    temp = head;
     count=0;
    if (head == NULL)
    {   printf("\n Sorry : List empty to search for data");
        return;
    }
    printf("\n Enter value to search : ");
    scanf("%d", &data);
    while (temp != NULL)
    {   if (temp->roll == data)
        {   printf("\n Data found in %d position",count + 1);
            return;
        }
        else
             temp = temp->next; count++;
     }
    printf("\n Sorry : %d not found in list", data);
}
void update(node *head)
{   int data, data1;
    node *temp;   
    temp = head;
    if (temp == NULL)
    {   printf("\n Error : List empty no node to update");
        return;
    }
    printf("\n Enter node data to be updated : ");
    scanf("%d",&data);    
     while (temp != NULL)
    {   if (temp->roll == data)
        {   printf("\n Enter new data : ");
            scanf("%d",&temp->roll);
            return;
        }
        else
            temp = temp->next;
    } 
    printf("\n Sorry : %d not found in list to update", data);
}
