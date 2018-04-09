#include<stdio.h>
#include<stdlib.h>
	typedef struct GLL_node
	{
		int header_data_node;
		char data;
		struct GLL_node *down;
		struct GLL_node *right;
	}GLL_node;

	void print_GLL(GLL_node *start);
	GLL_node * insert( char []) ;
	void main()
	{
		GLL_node *start=NULL;
		char index[50];
		printf("\nenter book index to create GLL\n");
		scanf("%s",index);//create GLL
		start=insert(index);
		printf("\nbook index is:\n");
		print_GLL(start);
	}
	void print_GLL(GLL_node *start)
	{
		if(start==NULL)
		{
			return;
		}
		else
		{
			if(start->header_data_node==1)
			{
				printf("(\t|");
				print_GLL(start->down);
				printf("|\t)");
				print_GLL(start->right);
			}
			else if(start->header_data_node ==0)
			{
				printf("%c",start->data)
				
				printf("->");
				print_GLL(start->right);
		}}
	}
	GLL_node * insert( char index[])
	{
		static int i=0;
		GLL_node *temp = NULL;
		if(index[i]=='\0')
		return NULL;
		for(;index[i]==',' || index[i]==' ';i++);
		temp =(GLL_node*)malloc(sizeof(GLL_node));
		temp->down=NULL;
		temp->right=NULL;
		if(index[i]=='(')
		{
			temp->header_data_node=1;
			i++;
			temp->down=insert(index);
			if(index[i]!='\0')
			temp->right=insert(index);
			else
			i=0;
		}
		else if(isalpha(index[i]))
		{
			temp->header_data_node=0;
			temp->data=index[i++];
			temp->right=insert(index);
		}
		else if(index[i]==')')
		{
			i++;
			free(temp);
			return NULL;
		}
		return temp;
	}
