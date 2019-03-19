#include<stdio.h>
#include<conio.h>
void dfs(int v);
typedef enum boolean{false,true}bool;
int n,a[6][6]={{0,0,0,0,0,0},{0,0,1,1,0,0},{0,1,0,0,1,1},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0}};
bool visited[10];
int b[6][2];
void main()
{
int i,j,v;
n=5;
//printf("Enter the no. of nodes in the graph\n");
//scanf("%d",&n);

printf("Enter the adjacency matrix \n");


printf("The adjacency matrix shown as\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
printf("Enter the starting node for Depth First search\n");
scanf("%d",&v);
for(i=1;i<=n;i++)
visited[i]=false;
dfs(v);
getch();
}
void dfs(int v)
{
    int p,o;
    for(p=1;p<2;p++)
    {
        for(o=1;o<2;o++)
        {
       b[p][o]=0;
        }
    printf("\n");
    }


int i,stack[10],stack1[10],top=-1,pop,top1=-1;
top++;
stack[top]=v;

top1++;
stack1[top1]=v;

int nt=1;

while(top>=0)
{
    int fg1=0;
    pop=stack[top];
    top--;


    if(visited[pop]==false)
    {
  //  printf("%d",pop);
    b[pop][0]=nt++;
    visited[pop]=true;
    }
    else
    continue;

    for(i=n;i>=1;i--)
    {
        if(a[pop][i]==1 && visited[i]==false)
        {
        top++;// push all the unvisited neighbours in the stack
        stack[top]=i;

        top1++;// push all the unvisited neighbours in the stack
        stack1[top1]=i;
        fg1=1;
        }
    }
    if(fg1==0)
    {
       b[pop][1]=nt;
       int pop1=stack1[top1];
        top1--;

       nt=nt+1;
        if(pop1!=pop)
        {
            nt=nt-2;
            visited[pop]=false;

          //  printf("\npop= %d pop1=%d nt=%d\n",pop,pop1,nt);
            b[pop1][1]=nt;
             top++;
             nt=nt+1;

         //   printf("\npop= %d pop1=%d nt=%d\n",pop,pop1,nt);
        }


    }
    b[v][1]=nt;

}

printf("\nThe PRE-POST matrix shown as\n");
for(p=1;p<=n;p++)
{
    for(o=0;o<2;o++)
    {
    printf("%d ",b[p][o]);
    }
printf("\n");
}


}
