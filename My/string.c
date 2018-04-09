#include<stdio.h>
int length(char s[100]);
void pali(char s[100],int l);
void comp(char s1[100],char s2[100],int l1,int l2);
void copy(char s1[100],char s2[100],int l1,int l2);
void reverse(char s[100],int l);
void sub(char c[100],int l);
int main()
{
	char s1[100],s2[100];
	int ch,l1,l2,x,y,z;
	printf("Enter the First string\n");
	scanf("%s",s1);
	printf("Enter the Second string\n");
	scanf("%s",s2);
	printf("The First string is %s\n",s1);
	printf("The Second string is %s\n",s2);
	do
	{
	printf("MENU For String Operations");
	printf("\n1.Length of the string");
	printf("\n2.Palindrome of the string");
	printf("\n3.Comparision of the string");
	printf("\n4.Copy of the string");
	printf("\n5.Reverse of the string");
	printf("\n6.Substring of the string");
	printf("\nEnter the choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			l1=length(s1);
			printf("The length of the First string is %d\n",l1);
			l2=length(s2);
			printf("The length of the Second string is %d\n",l2);
			break;
		}
		case 2:
		{
			do
			{
				printf("1.Check for 1st string\n");
				printf("2.Check for 2nd string\n");
				printf("Enter the choice");
				scanf("%d",&x);
				switch(x)
				{
					case 1:
					{	
						pali(s1,l1);
						break;
					}
					case 2:
					{
						pali(s2,l2);
						break;
					}
				}
				printf("If you want to continue to main menu press 3\n");
			}while(x!=3);
			continue;
		}
		case 3:
		{
			comp(s1,s2,l1,l2);
			break;
		}
		case 4:
		{
			copy(s1,s2,l1,l2);
			break;
		}
		case 5:
		{
			do
			{
				printf("1.Check for 1st string\n");
				printf("2.Check for 2nd string\n");
				printf("Enter the choice");
				scanf("%d",&y);
				switch(y)
				{
					case 1:
					{
						reverse(s1,l1);
						break;
					 }
					 case 2:
					 {
						reverse(s2,l2);
						break;
					 }
				}
				printf("If you want to continue to main menu press 3\n");
			}while(y!=3);
			break;
		}
		case 6:
		{
			do
			{
				printf("1.Check for 1st string\n");
				printf("2.Check for 2nd string\n");
				printf("Enter the choice\n");
				scanf("%d",&z);
				switch(z)
				{
				case 1:
				{
					sub(s1,l1);
					break;
				}
				case 2:
				{
					sub(s2,l2);
					break;
				}
			}
			printf("If you want to continue to main menu press 3\n");
			}while(z!=3);
			break;
		}
	}
	}while(ch!=7);
	return 0;
}

int length(char s[100])
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}
void pali(char s[100],int l)
{
	int i,p=0,count=0;
	char n[100];
	for(i=(l-1);i>=0;i--)
	{
		n[p]=s[i];
		p++;
	}
	n[p+1]='\0';
	for(i=0;i<l;i++)
	{
		if(n[i]==s[i])
		{
			count++;
		}
	}
	if(count==l)
	{
		printf("The string is Palindrome\n");
	}
	else
	{
		printf("The string is not Palindrome\n");
	}
}
void comp(char s1[100],char s2[100],int l1,int l2)
{
		int i,count=0;

	if(l1==l2)
	{
		for(i=0;i<l1;i++)
		{
			if(s1[i]==s2[i])
			{
				count++;
			}
		}
	}
	if(count==l1)
	{
		printf("The string are equal\n");
	}
	else
	{
		printf("The string are not equal\n");
	}
}
void copy(char s1[100],char s2[100],int l1,int l2)
{
	char temp;
	int i,b;
	l1>l2?(b=l1):(b=l2);
	for(i=0;i<b;i++)
	{
	 temp=s1[i];
	 s1[i]=s2[i];
	 s2[i]=temp;
	}
	s1[l2]='\0';
	s2[l1]='\0';
	printf("After the copy\n");
	printf("The first string is--");
	printf("%s\n ",s1);
	printf("The second string is--");
	printf("%s\n ",s2);
}
void reverse(char s[100],int l)
{
	int i,p=0;
	char n[100];
		for(i=(l-1);i>=0;i--)
		{
			n[p]=s[i];
			p++;
		}
		n[p]='\0';
	printf("The reverse string is:-%s\n",n);
}
void sub(char c[100],int l)
{
	int s,e,i,p=0;
	char n[100];
	printf("Enter the start and end for the substring\n");
	scanf("%d %d",&s,&e);
	for(i=(s-1);i<=(e-1);i++)
	{
		n[p]=c[i];
		p++;
	}
	n[p+1]='\0';
	printf("Substring is %s",n);
}

