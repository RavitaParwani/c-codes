#include<stdio.h>

struct Process
{
    int bt;
    int at;

};

void Asc(struct Process x[],int n)
{
    int i,j;
    struct Process temp;
    for(i=1;i<n;i++)
    {
        for(j=i-1; j>=0 && x[j].at>x[i].at;j--);
        temp=x[j+1];
        x[j+1]=x[i];
        x[i]=temp;
    }

}

int main()
{
    int i,j,clock,n;
    struct Process P[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&P[i].bt,&P[i].at);
    }

    Asc(P,n);

    //Order of Processes
    for(i=0;i<n;i++)
        printf("\n%d %d",P[i].bt,P[i].at);


    clock=P[0].at+P[0].bt;
    printf("\nWaiting Time: 0 Turnaround Time: %d",P[0].bt+P[0].at);

    for(i=1;i<n;i++)
    {
        if(P[i].at>clock)
            {
                clock=P[i].at+P[i].bt;
                printf("\nWaiting Time: 0 Turnaround Time: %d",clock);
            }
        else
        {
            printf("\nWaiting Time: %d Turnaround Time: %d",clock-P[i].at,clock+P[i].bt);
            clock+=P[i].bt;
        }

    }
}

