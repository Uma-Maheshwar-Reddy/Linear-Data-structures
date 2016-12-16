#include<iostream>
using namespace std;
int get_min(int a[],int vis[],int n)
{
	int min=100;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			if(a[i]<min&&vis[i]==0)
			min=a[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==min)
		return i;
	}
}
int main()
{
	int **g;
	int n;
	cout<<"enter the num of vertices ";
	cin>>n;
	g=new int*[n];
	for(int i=0;i<n;i++)
	{
		g[i]=new int[n];		
	}
	cout<<"enter matrix "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	}
	int s,go;
	cout<<"enter source goal ";
	cin>>s>>go;
	int curr=s;
	int dis[n],via[n],vis[n];
	for(int i=0;i<n;i++)
	{
		dis[i]=0;via[i]=0;vis[i]=0;
	}
	while(curr!=go)
	{
		vis[curr]=1;
		for(int i=0;i<n;i++)
		{
			if(g[curr][i]!=0&&vis[i]==0)
			{
				if(dis[i]==0)
				{
					dis[i]=dis[curr]+g[curr][i];
					via[i]=curr;
				}
				else
				if(dis[i]>(dis[curr]+g[curr][i])&&vis[i]==0)
				{
					dis[i]=dis[curr]+g[curr][i];
					via[i]=curr;
				}
			}
		}
		curr=get_min(dis,vis,n);
	}
	while(curr!=s)
	{
		cout<<curr<<" ";
		curr=via[curr];
	}
	cout<<curr<<" ";
	return 0;
}
