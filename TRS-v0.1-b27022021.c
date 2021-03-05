#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int createRandomInteger(int lowEnd, int highEnd){
 int num = (rand()%(highEnd-lowEnd+1))+lowEnd;
 return num;
}

int main (){

 int startingPoint;
 int lowRange, highRange;
 int episodeCount;
 int i,j,t;
 int co,ct;
 int mI[25][10];
 int index;


 printf("please enter starting point: ");
 scanf("%d", &startingPoint);
 printf("thank you\n");
 printf("please enter episode count: ");
 scanf("%d", &episodeCount);
 printf("thank You:\n");
 printf("please enter range(low): ");
 scanf("%d", &lowRange);
 printf("thank You:\n");
 printf("please enter range(high): ");
 scanf("%d", &highRange);
 printf("thank You:\n");

 t=highRange-lowRange+1;

 mI[0][0]=lowRange;
 mI[0][1]=t+lowRange;
 mI[0][2]=1;
 mI[0][3]=t;
 mI[0][4]=t;
 mI[t][1]=mI[0][1];
 mI[t][2]=mI[0][2];
 mI[t][3]=mI[0][3];
 mI[t][4]=mI[0][4];
 for(i=0;i<t;i++){
    j=i+1;
    mI[j][0]=mI[j-1][0]+1;
    mI[j][1]=t+mI[j][0];
    mI[j][2]=mI[j-1][2]+1;
    mI[j][3]=mI[j-1][3]-1;
    mI[j][4]=t;
    mI[t][1]+=mI[0][1];
    mI[t][2]+=mI[0][2];
    mI[t][3]+=mI[0][3];
    mI[t][4]+=mI[0][4];
 }
 co=0; ct=0;
 while(mI[t][2]<mI[t][1]){
    mI[t][2]+=t;
    mI[t][3]+=t;
    co++;
 }
 while(mI[t][4]>mI[t][1]){
    mI[t][4]-=5;
    ct++;
 }
 mI[t][4]-=5;
 ct--;
 for(i=0;i<t;i++){
    mI[i][2]=mI[i][2]+co;
    mI[i][3]=mI[i][3]+co;
    mI[i][4]=mI[i][4]-ct-1;
 }
 printf("Okay 5");
 for(i=0;i<t+1;i++){
    for(j=0;j<5;j++){
        printf("mI %d %d - %d\n", i,j,mI[i][j]);
    }

 }
}


/*
 srand(time(0));
 printf("Episode 1: %d\n", startingPoint);
 count--;
 for(i=0;i<count;i++){
   printf("Episode %d:  ", i+2);
   t=createRandomInteger(lE,hE);
   startingPoint=startingPoint+t-2;
   printf("%d ", startingPoint);
   printf("Change: %d\n", t-2);
 }
}
*/
