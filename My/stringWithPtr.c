//string opertion with pointer
#include<stdio.h>
int length(char s[100]);
void pali(char s[100],int l);
void comp(char s1[100],char s2[100],int l1,int l2);
void copy(char s1[100],char s2[100],int l1,int l2);
void reverse(char s[100],int l);
void sub(char c[10],int l);
void main()
{	
	int ch,l1,l2,x,y,z;
	char s1[10],s2[10];
	char *ptr1,*ptr2;
	printf("Enter the first string\n");
	scanf("%s",s1);
	printf("Enter the second string\n");
	scanf("%s",s2);	
	ptr1=s1;
	ptr2=s2;	
	printf("\nThe first string is %s",ptr1);
	printf("\nThe first string is %s \n",ptr2);
	do
	{
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
			l1=length(ptr1);
			printf("The length of the First string is %d\n",l1);
			l2=length(ptr2);
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
						pali(ptr1,l1);
						break;
					}
					case 2:
					{
						pali(ptr2,l2);
						break;
					}
				}
			printf("If you want to continue to main menu press 3\n");
			}while(x!=3);

			continue;	
	}
	case 3:
	{
		comp(ptr1,ptr2,l1,l2);
	break;	
	}
	case 4:
	{
		copy(ptr1,ptr2,l1,l2);
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
				reverse(ptr1,l1);
			     break;
			    }
			    case 2:
			    {
				reverse(ptr2,l2);
			    break;
			    }

						}
				printf("If you want to continue to main menu press 3\n");
						}while(y!=3);

			break;
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
			sub(ptr1,l1);
			break;
		}
		case 2:
		{
			sub(ptr2,l2);	
			break;
		 }
		printf("If you want to continue to main menu press 3\n");
	}			
	}while(z!=3);
	break;
	}
	}
}while(ch!=7);
}

int length(char s[10])
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
		*(n+p)=*(s+i);
		p++;
	}
	*(n+p+1)='\0';
	for(i=0;i<l;i++)
	{
		if(*(n+i)==*(s+i))
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
			if(*(s1+i)==*(s2+i))
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
	char c1[100],c2[100];
	l1>l2?(b=l1):(b=l2);
	for(i=0;i<l1;i++)
		{
		*(c1+i)=*(s1+i);		
		}
		for(i=0;i<l2;i++)
		{
		*(c2+i)=*(s2+i);	
		}
	for(i=0;i<b;i++)
	{
	 temp=*(c1+i);
	 *(c1+i)=*(c2+i);
	 *(c2+i)=temp;
	}
	*(c1+l2)='\0';
	*(c2+l1)='\0';
	printf("After the copy\n");
	printf("The first string is--");
	printf("%s\n ",c1);
	printf("The second string is--");
	printf("%s\n ",c2);
}

void reverse(char s[100],int l)
{
	int i,p=0;
	char n[100];
		for(i=(l-1);i>=0;i--)
		{
			*(n+p)=*(s+i);
			p++;
		}
		*(n+p)='\0';
	printf("The reverse string is:-%s\n",n);
}

void sub(char c[10],int l)
{
	int s,e,i,p=0;
	char n[10];
	printf("Enter the start and end for the substring\n");
	scanf("%d %d",&s,&e);
	for(i=(s-1);i<=(e-1);i++)
	{
		*(n+p)=*(c+i);
		p++;
	}
	*(n+p+1)='\0';
	printf("Substring is %s",n);
}
