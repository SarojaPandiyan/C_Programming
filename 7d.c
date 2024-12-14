//To find the results of SJF and FCFS algorithms using c
#include<stdio.h>
void FCFS(int,int*,int*,int*);
void SJF(int,int*,int*,int*);
void main()
{
    int n,i,pid[10],at[10],bt[10];
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the process number: ");
        scanf("%d",&pid[i]);
        printf("\nEnter arrival time of %d: ",pid[i]);
        scanf("%d",&at[i]);
        printf("Enter the burst time of %d: ",pid[i]);
        scanf("%d",&bt[i]);
    }
    FCFS(n,pid,at,bt);
    SJF(n,pid,at,bt);
}
void FCFS(int size,int* pid,int* at,int* bt)
{
    int i,j,t1,t2,t3,c=0;
    int tat[size],wt[size];
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(at[i]>at[j])
            {
                t1=pid[i];
                pid[i]=pid[j];
                pid[j]=t1;
                t2=at[i];
                at[i]=at[j];
                at[j]=t2;
                t3=bt[i];
                bt[i]=bt[j];
                bt[j]=t3;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        c+=bt[i];
        tat[i]=c-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("\npid\tat\tbt\ttat\twt");
    for(i=0;i<size;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],tat[i],wt[i]);
    }
}

void SJF(int n,int* pid,int* at,int* bt)
{
    int i,j,min_bt,min_bt_pid,t=0;
    int wt[n],tat[n];
    for(i=0;i<n;i++)
    {
        min_bt = 999;

        for(j=0;j<n;j++)
        {
            if(at[j] <= t && bt[j] < min_bt && bt[j] != 0)
            {
                min_bt = bt[j];
                min_bt_pid = j;
            }
        }

        wt[min_bt_pid] = t - at[min_bt_pid];
        tat[min_bt_pid] = wt[min_bt_pid] + bt[min_bt_pid];

        bt[min_bt_pid] = 0;
        t += min_bt;
    }
    printf("\npid\tat\tbt\ttat\twt");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d",pid[i],at[i],bt[i],tat[i],wt[i]);
        }
}
