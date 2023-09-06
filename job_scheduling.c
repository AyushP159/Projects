//C Program to implement Greedy Job Scheduling
#include<stdio.h>
void main()
{
	int n,i,temp1,k,z,maxp=0;
	printf("\n============ Greedy Job Scheduling ============\n\n");
	printf("Enter no of jobs:");
	scanf("%d",&n);
	int d[n],p[n],j[n],q[n];
	for (i=0;i<n;i++)
	{
		j[i]=i+1;
	}
	for (i=0;i<n;i++)
	{
		printf("\nEnter deadline of Job %d    :",i+1);
		scanf("%d",&d[i]);
	}
	printf("\n\nNow enter profits of respective jobs");
	for (i=0;i<n;i++)
	{
		printf("\nEnter profit of Job %d    :",i+1);
		scanf("%d",&p[i]);
	}
	printf("\nDetails of jobs are:\n");
	for (i=0;i<n;i++)
	{
		printf("Job %d  with  Deadline: %d   &   Profit: %d\n",i+1,d[i],p[i]);
	}
	
	for (i=0;i<n;i++)
	{
		for (k=i+1;k<n;k++)
		{
			if (p[i]<p[k])
			{
				temp1=p[i];//sorting profit
				p[i]=p[k];
				p[k]=temp1;
				
				temp1=d[i];//sorting deadline
				d[i]=d[k];
				d[k]=temp1;
				
				temp1=j[i];//sorting job orders
				j[i]=j[k];
				j[k]=temp1;
			}
		}
	}	
	printf("\nAfter sorting profits in descending order,deatils of jobs are:\n");
	for (i=0;i<n;i++)
	{
		printf("Job %d  with  Deadline: %d   &   Profit: %d\n",j[i],d[i],p[i]);
	}
	
	for(i=0;i<n;i++)
	{
		q[i]=0;
	}
	q[d[0]-1]=j[0];//for 1st job
	maxp=p[0];
	for (i=1;i<n;i++)
	{
		z=-1;
		for (k=0;k<=(d[i]-1);k++)
		{
			if (q[k]==0)
			{
				z=k;
			}
		}
		if(z!=-1)
		{
		q[z]=j[i];
		maxp=maxp+p[i];
		}
	}
	printf("\nJobs in order to get max profit  :  ");
	for (i=0;i<n;i++)
	{
		if(q[i]!=0)
		{
		printf("Job%d  ",q[i]);
		}
	}
	printf("\nMaximum profit gained  :  %d",maxp);
}