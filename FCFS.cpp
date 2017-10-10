// first come first serve (FCFS) algorithm for CPU scheduling
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int n, bt[20], wt[20],i,j,tt[20];
	float avgtt,avgw,s;
	cout<<"enter the number of processes"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter the burst time for process "<< i+1<<endl;
		cin>> bt[i];
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
		cout<<"waiting time for the processes "<<i+1<<"= "<<wt[i]<<endl;
		s=s+wt[i];
	}
	 avgw= s/n;
	 cout<<"average waiting time ="<<avgw<<endl;
	 
	 s=0;
	for(i=0;i<n;i++)
	{
	 	tt[i]=bt[i]+wt[i];
	 	cout<<"turn around time for process "<<i+1<<"="<<tt[i]<<endl;
	 	s=s+tt[i];
	}
	 
	 avgtt=s/n;
	 cout<<"average turn around time "<<avgtt<<endl;
	 
	 getch();
	 return 0;
}
