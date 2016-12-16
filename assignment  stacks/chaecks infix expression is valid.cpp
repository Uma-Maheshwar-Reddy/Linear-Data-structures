#include<iostream>
#include<cstring>
using namespace std;
struct stack
{
	int size;
	char elem[100];
	int top;
};
void push(struct stack &s,char &a)
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
char pop(struct stack &s)
{
	if(s.top==-1)
	cout<<"the stack is empty";
	else
	return s.elem[s.top--];
}
bool openbrac(char a)
{
	if(a=='('||a=='['||a=='{')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool closebrac(char a)
{
	if(a==')'||a=='}'||a==']')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int match(char a,char b)
{
	if((a=='('&&b==')')||(a=='{'&&b=='}')||(a=='['&&b==']'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	struct stack s;
	s.top=-1;
	s.size=100;
	int res;
	char infix[100];
	cout<<"enter the expression"<<endl;
	cin.getline(infix,100);
	int len=strlen(infix);
	for(int i=0;i<len;i++)
	{
		if(openbrac(infix[i]))
		{
			push(s,infix[i]);
		}
		else
		if(closebrac(infix[i]))
		{
			res=match(pop(s),infix[i]);
		}
		if(res==0) break;
	}
	if(res==1) 
	{
		cout<<"the given infix expression is valid"<<endl;
	}
	else 
	{
		cout<<"the given infix expression is not valid"<<endl;
	}
	return 0;
}
