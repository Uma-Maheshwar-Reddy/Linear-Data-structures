#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct stack
{
	int size;
	int elem[100];
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
bool isnum(char a)
{
	if(a>='0'&&a<='9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int num(char a)
{
	if(a=='0') return 0;
	if(a=='1') return 1;
	if(a=='2') return 2;
	if(a=='3') return 3;
	if(a=='4') return 4;
	if(a=='5') return 5;
	if(a=='6') return 6;
	if(a=='7') return 7;
	if(a=='8') return 8;
	if(a=='9') return 9;
}
int operation(int a,int b,char c)
{
	switch(c)
	{
		case '+':
			return a+b;
			break;
		case '-' :
			return a-b;
			break;
		case '*' :
			return a*b;
			break;
		case '/' :
			return a/b;
			break;
	}
}
int main()
{
	char postfix[100];
	stack s;
	s.top=-1;
	s.size=100;
	int a,b,res,sw;
	cout<<"enter the postfix expression"<<endl;
	cin.getline(postfix,100);
	int len=strlen(postfix);
	for(int i=0;i<len;i++)
	{
		if(isnum(postfix[i]))
		{
			sw=num(postfix[i]);
			push(s,sw);
			
		}
		else
		{
			a=pop(s);
			b=pop(s);
			res=operation(a,b,postfix[i]);
			push(s,res);
		}
	}
	if(s.top==0)
	{
		cout<<endl<<"the result is "<<s.elem[s.top];
	} 
	return 0;
}
