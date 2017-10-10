// priority scheduling algorithm for CPU scheduling
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int n, bt[20], wt[20],i,j,tt[20], p[20],temp, temp1, temp2, prio[20];
	float avgtt,avgw,s;
	cout<<"enter the number of processes"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		cout<<"enter the burst time for process "<< p[i] <<endl;
		cin>> bt[i];
	}
	
	for(i=0;i<n;i++)
	{
		cout<<"enter the priority for process "<< p[i]<<endl;
		cin>> prio[i];
	}
	
	for(i=0;i<n;i++) //swapping according to priority in ascending order
	{
		for(j=0;j<n-i;j++)
		{
			if(prio[j]>prio[j+1])
			{
				temp= bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp1=p[j];
				p[j]=p[j+1];
				p[j+1]=temp1;
				
				temp2= prio[j];
				prio[j]=prio[j+1];
				prio[j+1]= temp2;
			}
		}
	}

	
	
	wt[0]=0;
	for(i=0; i<n-1; i++)
	{
		s=0;
		for(j=0; j<=i; j++)
		{
			s= s+ bt[j];
		}
		wt[i+1]=s;
	}
	
	s=0;
	for(i=0;i<n;i++)
	{
		cout<<"waiting time for the processes "<<p[i]<<"= "<<wt[i]<<endl;
		s=s+wt[i];
	}
	 avgw= s/n;
	 cout<<"average waiting time ="<<avgw<<endl;
	 
	 
	 getch();
	 return 0;
}
