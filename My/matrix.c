#include<stdio.h>
#define MAX 5
void accept(int a[MAX][MAX],int r,int c);
void display(int a[MAX][MAX],int r,int c);
void add(int a[MAX][MAX],int b[MAX][MAX],int r,int c);
void mul(int a[MAX][MAX],int b[MAX][MAX],int r1,int r2,int c1,int c2);
void transpose(int a[MAX][MAX],int r1,int c1);
void saddlepnt(int a[MAX][MAX],int r1, int c1);

void main()
{
	int a[MAX][MAX],ch,b[MAX][MAX],r1,r2,c1,c2,x,y;
	printf("Enter the no of row of A");
	scanf("%d",&r1);
	printf("Enter the no of col of A");
	scanf("%d",&c1);
	printf("Enter the no of row of B");
	scanf("%d",&r2);
	printf("Enter the no of col of B");
	scanf("%d",&c2);
	do
	{
	printf("1.Accept the element\n");
	printf("2.Display the element\n");
	printf("3.ADDTION  of the matrix\n");
	printf("4.MULTIPICATION of the matrix\n");
	printf("5.TRANSPOSE of the matrix");
	printf("6.Saddle point\n");
	printf("Enter the choice");
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
			break;
		}
		case 6:
		{	
			do
			{
				printf("1.Saddle of the matrix A\n");
				printf("2.Saddle of the matrix B\n");
				printf("Enter the choice");
				scanf("%d",&y);
				switch(y)
				{
					case 1:
					{
						saddlepnt(a,r1,c1);
						break;
					}
					case 2:
					{
						saddlepnt(b,r2,c2);
						break;
					}
				}while(y!=2);
				break;
			}

		}
	}
	}while(ch!=7);
}


void accept(int a[MAX][MAX],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}

void display(int a[MAX][MAX],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d",a[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}

void add(int a[MAX][MAX],int b[MAX][MAX],int r,int c)
{
	int i,j;
	printf("The ADDTION of the matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d",a[i][j]+b[i][j]);
			printf("\t");
		}
		printf("\n");
	}

}

void mul(int a[MAX][MAX],int b[MAX][MAX],int r1,int r2,int c1,int c2)
{
	int i,j,k,c[MAX][MAX];
	printf("The MULATIPLICATION of the matrix\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			for(k=0;k<r2;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d",c[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}

void transpose(int a[MAX][MAX],int r1,int c1)
{
	int i,j;
	int c[MAX][MAX];
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			c[i][j]=a[j][i];
			printf("\t");
		}
		printf("\n");
	}
	for(i=0;i<c1;i++)
	{
		for(j=0;j<r1;j++)
		{
			printf("%d",c[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}


void s(int a[MAX][MAX],int r1, int c1)
{
	int i,j,c[MAX],d[MAX];
	int max,min,min1,max1;

	for(i=0;i<r1;i++)     //  minimum in row
	{
		min=a[i][0];
		for(j=1;j<c1;j++)
		{
			if(min>a[i][j])
			{
				min=a[i][j];
			}
		}
		c[i]=min;
	}
	for(j=0;j<c1;j++)
	{
		max=a[0][j];
		for(i=1;i<r1;i++)
		{
			if(max<a[i][j])
			{
				max=a[i][j];
			}
		}
		d[j]=max;
	}
	max1=c[0];
	for(i=1;i<r1;i++)
	{
		if(max1<c[i])
		{
			max1=c[i];
		}
	}

	min1=d[0];
	for(i=1;i<c1;i++)
	{
		if(min1>d[i])
		{
			min1=d[i];
		}
	}
	if(min1==max1)
	{
		printf("saddle point is %d",max1);
	}
}
}

