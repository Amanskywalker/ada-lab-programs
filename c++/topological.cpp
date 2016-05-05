#include<iostream>
using namespace std;
int s[10];
void source(int a[][20],int n)
{
	int i,j,indegree[20],u,v,sum,top=-1,t[20];
	int k=1;
	for(i=1;i<=n;i++)
	{	sum=0;
		for(j=1;j<=n;j++)
		{
			sum+=a[j][i];
		}
			indegree[i]=sum;
		
	}
	for(i=1;i<=n;i++)
		if(indegree[i]==0)
			s[++top]=i;

	while(k<=n)
	{
			u=s[top--];
			t[k++]=u;
			for(v=1;v<=n;v++)
			{
				if(a[u][v]==1)
				{
					indegree[v]-=1;
				
				
				if(indegree[v]==0)
					s[++top]=v;
				}
			}

	}
	cout<<endl<<"topo seq:";	
	for(i=1;i<=k;i++)
	{
		cout<<t[i]<<" ";

			}
}
int main()
{
	int a[20][20],i,j,n;
	cout<<"enter no of vertices:";
	cin>>n;
	cout<<"edj matrox:";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];

	source(a,n);
	return 0;	
}
