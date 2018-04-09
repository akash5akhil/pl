#include<stdio.h>;
#include<stdlib.h>;
#include<string.h>;
#define MAX 10
typedef struct
{
    int e_id;
    char Name[30];
    int salary;
}employee;
int icount=0;
void initialize(employee emp[MAX])
{
    int i;
    for(i=0;i&lt;MAX;i++)
        emp[i].e_id=0;
}
void InsertRecord(employee emp[MAX], int recno)
{
    int id,j,i,flag=0,pos;
    for(j=0;j&lt;recno;j++)
    {
        printf(&quot;\nEnter an employee ID&quot;);
        scanf(&quot;%d&quot;,&amp;id);
        flag=SearchRecord(emp,id);
        if(flag!=-1)
        {
            printf(&quot;\nRecord exists&quot;);
            j-- ;
            flag=0;
        }
        else
        {
            pos=findfree(emp);
            if(pos==-1)
            {
                printf(&quot;\nEmpty slot is not present&quot;);
                return;
            }
            emp[pos].e_id=id;
            printf(&quot;\nEnter your name&quot;);
            scanf(&quot;%s&quot;,emp[pos].Name);
            printf(&quot;\nEnter your Salary&quot;);
            scanf(&quot;%d&quot;,&amp;emp[pos].salary);
            printf(&quot;\nRecord entered successfully&quot;);
            icount++;
            
        }
    }
}
int findfree(employee emp[MAX])
{
    int i;
    for(i=0;i&lt;MAX;i++)
    {

        if(emp[i].e_id==0)
            return i;
    }
    return (-1);
}
int SearchRecord(employee emp[MAX], int id)
{
    int i;
    for(i=0;i&lt;icount;i++)
    {
        if(id==emp[i].e_id)
            return i;
    }
    return -1;
}
void DisplayRecord(employee emp[MAX])
{
    int i;
    printf(&quot;\n***********************RECORDS***********************&quot;);
    printf(&quot;\nID\tName\tSalary&quot;);
    for(i=0;i&lt;icount;i++)
    {
        if(emp[i].e_id!=0)
        {
            printf(&quot;\n%d\t%s\t%d&quot;,emp[i].e_id,emp[i].Name,emp[i].salary);
        }
    }
}
void ModifyRecord(employee emp[MAX])
{
    int id,i,flag=0;
    printf(&quot;Enter Employee ID&quot;);
    scanf(&quot;%d&quot;,&amp;id);
    flag=SearchRecord(emp,id);
    if(flag!=-1)
    {
        printf(&quot;\nEnter your name&quot;);
        scanf(&quot;%s&quot;,emp[flag].Name);
        printf(&quot;\nEnter your Salary&quot;);
        scanf(&quot;%d&quot;,&amp;emp[flag].salary);
        printf(&quot;\nRecord is modified successfully&quot;);
    }
    else
        printf(&quot;\nRecord does not exist&quot;);
}
void DelRecord(employee emp[MAX])
{
    int id,flag=0;
    printf(&quot;\nEnter Employee ID&quot;);
    scanf(&quot;%d&quot;,&amp;id);
    flag=SearchRecord(emp,id);
    if(flag!=-1)
    {
        emp[flag].e_id=0;
        printf(&quot;\n Record deleted&quot;);
    }
    else
        printf(&quot;Record not found&quot;);
}
void Delete(employee emp[MAX])
{
    int i,id,flag=0;
    printf(&quot;\nEnter Employee ID&quot;);
    scanf(&quot;%d&quot;,&amp;id);
    for(i=flag+1;i&lt;MAX;i++)
    {
        emp[i-1].e_id=emp[i].e_id;
        strcpy(emp[i-1].Name,emp[i].Name);
        emp[i-1].salary=emp[i].salary;
    }
    printf(&quot;Record deleted successfully&quot;);
}
int main(void)
{
    int choice,recno,id,flag;
    employee emp[MAX];
    initialize(emp);    
    do
    {
        printf(&quot;\n Enter : \n1. Insert a new Record \n2.Search a Record \n3.Display Records \n4.Modify
Records \n5.Delete A Record logically \n6.Delete a Record \n7.Exit&quot;);
        printf(&quot;\nEnter your choice\n&quot;);
        scanf(&quot;%d&quot;,&amp;choice);
        
        switch(choice)
        {
            case 1: printf(&quot;\n How many records do you want to enter&quot;);
                scanf(&quot;%d&quot;,&amp;recno);
                InsertRecord(emp,recno);
                break;
            case 2: printf(&quot;\nEnter employee ID\n&quot;);
                scanf(&quot;%d&quot;,&amp;id);
                flag=SearchRecord(emp,id);
                if(flag!=-1)
                {
                    printf(&quot;\nRecord exists&quot;);
                    printf(&quot;\nID\tName\tSalary&quot;);
                    printf(&quot;\n%d\t%s\t%d&quot;,emp[flag].e_id,emp[flag].Name,emp[flag].salary);
                }
                else
                    printf(&quot;\nRecord does not exist&quot;);
                break;
            case 3: DisplayRecord(emp);
                break;
            case 4: ModifyRecord(emp);
                break;
            case 5: DelRecord(emp);
                break;
            case 6: Delete(emp);
                break;
            default:printf(&quot;\nEnter valid option&quot;);
        }
    }while(choice!=7);  }
