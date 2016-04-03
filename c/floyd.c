/*
 *Implement All-Pairs Shortest Paths Problem using Floyd's algorithm.
 *Parallelize this algorithm, implement it using OpenMP and
 *determine the speed-up achieved.
 */

 #include <stdio.h>
 #include <omp.h>

 #define min(a, b) a < b ? a : b

 void floyd(int a[10][10],int n)
 {
   int thread_id, i, j, k;
   float s, e;
   s=omp_get_wtime();
   omp_set_num_threads(2);
   #pragma omp parallel for shared(a) private(i, j, k)
   for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
      {
        thread_id=omp_get_thread_num();
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        printf("Thread %d : a[%d][%d] = %d\n", thread_id, i, j, a[i][j]);
      }
    e=omp_get_wtime();
    printf("Shortest path matrix is\n");
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        printf("%d\t",a[i][j]);
      printf("\n");
    }
    printf("Time taken %f\n",(e-s) );
 }

int main(int argc, char const *argv[])
{
  int size,a[10][10],i,j;
  printf("Enter the size\n");
  scanf("%d\n",&size);
  printf("Enter the Elements\n");
  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      scanf("%d",&a[i][j]);
  floyd(a,size);
  return 0;
}
