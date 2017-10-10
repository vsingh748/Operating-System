// shortest job first serve(SJFS) algorithm for CPU scheduling
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int n, bt[20], wt[20],i,j,tt[20], p[20],temp, temp1;
	float avgtt,avgw,s;
	cout<<"enter the number of processes"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		cout<<"enter the burst time for process "<< p[i] <<endl;
		cin>> bt[i];
	}
	
	for(i=0;i<n;i++) //swapping the burst time in ascending order
	{
		for(j=0;j<n-i;j++)
		{
			if(bt[j]>bt[j+1])
			{
				temp= bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp1=p[j];
				p[j]=p[j+1];
				p[j+1]=temp1;
			}
		}
	}
	
	cout<<"sorted burst time and process "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<bt[i]<<" of process "<< p[i] <<endl;
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
	 
	 s=0;
	for(i=0;i<n;i++)
	{
	 	tt[i]=bt[i]+wt[i];
	 	cout<<"turn around time for process "<<p[i]<<"="<<tt[i]<<endl;
	 	s=s+tt[i];
	}
	 
	 avgtt=s/n;
	 cout<<"average turn around time "<<avgtt<<endl;
	 
	 getch();
	 return 0;
}
