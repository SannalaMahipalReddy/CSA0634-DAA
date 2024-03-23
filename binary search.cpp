#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (arr[m] == x)
			return m;
		if (arr[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}
int main(void)
{
	int arr[10],i,n;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("enter the elements of the array:");
	for(i-0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int x;
	printf("Enter the element to be found:");
	scanf("%d",&x);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Element is not present"
							" in array")
				: printf("Element is present at "
							"index %d",
							result);
	return 0;
}

