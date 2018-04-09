/* This program is created and maintained by Vidya S. Kurtadikar . Last accessed and modified on 8/8/2016*/
//This program is designed with an aim to teach students array of structures and different operations on array such as insert/delete 
//In insert we are assuming as we are creating arrays while insertion and insertion is done in append mode
//in delete mode we are shifting records to left side to permanently delete record

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct emp_data    // empucture defination
{
	int e_id;
	char Name[30];
	int salary ;
}employee;        // End of empucure


// Function Declaration

void Insert_Rec(employee emp[MAX],int iNo);
int Search_Rec(employee emp[MAX],int id);
void Display_Rec(employee emp[MAX]);
void Modify_Rec(employee emp[MAX]);
void Delete_Rec(employee emp[MAX]);

int iCount = 0;   // Global variable declaration

// Start of program

main()
{
	int opt , iNo,id,pos;  // Local variable declaration
	employee emp[MAX];

	for(;;)     // Infinite for loop
	{    			// Menu
		printf("\n 1. Insert a record ");
		printf("\n 2. To search a record ");
		printf("\n 3. To display records ");
		printf("\n 4. To modify a record ");
		printf("\n 5. To delete a  record ");
		printf("\n 6. exit");
		printf("\n Enter ur choice : ");
		scanf("%d" , &opt);  // users choie
		switch(opt)
		{
			case 1:
				printf("\n How many record do u wish to enter");
				scanf("%d" , &iNo); // to enter number of records
				Insert_Rec(emp,iNo);    //calling insert function
				break;
			case 2:
				printf("\n Enter a employee id ");
				scanf("%d" , &id );  // Record to be searched
				pos = Search_Rec(emp,id);   //Calling function
				if(pos != -1)
				{
					printf("\n Record exists");

					printf("\n\tId\tName\tSalary");
					printf("\n\t%d\t%s\t%d",emp[pos].e_id,emp[pos].Name,emp[pos].salary);
				}
				else
					printf("\n Record does not exist");
				break;
			case 3:
				Display_Rec(emp); //Calling function
				break;
			case 4:
				Modify_Rec(emp);     //Calling function
				break;
			case 5:
				Delete_Rec(emp);      //Calling function
				break;
			case 6:
				exit(0);           //End of menu
				break;
			default :
				printf("Enter valid option ");
		}
	} // end of for
}   //end of main


/* to insert a record in database . We are inserting at end. Append operation*/

void Insert_Rec(employee emp[MAX],int iNo)
{
	int id ,j, i,k,flag = 0,pos,datafull=0;
	
	for(j = 0 ; j < iNo ; j++)//To enter no of records user wish ot enter
	{
		if(1+iCount>MAX)
		{	datafull=1;
			break;
		}
		printf("\n Enter  a employee id ");
		scanf("%d" , &id);
		flag = Search_Rec(emp,id);

		if(flag != -1)
		{
			printf("\n Record exists");
			j--;
			flag = 0;
		}
		else         // entering the record
		{
			emp[iCount].e_id = id;
			printf("\n Enter ur name ");
			scanf("%s" , emp[iCount].Name);
			printf("\n Enter salary");
			scanf("%d" , &emp[iCount].salary);
			printf("\n Record entered successfully");
			printf("\n");
			iCount++;
		}
	}//End of for loop
	
if(datafull==1)
{
	printf("Sorry , Database is full !! No more records can be added");
}
}     //End of insert function


/* To search a record */

int Search_Rec(employee emp[MAX],int id)     //Function defination
{
	int i,retval=-1;            // Local variable declaration
	for(i = 0 ; i < iCount ; i++)   // Logic to search the record
	{
		if(id == emp[i].e_id)//to check if record exists
		{
			retval= i;
			break;
		}

	}   // End of for loop

	return retval;
}   // End od function

/* Code to display records  */

void Display_Rec(employee emp[MAX])  // Function defination
{
	int i;
	printf("\n ***********Records***********");
	printf("\n");
	if(iCount>0)
	{
		for(i= 0 ; i < iCount ; i++)
		{
			printf("\n Employee id : %d " , emp[i].e_id);
			printf("\n Name : %s " , emp[i].Name);
			printf("\n salary : %d " , emp[i].salary);
			printf("\n");
		}   // End of for loop
	}
	else
	{
		printf("Empty Database!!!");
	}

}  // End of function

/* Code to modify a record  */

void Modify_Rec(employee emp[MAX]) // Function Defination
{
	int id ,i , pos = 0 ;
	printf("\n Enter  a employee id ");
	scanf("%d" , &id);
	pos = Search_Rec(emp,id);
	if(pos != -1)
	{
		printf("\n Enter name : ");
		scanf("%s" , emp[pos].Name);
		printf("\n Enter salary ");
		scanf("%d" , &emp[pos].salary);
		printf("\n The record if modified ");
		printf("\n");
	}
	else
		printf("\n Record does not exist");
}   // End of function

/* Code to delete a record */

void Delete_Rec(employee emp[MAX])  // Function declaration
{
	int id ,i, pos ;      // Local variable declaration
	printf("\n Enter  a employee id ");
	scanf("%d" , &id);
	pos = Search_Rec(emp,id);
	if(pos != -1)
	{
	//shift records to left side to overwrite current record
		for(i=pos;i<iCount;i++)
		{
			emp[i]=emp[i+1];
		}
		printf("\n Record deleted ");
		iCount--;
	}
	else
		printf("\n Record not found");
}   // End of function
