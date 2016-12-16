#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
union data
{
	int num;
	char alph;
	double dec;
};
struct stack
{
	int top;
	int size;
	union data[100];
};
void push(stack &s,int a;)
{
	if(s.top==s.size-1)
	{
		cout<<"the stack is full";
	}
	else
	{
		s.top++;
		(s.data[s.top]).num=a;
	}
}
void push(stack &s,char a;)
{
	if(s.top==s.size-1)
	{
		cout<<"the stack is full";
	}
	else
	{
		s.top++;
		(s.data[s.top]).alph=a;
	}
}
void push(stack &s,double a;)
{
	if(s.top==s.size-1)
	{
		cout<<"the stack is full";
	}
	else
	{
		s.top++;
		(s.data[s.top]).dec=a;
	}
}
void pop(stack &s)
{
	if(s.top!=-1)
	{
		cout<<"the stack is empty ";
	}
	else
	{
		a=
	}
}
int main()
{
	stack s;
	s.top=-1;
	s.size=100;
	data d,d1;
	int in,in1;
	while(1)
	{
		cout<<"1: push, 2:pop ,3:exit";
		cin>>in;
		if(in==1)
		{
			cout<<"1:int 2:char 3:string";
			cin>>in1;
			if(in1==1)
			{
				
			}
		}
	}
}
