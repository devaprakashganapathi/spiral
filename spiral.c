//This file contains code for printing spiral in C language
//author: Deva Prakash Ganapathi
#include<stdio.h>
int min(int,int);
void find(int,int,int);//function to print each element
int main(void){
    int i,j,n;
    //read the dimension of square matrix to be printed
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)    find(i,j,n);
        printf("\n\n");
    }
return 0;
}
void find(int i,int j,int n){
    //'r' finds the level of the square matrix in which the element lies
    int r=min(min(min(i,j),n-i-1),n-j-1),add=0,t=n,tr=r;
    //used to calculate the base value of the level
    //for example, n=5; for the 1st level , it is 0
    //for the 2nd level, it is 16(the last element in previous level)
    //for the 3rd level , it is 24 (the last value in previous level)
    while(tr>0){
        add+=2*t+2*(t-2)-1;
        t-=2;tr--;
    }
    //the if-else ladder is to find the edge/side of the level in which the element lies
    //here,there are 4 sides for each level: namely, top,right,bottom and left
    if(i==r)    printf("%3d ",add+j+1);
    else if(j==n-r-1) printf("%3d ",add+(n-(2*r))+i);
    else if(i==n-r-1) printf("%3d ",add+(2*(n-(2*r)))+(n-2-j));
    else if(j==r)   printf("%3d ",add+(3*(n-(2*r))-1)+(n-2-i));
    return;
}
int min(int i,int j){
    //function to return the minimum of 2 numbers
    return (i<j)?i:j;
}
