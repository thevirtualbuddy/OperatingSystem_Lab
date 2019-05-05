//Implementation of shortest job first process scheduling algorithm

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

void sJobFirst(int process[],int at[], int bt[],int pno)
{
    int qtime = 0, count=0;
    int total = pno;
    int processnew[pno],btnew[pno], atnew[pno];

    int waitingtime[pno];
    int processexec[pno];
    int finalcount = 0;
    while(pno!=0)
    {
        count = 0;
        //1. Selecting which processes are ready
        for(int i=0;i<total;i++)
        {
            if(at[i]<=qtime && process[i]!= -1)
            {
                processnew[count]=process[i];
                btnew[count]=bt[i];
                atnew[count]=at[i];
                count++;
            }
        }
        int processmin = processnew[0];
        int btmin = btnew[0];
        int atmin = atnew[0];

        //2. Selecting the process with least burst time which are in the ready queue
        for(int i=1;i<count;i++)
        {
            if(btmin > btnew[i])
            {
                btmin = btnew[i];
                atmin = atnew[i];
                processmin = processnew[i];
            }
            if(btmin == btnew[i])
            {
                if(atmin > atnew[i])
                {
                    atmin = atnew[i];
                    btmin = btnew[i];
                    processmin = processnew[i];
                }
            }
        }

        printf("Process[%d]\t %d - %d\n",processmin,qtime,btmin+qtime);

        processexec[finalcount] = processmin;
        waitingtime[finalcount] = qtime;
        //3. Deleting the executed process and updating queue time
        for(int i=0;i<total;i++)
        {
            if(processmin == process[i])
            {
                process[i]=-1;
            }
        }

        pno --;
        qtime += btmin;
        finalcount++;
    }

    //Sorting the executed process in ascending order
    for(int i=0;i<total-1;i++)
    {
        int check=0;
        for(int j=0;j<total-i-1;j++)
        {
            if(processexec[j]>processexec[j+1])
            {
                swap(&processexec[j],&processexec[j+1]);
                swap(&waitingtime[j],&waitingtime[j+1]);
                check=1;
            }
        }
        if(check==0)
            break;
    }

    int averagewaiting=0;

    for(int i=0;i<total;i++)
    {
        waitingtime[i] = waitingtime[i]-at[i]; 
    }
    for(int i=0;i<total;i++)
        averagewaiting+=waitingtime[i];

    float res = averagewaiting/total;

    printf("Average waiting time : %.2f\n",res);



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

    printf("\nAfter sorting the arrival time in ascending order:\n");

    printf("P\tAT\tBT\n");
    for(int i=0;i<pno;i++)
        printf("%d\t%d\t%d\n",process[i],at[i],bt[i]);
    printf("\n");

    sJobFirst(process,at,bt,pno);

//    printf("The gantt chart for the given processes is:\n");

    printf("\n");
    return 0;
}