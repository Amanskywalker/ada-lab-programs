#include<iostream>
using namespace std;
int vis[10];

int dfs(int a[][20],int n,int source)
{
	int i,j;
	vis[source]=1;
	for(j=1;j<=n;j++)
	{
		if(vis[j]==0 && a[source][j]==1)
			dfs(a,n,j);
	}
	for(j=1;j<=n;j++)		
		if(vis[j]==0)
			return 0;
	return 1;
}

int main()
{
	int i,j,source,a[20][20],n,ans;
	cout<<"enter no of vertices:";
	cin>>n;
	cout<<"ener adj matrix:";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	cout<<"enter source:";
	cin>>source;
	cout<<"/";
	ans=dfs(a,n,source);
	if(ans==1)
		cout<<"connectes";
	else
		cout<<"not con";	
	return 0;
}
