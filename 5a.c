#include<stdio.h>
void main()
{
int p,q,pos,bT[10],rT[10],prio[10],remainPr,aT[10],totalExecTime=0;
int T,temp,flag=0,N;
float totalWaitTime=0,totalTurnAroundTime =0;
printf("Number of Process: ");
scanf("%d",&N);

remainPr=N;
printf("Arrival Time\n");
printf("------------\n");


for(p=0;p<N;p++){
printf("For P[%d]: ",p+1);
scanf("%d",&aT[p]);
}

printf("\nPriority\n");
printf("---------\n");


for(p=0;p<N;p++){
printf("For P[%d]: ",p+1);
scanf("%d",&prio[p]);
}


for(p=0;p<N;p++){
pos = p;
for(q=p+1;q<N;q++){
if(aT[p]==aT[q] && prio[q]>prio[p]){
pos = q;
}
	}
	temp = prio[p];
	prio[p]=prio[pos];
	prio[pos] = temp;
	
	temp=bT[p];
        bT[p]=bT[pos];
        bT[pos]=temp;
}
    printf("\nBurst Time\n");
    printf("-------------\n");
 

   for(p=0;p<N;p++){
        printf("For P[%d]: ",p+1);
        scanf("%d",&bT[p]);
        rT[p]=bT[p];
    }
	

    printf("\nTime Quantum: ");
    scanf("%d",&T);
	
    printf("\n");

    for(p=0;remainPr!=0;){
        
        if(rT[p]<=T && rT[p]>0){
		
            totalExecTime+=rT[p];
            rT[p]=0;
            flag=1;
        }

        else if(rT[p]>0){
            rT[p]-=T;
            totalExecTime= totalExecTime+T;
        }

        if(flag==1 && rT[p]==0){
            printf("P[%d] | Priority: %d | Arrival Time: %d | TurnAround Time: %d | Waiting Time : %d\n",p+1,prio[p],aT[p],totalExecTime-aT[p],totalExecTime-aT[p]-bT[p]);
            totalWaitTime += totalExecTime-aT[p]-bT[p];
			totalTurnAroundTime += totalExecTime-aT[p];
            flag=0;
            remainPr--;
        }

        if(p==N-1)
            p=0;
        else if(aT[p+1]<=totalExecTime){
            p++;
        }
        else
            p=0;
    }



    printf("Average Waiting Time (AWT): %f \n",(totalWaitTime*1.0)/N);
	printf("Average TurnAround Time: %f \n",(totalTurnAroundTime*1.0)/N);


}


