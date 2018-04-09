#include<stdio.h>
int icount=0;
struct employee
{
	int emp_id;
	char name[10];
	char dep[10];
	int salary;
};
void add(struct employee e1[10],int n,int m);
void create(struct employee e1[10],int n);
void display(struct employee e1[10],int n);
int search(struct employee e1[10],int emp_id,int n );
void modify(struct employee e1[10],int s,int n);
int delate(struct employee e1[10],int s,int n);

void main()
{
	struct employee e1[10];
	int i,n,ch,m,s,id,x,h;
	printf("Enter the how many record in the database");
	scanf("%d",&n);
	do
	{
	printf("\n1.create database\n"); 
	printf("2.display database\n");
	printf("3.add record\n"); 
	printf("4.search record\n");
	printf("5.modify record\n"); 
	printf("6.Delate record\n"); 
	printf("Enter the choice\n");
	scanf("%d",&ch);
	switch(ch) 
	{
		case 1:
		{
			create(e1,n);
			break;
		}
		case 2:
		{
			printf("EM-ID\tNAME\tDEPARTMENT\tSALARY\n");
			display(e1,n);
			break;
		}
		case 3:
		{
			printf("How many record you want to add\n");
			scanf("%d",&m);
			add(e1,n,m);
			n=n+m;
			break;
		}
		case 4:
		{
			printf("Enter the emp id which you want to search\n");
			scanf("%d",&id);
			s=search(e1,id,n);
			printf("%d\t",e1[s].emp_id);
			printf("%s\t",e1[s].name);
			printf("%s\t\t",e1[s].dep);
			printf("%d\t",e1[s].salary);
			break;
		}
		case 5:
		{
			printf("Enter the emp id which you want to modify");
			scanf("%d",&id);
			s=search(e1,id,n);
			modify(e1,s,n);
			break;
		}
		case 6:
		{
			printf("Enter the emp id which you want to delate\n");
			scanf("%d",&id);
			s=search(e1,id,n);
			x=delate(e1,s,n);
			n=x;
			break;
		}
	}
	}while(ch!=7);
}

void create(struct employee e1[10],int n)
{
	int i,id;
	for(i=1;i<=n;i++)
	{
		printf("Enter the %d) emp_id \n",i);
		scanf("%d",&e1[i].emp_id);
		printf("Enter the %d) name \n",i);
		scanf("%s",e1[i].name);
		printf("Enter the %d) department \n",i);
		scanf("%s",e1[i].dep);
		printf("Enter the %d)salary \n",i);
		scanf("%d",&e1[i].salary);
		icount++;	
	}
}
void display(struct employee e1[10],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d\t",e1[i].emp_id);
		printf("%s\t",e1[i].name);
		printf("%s\t\t",e1[i].dep);
		printf("%d\t",e1[i].salary);
		printf("\n");
	}
}

int search(struct employee e1[10],int id,int n )
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(e1[i].emp_id==id)
		{
			break;
		}
	}
	return i ;	
}

void add(struct employee e1[10],int n,int m)
{
	int i;
	for(i=n+1;i<=n+m;i++)
	{
		printf("Enter the %d) emp_id \n",i);
		scanf("%d",&e1[i].emp_id);
		printf("Enter the %d) name \n",i);
		scanf("%s",e1[i].name);
		printf("Enter the %d) department \n",i);
		scanf("%s",e1[i].dep);
		printf("Enter the %d)salary \n",i);
		scanf("%d",&e1[i].salary);
		icount++;		
	}

}

void modify(struct employee e1[10],int s,int n)
{
	int ch;
	do
	{
	printf("1.modify in name\n");
	printf("2.modify in department\n");
	printf("3.modify in salary\n");
	printf("Enter the choice \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 :
		{
		 	printf("Enter the new name of the employee\n");	
			scanf("%s",e1[s].name);
			break;
		}
		case 2 :
		{
			printf("Enter the new department of the employee\n");	
			scanf("%s",e1[s].dep);
		 	 break;
		}
		case 3 :
		{
			printf("Enter the new salary of the employee\n");	
			scanf("%d",&e1[s].salary);
			break;
		}
	}
}while(ch!=4);
}

int delate(struct employee e1[10],int s,int n)
{
	int i;
	for(i=1;i<=(n+1);i++)
	{
		if(i>=s)
		{
		e1[i]=e1[i+1];
		}
	icount--;
	}
	return (n-1); 
}


