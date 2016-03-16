#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int find(int u,int r[])
{
	return r[u];
}

void unionij(int i,int j,int r[],int n)
{
	int k;
	if(i<j)
	{
		r[j]=i;
		for(k=1;k<=n;k++)
		{
			if(r[k]==j)
			{
				r[k]=i;
			}
		}
	}
	else
	{
	r[i]=j;
	for(k=1;k<=n;k++)
	{
		if(r[k]==i)
		{
			r[k]=j;
		}
	}
	}//end else
}

void kruskal(int n,int cost[][10],int r[10])
{
	int count=0,select[10][2],k=0;
	int sum=0,min,i,j,v,u;
	while(count<n-1)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((min>cost[i][j]) && (cost[i][j]!=0))
				{
					min=cost[i][j];
					u=i;
					v=j;
				}
			}
		}
	
	i=find(u,r);
	j=find(v,r);
	if(i!=j)
	{
		select[k][0]=u;
		select[k][1]=v;
		count++;
		k++;
		sum=sum+cost[u][v];
		unionij(i,j,r,n);
	}
	cost[u][v]=cost[v][u]=999;
	}// end while
	if(sum<999)
	{
		cout<<"spanning tree exists";
		cout<<"the sum  is "<<sum<<endl;
		cout<<"the edges are\n";
		for(i=0;i<n-1;i++)
			cout<<"\t"<<select[i][0]<<"->"<<select[i][1]<<endl;
	}
	else
		cout<<"spanning tree does not exist";
}


int main()
{
	int i,j,cost[10][10],r[10],n;
	cout<<"enter n:";
	cin>>n;
	for(i=1;i<=n;i++)
		r[i]=i;
	cout<<"enter matrix:\n";
	for(i=1;i<=n;i++)				
			for(j=1;j<=n;j++)
				cin>>cost[i][j];
	
	kruskal(n,cost,r);			
	return 0;
}		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
						
