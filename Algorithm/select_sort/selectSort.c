/*  selectSort.c  */

#include <stdio.h>

void selectSort(int *A,int n)
{
    int i = 1;
    int j ;
    for(i=1;i<=n;i++)
    {
        int k=i;
        for(j=i;j<=n;j++)
        {
            if (A[j] < A[k]){
                k = j;
            }
        }

    int temp = A[i];
    A[i] = A[k];
    A[k] = temp;

    }
}

int main (int argc,char *argv[])

{
    int A[10] = {6,5,2,10,8,4,7,1,3,9};
    int i;
    selectSort(A,10);
    for(i=0;i<10;i++)
    {
        printf("%d ",A[i]);

    }
    return 0;
}
