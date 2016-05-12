#include<iostream>
#include<stdlib.h>
using namespace std;
int count,d,x[10],w[10];

void subset(int weightSofar,int k,int remaining)
{
	x[k]=1;int i;
	if(weightSofar+w[k]==d)
	{
		cout<<"sol:"<<++count<<endl;
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			{
				cout<<w[i];
			}
			cout<<"\n";
		}	
		return;
	}

	else if(weightSofar+w[k]+w[k+1]<=d)
	{
		subset(weightSofar+w[k],k+1,remaining-w[k]);

	}

	if(weightSofar+w[k+1]<=d && weightSofar+remaining-w[k]>=d)
	{
		x[k]=0;
		subset(weightSofar,k+1,remaining-w[k]);
	}

}




int main()
{
	int i,n,sum=0; 
	cout<<"no f ele;";
	cin>>n;
	cout<<"elements in asc order:";
	for(i=0;i<n;i++)
	{
		cin>>w[i];
		sum+=w[i];
	}
	cout<<"neter sum:";
	cin>>d;

	subset(0,0,sum);
	return 0;	
}