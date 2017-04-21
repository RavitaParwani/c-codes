#include<stdio.h>
struct Input
{ char pname[10];
int  bt,at,ct,wt,tbt;
}tab[5];
struct Sequence
{ int start,end;
char pname[10];
}seq[100],seq1[20];
int finish,time,n,k,prev;
void getinput()
{ int i;
printf("\nEnter No.of Processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{  printf("Process name:");
scanf("%s",tab[i].pname);
printf("Arrival time:");
scanf("%d",&tab[i].at);
printf("Burst time:");
scanf("%d",&tab[i].bt);
tab[i].tbt = tab[i].bt;
 }
}
void bubble()
{ struct Input t;
int i,j;
for(i=0;i<n;i++)
for(j=0;j< (n-1)-i;j++)
if(tab[j].at>tab[j+1].at)
{ t = tab[j];
tab[j] = tab[j+1];
tab[j+1] = t;
   }
}
void printoutput()
{ int i;
float AvgTAT=0,AvgWT=0;
for(i=0;i<n;i++)
 {      tab[i].tbt=tab[i].ct-tab[i].at;
tab[i].wt=tab[i].ct-tab[i].at-tab[i].bt;
  AvgTAT += tab[i].ct-tab[i].at;
  AvgWT += tab[i].ct-tab[i].at-tab[i].bt;
printf("\n\nProgram%s", tab[i].pname);
printf("\nRelease time: %d", tab[i].at);
printf("\nBurst time: %d", tab[i].bt);
printf("\nWaiting time: %d", tab[i].wt);
printf("\nTurn around time: %d", tab[i].tbt);
 }
 AvgTAT/=n;
 AvgWT/=n;
printf("\n\nAverage TAT = %f",AvgTAT);
printf("\n\nAverage WT = %f",AvgWT);

}
int arrived(int t)
{ int i;
for(i=0;i<n;i++)
if(tab[i].at<=t && tab[i].tbt!=0)
return 1;
return 0;
}

int getmin(int t)
{ int i,mini,min=99;
for(i=0;i<n;i++)
if(tab[i].at<=t && tab[i].tbt!=0 && tab[i].tbt<min)
  {   min = tab[i].tbt;
mini = i;
  }
return mini;
}
void processinput()
{ int i,j;
finish=k=0;
while(finish!=n)
{  if(arrived(time))
{i = getmin(time);
for(j=0;j<tab[i].bt;j++)
{   time++;
tab[i].tbt--;
tab[i].ct=time;
seq[k].start=prev;
seq[k].end = time;
strcpy(seq[k++].pname,tab[i].pname);
prev = time;
if(tab[i].tbt==0)
     {    finish++;
break;
     }
   }
  }
else
{  time++;
seq[k].start=prev;
seq[k].end = time;
strcpy(seq[k++].pname,"*");
prev = time;
  }
 }
}
void main()
{ int i;
getinput();
bubble();
processinput();
printoutput();
}

