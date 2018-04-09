#include<stdio.h>
#define MAX 50
typedef struct sparse_matrix
{
  int row;
  int col;
  int value;
}mat;

void create(mat A[MAX]);
void display(mat A[MAX]);
void transpose(mat A[MAX],mat B[MAX]);
void ftranspose(mat A[MAX],mat B[MAX]);
void add(mat A[MAX],mat B[MAX]);

void main()
{
  
  mat A[MAX],B[MAX]; //........................mat declaration
  int matrix[MAX][MAX];
  int r,c,choice;
  
  printf("\nMATRIX :- \n");
  
  create(A);
  display(A);
 
  do
  {
    printf("\n\n************MENU*************\n 1.SIMPLE TRANSPOSE \n 2.FAST TRANSPOSE \n 3.ADDITION \n 4.EXIT \n");
    printf("\nENTER YOUR CHOICE : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: //simple transpose
		printf("______________________________________________");
                printf("\n#GIVEN MATRIX :- \n");
                display(A);
                printf("\n\n#TRANSPOSE OF MATRIX :- \n");
                transpose(A,B);
		display(B);
                
                break;
 
        case 2: //fast transpose
		printf("______________________________________________");
                printf("\n#GIVEN MATRIX :- \n");
                display(A);
                printf("\n\n#FAST TRANSPOSE OF MATRIX :- \n");
                ftranspose(A,B);
		display(B);
                break;
 
        case 3: //addition
                printf("\n#ENTER 2nd MATRIX :- \n");
  		create(B);   
		printf("______________________________________________");
                printf("\n#MATRIX 1 :- \n");
                display(A);
                printf("\n\n#MATRIX 2 :- \n");
                display(B);           
                printf("\n______________________________________________\n");
                add(A,B);
                break;
        
        case 4:
                break;
 
       default: printf("\n INVALID CHOICE");
    }
  }while(choice!=4);
}

void create(mat A[MAX])
{
  int i,j,r,c,p=1,count=0;
  int matrix[MAX][MAX];
  printf("\nENTER NO. OF ROWS : ");
  scanf("%d",&r);
  printf("\nENTER NO. OF COLUMNS : ");
  scanf("%d",&c);
  printf("\nENTER THE ELEMENTS IN THE MATRIX - \n");
  

  for(i=0;i<r;i++)
   {
    for(j=0;j<c;j++)
     {
       scanf("%d",&matrix[i][j]);
     }
   }

  for(i=0;i<r;i++)
   {
    for(j=0;j<c;j++)
     {
       if(matrix[i][j]!=0)
       {
          A[p].row=i;//............................only i,j and not a[i],a[j]
          A[p].col=j;
          A[p].value=matrix[i][j];    
          p++;
          count++;
       }
     }
   }
 
A[0].row=r;
A[0].col=c;
A[0].value=count;
}

void display(mat A[MAX])
{
  int i,count=A[0].value;
  for(i=0;i<=count;i++)
   {
     printf("\n ROW : %d \t COL : %d \t VALUE : %d \t ",A[i].row,A[i].col,A[i].value);
   }
}

void transpose(mat A[MAX],mat B[MAX])
{
  int i,j,p=1,n;
 
 B[0].row=A[0].col;
 B[0].col=A[0].row; 
 B[0].value=n=A[0].value;
  if(n>0)
    {
      for(i=0;i<A[0].col;i++)
      {
  	for(j=1;j<=n;j++)
  	{       
    	  if(A[j].col==i)//......................................................"=="
           {
             
             B[p].row=A[j].col;
             B[p].col=A[j].row;
             B[p].value=A[j].value;
             p++;
           }
        }
      }
      
   }
}

void add(mat A[MAX],mat B[MAX])
{
 int i=1,j=1,k=1;
 mat C[MAX];
 if(A[0].row==B[0].row && A[0].col==B[0].col)
  {
    while(i<=A[0].value && j<=B[0].value)
     {
       if(A[i].row==B[j].row && A[i].col==B[j].col)  
        {
          C[k].row=A[i].row;
          C[k].col=A[i].col;
          C[k].value=A[i].value+B[j].value;
          i++;
          j++;
          k++;
        }
       else if(A[i].row==B[j].row && A[i].col<B[j].col)
        {
          C[k].row=A[i].row;
          C[k].col=A[i].col;
          C[k].value=A[i].value;
          i++;
          k++;
        }   
       else if(A[i].row==B[j].row && A[i].col>B[j].col)
        {
          C[k].row=B[j].row;
          C[k].col=B[j].col;
          C[k].value=B[j].value;
          j++;
          k++;
        }
       else if(A[i].row<B[j].row)
        {
          C[k].row=A[i].row;
          C[k].col=A[i].col;
          C[k].value=A[i].value;
          i++;
          k++;
        } 
       else 
        {
          C[k].row=B[j].row;
          C[k].col=B[j].col;
          C[k].value=B[j].value;
          j++;
          k++;
        } 
    }
  
  while(A[0].value>=i)
   {
     C[k]=A[i];
     i++;
     k++;
   }
  while(B[0].value>=j)
   {
     C[k]=B[j];
     i++;
     k++;
   }
 C[0].row=A[0].row;
 C[0].col=A[0].col;
 C[0].value=k-1;
 printf("\n#ADDED MATRIX :- \n");
 display(C);
}
 else
{
printf("\nMATRIX SIZE IS NOT SAME!! \n");
}
}

void ftranspose(mat A[MAX],mat B[MAX])
{
	int rowTerms[10], startPos[10],n;
	int i,p;
	
	B[0].row=A[0].col;
	B[0].col=A[0].row;
	n= B[0].value=A[0].value;
	
	if(n>0)
	{
		for(i=0; i<A[0].col; i++)
			rowTerms[i]=0;
		
		for(i=1; i<=n; i++)
			rowTerms[A[i].col] = rowTerms[A[i].col]+1;
			startPos[0]=1;
		
 		for(i=1;i<A[0].col;i++)
			startPos[i]= startPos[i-1]+rowTerms[i-1];
		
		for(i=1;i<=n;i++)
		{
			p=startPos[A[i].col] ++ ;
			B[p].row=A[i].col;
			B[p].col=A[i].row;
			B[p].value=A[i].value;
		}
	}
}








