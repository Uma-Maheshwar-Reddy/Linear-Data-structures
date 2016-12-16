#include<iostream>
using namespace std;
void f(int n,int &c)
{
	if(n==1||0)
	{
		return;
	}
	else
	{
		for(int i=0;i<2*n;i++)
		{
			cout<<"hello"<<endl;
			c++;
		}
		for(int i=0;i<7;i++)
		{
			f(n/3,c);
		}
	}
}
int main()
{
	int n;
	cout<<"enter n ";
	cin>>n;
	int c=0;
	while(n!=-1)
	{
		f(n,c);
		cout<<"c is "<<c<<endl;
		cout<<"enter n ";
		cin>>n;
	}
	return 0;
}
