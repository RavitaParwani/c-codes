#include<iostream>
using namespace std;

struct process
{
    int at;
    int bt;
};

int main()
{
int n;
cout<<"Enter the no. of processes";
process P[n];

for(int i=0;i<n;i++)
{
    cin>>P[i].at;
    cin>>P[i].bt;
}
for(int i=0;i<n;i++)
{
    cout<<P[i].at<<'\t';
    cout<<P[i].bt<<endl;
}
return 0;
}
