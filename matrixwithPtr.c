#include<stdio.h>
#include<stdlib.h>
void accept(int a[100][100], int row, int col);
void display(int a[100][100], int row, int col);
void add(int a[100][100], int b[100][100], int row, int col);
void mult(int a[100][100], int b[100][100], int row1, int col1, int col2);
void transpose(int a[100][100], int row, int col);
void saddle(int a[100][100], int row, int col);
void main()
{
	int row1,row2,col1,col2,a[100][100],b[100][100];
	int ch; int ans;
	do
	{
		printf("1.Accept \n 2.Display \n 3.Addition \n 4.Multiplication \n 5.Transpose \n 6.Saddle Point \n 7.Exit \n Enter your choice: \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter row and column of Matrix A \n");
			scanf("%d %d",&row1,&col1);
			printf("Enter elements of Matrix A \n");
			accept(a,row1,col1);
			printf("Enter row and column of Matrix B \n");
			scanf("%d %d",&row2,&col2);
			printf("Enter elements of Matrix B \n");
			accept(b,row2,col2); 
			break;
			case 2:
			printf("Elements of Matrix A are: \n");
			display(a,row1,col1);
			printf("Elements of Matrix B are:\n");
			display(b,row2,col2);
			break;
			case 3:
			if(row1==row2 && col1==col2)
			add(a,b,row1,col1);
			else
			printf("Addition is not possible \n");
			break;
			case 4:
			if(col1==row2)
			mult(a,b,row1,col1,col2);
			else
			printf("Multiplication is not possible \n");
			break;
			case 5:
			transpose(a,row1,col1);
			break;
			case 6:
			saddle(a,row1,col1);
			break;
			case 7:
			exit(0);
			default:printf("Wrong Choice \n");
		}
	}
	while(ch!=0);
}
void accept(int a[100][100], int row, int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void display(int a[100][100], int row, int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void add(int a[100][100], int b[100][100], int row, int col)
{
	int i,j;
	int c[100][100];//c[row][col]
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	display(c,row,col);
}
void mult(int a[100][100], int b[100][100], int row1, int col1, int col2)
{
	int i,j,k;
	int c[100][100];//row[row1][col2]
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			c[i][j]=0;
			for(k=0;k<col1;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	display(c,row1,col2);
}
void transpose(int a[100][100], int row, int col)
{
	int i,j;
	int b[100][100];//b[col][row]
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			b[j][i]=a[i][j];
		}
	}
	printf("Transpose of Matrix A is: \n");
	display(b,col,row);
}
void saddle(int a[100][100], int row, int col)
{
	int b[row], c[col];
	int i,j,x,y;
	for(i=0;i<row;i++)
	{
		b[i]=a[i][0];
		for(j=0;j<col;j++)
		{
			if(a[i][j]<b[i])
			b[i]=a[i][j];
		}
	}
	for(i=0;i<col;i++)
	{
		c[i]=a[0][i];
		for(j=0;j<row;j++)
		{
			if(a[j][i]>c[i])
			c[i]=a[j][i];
		}
	}
	x=b[0];
	for(i=0;i<row;i++)
	{
		if(b[i]>x)
		x=b[i];
	}
	y=c[0];
	for(i=0;i<col;i++)
	{
		if(c[i]<y)
		y=c[i];
	}
	if(x==y)
	printf("Saddle point of Matrix A is:%d \n",x);	
	else
	printf("There is no saddle point \n");
}
