#include<iostream>
using namespace std;

//non preemptive

struct process
{
	int at;
	int bt;
	int wt;
	int tat;
	bool exe;
};

int main()
{
	int i,j,small,n;
	printf("Enter the number of processes");
	scanf("%d",&n);
	process P[n],temp;
	for(int i=0;i<n;i++)
	{
		cin>>P[i].at;	
		cin>>P[i].bt;
		P[i].exe=false;
	}	
	
	for(i=0;i<n-1;i++)
	{
		small=i;
		for(j=i+1;j<n;j++)
		{
			if(P[small].bt>=P[j].bt)
			{
				small=j;
			}
		}	
		if(small!=i)
		{
			temp.at=P[i].at;
			temp.bt=P[i].bt;
			P[i].at=P[small].at;
			P[i].bt=P[small].bt;
			P[small].at=temp.at;
			P[small].bt=temp.bt;
		}
	}
	
	
	for(int i=0;i<n;i++)
	{
		
		cout<<'\n'<<P[i].at<<'\t'<<P[i].bt<<'\n';
	}
	//array is sorted now
	
	int time=P[0].at;
	for(i=1;i<n;i++)
	{
		if(P[i].at<=time)
		time=P[i].at;
	}
	
	cout<<"\nstarting time is "<<time;
	
	//starting time tak aa gaya sahi
	
	int cycles=n;
	int k;
	while(cycles>0)
	{
		int smallbt=P[n-1].bt;
		for(i=0;i<n;i++)
		{
			while(time<=P[i].at&&P[i].exe==false)
			{
				if(P[i].bt<=smallbt)
				{
					smallbt=P[i].bt;
					k=i;
				}
			}	
		}
		
		P[k].exe=true;
		time+=P[k].bt;
		cycles--;
	}
	
	return 0;
}
