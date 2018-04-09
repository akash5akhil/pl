#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int id;
    char name[25];
    char dept[20];
    int sal;
}emp;

int main()
{
    FILE *fp,*ft;
    emp e;
    int ch,id,found;
    long int recsize=sizeof(e);
    fp=fopen("EMP.DAT","rb+");
    if(fp==NULL)
    {
        fp=fopen("EMP.DAT","wb+");
        if(fp==NULL)
        {
            printf("\nFile cannot be created. No space is available");
            exit(1);
        }
    }
    do
    {
        printf("\n1.Add Records \n2.Display Records \n3.Modify Record \n4.Delete Record \n5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                fseek(fp,0,SEEK_END);
                char another;
                another='Y';
                while(another=='Y' || another=='y')
                {
                    printf("\nEnter Id, Name, Department and Salary\n");
                    scanf("%d %s %s %d",&e.id,e.name,e.dept,&e.sal);
                    fwrite(&e,recsize,1,fp);
                    fflush(stdin);
                    printf("\nDo you want to enter more records?\n");
                   
                    scanf(" %c",&another);
                }
                break;
            case 2:
                rewind(fp);
                printf("\nEMP ID \tNAME   \tDEPARTMENT \tSALARY\n");
                while(fread(&e,recsize,1,fp)==1)
                    printf("\n%d\t%s\t%s\t%d",e.id,e.name,e.dept,e.sal);
                break;
            case 3:
                      another='Y';
                      found =0;
                      while(another=='Y' || another=='y')
                      {
                          printf("Enter id of employee to modify");
                          scanf("%d",&id);
                          rewind(fp);
                            while(fread(&e,recsize,1,fp)==1)
                            {
                                if(id == e.id)
                                {
                                    printf("Enter name, department and salary:\n");
                                    scanf("%s %s %d", e.name, e.dept, &e.sal);
                                    fseek(fp,-recsize,SEEK_CUR);
                                    fwrite(&e,recsize,1,fp);
                                    found = 1;
                                    break;
                                }
                            }
                            if(found == 0)
                                printf("Record not present.");
                            fflush(stdin);
                            printf("\nModify another record (Y|N)? ");
                            scanf(" %c", &another);
                            }
                            break;
            case 4:
                        another = 'Y';
                        while(another=='Y')
                        {
                            printf("\nEnter ID of employee to delete:");
                            scanf("%d", &id);
                            ft= fopen("TEMP.DAT", "wb");
                            rewind(fp);
                            found =0;
                            while(fread(&e,recsize,1,fp)==1)
                            {
                                if(id!=e.id)
                                    fwrite(&e,recsize,1,ft);
                                else
                                    found =1;
                            }
                            if(found==0)
                                printf("\nRecord not present.");

                            fclose(fp);
                            fclose(ft);
                            remove("EMP.DAT");
                            rename("TEMP.DAT","EMP.DAT");
                            fp = fopen("EMP.DAT", "rb+");
                            fflush(stdin);
                            printf("\nDelete another record (Y|N)?");
                            scanf(" %c", &another);
                        }
                        break;

                case 5:
                        fclose(fp);
                        exit(0);
                }
        }while(ch!=5);
        return 0;
}
