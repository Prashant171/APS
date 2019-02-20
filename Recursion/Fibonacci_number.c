//To print the nth fibonacci number 
#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n)
{
    int *fib,i;
    fib=(int *)malloc(sizeof(int)*(n+1));
    fib[0]=0;
    fib[1]=1;
    for(i=2;i<=n;i++)
        fib[i]=fib[i-1]+fib[i-2];
    return fib[n];
}

int main()
{
    int n,res;
    printf("Fibonacci numbers: ");
    printf("\nEnter the required n value for the fibonacci number: ");
    scanf("%d",&n);
    if(n>=0)
    {
      res=fibonacci(n);
      printf("\nThe %d fibonacci number is: %d",n,res);
    }
    else
        printf("\nEnter the valid value for n");
    return(0);
}
