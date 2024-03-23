#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int findMaxRec(int A[], int n) {
    if (n == 1)
        return A[0];
    return max(A[n - 1], findMaxRec(A, n - 1));
}

int main() {
    int arr[100];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
    printf("Largest in given array is %d", findMaxRec(arr, n));
    return 0;
}

