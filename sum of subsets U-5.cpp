#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void findSubsets(int set[], int n, int sum, int subset[], int subsetSize, int totalSum, int k);
void displaySubset(int subset[], int subsetSize);
void findSubsets(int set[], int n, int sum, int subset[], int subsetSize, int totalSum, int k) {
    if (sum == totalSum) {
        displaySubset(subset, subsetSize);
        findSubsets(set, n, sum - set[k], subset, subsetSize - 1, totalSum, k + 1);
        return;
    } else {
        for (int i = k; i < n; i++) {
            if (sum + set[i] <= totalSum) {
                subset[subsetSize] = set[i];
                findSubsets(set, n, sum + set[i], subset, subsetSize + 1, totalSum, i + 1);
            }
        }
    }
}
void displaySubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

int main() {
    int set[100],n,i;
    printf("Enter the size of the set:");
    scanf("%d",&n);
    printf("Enter the elements of the set:");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&set[i]);
	}
    int subset[MAX_SIZE];
    int totalSum;
    printf("Enter the totalsum of the subset:");
    scanf("%d",&totalSum);

    printf("Subsets with sum equal to %d are:\n", totalSum);
    findSubsets(set, n, 0, subset, 0, totalSum, 0);

    return 0;
}

