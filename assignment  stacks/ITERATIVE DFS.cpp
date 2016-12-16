#include<iostream>
using namespace std;
struct stack
{
	int size;
	int elem[30];
	int top;
};
void push(struct stack &s,int &a)
{
	if(s.top==s.size-1)
	{
		cout<<"the stack is full";
	}
	else
	{
		s.top++;
		s.elem[s.top]=a;
	}
}
int pop(struct stack &s)
{
	if(s.top==-1)
	cout<<"the stack is empty";
	else
	return s.elem[s.top--];
}
void dft(stack &s,int v,int *vis,int n,int **g)
{
	push(s,v);
	vis[v]=1;
	while(s.top!=-1)
	{
		v=pop(s);
		cout<<v+1<<" ";
		for(int i=0;i<n;i++)
		{
			if(g[v][i]&&!vis[i])
			{
				push(s,i);
				vis[i]=1;
			}
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
	cout<<"enter the start vertex ";
	cin>>v;
	v--;
	stack s;
	s.top=-1;
	s.size=30;
	cout<<"DEPTH FIRST TRAVERSAL : ";
	dft(s,v,vis,n,g);
	return 0;
}
