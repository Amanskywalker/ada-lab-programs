/*
 * Find Minimum Cost Spanning Tree of a given undirected graph using Prims algorithm
 */

#include <stdio.h>
#include <stdlib.h>

void prims(int a[10][10], int n)
{
	int elec[9], u, v, i, j, ne = 0, cost = 0, mincost = 999;
	elec[1] = 1;
	while(ne != n - 1)
	{
		mincost = 999;
		for (i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(elec[i] == 1)
					if(a[i][j]< mincost)
					{
						u = i;
						v = j;
						mincost = a[i][j];
					}

		if(elec[v] != 1)
		{
			elec[v] = 1;
			cost = cost + mincost;
			ne ++;
		}
		a[u][v] += 999;
	}
	printf("Mincost : %d\n",cost);
}

int main(int argc, char *argv[])
{
	int no, i, j;
	int a[10][10] = {0};
	printf ("Enter the no of vertices\n");
	scanf("%d", &no);
	printf("Enter the matrix\n");
	for(i = 1; i <= no; i++)
	{
		for(j = 1; j <= no; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	prims(a, no);
	return 0;
}

/*Output
Enter the no of vertices
6
Enter the matrix
0 60 10 999 999 999
60 0 999 20 40 70
10 999 0 999 999 50
999 20 999 0 999 80
999 40 999 999 0 30
999 70 50 80 30 0
Mincost : 150
*/
