#include<iostream>
using namespace std;

int a[10][10],visited[10],n,cost=0,sum=0,lastcity=0,vs[10];

void get()
{
		int i,j;
		cout<<"Enter no of cities:";
		cin>>n;
		cout<<"enter the cost matrix:\n";
		for(i=1;i<=n;i++)
		{
				cout<<"enter element if row"<<i<<":";
				for(j=1;j<=n;j++)
					cin>>a[i][j];
				visited[i]=0;

		}
		cout<<"the cost list is :"<<endl;
		for(i=0;i<=n;i++)
		{
			cout<<"\n\n";
			for(j=1;j<=n;j++)
				cout<<a[i][j]<<"   ";

		}	
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=1;i<=n;i++)
	{
		if((a[c][i]!=0) && (visited[i]==0))
			if(a[c][i]<min)
			{
				min=a[i][1]+a[c][i];
				kmin=a[c][i];
				nc=i;

			}
	}
	if(min !=999)
		cost+=kmin;
	return nc;
}



void mincost(int city)
{
	int i,ncity;
	visited[city]=1;
	cout<<city<<"->";
	ncity=least(city);
	if (ncity==999)
	{
		ncity=1;
		cout<<ncity;
		cost+=a[city][ncity];
		return;
	}
	mincost(ncity);
}

void nearest_neighbour(int city)
{
	int min,j,i,u;
	vs[city]=1;
	cout<<city<<"->";
	u=city;
	for(j=1;j<=n;j++)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			if((vs[i]==0)&& (a[city][i] !=0))
				if(a[city][i] < min)
				{
					min=a[city][i];
					u=i;	
				}	
			city=u;
		}
		vs[u]=1;
		if (min != 999)
		{
			sum+=min;
			cout<<u<<"->";
		}
	}
	lastcity=u;	
}


void put()
{
	cout<<"\nmin cost"<<cost<<endl;
}	

int main()
{
	float ratio;
	get();
	cout<<"The path is:";
	mincost(1);
	put();
	cout<<"\nthe path using algorithm:";
	nearest_neighbour(1);
	cout<<"1";
	sum+=a[lastcity][1];
	cout<<"\nmin cost is:"<<sum;
	ratio=(float)sum/cost;

	cout<<"\nthe accurate ratio:"<<ratio<<endl;
	return 0;

}
