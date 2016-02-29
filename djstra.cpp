#include<iostream>
#include<time.h>
#include<stdio.h>
using namespace std;

void dij(int src,int cost[][10],int dist[],int n)
{
	int visited[10],min,i,j,u;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		dist[i]=cost[src][i];
	}
	visited[src]=1;
	dist[src]=0;
	for(i=0;i<n;i++)//for 3
	{
		if(i==src)
			continue;
		min=999;
		for(j=0;j<n;j++)//for 1
		{
			if((visited[j]==0) && (min>dist[j]))
			{
				min=dist[j];
				u=j;
			}
		}//end for1
		
		visited[u]=1;
		for(j=0;j<n;j++)//for 2
		{
			if(visited[j]==0)
			{
				if(dist[j]>dist[u]+cost[u][j])
					dist[j]=dist[u]+cost[u][j];
			}
		}//end for 2
	}//for 3
}


int main()
{	float start,end,t;
	int n,cost[10][10],dist[10]={0,0,0,0,0,0,0,0,0,0},i,j,src;
	cout<<"entr no. of vertics:";
	cin>>n;
	cout<<"enter adjacency matrix:";
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
	{
		//cout<<"enter["<<i<<"]"<<"["<<j<<"]";
		cin>>cost[i][j];
		
	}
	}
	cout<<"enter source vertex:";
	cin>>src;
	start=clock();	
	dij(src,cost,dist,n);
	end=clock();
	cout<<"the shortest path are :";
	for(i=0;i<n;i++)
	{
		cout<<"to:"<<i<<" "<<dist[i]<<endl;
		
	}
	cout<<"time="<<(end-start)/CLOCKS_PER_SEC;
	return 0;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



									
