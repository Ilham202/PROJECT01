#include<stdio.h>
int main()
 {
 	int i,j,k,pos,temp;
	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0},p[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;
    printf("\n\t\t\t\t!!!!------- FCFS & SJF Algorithm ------------!!!!\n\n");
	printf("Enter number of processes -> ");
	scanf("%d",&n);

	printf("Enter arrival time and burst time for each process ::\n\n");

	for(i=0;i<n;i++)
	{

		printf("Arrival time of process[%d]-> ",i+1);
		scanf("%d",&at[i]);
		
		printf("Burst time of process[%d]-> ",i+1);
		scanf("%d",&bt[i]);
		
		p[i]=i+1;
		
		printf("\n");
	}
		
	//calculate completion time of processes 	

	for(j=0;j<n;j++)
	{
		sum+=bt[j];
		ct[j]+=sum;
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
	
    system("cls");
	printf("\n\t\t\t\t   Solution for FCFS is -> \n");
	printf("\t\t\t\t  ------------------------\n\n");
	printf("Process\t AT\t BT\t CT\t TAT\t WT\t\n\n");
	
	for(i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
		
	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average Waiting Time = %f\n\n",totalWT/n);
	
	//Shortest Job First 
	
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
    wt[0]=0;            //waiting time for first process will be zero
 
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
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    //average turnaround time
    printf("\nAverage Turnaround Time=%f\n",(float)totalTAT/n);//average turnaround time
	printf("Average Waiting Time=%f\n\n",(float)totalWT/n);//average waiting time
    
    
	
	return 0;
}
