#include<stdio.h>
void accept(int a[], int size);
void display(int a[], int size);
void union_1(int a[], int b[], int size1, int size2);
void intersection(int a[], int b[], int size1, int size2);
void difference(int a[], int b[], int size1, int size2);
void sym_dif(int a[], int b[], int size1, int size2);
void main()
{
	int size1, size2,ans;	
	printf("Enter size of 2 sets \n");
	scanf("%d %d",&size1,&size2);
	int a[size1],b[size2];
	printf("Enter elements of first set \n");
	accept(a, size1);
	printf("Enter elements of second set \n");
	accept(b, size2);
	display(a, size1);
	printf("\n");
	display(b, size2);
	do
	{
		int ch;
		printf("\n Enter operation: \n 1.Union \n 2.Intersection \n 3.Difference \n 4.Symmetrical Difference \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
			printf("Union Operation \n");
			union_1(a, b, size1, size2);
			break;
			}
			case 2:
			{
			printf("Intersection Operation \n");
			intersection(a, b, size1, size2);
			break;	
			}
			case 3:
			{
			printf("Difference Operation \n");
			difference(a, b, size1, size2);
			break;
			}
			case 4:
			{
			printf("Symmetrical Difference Operation \n");
			sym_dif(a, b, size1, size2);
			break;
			}
			default: printf("Wrong Choice \n");

		}
		printf("\nAny further operation? Enter 1 for yes 0 for No \n");
		scanf("%d",&ans);
	}while(ans==1);
}
void accept(int a[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
}
void display(int a[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
}
void intersection(int a[], int b[], int size1, int size2)
{
	int i,j,k=0,c[100];
	for(i=0;i<size1;i++)
	{
		for(j=0;j<size2;j++)
		{
			if(a[i]==b[j])
			{
				c[k]=a[i];
				k++;
				break;
			}
		}
	}
	display(c,k);
}
void difference(int a[], int b[], int size1, int size2)
{
	int choice;
	void adiff(int a[], int b[], int size1, int size2);
	printf("Enter your option \n 1:A-B \n 2.B-A \n");	
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: 
		printf("Difference A-B is \n");
		adiff(a,b,size1,size2);
		break;
		case 2:
		printf("Difference B-A is \n");
		adiff(b,a,size2,size1);
		break;		
		default:printf("Enter valid option \n");
	}
}
void adiff(int a[], int b[], int size1, int size2)
{
	int i,j,k,c[100],l=0;
	for(i=0;i<size1;i++)
	{
		k=0;
		for(j=0;j<size2;j++)
		{
			if(a[i]==b[j])
			{			
			k++;
			break;
			}
		}
		if(k==0)
		{
			c[l]=a[i];
			l++;
		}
	}
	display(c,l);
}
void union_1(int a[], int b[], int size1, int size2)
{
	printf("Union is:");		
	display(a,size1);
	adiff(b,a,size2,size1);
}
void sym_dif(int a[], int b[], int size1, int size2)
{
	printf("Symmetric Difference is:");
	adiff(a,b,size1,size2);
	adiff(b,a,size2,size1);
}