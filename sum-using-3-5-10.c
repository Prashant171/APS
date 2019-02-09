#include <stdlib.h>
#include <stdio.h>

int main()
{
    int sum=15;
    int num[]={3,5,10};

    int a[sum+1];
    int j=0;
    // Fill 8 characters starting from str[13] with '.'
    memset(a, 0, (sum+1)*sizeof(int));

    a[0]=1;

     for(int i=0;i<3;i++)
    {
        int h=num[j];
        a[h]=1;
         for(int k=1,l=h+1;l<(sum+1);k++,l++)
        {
            if(a[k]==1 )
            {
                a[l]=a[l]+1;

            }

        }
        j++;
    }

   for(int i=0;i<(sum+1);i++)
    {
     printf("%d ",a[i]);
    }
    return 0;

}
