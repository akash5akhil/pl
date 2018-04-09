#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int binsearch(char a[10][10], char key[10], int start, int end);
int binary2(char a[10][10], char key[10], int beg, int end);
main()
{
	char a[10][10]; char key[10];
	int i,n,ch,flag;
	printf("Enter number of strings \n");
	scanf("%d", &n);
	printf("Enter keystring \n");
	scanf("%s", key);
	printf("Enter the strings \n");
	for(i=0;i<n;i++)
	{
		scanf("%s", a[i]);
	}
	while(1)
	{
		printf("\n 1.Binary Search without Recursion \n 2.Binary Search with Recusrsion \n 3.Exit \n");
		printf("Enter your choice \n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			flag=binsearch(a,key,0,n-1);
			if(flag==-1)
			printf("String not present \n");
			else
			printf("String is present at location %d", flag+1);
			break;
			case 2:
			flag=binsearch(a,key,0,n-1);
			if(flag==-1)
			printf("String not present \n");
			else
			printf("String is present at location %d \n", flag+1);
			break;
			case 3:
			exit(1);
			default:printf("Wrong Choice \n");
		}
	}
}
int binsearch(char a[10][10], char key[10], int start, int end)
{
	int mid;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(strcmp(a[mid],key)<0)
		start=mid+1;
		else if(strcmp(a[mid],key)>0)
		end=mid-1;
		else
		return mid;
	}
	if(start>end)
	return -1;
}
int binary2(char a[10][10], char key[10], int beg, int end)
{
	int mid;
	if(beg>end)
	return -1;
	mid=(beg+end)/2;
	if(strcmp(a[mid],key)==0)
	return mid;
	else if(strcmp(a[mid],key)<0)
	binary2(a,key,mid+1,end);
	else
	binary2(a,key,beg,mid-1);
}
