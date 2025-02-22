#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 7;
	int arr[7]={-3,-2,-1,0,1,2,3};
	int target= 3;
	int mid;
	int i = 0,j = n-1;
	while(i <= j)
	{
		mid = (i+j)/2;
//		printf("%d",mid);
		if(arr[mid] == target)
		{
	//		printf("hii");
			printf("%d",mid);
		}
		if(arr[mid] >= target)
		{
	//		printf("h1");
			j= mid-1;
		}
		else 
		{
	//		printf("h2");
			i = mid+1;
		}
	}
	return 0;
}	      
