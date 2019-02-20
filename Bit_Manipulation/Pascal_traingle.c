#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,p=0;
    n=4,k=4;
    scanf("%d",&n);
    scanf("%d",&k);
   int a[n][k];


   for(int i=0;i<n;i++)
   {
       if(i<=k) p=i;
       else p=k;

       for(int j=0;j<=p;j++)
       {

           if(i==j || j==0)
           {
               a[i][j]=1;
           }
           else
           {
               a[i][j]=a[i-1][j-1]+a[i-1][j];

           }
       }

   }
 for(int i=0;i<n;i++)
   {
       if(i<=k) p=i;
       else p=k;

       for(int j=0;j<=p;j++)
       {
          printf("%d ",a[i][j]);
       }
printf("\n");
   }
    return 0;
}
