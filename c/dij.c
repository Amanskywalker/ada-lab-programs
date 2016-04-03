/*
From a given vertex in a weighted connected graph, find shortest
paths to other vertices using Dijkstra's algorithm.
*/

#include <stdio.h>

void dij(int scr,int cost[][10],int *dist,int n)
{
  int visited[10],min,i,count,u;
  for (i = 1; i <= n; i++)
    visited[i]=0,dist[i]=cost[scr][i];
  count=2;
  while (count<=n)
  {
    min=999;
    for (i = 1; i <=n; i++)
      if (dist[i]<min && !visited[i])
        min=dist[i], u=i;
    visited[u]=1;
    count++;
    for (i = 1; i<=n; i++)
      if ((dist[u]+cost[u][i] < dist[i]) && !visited[i])
        dist[i]=dist[u]+cost[u][i];
  }
}

int main(int argc, char const *argv[])
{
  int n, src, i, j, cost[10][10], dist[10];
  printf("Enter the number of vertices \n");
  scanf("%d",&n);
  printf("Enter cost matrix:\n");
  for (i = 1; i <=n; i++)
    for (j = 1; j <=n; j++)
      scanf("%d\n",&cost[i][j]);
  printf("Enter the source vertex\n");
  scanf("%d",&src);
  dij(src,cost,dist,n);
  printf("The Shortest path to source %d to other vertices are \n",src);
  for (i = 1; i <=n; i++)
    printf("to %d = %d \n",i,dist[i]);
  return 0;
}
