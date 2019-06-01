//Implementation of first come first served process scheduling algorithm

#include <stdio.h>


void swap(int *a,int*b)
{
    int z=*a;
    *a=*b;
    *b=z;
}

void sortTime(int at[],int bt[],int process[],int pno)
{
        for(int i=0;i<pno-1;i++)
    {
        int check=0;
        for(int j=0;j<pno-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&process[j],&process[j+1]);
                check=1;
            }
        }
        if(check==0)
            break;
    }
}
int main()
{
    int pno;
    printf("How many processes you want to schedule: ");
    scanf("%d",&pno);
    int at[pno],bt[pno],process[pno];
    printf("Enter the arrival time and burst time of the processes:\n");
    for(int i=0;i<pno;i++)
    {
        process[i]=i+1;

        printf("Arrival Time of Process %d : ", i+1);
        scanf("%d",&at[i]);

        printf("Burst Time of Process %d : ", i+1);
        scanf("%d",&bt[i]);
    }

    printf("The input for arrival time and burst time for the processes are as follows:\n");

    printf("P\tAT\tBT\n");
    for(int i=0;i<pno;i++)
        printf("%d\t%d\t%d\n",process[i],at[i],bt[i]);

    sortTime(at,bt,process,pno);

    printf("\nAfter sorting:\n");

    printf("P\tAT\tBT\n");
    for(int i=0;i<pno;i++)
        printf("%d\t%d\t%d\n",process[i],at[i],bt[i]);
    
    printf("\n");

    printf("The gantt chart for the given processes is:\n");
    
    for(int i=0;i<pno;i++)
        printf("   P[%d]\t",process[i]);
    printf("\n");
    
    int comp[pno+1];
    
    for(int i=0;i<=pno;i++)
    {
        if(i==0)
            comp[i]=at[i];
        else
        {
            comp[i]=bt[i-1]+comp[i-1];
        }
    }
    
    for(int i=0;i<=pno;i++)
    {
        printf("%d\t",comp[i]);
    }
    printf("\n");
    return 0;
}
