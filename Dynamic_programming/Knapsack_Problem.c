//Knapsack problem
//Problem to find the maximum profit and which combination of weights produces that maximum profit.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,*weight,*value,i,j,capacity_bag,**v,a,b;
    printf("Knapsack problem");
    printf("\nEnter the number of items: ");
    scanf("%d",&n);
    weight=(int *)malloc(sizeof(int)*n);
    value=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the weight of item %d: ",i+1);
        scanf("%d",&weight[i]);
        printf("Enter the value of item %d: ",i+1);
        scanf("%d",&value[i]);
    }
    printf("\nEnter the maximum capacity of the bag: ");
    scanf("%d",&capacity_bag);
    v=(int **)malloc(sizeof(int *)*(n+1));
    for(i=0;i<n+1;i++)
    {
        v[i]=(int *)malloc(sizeof(int)*(capacity_bag+1));
    }
    memset(v[0],0,sizeof(int)*(capacity_bag+1));
    for(i=0;i<(n+1);i++)
        v[i][0]=0;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<capacity_bag+1;j++)
        {
            if(j-weight[i-1]<0)
            {
                v[i][j]=v[i-1][j];
            }
            else if(j-weight[i-1]>=0)
            {
                a=v[i-1][j];
                b=v[i-1][j-weight[i-1]]+value[i-1];
                if(a>=b)
                {
                    v[i][j]=a;
                }
                else
                {
                    v[i][j]=b;
                }
            }
        }
    }
    printf("\nFor analysis of the result: ");
    printf("\n");
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<capacity_bag+1;j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }
    printf("\nThe maximum value of the profit for this knapsack problem is : %d",v[n][capacity_bag]);
    printf("\nThe items which maximizes the profit is: ");
    for(i=n,j=capacity_bag;i>0&&j>0;)
    {
      if(v[i][j]==v[i-1][j])
         i=i-1;
      else
      {
         printf("\nItem: %d Weight: %d Value: %d",i,weight[i-1],value[i-1]);
         j=j-weight[i-1];
         i=i-1;
      }
    }
    return 0;
}
