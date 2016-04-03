/*
 * Find Minimum Cost Spanning Tree of a given undirected graph
 * using Kruskal's algorithm.
 */

 #include <stdio.h>
 #include <stdlib.h>

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

int main(int argc, char const *argv[]) {
  
  return 0;
}
