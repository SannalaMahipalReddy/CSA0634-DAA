#include <stdio.h>
#include <limits.h>

#define N 4
int findMinCost(int costMatrix[N][N], int assignment[], int assignedWorker[], int task, int cost, int numAssigned) {

    if (numAssigned == N)
        return cost;

    int minCost = INT_MAX;

    for (int worker = 0; worker < N; worker++) {
        if (!assignedWorker[worker]) {
            assignedWorker[worker] = 1;
            assignment[task] = worker;
            int currentCost = findMinCost(costMatrix, assignment, assignedWorker, task + 1, cost + costMatrix[worker][task], numAssigned + 1);

            if (currentCost < minCost)
                minCost = currentCost;
            assignedWorker[worker] = 0;
            assignment[task] = -1;
        }
    }

    return minCost;
}
int assignmentProblem(int costMatrix[N][N]) {
    int assignment[N];
    int assignedWorker[N] = {0};
    for (int i = 0; i < N; i++)
        assignment[i] = -1;
    return findMinCost(costMatrix, assignment, assignedWorker, 0, 0, 0);
}

int main() {
    int costMatrix[N][N],i,j;
    printf("Enter the 4X4 matrix:\n");
    for(i=0;i<N;i++)
    {
    	for(j=0;j<N;j++)
    	{
    		scanf("%d",&costMatrix[i][j]);
		}
	}
    
    printf("Minimum cost of assignment: %d\n", assignmentProblem(costMatrix));

    return 0;
}

