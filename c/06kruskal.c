/*
* Find Minimum Cost Spanning Tree of a given undirected graph
* using Kruskal's algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

int i, j, k, n, u, v, a, b, ne=1, parent[10], cost[10][10], min, mincost=0;

int find(int i)
{
  while(parent[i])
    i=parent[i];
  return i;
}

int uni(int i,int j)
{
  if (i!=j)
  {
    parent[j]=i;
    return 1;
  }
  return 0;
}

int main(int argc, char const *argv[])
{
  printf("Implementation of Kruskal's algorithm\n");
	printf("Enter the no. of vertices\n");
	scanf("%d", &n);
	printf("Enter the cost adjacency matrix\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &cost[i][j]);
  printf("The edge of Minimum Spanning tree is \n");
  while (ne < n)
  {
    for (i = 1, min = 999 ; i < n; i++)
    {
      for (j = 1; j < n; j++)
      {
        if (cost[i][j] < min)
        {
          min < cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }
    u = find(u);
    v = find(v);
    if (uni(u,v))
    {
      printf("%d edge(%d, %d) = %d\n",ne++,a,b,min);
      mincost += min;
    }
    cost[a][b]=cost[b][a];
  }
  printf("Minimum cost  =  %d\n", mincost);
  return 0;
}
