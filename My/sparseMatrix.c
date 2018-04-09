#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct
{
	int row;
	int col;
	int val;
}sparse;


void accept(int a[max][max], sparse s1[max],int m,int n);
void display(sparse s1[max]);
void add(sparse s1[max],sparse s2[max],sparse s3[max]);
void fast_transpose(sparse s1[max], sparse st[max]);
void simple_transpose(sparse s1[max], sparse st[max]);

int main()
{

	int a[max][max],b[max][max],c[max][max],m1,n1,m2,n2,ch;
	sparse s1[max];
	sparse s2[max];
	sparse s3[max];
	sparse st[max];
	while(1)
	{
	printf("\n1.Addition\n2.Simple Transpose\n3.Fast Transpose\n4.Exit\n Enter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("enter no size of conventional matrix1");
		scanf("%d %d",&m1,&n1);
		printf("enter the elements of 1st matrix");
		accept(a,s1,m1,n1);
		printf("enter no size of conventional matrix2");
		scanf("%d %d",&m2,&n2);
		printf("enter the elements of 2nd matrix");
		accept(b,s2,m2,n2);
		add(s1,s2,s3);
		display(s3);
		break;

		case 2:
			printf("enter no size of conventional matrix1");
			scanf("%d %d",&m1,&n1);
			printf("enter the elements of 1st matrix");
			accept(a,s1,m1,n1);
			simple_transpose(s1,st);
			break;
		
		case 3:
			printf("enter no size of conventional matrix1");
			scanf("%d %d",&m1,&n1);
			printf("enter the elements of 1st matrix");
			accept(a,s1,m1,n1);
			fast_transpose(s1,st);
			break;
		
		case 4: 
			exit(0);
		}
	}

}

void accept(int a[max][max], sparse s1[max],int m,int n)
{
	int  i, j, k;
	k=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j] !=0 )
			{
				s1[k].row=i;
				s1[k].col=j;
				s1[k].val=a[i][j];
				k++;
			}
		}
	}
	s1[0].row=m;
	s1[0].col=n;
	s1[0].val=k-1;
}

void display( sparse s1[max])
{

	int  i;
	printf("\n Sparse Matrix is:");
	for(i=0;i<s1[0].val+1;i++)
	{
		printf("\n %d\t %d\t %d\t ", s1[i].row,s1[i].col,s1[i].val);


	}
}


void add(sparse s1[max],sparse s2[max],sparse s3[max])
{
	int r,c,i,j,k1,k2,k3,tot1,tot2;
	if(s1[0].row != s2[0].row || s1[0].col != s2[0].col)
	{
		printf("invalid matrix size");
		exit(0);
	}
	tot1=s1[0].val;
	tot2=s2[0].val;
	//set indices for all matrices to 1
	k1=k2=k3=1;
	while(k1<=tot1 && k2<=tot2)
	{
		if(s1[k1].row< s2[k2].row)
		{
			s3[k3].row=s1[k1].row;
			s3[k3].col=s1[k1].col;
			s3[k3].val=s1[k1].val;
			k3++;
			k1++;
		}
		else if(s1[k1].row> s2[k2].row)
		{
			s3[k3].row=s2[k2].row;
			s3[k3].col=s2[k2].col;
			s3[k3].val=s2[k2].val;
			k3++;
			k2++;
		}
		else if(s1[k1].row==s2[k2].row)
		{
			if(s1[k1].col< s2[k2].col)
			{
				s3[k3].row=s1[k1].row;
				s3[k3].col=s1[k1].col;
				s3[k3].val=s1[k1].val;
				k3++;
				k1++;
			}
			else if(s1[k1].col> s2[k2].col)
			{
				s3[k3].row=s2[k2].row;
				s3[k3].col=s2[k2].col;
				s3[k3].val=s2[k2].val;
				k3++;
				k2++;
			}
			else
			{
				s3[k3].row=s2[k2].row;
				s3[k3].col=s2[k2].col;
				s3[k3].val=s1[k1].val+s2[k2].val;
				k1++;
				k2++;
				k3++;
			}
		}
	}
	while(k1<=tot1)
	{
		s3[k3].row=s1[k1].row;
		s3[k3].col=s1[k1].col;
		s3[k3].val=s1[k1].val;
		k3++;
		k1++;
	}
	while(k2<=tot1)
	{
		s3[k3].row=s2[k2].row;
		s3[k3].col=s2[k2].col;
		s3[k3].val=s2[k2].val;
		k3++;
		k2++;
	}
	s3[0].row=s1[0].row;
	s3[0].col=s1[0].col;
	s3[0].val=k3-1;
}

void fast_transpose(sparse s1[max], sparse st[max])
{
	int t,i,loc,j,m;
	int total[max],index[max];
	
	t=s1[0].val;
	st[0].row=s1[0].col;
	st[0].col=s1[0].row;
	st[0].val=s1[0].val;
	
	for(i=0;i<s1[0].col;i++)
	total[i]=0;
	
	for(i=0;i<=t;i++)
	{
	  j=s1[i].col;
	  total[j]=total[j]+1;
	}
	
	index[0]=1;
	for(i=1;i<s1[0].col;i++)
	index[i]=index[i-1]+total[i-1];
	
	for(i=1;i<=t;i++)
	{
		j=s1[i].col;
		loc=index[j];
		index[j]++;
		st[loc].row=s1[i].col;
		st[loc].col=s1[i].row;
		st[loc].val=s1[i].val;
	}
	printf("Elements after Transpose are\n");
	for(m=0;m<=t;m++)
	{
		printf("%d \t %d \t %d \n",st[m].row,st[m].col,st[m].val);
	}
}

void simple_transpose(sparse s1[max], sparse st[max])
{
 	int i,j,k,m;
 	st[0].row=s1[0].col;
  	st[0].col=s1[0].row;
  	st[0].val=s1[0].val;
   	k=1;
   	for(i=0;i<s1[0].col;i++)
   	{
   		for(j=1;j<=s1[0].val;j++)
   		{
			if(s1[j].col==i)
			{
				st[k].row=s1[j].col;
				st[k].col=s1[j].row;
				st[k].val=s1[j].val;
				k++;
			}
		}
	}
	k--;
	for(m=0;m<=k;m++)
	{
		printf("%d \t %d \t %d \n",st[m].row,st[m].col,st[m].val);
	}
}

