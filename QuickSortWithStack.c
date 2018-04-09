#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack
{
    int a,b;
}s[MAX];
int top=-1;
int a[MAX],n;
void accept();
void display();
void swap(int *,int *);
int partition( int ,int  );
void rec_quicksort( int , int );
void non_rec_quicksort(int ,int );
void push(int , int );
void pop(int *, int *);
int isempty();
int isfull(); 
 void main()
{
    int ch,low=0,high;
    for(;;)
    {
        printf("\n 1.Recursive Quick sort");
        printf("\n 2.Non Recursive Quick sort");
        printf("\n 3.Exit");
        printf("\n Enter your choice");
        scanf("%d",&ch);
            switch(ch)
            { 
 	case 1:
                        printf("\n Enter number of elements :");
                        scanf("%d",&n);
                        high = n-1;
                        accept();
                        rec_quicksort(low,n-1);
                        display();
                        break;
                case 2:
                        printf("\n Enter number of elements :");
                        scanf("%d",&n);
                        high=n-1;
                        accept();
                        non_rec_quicksort(low,high);
                        display();
                        break;
                case 3: exit(0);
            }
    }
}
void accept()
{    int i;
    printf("\n Enter the elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display()
{
    int i;
    printf("\n The array is :");
    for(i=0;i<n;i++)
    {
        printf("\t %d",a[i]);
    }
}
void swap(int *a,int *b)
{
    int t=0;
    t=*a;
    *a=*b;
    *b=t;
}
void push(int x, int y)
{
    if(isfull() == 1 )
    {
        printf("\n Stack is full !");
    }
    else
    {
        top++;
        s[top].a=x;
        s[top].b=y;
    }
}
void pop(int *x, int *y)
{
    if(isempty() == 1 )
    {
        printf("\n Stack is empty !");
    }
    else
    {
        *x=s[top].a;
        *y=s[top].b;
        top--;
    }
}
int isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(top == MAX)
        return 1;
    else
        return 0;
}
int partition(int low,int high)
{
    int piv,i,j;
    piv=a[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(a[i] <= piv && i<high)
            i++;
        while(a[j] >= piv && j>low)
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
        else
            break;
    }
    swap(&a[low],&a[j]);
    return j;
}
void rec_quicksort(int low,int high)
{
    int i, j=0;
    if(low < high)
    {
        for(i=low;i<high+1;i++)
            printf("%d\t",a[i]);
        printf("\n");
        j = partition(low,high);
        rec_quicksort(low,j-1);
        rec_quicksort(j+1,high);
    }
}
void non_rec_quicksort(int low ,int high)
{
    int i,j=0;
    push(low ,high);
    while(! isempty())
    {
        pop(&low , &high);
        while(low < high)
        {
            for(i=low;i<high+1;i++)
                printf("%d\t",a[i]);
             printf("\n");
            j = partition(low ,high);
            push(j+1,high);
            high=j-1;        
}   }  }
