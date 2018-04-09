
#include<stdio.h>
int a[100],b[100],c[100];
void getdata(int n,int a[100]);
void display(int a[100],int n);
void sort(int a[100],int n);
void un(int a[],int b[],int n1,int n2);
void intersection(int a[],int b[],int n1,int n2);
void s1(int a[],int b[],int n1,int n2);
void s2(int a[],int b[],int n1,int n2);

int main()
{
	int ch,n1,n2;
	char r;
	printf("Enter Size of Set A::\n");
	scanf("%d",&n1);
	getdata(n1,a);
	printf("\nThe element in the set 1");
	display(a,n1);
	printf("\nEnter Size of Set B::");
	scanf("%d",&n2);
	getdata(n2,b);
	printf("\nThe element in the set 2");
	display(b,n2);
	sort(a,n1);
	sort(b,n2);
	do
	{
	printf("\n1.union\n2.Intersection\n3.Difference\n4.symmetric Differnece\n5.Exit");
	printf("\nEnter the choice \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			un(a,b,n1,n2);
			break;
		}
		case 2:
		{
			intersection(a,b,n1,n2);
			break;
		}
		case 3:
		{ 
			printf("\nThe difference A-B is\n");
			s1(a,b,n1,n2);
			printf("\nThe difference B-A is\n");
			s1(b,a,n2,n1);
			break;
		}
		case 4:
		{
			printf("\nThe symmetric diffence of A and B is\n");
			printf("{");	
			s2(a,b,n1,n2);
			s2(b,a,n2,n1);
			printf("}");
			break;
		}
		
	}

	}while(ch!=5);
	return 0;
}
void getdata(int n,int a[100])
{
	int i;
	printf("\nEnter the element in the set\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void display(int a[100],int n)
{
	int i;
	printf("{");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		printf(",");
	}
	printf("}");
}
void sort(int a[100],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("\nThe sorted set is");
	printf("{");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		printf(",");
	}
	printf("}");
}
void un(int a[],int b[],int n1,int n2)
{
	int i=0,j=0,k=0;
	while((i<n1)&&(j<n2))
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else if(a[i]>b[j])
		{	
			c[k]=b[j];
		 	j++;
			k++;	
		}
		else
		{
			c[k]=a[i];
			i++;
			j++;
			k++;	
		}
	}	
	if(i==n1)
	{
		while(j<n2)	
		{
			c[k]=b[j];
			j++;
			k++;	
		}	
	}
	else
	{
		while(i<n1)	
		{
			c[k]=b[i];
			i++;
			k++;	
		}	
	}
	printf("\nThe union of the set=");
	printf("{");
	for(i=0;i<k;i++)
	{
		printf("%d",c[i]);	
		printf(",");
	}
	printf("}");
}

void intersection(int a[],int b[],int n1,int n2)
{
	int i=0,j=0,k=0;
	while((i<n1)&&(j<n2))
	{
		if(a[i]<b[j])
		{
			i++;
		}
		else if(a[i]>b[j])
		{
 			j++;
		}
		else
 		{
			c[k]=a[i];
			i++;
			j++;
			k++;	
		}
	}	
	printf("\nThe intersection of the set=");
	printf("{");
	for(i=0;i<k;i++)
	{
	printf("%d",c[i]);
	printf(",");
	}
	printf("}");
	display(c,k);
}

void s1(int a[],int b[],int n1,int n2)
{
	int i,j,k=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(a[i]==b[j])
			{
				break;	
			}
		}
		if(j==n2)
		{
			c[k]=a[i];
			k++;		
		}
	}
	display(c,k);		
}

void s2(int a[],int b[],int n1,int n2)
{
	int i,j,k=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(a[i]==b[j])
			{
				break;	
			}
		}
		if(j==n2)
		{
			c[k]=a[i];
			k++;		
		}
	}
	for(i=0;i<k;i++)
	{ 		
		printf("%d",c[i]);
		printf(",");
	}	
}
