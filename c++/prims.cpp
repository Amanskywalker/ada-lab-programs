#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void prims(int n,int cost[][10])
{
	int min=999,source=1,i,j,k,p[10],u,q=0;
	int select[10][2],visit[10],sum=0,count=0;
	visit[source]=1;
	k=0;
	while(count<n-1)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((visit[i]==1) && (visit[j]!=1))
				{
					if(cost[i][j]<min)
					{
						min=cost[i][j];
						u=j;
						p[u]=i;
					}
				}
			}
		}
		visit[u]=1;
		select[q][0]=u;
		select[q][1]=p[u];
		sum=sum+cost[u][p[u]];
		count++;
		q++;
		}// end while
		
		if(sum<999)
		{
			cout<<"spanning tree exists"<<endl;
			for(i=0;i<n-1;i++)
				cout<<select[i][0]<<"  "<<select[i][1]<<endl;
			cout<<"The cost of the path is:"<<sum<<endl;
		}
		else
		{
			cout<<"does not exist";
		}
}

int main()
{
	int i,j,k,cost[10][10],n;
	cout<<"enter n:";
	cin>>n;
	cout<<"enter matrix:\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>cost[i][j];
	prims(n,cost);
	return 0;
}			
				
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
						
	
						
