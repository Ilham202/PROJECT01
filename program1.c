#include<stdio.h>
int main()
 {
 	int i,j,k,pos,temp;
	float bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int p[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0,totalTAT2=0;
    printf("\n\t\t\t\t!!!!------- FCFS & SJF Algorithm ------------!!!!\n\n");
	printf("Enter number of processes -> ");
	scanf("%d",&n);
	printf("Enter arrival time and burst time for each process ::\n\n");

	for(i=0;i<n;i++)
	{
		printf("Arrival time of process[%d]-> ",i+1);
      	scanf("%f",&at[i]);
		printf("Burst time of process[%d]-> ",i+1);
		scanf("%f",&bt[i]);
        p[i]=i+1;
		printf("\n");
	}

	//calculate completion time of processes 	

	for(j=0;j<n;j++)
	{
		//sum+=bt[j];
		//ct[j]+=sum;
		if(j == 0) ct[j] = bt[j] + at[j];
		else ct[j] = ct[j-1] + bt[j];
	}

	//calculate turnaround time and waiting times 

	for(k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];

	}

	for(k=0;k<n;k++)
	{

		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];

	}

    //system("cls");

	printf("\n\t\t\t\t   Solution for FCFS is -> \n");
	printf("\t\t\t\t  ------------------------\n\n");
	printf("Process\t AT\t BT\t CT\t TAT\t WT\t\n\n");

	for(i=0;i<n;i++)
	{

		printf("P%d\t %.3f\t %.3f\t %.3f\t %.3f\t %.3f\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

	}

	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average Waiting Time = %.3f\n\n",totalWT/n);

	
	//Shortest Job First 
	sum=0;
	totalTAT=0,totalWT=0,totalTAT2=0;
	
	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {

            if(bt[j]<bt[pos])

                pos=j;

        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

 

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;            //waiting time for first process will be 1

    //calculate waiting time

    for(i=1;i<n;i++)
    {

        wt[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
        totalWT+=wt[i];
    }

    printf("\t\t\t\t   Solution for SJF is -> \n");
    printf("\t\t\t\t  ------------------------\n\n");
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        totalTAT+=tat[i];
        printf("\nP%d\t\t  %f\t\t    %f\t\t\t%.3f",p[i],bt[i],wt[i],tat[i]);

    }
 
    //average turnaround time

    printf("\nAverage Turnaround Time=%.3f\n",(float)totalTAT/n);//average turnaround time
    printf("Average Waiting Time=%.3f\n\n",(float)totalWT/n);//average waiting time
    printf("Average Turnaround time if CPU is left for 1 time unit : %.3f\n",(totalTAT + 1)/n); 
	
    return 0;
}

