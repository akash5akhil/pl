#include<stdio.h>
#include<stdlib.h>
void accept(char str[20]);
int scomp(char str1[20], char str2[20]);
int slen(char str[20]);
void scopy(char str1[20],char str2[20]);
void rev(char str[20]);
void palindrome(char str[20]);
void substring(char str1[20], char str2[20]);
void main()
{
	char str1[20],str2[20];
	int len, comp,ch,ans;
	do
	{
	printf("Enter your choice: \n 1.Length \n 2.Comparison \n 3.Copy \n 4.Reverse \n 5.Palindrome \n 6.Substring \n 7.Exit \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("Enter a string \n");
		accept(str1);
		len=slen(str1);
		printf("Length of string is:%d \n",len);
		break;
		case 2:
		printf("Enter 2 strings \n");
		accept(str1);
		accept(str2);
		comp=scomp(str1,str2);
		if(comp<0)
		printf("String 1 is less than String 2 \n");
		else if(comp>0)
		printf("String 2 is less than String 1 \n");		
		else
		printf("Strings are identical \n");
		break;
		case 3:
		printf("Enter 2 strings \n");
		accept(str1);
		accept(str2);
		scopy(str1,str2);
		printf("First:%s \n",str1);
		printf("Second String:%s \n",str2);	
		break;
		case 4:
		printf("Enter a string \n");
		accept(str1);
		rev(str1);
		printf("Reversed String:%s \n",str1);
		break;
		case 5:
		printf("Enter a string \n");
		accept(str1);
		palindrome(str1);
		break;
		case 6:
		printf("Enter 2 strings \n");
		accept(str1);
		accept(str2);
		substring(str1,str2);
		break;
		case 7:
		exit(0);
		default:printf("Wrong choice \n");
	}
	printf("More..? Enter '1' for Yes and '0' for No \n");
	scanf("%d",&ans);
	}while(ans==1);
}
void accept(char x[])
{
	scanf("%s",x);
}
int slen(char x[])
{
	int i=0;
	while(x[i]!='\0')
	i++;
	return i;
}
void scopy(char x[], char y[])
{
	int i=0;
	while(y[i]!='\0')
	{
		x[i]=y[i];
		i++;
	}
	x[i]='\0';
}
void rev(char x[])
{
	int len; char temp;
	len=slen(x);
	int i=0,j=len-1;
	while(i<=j)
	{
		temp=x[i];
		x[i]=x[j];
		x[j]=temp;
		i++;
		j--;
	}
}
int scomp(char x[], char y[])
{
	int i,k=0;
	for(i=0;x[i]!='\0' || y[i]!='\0';i++)	
	{
		if(x[i]==y[i])
		continue;
		if(x[i]<y[i])
		k--;
		else		
		k++;
		break;
	}
	return k;
}
void palindrome(char x[])
{
	int comp;	
	char y[20];
	scopy(y,x);
	rev(x);
	comp=scomp(x,y);
	if(comp==0)
	printf("String is Palindrome \n");
	else
	printf("String is not Palindrome \n");
}	
void substring(char x[], char y[])
{
	int i=0,j=0,k=0;
	while(x[k]!='\0' && y[j]!='\0')
	{
		i=k;
		j=0;
		while(x[i]!='\0' && y[j]!='\0')
		{
			if(x[i]!=y[j])
			break;
			i++;
			j++;
		}
		k++;
	}
	if(y[j]=='\0')
	printf("Substring is present in main string \n");
	else
	printf("Substring is not present in main string \n");  }
