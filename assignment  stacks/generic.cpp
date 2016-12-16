#include<iostream>
using namespace std;
void push(struct stack &s,struct p x);
struct p pop(struct stack &s);
union s
{
	int m;
	char a[10];
	float f;
	char ch;
};
struct p
{
	union s g;
	int flag;
};
struct stack
{
	int size;
	struct p element[10];
	int top;
};


int main()
{
	struct stack stk;
	int i,j;
	stk.size=10;
	stk.top=-1;
	struct p c1,c2;
	for(i=0;i<4;i++)
	{
	cout<<"enter flag";
	cin>>c1.flag;
	switch(c1.flag)
	{
		case 1:cout<<"enter the charector";cin>>c1.g.a;break;
		case 2:cout<<"enter float value";cin>>c1.g.f;break;
		case 3:cout<<"enter the charecter value";cin>>c1.g.ch;break;
		case 4:cout<<"enter the integer value";cin>>c1.g.m;break;
	}
}
	push(stk,c1);
	c2=pop(stk);
	switch(c2.flag)
	{
		case 1:cout<<"the charector";cout<<c2.g.a;break;
		case 2:cout<<"float value";cout<<c2.g.f;break;
		case 3:cout<<"charecter value";cout<<c2.g.ch;break;
		case 4:cout<<"integer value";cout<<c2.g.m;break;
	}
	return 0;
}
void push(struct stack &s,struct p x)
{
	if(s.size-1==s.top)
	cout<<"stack is full";
	else
	{
		s.top++;
		s.element[s.top]=x;
	}
}
struct p pop(struct stack &s)
{
	if(s.top==-1)
	cout<<"stack is empty";
	else
	return (s.element[s.top--]);
}


