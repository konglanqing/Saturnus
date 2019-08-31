/*  select_Sort.c  */

#include <stdio.h>

void select_Sort(int arr[],int len)
{
	int i = 0;
	int j = 1;
	for(i=0;i<len;i++)
	{
		int index_nmax = 0;
		for(j=1;j<len-i;j++)
		{
			if(arr[j] > arr[index_nmax])
			{
				index_nmax = j;
			}
		}
			if(index_nmax != len-i-1)
			{
				int temp = arr[index_nmax];
				arr[index_nmax]= arr[len-i-1];
				arr[len-i-1] = temp;
			}
		
	}

}

int main()
{
	int arr[]= {9,8,7,6,5,4,3,2,1,99};
	int len = sizeof(arr)/sizeof(arr[0]);
	travel(arr,len);
	
	select_Sort(arr,len);
	
	travel(arr,len);
	return 0;

}

