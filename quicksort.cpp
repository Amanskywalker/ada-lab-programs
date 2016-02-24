#include<iostream>

#include<time.h>
#include<stdlib.h>
using namespace std;
int partition(int a[],int low,int high)
{
	int p=a[low],temp;
	int i,j;
	i=low;j=high+1;
	while(i<j)
	{
		do{
			++i;
			}while(a[i]<p);
		
		do{
			j--;
			}while(a[j]>p);
		
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
	}//end while
	
	temp=a[j];
	a[j]=a[low];
	a[low]=temp;
	
	return j;
	}
	
	
int quicksort(int a[],int low,int high)
{
	int s;
	if(low<high)
	{
		s=partition(a,low,high);
		quicksort(a,low,s-1);
		quicksort(a,s+1,high);
		
	}
}

int main(int argc,char *argv[])
{
	float start,end,t;
	int p,n,i;
	//cout<<"enter n:";
	n=atoi(argv[1]);
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand()%50;
	
	start=clock();
	quicksort(a,0,n-1);
	end=clock();	
	t=(end-start)/CLOCKS_PER_SEC;
	//for(i=0;i<n;i++)
	//	cout<<a[i]<<"  ";
	//cout<<endl;
	//cout<<"time="<<t<<endl;
	cout<<"\n "<<n<<"\t"<<t<<"\n";
	return 0;
}					
					
