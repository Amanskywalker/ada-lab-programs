/*
  Programme to check if a graph is connected using DFS traversal
*/

#include<stdio.h>
#include<stdlib.h>

int a[20][20], n, vis[20]={0};

void Dfs(int src)
{
  int j;
  vis[src] = 1 ;
  for (j = 0; j <= n; ++j)
  {
    if (a[src][j] == 1 && vis[j] == 0)
    {
      Dfs(j);
    }
  }
}

int main(int argc, char const *argv[])
{
  int i, j, src;
  printf("Implementation of DFS traversal \n enter the number of verticies \n : ");
  scanf("%d",&n);
  printf("Enter the Adjecency matrix\n");
  for (i = 0; i <= n; ++i)
    for (j = 0; j <= n; j++)
      scanf("%d",&a[i][j]);

  printf("Enter the Source vertex\n");
  scanf("%d",&src);
  Dfs(src);
  for (j = 0; j <= n; ++j)
  {
    if(vis[j] != 1)
    {
      printf("\nGraph is not connected\n");
      return 0;
    }
  }
  printf("\nGraph is connected\n");
  return 0;
}
