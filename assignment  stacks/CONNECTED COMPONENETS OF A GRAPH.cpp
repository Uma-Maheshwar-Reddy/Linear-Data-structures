#include<iostream>
using namespace std;
int disconn(int**g,int* v,int n)
{
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		return i;
	}
	return -1;
}
bool is_adj(int **g,int i,int j)
{
	return g[i][j];
}
void dft(int v,int *vis,int n,int **g,int* num,int &p)
{
	vis[v]=1;
	//cout<<v+1<<" ";
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
int get_max(int *num,int n,int* vis)
{
	int max=-1;
	for(int i=0;i<n;i++)
	{
		if(num[i]>max&&vis[i]==0)
		max=num[i];
	}
	if(max==-1)
	return -1;
	for(int i=0;i<n;i++)
	{
		if(num[i]==max)
		{
			return i;
		}
	}
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
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			dft(i,vis,n,g,num,count);
		}
	}
	cout<<"numbering : ";
	for(int i=0;i<n;i++)
	{
		cout<<num[i]<<" ";
	}
	int **h;
	h=new int* [n];
	for(int i=0;i<n;i++)
	{
		h[i]=new int[n];
	}
	reverse(g,h,n);
	for(int i=0;i<n;i++)
	{
		vis[i]=0;
	}
	cout<<"\nThe Strongly Connected Componenets of graph are : "<<endl;
	int c=get_max(num,n,vis);
	while(c!=-1)
	{
		cout<<"{ ";
		dfs(c,vis,n,h);
		cout<<"} ";
		for(int i=0;i<n;i++)
		{
			if(vis[i])
			num[i]=-1;
		}
		c=get_max(num,n,vis);
		if(c!=-1)
		cout<<endl;
	}
	return 0;
}
