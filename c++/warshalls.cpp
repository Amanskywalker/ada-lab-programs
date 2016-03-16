#include<iostream>
#include<stdlib.h>
using namespace std;

void warshalls(int n, int a[][10])
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j] !=1)
				{
					if((a[i][k]==1) && (a[k][j]==1))
						a[i][j]=1;
				}
			}
		}
	}
	cout<<"transitive closure:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
}

int main()
{
	int n,i,j,a[10][10];
	cout<<"enter size of matrix:";
	cin>>n;
	cout<<"enter elements:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"the matrix entered is:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
	
	warshalls(n,a);
	
	return 0;
}		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
									
