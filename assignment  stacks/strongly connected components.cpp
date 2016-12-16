#include<iostream>
using namespace std;
bool is_adj(int **g,int i,int j)
{
	return g[i][j];
}
int disconn(int**g,int* v,int n)
{
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		return i;
	}
	return -1;
}
void dfs(int v,int *vis,int n,int **g)
{
	vis[v]=1;
	cout<<v<<" ";
	for(int i=0;i<n;i++)
	{
		if(is_adj(g,v,i))
		{
			if(!vis[i])
			dfs(i,vis,n,g);
		}
	}
}
void dft(int v,int *vis,int n,int **g,int* num,int &p)
{
	vis[v]=1;
	for(int i=0;i<n;i++)
	{
		if(is_adj(g,v,i)&&vis[i]==0)
		{
			dft(i,vis,n,g,num,p);
		}
	}
	num[v]=p;
	p++;
}
void reverse(int **g,int **h,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			h[j][i]=g[i][j];
		}
	}
}
int find_max(int *a,int n)
{
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==max)
		{
			a[i]=-1;
		}
	}
	return max;
}
int main()
{
	int n;
	cout<<"enter the number of vertices of the graph ";
	cin>>n;
	int **g;
	g=new int* [n];
	for(int i=0;i<n;i++)
	{
		g[i]=new int[n];
	}
	cout<<"enter the matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	}
	int v;
	int *vis;
	vis=new int[n];
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
	}
	int *num;
	num=new int[n];
	for(int i=0;i<n;i++)
	num[i]=-1;
	int count=0,temp=0;
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			dft(i,vis,n,g,num,count);
		}
	}
	cout<<endl;
	int **h;
	h=new int* [n];
	for(int i=0;i<n;i++)
	{
		h[i]=new int[n];
	}
	reverse(g,h,n);
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
	}
	cout<<"hello ";
	for(int i=0;i<n;i++)
	{
		int v=find_max(num,n);
		if(vis[v]==0)
		{
			cout<<"v: "<<v<<endl;
			dfs(v,vis,n,h);
			cout<<endl;
		}
	}
	return 0;
}
