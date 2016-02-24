#include<iostream>
#include<omp.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

int *a;
void merge(int low,int mid,int high)
{
	int i,j,k;
	long int b[60000];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			k++;i++;
		}
		else
		{	
			b[k]=a[j];
			k++;j++;
		}
	
	}//end while
	
	while(i<=mid)
	{
		b[k]=a[i];
		k++;i++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		k++;j++;
	}
	for(i=low;i<=k-1;i++)
		a[i]=b[i];
		
}


int mergesort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(high+low)/2;
		#pragma omp task
		{
			mergesort(low,mid);
		}
		#pragma omp task
		{
			mergesort(low,mid);
		}
		merge(low,mid,high);
	}
}


int main()
{
	int size,i,n;
	double start,end;
	cout<<"enter size of array:";
	cin>>n;
	a=new int[n];
	cout<<"enter"<<n<<" elements";
	omp_set_num_threads(2);
	srand(0);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%50;	
		cout<<a[i]<<endl;
	}
	start=omp_get_wtime();
	mergesort(0,n-1);
	end=omp_get_wtime();
	cout<<"\nsorted array";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}	
	cout<<"time="<<(end-start)<<endl;
	return 0;
}	































		
		
		
		
				




		
						
