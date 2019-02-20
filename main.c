#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int count_set_bits(int n)
{
    if(n==0)return 0;
    if(n==1 || n==2)return 1;
    if(n==3)return 2;
    if(n==4)return 1;
    if(n==5)return 2;
    if(n==6)return 2;

}
int assign(int a[3][3],int n)
{
 int set_size=pow(2,n);
 int b[set_size];
 int mask,x;


 b[0]=0;
 for(int i=1;i<set_size;i++)
 {
     b[i]=INT_MAX;
 }

 for(mask=0;mask<set_size;mask++)
 {
     x=count_set_bits(mask);

     for(int j=0;j<n;j++)
     {
         if((mask & 1<<j)==0)
         {
             b[mask | 1<<j]=min( b[mask | 1<<j] , b[mask]+a[x][j]);
         }
     }
 }
 return b[set_size-1];

}

int min(int n1,int n2)
{
    if(n1<n2)return n1;
    else return n2;
}


int main()
{
    int n=3;
    int a[3][3]={{8,2,5},{3,2,7},{4,1,2}};

    int nn=assign(a,n);
/*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
*/
    printf("\nMin sum : %d\n",nn);
    return 0;
}
