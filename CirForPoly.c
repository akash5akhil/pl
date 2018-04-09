#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
int power;
float coeff;
struct node *next;
}node;
float pow1(float n, int p);
node * insert(node *head,int power1,float coeff1);
node * create();
node * padd(node *p1,node *p2,node *p3);
node * pmul(node *p1,node *p2);
float eval(node *p1,float x);
void print(node *head);
node *insert(node *head,int power1,float coeff1)
{
	node *p,*q;
	p=(node*) malloc(sizeof(node));
	p->power=power1;
	p->coeff=coeff1;
	p->next=NULL;	
	if(head==NULL)
	{
		head=p;
		head->next=head;
		return(head);
	}
	if(power1<head->power)  //arrage in descending order of power
	{
		p->next=head->next;
		head->next=p;
		head=p;
		return(head);
	}
	if(power1==head->power) //add coefficients
	{	
		head->coeff=head->coeff+coeff1;
		return(head);
	}	
	q=head;
	while(q->next!=head && power1<=q->next->power) //locate the postion for insertion
		q=q->next;
	if(p->power==q->power)
		q->coeff=q->coeff+coeff1;
	else
	{
		p->next=q->next;
		q->next=p;
	}	
	return(head);
}
node *create()
{
	int n,i,power1;
	float coeff1;
	node *head=NULL;
	printf("\nEnter No. of Terms:");
	scanf("%d",&n);
	head=insert(head,-1,0);
	for(i=1;i<=n;i++)
	{	
		printf("\nenter a term as a tuple of (power,coefficient) : ");
		scanf("%d%f",&power1,&coeff1);
		head=insert(head,power1,coeff1);
	}
	return(head);
}
node * padd(node *p1,node *p2,node *p3)
{
int done=0;
node *t1,*t2,*startA;
t1=p1;
startA=t1;
t1=p1->next;
t2=p2->next;
do
{
	if(t1->power==t2->power) 
	{
		if (startA==t1) done=1;
		else
	{
	p3=insert(p3,t1->power,t1->coeff+t2->coeff);
         t1=t1->next;
         t2=t2->next;
	}

	}
	else if(t1->power>t2->power) 
		{
			p3=insert(p3,t1->power,t1->coeff);
         		t1=t1->next;
         
		}
	else if(t2->power>t1->power)
	{
		p3=insert(p3,t2->power,t2->coeff);
        	 t2=t2->next;
	}

}while(!done);
return p3;	
}
node *pmul(node *p1,node *p2)
{
	node *head1,*head2;
	node *head=NULL;
	
	head2=p2->next;
	if(head2->power == -1)
		head2=p2->next;
	do 
	{
		head1=p1->next;
		if(head1->power == -1)
			head1=p1->next;
		do 
		{
		
		head=insert(head,head1->power+head2->power,head1->coeff * head2->coeff);

		head1=head1->next;
		if(head1->power == -1)
			head1=head1->next;
		}while(head1!=p1->next);

		head2=head2->next;
		if(head2->power == -1)
		head2=head2->next;

	}while(head2!=p2->next);
	
	return(head);
}
float pow1(float n, int p)
{
 float r=1;
 for(; p>=1; p--)
    r = r*n;
 return r;
}
float eval(node *head,float x)
{
	float value=0.00,j;
	node *p;
	p=head->next;
	
	if(p->power == -1)
			p=p->next;
	do
	{
		j=pow1(x,p->power);
		value=value+p->coeff * j;
		p=p->next;
	}while(p!=head->next);
	
	return(value);
}
void print( node *head)
{
	node *p;
	p=head->next;
	printf("\n");
	do
	{
       		if(p->power!=-1)
		{
			printf("%fx^%d +",p->coeff,p->power);
			p=p->next;
		}
		else
			p=p->next;
	}while(p!=head->next);
}
void main()
{
	node *p1,*p2,*p3;
	int op;
	float value,x;
	p1=p2=p3=NULL;
	
	do
	{
		printf("\n1)Create first polynomial");
		printf("\n2)Create second polynomial");
		printf("\n3)Print first polynomial");
		printf("\n4)Print second polynomial");
		printf("\n5)Add\n6)Multiply\n7)Evaluate First Polynomial\n8)Quit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: p1=create();break;
			case 2: p2=create();break;
			case 3: print(p1);break;
			case 4: print(p2);break;
			case 5: p3=padd(p1,p2,p3);
			print(p3);break;
			case 6: p3=pmul(p1,p2);
			print(p3);break;
			case 7: printf("\nEnter the value of X:");
			scanf("%f",&x);
			value=eval(p1,x);
			printf("\nEvaluated value = %6.2f",value);
			break;
		}
		
	}while(op!=8);
}

