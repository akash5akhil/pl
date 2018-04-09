#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
	{
		int id;		
		char name[25];
		int salary;
		char dept[25];		
	}emp;

int main()
{
	FILE *fp,*ft;
	char another;
	int choice,id;
	

	emp e;
	long int recsize;

	fp=fopen("EMP.DAT","rb+");
	
	if(fp==NULL)
	{		
		fp=fopen("EMP.DAT","wb+");
		if(fp==NULL)
		{
			puts("can not open file");
			exit(1);
		}
	}	
	recsize=sizeof(e);

	while(1)
	{	
		printf("\n1.Add records\n2.Display Records\n3.Modify Records\nDelete Records\nExit");
		printf("Enter your choice");
		scanf("%d",&choice);	

		switch(choice)
		{
		case 1:

		//insert record at end

			fseek(fp,0,SEEK_END);
			another='Y';
			while(another=='Y')
			{
				printf("Enter id name,Department and Salary");
				scanf("%d %s %s %d",&e.id,e.name,e.dept,&e.salary);
				fwrite(&e,recsize,1,fp);
				printf("add another record(Y/N)");
				fflush(stdin);
				scanf(" %c",&another);				
			}	
			break;
		case 2:
			rewind(fp);
			while(fread(&e,recsize,1,fp)==1)
			{
				printf("%d %s %s %d",e.id,e.name,e.dept,e.salary);
				printf("\n");
			}
				
			break;
		case  3:
			another='Y';
			while(another == 'Y')
			{
				printf("enter id  of eloyee to modify");
				scanf("%d",&id);
				rewind(fp);
				while(fread(&e,recsize,1,fp)==1)
				{
					if(id==e.id)
					{
						printf("enter name,department and salary");
						scanf("%s %s %d",e.name,e.dept,&e.salary);
						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&e,recsize,1,fp);
						break;
					}
				}
				printf("modify another record (Y/N)?");
				fflush(stdin);
				scanf(" %c",&another);
			}
			break;
		case 4:
			another='Y';
			while(another=='Y')
			{
				printf("\nEnter id of employee to delete");
				scanf("%d",&id);
				ft=fopen("TEMP.DAT","wb");
				rewind(fp);
				while(fread(&e,recsize,1,fp)==1)
				{
					if(id != e.id)
						fwrite(&e,recsize,1,ft);
				}
				fclose(fp);
				fclose(ft);
				remove("EMP.DAT");
				rename("TEMP.DAT","EMP.DAT");
				fp=fopen("EMP.DAT","rb+");
				printf("Delete another record (Y/N)" );
				fflush(stdin);
				scanf(" %c",&another);
			}
			break;
		case 0:
			fclose(fp);
			exit(0);		
		}
}
return 0;	
}

