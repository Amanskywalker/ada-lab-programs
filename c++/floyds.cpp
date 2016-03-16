#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;


int min(int a,int b)
{
	return (a<b?a:b);
}
	

void floyd(int a[][10],int n)
{
	int b[10][10],threadId,i,j,k;
	double startTime,endTime;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[i][j]=a[i][j];
			
	startTime= omp_get_wtime();
	omp_set_num_threads(2);
	#pragma omp parallel for shared(b) private(i,j,k)
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				threadId=omp_get_thread_num();
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
				cout<<"thread="<<threadId<<"~~"<<"b["<<i<<"]"<<"["<<j<<"]"<<"="<<b[i][j]<<endl;	
			}
			endTime=omp_get_wtime();
			cout<<"\nAll pairs shortest path matrix:\n";
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<b[i][j]<<"  ";
				}
				cout<<"\n";
			}
			cout<<"\ntime elapsed:"<<endTime-startTime<<endl;
			return ;
}

int main()
{
	int threadId,i,j,n,a[10][10];
	cout<<"enter no. of nodes:";
	cin>>n;
	cout<<"enter distance matrix:\n";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	
	floyd(a,n);
	return 0;
}			





























			
