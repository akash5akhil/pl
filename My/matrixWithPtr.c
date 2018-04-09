#include<stdio.h>
#include<stdlib.h>
int **d(int row ,int col);
void accept(int **a,int r,int c);
void display(int **a,int r,int c);
void add(int **a,int **b,int r,int c);
void mul(int **a,int** b,int r1,int r2,int c1,int c2);
void transpose(int **a,int r1,int c1);
int **d(int row ,int col)
{
	int i;
	int **a;
	a=(int **)malloc(row*sizeof(int *));
	for(i=0;i<row;i++)
	{
		a[i]=(int *)malloc(col*sizeof(int));
	}
	return a;
}
int *a1(int row)
{
	int *a;
	a=(int *)malloc(row*sizeof(int));
	return a;
}

int main()
{
	int **a,**b,r1,r2,c1,c2,ch,x,y;
	printf("\nEnter the no of row of A::");
	scanf("%d",&r1);
	printf("\nEnter the no of col of A::");
	scanf("%d",&c1);
	a=d(r1,c1);
	printf("%d",sizeof(a));
	printf("\nEnter the no of row of B::");
	scanf("%d",&r2);
	printf("\nEnter the no of col of B::");
	scanf("%d",&c2);
	b=d(r2,c2);
	do
	{
	printf("\n1.Accept the element");
	printf("\n2.Display the element");
	printf("\n3.ADDTION  of the matrix");
	printf("\n4.MULTIPICATION of the matrix");
	printf("\n5.TRANSPOSE of the matrix");
	printf("\n6.Saddle point");
	printf("\nEnter the choice::");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			printf("Enter the element of matrix A\n");
			accept(a,r1,c1);
			printf("Enter the element of matrix B\n");
			accept(b,r2,c2);
			break;
		}
		case 2:
		{
			printf("The element of matrix A\n");
			display(a,r1,c1);
			printf("The element of matrix B\n");
			display(b,r2,c2);
			break;
		}
		case 3:
		{
			if(r1==r2&&c1==c2)
			{
				add(a,b,r1,c1);
			}
			else
			{
				printf("ADDTION IS NOT POSIBALE");
			}
			break;
		}
		case 4:
		{		
				if(c1==r2)
				{
					mul(a,b,r1,r2,c1,c2);
				}
				else
				{
					printf("MULATIPLICATION IS NOT POSIBALE");
				}
				break;
		}
		case 5:
		{
			do
			{
				printf("1.Transpose of the matrix A\n");
				printf("2.Transpose of the matrix B\n");
				printf("Enter the choice");
				scanf("%d",&x);
				switch(x)
				{
					case 1:
					{
						transpose(a,r1,c1);
						break;
					}
					case 2:
					{
						transpose(b,r2,c2);
						break;
					}
				}
			}while(x!=2);
			continue;
		}
		case 6:
		{			
			do
			{
				printf("1.Saddle of the matrix A\n");
				printf("2.Saddle of the matrix B\n");
				printf("\nEnter the choice");
				scanf("%d",&y);
				switch(y)
				{
					case 1:
					{
						s(a,r1,c1);
						break;
					}
					case 2:
					{
						s(b,r2,c2);
						break;
					}
				}
			}while(y!=3);
			continue;
		}
	}
}while(ch!=7);
return 0;
}

void accept(int **a,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",(*(a+i)+j));
			printf("\t");
		}
		printf("\n");
	}
}

void display(int **a,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d",*(*(a+i)+j));
			printf("\t");
		}
		printf("\n");
	}
}

void add(int **a,int **b,int r,int c)
{
	int i,j;
	int**s;
	s=d(r,c);
	printf("The ADDTION of the matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			(*(*(s+i)+j))=(*(*(a+i)+j))+(*(*(b+i)+j));
			printf("%d",*(*(s+i)+j));
			printf("\t");
		}
		printf("\n");
	}

}


void mul(int **a,int** b,int r1,int r2,int c1,int c2)
{
	int i,j,k;
	int**s;
	s=d(r1,c2);
	printf("The MULATIPLICATION of the matrix\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			for(k=0;k<r2;k++)
			{
				(*(*(s+i)+j))=(*(*(s+i)+j))+((*(*(a+i)+j))*(*(*(b+i)+j)));
			}
			printf("%d",*(*(s+i)+j));
			printf("\t");
		}
	printf("\n");
	}
}

void transpose(int **a,int r1,int c1)
{
	int i,j;
	int**s;
	s=d(r1,c1);
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			(*(*(s+i)+j))=(*(*(a+i)+j));
			printf("%d",*(*(s+i)+j));
			printf("\t");
		}
		printf("\n");
	}
}

void s(int **a,int r1, int c1)
{
	int i,j,**s;
	s=d(r1,c1);
	int max,min,min1,max1;
	int *c,*d;
	c=a1(r1);
	d=a1(r1);
	for(i=0;i<r1;i++)
	{
		min=(*(*(a+i)+0));
		for(j=1;j<c1;j++)
		{
			if(min>(*(*(a+i)+j)))
			{
				min=(*(*(a+i)+j));
			}
		}
		*(c+i)=min;
	}
	for(j=0;j<c1;j++)
	{
		max=(*(*(a+0)+j));
		for(i=1;i<r1;i++)
		{
			if(max<(*(*(a+i)+j)))
			{
				max=(*(*(a+i)+j));
			}
		}
		*(d+j)=max;
	}
	max1=*(c+0);
	for(i=1;i<r1;i++)
	{
		if(max1<*(c+i))
		{
			max1=*(c+i);
		}
	}

	min1=*(d+0);
	for(i=1;i<c1;i++)
	{
		if(min1>*(d+i))
		{
			min1=*(d+i);
		}
	}
	if(min1==max1)
	{
		printf("\n saddle point is %d",max1);
	}

}

