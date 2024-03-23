#include <stdio.h> 
int max(int a, int b) { return (a > b) ? a : b; } 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	if (n == 0 || W == 0) 
		return 0; 
	if (wt[n - 1] > W) 
		return knapSack(W, wt, val, n - 1);  
	else
		return max( 
			val[n - 1]+ knapSack(W - wt[n - 1], wt, val, n - 1), 
			knapSack(W, wt, val, n - 1)); 
}  
int main() 
{ 
	int profit[10],i,n;
	int weight[10];
	int W =10; 
	printf("Enter the no of elements in the array:");
    scanf("%d",&n);
    
    printf("Enter the values:");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&profit[i]);
	}
    
    printf("Enter the weights:");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&weight[i]);
	}
	printf("%d", knapSack(W, weight, profit, n)); 
	return 0; 
}

