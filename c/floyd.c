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
   int thread_id, i, j, k, s, e;
   s=omp_get_wtime();
   omp_set_num_threads(2);
   #pragma omp parallel shared(a) private(i, j, k)
   for (i = 1; i < n; i++)
    for (j = 1; j < n; j++)
      for (k = 0; k < n; k++)
      {
        thread_id=omp_get_thread_num();
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        printf("Thread %d : a[%d][%d] = %d\n", thread_id, i, j, a[i][j]);
      }
 }
