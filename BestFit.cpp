// best fit memory management algorithm
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int n,b,bs[20],ef,s,p,ps[20],i,j,inf,a[20],fmem[20],allo[20],temp,temp1,po[20];
	cout<<"enter the overall size of memory ";
	cin>>n;
	cout<<"enter the number of blocks ";
	cin>>b;
	
	while(1)
	{
		s=0;
		cout<<"enter individual sizes of all the blocks ";
		for(i=0;i<b;i++)
		{
			cin>>bs[i];
			s=s+bs[i];
			po[i]=i+1;
		}
		if(s>n)
		{
			cout<<"re-enter the block size because it exceeds overall memory";
		}
		else 
			break;
			
	}
	
	//sorting according to block size so that best fit can be implemented
	for(i=0;i<b;i++)
	{
		for(j=0;j<b-i;j++)
		{
			if(bs[j]>bs[j+1])
			{
				temp=bs[j];
				bs[j]=bs[j+1];
				bs[j+1]=temp;
				
				temp1=po[j];
				po[j]=po[j+1];
				po[j+1]=temp1;
			}
		}
	}
	ef= n-s;
	cout<<"enter number of processes";
	cin>>p;
	cout<<"enter individal process size ";
	for(i=0;i<p;i++)
	{
		cin>>ps[i];
		a[i]=0;
	}
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<b;j++)
		{
			if(a[j]==0 &&(bs[j]>=ps[i]))
			{
			fmem[j]=bs[j]-ps[i];//internal fragmentation
			allo[j]=i; //store that which process allocated to which block
			a[j]=1; //allocation flag array
			break;
			}
		}
	}	
	
	cout<<"\n \t BLOCK \t BLOCK SIZE \t PROCESS \t PROCESS SIZE";
	for(i=0;i<b;i++)
	{
		cout<<"\n \t"<<i+1<<" \t "<<bs[i];
		if(a[i]==1)
		{
			cout<<"\t"<<allo[i]+1<<"\t"<<ps[allo[i]];
		}
		else 
		{
			cout<<"\t not allocated";
		}
	}
	
	cout<<"\n external fragmentation "<<ef<<endl;
	inf=0;
	for(i=0;i<b;i++)
	{
		inf=inf+fmem[i];	
	}
	cout<<"\n internal fragmentation "<<inf<<endl;
	getch();
	
	
}
