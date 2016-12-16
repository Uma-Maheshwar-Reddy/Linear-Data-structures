#include<iostream>
#include<cstring>
using namespace std;
struct employee
{
	string name;
	int salary;
};
struct stack
{
	int top;
	int size;
	employee e[100];
};
void push(stack &s,employee &e)
{
	if(s.top==s.size-1)
	{
		cout<<"the stack is empty";
	}
	else
	{
		s.top++;
		(s.e[s.top]).name=e.name;
		(s.e[s.top]).salary=e.salary;
	}
}
employee pop(stack &s)
{
	employee p;
	if(s.top==-1)
	{
		cout<<"the stack is empty"<<endl;
	}
	else
	{
		p.name=(s.e[s.top]).name;
		p.salary=(s.e[s.top]).salary;
		s.top--;
	}
	return p;
}
int main()
{
	stack s;
	s.top=-1;
	s.size=100;
	employee e,e1;
	int in;
	while(1)
	{
		cout<<"1:push  2:pop  3:exit";
		cin>>in;
		if(in==1)
		{
			cout<<"enter employee details";
			cin>>e.name>>e.salary;
			push(s,e);
		}
		else
		if(in==2)
		{
			e1=pop(s);
			cout<<e1.name<<"  "<<e1.salary<<endl;
		}
		else
		if(in==3)
		{
			break;
		}
	}
	return 0;
}

